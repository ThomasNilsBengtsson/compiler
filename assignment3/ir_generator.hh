#ifndef IR_GENERATOR_HH
#define IR_GENERATOR_HH

#include <vector>
#include "Node.h"
#include "ir.hh"

class IRGenerator {
private:
    IRProgram program;
    BasicBlock* currentBlock;
    MethodCFG* currentMethod;
    string currentClassName;
    vector<Node*> parents;
    Node* root;

public:
    IRGenerator() : currentBlock(nullptr), currentMethod(nullptr), currentClassName(""), root(nullptr) {}

    void generate(Node* root);

    void visitNode(Node* node);
    void visitMainClass(Node* node);
    void visitClass(Node* node);
    void visitMethod(Node* node);

    string visitExpression(Node* node);
    BasicBlock* visitStatement(Node* node, BasicBlock* block);

    // Generates short-circuit condition code for && and ||.
    // On return, currentBlock is the last condition block created.
    void visitCondition(Node* condExpr, BasicBlock* trueBlock, BasicBlock* falseBlock);

    // Post-processing: removes blocks that contain only a single goto.
    void eliminatePassthroughBlocks(MethodCFG* method);

    void writeDotFile(const string& filename);

    IRProgram& getProgram() { return program; }
};

#endif
