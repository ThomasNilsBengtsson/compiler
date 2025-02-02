/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP LBRACE RBRACE ASSIGN AND OR LT GT EQ NOT STATIC PUBLIC CLASS VOID MAIN STRING BOOLEAN IF ELSE WHILE SYSTEM_OUT_PRINTLN RETURN TRUE FALSE THIS NEW LENGTH IDENTIFIER SEMICOLON COMMA DOT LBRACKET RBRACKET
%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left PLUSOP MINUSOP
%left MULTOP

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root expression factor Identifier MainClass Statement Type MethodDeclaration VarDeclaration ClassDeclaration Goal

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root:      Goal {root = $1;};/*  mainclass {root = $2;}; */


Goal: MainClass ClassDeclaration { 
                $$ = new Node("Goal", "", yylineno);
                $$->children.push_back($1);
                if($2)
                {
                  for (auto i : *$2)
                  {
                    $$->children.push_back(i);
                  }
                  delete $2;
                }
          }
    ;

MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement Statement RBRACE RBRACE { 
                $$ = new Node("MainClass", "", yylineno);
               /*  $$->children.push_back(new Node("Identifier", $3, yylineno));   vet inte ska man ha detta*/
               $$->children.push_back($3);
                $$->children.push_back($13);
                $$->children.push_back($16);
                if($17)
                {
                  for (auto i : *$17)
                  {
                    $$->children.push_back(i);
                  }
                  delete $17;
                }
          } 

    ;


ClassDeclaration: CLASS Identifier LBRACE VarDeclaration MethodDeclaration RBRACE { 
                $$ = new Node("ClassDeclaration", "", yylineno);
                $$->children.push_back($2);
                if($4)
                {
                  for (auto i : *$4)
                  {
                    $$->children.push_back(i);
                  }
                  delete $4;
                }
                if($5)
                {
                  for (auto i : *$5)
                  {
                    $$->children.push_back(i);
                  }
                  delete $5;
                }
          }
    ;


MethodDeclaration: PUBLIC Type Identifier LP Type Identifier COMMA Type Identifier RP LBRACE VarDeclaration Statement RETURN expression SEMICOLON RBRACE { 
                $$ = new Node("MethodDeclaration", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($6);
                $$->children.push_back($8);
                $$->children.push_back($9);
                if($8 && $9)
                {
                  for (auto i : *$8)
                  {
                    $$->children.push_back(i);
                  }
                  delete $8;

                  for (auto i : *$9)
                  {
                    $$->children.push_back(i);
                  }
                }
                /* måste lägga till för flera parameterar för 8 och 9 */
                if($12)
                {
                  for (auto i : *$12)
                  {
                    $$->children.push_back(i);
                  }
                  delete $12;
                }
                if($13)
                {
                  for (auto i : *$13)
                  {
                    $$->children.push_back(i);
                  }
                  delete $13;
                }
                $$->children.push_back($14);
          }

    ;

VarDeclaration: Type Identifier SEMICOLON { 
                $$ = new Node("VarDeclaration", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
          }
    ;


Type: INT LBRACKET RBRACKET { $$ = new Node("IntArray", "", yylineno); }
    | BOOLEAN { $$ = new Node("Boolean", "", yylineno); }
    | INT { $$ = new Node("Int", "", yylineno); }
    | IDENTIFIER { $$ = new Node("Identifier", $1, yylineno); }
    ;

Statement: LBRACE Statement RBRACE {
                $$ = new Node("Block", "", yylineno);
                if($2)
                {
                  for (auto i : *$2)
                  {
                    $$->children.push_back(i);
                  }
                  delete $2;
                }
          }
        | IF LP expression RP Statement ELSE Statement { 
                $$ = new Node("IfStatement", "", yylineno);
                $$->children.push_back($3);
                $$->children.push_back($5);
                $$->children.push_back($7);
          }
        | WHILE LP expression RP Statement { 
                $$ = new Node("WhileStatement", "", yylineno);
                $$->children.push_back($3);
                $$->children.push_back($5);
          }
        | SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON { 
                $$ = new Node("PrintStatement", "", yylineno);
                $$->children.push_back($3);
          }
        | Identifier ASSIGN expression SEMICOLON { 
                $$ = new Node("AssignStatement", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON { 
                $$ = new Node("ArrayAssignStatement", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
                $$->children.push_back($6);
          }
    ;
expression: expression PLUSOP expression { 
                $$ = new Node("AddExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression MINUSOP expression { 
                $$ = new Node("SubExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression MULTOP expression { 
                $$ = new Node("MultExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression AND expression { 
                $$ = new Node("AndExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression OR expression { 
                $$ = new Node("OrExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression LT expression { 
                $$ = new Node("LtExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression GT expression { 
                $$ = new Node("GtExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        | expression EQ expression { 
                $$ = new Node("EqExpression", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
        /*| expression DOT IDENTIFIER LP (expression (COMMA expression)*)? RP { 
                $$ = new Node("MethodCall", $3, yylineno);
                $$->children.push_back($1);
                if ($5) $$->children.push_back($5);
          }

*/
/*         | NEW INT LBRACKET expression RBRACKET {
                $$ = new Node("NewArrayExpression", "", yylineno);
                $$->children.push_back($4);
          }
        | NEW IDENTIFIER LP RP {
                $$ = new Node("NewObjectExpression", $2, yylineno);
          } */
  

        | expression LBRACKET expression RBRACKET {
                $$ = new Node("ArrayAccess", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }
  /*       | expression DOT Identifier LP expression COMMA expression RP {
                $$ = new Node("MethodCall", $3, yylineno);
                $$->children.push_back($1);
                if ($5) $$->children.push_back($5);
                if($6)
                {
                  for (auto i : *$6)
                  {
                    $$->children.push_back(i);
                  }
            
                }
          } */
        | INT { $$ = new Node("IntLiteral", $1, yylineno); }
        | TRUE { $$ = new Node("BooleanLiteral", "true", yylineno); }
        | FALSE { $$ = new Node("BooleanLiteral", "false", yylineno); }
        | Identifier { $$ = $1; }
        | THIS { $$ = new Node("This", "", yylineno); }
        | NEW INT LBRACKET expression RBRACKET { $$ = new Node("NewArrayExpression", "", yylineno); $$->children.push_back($4); }
      /*   | NEW Identifier LP RP { $$ = new Node("NewObjectExpression", $2, yylineno);} */
        | NOT expression { $$ = new Node("NotExpression", "", yylineno); $$->children.push_back($2); }
        /* | LP expression RP { $$ = $2; } */ /* Denna görs redan i factor */
        | factor { $$ = $1; };

/* SKa vi pusha identifiers? */



factor:     INT           {  $$ = new Node("Int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */}
    ;



Identifier: IDENTIFIER { $$ = new Node("Identifier", $1, yylineno); /* printf("r7 "); */}
    ;
  

%%