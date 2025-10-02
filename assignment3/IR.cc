#include "IR.hh"

string IRGenerator::genTemp()
{
    return "t" + to_string(tempCounter++);
}

CFG *IRGenerator::generateIR(Node *ast)
{
    BasicBlock* currentBlock = cfg->createBlock();

    //Traverse ast

    return cfg;
}

string IRGenerator::genBinaryExpr(BasicBlock *currentBlock, string op, string leftChild, string rightChild)
{
        // Step 1: Generate code for left child
        string leftResult = ""; // = genExpr(currentBlock, leftChild);
        
        // Step 2: Generate code for right child  
        string rightResult = ""; // = genExpr(currentBlock, rightChild);
        
        // Step 3: Create TAC for this operation
        string tempVar = genTemp();
        Tac* instruction = new Tac();
        instruction->result = tempVar;
        instruction->op = op;
        instruction->lhs = leftResult;
        instruction->rhs = rightResult;
        
        // Step 4: Add to current block
        currentBlock->addInstruction(instruction);
        
        return tempVar;  // Return the temp variable holding result
}

string IRGenerator::genUnaryExpr(BasicBlock *currentBlock, string op)
{
        // Step 1: Generate code for child
        string childResult = ""; // = genExpr(currentBlock, child);
        
        // Step 2: Create TAC
        string tempVar = genTemp();
        Tac* instruction = new Tac();
        instruction->result = tempVar;
        instruction->op = op;
        instruction->lhs = childResult;
        instruction->rhs = "";  // No right operand for unary
        
        // Step 3: Add to current block
        currentBlock->addInstruction(instruction);
        
        return tempVar;
}

string IRGenerator::genIdentifier(BasicBlock *currentBlock, string name)
{
        return name;
}

string IRGenerator::genInteger(BasicBlock *currentBlock, int value)
{
    return to_string(value);
}

BasicBlock *IRGenerator::genAssignment(BasicBlock *currentBlock, string varName)
{
        // Step 1: Generate code for expression
        string exprResult = ""; // = genExpr(currentBlock, exprNode);
        
        // Step 2: Create copy instruction
        Tac* instruction = new Tac();
        instruction->result = varName;
        instruction->op = ":=";
        instruction->lhs = exprResult;
        instruction->rhs = "";
        
        // Step 3: Add to current block
        currentBlock->addInstruction(instruction);
        
        return currentBlock;  // Assignment doesn't create new blocks
}

BasicBlock *IRGenerator::genIfElse(BasicBlock *currentBlock)
{
        // Step 1: Evaluate condition in current block
        string condResult = ""; // = genExpr(currentBlock, condition);
        
        // Step 2: Create blocks for then and else branches
        BasicBlock* thenBlock = cfg->createBlock();
        BasicBlock* elseBlock = cfg->createBlock();
        
        // Step 3: Create rejoin block (where both branches meet)
        BasicBlock* joinBlock = cfg->createBlock();
        
        // Step 4: Add conditional jump to current block
        Tac* jumpInst = new Tac();
        jumpInst->op = "iffalse";
        jumpInst->lhs = condResult;
        jumpInst->result = elseBlock->name;
        currentBlock->addInstruction(jumpInst);
        
        // Step 5: Connect current block to branches
        currentBlock->trueExit = thenBlock;
        currentBlock->falseExit = elseBlock;
        
        // Step 6: Generate code for then branch
        // genStatement(thenBlock, thenStmt);
        thenBlock->trueExit = joinBlock;
        
        // Step 7: Generate code for else branch
        // genStatement(elseBlock, elseStmt);
        elseBlock->trueExit = joinBlock;
        
        return joinBlock;  // Return the join block for next statements
}

BasicBlock *IRGenerator::genSequence(BasicBlock *currentBlock)
{
        BasicBlock* current = currentBlock;
        
        // Process each statement in sequence
        // for (each statement) {
        //     current = genStatement(current, statement);
        // }
        
        return current;
}

BasicBlock *IRGenerator::genWhile(BasicBlock *currentBlock)
{
        // Step 1: Create loop header block (evaluates condition)
        BasicBlock* loopHeader = cfg->createBlock();
        currentBlock->trueExit = loopHeader;
        
        // Step 2: Create loop body block
        BasicBlock* loopBody = cfg->createBlock();
        
        // Step 3: Create exit block (after loop)
        BasicBlock* exitBlock = cfg->createBlock();
        
        // Step 4: Evaluate condition in loop header
        string condResult = ""; // = genExpr(loopHeader, condition);
        
        // Step 5: Add conditional jump
        Tac* jumpInst = new Tac();
        jumpInst->op = "iffalse";
        jumpInst->lhs = condResult;
        jumpInst->result = exitBlock->name;
        loopHeader->addInstruction(jumpInst);
        
        // Step 6: Connect loop header to body and exit
        loopHeader->trueExit = loopBody;
        loopHeader->falseExit = exitBlock;
        
        // Step 7: Generate code for loop body
        // genStatement(loopBody, body);
        
        // Step 8: Connect body back to header (loop back)
        loopBody->trueExit = loopHeader;
        
        return exitBlock;  // Return exit block for next statements
}
