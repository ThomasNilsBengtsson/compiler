#include "ir_generator.h"

IRGenerator::IRGenerator()
    : currentBlock(nullptr), currentMethod(nullptr) {
}

void IRGenerator::generate(Node* root) {
    // Root should be "Goal" node with children:
    // [0] MainClass
    // [1] ClassDeclarationList (optional)

    if (!root || root->children.empty()) {
        return;
    }

    auto it = root->children.begin();

    // First child is MainClass
    Node* mainClass = *it;
    translateMainClass(mainClass);
    ++it;

    // Second child (if exists) is ClassDeclarationList
    if (it != root->children.end()) {
        Node* classListNode = *it;
        // Iterate through all class declarations
        for (Node* classDecl : classListNode->children) {
            translateClass(classDecl);
        }
    }
}

string IRGenerator::translateExpression(Node* expr) {
    if (!expr) return "";

    const string& type = expr->type;

    // IntLiteral: temp = constant
    if (type == "IntLiteral") {
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::COPY_CONST, temp, expr->value));
        return temp;
    }

    // BooleanLiteral: temp = 1 or 0
    if (type == "BooleanLiteral") {
        string temp = program.newTemp();
        string val = (expr->value == "true") ? "1" : "0";
        currentBlock->addInstruction(TAC(TACOp::COPY_CONST, temp, val));
        return temp;
    }

    // Identifier: just return the variable name
    if (type == "Identifier") {
        return expr->value;
    }

    // This: return "this"
    if (type == "This") {
        return "this";
    }

    // Parenthesized expression: translate inner
    if (type == "Expression") {
        return translateExpression(expr->children.front());
    }

    // Binary arithmetic: AddExpression, SubExpression, MultExpression
    if (type == "AddExpression" || type == "SubExpression" || type == "MultExpression") {
        auto it = expr->children.begin();
        Node* left = *it++;
        Node* right = *it;

        string t1 = translateExpression(left);
        string t2 = translateExpression(right);
        string temp = program.newTemp();

        TACOp op;
        if (type == "AddExpression") op = TACOp::ADD;
        else if (type == "SubExpression") op = TACOp::SUB;
        else op = TACOp::MUL;

        currentBlock->addInstruction(TAC(op, temp, t1, t2));
        return temp;
    }

    // Binary comparison/logical: AndExpression, OrExpression, LtExpression, GtExpression, EqExpression
    if (type == "AndExpression" || type == "OrExpression" ||
        type == "LtExpression" || type == "GtExpression" || type == "EqExpression") {
        auto it = expr->children.begin();
        Node* left = *it++;
        Node* right = *it;

        string t1 = translateExpression(left);
        string t2 = translateExpression(right);
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

    // NotExpression: temp = !operand
    if (type == "NotExpression") {
        string t1 = translateExpression(expr->children.front());
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::NOT, temp, t1));
        return temp;
    }

    // ArrayAccess: temp = array[index]
    if (type == "ArrayAccess") {
        auto it = expr->children.begin();
        Node* arrayNode = *it++;
        Node* indexNode = *it;

        string arrTemp = translateExpression(arrayNode);
        string idxTemp = translateExpression(indexNode);
        string temp = program.newTemp();

        currentBlock->addInstruction(TAC(TACOp::ARRAY_ACCESS, temp, arrTemp, idxTemp));
        return temp;
    }

    // ArrayLength: temp = length array
    if (type == "ArrayLength") {
        string arrTemp = translateExpression(expr->children.front());
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::ARRAY_LENGTH, temp, arrTemp));
        return temp;
    }

    // NewArrayExpression: temp = new int[size]
    if (type == "NewArrayExpression") {
        string sizeTemp = translateExpression(expr->children.front());
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::NEW_ARRAY, temp, sizeTemp));
        return temp;
    }

    // NewObjectExpression: temp = new ClassName
    if (type == "NewObjectExpression") {
        Node* classId = expr->children.front();
        string className = classId->value;
        string temp = program.newTemp();
        currentBlock->addInstruction(TAC(TACOp::NEW_OBJECT, temp, className));
        return temp;
    }

    // MethodCall: obj.method(args)
    if (type == "MethodCall") {
        auto it = expr->children.begin();
        Node* objExpr = *it++;
        Node* methodId = *it++;
        Node* argsNode = *it;  // ExpressionParamsOpt

        // Translate the object expression
        string objTemp = translateExpression(objExpr);

        // Emit PARAM for "this" (the object)
        currentBlock->addInstruction(TAC(TACOp::PARAM, objTemp));

        // Translate and emit PARAM for each argument
        // Structure: ExpressionParamsOpt -> ExpressionParams -> expressions
        int argCount = 1;  // Start at 1 because "this" is first param
        if (argsNode && !argsNode->children.empty()) {
            // argsNode has one child: ExpressionParams
            Node* exprParams = argsNode->children.front();
            if (exprParams && exprParams->type == "ExpressionParams") {
                for (Node* arg : exprParams->children) {
                    string argTemp = translateExpression(arg);
                    currentBlock->addInstruction(TAC(TACOp::PARAM, argTemp));
                    argCount++;
                }
            }
        }

        // Emit CALL
        string temp = program.newTemp();
        string methodName = methodId->value;
        currentBlock->addInstruction(TAC(TACOp::CALL, temp, methodName, "", argCount));

        return temp;
    }

    // Fallback: unknown expression type
    return "";
}

