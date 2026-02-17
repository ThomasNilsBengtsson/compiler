#include "ir.h"
#include <fstream>
#include <sstream>

// Convert TACOp to string for output
static string opToString(TACOp op) {
    switch (op) {
        case TACOp::ADD: return "ADD";
        case TACOp::SUB: return "SUB";
        case TACOp::MUL: return "MUL";
        case TACOp::DIV: return "DIV";
        case TACOp::LT:  return "LT";
        case TACOp::GT:  return "GT";
        case TACOp::EQ:  return "EQ";
        case TACOp::AND: return "AND";
        case TACOp::OR:  return "OR";
        default: return "";
    }
}

string TAC::toString() const {
    stringstream ss;

    switch (op) {
        case TACOp::COPY:
            ss << result << " = " << arg1;
            break;

        case TACOp::COPY_CONST:
            ss << result << " = " << arg1;
            break;

        case TACOp::ADD:
        case TACOp::SUB:
        case TACOp::MUL:
        case TACOp::DIV:
        case TACOp::LT:
        case TACOp::GT:
        case TACOp::EQ:
        case TACOp::AND:
        case TACOp::OR:
            ss << result << " = " << arg1 << " " << opToString(op) << " " << arg2;
            break;

        case TACOp::NOT:
            ss << result << " = NOT " << arg1;
            break;

        case TACOp::JUMP:
            ss << "goto " << result;
            break;

        case TACOp::COND_JUMP:
            ss << "iffalse " << arg1 << " goto " << result;
            break;

        case TACOp::PARAM:
            ss << "param " << result;
            break;

        case TACOp::CALL:
            ss << result << " = call " << arg1 << " " << numArgs;
            break;

        case TACOp::RETURN:
            ss << "return " << result;
            break;

        case TACOp::PRINT:
            ss << "print " << result;
            break;

        case TACOp::ARRAY_ACCESS:
            ss << result << " = " << arg1 << "[" << arg2 << "]";
            break;

        case TACOp::ARRAY_ASSIGN:
            ss << result << "[" << arg1 << "] = " << arg2;
            break;

        case TACOp::ARRAY_LENGTH:
            ss << result << " = length " << arg1;
            break;

        case TACOp::NEW_ARRAY:
            ss << result << " = new int[" << arg1 << "]";
            break;

        case TACOp::NEW_OBJECT:
            ss << result << " = new " << arg1;
            break;

        case TACOp::STOP:
            ss << "stop";
            break;
    }

    return ss.str();
}

// BasicBlock implementation
void BasicBlock::addInstruction(const TAC& tac) {
    instructions.push_back(tac);
}

string BasicBlock::toDot() const {
    stringstream ss;

    // Node definition with label containing instructions
    ss << "    \"" << label << "\" [shape=box, label=\"" << label << "\\n";
    for (const auto& instr : instructions) {
        // Escape special characters for dot format
        string s = instr.toString();
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '"') ss << "\\\"";
            else if (s[i] == '<') ss << "\\<";
            else if (s[i] == '>') ss << "\\>";
            else ss << s[i];
        }
        ss << "\\n";
    }
    ss << "\"];\n";

    // Edges
    if (trueExit && falseExit) {
        // Conditional branch
        ss << "    \"" << label << "\" -> \"" << trueExit->label << "\" [label=\"true\"];\n";
        ss << "    \"" << label << "\" -> \"" << falseExit->label << "\" [label=\"false\"];\n";
    } else if (trueExit) {
        // Unconditional jump
        ss << "    \"" << label << "\" -> \"" << trueExit->label << "\";\n";
    }

    return ss.str();
}

// MethodCFG implementation
MethodCFG::~MethodCFG() {
    for (auto* block : allBlocks) {
        delete block;
    }
}

// IRProgram implementation
IRProgram::~IRProgram() {
    for (auto* method : methods) {
        delete method;
    }
}

string IRProgram::newTemp() {
    return "_t" + to_string(tempCounter++);
}

BasicBlock* IRProgram::newBlock() {
    string label = "block_" + to_string(blockCounter++);
    return new BasicBlock(label);
}

void IRProgram::toDotFile(const string& filename) const {
    ofstream out(filename);

    out << "digraph CFG {\n";
    out << "    node [fontname=\"Courier\"];\n";
    out << "    edge [fontname=\"Courier\"];\n\n";

    for (const auto* method : methods) {
        // Create a subgraph for each method
        // Replace '.' with '_' for valid DOT identifier
        string clusterId = method->name;
        for (char& c : clusterId) {
            if (c == '.') c = '_';
        }
        out << "    subgraph cluster_" << clusterId << " {\n";
        out << "        label=\"" << method->name << "\";\n";
        out << "        style=rounded;\n";

        for (const auto* block : method->allBlocks) {
            // Indent the block's dot output
            string blockDot = block->toDot();
            out << "    " << blockDot;
        }

        out << "    }\n\n";
    }

    out << "}\n";
    out.close();
}
