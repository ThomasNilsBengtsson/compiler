#include "semantic_analyzer.hh"
//Windsurfer, cursor

string SemanticAnalyzer::getExpressionType(Node *node)
{
    if(!node){
        return "Unknown";
    }
    if(node->type == "Identifier"){
        Symbol* symbol = symbolTable.findSymbol(node->value);
        if(!symbol){
            return "Unknown";
        }
        return symbol->type;
    }
    else if(node->type == "IntLiteral"){
        return "int";
    }
    else if(node->type == "BoolLiteral"){
        return "bool";
    }
    else if(node->type == "This"){
        return "this";
    }
    else if(node->type == "NewArray"){
        return "int[]";
    }
    else if(node->type == "NewObject"){
        return node->value;
    }
    else if(node->type == "Not"){
        return "bool";
    }
    else if(node->type == "And" || node->type == "LessThan" || node->type == "Plus" || node->type == "Minus" || node->type == "Times" || node->type == "ArrayLookup"){
        return "int";
    }
    else if(node->type == "ArrayLength"){
        return "int";
    }
    else if(node->type == "MethodCall"){
        Symbol* symbol = symbolTable.findSymbol(node->value);
        if(!symbol){
            return "Unknown";
        }
        return symbol->type;
    }
}

bool SemanticAnalyzer::isCompatible(string type1, string type2)
{
    return false;
}

void SemanticAnalyzer::analyze(Node *ast)
{
    if(!ast){
        return;
    }
    checkIdentifiers(ast);
    checkTypes(ast);
}

void SemanticAnalyzer::checkTypes(Node *node)
{
    if (!node) return;
    
    // Check statements
    if (node->type == "AssignStatement") {
        std::string leftType = getExpressionType(node->children[0]);
        std::string rightType = getExpressionType(node->children[1]);
        
        if (leftType != rightType && leftType != "unknown" && rightType != "unknown") {
            reportError("Type mismatch in assignment", node->lineNo);
        }
    }
    else if (node->type == "ArrayAssignStatement") {
        // Check array type, index type, and value type
        std::string arrayType = getExpressionType(node->children[0]);
        std::string indexType = getExpressionType(node->children[1]);
        std::string valueType = getExpressionType(node->children[2]);
        
        if (arrayType != "IntArray") {
            reportError("Array assignment requires array type", node->lineNo);
        }
        if (indexType != "Int") {
            reportError("Array index must be integer", node->lineNo);
        }
        if (valueType != "Int") {
            reportError("Array element must be integer", node->lineNo);
        }
    }
    else if (node->type == "IfStatement" || node->type == "WhileStatement") {
        // Check condition type
        std::string condType = getExpressionType(node->children[0]);
        
        if (condType != "Boolean") {
            reportError("Condition must be boolean type", node->lineNo);
        }
    }
    else if (node->type == "PrintStatement") {
        // Check print argument type (MiniJava typically only prints integers)
        std::string exprType = getExpressionType(node->children[0]);
        
        if (exprType != "Int") {
            reportError("Print statement requires integer argument", node->lineNo);
        }
    }
    else if (node->type == "MethodDeclaration") {
        // Check return type matches declared type
        if (!node->children.empty()) {
            Node* returnTypeNode = node->children[0];
            Node* returnExprNode = node->children[node->children.size() - 1];
            
            std::string declaredType = returnTypeNode->type;
            std::string returnType = getExpressionType(returnExprNode);
            
            if (declaredType != returnType && returnType != "unknown") {
                reportError("Return type does not match method declaration", node->lineNo);
            }
        }
    }
}

bool SemanticAnalyzer::checkIdentifiers(Node *node)
{
    if(!node){
        return false;
    }
    if(node->type == "Identifier"){
        Symbol* symbol = symbolTable.findSymbol(node->value);
        if(!symbol){
            reportError("Identifier " + node->value + " not found", node);
            return false;
        }
    }
    if(node->type == "VarDeclaration" || node->type == "MethodDeclaration" || node->type == "ClassDeclaration"){
        Symbol* symbol = symbolTable.findSymbol(node->value);
        if(symbol){
            reportError("Identifier " + node->value + " already declared", node);
            return false;
        }
    }
    bool result = true;
    for (auto child : node->children)
    {
        result &= checkIdentifiers(child);
    }
    return result;
}

bool SemanticAnalyzer::checkExpressions(Node *node)
{
    return false;
}

bool SemanticAnalyzer::checkStatements(Node *node)
{
    return false;
}

bool SemanticAnalyzer::checkMethodDeclaration(Node *node)
{
    return false;
}

void SemanticAnalyzer::printSymbolTable()
{
}

void SemanticAnalyzer::reportError(string message, Node *node)
{
}