BasicBlock* IRGenerator::translateStatement(Node* stmt, BasicBlock* block) {
    if (!stmt || !block) return block;

    currentBlock = block;
    const string& type = stmt->type;

    // AssignStatement: var = expr
    if (type == "AssignStatement") {
        auto it = stmt->children.begin();
        Node* varId = *it++;
        Node* expr = *it;

        string result = translateExpression(expr);
        currentBlock->addInstruction(TAC(TACOp::COPY, varId->value, result));
        return currentBlock;
    }

    // ArrayAssignStatement: array[index] = value
    if (type == "ArrayAssignStatement") {
        auto it = stmt->children.begin();
        Node* arrayId = *it++;
        Node* indexExpr = *it++;
        Node* valueExpr = *it;

        string indexTemp = translateExpression(indexExpr);
        string valueTemp = translateExpression(valueExpr);
        currentBlock->addInstruction(TAC(TACOp::ARRAY_ASSIGN, arrayId->value, indexTemp, valueTemp));
        return currentBlock;
    }

    // PrintStatement: print(expr)
    if (type == "PrintStatement") {
        Node* expr = stmt->children.front();
        string result = translateExpression(expr);
        currentBlock->addInstruction(TAC(TACOp::PRINT, result));
        return currentBlock;
    }

    // Block: { statements }
    if (type == "Block") {
        // children[0] is StatementMulti containing the statements
        if (!stmt->children.empty()) {
            Node* stmtMulti = stmt->children.front();
            BasicBlock* exitBlock = block;
            for (Node* s : stmtMulti->children) {
                exitBlock = translateStatement(s, exitBlock);
            }
            return exitBlock;
        }
        return block;
    }

    // IfStatement: if (cond) stmt [else stmt]
    if (type == "IfStatement") {
        auto it = stmt->children.begin();
        Node* condExpr = *it++;
        Node* thenStmt = *it++;

        // Translate condition in current block
        string condTemp = translateExpression(condExpr);

        // Create blocks
        BasicBlock* thenBlock = program.newBlock();
        currentMethod->allBlocks.push_back(thenBlock);
        BasicBlock* mergeBlock = program.newBlock();
        currentMethod->allBlocks.push_back(mergeBlock);

        bool hasElse = (stmt->children.size() == 3);

        if (hasElse) {
            Node* elseStmt = *it;

            // Create else block
            BasicBlock* elseBlock = program.newBlock();
            currentMethod->allBlocks.push_back(elseBlock);

            // Current block: iffalse cond goto elseBlock
            currentBlock->addInstruction(TAC(TACOp::COND_JUMP, elseBlock->label, condTemp));
            currentBlock->condition = condTemp;
            currentBlock->trueExit = thenBlock;
            currentBlock->falseExit = elseBlock;

            // Translate then branch
            BasicBlock* thenExit = translateStatement(thenStmt, thenBlock);
            thenExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            thenExit->trueExit = mergeBlock;

            // Translate else branch
            BasicBlock* elseExit = translateStatement(elseStmt, elseBlock);
            elseExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            elseExit->trueExit = mergeBlock;
        } else {
            // No else: iffalse cond goto mergeBlock
            currentBlock->addInstruction(TAC(TACOp::COND_JUMP, mergeBlock->label, condTemp));
            currentBlock->condition = condTemp;
            currentBlock->trueExit = thenBlock;
            currentBlock->falseExit = mergeBlock;

            // Translate then branch
            BasicBlock* thenExit = translateStatement(thenStmt, thenBlock);
            thenExit->addInstruction(TAC(TACOp::JUMP, mergeBlock->label));
            thenExit->trueExit = mergeBlock;
        }

        return mergeBlock;
    }

    // WhileStatement: while (cond) stmt
    if (type == "WhileStatement") {
        auto it = stmt->children.begin();
        Node* condExpr = *it++;
        Node* bodyStmt = *it;

        // Create blocks: condition, body, exit
        BasicBlock* condBlock = program.newBlock();
        currentMethod->allBlocks.push_back(condBlock);
        BasicBlock* bodyBlock = program.newBlock();
        currentMethod->allBlocks.push_back(bodyBlock);
        BasicBlock* exitBlock = program.newBlock();
        currentMethod->allBlocks.push_back(exitBlock);

        // Current block jumps to condition block
        currentBlock->addInstruction(TAC(TACOp::JUMP, condBlock->label));
        currentBlock->trueExit = condBlock;

        // Condition block: evaluate condition, branch
        currentBlock = condBlock;
        string condTemp = translateExpression(condExpr);
        condBlock->addInstruction(TAC(TACOp::COND_JUMP, exitBlock->label, condTemp));
        condBlock->condition = condTemp;
        condBlock->trueExit = bodyBlock;
        condBlock->falseExit = exitBlock;

        // Body block: execute body, jump back to condition
        BasicBlock* bodyExit = translateStatement(bodyStmt, bodyBlock);
        bodyExit->addInstruction(TAC(TACOp::JUMP, condBlock->label));
        bodyExit->trueExit = condBlock;

        return exitBlock;
    }

    // Fallback: unknown statement type
    return block;
}

