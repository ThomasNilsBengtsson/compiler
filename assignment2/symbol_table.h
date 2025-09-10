#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Node.h"
using namespace std;

enum class IdentifierKind
{
    CLASS,
    METHOD,
    VARIABLE,
    PARAMETER
};

struct Symbol
{
    string name;
    string type;
    IdentifierKind kind;
    string scopeLevel;
    int lineNumber;
    bool returnType;
};

class ScopeNode
{
public:
    string scopeName;
    vector<Symbol> symbols;
    ScopeNode *parent;
    vector<ScopeNode *> children;
    ScopeNode(ScopeNode *parentScope = nullptr) : parent(parentScope) {}
};

class SymbolTable
{
private:
    ScopeNode *currentScope;
    string currentScopeName;
    vector<ScopeNode*> scopes;

public:
    SymbolTable();
    void enterScope(string scopeName);
    void exitScope();
    void addSymbol(string name, string type, IdentifierKind kind, int lineNumber);
    vector<Symbol *> findSymbol(string name);
    void printTable(ScopeNode *scope, int depth = 0);
    ScopeNode *getCurrentScope() { return currentScope; };
    string getCurrentScopeName() { return currentScopeName; }
    static void buildSymbolTable(Node *node, SymbolTable &symbolTable);
    string getSymbolType(ScopeNode *scope, Node *node);
};
#endif