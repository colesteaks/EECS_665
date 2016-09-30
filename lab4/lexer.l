%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the tokens that you want to return from your lex as follows
#define ID 256
#define INTVAL 257

int list_type;
%}

%option noyywrap nounput yylineno
ID        [a-zA-Z][a-zA-Z0-9_]*
PREPROC   "#".\n

INTVAL    [0-9]+|[0-7]+|[0-16]+
DBLVAL    [0-9]+"."[0-9]+
FLTVAL    [0-9]+"."[0-9]+"f"
CHARVAL   \'.\'
STRVAL    \".\"


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
  //return PREPROC;
}

{ID} {
/**************************************
* If an identifier is matched, then
* print ID and return a token ID
**************************************/

printf("ID\n");
return ID;
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

%%
int main(int argc, const char* argv[])
{
  /*Make a call to yylex() recursively. Whenever yylex() is called, it scans tokens from the
    global input file yyin (which defaults to stdin). It continues until it either reaches an
    end-of-file (at which point it returns the value 0) or one of its actions executes a return statement.*/
  yylex();
return 0;
}
