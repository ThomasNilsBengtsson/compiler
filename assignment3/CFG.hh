#include "BasicBlock.hh"

class CFG
{
private:
    BasicBlock *entry;
    vector<BasicBlock *> allBlocks;

public:
    CFG() : entry(nullptr) {}

    BasicBlock *createBlock();

    void generateDotFile(string filename);
};