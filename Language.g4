grammar Language;

// program: expression|;
program: ( expression (NL | EOF) )* EOF? # instructionLine;

expression:
	(Int | Bool)                                	# literal // used to be constant
	| Identifier typeBinding?                  	 	# variable
	| expression expression							# application
	| Lambda Identifier typeBinding? '.' expression # abstraction
	| Identifier typeBinding? '=' expression        # assign
	| condition                                 	# conditional // used to be ifThenElse
	| expression Operator expression				# binaryExpression
    | 'print' expression                        	# printInstruction
	| 'import' Identifier							# importInstruction
	| '(' expression ')'							# brackets;

body: expression ;
condition: 'if' expression 'then' body 'else' body
    | '(' expression '->' body '|' body ')';


// leafType: TypeIdentifier;
// nodeType: TypeIdentifier '->' TypeIdentifier;
// type: leafType
// 	| nodeType
// 	| '(' type ')';

typeBinding: ':' type;

type: TypeIdentifier						#leafType
	| type '->' type						#nodeType
	| '(' type ')'							#typeBrackets;

// imports: 'import' Identifier | '(' imports ')';

Lambda: '\\' | 'λ';
Bool : 'tru' | 'fls' | 'true' | 'false';
Int: [0-9]+;
Identifier: ('a' ..'z') ('a' ..'z' | '0' ..'9')*;
TypeIdentifier: ('A' ..'Z') ('a' ..'z')*;
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