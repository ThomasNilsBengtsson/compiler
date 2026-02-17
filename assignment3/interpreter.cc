#include "interpreter.h"
#include <fstream>
#include <iostream>
#include <sstream>

Interpreter::Interpreter() : currentMethod(0), pc(0), stopped(false) {}

bool Interpreter::startsWith(const string& str, const string& prefix) {
    return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix;
}

int Interpreter::parseIntArg(const string& instr) {
    size_t spacePos = instr.rfind(' ');
    return stoi(instr.substr(spacePos + 1));
}

string Interpreter::parseStringArg(const string& instr) {
    size_t spacePos = instr.rfind(' ');
    return instr.substr(spacePos + 1);
}

vector<int>& Interpreter::currentLocals() {
    return callStack.top().locals;
}

Interpreter::Method* Interpreter::findMethod(const string& name) {
    for (Method& m : methods) {
        if (m.name == name) {
            return &m;
        }
    }
    return nullptr;
}

int Interpreter::findMethodIndex(const string& name) {
    for (size_t i = 0; i < methods.size(); i++) {
        if (methods[i].name == name) {
            return i;
        }
        // Also check for partial match (e.g., "*.main" matches "E.main")
        if (!name.empty() && name.front() == '*') {
            string suffix = name.substr(1);  // e.g., ".main"
            if (methods[i].name.size() >= suffix.size() &&
                methods[i].name.substr(methods[i].name.size() - suffix.size()) == suffix) {
                return i;
            }
        }
        // Check if method name ends with ".name" (e.g., "calcSum" matches "Sum.calcSum")
        string suffix = "." + name;
        if (methods[i].name.size() >= suffix.size() &&
            methods[i].name.substr(methods[i].name.size() - suffix.size()) == suffix) {
            return i;
        }
    }
    return -1;
}

int Interpreter::findLabel(const string& label) {
    Method& method = methods[currentMethod];
    auto it = method.labelToPC.find(label);
    if (it != method.labelToPC.end()) {
        return it->second;
    }
    cerr << "Error: Label not found: " << label << endl;
    return -1;
}

void Interpreter::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    methods.clear();
    Method* currentMethodPtr = nullptr;
    string line;

    while (getline(file, line)) {
        // Trim leading/trailing whitespace
        size_t start = line.find_first_not_of(" \t");
        if (start == string::npos) continue;  // Empty line
        size_t end = line.find_last_not_of(" \t\r\n");
        line = line.substr(start, end - start + 1);

        if (line.empty()) continue;

        // Check if this is a method declaration (ends with : but not a block label)
        // Method names contain a dot (e.g., "E.main:")
        if (line.back() == ':' && line.find('.') != string::npos) {
            // New method
            methods.push_back(Method());
            currentMethodPtr = &methods.back();
            currentMethodPtr->name = line.substr(0, line.size() - 1);  // Remove ':'
        }
        // Check if this is a block label (e.g., "block_0:")
        else if (line.back() == ':') {
            if (currentMethodPtr) {
                string label = line.substr(0, line.size() - 1);
                currentMethodPtr->labelToPC[label] = currentMethodPtr->instructions.size();
                // Don't add label as instruction - it's just a marker
            }
        }
        else {
            // Regular instruction
            if (currentMethodPtr) {
                currentMethodPtr->instructions.push_back(line);
            }
        }
    }

    file.close();
}

