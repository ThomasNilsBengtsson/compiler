#include "semantic_analyzer.hh"
#include <iostream>
#include <map>

void SemanticAnalyzer::analyze(Node *ast)
{
    if (!ast)
        return;
    this->root = ast;
    checkInvalidDefinitions(ast);
    checkDuplicateIdentifiers(ast);
}

void SemanticAnalyzer::checkDuplicateIdentifiers(Node *node)
{
    if (!node)
        return;

    if (node->type == "Goal")
    {
        checkDuplicateIdentifiersClass(node);
    }

    if (node->type == "ClassDeclaration")
    {
        checkDuplicateIdentifiersMethodAndVar(node);
    }

    if (node->type == "MethodDeclaration")
    {
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

void SemanticAnalyzer::checkDuplicateIdentifiersClass(Node *node)
{
    vector<Node *> classes;
    for (auto it : node->children)
    {
        classes.emplace_back(it);
        if (it->type == "ClassDeclarationList")
        {
            for (auto c : it->children)
            {
                classes.emplace_back(c);
            }
        }
    }
    for (int i = 0; i < classes.size(); i++)
    {
        for (int j = i + 1; j < classes.size(); j++)
        {
            if (classes[i]->value == classes[j]->value)
            {
                reportError("semantic - duplicate identifier.", classes[j]->children.front());
            }
        }
    }
}

void SemanticAnalyzer::checkDuplicateIdentifiersMethodAndVar(Node *node)
{
    vector<Node *> variables;
    vector<Node *> methods;

    for (auto it : node->children)
    {
        if (it->type == "VarDeclarationCL")
        {
            for (auto var : it->children)
            {
                variables.emplace_back(var);
            }
        }
        if (it->type == "MethodDeclarationCL")
        {
            for (auto meth : it->children)
            {
                methods.emplace_back(meth);
            }
        }
    }
    for (int i = 0; i < variables.size(); i++)
    {
        for (int j = i + 1; j < variables.size(); j++)
        {
            if (variables[i]->value == variables[j]->value)
            {
                reportError("semantic - duplicate identifier.", variables[j]->children.front());
            }
        }
    }
    for (int i = 0; i < methods.size(); i++)
    {
        for (int j = i + 1; j < methods.size(); j++)
        {
            if (methods[i]->value == methods[j]->value)
            {
                reportError("semantic - duplicate identifier.", methods[j]->children.front());
            }
        }
    }
}
void SemanticAnalyzer::checkDuplicateIdentifiersParams(Node *node)
{
    vector<Node *> paramsVar;
    for (auto it : node->children)
    {
        if (it->type == "MethodDeclarationParamsOpt")
        {
            for (auto p : it->children)
            {
                if (p->type == "ParameterList")
                {
                    for (auto c : p->children)
                    {
                        paramsVar.emplace_back(c->children.back());
                    }
                }
            }
        }
        if (it->type == "MethodDeclarationBody")
        {
            for (auto x : it->children)
            {
                if (x->type == "VarDeclaration")
                    paramsVar.emplace_back(x);
            }
        }
    }
    for (int i = 0; i < paramsVar.size(); i++)
    {
        for (int j = i + 1; j < paramsVar.size(); j++)
        {
            if (paramsVar[i]->value == paramsVar[j]->value)
            {
                reportError("semantic - duplicate identifier.", paramsVar[j]);
            }
        }
    }
}


ScopeNode *SemanticAnalyzer::getCurrentScopeNode()
{
    string methodName = "";
    string className = "";

    for (int i = (int)parents.size() - 1; i >= 0; i--)
    {
        if (methodName.empty() && parents[i]->type == "MethodDeclaration")
            methodName = parents[i]->value;
        if (className.empty() && parents[i]->type == "ClassDeclaration")
        {
            className = parents[i]->value;
            break;
        }
    }

    if (className.empty())
    {
        bool foundInner = false;
        for (int i = (int)parents.size() - 1; i >= 0; i--)
        {
            if (parents[i]->type == "MainClass")
            {
                if (!foundInner)
                {
                    methodName = parents[i]->value;
                    foundInner = true;
                }
                else
                {
                    className = parents[i]->value;
                    break;
                }
            }
        }
    }

    ScopeNode *root = symbolTable.getRootScope();

    ScopeNode *classScope = nullptr;
    for (auto child : root->children)
    {
        if (child->scopeName == className)
        {
            classScope = child;
            break;
        }
    }
    if (!classScope)
        return root;

    if (!methodName.empty())
    {
        for (auto child : classScope->children)
        {
            if (child->scopeName == methodName)
                return child;
        }
    }

    return classScope;
}

ScopeNode *SemanticAnalyzer::getCurrentClassScopeNode()
{
    string className = "";

    for (int i = (int)parents.size() - 1; i >= 0; i--)
    {
        if (parents[i]->type == "ClassDeclaration")
        {
            className = parents[i]->value;
            break;
        }
    }

    if (className.empty())
    {
        bool foundInner = false;
        for (int i = (int)parents.size() - 1; i >= 0; i--)
        {
            if (parents[i]->type == "MainClass")
            {
                if (!foundInner)
                    foundInner = true;
                else
                {
                    className = parents[i]->value;
                    break;
                }
            }
        }
    }

    ScopeNode *root = symbolTable.getRootScope();
    for (auto child : root->children)
    {
        if (child->scopeName == className)
            return child;
    }
    return nullptr;
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
    if (node->type == "VarDeclaration" && node->children.front()->children.front())
    {
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

bool SemanticAnalyzer::isUndeclared(Node *id, Symbol *sym, const string &className)
{
    if (!sym)
        return true;
    if (sym->kind == IdentifierKind::VARIABLE &&
        sym->scopeLevel != className &&
        sym->lineNumber > id->lineno)
        return true;
    return false;
}

void SemanticAnalyzer::invalidDefinitionsVariable(Node *node)
{
    Node *leftId = nullptr;
    Node *rightId = nullptr;

    for (auto it : node->children)
    {
        if (it->type == "Identifier")
        {
            if (!leftId)
                leftId = it;
            else if (!rightId)
            {
                rightId = it;
                break;
            }
        }
    }

    ScopeNode *scope = getCurrentScopeNode();
    ScopeNode *classScope = getCurrentClassScopeNode();
    string className = classScope ? classScope->scopeName : "";

    Symbol *leftSym = leftId ? symbolTable.lookupInScopeChain(scope, leftId->value) : nullptr;
    Symbol *rightSym = rightId ? symbolTable.lookupInScopeChain(scope, rightId->value) : nullptr;

    if (leftId && isUndeclared(leftId, leftSym, className))
        reportError("semantic - undeclared variable.", leftId);
    if (rightId && isUndeclared(rightId, rightSym, className))
        reportError("semantic - undeclared variable.", rightId);
    if (leftSym && rightSym && leftSym->type != rightSym->type)
        reportError("semantic - type mismatch.", leftId);
}

void SemanticAnalyzer::invalidDefinitionsMethod(Node *node)
{
    Node *varId = nullptr;
    Node *methodId = nullptr;
    bool isThis = false;

    for (auto it : node->children)
    {
        if (it->type == "Identifier")
            varId = it;

        if (it->type == "MethodCall")
        {
            for (auto child : it->children)
            {
                if (child->type == "Identifier")
                    methodId = child;
                if (child->type == "This")
                    isThis = true;
            }
        }
    }

    if (!methodId)
        return;

    ScopeNode *scope = getCurrentScopeNode();
    ScopeNode *classScope = getCurrentClassScopeNode();
    ScopeNode *root = symbolTable.getRootScope();

    Symbol *methodSym = nullptr;
    if (isThis && classScope)
    {
        for (auto &sym : classScope->symbols)
        {
            if (sym.name == methodId->value && sym.kind == IdentifierKind::METHOD)
            {
                methodSym = &sym;
                break;
            }
        }
    }
    else
    {
        for (auto child : root->children)
        {
            for (auto &sym : child->symbols)
            {
                if (sym.name == methodId->value && sym.kind == IdentifierKind::METHOD)
                {
                    methodSym = &sym;
                    break;
                }
            }
            if (methodSym)
                break;
        }
    }

    if (!methodSym)
    {
        reportError("semantic - undeclared method.", methodId);
        return;
    }

    if (varId)
    {
        Symbol *varSym = symbolTable.lookupInScopeChain(scope, varId->value);
        if (varSym && varSym->type != methodSym->type)
            reportError("semantic - not matching types.", varId);
    }
}

void SemanticAnalyzer::invalidDefinitionClass(Node *node)
{
    Node *className = node->children.front()->children.front();
    if (!className)
        return;

    ScopeNode *root = symbolTable.getRootScope();
    for (auto &sym : root->symbols)
    {
        if (sym.name == className->value && sym.kind == IdentifierKind::CLASS)
            return;
    }
    reportError("semantic - undeclared class.", className);
}

void SemanticAnalyzer::printSymbolTable()
{
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
