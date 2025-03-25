#include "semantic_analyzer.hh"
// Windsurfer, cursor

string SemanticAnalyzer::getExpressionType(Node *node)
{
    if (!node)
    {
        return "Unknown";
    }

    // Handle literals
    if (node->type == "IntLiteral")
    {
        return "Int";
    }
    if (node->type == "BoolLiteral" || node->type == "True" || node->type == "False")
    {
        return "Boolean";
    }

    // Handle identifiers
    if (node->type == "Identifier")
    {
        vector<Symbol *> symbols = symbolTable.findSymbol(node->value);
        if (symbols.empty())
        {
            reportError("Undefined identifier: " + node->value, node);
            return "Unknown";
        }
        return symbols[0]->type;
    }

    // Handle array operations
    if (node->type == "NewArray")
    {
        // Check array size type
        if (!node->children.empty())
        {
            string sizeType = getExpressionType(node->children.front());
            if (!isCompatible(sizeType, "Int"))
            {
                reportError(sizeType + ": is of wrong type", node);
                return "Unknown";
            }
        }
        return "int[]";
    }
    if (node->type == "ArrayLength")
    {
        if (!node->children.empty())
        {
            string arrayType = getExpressionType(node->children.front());
            if (arrayType != "int[]")
            {
                reportError("Length property can only be used with arrays", node);
                return "Unknown";
            }
        }
        return "Int";
    }
    if (node->type == "ArrayLookup")
    {
        if (node->children.size() >= 2)
        {
            auto it = node->children.begin();
            string arrayType = getExpressionType(*it);
            string indexType = getExpressionType(*(++it));

            if (arrayType != "int[]")
            {
                reportError(arrayType + " is undefined or wrong", node);
                return "Unknown";
            }
            if (indexType != "Int")
            {
                reportError("Array index must be integer", node);
                return "Unknown";
            }
        }
        return "Int";
    }

    // Handle object creation and this
    if (node->type == "NewObject")
    {
        vector<Symbol *> symbols = symbolTable.findSymbol(node->value);
        if (symbols.empty() || symbols[0]->kind != IdentifierKind::CLASS)
        {
            reportError(node->value + " is not a valid Class", node);
            return "Unknown";
        }
        return node->value;
    }
    if (node->type == "This")
    {
        ScopeNode *scope = symbolTable.getCurrentScope();
        while (scope && scope->parent)
        {
            scope = scope->parent;
        }
        if (scope && !scope->symbols.empty())
        {
            return scope->symbols[0].name;
        }
        return "Unknown";
    }

    // Handle method calls
    if (node->type == "MethodCall")
    {
        if (!node->children.empty())
        {
            Node *object = node->children.front();
            string objectType = getExpressionType(object);

            vector<Symbol *> symbols = symbolTable.findSymbol(node->value);
            if (symbols.empty())
            {
                reportError("Undefined method: " + node->value, node);
                return "Unknown";
            }

            // Check parameter count 
            size_t expectedParams = 1; // Assuming all methods take 1 parameter for now
            size_t actualParams = node->children.size() - 1;
            if (actualParams != expectedParams)
            {
                reportError("Missing parameter", node);
                return "Unknown";
            }
        }
        return "Int"; // Assuming all methods return int for now
    }

    // Handle operators
    if (node->type == "And" || node->type == "Or" || node->type == "Not")
    {
        return "Boolean";
    }
    if (node->type == "LessThan" || node->type == "Equal")
    {
        return "Boolean";
    }
    if (node->type == "Plus" || node->type == "Minus" || node->type == "Times")
    {
        for (auto child : node->children)
        {
            if (getExpressionType(child) != "Int")
            {
                reportError("Arithmetic operators require integer operands", node);
                return "Unknown";
            }
        }
        return "Int";
    }

    return "Unknown";
}

bool SemanticAnalyzer::isCompatible(string type1, string type2)
{
    // Direct type equality
    if (type1 == type2)
        return true;

    // Handle array types
    if (type1 == "int[]" && type2 == "int[]")
        return true;

    // Handle primitive types
    if ((type1 == "Int" || type1 == "int") && (type2 == "Int" || type2 == "int"))
        return true;
    if ((type1 == "Boolean" || type1 == "boolean" || type1 == "bool") &&
        (type2 == "Boolean" || type2 == "boolean" || type2 == "bool"))
        return true;

    // Handle unknown types (to avoid cascading errors)
    if (type1 == "Unknown" || type2 == "Unknown")
        return true;

    return false;
}

void SemanticAnalyzer::analyze(Node *ast)
{
    if (!ast)
        return;
    checkIdentifiers(ast);
}

bool SemanticAnalyzer::checkDuplicateInScope(ScopeNode *scope, const string &name, IdentifierKind kind)
{
    int symbolCount = 0;
    for (const auto &symbol : scope->symbols)
    {
        if (symbol.name == name && symbol.kind == kind)
        {
            cout << "Duplicate identifier: " << symbol.name << endl;
            symbolCount++;
            if (symbolCount > 1)
                return true;
        }
    }
    return false;
}

