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
        currentScopeName = currentScope->symbols.begin()->second.scopeLevel;
    }
}

void SymbolTable::addSymbol(std::string name, std::string type, IdentifierKind kind)
{
    if(currentScopeName == ""){
        currentScopeName = "Global";
    }
    currentScope->symbols[name] = {name, type, kind, currentScopeName};
}

Symbol *SymbolTable::findSymbol(std::string name)
{
    ScopeNode *scope = currentScope;
    while (scope)
    {
        if (scope->symbols.find(name) != scope->symbols.end())
        {
            return &scope->symbols[name];
        }
        scope = scope->parent;
    }
    return nullptr;
}

void SymbolTable::printTable(ScopeNode *scope, int depth)
{
    for (const auto &entry : scope->symbols)
    {
        std::cout << std::string(depth * 2, ' ') // Indentation
                  << "Name: " << entry.second.name
                  << ", Type: " << entry.second.type
                  << ", Kind: " << (int)entry.second.kind
                  << ", Scope Level: " << entry.second.scopeLevel << "\n";
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
        symbolTable.addSymbol(node->value, "class", IdentifierKind::CLASS);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "MethodDeclaration")
    {

        symbolTable.addSymbol(node->value, "method", IdentifierKind::METHOD);
        symbolTable.enterScope(node->value);
    }
    else if (node->type == "VarDeclaration")
    {
        if(node->children.size() >= 2)
        {
            Node* typeNode = node->children.front();
            Node* nameNode = *(++node->children.begin());
            symbolTable.addSymbol(nameNode->value, typeNode->type, IdentifierKind::VARIABLE);
        }
    }
    for(auto child : node->children)
    {
        buildSymbolTable(child, symbolTable);
    }
    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration")
    {
        symbolTable.exitScope();
    }
}
