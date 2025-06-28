#ifndef SEMANTIC_ANALYZER_HH
#define SEMANTIC_ANALYZER_HH

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "symbol_table.h"

class SemanticAnalyzer
{
private:
    SymbolTable symbolTable;
    vector<string> errors;
    // Keep track of identifiers declared in the current scope to detect duplicates.
    std::unordered_map<ScopeNode *, std::unordered_set<std::string>> declaredIdentifiers;

    string getExpressionType(Node *node);
    bool isCompatible(string type1, string type2);

public:
    SemanticAnalyzer() : symbolTable() {}
    SemanticAnalyzer(SymbolTable &st) : symbolTable(st) {}

    void analyze(Node *ast);
    void checkTypes(Node *node);

    bool checkDuplicates(Node *node);

    void checkIdentifiers(Node *node);
    bool checkExpressions(Node *node);
    bool checkStatements(Node *node);
    bool checkMethodDeclaration(Node *node);

    void printSymbolTable();
    vector<string> getErrors() const { return errors; }
    void reportError(string message, Node *node);
};
#endif