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
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 + v1);
    }
    else if (instr == "isub") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 - v1);
    }
    else if (instr == "imul") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 * v1);
    }
    else if (instr == "idiv") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        if (v1 == 0) {
            cerr << "Error: Division by zero" << endl;
            stopped = true;
            return;
        }
        dataStack.push(v2 / v1);
    }
    else if (instr == "ilt") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 < v1 ? 1 : 0);
    }
    else if (instr == "igt") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 > v1 ? 1 : 0);
    }
    else if (instr == "ieq") {
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push(v2 == v1 ? 1 : 0);
    }
    else if (instr == "iand") {
        // Push 0 if v1 * v2 == 0, else push 1
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push((v1 * v2 == 0) ? 0 : 1);
    }
    else if (instr == "ior") {
        // Push 0 if v1 + v2 == 0, else push 1
        int v1 = dataStack.top(); dataStack.pop();
        int v2 = dataStack.top(); dataStack.pop();
        dataStack.push((v1 + v2 == 0) ? 0 : 1);
    }
    else if (instr == "inot") {
        int v = dataStack.top(); dataStack.pop();
        dataStack.push(v == 0 ? 1 : 0);
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
        string methodName;
        // Check if numArgs is present
        size_t spacePos = rest.rfind(' ');
        if (spacePos != string::npos) {
            methodName = rest.substr(0, spacePos);
            // numArgs is parsed but not used here; callee pops its own args
        } else {
            methodName = rest;
        }

        int methodIdx = findMethodIndex(methodName);

        if (methodIdx < 0) {
            cerr << "Error: Method not found: " << methodName << endl;
            stopped = true;
            return;
        }

        // Push current activation and switch to new method
        // The callee will pop its own arguments from the data stack via istore
        ActivationRecord ar;
        ar.methodName = methodName;
        ar.returnMethod = currentMethod;
        ar.returnAddress = pc;

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
    else if (startsWith(instr, "new ")) {
        // Object creation - push a dummy reference (0) since objects are simplified
        dataStack.push(0);
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
