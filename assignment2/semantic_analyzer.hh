#ifndef SEMANTIC_ANALYZER_HH
#define SEMANTIC_ANALYZER_HH

#include <unordered_set>
#include "symbol_table.h"

class SemanticAnalyzer
{
private:
    SymbolTable symbolTable;
    vector<string> errors;
    // Map to store the last checked position for each scope and kind
    unordered_map<ScopeNode *, unordered_map<IdentifierKind, size_t>> lastCheckedPosition;

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

    bool checkDuplicateInScope(ScopeNode *scope, const string &name, IdentifierKind kind);
};
#endif