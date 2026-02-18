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

    void writeDotFile(const string& filename);

    IRProgram& getProgram() { return program; }
};

#endif
