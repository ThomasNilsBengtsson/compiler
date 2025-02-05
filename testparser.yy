//ex 1
%% 


Goal:
  MainClass END  {$$ = $1; root = $$;}
  | MainClass ClassDeclarationP END {$$ = $1; $$->children.push_back($2); root = $$;};


//ex 2
%% 

root:      Goal {root = $$;};

Goal: 
MainClass END {$$ = $1;};
| MainClass ClassDeclarationP END {$$ = $1; $$->children.push_back($2);};






MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE RBRACE { 
                $$ = new Node("MainClass", "", yylineno);
               /*  $$->children.push_back(new Node("Identifier", $3, yylineno));   vet inte ska man ha detta*/
               $$->children.push_back($3);
                $$->children.push_back($13);
                $$->children.push_back($16);

          } 
    ;

StatementListM:
    Statement{
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
          }
    ;

VarDeclarationCL:
    VarDeclaration{
        $$ = new Node("VarDeclarationCL", "", yylineno);
        $$->children.push_back($1);
    }
    | VarDeclarationCL VarDeclaration{
        $$ = $1;
        $$->children.push_back($2);
    };

MethodDeclarationCL:
    MethodDeclaration{
        $$ = new Node("MethodDeclarationCL", "", yylineno);
        $$->children.push_back($1);
    }
    | MethodDeclarationCL MethodDeclaration{
        $$ = $1;
        $$->children.push_back($2);
    };




MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParams RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE { 
                $$ = new Node("MethodDeclaration", "", yylineno);
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($5);
                $$->children.push_back($6);
                $$->children.push_back($8);
                $$->children.push_back($9);
               
          };

MethodDeclarationParams:
    Type Identifier{
        $$ = new Node("MethodDeclarationParams", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($2);
    }
    | MethodDeclarationParams COMMA Type Identifier{
        $$ = $1;
        $$->children.push_back($3);
        $$->children.push_back($4);
    };

MethodDeclarationBody:
    VarDeclaration{
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





Statement: LBRACE StatementMulti RBRACE {
            $$ = new Node("Block", "", yylineno);
        }

StatementMulti:
    Statement{
        $$ = new Node("StatementMulti", "", yylineno);
        $$->children.push_back($1);
    }
    | StatementMulti Statement{
        $$ = $1;
        $$->children.push_back($2);
    };


| expression DOT Identifier LP ExpressionParams RP {
        $$ = new Node("MethodCall", $3, yylineno);
        $$->children.push_back($1);
       
    }

ExpressionParams:
    expression{
        $$ = new Node("ExpressionParams", "", yylineno);
        $$->children.push_back($1);
    }
    | ExpressionParams COMMA expression{
        $$ = $1;
        $$->children.push_back($3);
    };

