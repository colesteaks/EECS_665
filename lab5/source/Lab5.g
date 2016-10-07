// The name of the grammar. The name here needs to match the name of the
// file, including capitalization.
grammar Lab5;

// Define literals, keywords or operators, here as tokens.
tokens {
	PLUS='+';
	MINUS='-';
	DIV='/';
	MULT='*';
	EXP='^';
	LPAREN='(';
	RPAREN=')';
	LOG='log';
	SIN='sin';
	COS='cos';
	TAN='tan';
}

// Written in the target language. The header section can be
// used to import any Java classes that may be required.
@header {
}

// A main function to the parser. This function will setup the
// parsers input stream and execute the rule named "top".
@members {
    public static void main(String[] args) throws Exception {
        Lab5Lexer lex = new Lab5Lexer(new ANTLRInputStream(System.in));
       	CommonTokenStream tokens = new CommonTokenStream(lex);
        Lab5Parser parser = new Lab5Parser(tokens);

        try {
            parser.top();
        } catch (RecognitionException e)  {
            e.printStackTrace();
        }
    }
}

// Some example lexer fragments. These fragments don't produce any
// tokens themselves but can be used inside of other lexer rules.
fragment BIN: '0' .. '1';
fragment OCT: '0' .. '7';
fragment DEC: '0' .. '9';
fragment HEX: ('0' .. '9' | 'A' .. 'F' | 'a' .. 'f');


// The white space lexer rule. Match any number of white space characters
// and hide the results from the parser.
WS : (' ' | '\t' | '\r' | '\n')+ { $channel=HIDDEN; };

// The decimal value lexer rule. Match one or more decimal digits.
OCTAL		: '0' OCT+;
HEXIDECIMAL	: '0x' HEX+;
BINARY		: '0b' BIN+;
REAL		: DEC+ '.' DEC+;
DECIMAL 	: DEC+ ;

// The top rule. You should replace this with your own rule definition to
// parse expressions according to the assignment.
top : expr EOF
      | EOF
      ;

expr : l = pm { System.out.println( $l.value ); } ;

pm returns [double value] : l = md { $value = $l.value; }
 (( PLUS r = md { $value += $r.value; } )
 |( MINUS r = md {$value -= $r.value; } ))* ;
 
md returns [double value] : l = ex { $value = $l.value; }
(( DIV r = ex {if($r.value == 0) {
			System.out.print("Error: Divide by zero");
		}  else {
			$value /= $r.value;
		}
	} )
 |( MULT r = ex {$value *= $r.value; } ))*;
 
ex returns [double value] : l = paren {$value = $l.value;}
 (|(EXP r = paren { Math.pow($value, $r.value); }));
 
paren returns [double value] : LPAREN l = pm RPAREN {$value = $l.value;}
 | l = digit  {$value = $l.value;} 
 | l = func   {$value = $l.value;} ;

func returns [double value] 
	: LOG l = paren {$value = Math.log($l.value);}
	| SIN l = paren {$value = Math.sin($l.value);}
	| COS l = paren {$value = Math.cos($l.value);}
	| TAN l = paren {$value = Math.tan($l.value);};

digit returns [double value]
:  l = HEXIDECIMAL { $value = (double)Integer.decode( $l.getText()); }
 | l = BINARY { $value = (double)Integer.parseInt( $l.getText(), 2); }
 | l = OCTAL { $value = (double)Integer.decode( $l.getText()); } 
 | l = REAL {$value = Double.parseDouble( $l.getText()); } 
 | l = DECIMAL { $value = Integer.parseInt( $l.getText(), 10 ); };
 
