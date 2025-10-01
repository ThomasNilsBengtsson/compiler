#include "semantic_analyzer.hh"
#include <iostream>
#include <map>

void SemanticAnalyzer::analyze(Node *ast)
{
    if (!ast)
        return;
    this->root = ast;
    symbolTable.buildSymbolTable(ast, symbolTable);
    checkInvalidDefinitions(ast);
    checkDuplicateIdentifiers(ast);
}

void SemanticAnalyzer::checkDuplicateIdentifiers(Node *node){
    if(!node)
        return;
    
    if(node->type == "Goal"){
        checkDuplicateIdentifiersClass(node);
    }

    if(node->type == "ClassDeclaration"){
        checkDuplicateIdentifiersMethodAndVar(node);
    }

    if(node->type == "MethodDeclaration"){
        checkDuplicateIdentifiersParams(node);
    }

    if (!node->children.empty())
    {
        for (auto child : node->children)
        {
            parents.emplace_back(node);
            checkDuplicateIdentifiers(child);
            parents.pop_back();
        }
    }
}

void SemanticAnalyzer::checkDuplicateIdentifiersClass(Node *node){
    vector<Node*> classes;
    for(auto it : node->children){
        classes.emplace_back(it);
        if(it->type == "ClassDeclarationList"){
            for(auto c : it->children){
                classes.emplace_back(c);
            }
        }
    }
    for(int i = 0; i < classes.size(); i++){
        for(int j = i + 1; j < classes.size(); j++){
            if(classes[i]->value == classes[j]->value){
                reportError("semantic - duplicate identifier.", classes[j]->children.front());
            }
        }
    }
}

void SemanticAnalyzer::checkDuplicateIdentifiersMethodAndVar(Node *node){
    vector<Node*> variables;
    vector<Node*> methods;

    for(auto it : node->children){
        if(it->type == "VarDeclarationCL"){
            for(auto var : it->children){
                variables.emplace_back(var);
            }
        }
        if(it->type == "MethodDeclarationCL"){
            for(auto meth : it->children){
                methods.emplace_back(meth);
            }
        }
    }
    for(int i = 0; i < variables.size(); i++){
        for(int j = i + 1; j < variables.size(); j++){
            cout << node->value << "   " << variables[i]->value << "   " << variables[j]->value << endl;
            if(variables[i]->value == variables[j]->value){
                reportError("semantic - duplicate identifier.", variables[j]->children.front());
            }
        }
    }
    for(int i = 0; i < methods.size(); i++){
        for(int j = i + 1; j < methods.size(); j++){
            if(methods[i]->value == methods[j]->value){
                reportError("semantic - duplicate identifier.", methods[j]->children.front());
            }
        }
    }
}
void SemanticAnalyzer::checkDuplicateIdentifiersParams(Node *node){
    vector <Node*> paramsVar;
    for(auto it : node->children){
        if(it->type == "MethodDeclarationParamsOpt"){
            for(auto p : it->children){
                if(p->type == "ParameterList"){
                    for(auto c : p->children){
                        paramsVar.emplace_back(c->children.back());
                    }
                }
            }
        }
        if(it->type == "MethodDeclarationBody"){
            for(auto x : it->children){
                if(x->type == "VarDeclaration")
                    paramsVar.emplace_back(x);
            }
        }
    }
    for(int i = 0; i < paramsVar.size(); i++){
        for(int j = i + 1; j < paramsVar.size(); j++){
            if(paramsVar[i]->value == paramsVar[j]->value){
                reportError("semantic - duplicate identifier.", paramsVar[j]);
            }
        }
    }
}


void SemanticAnalyzer::checkInvalidDefinitions(Node *node)
{
    if (!node)
        return;
    if (node->type == "AssignStatement")
    {

        invalidDefinitionsVariable(node);
        invalidDefinitionsMethod(node);
    }
    if(node->type == "VarDeclaration" && node->children.front()->children.front()){
        invalidDefinitionClass(node);
    }

    if (!node->children.empty())
    {
        for (auto child : node->children)
        {
            parents.emplace_back(node);
            checkInvalidDefinitions(child);
            parents.pop_back();
        }
    }
}

