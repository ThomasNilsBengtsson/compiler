#include "bytecode.h"
#include <fstream>
#include <iostream>
#include <set>

int BytecodeGenerator::MethodBytecode::getOrCreateVar(const string& name) {
    if (varIndex.find(name) == varIndex.end()) {
        varIndex[name] = nextVarIndex++;
    }
    return varIndex[name];
}

void BytecodeGenerator::translateTAC(const TAC& tac, MethodBytecode& method) {
    switch (tac.op) {
        case TACOp::COPY_CONST: {
            // x = 5  ->  iconst 5; istore [x]
            method.instructions.push_back("iconst " + tac.arg1);
            int idx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(idx));
            break;
        }

        case TACOp::COPY: {
            // x = y  ->  iload [y]; istore [x]
            int srcIdx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(srcIdx));
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::ADD: {
            // x = y + z  ->  iload [y]; iload [z]; iadd; istore [x]
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("iadd");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::SUB: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("isub");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::MUL: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("imul");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::DIV: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("idiv");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::LT: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("ilt");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::GT: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("igt");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::EQ: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("ieq");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::AND: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("iand");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::OR: {
            int idx1 = method.getOrCreateVar(tac.arg1);
            int idx2 = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(idx1));
            method.instructions.push_back("iload " + to_string(idx2));
            method.instructions.push_back("ior");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::NOT: {
            // x = !y  ->  iload [y]; inot; istore [x]
            int srcIdx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(srcIdx));
            method.instructions.push_back("inot");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::PRINT: {
            // print x  ->  iload [x]; print
            int idx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("iload " + to_string(idx));
            method.instructions.push_back("print");
            break;
        }

        case TACOp::JUMP: {
            // goto L  ->  goto L
            method.instructions.push_back("goto " + tac.result);
            break;
        }

        case TACOp::COND_JUMP: {
            // iffalse x goto L  ->  iload [x]; iffalse goto L
            int idx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(idx));
            method.instructions.push_back("iffalse goto " + tac.result);
            break;
        }

        case TACOp::PARAM: {
            // param x  ->  iload [x]  (push parameter onto stack)
            int idx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("iload " + to_string(idx));
            break;
        }

        case TACOp::CALL: {
            // x = call method n  ->  invokevirtual method n; istore [x]
            method.instructions.push_back("invokevirtual " + tac.arg1 + " " + to_string(tac.numArgs));
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::RETURN: {
            // return x  ->  iload [x]; ireturn
            if (!tac.result.empty()) {
                int idx = method.getOrCreateVar(tac.result);
                method.instructions.push_back("iload " + to_string(idx));
            }
            method.instructions.push_back("ireturn");
            break;
        }

        case TACOp::ARRAY_ACCESS: {
            // x = y[z]  ->  iload [y]; iload [z]; iaload; istore [x]
            int arrIdx = method.getOrCreateVar(tac.arg1);
            int indexIdx = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(arrIdx));
            method.instructions.push_back("iload " + to_string(indexIdx));
            method.instructions.push_back("iaload");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::ARRAY_ASSIGN: {
            // x[y] = z  ->  iload [x]; iload [y]; iload [z]; iastore
            int arrIdx = method.getOrCreateVar(tac.result);
            int indexIdx = method.getOrCreateVar(tac.arg1);
            int valIdx = method.getOrCreateVar(tac.arg2);
            method.instructions.push_back("iload " + to_string(arrIdx));
            method.instructions.push_back("iload " + to_string(indexIdx));
            method.instructions.push_back("iload " + to_string(valIdx));
            method.instructions.push_back("iastore");
            break;
        }

        case TACOp::ARRAY_LENGTH: {
            // x = length y  ->  iload [y]; arraylength; istore [x]
            int arrIdx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(arrIdx));
            method.instructions.push_back("arraylength");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::NEW_ARRAY: {
            // x = new int[y]  ->  iload [y]; newarray; istore [x]
            int sizeIdx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(sizeIdx));
            method.instructions.push_back("newarray");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::NEW_OBJECT: {
            // x = new Class  ->  new Class; istore [x]
            method.instructions.push_back("new " + tac.arg1);
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::STOP: {
            method.instructions.push_back("stop");
            break;
        }
    }
}

void BytecodeGenerator::translateBlock(BasicBlock* block, MethodBytecode& method, BasicBlock* nextBlock) {
    // Add block label
    method.instructions.push_back(block->label + ":");

    // Translate all instructions in the block
    for (const TAC& tac : block->instructions) {
        translateTAC(tac, method);
    }

    // If this is a conditional block (has both trueExit and falseExit),
    // and the trueExit is not the next block, add explicit goto
    if (block->trueExit && block->falseExit) {
        // The iffalse instruction already jumps to falseExit
        // We need to add goto trueExit if it's not the next block
        if (block->trueExit != nextBlock) {
            method.instructions.push_back("goto " + block->trueExit->label);
        }
    }
}

void BytecodeGenerator::translateMethod(MethodCFG* cfg) {
    MethodBytecode method;
    method.name = cfg->name;

    // Pre-register parameters with indices
    for (const string& param : cfg->parameters) {
        method.getOrCreateVar(param);
    }

    // Collect all blocks in order (BFS from entry)
    vector<BasicBlock*> orderedBlocks;
    set<BasicBlock*> visited;

    vector<BasicBlock*> worklist;
    if (cfg->entryBlock) {
        worklist.push_back(cfg->entryBlock);
    }

    while (!worklist.empty()) {
        BasicBlock* block = worklist.front();
        worklist.erase(worklist.begin());

        if (visited.count(block)) continue;
        visited.insert(block);
        orderedBlocks.push_back(block);

        if (block->trueExit && !visited.count(block->trueExit)) {
            worklist.push_back(block->trueExit);
        }
        if (block->falseExit && !visited.count(block->falseExit)) {
            worklist.push_back(block->falseExit);
        }
    }

    // Translate each block
    for (size_t i = 0; i < orderedBlocks.size(); i++) {
        BasicBlock* nextBlock = (i + 1 < orderedBlocks.size()) ? orderedBlocks[i + 1] : nullptr;
        translateBlock(orderedBlocks[i], method, nextBlock);
    }

    methods.push_back(method);
}

void BytecodeGenerator::generate(IRProgram& program) {
    methods.clear();

    for (MethodCFG* cfg : program.methods) {
        translateMethod(cfg);
    }
}

void BytecodeGenerator::writeToFile(const string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    for (const MethodBytecode& method : methods) {
        out << method.name << ":" << endl;
        for (const string& instr : method.instructions) {
            // Don't indent block labels
            if (instr.back() == ':') {
                out << instr << endl;
            } else {
                out << "    " << instr << endl;
            }
        }
        out << endl;
    }

    out.close();
}

void BytecodeGenerator::print() {
    for (const MethodBytecode& method : methods) {
        cout << method.name << ":" << endl;
        for (const string& instr : method.instructions) {
            if (instr.back() == ':') {
                cout << instr << endl;
            } else {
                cout << "    " << instr << endl;
            }
        }
        cout << endl;
    }
}
