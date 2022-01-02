lexer grammar CoolLexer;

// These are all supported lexer sections:

// Lexer file header. Appears at the top of h + cpp files. Use e.g. for copyrights.
@lexer::header {/* lexer header section */}

// Appears before any #include in h + cpp files.
@lexer::preinclude {/* lexer precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@lexer::postinclude {
/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceds the lexer class declaration in the h file (e.g. for additional types etc.).
@lexer::context {/* lexer context section */}

// Appears in the public part of the lexer in the h file.
@lexer::members {/* public lexer declarations section */
	void raiseError(const std::string& message) {
		setText(message);
	}
}

// Appears in the private part of the lexer in the h file.
@lexer::declarations {/* private lexer declarations/members section */}

// Appears in line with the other class member definitions in the cpp file.
@lexer::definitions {/* lexer definitions section */}

/* Comments */
BLOCK_COMMENT
    : '(*'
      (BLOCK_COMMENT |.)*?
      '*)' ->skip
    ; 

COMMENTS : '-''-' (~'\n')*? '\n' -> skip;

/* Errors */
ERROR_COMMENT
	: '(*' (BLOCK_COMMENT | ~[*)])*? EOF {
		raiseError("EOF in comment");
	};
	
UNMATCH : '*)' {
	raiseError("Unmatched *)");
};

NULLINSTRING: '"' (~["\n])*? '\u0000' ~["\n]*? ["\nEOF] {
	raiseError("String contains null character");
};

UNFINISHED : '"' (~["EOF\\])*? '\n' {
	raiseError("Unterminated string constant");
};


EOF_IN_STRING :
	'"' (~["\n])*? EOF {
		raiseError("EOF in string constant");
	};

WS
    :   [ \n\f\r\t\b]+ -> skip
    ; 
    
/* Keywords */
CLASS		: ('c'|'C') ('l'|'L') ('a'|'A') ('s'|'S') ('s'|'S') ;
ELSE		: ('e'|'E') ('l'|'L') ('s'|'S') ('e'|'E') ;
FI			: ('f'|'F') ('i'|'I') ;
IF			: ('i'|'I') ('f'|'F') ;
IN			: ('i'|'I') ('n'|'N') ;
INHERITS	: ('i'|'I') ('n'|'N') ('h'|'H') ('e'|'E') ('r'|'R') ('i'|'I') ('t'|'T') ('s'|'S') ;
LET			: ('l'|'L') ('e'|'E') ('t'|'T') ;
LOOP		: ('l'|'L') ('o'|'O') ('o'|'O') ('p'|'P') ;
POOL		: ('p'|'P') ('o'|'O') ('o'|'O') ('l'|'L') ;
THEN		: ('t'|'T') ('h'|'H') ('e'|'E') ('n'|'N') ;
WHILE		: ('w'|'W') ('h'|'H') ('i'|'I') ('l'|'L') ('e'|'E') ;
CASE		: ('c'|'C') ('a'|'A') ('s'|'S') ('e'|'E') ;
ESAC		: ('e'|'E') ('s'|'S') ('a'|'A') ('c'|'C') ;
OF			: ('o'|'O') ('f'|'F') ;
NEW			: ('n'|'N') ('e'|'E') ('w'|'W') ;
ISVOID		: ('i'|'I') ('s'|'S') ('v'|'V') ('o'|'O') ('i'|'I') ('d'|'D') ;
NOT			: ('n'|'N') ('o'|'O') ('t'|'T') ;

/* Manual boolshit*/
TRUE : 't'('r'|'R')('u' | 'U')('e' | 'E');
FALSE : 'f'('a' | 'A')('l' | 'L')('s' | 'S')('e'| 'E');

/* Integer number */
fragment DIGIT : [0-9];
INT : DIGIT+;

/* Identifiers */
fragment LOWERCASELETTER : [a-z];
fragment UPPERCASELETTER : [A-Z];
fragment LETTER : LOWERCASELETTER | UPPERCASELETTER;
ID : LOWERCASELETTER (LETTER | '_' | DIGIT)*;
TYPE : UPPERCASELETTER (LETTER | '_' | DIGIT)*;

/* Special identifiers */

LE : '<=';
LT : '<';
EQ : '=';
ASSIGN : '<-';
RE : '=>';

/* Parentheses and operators */
PLUS : '+';
MINUS : '-';
MUL : '*';
DIV : '/';
AT : '@';
TILDA : '~';

LPAREN : '(';
RPAREN : ')';
LBRACKET : '{';
RBRACKET : '}';

SEMICOLON : ';';
COLON : ':';
COMMA : ',';
PERIOD : '.';

/* Strings */
STRING : '"' (('\\''\n') | '\\''\r''\n' | ~[\n\r\u0000])*? '"' {
{
	std::string text = getText();

	std::string newText = "";
	
	for (int i = 1; i < text.length() - 1; ++i) {
		if (text[i] == '\\') {
			if (text[i + 1] == 'n')
				newText.push_back('\n');
			else if (text[i + 1] == 'b')
				newText.push_back('\b'); 
			else if (text[i + 1] == 't')
				newText.push_back('\t');
			else if (text[i + 1] == 'f')
				newText.push_back('\f');
			else if (text[i + 1] == 'r')
				newText.push_back('\r');
			else
				newText.push_back(text[i + 1]);   
			i++;
		} else 
			newText.push_back(text[i]);
	}
	
	if (newText.length() > 1024) {
		raiseError("String constant too long");
		return;
	}
	
	setText(newText);
}
};

/* Error invalid character */ 
STHELSE:
. {
	raiseError("Invalid character: " + getText());
};