void SemanticAnalyzer::invalidDefinitionsVariable(Node *node)
{
    Node *leftNodeIdentifier = nullptr;
    Node *rightNodeIdentifier = nullptr;

    for (auto it : node->children)
    {
        if (it->type == "Identifier")
        {
            if (leftNodeIdentifier == nullptr)
            {
                leftNodeIdentifier = it;
            }
            else if (rightNodeIdentifier == nullptr)
            {
                rightNodeIdentifier = it;
                break;
            }
        }
    }

    bool leftDeclared = false;
    bool rightDeclared = false;
    Node *leftType = nullptr;
    Node *rightType = nullptr;

    if (parents.size() > 0)
    {
        for (int i = parents.size() - 1; i >= 0; i--)
        {
            Node *parent = parents[i];
            for (auto it : parent->children)
            {
                if (it->type == "VarDeclarationCL")
                {
                    for (auto child : it->children)
                    {
                        if (leftNodeIdentifier && child->value == leftNodeIdentifier->value)
                        {
                            leftDeclared = true;
                            for (auto x : child->children)
                            {
                                leftType = x;
                                break;
                            }
                        }
                        if (rightNodeIdentifier && child->value == rightNodeIdentifier->value)
                        {
                            rightDeclared = true;
                            for (auto x : child->children)
                            {
                                rightType = x;
                                break;
                            }
                        }
                    }
                }
                if (it->type == "MethodDeclaration")
                {
                    for (auto z : it->children)
                    {
                        if (z->type == "MethodDeclarationParamsOpt")
                        {
                            for (auto x : z->children)
                            {
                                if (x->type == "ParameterList")
                                {
                                    for (auto n : x->children)
                                    {
                                        if (n->type == "Parameter")
                                        {
                                            for (auto c : n->children)
                                            {
                                                if (leftNodeIdentifier && c->value == leftNodeIdentifier->value)
                                                {
                                                    leftDeclared = true;
                                                }
                                                if (rightNodeIdentifier && c->value == rightNodeIdentifier->value)
                                                {
                                                    rightDeclared = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (leftNodeIdentifier && !leftDeclared)
    {
        reportError("semantic - undeclared variable.", leftNodeIdentifier);
    }
    if (rightNodeIdentifier && !rightDeclared)
    {
        reportError("semantic - undeclared variable.", rightNodeIdentifier);
    }
    if (leftType && rightType && leftType->type != rightType->type)
    {
        reportError("semantic - type mismatch.", leftNodeIdentifier);
    }
}

void SemanticAnalyzer::invalidDefinitionsMethod(Node *node)
{
    Node *methodNodeIdentifier = nullptr;
    Node *varNodeIdentifier = nullptr;
    bool isThis = false;

    for (auto it : node->children)
    {
        if (it->type == "Identifier")
        {
            varNodeIdentifier = it;
        }

        if (it->type == "MethodCall")
        {
            for (auto child : it->children)
            {
                if (child->type == "Identifier")
                    methodNodeIdentifier = child;
                if (child->type == "This")
                {
                    isThis = true;
                }
            }
        }
        // functﬁion som letar igenom alla klasser
    }
    string methodType;
    if (methodNodeIdentifier)
    {
        methodType = findMethodCallType(methodNodeIdentifier->value, root);
    }

    bool methodDeclared = false;
    string leftVarType;
    if (parents.size() > 0)
    {
        for (int i = parents.size() - 1; i >= 0; i--)
        {
            Node *parent = parents[i];
            for (auto it : parent->children)
            {
                if (isThis)
                {
                    if (it->type == "MethodDeclarationCL")
                    {
                        for (auto c : it->children)
                        {
                            if (methodNodeIdentifier && c->value == methodNodeIdentifier->value)
                            {
                                methodDeclared = true;
                            }
                        }
                        if (!methodDeclared)
                        {
                            break;
                        }
                    }
                    else if (it->type == "VarDeclarationCL")
                    {
                        for (auto c : it->children)
                        {
                            if (c->value == varNodeIdentifier->value)
                            {
                                leftVarType = c->children.front()->type;
                            }
                        }
                    }
                }
                else
                {
                    if (it->type == "MethodDeclarationCL")
                    {
                        for (auto c : it->children)
                        {
                            if (methodNodeIdentifier && c->value == methodNodeIdentifier->value)
                            {
                                methodDeclared = true;
                            }
                        }
                    }
                    else if (it->type == "VarDeclarationCL")
                    {
                        for (auto c : it->children)
                        {
                            if (c->value == varNodeIdentifier->value)
                            {
                                leftVarType = c->children.front()->type;
                            }
                        }
                    }
                    else if (it->type == "ClassDeclarationList")
                    {
                        for (auto c : it->children)
                        {
                            if (c->type == "ClassDeclaration")
                            {
                                for (auto x : c->children)
                                {
                                    if (x->type == "MethodDeclarationCL")
                                    {
                                        for (auto z : x->children)
                                        {
                                            if (methodNodeIdentifier && z->value == methodNodeIdentifier->value)
                                                methodDeclared = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        bool undeclared = false;
        if (methodNodeIdentifier && !methodDeclared)
        {
            reportError("semantic - undeclared method.", methodNodeIdentifier);
            undeclared = true;
        }
        if (!undeclared && methodNodeIdentifier && methodType != leftVarType)
        {
            reportError("semantic - not matching types.", varNodeIdentifier);
        }
    }
}


void SemanticAnalyzer::invalidDefinitionClass(Node *node){
    Node* className = node->children.front()->children.front();
    bool declaredClass = false;
    if(parents.size() > 0){
        for(int i = parents.size() - 1; i >= 0; i--){
            Node *parent = parents[i];
            if(parent->type == "ClassDeclarationList"){
                for(auto it : parent->children){
                    if(it->value == className->value){
                        declaredClass = true;
                    }
                }
            }
        }
    }
    if(!declaredClass && className){
        reportError("semantic - undeclared class.", className);

    }
}



void SemanticAnalyzer::printSymbolTable()
{
    // Print the symbol table for debugging
    cout << "Symbol Table Contents:" << endl;
    symbolTable.printTable(symbolTable.getCurrentScope());
}

void SemanticAnalyzer::reportError(string message, Node *node)
{
    string location = node ? " at line " + to_string(node->lineno) : "";
    string error = "@error" + location + ": " + message;
    errors.push_back(error);
    cerr << error << endl;
}

string SemanticAnalyzer::findMethodCallType(string value, Node *root)
{
    string type;
    for (auto it : root->children)
    {
        if (it->type == "ClassDeclarationList")
        {
            for (auto child : it->children)
            {
                if (child->type == "ClassDeclaration")
                {
                    for (auto k : child->children)
                    {
                        if (k->type == "MethodDeclarationCL")
                        {
                            for (auto t : k->children)
                            {
                                if (t->value == value)
                                {
                                    return t->children.front()->type;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return "Did not find method call";
}
