#include "CFG.hh"

BasicBlock *CFG::createBlock()
{
        BasicBlock* newBlock = new BasicBlock();
        allBlocks.push_back(newBlock);
        if (!entry) {
            entry = newBlock;
        }
        return newBlock;
}

void CFG::generateDotFile(string filename)
{
    ofstream out(filename);
        out << "digraph {" << endl;
        out << "  graph [splines=ortho]" << endl;
        out << "  node [shape=box];" << endl;
        
        for (BasicBlock* block : allBlocks) {
            out << "  " << block->name << " [label=\"" << block->name << "\\n";
            
            for (Tac* inst : block->instructions) {
                if (inst->op == "goto") {
                    out << "goto " << inst->result << "\\n";
                } else if (inst->op == "iffalse") {
                    out << "iffalse " << inst->lhs << " goto " << inst->result << "\\n";
                } else if (inst->op == ":=") {
                    out << inst->result << " := " << inst->lhs << "\\n";
                } else if (inst->rhs.empty()) {
                    out << inst->result << " := " << inst->op << " " << inst->lhs << "\\n";
                } else {
                    out << inst->result << " := " << inst->lhs << " " << inst->op << " " << inst->rhs << "\\n";
                }
            }
            out << "\"];" << endl;
            
            if (block->trueExit) {
                out << "  " << block->name << " -> " << block->trueExit->name;
                if (block->falseExit) {
                    out << " [xlabel=\"true\"]";
                }
                out << ";" << endl;
            }
            if (block->falseExit) {
                out << "  " << block->name << " -> " << block->falseExit->name;
                out << " [xlabel=\"false\"];" << endl;
            }
        }
        
        out << "}" << endl;
        out.close();
}
