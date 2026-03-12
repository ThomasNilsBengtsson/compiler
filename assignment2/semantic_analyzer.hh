#ifndef SEMANTIC_ANALYZER_HH
#define SEMANTIC_ANALYZER_HH

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include "symbol_table.h"

class SemanticAnalyzer
{
private:
    SymbolTable symbolTable;
    vector<string> errors;
    std::unordered_map<ScopeNode *, std::unordered_set<std::string>> declaredIdentifiers;
    std::map<string, string> IdentifierMap;
    vector<Node*> parents;
    Node* root;

public:
    SemanticAnalyzer() : symbolTable() {}
    SemanticAnalyzer(SymbolTable &st) : symbolTable(st) {}

    void analyze(Node *ast);

    void checkDuplicateIdentifiers(Node* node);
    void checkDuplicateIdentifiersClass(Node* node);
    void checkDuplicateIdentifiersMethodAndVar(Node* node);
    void checkDuplicateIdentifiersParams(Node* node);

    void checkInvalidDefinitions(Node *node);
    void invalidDefinitionsVariable(Node *node);
    void invalidDefinitionsMethod(Node *node);
    void invalidDefinitionClass(Node* node);
    

    void printSymbolTable();
    void reportError(string message, Node *node);
    ScopeNode* getCurrentScopeNode();
    ScopeNode* getCurrentClassScopeNode();
    bool isUndeclared(Node *id, Symbol *sym, const string &className);
};
#endif