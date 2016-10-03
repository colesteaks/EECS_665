// The name of the grammar. The name here needs to match the name of the
// file, including capitalization.
grammar Lab5;

// Define literals, keywords or operators, here as tokens.
tokens {
	PLUS='+';
	MINUS='-';
	DIV='/';
	MULT='*';
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
DECIMAL : DEC+ ;

// The top rule. You should replace this with your own rule definition to
// parse expressions according to the assignment.
top : expr EOF
      | EOF
      ;

expr : term { System.out.println( $term.value ); } ;

term returns [int value] : l = digit { $value = $l.value; }
 ( PLUS r = digit { $value += $r.value; } )*
 ( MINUS r = digit {$value -= $r.value; } )*
 ( DIV r = digit {$value /= $r.value; } )*
 ( MULT r = digit {$value *= $r.value; } )* ;


digit returns [int value] : DECIMAL { $value =
 Integer.parseInt( $DECIMAL.getText(), 10 ); } ;