bool SemanticAnalyzer::checkIdentifiers(Node *node)
{
    if (!node)
        return true;

    bool result = true;

    // Check current node first
    if (node->type == "ClassDeclaration")
    {
        // Then check for duplicates in global scope
        ScopeNode *globalScope = symbolTable.getCurrentScope();
        while (globalScope && globalScope->parent)
        {
            globalScope = globalScope->parent;
        }
        symbolTable.addSymbol(node->value, "class", IdentifierKind::CLASS, node->lineno);
        if (checkDuplicateInScope(globalScope, node->value, IdentifierKind::CLASS))
        {
            reportError("semantic - already Declared Class: '" + node->value + "'", node);
            result = false;
        }
        symbolTable.enterScope(node->value);
        for (auto child : node->children)
        {
            result &= checkIdentifiers(child);
        }
        
        // Exit the class scope after checking
        symbolTable.exitScope();
    }
    else if (node->type == "VarDeclaration")
    {
        // Get variable name from children if available
        string varName = node->value;
        if (node->children.size() >= 2)
        {
            Node *nameNode = *(++node->children.begin());
            varName = nameNode->value;
        }
        symbolTable.addSymbol(varName, "variable", IdentifierKind::VARIABLE, node->lineno);
        // Check for duplicate variable in current scope only
        ScopeNode *scope = symbolTable.getCurrentScope();
        if (checkDuplicateInScope(scope, varName, IdentifierKind::VARIABLE))
        {
            reportError("semantic - already Declared variable: '" + varName + "'", node);
            result = false;
        }
    }
    else if (node->type == "MethodDeclaration")
    {
        // Check for duplicate method in current scope only
        ScopeNode *scope = symbolTable.getCurrentScope();
        if (checkDuplicateInScope(scope, node->value, IdentifierKind::METHOD))
        {
            reportError("semantic - already Declared Function: '" + node->value + "'", node);
            result = false;
        }
        symbolTable.addSymbol(node->value, "method", IdentifierKind::METHOD, node->lineno);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "Parameter")
    {
        // Get the parameter name and type
        string paramName = "";
        string paramType = "";
        if (node->children.size() >= 2)
        {
            Node *typeNode = node->children.front();
            Node *nameNode = *(++node->children.begin());
            paramName = nameNode->value;
            paramType = typeNode->type;
        }
        else if (!node->value.empty())
        {
            paramName = node->value;
            paramType = "variable";
        }

        // Check for duplicate parameter in current scope only
        if (!paramName.empty())
        {
            ScopeNode *scope = symbolTable.getCurrentScope();
            if (checkDuplicateInScope(scope, paramName, IdentifierKind::VARIABLE))
            {
                reportError("semantic - already Declared parameter: '" + paramName + "'", node);
                result = false;
            }
            symbolTable.addSymbol(paramName, paramType, IdentifierKind::VARIABLE, node->lineno);
        }
    }

    // Then check all children
    for (auto child : node->children)
    {
        result &= checkIdentifiers(child);
    }

    // Exit scopes after checking children
    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration")
    {
        symbolTable.exitScope();
    }

    return result;
}

void SemanticAnalyzer::checkTypes(Node *node)
{
    if (!node)
        return;

    // Check statements
    if (node->type == "AssignStatement")
    {
        if (node->children.size() >= 2)
        {
            auto it = node->children.begin();
            Node *left = *it;
            Node *right = *(++it);
            string leftType = getExpressionType(left);
            string rightType = getExpressionType(right);

            if (!isCompatible(leftType, rightType))
            {
                reportError(left->value + " and expression " + right->type + " are of different types", node);
            }
        }
    }
    else if (node->type == "ArrayAssignStatement")
    {
        if (node->children.size() >= 3)
        {
            auto it = node->children.begin();
            string arrayType = getExpressionType(*it);
            string indexType = getExpressionType(*(++it));
            string valueType = getExpressionType(*(++it));

            if (arrayType != "int[]")
            {
                reportError("Array assignment requires array type", node);
            }
            if (!isCompatible(indexType, "Int"))
            {
                reportError("Array index must be integer", node);
            }
            if (!isCompatible(valueType, "Int"))
            {
                reportError("Array element must be integer", node);
            }
        }
    }
    else if (node->type == "IfStatement" || node->type == "WhileStatement")
    {
        if (!node->children.empty())
        {
            string condType = getExpressionType(node->children.front());
            if (!isCompatible(condType, "Boolean"))
            {
                reportError("Condition must be boolean type", node);
            }
        }
    }
    else if (node->type == "PrintStatement")
    {
        if (!node->children.empty())
        {
            string exprType = getExpressionType(node->children.front());
            if (!isCompatible(exprType, "Int"))
            {
                reportError("Print statement requires integer argument", node);
            }
        }
    }
    else if (node->type == "MethodDeclaration")
    {
        if (!node->children.empty())
        {
            string declaredReturnType = node->children.front()->type;

            if (node->children.size() >= 2)
            {
                string actualReturnType = getExpressionType(node->children.back());
                if (!isCompatible(declaredReturnType, actualReturnType))
                {
                    reportError("Method return type mismatch: expected " + declaredReturnType +
                                    ", got " + actualReturnType,
                                node);
                }
            }
        }
    }

    // Recursively check all children
    for (auto child : node->children)
    {
        checkTypes(child);
    }
}

bool SemanticAnalyzer::checkDuplicates(Node *node)
{
    bool duplicates = false;

    return duplicates;
}

bool SemanticAnalyzer::checkExpressions(Node *node)
{
    // This functionality is now handled in checkTypes
    return true;
}

bool SemanticAnalyzer::checkStatements(Node *node)
{
    // This functionality is now handled in checkTypes
    return true;
}

bool SemanticAnalyzer::checkMethodDeclaration(Node *node)
{
    // This functionality is now handled in checkTypes and checkIdentifiers
    return true;
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
