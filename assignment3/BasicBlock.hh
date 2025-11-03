#ifndef BASICBLOCK_HH
#define BASICBLOCK_HH
#include "TAC.hh"

class BasicBlock{
    private:
        int blockNumber;
        vector<BasicBlock> allBasicBlock;
        vector<TAC> threeAdressInstruct;
    public:
        void insertTACIntoBlock();
};

#endif