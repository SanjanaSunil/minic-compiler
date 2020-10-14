grammar Expr;

prog: statement + EOF
    ;

variable: ID                                #varId
        | ID '[' expr ']'                   #varArrOneD
        | ID '[' expr ']' '[' expr ']'      #varArrTwoD
        ;

varAssign: ID '=' expr      #variableAssign
         ;

expr: op=('+' | '-') expr                       #exprUnary
    | op='!' expr                               #exprNot
    | expr op=('/' | '*' | '%') expr            #exprDivMulMod
    | expr op=('+' | '-') expr                  #exprAddSub
    | expr op=('<' | '<=' | '>' | '>=') expr    #exprComp
    | expr op=('==' | '!=') expr                #exprEq
    | expr op='&&' expr                         #exprAnd
    | expr op='||' expr                         #exprOr
    | expr '?' expr ':' expr                    #exprTernary
    | INT                                       #exprInt
    | FLOAT                                     #exprFloat
    | CHAR                                      #exprChar
    | BOOL                                      #exprBool
    | STRING                                    #exprString
    | '(' expr ')'                              #exprParenthesis
    | variable                                  #exprVar
    ;

statement: variable '=' expr ';'            #statVarAssign
         ;

/*Tokens*/

TYPE : ('uint' | 'int' | 'long' | 'float' | 'bool' | 'char' | 'string') ;

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.' [0-9]+) ;
BOOL : ('true' | 'false') ;
CHAR : ('\'' . '\'' | '\'' '\\' [ntr] '\'') ;
STRING : '"' .*? '"' ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 