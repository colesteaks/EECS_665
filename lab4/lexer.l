%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the tokens that you want to return from your lex as follows
#define ID      256
#define PREPROC 257
//Literal Values
#define INTVAL  258
#define DBLVAL  259
#define FLTVAL  260
#define CHARVAL 261
#define STRVAL  262
//Primitive Types
#define VOID    263
#define SHORT   264
#define LONG    265
#define DOUBLE  266
#define CHAR    267
#define INT     268
#define FLOAT   269
//Operators
#define EQ      270
#define NE      271
#define GE      272
#define LE      273
#define GT      274
#define LT      275
#define ADD     276
#define SUB     277
#define MUL     278
#define DIV     279
#define MOD     280
#define OR      281
#define AND     282
#define BITOR   283
#define BITAND  284
#define LSH     285
#define RSH     286
#define SET     287
#define SETADD  288
#define SETSUB  289
#define SETMUL  290
#define SETDIV  291
#define SETMOD  292
#define SETOR   293
#define SETAND  294
#define SETXOR  295
#define SETLSH  296
#define SETRSH  297
//Control Flow
#define RETURN    298
#define DO        299
#define WHILE     300
#define FOR       301
#define SWITCH    302
#define CASE      303
#define DEFAULT   304
#define IF        305
#define ELSE      306
#define CONTINUE  308
#define BREAK     309
#define GOTO      310
//Keywords
#define UNSIGNED  311
#define TYPEDEF   312
#define STRUCT    313
#define UNION     314
#define CONST     315
#define STATIC    316
#define EXTERN    317
#define AUTO      318
#define REGISTER  319
#define SIZEOF    320

int list_type;
%}

%option noyywrap nounput yylineno
ID        [a-zA-Z][a-zA-Z0-9_]*
PREPROC   "#".

INTVAL    [0-9]+|"0"[0-7]*|"0x"[0-9a-fA-F]*
DBLVAL    [0-9]+"."[0-9]+
FLTVAL    [0-9]+"."[0-9]+"f"
CHARVAL   \'.\'
STRVAL    \".\"

VOID      "void"
SHORT     "short"
LONG      "long"
DOUBLE    "double"
CHAR      "char"
INT       "int"
FLOAT     "float"

EQ        "=="
NE        "!="
GE        ">="
LE        "<="
GT        ">"
LT        "<"
ADD       "+"
SUB       "-"
MUL       "*"
DIV       "/"
MOD       "%"
OR        "||"
AND       "&&"
BITOR     "|"
BITAND    "&"
LSH       "<<"
RSH       ">>"
SET       "="
SETADD    "+="
SETSUB    "-="
SETMUL    "*="
SETDIV    "/="
SETMOD    "%="
SETOR     "|="
SETAND    "&="
SETXOR    "^="
SETLSH    "<<="
SETRSH    ">>="

RETURN    "return"
DO        "do"
WHILE     "while"
FOR       "for"
SWITCH    "switch"
CASE      "case"
DEFAULT   "default"
IF        "if"
ELSE      "else"
CONTINUE  "continue"
BREAK     "break"
GOTO      "goto"

UNSIGNED  "unsigned"
TYPEDEF   "typedef"
STRUCT    "struct"
UNION     "union"
CONST     "const"
STATIC    "static"
EXTERN    "extern"
AUTO      "auto"
REGISTER  "register"
SIZEOF    "sizeof"


%x INCOMMENT INLINECOMMENT

%%
"//" {
/****************************************
* Matching with Single line comments in our
* C code
******************************************/
BEGIN INLINECOMMENT;
}

<INLINECOMMENT>[\n](\r)? {
/****************************************
* A new line indicates end of a single
* line comment in C
****************************************/

BEGIN 0;
}

<INLINECOMMENT>[ \t] {
/****************************************
* Lexer ignores the comments section
* by Ignoring anything inside a comment
****************************************/
}

<INLINECOMMENT>. {
}

"/*" {
/****************************************
* Matching with Single line comments in our
* C code
******************************************/
BEGIN INLINECOMMENT;
}

<INCOMMENT>"*/" {
/****************************************
* A new line indicates end of a single
* line comment in C
****************************************/
BEGIN 0;
}

<INCOMMENT>[ \t] {
/****************************************
* Lexer ignores the comments section
* by Ignoring anything inside a comment
****************************************/
}

<INCOMMENT>. {
}

{PREPROC} {
  /***********************
  * Preprocessor command
  ***********************/
  printf("PREPROC\n");
  return PREPROC;
}

{INTVAL} {
  printf("INTVAL\n");
  return INTVAL;
}

{DBLVAL} {
  printf("DBLVAL\n");
  return DBLVAL;
}

{FLTVAL} {
  printf("FLTVAL\n");
  return FLTVAL;
}

