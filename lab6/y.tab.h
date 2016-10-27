/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTVAL = 259,
     STRVAL = 260,
     CHARVAL = 261,
     DBLVAL = 262,
     FLTVAL = 263,
     EQ = 264,
     NE = 265,
     GE = 266,
     LE = 267,
     GT = 268,
     LT = 269,
     ADD = 270,
     SUB = 271,
     MUL = 272,
     DIV = 273,
     MOD = 274,
     BITOR = 275,
     BITAND = 276,
     BITXOR = 277,
     LSH = 278,
     RSH = 279,
     SET = 280,
     RETURN = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     VOID = 285,
     CHAR = 286,
     SHORT = 287,
     INT = 288,
     LONG = 289,
     FLOAT = 290,
     DOUBLE = 291
   };
#endif
/* Tokens.  */
#define ID 258
#define INTVAL 259
#define STRVAL 260
#define CHARVAL 261
#define DBLVAL 262
#define FLTVAL 263
#define EQ 264
#define NE 265
#define GE 266
#define LE 267
#define GT 268
#define LT 269
#define ADD 270
#define SUB 271
#define MUL 272
#define DIV 273
#define MOD 274
#define BITOR 275
#define BITAND 276
#define BITXOR 277
#define LSH 278
#define RSH 279
#define SET 280
#define RETURN 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define VOID 285
#define CHAR 286
#define SHORT 287
#define INT 288
#define LONG 289
#define FLOAT 290
#define DOUBLE 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "fcg.y"
{
    char* id;
    int intval;
    double dblval;
    float fltval;
    char charval;
    char* strval;
}
/* Line 1529 of yacc.c.  */
#line 130 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

