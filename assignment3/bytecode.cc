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
            int srcIdx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(srcIdx));
            method.instructions.push_back("inot");
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::PRINT: {
            int idx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("iload " + to_string(idx));
            method.instructions.push_back("print");
            break;
        }

        case TACOp::JUMP: {
            method.instructions.push_back("goto " + tac.result);
            break;
        }

        case TACOp::COND_JUMP: {
            int idx = method.getOrCreateVar(tac.arg1);
            method.instructions.push_back("iload " + to_string(idx));
            method.instructions.push_back("iffalse goto " + tac.result);
            break;
        }

        case TACOp::PARAM: {
            // Push parameter onto data stack for callee
            int idx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("iload " + to_string(idx));
            break;
        }

        case TACOp::CALL: {
            // invokevirtual QualifiedMethodName numArgs
            method.instructions.push_back("invokevirtual " + tac.arg1 + " " + to_string(tac.numArgs));
            int dstIdx = method.getOrCreateVar(tac.result);
            method.instructions.push_back("istore " + to_string(dstIdx));
            break;
        }

        case TACOp::RETURN: {
            if (!tac.result.empty()) {
                int idx = method.getOrCreateVar(tac.result);
                method.instructions.push_back("iload " + to_string(idx));
            }
            method.instructions.push_back("ireturn");
            break;
        }

        case TACOp::NEW_OBJECT: {
            // new ClassName -> pushes object reference onto stack, store in local
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
        if (block->trueExit != nextBlock) {
            method.instructions.push_back("goto " + block->trueExit->label);
        }
    }
}

void BytecodeGenerator::
translateMethod(MethodCFG* cfg) {
    MethodBytecode method;
    method.name = cfg->name;

    // Build full parameter list: "this" first (for non-main methods), then declared params
    vector<string> allParams;
    bool isMainMethod = (cfg->name.find(".main") != string::npos && cfg->parameters.empty());
    if (!isMainMethod) {
        allParams.push_back("this");
    }
    for (const string& param : cfg->parameters) {
        allParams.push_back(param);
    }

    // Pre-register all parameters with sequential indices
    for (const string& param : allParams) {
        method.getOrCreateVar(param);
    }

    for (int i = allParams.size() - 1; i >= 0; i--) {
        int idx = method.varIndex[allParams[i]];
        method.instructions.push_back("istore " + to_string(idx));
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

    // Remove redundant istore/iload pairs
    optimize(method);

    methods.push_back(method);
}

void BytecodeGenerator::optimize(MethodBytecode& method) {
    auto& ins = method.instructions;

    {
        vector<string> opt;
        size_t i = 0;
        while (i < ins.size()) {
            if (i + 1 < ins.size()) {
                const string& curr = ins[i];
                const string& next = ins[i + 1];
                if (curr.substr(0, 7) == "istore " && next.substr(0, 6) == "iload ") {
                    if (curr.substr(7) == next.substr(6)) {
                        i += 2;
                        continue;
                    }
                }
            }
            opt.push_back(ins[i]);
            i++;
        }
        ins = opt;
    }

    {
        // Count how many times each local index is stored and loaded
        map<string, int> storeCount, loadCount;
        for (const string& s : ins) {
            if (s.substr(0, 7) == "istore ") storeCount[s.substr(7)]++;
            if (s.substr(0, 6) == "iload ")  loadCount[s.substr(6)]++;
        }


        map<string, string> replacement;  // local index -> replacement instruction
        set<size_t> toRemove;

        for (size_t i = 0; i + 1 < ins.size(); i++) {
            const string& curr = ins[i];
            const string& next = ins[i + 1];
            if (next.substr(0, 7) != "istore ") continue;
            string idx = next.substr(7);

            bool isConst = (curr.substr(0, 7) == "iconst ");
            bool isLoad  = (curr.substr(0, 6) == "iload ");
            if (!isConst && !isLoad) continue;

            // Only optimize temps stored once and loaded once
            if (storeCount[idx] == 1 && loadCount[idx] == 1) {
                replacement[idx] = curr;  // replace "iload N" with this
                toRemove.insert(i);       // remove the source instruction
                toRemove.insert(i + 1);   // remove the istore
            }
        }

        vector<string> opt;
        for (size_t i = 0; i < ins.size(); i++) {
            if (toRemove.count(i)) continue;
            const string& s = ins[i];
            if (s.substr(0, 6) == "iload ") {
                string idx = s.substr(6);
                auto it = replacement.find(idx);
                if (it != replacement.end()) {
                    opt.push_back(it->second);
                    continue;
                }
            }
            opt.push_back(s);
        }
        ins = opt;
    }
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
