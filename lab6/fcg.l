%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcg.yacc.h>


#ifndef NDEBUG
#    define DEBUGF(...) printf(__VA_ARGS__)
#else
#    define DEBUGF(...)
#endif
%}

%option       noyywrap nounput yylineno
%x            COMMENT

whitesp       [ \t\n\r]
nonwhitesp    [^ \t\n\r]

ID        [a-zA-Z][a-zA-Z0-9_]*
PREPROC   "#"[^\n]*\n

INTVAL    [0-9]+|"0"[0-7]*|"0x"[0-9a-fA-F]*
DBLVAL    [0-9]+"."[0-9]+
FLTVAL    [0-9]+"."[0-9]+"f"
CHARVAL   \'([^']|\\.)*\'
STRVAL    \"([^"]|\\.)*\"
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
BITXOR     "^"
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

%%

%{
 /**************************************************************************
  * Scan miscellaneous C punctuation.
  *************************************************************************/
%}

"("         { DEBUGF( "(\n" ); return '('; }
")"         { DEBUGF( ")\n" ); return ')'; }
"{"         { DEBUGF( "{\n" ); return '{'; }
"}"         { DEBUGF( "}\n" ); return '}'; }
"["         { DEBUGF( "[\n" ); return '['; }
"]"         { DEBUGF( "]\n" ); return ']'; }
","         { DEBUGF( ",\n" ); return ','; }
";"         { DEBUGF( ";\n" ); return ';'; }

%{
 /**************************************************************************
  * Scan C identifiers.
  *************************************************************************/
%}

{ID}        { DEBUGF("ID\n") return ID; }

%{
 /**************************************************************************
  * Scan a multi-line C comment using left context or a C single line
  * comment to the end of the line.
  *************************************************************************/
%}

"//".*                      { /* ignored */ }

"/*"                        { BEGIN COMMENT; }
<COMMENT>"*/"               { BEGIN 0; }
<COMMENT>([\n](\r)?)|.      { /* ignored */ }

%{
 /**************************************************************************
  * Scan C literal values including strings, character literals, integer
  * literals, and floating point literals.
  *************************************************************************/
%}

%{/*{PREPROC}   { DEBUGF("PREPROC\n"); return PREPROC; }
{OR}        { DEBUGF("OR\n"); return OR; }
{AND}       { DEBUGF("AND\n"); return AND; }
{SETADD}    { DEBUGF("SETADD\n"); return SETADD; }
{SETSUB}    { DEBUGF("SETSUB\n"); return SETSUB; }
{SETMUL}    { DEBUGF("SETMUL\n"); return SETMUL; }
{SETDIV}    { DEBUGF("SETDIV\n"); return SETDIV; }
{SETMOD}    { DEBUGF("SETMOD\n"); return SETMOD; }
{SETOR}     { DEBUGF("SETOR\n"); return SETOR; }
{SETAND}    { DEBUGF("SETAND\n"); return SETAND; }
{SETXOR}    { DEBUGF("SETXOR\n"); return SETXOR; }
{SETLSH}    { DEBUGF("SETLSH\n"); return SETLSH; }
{SETRSH}    { DEBUGF("SETRSH\n"); return SETRSH; }
{DO}        { DEBUGF("DO\n"); return DO; }
{FOR}       { DEBUGF("FOR\n"); return FOR; }
{SWITCH}    { DEBUGF("SWITCH\n"); return SWITCH; }
{CASE}      { DEBUGF("CASE\n"); return CASE; }
{DEFAULT}   { DEBUGF("DEFAULT\n"); return DEFAULT; }
{CONTINUE}  { DEBUGF("CONTINUE\n"); return CONTINUE; }
{BREAK}     { DEBUGF("BREAK\n"); return BREAK; }
{GOTO}      { DEBUGF("GOTO\n"); return GOTO; }
{UNSIGNED}  { DEBUGF("UNSIGNED\n"); return UNSIGNED; }
{TYPEDEF}   { DEBUGF("TYPEDEF\n"); return TYPEDEF; }
{STRUCT}    { DEBUGF("STRUCT\n"); return STRUCT; }
{UNION}     { DEBUGF("UNION\n"); return UNION; }
{CONST}     { DEBUGF("CONST\n"); return CONST; }
{STATIC}    { DEBUGF("STATIC\n"); return STATIC; }
{EXTERN}    { DEBUGF("EXTERN\n"); return EXTERN; }
{AUTO}      { DEBUGF("AUTO\n"); return AUTO; }
{REGISTER}  { DEBUGF("REGISTER\n"); return REGISTER; }
{SIZEOF}    { DEBUGF("SIZEOF\n"); return SIZEOF; }*/%}
{INTVAL}    { DEBUGF("INTVAL\n"); return INTVAL; }
{DBLVAL}    { DEBUGF("DBLVAL\n"); return DBLVAL; }
{FLTVAL}    { DEBUGF("FLTVAL\n"); return FLTVAL; }
{CHARVAL}   { DEBUGF("CHARVAL\n"); return CHARVAL; }
{STRVAL}    { DEBUGF("STRVAL\n"); return STRVAL; }
{VOID}      { DEBUGF("VOID\n"); return VOID; }
{SHORT}     { DEBUGF("SHORT\n"); return SHORT; }
{LONG}      { DEBUGF("LONG\n"); return LONG; }
{DOUBLE}    { DEBUGF("DOUBLE\n"); return DOUBLE; }
{CHAR}      { DEBUGF("CHAR\n"); return CHAR; }
{INT}       { DEBUGF("INT\n"); return INT; }
{FLOAT}     { DEBUGF("FLOAT\n"); return FLOAT; }
{EQ}        { DEBUGF("EQ\n"); return EQ; }
{NE}        { DEBUGF("NE\n"); return NE; }
{GE}        { DEBUGF("GE\n"); return GE; }
{LE}        { DEBUGF("LE\n"); return LE; }
{GT}        { DEBUGF("GT\n"); return GT; }
{LT}        { DEBUGF("LT\n"); return LT; }
{ADD}       { DEBUGF("ADD\n"); return ADD; }
{SUB}       { DEBUGF("SUB\n"); return SUB; }
{MUL}       { DEBUGF("MUL\n"); return MUL; }
{DIV}       { DEBUGF("DIV\n"); return DIV; }
{MOD}       { DEBUGF("MOD\n"); return MOD; }
{BITOR}     { DEBUGF("BITOR\n"); return BITOR; }
{BITAND}    { DEBUGF("BITAND\n"); return BITAND; }
{BITXOR}    { DEBUGF("BITXOR\n"); return BITXOR; }
{LSH}       { DEBUGF("LSH\n"); return LSH; }
{RSH}       { DEBUGF("RSH\n"); return RSH; }
{SET}       { DEBUGF("SET\n"); return SET; }
{RETURN}    { DEBUGF("RETURN\n"); return RETURN; }

{WHILE}     { DEBUGF("WHILE\n"); return WHILE; }

{IF}        { DEBUGF("IF\n"); return IF; }
{ELSE}      { DEBUGF("ELSE\n"); return ELSE; }



%{
 /**************************************************************************
  * Scan white space in-between tokens and ignore it.
  *************************************************************************/
%}

{whitesp}+  { /* ignored */  }

%{
 /**************************************************************************
  * Anything else that matches is unexpected so print an error.
  *************************************************************************/
%}

. {
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}

%%
int main(int argc, const char* argv[])
{
  while(yylex()){};
  return 0;
}
