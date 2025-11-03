#ifndef TAC_HH
#define TAC_HH 
#include <string>
#include <iostream>
#include <map>
#include "Node.h"
using namespace std;

enum class TACtype{
    EXPRESSION, // X := Y OP Z
    METHODCALL
    
};

class TAC{
    private:
        string result;
        string op;
        string lhs;
        string rhs;
        vector<Node*> parents;
        TACtype type;
        vector<TAC> allTAC;

    public:
        TAC();
        TAC(string result, string op, string lhs, string rhs, TACtype type);
        TAC(string result, string lhs, TACtype type);
        ~TAC();

        void generate(Node* ast);
        void printTAC() const;

        TACtype getType() const { return type; }
        const string &getResult() const { return result; }
        const string &getOp() const { return op; }
        const string &getLhs() const { return lhs; }
        const string &getRhs() const { return rhs; }
};

#endif