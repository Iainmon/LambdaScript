grammar lambda;

// program: expression|;
program: ( expression NL )*  # instructionLine;

expression:
	(Int | Bool)                                # literal // used to be constant
	| Identifier                                # variable
	| expression expression						# application
	| Lambda Identifier '.' expression		    # abstraction
	| Identifier '=' expression         	    # assign
	| condition                                 # conditional // used to be ifThenElse
	| Operator expression expression			# binaryExpression
    | 'print' expression                        # printInstruction
	| '(' expression ')'						# brackets;

body: expression ;
condition: 'if' expression 'then' body 'else' body
    | '(' expression '->' body '|' body ')';

// imports: 'import' Identifier | '(' imports ')';

Lambda: '\\' | 'λ';
Bool : 'tru' | 'fls' | 'true' | 'false';
Int: [0-9]+;
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

WS: [ \t\r]+ -> skip;
NL: [\n;]+;