#include "ir_generator.hh"
#include <algorithm>

void IRGenerator::generate(Node* root) {
    if (!root) return;
    this->root = root;
    visitNode(root);
}

void IRGenerator::visitNode(Node* node) {
    if (!node) return;

    if (node->type == "MainClass") {
        visitMainClass(node);
        return;
    }

    if (node->type == "ClassDeclaration") {
        visitClass(node);
        return;
    }

    if (!node->children.empty()) {
        for (auto child : node->children) {
            parents.push_back(node);
            visitNode(child);
            parents.pop_back();
        }
    }
}

void IRGenerator::visitMainClass(Node* node) {
    // node->value = class name
    // children[0] = class Identifier
    // children[1] = MainClassParams (type "MainClass"):
    //   children[0] = args Identifier
    //   children[1] = first Statement
    //   children[2] = StatementList (remaining statements)

    string className = node->value;
    currentClassName = className;

    MethodCFG* method = new MethodCFG(className + ".main");
    currentMethod = method;

    BasicBlock* entryBlock = program.newBlock();
    method->entryBlock = entryBlock;
    method->allBlocks.push_back(entryBlock);
    currentBlock = entryBlock;

    auto it = node->children.begin();
    ++it;  // skip class Identifier
    Node* mainParams = *it;

    auto paramIt = mainParams->children.begin();
    ++paramIt;  // skip args Identifier
    Node* firstStmt = *paramIt++;
    Node* stmtList = *paramIt;

    BasicBlock* exitBlock = visitStatement(firstStmt, entryBlock);

    for (Node* stmt : stmtList->children) {
        exitBlock = visitStatement(stmt, exitBlock);
    }

    currentBlock = exitBlock;
    currentBlock->addInstruction(TAC(TACOp::STOP, ""));

    eliminatePassthroughBlocks(method);
    program.methods.push_back(method);
}

void IRGenerator::visitClass(Node* node) {
    // node->value = class name
    // children[0] = class Identifier
    // children[1] = VarDeclarationCL (class-level variables)
    // children[2] = MethodDeclarationCL (methods)

    string className = node->value;
    currentClassName = className;

    auto it = node->children.begin();
    ++it;  // skip class Identifier
    ++it;  // skip VarDeclarationCL
    Node* methodDeclList = *it;

    for (Node* methodDecl : methodDeclList->children) {
        visitMethod(methodDecl);
    }
}

void IRGenerator::visitMethod(Node* node) {
    // node->value = method name
    // children[0] = return type
    // children[1] = method Identifier
    // children[2] = MethodDeclarationParamsOpt
    // children[3] = MethodDeclarationBody
    // children[4] = return expression

    auto it = node->children.begin();
    Node* returnType = *it++;
    Node* methodId = *it++;
    Node* paramsOpt = *it++;
    Node* body = *it++;
    Node* returnExpr = *it;

    string methodName = methodId->value;

    MethodCFG* method = new MethodCFG(currentClassName + "." + methodName);
    currentMethod = method;

    BasicBlock* entryBlock = program.newBlock();
    method->entryBlock = entryBlock;
    method->allBlocks.push_back(entryBlock);
    currentBlock = entryBlock;

    // Extract parameters from MethodDeclarationParamsOpt -> ParameterList -> Parameter nodes
    // Parameter children: [0] = type, [1] = Identifier
    if (paramsOpt && !paramsOpt->children.empty()) {
        Node* paramList = paramsOpt->children.front();
        if (paramList && paramList->type == "ParameterList") {
            for (Node* param : paramList->children) {
                if (param->type == "Parameter") {
                    auto paramIt = param->children.begin();
                    ++paramIt;  // skip type
                    Node* paramId = *paramIt;
                    method->parameters.push_back(paramId->value);
                }
            }
        }
    }

    // Process MethodDeclarationBody children:
    // VarDeclaration nodes -> localVars, Statement nodes -> visitStatement
    BasicBlock* exitBlock = entryBlock;
    if (body && !body->children.empty()) {
        for (Node* child : body->children) {
            if (child->type == "VarDeclaration") {
                auto varIt = child->children.begin();
                ++varIt;  // skip type
                Node* varId = *varIt;
                method->localVars.push_back(varId->value);
            } else {
                exitBlock = visitStatement(child, exitBlock);
            }
        }
    }

    currentBlock = exitBlock;
    string returnTemp = visitExpression(returnExpr);
    currentBlock->addInstruction(TAC(TACOp::RETURN, returnTemp));

    eliminatePassthroughBlocks(method);
    program.methods.push_back(method);
}

