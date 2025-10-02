#include "CFG.hh"
#include "Node.h"

class IRGenerator {
private:
    CFG* cfg;
    int tempCounter;
    
public:
    IRGenerator() : tempCounter(0) {
        cfg = new CFG();
    }
    
    string genTemp();
    
    CFG* generateIR(Node* ast);
    
    
    string genBinaryExpr(BasicBlock* currentBlock, string op, string leftChild, string rightChild);
    
    // Generate IR for unary expression (like !x)
    string genUnaryExpr(BasicBlock* currentBlock, string op /* child */);
    
    // Generate IR for identifier (just return the name)
    string genIdentifier(BasicBlock* currentBlock, string name);
    
    // Generate IR for integer literal
    string genInteger(BasicBlock* currentBlock, int value);
    
    
    // Generate IR for assignment statement (x = expr)
    BasicBlock* genAssignment(BasicBlock* currentBlock, string varName /* expression node */);
    
    // Generate IR for if-else statement
    BasicBlock* genIfElse(BasicBlock* currentBlock /* condition, thenStmt, elseStmt */);
    
    // Generate IR for while statement
    BasicBlock* genWhile(BasicBlock* currentBlock /* condition, body */);
    
    // Generate IR for sequence of statements
    BasicBlock* genSequence(BasicBlock* currentBlock /* list of statements */);
};