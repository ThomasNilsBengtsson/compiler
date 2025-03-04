#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

enum class IdentifierKind
{
    CLASS,
    METHOD,
    VARIABLE
};

struct Symbol
{
    string name;
    string type;
    IdentifierKind kind;
    int scopeLevel;
};

class ScopeNode
{
public:
    unordered_map<string, Symbol> symbols;
    ScopeNode *parent;
    vector<ScopeNode *> children;
    ScopeNode(ScopeNode *parentScope = nullptr) : parent(parentScope) {}
};

class SymbolTable
{
private:
    ScopeNode *currentScope;

public:
    SymbolTable();
    void enterScope();
    void exitScope();
    void addSymbol(string name, string type, IdentifierKind kind);
    Symbol *findSymbol(string name);
    void printTable(ScopeNode *scope, int depth = 0);
    ScopeNode *getCurrentScope() { return currentScope; };
};
#endif