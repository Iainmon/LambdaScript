grammar lcalc;

program: statement+;

statement: schema;


schema: variable
    |   constant
    |   abstraction
    |   primApply
    |   funApply
    |   conditional;// '(' schema ')'

variable: VAR;


tru_expression: schema;
fls_expression: schema;
conditional: '(' schema THEN tru_expression ELSE fls_expression ')';

let: VAR '<-' INT;
show: 'show' (INT | VAR);

//
VAR: [a-z]+;
INT: [0-9]+;
WS: [ \n\t]+ -> skip;

THEN: '->' | 'then';
ELSE: '|' | 'else';

TRUE: 'tru';
FALSE: 'fls';

COMMENT: '//'.*[\n];
STRING: '"' CHAR*? '"';
CHAR: [ a-zA-Z0-9];
INTEGER: [0-9]+;
IDENT: [a-zA-Z]+;