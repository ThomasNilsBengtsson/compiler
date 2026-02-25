#ifndef BYTECODE_H
#define BYTECODE_H

#include <string>
#include <vector>
#include <map>
#include "ir.hh"

using namespace std;

class BytecodeGenerator {
private:
    struct MethodBytecode {
        string name;
        vector<string> instructions;
        map<string, int> varIndex;
        int nextVarIndex = 0;

        int getOrCreateVar(const string& name);
    };

    vector<MethodBytecode> methods;

    void translateTAC(const TAC& tac, MethodBytecode& method);

    void translateBlock(BasicBlock* block, MethodBytecode& method, BasicBlock* nextBlock);

    void translateMethod(MethodCFG* cfg);

    void optimize(MethodBytecode& method);

public:
    void generate(IRProgram& program);
    void writeToFile(const string& filename);

    void print();
};

#endif
