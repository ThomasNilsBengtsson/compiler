#include "ir.hh"
#include <fstream>
#include <sstream>

// Convert binary TACOp to string for output
static string opToString(TACOp op) {
    switch (op) {
        case TACOp::ADD: return "ADD";
        case TACOp::SUB: return "SUB";
        case TACOp::MUL: return "MUL";
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

    ss << "    \"" << label << "\" [shape=box, label=\"" << label << "\\n";
    for (const auto& instr : instructions) {
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

    if (trueExit && falseExit) {
        ss << "    \"" << label << "\" -> \"" << trueExit->label << "\" [label=\"true\"];\n";
        ss << "    \"" << label << "\" -> \"" << falseExit->label << "\" [label=\"false\"];\n";
    } else if (trueExit) {
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
        string clusterId = method->name;
        for (char& c : clusterId) {
            if (c == '.') c = '_';
        }
        out << "    subgraph cluster_" << clusterId << " {\n";
        out << "        label=\"" << method->name << "\";\n";
        out << "        style=rounded;\n";

        for (const auto* block : method->allBlocks) {
            string blockDot = block->toDot();
            out << "    " << blockDot;
        }

        out << "    }\n\n";
    }

    out << "}\n";
    out.close();
}
