#include "symbol_table.h"

SymbolTable::SymbolTable()
{
    currentScope = new ScopeNode();
}

void SymbolTable::enterScope(string scopeName)
{
    ScopeNode *newScope = new ScopeNode(currentScope);
    currentScope->children.push_back(newScope);
    currentScope = newScope;
    currentScopeName = scopeName;
}

void SymbolTable::exitScope()
{
    if (currentScope->parent)
    {
        currentScope = currentScope->parent;
        if (!currentScope->symbols.empty())
        {
            currentScopeName = currentScope->symbols[0].scopeLevel;
        }
    }
}

void SymbolTable::addSymbol(std::string name, std::string type, IdentifierKind kind, int lineNumber)
{
    if (currentScopeName == "")
    {
        currentScopeName = "Global";
    }
    currentScope->symbols.push_back({name, type, kind, currentScopeName, lineNumber});
}

vector<Symbol *> SymbolTable::findSymbol(std::string name)
{
    vector<Symbol *> found;
    ScopeNode *scope = currentScope;
    while (scope)
    {
        for (auto &symbol : scope->symbols)
        {
            if (symbol.name == name)
            {
                found.push_back(&symbol);
            }
        }
        scope = scope->parent;
    }
    return found;
}

void SymbolTable::printTable(ScopeNode *scope, int depth)
{
    for (const auto &symbol : scope->symbols)
    {
        std::cout << std::string(depth * 2, ' ') // Indentation
                  << "Name: " << symbol.name
                  << ", Type: " << symbol.type
                  << ", Kind: " << (int)symbol.kind
                  << ", Scope Level: " << symbol.scopeLevel
                  << ", Line: " << symbol.lineNumber << "\n";
    }
    for (auto child : scope->children)
    {
        printTable(child, depth + 1);
    }
}

void SymbolTable::buildSymbolTable(Node *node, SymbolTable &symbolTable)
{
    if (!node)
    {
        return;
    }

    if (node->type == "ClassDeclaration")
    {
        cout << "hej " << node->value << endl;
        symbolTable.addSymbol(node->value, "class", IdentifierKind::CLASS, node->lineno);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "MethodDeclaration")
    {
        symbolTable.addSymbol(node->value, "method", IdentifierKind::METHOD, node->lineno);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "VarDeclaration")
    {
        if (node->children.size() >= 2)
        {
            Node *typeNode = node->children.front();
            Node *nameNode = *(++node->children.begin());
            symbolTable.addSymbol(nameNode->value, typeNode->type, IdentifierKind::VARIABLE, nameNode->lineno);
        }
    }
    else if (node->type == "MainClass")
    {
        symbolTable.addSymbol(node->value, "class", IdentifierKind::CLASS, node->lineno);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "MainClassParams")
    {
        symbolTable.addSymbol(node->value, "class", IdentifierKind::CLASS, node->lineno);
        symbolTable.enterScope(node->value);
    }
    for (auto child : node->children)
    {
        buildSymbolTable(child, symbolTable);
    }
    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration" || node->type == "MainClass" || node->type == "MainClassParams")
    {
        symbolTable.exitScope();
    }
}
