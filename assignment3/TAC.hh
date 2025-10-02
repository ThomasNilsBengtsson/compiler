#ifndef TAC_HH
#define TAC_HH

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Tac {
public:
    string result;
    string op;
    string lhs;
    string rhs;     
    
    Tac() {}
    
    void dump();
};




#endif