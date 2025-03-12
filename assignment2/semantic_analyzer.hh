#ifndef SEMANTIC_ANALYZER_HH
#define SEMANTIC_ANALYZER_HH

#include "symbol_table.h"

class SemanticAnalyzer
{
private:
    SymbolTable symbolTable;
    vector<string> errors;

    string getExpressionType(Node *node);
    bool isCompatible(string type1, string type2);

public:
    SemanticAnalyzer(SymbolTable &st) : symbolTable(st) {}

    void analyze(Node *ast);
    void checkTypes(Node *node);

    bool checkDuplicates(Node *node);

    bool checkIdentifiers(Node *node);
    bool checkExpressions(Node *node);
    bool checkStatements(Node *node);
    bool checkMethodDeclaration(Node *node);

    void printSymbolTable();
    const vector<string> &getErrors() { return errors; }
    void reportError(string message, Node *node);
};
#endif