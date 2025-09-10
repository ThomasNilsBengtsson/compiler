#include "semantic_analyzer.hh"
#include <iostream>
#include <map>

void SemanticAnalyzer::analyze(Node *ast)
{
    if (!ast)
        return;

    symbolTable.buildSymbolTable(ast, symbolTable);

    checkInvalidDefinitions(ast);
}

void SemanticAnalyzer::checkInvalidDefinitions(Node *node)
{
    if (!node)
        return;

    // Remove all manual scope management - just traverse and check
    if (node->type == "Identifier")
    {
        // Use findSymbol which searches all scopes, not just current scope
        vector<Symbol *> symbols = symbolTable.findSymbol(node->value);
        
        if (symbols.empty())
        {
            cout << "Symbol '" << node->value << "' not found" << endl;
        }
        else
        {
            cout << "Found symbol: " << node->value << " of type: " << symbols[0]->type << endl;
        }
    }

    // Just traverse - no scope management needed
    for (auto child : node->children)
    {
        checkInvalidDefinitions(child);
    }
}

void SemanticAnalyzer::checkDuplicatesOnly(Node *node)
{
    if (!node)
        return;

    static std::unordered_map<string, std::unordered_set<string>> scopeNames;
    static string currentScopePath = "";
    static bool initialized = false;
    static int classCounter = 0; // Add this counter

    if (!initialized)
    {
        scopeNames.clear();
        currentScopePath = "";
        classCounter = 0; // Reset counter
        initialized = true;
    }

    if (node->type == "ClassDeclaration" || node->type == "MainClass")
    {
        string name = node->value;
        if (scopeNames[currentScopePath].count(name))
        {
            reportError("semantic - already Declared Class: '" + name + "'", node);
        }
        else
        {
            scopeNames[currentScopePath].insert(name);
        }

        string previousPath = currentScopePath;
        // Make each class instance unique
        currentScopePath = currentScopePath + "::" + name + "_" + to_string(++classCounter);

        for (auto child : node->children)
        {
            checkDuplicatesOnly(child);
        }

        currentScopePath = previousPath;
        return;
    }
    else if (node->type == "MethodDeclaration")
    {
        string name = node->value;
        if (scopeNames[currentScopePath].count(name))
        {
            reportError("semantic - already Declared Function: '" + name + "'", node);
        }
        else
        {
            scopeNames[currentScopePath].insert(name);
        }

        string previousPath = currentScopePath;
        currentScopePath = currentScopePath + "::" + name;

        for (auto child : node->children)
        {
            checkDuplicatesOnly(child);
        }

        currentScopePath = previousPath;
        return;
    }
    else if (node->type == "VarDeclaration")
    {
        string name = node->value;
        if (node->children.size() >= 2)
        {
            auto it = node->children.begin();
            name = (*(++it))->value; // Second child is the variable name
        }

        if (scopeNames[currentScopePath].count(name))
        {
            cout << currentScopePath << endl;
            reportError("semantic - already Declared variable: '" + name + "'", node);
        }
        else
        {
            scopeNames[currentScopePath].insert(name);
        }
        return; // Don't recurse for variable declarations
    }
    else if (node->type == "Parameter")
    {
        string name = "";
        if (node->children.size() >= 2)
        {
            auto it = node->children.begin();
            name = (*(++it))->value; // Second child is the parameter name
        }

        if (!name.empty())
        {
            if (scopeNames[currentScopePath].count(name))
            {
                reportError("semantic - already Declared parameter: '" + name + "'", node);
            }
            else
            {
                scopeNames[currentScopePath].insert(name);
            }
        }
        return; // Don't recurse for parameters
    }

    // Recurse on children for other node types
    for (auto child : node->children)
    {
        checkDuplicatesOnly(child);
    }
}

void SemanticAnalyzer::checkReturnType(Node *node)
{
    if (!node)
        return;

    if (node->type == "ClassDeclaration")
    {
        symbolTable.enterScope(node->value);

        // CLEAR the IdentifierMap for each new class
        IdentifierMap.clear();

        // FIRST: Collect all variables in this class scope
        for (auto child : node->children)
        {
            if (child->type == "VarDeclarationCL")
            {
                for (auto varNode : child->children)
                {
                    if (varNode->type == "VarDeclaration" && varNode->children.size() >= 2)
                    {
                        auto it = varNode->children.begin();
                        string type = (*it)->type;      // First child is type
                        string name = (*(++it))->value; // Second child is name

                        IdentifierMap.emplace(type, name);
                        cout << "Added to IdentifierMap: " << name << " -> " << type << endl;
                    }
                }
            }
        }

        // SECOND: Now process all children (including methods)
        for (auto child : node->children)
        {
            checkReturnType(child);
        }

        symbolTable.exitScope();
        return;
    }

    if (node->type == "MethodDeclaration")
    {
        // Get the method's declared return type and return expression
        if (node->children.size() >= 5)
        {
            auto it = node->children.begin();
            Node *returnTypeNode = *it; // First child: declared return type
            advance(it, 4);             // Move to 5th child
            Node *returnExpr = *it;     // Fifth child: actual return expression

            string declaredType = returnTypeNode->type; // e.g., "Int"
            string actualType = "Unknown";

            // If return expression is an identifier, look it up in IdentifierMap
            cout << "Hej" << returnExpr->type << endl;
            cout << "xx" << symbolTable.getSymbolType(symbolTable.getCurrentScope(), node) << endl;
            if (returnExpr->type == "Identifier")
            {
                string returnVarName = returnExpr->value; // e.g., "y"

                // Find this variable in IdentifierMap
                for (auto mapEntry : IdentifierMap)
                {
                    if (mapEntry.second == returnVarName) // mapEntry.second is variable name
                    {
                        actualType = mapEntry.first; // mapEntry.first is variable type
                        break;
                    }
                }
            }
            else if (returnExpr->type == "IntLiteral")
            {
                actualType = "Int";
            }
            else if (returnExpr->type == "BooleanLiteral" || returnExpr->type == "True" || returnExpr->type == "False")
            {
                actualType = "Boolean";
            }
            else if (returnExpr->type == "MethodCall")
            {
            }

            cout << "Method: " << node->value
                 << ", declared: " << declaredType
                 << ", returnType: " << actualType << endl;

            if (!isCompatible(declaredType, actualType))
            {
                reportError("semantic (invalid return type)", node);
            }
        }
        return;
    }

    // Remove the VarDeclaration case since we handle it above
    // if (node->type == "VarDeclaration") { ... }

    // Generic processing for other node types
    for (auto child : node->children)
    {
        checkReturnType(child);
    }
}

bool SemanticAnalyzer::isCompatible(string type1, string type2)
{
    // Normalize types
    if ((type1 == "Int" || type1 == "Integer") && (type2 == "Int" || type2 == "Integer"))
        return true;
    if ((type1 == "Boolean" || type1 == "Bool") && (type2 == "Boolean" || type2 == "Bool"))
        return true;
    if (type1 == "IntArray" && type2 == "IntArray")
        return true;

    return type1 == type2;
}

void SemanticAnalyzer::printSymbolTable()
{
    // Print the symbol table for debugging
    cout << "Symbol Table Contents:" << endl;
    symbolTable.printTable(symbolTable.getCurrentScope());
}

void SemanticAnalyzer::reportError(string message, Node *node)
{
    string location = node ? " at line " + to_string(node->children.front()->lineno) : "";
    string error = "@error" + location + ": " + message;
    errors.push_back(error);
    cerr << error << endl;
}
