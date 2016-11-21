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
     CON = 259,
     STR = 260,
     CHAR = 261,
     ELSE = 262,
     FLOAT = 263,
     DOUBLE = 264,
     FOR = 265,
     IF = 266,
     INT = 267,
     RESERVED = 268,
     RETURN = 269,
     WHILE = 270,
     DO = 271,
     CONTINUE = 272,
     BREAK = 273,
     GOTO = 274,
     LVAL = 275,
     SETMOD = 276,
     SETDIV = 277,
     SETMUL = 278,
     SETSUB = 279,
     SETADD = 280,
     SETRSH = 281,
     SETLSH = 282,
     SETAND = 283,
     SETXOR = 284,
     SETOR = 285,
     SET = 286,
     OR = 287,
     AND = 288,
     BITOR = 289,
     BITXOR = 290,
     BITAND = 291,
     NE = 292,
     EQ = 293,
     LE = 294,
     LT = 295,
     GE = 296,
     GT = 297,
     RSH = 298,
     LSH = 299,
     SUB = 300,
     ADD = 301,
     MOD = 302,
     DIV = 303,
     MUL = 304,
     COM = 305,
     NOT = 306,
     UNARY = 307
   };
#endif
/* Tokens.  */
#define ID 258
#define CON 259
#define STR 260
#define CHAR 261
#define ELSE 262
#define FLOAT 263
#define DOUBLE 264
#define FOR 265
#define IF 266
#define INT 267
#define RESERVED 268
#define RETURN 269
#define WHILE 270
#define DO 271
#define CONTINUE 272
#define BREAK 273
#define GOTO 274
#define LVAL 275
#define SETMOD 276
#define SETDIV 277
#define SETMUL 278
#define SETSUB 279
#define SETADD 280
#define SETRSH 281
#define SETLSH 282
#define SETAND 283
#define SETXOR 284
#define SETOR 285
#define SET 286
#define OR 287
#define AND 288
#define BITOR 289
#define BITXOR 290
#define BITAND 291
#define NE 292
#define EQ 293
#define LE 294
#define LT 295
#define GE 296
#define GT 297
#define RSH 298
#define LSH 299
#define SUB 300
#define ADD 301
#define MOD 302
#define DIV 303
#define MUL 304
#define COM 305
#define NOT 306
#define UNARY 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "cgram.y"
{
   int inttype;
   char *str_ptr;
   struct sem_rec *rec_ptr;
   struct id_entry *id_ptr;
}
/* Line 1529 of yacc.c.  */
#line 160 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

