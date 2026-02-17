#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Interpreter {
private:
    // Activation record for method calls
    struct ActivationRecord {
        string methodName;
        int returnMethod;           // Method index to return to
        int returnAddress;          // Instruction to return to
        vector<int> locals;         // Local variables
    };

    // Method representation
    struct Method {
        string name;
        vector<string> instructions;
        map<string, int> labelToPC;  // Label -> instruction index
    };

    // Data stack for computation
    stack<int> dataStack;

    // Call stack for method invocations
    stack<ActivationRecord> callStack;

    // Loaded program
    vector<Method> methods;

    // Execution state
    int currentMethod;
    int pc;              // Program counter
    bool stopped;        // Execution halted

    // Helper methods
    void executeInstruction(const string& instr);
    Method* findMethod(const string& name);
    int findMethodIndex(const string& name);
    int findLabel(const string& label);
    vector<int>& currentLocals();

    // Parsing helpers
    bool startsWith(const string& str, const string& prefix);
    int parseIntArg(const string& instr);
    string parseStringArg(const string& instr);

public:
    Interpreter();

    void loadFromFile(const string& filename);
    void run();

    // For debugging
    void printProgram();
};

#endif
