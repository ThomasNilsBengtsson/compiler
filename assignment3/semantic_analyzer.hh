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
    // Keep track of identifiers declared in the current scope to detect duplicates.
    std::unordered_map<ScopeNode *, std::unordered_set<std::string>> declaredIdentifiers;
    // For checkReturnType
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
    string findMethodCallType(string value, Node* root);
};
#endif