grammar Expr;
module: (expr NEWLINE)+;
expr: assignment    #ass
    | expr '+' term #addition
    | expr '-' term #subtraction
    | term          #termonly
    ;
assignment: ID '=' expr;
term: term '*' factor #multiplication
    | term '/' factor #division
    | factor          #factoronly
    ;
factor: INT;
NEWLINE: [\r\n]+;
INT: [0-9]+;
ID: [a-zA-Z]+;
