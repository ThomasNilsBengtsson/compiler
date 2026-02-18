#ifndef IR_HH
#define IR_HH

#include <string>
#include <vector>

using namespace std;

// Three-Address Code operation types
// Only includes operations needed for assignment3_valid test cases.
enum class TACOp {
    COPY,       // x = y
    COPY_CONST, // x = 5
    ADD,        // x = y + z
    SUB,        // x = y - z
    MUL,        // x = y * z
    LT,         // x = y < z
    GT,         // x = y > z
    EQ,         // x = y == z
    AND,        // x = y && z
    OR,         // x = y || z
    NOT,        // x = !y
    JUMP,       // goto L
    COND_JUMP,  // iffalse x goto L
    PARAM,      // param x
    CALL,       // x = call method n
    RETURN,     // return x
    PRINT,      // print x
    NEW_OBJECT, // x = new Class
    STOP        // stop
};

// Three-Address Code instruction
struct TAC {
    TACOp op;
    string result;  // destination
    string arg1;    // first operand
    string arg2;    // second operand (or label for jumps)
    int numArgs;    // for CALL

    TAC() : op(TACOp::STOP), numArgs(0) {}
    TAC(TACOp o, const string& r, const string& a1 = "", const string& a2 = "", int n = 0)
        : op(o), result(r), arg1(a1), arg2(a2), numArgs(n) {}

    string toString() const;
};

// Basic block in the control flow graph
class BasicBlock {
public:
    string label;
    vector<TAC> instructions;
    BasicBlock* trueExit = nullptr;
    BasicBlock* falseExit = nullptr;
    string condition;  // for conditional branches

    BasicBlock(const string& lbl) : label(lbl) {}

    void addInstruction(const TAC& tac);
    string toDot() const;
};

// Control flow graph for a single method
class MethodCFG {
public:
    string name;  // qualified: "ClassName.methodName"
    BasicBlock* entryBlock = nullptr;
    vector<string> parameters;
    vector<string> localVars;
    vector<BasicBlock*> allBlocks;

    MethodCFG(const string& n) : name(n) {}
    ~MethodCFG();
};

// IR for the entire program
class IRProgram {
public:
    vector<MethodCFG*> methods;
    int tempCounter = 0;
    int blockCounter = 0;

    ~IRProgram();

    string newTemp();
    BasicBlock* newBlock();
    void toDotFile(const string& filename) const;
};

#endif
