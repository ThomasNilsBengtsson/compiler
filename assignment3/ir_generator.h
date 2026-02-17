#ifndef IR_GENERATOR_H
#define IR_GENERATOR_H

#include "Node.h"
#include "ir.h"

class IRGenerator {
private:
    IRProgram program;
    BasicBlock* currentBlock;
    MethodCFG* currentMethod;

public:
    IRGenerator();

    // Main entry point
    void generate(Node* root);

    // Returns the temp variable holding the expression result
    string translateExpression(Node* expr);

    // Returns the exit block after the statement
    BasicBlock* translateStatement(Node* stmt, BasicBlock* block);

    // Structural translation
    void translateMethod(Node* methodDecl, const string& className);
    void translateClass(Node* classDecl);
    void translateMainClass(Node* mainClass);

    // Output
    void writeDotFile(const string& filename);

    IRProgram& getProgram() { return program; }
};

#endif
