#include "TAC.hh"

void Tac::dump()
{
        if (this->op == "goto") {
            cout << "goto " << this->result << endl;
        } else if (this->op == "iffalse") {
            cout << "iffalse " << this->lhs << " goto " << this->result << endl;
        } else if (this->op == ":=") {
            cout << this->result << " := " << this->lhs << endl;
        } else if (this->rhs.empty()) {
            cout << this->result << " := " << this->op << " " << this->lhs << endl;
        } else {
            cout << this->result << " := " << this->lhs << " " << this->op << " " << this->rhs << endl;
        }
}