{CHARVAL} {
  printf("CHARVAL\n");
  return CHARVAL;
}
{STRVAL} {
  printf("STRVAL\n");
  return STRVAL;
}
{VOID} {
  printf("VOID\n");
  return VOID;
}
{SHORT} {
  printf("SHORT\n");
  return SHORT;
}
{LONG} {
  printf("LONG\n");
  return LONG;
}
{DOUBLE} {
  printf("DOUBLE\n");
  return DOUBLE;
}
{CHAR} {
  printf("CHAR\n");
  return CHAR;
}
{INT} {
  printf("INT\n");
  return INT;
}
{FLOAT} {
  printf("FLOAT\n");
  return FLOAT;
}
{EQ} {
  printf("EQ\n");
  return EQ;
}
{NE} {
  printf("NE\n");
  return NE;
}
{GE} {
  printf("GE\n");
  return GE;
}
{LE} {
  printf("LE\n");
  return LE;
}
{GT} {
  printf("GT\n");
  return GT;
}
{LT} {
  printf("LT\n");
  return LT;
}
{ADD} {
  printf("ADD\n");
  return ADD;
}
{SUB} {
  printf("SUB\n");
  return SUB;
}
{MUL} {
  printf("MUL\n");
  return MUL;
}
{DIV} {
  printf("DIV\n");
  return DIV;
}
{MOD} {
  printf("MOD\n");
  return MOD;
}
{OR} {
  printf("OR\n");
  return OR;
}
{AND} {
  printf("AND\n");
  return AND;
}
{BITOR} {
  printf("BITOR\n");
  return BITOR;
}
{BITAND} {
  printf("BITAND\n");
  return BITAND;
}
{LSH} {
  printf("LSH\n");
  return LSH;
}
{RSH} {
  printf("RSH\n");
  return RSH;
}
{SET} {
  printf("SET\n");
  return SET;
}
{SETADD} {
  printf("SETADD\n");
  return SETADD;
}
{SETSUB} {
  printf("SETSUB\n");
  return SETSUB;
}
{SETMUL} {
  printf("SETMUL\n");
  return SETMUL;
}
{SETDIV} {
  printf("SETDIV\n");
  return SETDIV;
}
{SETMOD} {
  printf("SETMOD\n");
  return SETMOD;
}
{SETOR} {
  printf("SETOR\n");
  return SETOR;
}
{SETAND} {
  printf("SETAND\n");
  return SETAND;
}
{SETXOR} {
  printf("SETXOR\n");
  return SETXOR;
}
{SETLSH} {
  printf("SETLSH\n");
  return SETLSH;
}
{SETRSH} {
  printf("SETRSH\n");
  return SETRSH;
}
{RETURN} {
  printf("RETURN\n");
  return RETURN;
}
{DO} {
  printf("DO\n");
  return DO;
}
{WHILE} {
  printf("WHILE\n");
  return WHILE;
}
{FOR} {
  printf("FOR\n");
  return FOR;
}
{SWITCH} {
  printf("SWITCH\n");
  return SWITCH;
}
{CASE} {
  printf("CASE\n");
  return CASE;
}
{DEFAULT} {
  printf("DEFAULT\n");
  return DEFAULT;
}
{IF} {
  printf("IF\n");
  return IF;
}
{ELSE} {
  printf("ELSE\n");
  return ELSE;
}
{CONTINUE} {
  printf("CONTINUE\n");
  return CONTINUE;
}
{BREAK} {
  printf("BREAK\n");
  return BREAK;
}
{GOTO} {
  printf("GOTO\n");
  return GOTO;
}
{UNSIGNED} {
  printf("UNSIGNED\n");
  return UNSIGNED;
}
{TYPEDEF} {
  printf("TYPEDEF\n");
  return TYPEDEF;
}
{STRUCT} {
  printf("STRUCT\n");
  return STRUCT;
}
{UNION} {
  printf("UNION\n");
  return UNION;
}
{CONST} {
  printf("CONST\n");
  return CONST;
}
{STATIC} {
  printf("STATIC\n");
  return STATIC;
}
{EXTERN} {
  printf("EXTERN\n");
  return EXTERN;
}
{AUTO} {
  printf("AUTO\n");
  return AUTO;
}
{REGISTER} {
  printf("REGISTER\n");
  return REGISTER;
}
{SIZEOF} {
  printf("SIZEOF\n");
  return SIZEOF;
}

"(" {
  printf("(\n");
}

")" {
  printf(")\n");
}

"[" {
  printf("[\n");
}

"]" {
  printf("]\n");
}

"," {
  printf(",\n");
}

";" {
  printf(";\n");
}

"{" {
  printf("{\n");
}

"}" {
  printf("}\n");
}

{ID} {
/**************************************
* If an identifier is matched, then
* print ID and return a token ID
**************************************/

printf("ID\n");
return ID;
}

%%
int main(int argc, const char* argv[])
{
  /*Make a call to yylex() recursively. Whenever yylex() is called, it scans tokens from the
    global input file yyin (which defaults to stdin). It continues until it either reaches an
    end-of-file (at which point it returns the value 0) or one of its actions executes a return statement.*/
  yylex();
return 0;
}
