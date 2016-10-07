// $ANTLR 3.4 Lab5.g 2016-10-07 16:09:35



import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class Lab5Parser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "BIN", "BINARY", "COS", "DEC", "DECIMAL", "DIV", "EXP", "HEX", "HEXIDECIMAL", "LOG", "LPAREN", "MINUS", "MULT", "OCT", "OCTAL", "PLUS", "REAL", "RPAREN", "SIN", "TAN", "WS"
    };

    public static final int EOF=-1;
    public static final int BIN=4;
    public static final int BINARY=5;
    public static final int COS=6;
    public static final int DEC=7;
    public static final int DECIMAL=8;
    public static final int DIV=9;
    public static final int EXP=10;
    public static final int HEX=11;
    public static final int HEXIDECIMAL=12;
    public static final int LOG=13;
    public static final int LPAREN=14;
    public static final int MINUS=15;
    public static final int MULT=16;
    public static final int OCT=17;
    public static final int OCTAL=18;
    public static final int PLUS=19;
    public static final int REAL=20;
    public static final int RPAREN=21;
    public static final int SIN=22;
    public static final int TAN=23;
    public static final int WS=24;

    // delegates
    public Parser[] getDelegates() {
        return new Parser[] {};
    }

    // delegators


    public Lab5Parser(TokenStream input) {
        this(input, new RecognizerSharedState());
    }
    public Lab5Parser(TokenStream input, RecognizerSharedState state) {
        super(input, state);
    }

    public String[] getTokenNames() { return Lab5Parser.tokenNames; }
    public String getGrammarFileName() { return "Lab5.g"; }


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



    // $ANTLR start "top"
    // Lab5.g:62:1: top : ( expr EOF | EOF );
    public final void top() throws RecognitionException {
        try {
            // Lab5.g:62:5: ( expr EOF | EOF )
            int alt1=2;
            int LA1_0 = input.LA(1);

            if ( ((LA1_0 >= BINARY && LA1_0 <= COS)||LA1_0==DECIMAL||(LA1_0 >= HEXIDECIMAL && LA1_0 <= LPAREN)||LA1_0==OCTAL||LA1_0==REAL||(LA1_0 >= SIN && LA1_0 <= TAN)) ) {
                alt1=1;
            }
            else if ( (LA1_0==EOF) ) {
                alt1=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 1, 0, input);

                throw nvae;

            }
            switch (alt1) {
                case 1 :
                    // Lab5.g:62:7: expr EOF
                    {
                    pushFollow(FOLLOW_expr_in_top257);
                    expr();

                    state._fsp--;


                    match(input,EOF,FOLLOW_EOF_in_top259); 

                    }
                    break;
                case 2 :
                    // Lab5.g:63:9: EOF
                    {
                    match(input,EOF,FOLLOW_EOF_in_top269); 

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "top"



    // $ANTLR start "expr"
    // Lab5.g:66:1: expr : l= pm ;
    public final void expr() throws RecognitionException {
        double l =0.0;


        try {
            // Lab5.g:66:6: (l= pm )
            // Lab5.g:66:8: l= pm
            {
            pushFollow(FOLLOW_pm_in_expr288);
            l=pm();

            state._fsp--;


             System.out.println( l ); 

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "expr"



    // $ANTLR start "pm"
    // Lab5.g:68:1: pm returns [double value] : l= md ( ( PLUS r= md ) | ( MINUS r= md ) )* ;
    public final double pm() throws RecognitionException {
        double value = 0.0;


        double l =0.0;

        double r =0.0;


        try {
            // Lab5.g:68:27: (l= md ( ( PLUS r= md ) | ( MINUS r= md ) )* )
            // Lab5.g:68:29: l= md ( ( PLUS r= md ) | ( MINUS r= md ) )*
            {
            pushFollow(FOLLOW_md_in_pm307);
            l=md();

            state._fsp--;


             value = l; 

            // Lab5.g:69:2: ( ( PLUS r= md ) | ( MINUS r= md ) )*
            loop2:
            do {
                int alt2=3;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==PLUS) ) {
                    alt2=1;
                }
                else if ( (LA2_0==MINUS) ) {
                    alt2=2;
                }


                switch (alt2) {
            	case 1 :
            	    // Lab5.g:69:3: ( PLUS r= md )
            	    {
            	    // Lab5.g:69:3: ( PLUS r= md )
            	    // Lab5.g:69:5: PLUS r= md
            	    {
            	    match(input,PLUS,FOLLOW_PLUS_in_pm315); 

            	    pushFollow(FOLLOW_md_in_pm321);
            	    r=md();

            	    state._fsp--;


            	     value += r; 

            	    }


            	    }
            	    break;
            	case 2 :
            	    // Lab5.g:70:3: ( MINUS r= md )
            	    {
            	    // Lab5.g:70:3: ( MINUS r= md )
            	    // Lab5.g:70:5: MINUS r= md
            	    {
            	    match(input,MINUS,FOLLOW_MINUS_in_pm331); 

            	    pushFollow(FOLLOW_md_in_pm337);
            	    r=md();

            	    state._fsp--;


            	    value -= r; 

            	    }


            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "pm"



    // $ANTLR start "md"
    // Lab5.g:72:1: md returns [double value] : l= ex ( ( DIV r= ex ) | ( MULT r= ex ) )* ;
    public final double md() throws RecognitionException {
        double value = 0.0;


        double l =0.0;

        double r =0.0;


        try {
            // Lab5.g:72:27: (l= ex ( ( DIV r= ex ) | ( MULT r= ex ) )* )
            // Lab5.g:72:29: l= ex ( ( DIV r= ex ) | ( MULT r= ex ) )*
            {
            pushFollow(FOLLOW_ex_in_md361);
            l=ex();

            state._fsp--;


             value = l; 

            // Lab5.g:73:2: ( ( DIV r= ex ) | ( MULT r= ex ) )*
            loop3:
            do {
                int alt3=3;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==DIV) ) {
                    alt3=1;
                }
                else if ( (LA3_0==MULT) ) {
                    alt3=2;
                }


                switch (alt3) {
            	case 1 :
            	    // Lab5.g:73:2: ( DIV r= ex )
            	    {
            	    // Lab5.g:73:2: ( DIV r= ex )
            	    // Lab5.g:73:4: DIV r= ex
            	    {
            	    match(input,DIV,FOLLOW_DIV_in_md368); 

            	    pushFollow(FOLLOW_ex_in_md374);
            	    r=ex();

            	    state._fsp--;


            	    if(r == 0) {
            	    			System.out.print("Error: Divide by zero");
            	    		}  else {
            	    			value /= r;
            	    		}
            	    	

            	    }


            	    }
            	    break;
            	case 2 :
            	    // Lab5.g:79:3: ( MULT r= ex )
            	    {
            	    // Lab5.g:79:3: ( MULT r= ex )
            	    // Lab5.g:79:5: MULT r= ex
            	    {
            	    match(input,MULT,FOLLOW_MULT_in_md384); 

            	    pushFollow(FOLLOW_ex_in_md390);
            	    r=ex();

            	    state._fsp--;


            	    value *= r; 

            	    }


            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "md"



    // $ANTLR start "ex"
    // Lab5.g:81:1: ex returns [double value] : l= paren ( EXP r= paren )* ;
    public final double ex() throws RecognitionException {
        double value = 0.0;


        double l =0.0;

        double r =0.0;


        try {
            // Lab5.g:81:27: (l= paren ( EXP r= paren )* )
            // Lab5.g:81:29: l= paren ( EXP r= paren )*
            {
            pushFollow(FOLLOW_paren_in_ex413);
            l=paren();

            state._fsp--;


            value = l;

            // Lab5.g:82:2: ( EXP r= paren )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( (LA4_0==EXP) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // Lab5.g:82:3: EXP r= paren
            	    {
            	    match(input,EXP,FOLLOW_EXP_in_ex419); 

            	    pushFollow(FOLLOW_paren_in_ex425);
            	    r=paren();

            	    state._fsp--;


            	     value = Math.pow(value, r); 

            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "ex"



    // $ANTLR start "paren"
    // Lab5.g:84:1: paren returns [double value] : ( LPAREN l= pm RPAREN |l= digit |l= func );
    public final double paren() throws RecognitionException {
        double value = 0.0;


        double l =0.0;


        try {
            // Lab5.g:84:30: ( LPAREN l= pm RPAREN |l= digit |l= func )
            int alt5=3;
            switch ( input.LA(1) ) {
            case LPAREN:
                {
                alt5=1;
                }
                break;
            case BINARY:
            case DECIMAL:
            case HEXIDECIMAL:
            case OCTAL:
            case REAL:
                {
                alt5=2;
                }
                break;
            case COS:
            case LOG:
            case SIN:
            case TAN:
                {
                alt5=3;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 5, 0, input);

                throw nvae;

            }

            switch (alt5) {
                case 1 :
                    // Lab5.g:84:32: LPAREN l= pm RPAREN
                    {
                    match(input,LPAREN,FOLLOW_LPAREN_in_paren442); 

                    pushFollow(FOLLOW_pm_in_paren448);
                    l=pm();

                    state._fsp--;


                    match(input,RPAREN,FOLLOW_RPAREN_in_paren450); 

                    value = l;

                    }
                    break;
                case 2 :
                    // Lab5.g:85:4: l= digit
                    {
                    pushFollow(FOLLOW_digit_in_paren461);
                    l=digit();

                    state._fsp--;


                    value = l;

                    }
                    break;
                case 3 :
                    // Lab5.g:86:4: l= func
                    {
                    pushFollow(FOLLOW_func_in_paren474);
                    l=func();

                    state._fsp--;


                    value = l;

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "paren"



    // $ANTLR start "func"
    // Lab5.g:88:1: func returns [double value] : ( LOG l= paren | SIN l= paren | COS l= paren | TAN l= paren );
    public final double func() throws RecognitionException {
        double value = 0.0;


        double l =0.0;


        try {
            // Lab5.g:89:2: ( LOG l= paren | SIN l= paren | COS l= paren | TAN l= paren )
            int alt6=4;
            switch ( input.LA(1) ) {
            case LOG:
                {
                alt6=1;
                }
                break;
            case SIN:
                {
                alt6=2;
                }
                break;
            case COS:
                {
                alt6=3;
                }
                break;
            case TAN:
                {
                alt6=4;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 6, 0, input);

                throw nvae;

            }

            switch (alt6) {
                case 1 :
                    // Lab5.g:89:4: LOG l= paren
                    {
                    match(input,LOG,FOLLOW_LOG_in_func493); 

                    pushFollow(FOLLOW_paren_in_func499);
                    l=paren();

                    state._fsp--;


                    value = Math.log(l);

                    }
                    break;
                case 2 :
                    // Lab5.g:90:4: SIN l= paren
                    {
                    match(input,SIN,FOLLOW_SIN_in_func506); 

                    pushFollow(FOLLOW_paren_in_func512);
                    l=paren();

                    state._fsp--;


                    value = Math.sin(l);

                    }
                    break;
                case 3 :
                    // Lab5.g:91:4: COS l= paren
                    {
                    match(input,COS,FOLLOW_COS_in_func519); 

                    pushFollow(FOLLOW_paren_in_func525);
                    l=paren();

                    state._fsp--;


                    value = Math.cos(l);

                    }
                    break;
                case 4 :
                    // Lab5.g:92:4: TAN l= paren
                    {
                    match(input,TAN,FOLLOW_TAN_in_func532); 

                    pushFollow(FOLLOW_paren_in_func538);
                    l=paren();

                    state._fsp--;


                    value = Math.tan(l);

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "func"



    // $ANTLR start "digit"
    // Lab5.g:94:1: digit returns [double value] : (l= HEXIDECIMAL |l= BINARY |l= OCTAL |l= REAL |l= DECIMAL );
    public final double digit() throws RecognitionException {
        double value = 0.0;


        Token l=null;

        try {
            // Lab5.g:95:4: (l= HEXIDECIMAL |l= BINARY |l= OCTAL |l= REAL |l= DECIMAL )
            int alt7=5;
            switch ( input.LA(1) ) {
            case HEXIDECIMAL:
                {
                alt7=1;
                }
                break;
            case BINARY:
                {
                alt7=2;
                }
                break;
            case OCTAL:
                {
                alt7=3;
                }
                break;
            case REAL:
                {
                alt7=4;
                }
                break;
            case DECIMAL:
                {
                alt7=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 7, 0, input);

                throw nvae;

            }

            switch (alt7) {
                case 1 :
                    // Lab5.g:95:4: l= HEXIDECIMAL
                    {
                    l=(Token)match(input,HEXIDECIMAL,FOLLOW_HEXIDECIMAL_in_digit557); 

                     value = (double)Integer.decode( l.getText()); 

                    }
                    break;
                case 2 :
                    // Lab5.g:96:4: l= BINARY
                    {
                    l=(Token)match(input,BINARY,FOLLOW_BINARY_in_digit568); 

                     value = (double)Integer.parseInt( l.getText(), 2); 

                    }
                    break;
                case 3 :
                    // Lab5.g:97:4: l= OCTAL
                    {
                    l=(Token)match(input,OCTAL,FOLLOW_OCTAL_in_digit579); 

                     value = (double)Integer.decode( l.getText()); 

                    }
                    break;
                case 4 :
                    // Lab5.g:98:4: l= REAL
                    {
                    l=(Token)match(input,REAL,FOLLOW_REAL_in_digit591); 

                    value = Double.parseDouble( l.getText()); 

                    }
                    break;
                case 5 :
                    // Lab5.g:99:4: l= DECIMAL
                    {
                    l=(Token)match(input,DECIMAL,FOLLOW_DECIMAL_in_digit603); 

                     value = Integer.parseInt( l.getText(), 10 ); 

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return value;
    }
    // $ANTLR end "digit"

    // Delegated rules


 

    public static final BitSet FOLLOW_expr_in_top257 = new BitSet(new long[]{0x0000000000000000L});
    public static final BitSet FOLLOW_EOF_in_top259 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_EOF_in_top269 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_pm_in_expr288 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_md_in_pm307 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_PLUS_in_pm315 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_md_in_pm321 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_MINUS_in_pm331 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_md_in_pm337 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_ex_in_md361 = new BitSet(new long[]{0x0000000000010202L});
    public static final BitSet FOLLOW_DIV_in_md368 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_ex_in_md374 = new BitSet(new long[]{0x0000000000010202L});
    public static final BitSet FOLLOW_MULT_in_md384 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_ex_in_md390 = new BitSet(new long[]{0x0000000000010202L});
    public static final BitSet FOLLOW_paren_in_ex413 = new BitSet(new long[]{0x0000000000000402L});
    public static final BitSet FOLLOW_EXP_in_ex419 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_paren_in_ex425 = new BitSet(new long[]{0x0000000000000402L});
    public static final BitSet FOLLOW_LPAREN_in_paren442 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_pm_in_paren448 = new BitSet(new long[]{0x0000000000200000L});
    public static final BitSet FOLLOW_RPAREN_in_paren450 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_digit_in_paren461 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_func_in_paren474 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_LOG_in_func493 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_paren_in_func499 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_SIN_in_func506 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_paren_in_func512 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_COS_in_func519 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_paren_in_func525 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAN_in_func532 = new BitSet(new long[]{0x0000000000D47160L});
    public static final BitSet FOLLOW_paren_in_func538 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_HEXIDECIMAL_in_digit557 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_BINARY_in_digit568 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_OCTAL_in_digit579 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_REAL_in_digit591 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_DECIMAL_in_digit603 = new BitSet(new long[]{0x0000000000000002L});

}