string IRGenerator::visitExpression(Node* node) {
    if (!node) return "";

    const string& type = node->type;

    if (type == "IntLiteral") {
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::COPY_CONST, temp, node->value));
        return temp;
    }

    if (type == "BooleanLiteral") {
        string temp = program.newTemp();
        string val = (node->value == "true") ? "1" : "0";
        currentBlock->addInstruction(TAC(TACOp::COPY_CONST, temp, val));
        return temp;
    }

    if (type == "Identifier") {
        return node->value;
    }

    if (type == "This") {
        return "this";
    }

    if (type == "Expression") {
        return visitExpression(node->children.front());
    }

    if (type == "AddExpression" || type == "SubExpression" || type == "MultExpression") {
        auto it = node->children.begin();
        Node* left = *it++;
        Node* right = *it;

        string t1 = visitExpression(left);
        string t2 = visitExpression(right);
        string temp = program.newTemp();

        TACOp op;
        if (type == "AddExpression") op = TACOp::ADD;
        else if (type == "SubExpression") op = TACOp::SUB;
        else op = TACOp::MUL;

        currentBlock->addInstruction(TAC(op, temp, t1, t2));
        return temp;
    }

    if (type == "AndExpression" || type == "OrExpression" ||
        type == "LtExpression" || type == "GtExpression" || type == "EqExpression") {
        auto it = node->children.begin();
        Node* left = *it++;
        Node* right = *it;

        string t1 = visitExpression(left);
        string t2 = visitExpression(right);
        string temp = program.newTemp();

        TACOp op;
        if (type == "AndExpression") op = TACOp::AND;
        else if (type == "OrExpression") op = TACOp::OR;
        else if (type == "LtExpression") op = TACOp::LT;
        else if (type == "GtExpression") op = TACOp::GT;
        else op = TACOp::EQ;

        currentBlock->addInstruction(TAC(op, temp, t1, t2));
        return temp;
    }

    if (type == "NotExpression") {
        string t1 = visitExpression(node->children.front());
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::NOT, temp, t1));
        return temp;
    }

    if (type == "NewObjectExpression") {
        Node* classId = node->children.front();
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::NEW_OBJECT, temp, classId->value));
        return temp;
    }

    if (type == "MethodCall") {
        auto it = node->children.begin();
        Node* objExpr = *it++;
        Node* methodId = *it++;
        Node* argsNode = *it;  // ExpressionParamsOpt

        // Determine the qualified class name for the method call
        string callClassName = "";
        if (objExpr->type == "NewObjectExpression") {
            callClassName = objExpr->children.front()->value;
        } else if (objExpr->type == "This") {
            callClassName = currentClassName;
        } else if (objExpr->type == "Identifier") {
            callClassName = currentClassName;
        }

        // Translate the object expression and emit as first param ("this")
        string objTemp = visitExpression(objExpr);
        currentBlock->addInstruction(TAC(TACOp::PARAM, objTemp));

        // Translate and emit each argument
        int argCount = 1;
        if (argsNode && !argsNode->children.empty()) {
            Node* exprParams = argsNode->children.front();
            if (exprParams && exprParams->type == "ExpressionParams") {
                for (Node* arg : exprParams->children) {
                    string argTemp = visitExpression(arg);
                    currentBlock->addInstruction(TAC(TACOp::PARAM, argTemp));
                    argCount++;
                }
            }
        }

        string temp = program.newTemp();
        string methodName = methodId->value;
        string qualifiedName = callClassName.empty() ? methodName : callClassName + "." + methodName;
        currentBlock->addInstruction(TAC(TACOp::CALL, temp, qualifiedName, "", argCount));
        return temp;
    }

    return "";
}

void IRGenerator::visitCondition(Node* condExpr, BasicBlock* trueBlock, BasicBlock* falseBlock) {
    if (!condExpr) return;

    // Unwrap parenthesized expression
    if (condExpr->type == "Expression") {
        visitCondition(condExpr->children.front(), trueBlock, falseBlock);
        return;
    }

    // Short-circuit AND: if left is false jump directly to falseBlock,
    // otherwise evaluate right in a new mid-block.
    if (condExpr->type == "AndExpression") {
        auto it = condExpr->children.begin();
        Node* left = *it++;
        Node* right = *it;

        BasicBlock* midBlock = program.newBlock();
        currentMethod->allBlocks.push_back(midBlock);

        // Evaluate left in currentBlock; if false short-circuit to falseBlock
        visitCondition(left, midBlock, falseBlock);

        // Evaluate right in midBlock
        currentBlock = midBlock;
        visitCondition(right, trueBlock, falseBlock);
        return;
    }

    // Short-circuit OR: if left is true jump directly to trueBlock,
    // otherwise evaluate right in a new mid-block.
    if (condExpr->type == "OrExpression") {
        auto it = condExpr->children.begin();
        Node* left = *it++;
        Node* right = *it;

        BasicBlock* midBlock = program.newBlock();
        currentMethod->allBlocks.push_back(midBlock);

        // Evaluate left in currentBlock; if true short-circuit to trueBlock.
        // COND_JUMP jumps on false, so "iffalse left goto midBlock" with trueExit=trueBlock.
        visitCondition(left, trueBlock, midBlock);

        // Evaluate right in midBlock
        currentBlock = midBlock;
        visitCondition(right, trueBlock, falseBlock);
        return;
    }

    // Default: evaluate the expression as a value, then branch.
    string condTemp = visitExpression(condExpr);
    currentBlock->addInstruction(TAC(TACOp::COND_JUMP, falseBlock->label, condTemp));
    currentBlock->condition = condTemp;
    currentBlock->trueExit = trueBlock;
    currentBlock->falseExit = falseBlock;
}