void IRGenerator::translateMethod(Node* methodDecl, const string& className) {
    // methodDecl->value = method name
    // children[0] = return type
    // children[1] = method Identifier
    // children[2] = MethodDeclarationParamsOpt
    // children[3] = MethodDeclarationBody
    // children[4] = return expression

    auto it = methodDecl->children.begin();
    Node* returnType = *it++;
    Node* methodId = *it++;
    Node* paramsOpt = *it++;
    Node* body = *it++;
    Node* returnExpr = *it;

    string methodName = methodId->value;

    // Create method CFG
    MethodCFG* method = new MethodCFG(className + "." + methodName);
    currentMethod = method;

    // Create entry block
    BasicBlock* entryBlock = program.newBlock();
    method->entryBlock = entryBlock;
    method->allBlocks.push_back(entryBlock);
    currentBlock = entryBlock;

    // Extract parameters from MethodDeclarationParamsOpt
    // Structure: MethodDeclarationParamsOpt -> ParameterList -> Parameter nodes
    // Parameter: children[0]=type, children[1]=identifier
    if (paramsOpt && !paramsOpt->children.empty()) {
        // paramsOpt has one child: ParameterList
        Node* paramList = paramsOpt->children.front();
        if (paramList && paramList->type == "ParameterList") {
            // ParameterList contains all Parameter nodes as children
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
    // - VarDeclaration nodes: add to localVars
    // - Statement nodes: translate
    BasicBlock* exitBlock = entryBlock;
    if (body && !body->children.empty()) {
        for (Node* child : body->children) {
            if (child->type == "VarDeclaration") {
                // VarDeclaration: children[0]=type, children[1]=identifier
                auto varIt = child->children.begin();
                ++varIt;  // skip type
                Node* varId = *varIt;
                method->localVars.push_back(varId->value);
            } else {
                // It's a statement
                exitBlock = translateStatement(child, exitBlock);
            }
        }
    }

    // Translate return expression
    currentBlock = exitBlock;
    string returnTemp = translateExpression(returnExpr);
    currentBlock->addInstruction(TAC(TACOp::RETURN, returnTemp));

    // Add method to program
    program.methods.push_back(method);
}

void IRGenerator::translateClass(Node* classDecl) {
    // classDecl->value = class name
    // children[0] = class Identifier
    // children[1] = VarDeclarationCL (class variables - skip for now)
    // children[2] = MethodDeclarationCL

    string className = classDecl->value;

    auto it = classDecl->children.begin();
    Node* classId = *it++;
    Node* varDeclList = *it++;
    Node* methodDeclList = *it;

    // Iterate MethodDeclarationCL children
    // For each MethodDeclaration: translateMethod(method, className)
    if (methodDeclList && !methodDeclList->children.empty()) {
        for (Node* methodDecl : methodDeclList->children) {
            translateMethod(methodDecl, className);
        }
    }
}

void IRGenerator::translateMainClass(Node* mainClass) {
    // mainClass->value = class name
    // children[0] = class Identifier
    // children[1] = MainClassParams
    // MainClassParams structure:
    //   children[0] = args Identifier
    //   children[1] = first Statement
    //   children[2] = StatementList (remaining statements)

    string className = mainClass->value;

    auto it = mainClass->children.begin();
    Node* classId = *it++;
    Node* mainParams = *it;

    // Create method CFG with name "ClassName.main"
    MethodCFG* method = new MethodCFG(className + ".main");
    currentMethod = method;

    // Create entry block
    BasicBlock* entryBlock = program.newBlock();
    method->entryBlock = entryBlock;
    method->allBlocks.push_back(entryBlock);
    currentBlock = entryBlock;

    // Process MainClassParams
    auto paramIt = mainParams->children.begin();
    Node* argsId = *paramIt++;       // args Identifier (skip)
    Node* firstStmt = *paramIt++;    // first Statement
    Node* stmtList = *paramIt;       // StatementList (remaining statements)

    // Translate first statement
    BasicBlock* exitBlock = translateStatement(firstStmt, entryBlock);

    // Iterate StatementList and translate each
    if (stmtList && !stmtList->children.empty()) {
        for (Node* stmt : stmtList->children) {
            exitBlock = translateStatement(stmt, exitBlock);
        }
    }

    // Add STOP instruction at the end
    currentBlock = exitBlock;
    currentBlock->addInstruction(TAC(TACOp::STOP, ""));

    // Add method to program.methods
    program.methods.push_back(method);
}

void IRGenerator::writeDotFile(const string& filename) {
    program.toDotFile(filename);
}
