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
%token END 0 "END of FILE"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See   https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
/* %left PLUSOP MINUSOP
%left MULTOP
%left DOT LP RP LBRACKET RBRACKET

 */

%right ASSIGN        
%left OR             
%left AND            
%left EQ            
%left LT GT         
%left PLUSOP MINUSOP 
%left MULTOP         
%right NOT          
%left DOT LBRACKET RBRACKET LP RP  

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root expression factor Identifier MainClass Statement Type MethodDeclaration VarDeclaration ClassDeclaration Goal ClassDeclarationList StatementListM MethodDeclarationCL VarDeclarationCL MethodDeclarationParams MethodDeclarationBody StatementMulti ExpressionParams MethodDeclarationParamsOpt Parameter ExpressionParamsOpt

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root:      Goal {root = $$;};/*  mainclass {root = $2;}; */



Goal: 
  MainClass END{
      $$ = $1; /* Måste kanske sätta root som root = $$ */                  
  }
  | MainClass ClassDeclarationList END{
      $$ = $1;
      $$->children.push_back($2);
  };

ClassDeclarationList:
    ClassDeclaration {
      $$ = new Node("ClassDeclarationList", "", yylineno);
      $$ -> children.push_back($1);
    }
    | ClassDeclarationList ClassDeclaration{
      $$ = $1;
      $$->children.push_back($2);
    };


MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE RBRACE { 
                $$ = new Node("MainClass", "", yylineno);

               $$->children.push_back($3);
                $$->children.push_back($13);
                $$->children.push_back($16);
                $$->children.push_back($17);

          } 
    ;

StatementListM:
    { $$ = new Node("StatementList", "", yylineno); }
    |Statement{
        $$ = new Node("StatementList", "", yylineno);
        $$->children.push_back($1);
    }
    | StatementListM Statement{
        $$ = $1;
        $$->children.push_back($2);
    };



ClassDeclaration: CLASS Identifier LBRACE VarDeclarationCL MethodDeclarationCL RBRACE { 
            $$ = new Node("ClassDeclaration", "", yylineno);
            $$->children.push_back($2);
            $$->children.push_back($4);
            $$->children.push_back($5);
      }
;

VarDeclarationCL:
    { $$ = new Node("VarDeclarationCL", "", yylineno); }
    |VarDeclaration{
        $$ = new Node("VarDeclarationCL", "", yylineno);
        $$->children.push_back($1);
    }
    | VarDeclarationCL VarDeclaration{
        $$ = $1;
        $$->children.push_back($2);
    };

MethodDeclarationCL:
    { $$ = new Node("MethodDeclarationCL", "", yylineno); }
    |MethodDeclaration{
        $$ = new Node("MethodDeclarationCL", "", yylineno);
        $$->children.push_back($1);
    }
    | MethodDeclarationCL MethodDeclaration{
        $$ = $1;
        $$->children.push_back($2);
    };


MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParamsOpt RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE { 
                $$ = new Node("MethodDeclaration", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($5);
                $$->children.push_back($8);
                $$->children.push_back($10);
               
          }
          | /*PUBLIC Type Identifier LP RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE { 
                $$ = new Node("MethodDeclaration", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($7);
                $$->children.push_back($9);
          }*/

MethodDeclarationParamsOpt:
    { $$ = new Node("MethodDeclarationParamsOpt", "", yylineno); }
    |MethodDeclarationParams{
        $$ = new Node("MethodDeclarationParamsOpt", "", yylineno);
        $$->children.push_back($1);
    };

MethodDeclarationParams:
   Parameter { $$ = new Node("ParameterList", "", yylineno); $$->children.push_back($1); }
  | MethodDeclarationParams COMMA Parameter { 
          $$ = $1; 
          $$->children.push_back($3); 
      }
;


Parameter:
    Type Identifier {
         $$ = new Node("Parameter", "", yylineno);
         $$->children.push_back($1);
         $$->children.push_back($2);
    }
    ;


MethodDeclarationBody:
    { $$ = new Node("MethodDeclarationBody", "", yylineno); }
    |VarDeclaration{
        $$ = new Node("MethodDeclarationBody", "", yylineno);
        $$->children.push_back($1);
    }
    | Statement{
        $$ = new Node("MethodDeclarationBody", "", yylineno);
        $$->children.push_back($1);
    }
    | MethodDeclarationBody VarDeclaration{
        $$ = $1;
        $$->children.push_back($2);
    }
    | MethodDeclarationBody Statement{
        $$ = $1;
        $$->children.push_back($2);
    };

VarDeclaration: Type Identifier SEMICOLON { 
                $$ = new Node("VarDeclaration", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
          }
    ;


Type: INT LBRACKET RBRACKET { $$ = new Node("IntArray", "", yylineno); }
    | BOOLEAN { $$ = new Node("Boolean", "", yylineno); }
    | INT { $$ = new Node("Int", "", yylineno); }
    | Identifier { $$ = new Node("Identifier", "", yylineno); $$->children.push_back($1); }
    ;


StatementMulti:
    { $$ = new Node("StatementMulti", "", yylineno); }
    |Statement{
        $$ = new Node("StatementMulti", "", yylineno);
        $$->children.push_back($1);
    }
    | StatementMulti Statement{
        $$ = $1;
        $$->children.push_back($2);
    };



Statement: LBRACE StatementMulti RBRACE {
            $$ = new Node("Block", "", yylineno);
            $$->children.push_back($2);
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

        | expression LBRACKET expression RBRACKET {
                $$ = new Node("ArrayAccess", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
          }

        | expression DOT LENGTH {
                $$ = new Node("ArrayLength", "", yylineno);
                $$->children.push_back($1);
          }  
        | expression DOT Identifier LP ExpressionParamsOpt RP {
                $$ = new Node("MethodCall","", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($3);
                $$->children.push_back($5);
              
            }
        | INT { $$ = new Node("IntLiteral", $1, yylineno); }
        | TRUE { $$ = new Node("BooleanLiteral", "true", yylineno); }
        | FALSE { $$ = new Node("BooleanLiteral", "false", yylineno); }
        | Identifier { $$ = $1; }
        | THIS { $$ = new Node("This", "", yylineno); }
        | NEW INT LBRACKET expression RBRACKET { $$ = new Node("NewArrayExpression", "", yylineno); $$->children.push_back($4); }
        | NEW Identifier LP RP { $$ = new Node("NewObjectExpression", "", yylineno); $$->children.push_back($2); }
        | NOT expression { $$ = new Node("NotExpression", "", yylineno); $$->children.push_back($2); }
         | LP expression RP { $$ = new Node("Expression", "", yylineno); $$->children.push_back($2);} 
         | factor { $$ = $1; }
        ;

/* SKa vi pusha identifiers? */

ExpressionParamsOpt: 
            { $$ = new Node("ExpressionParamsOpt", "", yylineno); }
            | ExpressionParams{
            $$ = new Node("ExpressionParamsOpt", "", yylineno);
            $$->children.push_back($1);
            };

ExpressionParams:            
            expression{
            $$ = new Node("ExpressionParams", "", yylineno);
            $$->children.push_back($1);
            }
            | ExpressionParams COMMA expression{
            $$ = $1;
            $$->children.push_back($3);
            }; 
 

factor: INT { $$ = new Node("IntLiteral", $1, yylineno); /* printf("r1 "); */}


Identifier: IDENTIFIER { $$ = new Node("Identifier", $1, yylineno); /* printf("r7 "); */}
    ;
  

%%