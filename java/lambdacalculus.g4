grammar lambdacalculus;

//


program : statement+;

statement : let | show ;

declaration : let | 

let    :  VAR '<-' INT ;
show     : 'show' (INT | VAR) ;


//


VAR     : [a-z]+ ;
INT : [0-9]+ ;
WS     : [ \n\t]+ -> skip;