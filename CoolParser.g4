parser grammar CoolParser;

options {
	tokenVocab = CoolLexer;
}

// These are all supported parser sections:

// Parser file header. Appears at the top in all parser related files. Use e.g. for copyrights.
@parser::header {/* parser/listener/visitor header section */}

// Appears before any #include in h + cpp files.
@parser::preinclude {/* parser precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@parser::postinclude {
/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceeds the parser class declaration in the h file (e.g. for additional types etc.).
@parser::context {/* parser context section */}

// Appears in the private part of the parser in the h file.
// The function bodies could also appear in the definitions section, but I want to maximize
// Java compatibility, so we can also create a Java parser from this grammar.
// Still, some tweaking is necessary after the Java file generation (e.g. bool -> boolean).
@parser::members {
/* public parser declarations/members section */
}

// Appears in the public part of the parser in the h file.
@parser::declarations {/* private parser declarations section */}

// Appears in line with the other class member definitions in the cpp file.
@parser::definitions {/* parser definitions section */}

// Additionally there are similar sections for (base)listener and (base)visitor files.
@parser::listenerpreinclude {/* listener preinclude section */}
@parser::listenerpostinclude {/* listener postinclude section */}
@parser::listenerdeclarations {/* listener public declarations/members section */}
@parser::listenermembers {/* listener private declarations/members section */}
@parser::listenerdefinitions {/* listener definitions section */}

@parser::baselistenerpreinclude {/* base listener preinclude section */}
@parser::baselistenerpostinclude {/* base listener postinclude section */}
@parser::baselistenerdeclarations {/* base listener public declarations/members section */}
@parser::baselistenermembers {/* base listener private declarations/members section */}
@parser::baselistenerdefinitions {/* base listener definitions section */}

@parser::visitorpreinclude {/* visitor preinclude section */}
@parser::visitorpostinclude {/* visitor postinclude section */}
@parser::visitordeclarations {/* visitor public declarations/members section */}
@parser::visitormembers {/* visitor private declarations/members section */}
@parser::visitordefinitions {/* visitor definitions section */}

@parser::basevisitorpreinclude {/* base visitor preinclude section */}
@parser::basevisitorpostinclude {/* base visitor postinclude section */}
@parser::basevisitordeclarations {/* base visitor public declarations/members section */}
@parser::basevisitormembers {/* base visitor private declarations/members section */}
@parser::basevisitordefinitions {/* base visitor definitions section */}

// Actual grammar start.
program
    :   (clas SEMICOLON)+ EOF
    ; 
   
clas
	:
	CLASS TYPE (INHERITS TYPE)? LBRACKET (feature SEMICOLON)* RBRACKET
	;
	
feature
	: ID LPAREN (formal (COMMA formal)*)? RPAREN COLON TYPE LBRACKET expr (RBRACKET)  				#func
	| ID COLON TYPE (ASSIGN expr)? #global_decl
	;

formal
	: ID COLON TYPE
	;

expr
	: 
	expr (AT TYPE)? PERIOD ID LPAREN (expr (COMMA expr)*)? RPAREN #dispatch 
	| ID LPAREN (expr (COMMA expr)*)? RPAREN #call_func
	| IF expr THEN expr ELSE expr FI	#if
	| WHILE expr LOOP expr POOL	#while
	| LBRACKET (expr SEMICOLON)+ RBRACKET	#block
	| LET ID COLON TYPE (ASSIGN expr)? optionals* IN expr #let
	| CASE expr OF (ID COLON TYPE RE expr SEMICOLON)+ ESAC #case
	| NEW TYPE	#new
	| ISVOID expr	#isvoid
	| LPAREN expr RPAREN #paran
	| expr MUL expr	#mul
	| expr DIV expr #div
	| expr PLUS expr #plus
	| expr MINUS expr #minus
	| TILDA expr #tilda
	| expr LT expr	#lt
	| expr LE expr	#le
	| expr EQ expr  #eq
	| NOT expr		#not
	| ID			#id
	| INT			#int
	| STRING		#string
	| TRUE			#true
	| FALSE			#false
	| ID ASSIGN expr	#assignment
	;

optionals 
	: (COMMA ID COLON TYPE (ASSIGN expr)?)
	;