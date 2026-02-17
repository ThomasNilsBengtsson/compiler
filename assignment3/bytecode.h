#ifndef BYTECODE_H
#define BYTECODE_H

#include <string>
#include <vector>
#include <map>
#include "ir.h"

using namespace std;

class BytecodeGenerator {
private:
    struct MethodBytecode {
        string name;
        vector<string> instructions;
        map<string, int> varIndex;  // variable name -> index
        int nextVarIndex = 0;

        int getOrCreateVar(const string& name);
    };

    vector<MethodBytecode> methods;

    // Translate a single TAC instruction to bytecode
    void translateTAC(const TAC& tac, MethodBytecode& method);

    // Translate a basic block
    void translateBlock(BasicBlock* block, MethodBytecode& method, BasicBlock* nextBlock);

    // Translate a method CFG
    void translateMethod(MethodCFG* cfg);

    // Peephole optimization: remove redundant istore/iload pairs
    void peepholeOptimize(MethodBytecode& method);

public:
    void generate(IRProgram& program);
    void writeToFile(const string& filename);

    // For debugging
    void print();
};

#endif