BasicBlock* IRGenerator::visitStatement(Node* node, BasicBlock* block) {
    if (!node || !block) return block;

    currentBlock = block;
    const string& type = node->type;

    if (type == "AssignStatement") {
        auto it = node->children.begin();
        Node* varId = *it++;
        Node* expr = *it;

        string result = visitExpression(expr);
        currentBlock->addInstruction(TAC(TACOp::COPY, varId->value, result));
        return currentBlock;
    }

    if (type == "PrintStatement") {
        Node* expr = node->children.front();
        string result = visitExpression(expr);
        currentBlock->addInstruction(TAC(TACOp::PRINT, result));
        return currentBlock;
    }

    if (type == "Block") {
        if (!node->children.empty()) {
            Node* stmtMulti = node->children.front();
            BasicBlock* exitBlock = block;
            for (Node* s : stmtMulti->children) {
                exitBlock = visitStatement(s, exitBlock);
            }
            return exitBlock;
        }
        return block;
    }

    if (type == "IfStatement") {
        auto it = node->children.begin();
        Node* condExpr = *it++;
        Node* thenStmt = *it++;

        BasicBlock* thenBlock = program.newBlock();
        currentMethod->allBlocks.push_back(thenBlock);
        BasicBlock* mergeBlock = program.newBlock();
        currentMethod->allBlocks.push_back(mergeBlock);

        bool hasElse = (node->children.size() == 3);

        if (hasElse) {
            Node* elseStmt = *it;

            BasicBlock* elseBlock = program.newBlock();
            currentMethod->allBlocks.push_back(elseBlock);

            visitCondition(condExpr, thenBlock, elseBlock);

            BasicBlock* thenExit = visitStatement(thenStmt, thenBlock);
            thenExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            thenExit->trueExit = mergeBlock;

            BasicBlock* elseExit = visitStatement(elseStmt, elseBlock);
            elseExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            elseExit->trueExit = mergeBlock;
        } else {
            visitCondition(condExpr, thenBlock, mergeBlock);

            BasicBlock* thenExit = visitStatement(thenStmt, thenBlock);
            thenExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            thenExit->trueExit = mergeBlock;
        }

        return mergeBlock;
    }

    if (type == "WhileStatement") {
        auto it = node->children.begin();
        Node* condExpr = *it++;
        Node* bodyStmt = *it;

        // condBlock is the entry of the condition evaluation.
        // For && / ||, visitCondition may create additional blocks after condBlock,
        // but the loop-back always targets condBlock (the first condition block).
        BasicBlock* condBlock = program.newBlock();
        currentMethod->allBlocks.push_back(condBlock);
        BasicBlock* bodyBlock = program.newBlock();
        currentMethod->allBlocks.push_back(bodyBlock);
        BasicBlock* exitBlock = program.newBlock();
        currentMethod->allBlocks.push_back(exitBlock);

        currentBlock->addInstruction(TAC(TACOp::JUMP, condBlock->label));
        currentBlock->trueExit = condBlock;

        currentBlock = condBlock;
        visitCondition(condExpr, bodyBlock, exitBlock);

        BasicBlock* bodyExit = visitStatement(bodyStmt, bodyBlock);
        bodyExit->addInstruction(TAC(TACOp::JUMP, condBlock->label));
        bodyExit->trueExit = condBlock;

        return exitBlock;
    }

    return block;
}

void IRGenerator::eliminatePassthroughBlocks(MethodCFG* method) {
    // Repeatedly eliminate blocks that contain only a single unconditional JUMP.
    // These are "passthrough" blocks with no real work — redirecting their
    // predecessors directly to their successor compacts the CFG.
    bool changed = true;
    while (changed) {
        changed = false;

        for (size_t i = 0; i < method->allBlocks.size(); i++) {
            BasicBlock* block = method->allBlocks[i];

            // Passthrough criteria: exactly one instruction, it is a JUMP,
            // no false exit (unconditional), and does not loop to itself.
            if (block->instructions.size() != 1 ||
                block->instructions[0].op != TACOp::JUMP ||
                block->falseExit != nullptr ||
                block->trueExit == nullptr ||
                block->trueExit == block) {
                continue;
            }

            BasicBlock* successor = block->trueExit;
            string blockLabel = block->label;
            string successorLabel = successor->label;

            // Redirect every block that referenced the passthrough block
            for (BasicBlock* other : method->allBlocks) {
                if (other == block) continue;

                if (other->trueExit == block)  other->trueExit  = successor;
                if (other->falseExit == block) other->falseExit = successor;

                for (TAC& tac : other->instructions) {
                    if ((tac.op == TACOp::JUMP || tac.op == TACOp::COND_JUMP) &&
                        tac.result == blockLabel) {
                        tac.result = successorLabel;
                    }
                }
            }

            if (method->entryBlock == block)
                method->entryBlock = successor;

            method->allBlocks.erase(method->allBlocks.begin() + i);
            delete block;
            i--;
            changed = true;
        }
    }

}

void IRGenerator::writeDotFile(const string& filename) {
    program.toDotFile(filename);
}
