#include "TAC.hh"

TAC::TAC()
{
}

TAC::TAC(string result, string op, string lhs, string rhs, TACtype type)
{
    this->result = result;
    this->op = op;
    this->lhs = lhs;
    this->rhs = rhs;
    this->type = type;
}

TAC::TAC(string result, string lhs, TACtype type)
{
    this->result = result;
    this->lhs = lhs;
    this->type = type;
}

TAC::~TAC()
{
}

void TAC::generate(Node *ast)
{
    if (!ast)
        cout << "NO AST" << endl;

    if (ast->type == "AssignStatement")
    {
        string expr = ast->children.back()->type;
        if (expr == "MultExpression" || expr == "SubExpression" || expr == "AssignStatement"){ // x := y op z || x = y * z
            expr = "op";
            TAC x = TAC(ast->children.front()->value, expr, ast->children.back()->children.front()->value, ast->children.back()->children.back()->value, TACtype::EXPRESSION);
            allTAC.emplace_back(x);
        }
        if(expr == "IntLiteral" || expr == "Identifier"){ // x := op y || x = y
            expr = "op";
            TAC x = TAC(ast->children.front()->value, ast->children.back()->value, TACtype::EXPRESSION);
            allTAC.emplace_back(x);
        }
    }

    if (!ast->children.empty())
    {
        for (auto child : ast->children)
        {
            parents.emplace_back(child);
            generate(child);
            parents.pop_back();
        }
    }
}

void TAC::printTAC() const
{
    if (allTAC.empty()) { 
        cout << "empty" << endl;
        return; 
    }
    for (const auto &it : allTAC) {
        if (!it.getOp().empty())
            cout << it.getResult() << " := " << it.getLhs() << " " << it.getOp() << " " << it.getRhs() << endl;
        else if (!it.getLhs().empty())
            cout << it.getResult() << " := " << it.getLhs() << endl;
        else
            cout << it.getResult() << endl;
    }
}
