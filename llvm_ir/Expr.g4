grammar Expr;

prog: progStatement* EOF
    ;

progStatement: (varDecl | functionDecl)      #progStat
             ;

block: '{' (statement)* '}'     #blockStat
     ;

variable: ID                                #varId
        | ID '[' expr ']'                   #varArrOneD
        | ID '[' expr ']' '[' expr ']'      #varArrTwoD
        ;

varAssign: ID '=' expr      #variableAssign
         ;

varDecl: TYPE varDeclTypeA (varDeclTypeB)* ';'    #variableDecl
        ;

varDeclTypeA: (variable | varAssign)              #variableDeclTypeA
            ;

varDeclTypeB: ((',' variable) | (',' varAssign))  #variableDeclTypeB
            ;

functionArgument: TYPE ID                   #funcArg
                | TYPE ID '[' ']'           #funcArgArrOneD
                | TYPE ID '[' ']' '[' ']'   #funcArgArrTwoD
                ;

functionDecl: 'func' functype=(TYPE | 'void') ID '(' (functionArgument)? (',' functionArgument)* ')' block       #funcDecl
            ;

functionCall: ID '(' (expr)? (',' expr)* ')'        #funcCall
            ;

expr: op='-' expr                               #exprUnary
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
    | functionCall                              #exprFuncCall
    ;

statement: varDecl                          #statVarDecl
         | variable '=' expr ';'            #statVarAssign
         | block                            #statBlock
         | functionCall ';'                 #statFuncCall
         | 'return' (expr)? ';'             #statReturn
         | 'break' ';'                      #statBreak
         | 'continue' ';'                   #statContinue
         | 'while' '(' expr ')' block       #statWhile
         | 'if' '(' expr ')' block ('else' block)?     #statIf
         | 'for' '(' (varDecl | initvar=variable '=' initexpr=expr ';')? (condexpr=expr)? ';' (loopvar=variable '=' loopexpr=expr)? ')' block    #statFor
         ;

/*Tokens*/

TYPE : ('uint' | 'int' | 'long' | 'float' | 'bool' | 'char') ;

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.' [0-9]+) ;
BOOL : ('true' | 'false') ;
CHAR : ('\'' . '\'' | '\'' '\\' [ntr] '\'') ;
STRING : '"' .*? '"' ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 