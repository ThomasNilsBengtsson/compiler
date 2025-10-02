#include "TAC.hh"

class BasicBlock {
public:
    string name;                    // Unique name like "block_0", "block_1", etc.
    vector<Tac*> instructions;      // List of TAC instructions in this block
    BasicBlock* trueExit;              // Where to go if condition is true (or next block)
    BasicBlock* falseExit;             // Where to go if condition is false
    
    BasicBlock();

    void addInstruction(Tac* instruction);
};