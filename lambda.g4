grammar lambda;

program: expression |;

expression:
	Identifier                                  # variable
	| (Int | Bool)                              # literal // used to be constant
	| expression expression						# application
	| Lambda Identifier '.' expression		    # abstraction
	| Identifier '=' expression         	    # assign
	| condition                                 # conditional // used to be ifThenElse
	| Operator expression expression			# binaryExpression
    | 'print' expression                        # printInstruction
	| '(' expression ')'						# brackets;

body: expression;
condition: 'if' expression 'then' body 'else' body
    | '(' expression '->' body '|' body;

imports: 'import' Identifier | '(' imports ')';

Lambda: '\\' | 'λ';
Identifier: ('a' ..'z') ('a' ..'z' | '0' ..'9')*;
Operator:
	'+'
	| '-'
	| '*'
	| '/'
	| '<'
	| '>'
	| '<='
	| '>='
	| '==';

Bool: 'tru' | 'fls' | 'true' | 'false';
Int: [0-9]+;

WS: [ \n\t\r]+ -> skip;