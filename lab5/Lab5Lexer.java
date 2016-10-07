// $ANTLR 3.4 Lab5.g 2016-10-07 15:06:01

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class Lab5Lexer extends Lexer {
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
    // delegators
    public Lexer[] getDelegates() {
        return new Lexer[] {};
    }

    public Lab5Lexer() {} 
    public Lab5Lexer(CharStream input) {
        this(input, new RecognizerSharedState());
    }
    public Lab5Lexer(CharStream input, RecognizerSharedState state) {
        super(input,state);
    }
    public String getGrammarFileName() { return "Lab5.g"; }

    // $ANTLR start "COS"
    public final void mCOS() throws RecognitionException {
        try {
            int _type = COS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:2:5: ( 'cos' )
            // Lab5.g:2:7: 'cos'
            {
            match("cos"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "COS"

    // $ANTLR start "DIV"
    public final void mDIV() throws RecognitionException {
        try {
            int _type = DIV;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:3:5: ( '/' )
            // Lab5.g:3:7: '/'
            {
            match('/'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DIV"

    // $ANTLR start "EXP"
    public final void mEXP() throws RecognitionException {
        try {
            int _type = EXP;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:4:5: ( '^' )
            // Lab5.g:4:7: '^'
            {
            match('^'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "EXP"

    // $ANTLR start "LOG"
    public final void mLOG() throws RecognitionException {
        try {
            int _type = LOG;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:5:5: ( 'log' )
            // Lab5.g:5:7: 'log'
            {
            match("log"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "LOG"

    // $ANTLR start "LPAREN"
    public final void mLPAREN() throws RecognitionException {
        try {
            int _type = LPAREN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:6:8: ( '(' )
            // Lab5.g:6:10: '('
            {
            match('('); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "LPAREN"

    // $ANTLR start "MINUS"
    public final void mMINUS() throws RecognitionException {
        try {
            int _type = MINUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:7:7: ( '-' )
            // Lab5.g:7:9: '-'
            {
            match('-'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "MINUS"

    // $ANTLR start "MULT"
    public final void mMULT() throws RecognitionException {
        try {
            int _type = MULT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:8:6: ( '*' )
            // Lab5.g:8:8: '*'
            {
            match('*'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "MULT"

    // $ANTLR start "PLUS"
    public final void mPLUS() throws RecognitionException {
        try {
            int _type = PLUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:9:6: ( '+' )
            // Lab5.g:9:8: '+'
            {
            match('+'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "PLUS"

    // $ANTLR start "RPAREN"
    public final void mRPAREN() throws RecognitionException {
        try {
            int _type = RPAREN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:10:8: ( ')' )
            // Lab5.g:10:10: ')'
            {
            match(')'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "RPAREN"

    // $ANTLR start "SIN"
    public final void mSIN() throws RecognitionException {
        try {
            int _type = SIN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:11:5: ( 'sin' )
            // Lab5.g:11:7: 'sin'
            {
            match("sin"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "SIN"

    // $ANTLR start "TAN"
    public final void mTAN() throws RecognitionException {
        try {
            int _type = TAN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:12:5: ( 'tan' )
            // Lab5.g:12:7: 'tan'
            {
            match("tan"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "TAN"

    // $ANTLR start "BIN"
    public final void mBIN() throws RecognitionException {
        try {
            // Lab5.g:43:13: ( '0' .. '1' )
            // Lab5.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '1') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "BIN"

    // $ANTLR start "OCT"
    public final void mOCT() throws RecognitionException {
        try {
            // Lab5.g:44:13: ( '0' .. '7' )
            // Lab5.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '7') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "OCT"

    // $ANTLR start "DEC"
    public final void mDEC() throws RecognitionException {
        try {
            // Lab5.g:45:13: ( '0' .. '9' )
            // Lab5.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DEC"

    // $ANTLR start "HEX"
    public final void mHEX() throws RecognitionException {
        try {
            // Lab5.g:46:13: ( ( '0' .. '9' | 'A' .. 'F' | 'a' .. 'f' ) )
            // Lab5.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'F')||(input.LA(1) >= 'a' && input.LA(1) <= 'f') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "HEX"

    // $ANTLR start "WS"
    public final void mWS() throws RecognitionException {
        try {
            int _type = WS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:51:4: ( ( ' ' | '\\t' | '\\r' | '\\n' )+ )
            // Lab5.g:51:6: ( ' ' | '\\t' | '\\r' | '\\n' )+
            {
            // Lab5.g:51:6: ( ' ' | '\\t' | '\\r' | '\\n' )+
            int cnt1=0;
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( ((LA1_0 >= '\t' && LA1_0 <= '\n')||LA1_0=='\r'||LA1_0==' ') ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '\t' && input.LA(1) <= '\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt1 >= 1 ) break loop1;
                        EarlyExitException eee =
                            new EarlyExitException(1, input);
                        throw eee;
                }
                cnt1++;
            } while (true);


             _channel=HIDDEN; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "WS"

    // $ANTLR start "OCTAL"
    public final void mOCTAL() throws RecognitionException {
        try {
            int _type = OCTAL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:54:8: ( '0' ( OCT )+ )
            // Lab5.g:54:10: '0' ( OCT )+
            {
            match('0'); 

            // Lab5.g:54:14: ( OCT )+
            int cnt2=0;
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( ((LA2_0 >= '0' && LA2_0 <= '7')) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '7') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt2 >= 1 ) break loop2;
                        EarlyExitException eee =
                            new EarlyExitException(2, input);
                        throw eee;
                }
                cnt2++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "OCTAL"

    // $ANTLR start "HEXIDECIMAL"
    public final void mHEXIDECIMAL() throws RecognitionException {
        try {
            int _type = HEXIDECIMAL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:55:13: ( '0x' ( HEX )+ )
            // Lab5.g:55:15: '0x' ( HEX )+
            {
            match("0x"); 



            // Lab5.g:55:20: ( HEX )+
            int cnt3=0;
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( ((LA3_0 >= '0' && LA3_0 <= '9')||(LA3_0 >= 'A' && LA3_0 <= 'F')||(LA3_0 >= 'a' && LA3_0 <= 'f')) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'F')||(input.LA(1) >= 'a' && input.LA(1) <= 'f') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt3 >= 1 ) break loop3;
                        EarlyExitException eee =
                            new EarlyExitException(3, input);
                        throw eee;
                }
                cnt3++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "HEXIDECIMAL"

    // $ANTLR start "BINARY"
    public final void mBINARY() throws RecognitionException {
        try {
            int _type = BINARY;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:56:9: ( '0b' ( BIN )+ )
            // Lab5.g:56:11: '0b' ( BIN )+
            {
            match("0b"); 



            // Lab5.g:56:16: ( BIN )+
            int cnt4=0;
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( ((LA4_0 >= '0' && LA4_0 <= '1')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '1') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt4 >= 1 ) break loop4;
                        EarlyExitException eee =
                            new EarlyExitException(4, input);
                        throw eee;
                }
                cnt4++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "BINARY"

    // $ANTLR start "REAL"
    public final void mREAL() throws RecognitionException {
        try {
            int _type = REAL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:57:7: ( ( DEC )+ '.' ( DEC )+ )
            // Lab5.g:57:9: ( DEC )+ '.' ( DEC )+
            {
            // Lab5.g:57:9: ( DEC )+
            int cnt5=0;
            loop5:
            do {
                int alt5=2;
                int LA5_0 = input.LA(1);

                if ( ((LA5_0 >= '0' && LA5_0 <= '9')) ) {
                    alt5=1;
                }


                switch (alt5) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt5 >= 1 ) break loop5;
                        EarlyExitException eee =
                            new EarlyExitException(5, input);
                        throw eee;
                }
                cnt5++;
            } while (true);


            match('.'); 

            // Lab5.g:57:18: ( DEC )+
            int cnt6=0;
            loop6:
            do {
                int alt6=2;
                int LA6_0 = input.LA(1);

                if ( ((LA6_0 >= '0' && LA6_0 <= '9')) ) {
                    alt6=1;
                }


                switch (alt6) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt6 >= 1 ) break loop6;
                        EarlyExitException eee =
                            new EarlyExitException(6, input);
                        throw eee;
                }
                cnt6++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "REAL"

    // $ANTLR start "DECIMAL"
    public final void mDECIMAL() throws RecognitionException {
        try {
            int _type = DECIMAL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // Lab5.g:58:10: ( ( DEC )+ )
            // Lab5.g:58:12: ( DEC )+
            {
            // Lab5.g:58:12: ( DEC )+
            int cnt7=0;
            loop7:
            do {
                int alt7=2;
                int LA7_0 = input.LA(1);

                if ( ((LA7_0 >= '0' && LA7_0 <= '9')) ) {
                    alt7=1;
                }


                switch (alt7) {
            	case 1 :
            	    // Lab5.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt7 >= 1 ) break loop7;
                        EarlyExitException eee =
                            new EarlyExitException(7, input);
                        throw eee;
                }
                cnt7++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DECIMAL"

    public void mTokens() throws RecognitionException {
        // Lab5.g:1:8: ( COS | DIV | EXP | LOG | LPAREN | MINUS | MULT | PLUS | RPAREN | SIN | TAN | WS | OCTAL | HEXIDECIMAL | BINARY | REAL | DECIMAL )
        int alt8=17;
        alt8 = dfa8.predict(input);
        switch (alt8) {
            case 1 :
                // Lab5.g:1:10: COS
                {
                mCOS(); 


                }
                break;
            case 2 :
                // Lab5.g:1:14: DIV
                {
                mDIV(); 


                }
                break;
            case 3 :
                // Lab5.g:1:18: EXP
                {
                mEXP(); 


                }
                break;
            case 4 :
                // Lab5.g:1:22: LOG
                {
                mLOG(); 


                }
                break;
            case 5 :
                // Lab5.g:1:26: LPAREN
                {
                mLPAREN(); 


                }
                break;
            case 6 :
                // Lab5.g:1:33: MINUS
                {
                mMINUS(); 


                }
                break;
            case 7 :
                // Lab5.g:1:39: MULT
                {
                mMULT(); 


                }
                break;
            case 8 :
                // Lab5.g:1:44: PLUS
                {
                mPLUS(); 


                }
                break;
            case 9 :
                // Lab5.g:1:49: RPAREN
                {
                mRPAREN(); 


                }
                break;
            case 10 :
                // Lab5.g:1:56: SIN
                {
                mSIN(); 


                }
                break;
            case 11 :
                // Lab5.g:1:60: TAN
                {
                mTAN(); 


                }
                break;
            case 12 :
                // Lab5.g:1:64: WS
                {
                mWS(); 


                }
                break;
            case 13 :
                // Lab5.g:1:67: OCTAL
                {
                mOCTAL(); 


                }
                break;
            case 14 :
                // Lab5.g:1:73: HEXIDECIMAL
                {
                mHEXIDECIMAL(); 


                }
                break;
            case 15 :
                // Lab5.g:1:85: BINARY
                {
                mBINARY(); 


                }
                break;
            case 16 :
                // Lab5.g:1:92: REAL
                {
                mREAL(); 


                }
                break;
            case 17 :
                // Lab5.g:1:97: DECIMAL
                {
                mDECIMAL(); 


                }
                break;

        }

    }


    protected DFA8 dfa8 = new DFA8(this);
    static final String DFA8_eotS =
        "\15\uffff\2\23\2\uffff\1\24\3\uffff";
    static final String DFA8_eofS =
        "\25\uffff";
    static final String DFA8_minS =
        "\1\11\14\uffff\2\56\2\uffff\1\56\3\uffff";
    static final String DFA8_maxS =
        "\1\164\14\uffff\1\170\1\71\2\uffff\1\71\3\uffff";
    static final String DFA8_acceptS =
        "\1\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\7\1\10\1\11\1\12\1\13\1\14\2"+
        "\uffff\1\16\1\17\1\uffff\1\20\1\21\1\15";
    static final String DFA8_specialS =
        "\25\uffff}>";
    static final String[] DFA8_transitionS = {
            "\2\14\2\uffff\1\14\22\uffff\1\14\7\uffff\1\5\1\11\1\7\1\10\1"+
            "\uffff\1\6\1\uffff\1\2\1\15\11\16\44\uffff\1\3\4\uffff\1\1\10"+
            "\uffff\1\4\6\uffff\1\12\1\13",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "\1\22\1\uffff\10\21\2\16\50\uffff\1\20\25\uffff\1\17",
            "\1\22\1\uffff\12\16",
            "",
            "",
            "\1\22\1\uffff\10\21\2\16",
            "",
            "",
            ""
    };

    static final short[] DFA8_eot = DFA.unpackEncodedString(DFA8_eotS);
    static final short[] DFA8_eof = DFA.unpackEncodedString(DFA8_eofS);
    static final char[] DFA8_min = DFA.unpackEncodedStringToUnsignedChars(DFA8_minS);
    static final char[] DFA8_max = DFA.unpackEncodedStringToUnsignedChars(DFA8_maxS);
    static final short[] DFA8_accept = DFA.unpackEncodedString(DFA8_acceptS);
    static final short[] DFA8_special = DFA.unpackEncodedString(DFA8_specialS);
    static final short[][] DFA8_transition;

    static {
        int numStates = DFA8_transitionS.length;
        DFA8_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA8_transition[i] = DFA.unpackEncodedString(DFA8_transitionS[i]);
        }
    }

    class DFA8 extends DFA {

        public DFA8(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 8;
            this.eot = DFA8_eot;
            this.eof = DFA8_eof;
            this.min = DFA8_min;
            this.max = DFA8_max;
            this.accept = DFA8_accept;
            this.special = DFA8_special;
            this.transition = DFA8_transition;
        }
        public String getDescription() {
            return "1:1: Tokens : ( COS | DIV | EXP | LOG | LPAREN | MINUS | MULT | PLUS | RPAREN | SIN | TAN | WS | OCTAL | HEXIDECIMAL | BINARY | REAL | DECIMAL );";
        }
    }
 

}