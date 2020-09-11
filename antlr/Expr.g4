grammar Expr;

prog: (varDecl | functionDecl)* 'func int main()' block + EOF
    ;

literal: INT
       | FLOAT
       | CHAR
       | BOOL
       ;

variable: ID
        | ID '[' expr ']'
        | ID '[' expr ']' '[' expr ']'
        ;

varAssign: ID '=' expr
         ;

varDecl: TYPE (variable | varAssign) ((',' variable) | (',' varAssign))* ';'
        ;

block: '{' (statement)* '}'
     ;

functionArgument: TYPE ID
                | TYPE ID '[' ']'
                | TYPE ID '[' ']' '[' ']'
                ;

functionDecl: 'func' (TYPE | 'void') ID '(' (functionArgument)? (',' functionArgument)* ')' block
            ;

functionCall: ID '(' (expr)? (',' expr)* ')'
            ;

expr:  functionCall
    | ('+' | '-') expr
    | '!' expr
    | expr ('/' | '*' | '%') expr
    | expr ('+' | '-') expr
    | expr ('<' | '<=' | '>' | '>=') expr
    | expr ('==' | '!=') expr
    | expr '&&' expr
    | expr '||' expr
    | '(' expr ')' '?' expr ':' expr
    | variable
    | literal
    | '(' expr ')'
    ;
        
statement: varDecl
         | variable '=' expr ';'
         | functionCall ';'
         | block
         | 'return' (expr)? ';'
         | 'break' ';'
         | 'continue' ';'
         | 'while' '(' expr ')' block
         | 'if' '(' expr ')' block ('elif' '(' expr ')' block)* ('else' block)?
         | 'while' '(' expr ')' block
         | 'for' '(' ((TYPE)? variable '=' expr)? ';' (expr)? ';' (variable '=' expr)? ')' block
         ;

/*Tokens*/

TYPE : ('uint' | 'int' | 'long' | 'float' | 'bool' | 'char') ;

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.' [0-9]+) ;
BOOL : ('true' | 'false') ;
CHAR : ('\'' . '\'' | '\'' '\\' [ntr] '\'') ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 