void Interpreter::executeInstruction(const string& instr) {
    if (startsWith(instr, "iconst ")) {
        int val = parseIntArg(instr);
        dataStack.push(val);
    }
    else if (startsWith(instr, "iload ")) {
        int idx = parseIntArg(instr);
        vector<int>& locals = currentLocals();
        // Expand locals if needed
        while (locals.size() <= (size_t)idx) {
            locals.push_back(0);
        }
        dataStack.push(locals[idx]);
    }
    else if (startsWith(instr, "istore ")) {
        int idx = parseIntArg(instr);
        int val = dataStack.top();
        dataStack.pop();
        vector<int>& locals = currentLocals();
        // Expand locals if needed
        while (locals.size() <= (size_t)idx) {
            locals.push_back(0);
        }
        locals[idx] = val;
    }
    else if (instr == "iadd") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a + b);
    }
    else if (instr == "isub") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a - b);
    }
    else if (instr == "imul") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a * b);
    }
    else if (instr == "idiv") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        if (b == 0) {
            cerr << "Error: Division by zero" << endl;
            stopped = true;
            return;
        }
        dataStack.push(a / b);
    }
    else if (instr == "ilt") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a < b ? 1 : 0);
    }
    else if (instr == "igt") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a > b ? 1 : 0);
    }
    else if (instr == "ieq") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a == b ? 1 : 0);
    }
    else if (instr == "iand") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push((a != 0 && b != 0) ? 1 : 0);
    }
    else if (instr == "ior") {
        int b = dataStack.top(); dataStack.pop();
        int a = dataStack.top(); dataStack.pop();
        dataStack.push((a != 0 || b != 0) ? 1 : 0);
    }
    else if (instr == "inot") {
        int a = dataStack.top(); dataStack.pop();
        dataStack.push(a == 0 ? 1 : 0);
    }
    else if (instr == "print") {
        int val = dataStack.top();
        dataStack.pop();
        cout << val << endl;
    }
    else if (startsWith(instr, "goto ")) {
        string label = parseStringArg(instr);
        pc = findLabel(label);
    }
    else if (startsWith(instr, "iffalse goto ")) {
        int val = dataStack.top();
        dataStack.pop();
        if (val == 0) {
            // Parse label from "iffalse goto label"
            string label = instr.substr(13);  // Skip "iffalse goto "
            pc = findLabel(label);
        }
    }
    else if (startsWith(instr, "invokevirtual ")) {
        // Parse "invokevirtual methodName numArgs"
        string rest = instr.substr(14);  // Skip "invokevirtual "
        size_t spacePos = rest.rfind(' ');
        string methodName = rest.substr(0, spacePos);
        int numArgs = stoi(rest.substr(spacePos + 1));

        int methodIdx = findMethodIndex(methodName);

        if (methodIdx < 0) {
            cerr << "Error: Method not found: " << methodName << endl;
            stopped = true;
            return;
        }

        // Pop arguments from stack (in reverse order)
        vector<int> args(numArgs);
        for (int i = numArgs - 1; i >= 0; i--) {
            args[i] = dataStack.top();
            dataStack.pop();
        }

        // Create new activation record
        ActivationRecord ar;
        ar.methodName = methodName;
        ar.returnMethod = currentMethod;
        ar.returnAddress = pc;
        // Initialize locals with arguments (skip first arg which is 'this')
        for (int i = 1; i < numArgs; i++) {
            ar.locals.push_back(args[i]);
        }

        // Push current state and switch to new method
        callStack.push(ar);
        currentMethod = methodIdx;
        pc = 0;
    }
    else if (instr == "ireturn") {
        // Get return value from stack
        int returnVal = 0;
        if (!dataStack.empty()) {
            returnVal = dataStack.top();
            dataStack.pop();
        }

        // Pop activation record
        ActivationRecord ar = callStack.top();
        callStack.pop();

        // Restore caller state
        currentMethod = ar.returnMethod;
        pc = ar.returnAddress;

        // Push return value for caller
        dataStack.push(returnVal);
    }
    else if (startsWith(instr, "iaload")) {
        // Array access: array ref and index on stack
        int index = dataStack.top(); dataStack.pop();
        int arrayRef = dataStack.top(); dataStack.pop();
        // For simplicity, arrayRef is the base index in locals where array starts
        // This is a simplified implementation
        vector<int>& locals = currentLocals();
        dataStack.push(locals[arrayRef + index + 1]);  // +1 to skip length
    }
    else if (startsWith(instr, "iastore")) {
        // Array store: array ref, index, and value on stack
        int val = dataStack.top(); dataStack.pop();
        int index = dataStack.top(); dataStack.pop();
        int arrayRef = dataStack.top(); dataStack.pop();
        vector<int>& locals = currentLocals();
        while (locals.size() <= (size_t)(arrayRef + index + 1)) {
            locals.push_back(0);
        }
        locals[arrayRef + index + 1] = val;  // +1 to skip length
    }
    else if (instr == "arraylength") {
        int arrayRef = dataStack.top(); dataStack.pop();
        vector<int>& locals = currentLocals();
        dataStack.push(locals[arrayRef]);  // Length stored at base
    }
    else if (instr == "newarray") {
        int size = dataStack.top(); dataStack.pop();
        vector<int>& locals = currentLocals();
        int arrayRef = locals.size();
        locals.push_back(size);  // Store length first
        for (int i = 0; i < size; i++) {
            locals.push_back(0);  // Initialize elements to 0
        }
        dataStack.push(arrayRef);
    }
    else if (startsWith(instr, "new ")) {
        // Object creation - simplified: just push a reference (index)
        string className = parseStringArg(instr);
        vector<int>& locals = currentLocals();
        int objRef = locals.size();
        locals.push_back(0);  // Placeholder for object
        dataStack.push(objRef);
    }
    else if (instr == "stop") {
        stopped = true;
    }
    else {
        cerr << "Warning: Unknown instruction: " << instr << endl;
    }
}

void Interpreter::run() {
    // Find main method
    currentMethod = findMethodIndex("*.main");
    if (currentMethod < 0) {
        cerr << "Error: No main method found" << endl;
        return;
    }

    pc = 0;
    stopped = false;

    // Create initial activation record for main
    ActivationRecord mainAR;
    mainAR.methodName = methods[currentMethod].name;
    mainAR.returnMethod = -1;
    mainAR.returnAddress = -1;
    callStack.push(mainAR);

    // Main execution loop
    while (!stopped) {
        if (pc < 0 || pc >= (int)methods[currentMethod].instructions.size()) {
            cerr << "Error: PC out of bounds: " << pc << endl;
            break;
        }

        string instr = methods[currentMethod].instructions[pc];
        pc++;
        executeInstruction(instr);
    }
}

void Interpreter::printProgram() {
    for (const Method& m : methods) {
        cout << "Method: " << m.name << endl;
        cout << "Labels:" << endl;
        for (const auto& kv : m.labelToPC) {
            cout << "  " << kv.first << " -> " << kv.second << endl;
        }
        cout << "Instructions:" << endl;
        for (size_t i = 0; i < m.instructions.size(); i++) {
            cout << "  " << i << ": " << m.instructions[i] << endl;
        }
        cout << endl;
    }
}
