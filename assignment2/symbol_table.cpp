#include "symbol_table.h"

SymbolTable::SymbolTable()
{
    currentScope = new ScopeNode();
}

void SymbolTable::enterScope()
{
    ScopeNode *newScope = new ScopeNode(currentScope);
    currentScope->children.push_back(newScope);
    currentScope = newScope;
}

void SymbolTable::exitScope()
{
    if (currentScope->parent)
    {
        currentScope = currentScope->parent;
    }
}

void SymbolTable::addSymbol(std::string name, std::string type)
{
    currentScope->symbols[name] = {name, type, (int)currentScope->symbols.size()};
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
                  << ", Scope Level: " << entry.second.scopeLevel << "\n";
    }
    for (auto child : scope->children)
    {
        printTable(child, depth + 1);
    }
}