#include "BasicBlock.hh"

BasicBlock::BasicBlock()
{
    this->trueExit = nullptr;
    this->falseExit = nullptr;
    static int counter = 0;
    this->name = "block_" + to_string(counter++);
}

void BasicBlock::addInstruction(Tac *instruction)
{
    instructions.push_back(instruction);
}
