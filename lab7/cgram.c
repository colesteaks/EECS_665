/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "cgram.y"

  /* grammar for subset of C. The grammar does not recognize all C syntax:
     For example:
     1. Character literals
     2. Structres
     3. Double constants
     4. Nested paraenthesis of the form "if((x == 1))"
     5. etc.
  */
# include <stdio.h>
# include <stdlib.h>
# include "cc.h"
# include "scan.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "cgram.y"
{
   int inttype;
   char *str_ptr;
   struct sem_rec *rec_ptr;
   struct id_entry *id_ptr;
}
/* Line 193 of yacc.c.  */
#line 225 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    14,    15,    19,
      22,    26,    28,    32,    37,    39,    41,    43,    45,    49,
      54,    57,    59,    62,    66,    69,    74,    76,    81,    82,
      85,    88,    92,    95,    99,   100,   101,   102,   103,   106,
     114,   126,   137,   149,   166,   169,   172,   176,   179,   183,
     185,   187,   188,   190,   194,   198,   202,   206,   210,   214,
     219,   224,   227,   229,   231,   235,   236,   238,   242,   246,
     250,   254,   258,   262,   266,   270,   274,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   322,   325,
     328,   331,   333,   337,   342,   346,   348,   350,   352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    -1,    64,    65,    -1,    67,
      53,    -1,    70,    -1,    -1,    66,    67,    53,    -1,    69,
      68,    -1,    67,    54,    68,    -1,     3,    -1,     3,    55,
      56,    -1,     3,    55,     4,    56,    -1,     6,    -1,     8,
      -1,     9,    -1,    12,    -1,    71,    77,    57,    -1,    72,
      73,    58,    66,    -1,    69,     3,    -1,     3,    -1,    59,
      60,    -1,    59,    74,    60,    -1,    69,    68,    -1,    74,
      54,    69,    68,    -1,    58,    -1,    75,    66,    77,    57,
      -1,    -1,    77,    78,    -1,    83,    84,    -1,    83,    79,
      84,    -1,     3,    61,    -1,    79,     3,    61,    -1,    -1,
      -1,    -1,    -1,    89,    53,    -1,    11,    59,    86,    60,
      81,    78,    81,    -1,    11,    59,    86,    60,    81,    78,
       7,    82,    81,    78,    81,    -1,    15,    59,    81,    86,
      60,    81,    80,    78,    82,    81,    -1,    16,    81,    80,
      78,    15,    59,    81,    86,    60,    53,    81,    -1,    10,
      59,    88,    53,    81,    85,    53,    81,    88,    82,    60,
      81,    80,    78,    82,    81,    -1,    17,    53,    -1,    18,
      53,    -1,    19,     3,    53,    -1,    14,    53,    -1,    14,
      89,    53,    -1,    76,    -1,    53,    -1,    -1,    86,    -1,
      89,    38,    89,    -1,    89,    37,    89,    -1,    89,    39,
      89,    -1,    89,    41,    89,    -1,    89,    40,    89,    -1,
      89,    42,    89,    -1,    86,    33,    81,    86,    -1,    86,
      32,    81,    86,    -1,    51,    86,    -1,    89,    -1,    89,
      -1,    87,    54,    89,    -1,    -1,    89,    -1,    90,    31,
      89,    -1,    90,    30,    89,    -1,    90,    29,    89,    -1,
      90,    28,    89,    -1,    90,    27,    89,    -1,    90,    26,
      89,    -1,    90,    25,    89,    -1,    90,    24,    89,    -1,
      90,    23,    89,    -1,    90,    22,    89,    -1,    90,    21,
      89,    -1,    89,    34,    89,    -1,    89,    35,    89,    -1,
      89,    36,    89,    -1,    89,    44,    89,    -1,    89,    43,
      89,    -1,    89,    46,    89,    -1,    89,    45,    89,    -1,
      89,    49,    89,    -1,    89,    48,    89,    -1,    89,    47,
      89,    -1,    36,    90,    -1,    45,    89,    -1,    50,    89,
      -1,    90,    -1,     3,    59,    60,    -1,     3,    59,    87,
      60,    -1,    59,    89,    60,    -1,     4,    -1,     5,    -1,
       3,    -1,     3,    55,    89,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    52,    53,    56,    57,    60,
      61,    64,    65,    66,    69,    70,    71,    72,    75,    78,
      81,    82,    85,    86,    89,    90,    93,    95,    98,    99,
     102,   103,   106,   107,   110,   113,   116,   119,   122,   124,
     126,   128,   130,   132,   134,   136,   138,   140,   142,   144,
     146,   150,   151,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   170,   171,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   197,
     198,   199,   200,   201,   202,   203,   204,   207,   208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CON", "STR", "CHAR", "ELSE",
  "FLOAT", "DOUBLE", "FOR", "IF", "INT", "RESERVED", "RETURN", "WHILE",
  "DO", "CONTINUE", "BREAK", "GOTO", "LVAL", "SETMOD", "SETDIV", "SETMUL",
  "SETSUB", "SETADD", "SETRSH", "SETLSH", "SETAND", "SETXOR", "SETOR",
  "SET", "OR", "AND", "BITOR", "BITXOR", "BITAND", "NE", "EQ", "LE", "LT",
  "GE", "GT", "RSH", "LSH", "SUB", "ADD", "MOD", "DIV", "MUL", "COM",
  "NOT", "UNARY", "';'", "','", "'['", "']'", "'}'", "'{'", "'('", "')'",
  "':'", "$accept", "prog", "externs", "extern", "dcls", "dcl", "dclr",
  "type", "func", "fhead", "fname", "fargs", "args", "bhead", "block",
  "stmts", "lblstmt", "labels", "s", "m", "n", "b", "stmt", "cexpro",
  "cexpr", "exprs", "expro", "expr", "lval", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    59,    44,    91,    93,   125,   123,    40,
      41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     0,     3,     2,
       3,     1,     3,     4,     1,     1,     1,     1,     3,     4,
       2,     1,     2,     3,     2,     4,     1,     4,     0,     2,
       2,     3,     2,     3,     0,     0,     0,     0,     2,     7,
      11,    10,    11,    16,     2,     2,     3,     2,     3,     1,
       1,     0,     1,     3,     3,     3,     3,     3,     3,     4,
       4,     2,     1,     1,     3,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     3,     4,     3,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    21,    14,    15,    16,    17,     4,
       0,     0,     6,    28,     0,     5,     0,    11,     9,    37,
       0,     0,    11,    10,     0,    18,    29,     0,    22,     0,
       0,     7,     0,    12,    97,    95,    96,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,    50,    26,
       0,     7,    49,     0,    30,     0,    91,    24,     0,    23,
      19,    13,     0,     0,    32,    65,     0,    97,    47,     0,
      35,    34,    44,    45,     0,    97,    88,    89,    90,     0,
      28,    97,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,    63,     0,    66,     0,     0,    62,    48,     0,    37,
      46,    94,    37,    33,    78,    79,    80,    82,    81,    84,
      83,    87,    86,    85,    77,    76,    75,    74,    73,    72,
      71,    70,    69,    68,    67,    25,     8,    98,     0,    93,
      35,    61,    35,    35,    35,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    64,    51,     0,     0,    37,    54,
      53,    55,    57,    56,    58,    35,     0,     0,    52,    60,
      59,    35,    34,    35,    35,    36,    39,    37,     0,    65,
      35,    36,     0,    36,    37,    35,     0,     0,    35,    41,
      35,    35,    40,    42,    34,    37,    36,    35,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    60,   106,    18,   107,    12,    13,
      14,    21,    30,    51,    52,    19,    26,    53,   119,    71,
     190,    27,    54,   177,   115,   110,   112,   116,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -179
static const yytype_int16 yypact[] =
{
    -179,     3,   138,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
      41,     8,  -179,  -179,   -43,  -179,    18,   -11,  -179,   -24,
      33,    -6,     0,  -179,    -2,  -179,  -179,   160,  -179,    18,
     -14,  -179,    30,  -179,   -37,  -179,  -179,    43,    45,   180,
      49,  -179,    47,    57,   121,   142,   204,   204,  -179,  -179,
     204,  -179,  -179,   184,  -179,   246,   342,  -179,   215,  -179,
     215,  -179,   204,    46,  -179,   204,   122,    29,  -179,   262,
    -179,  -179,  -179,  -179,    95,    98,  -179,  -179,  -179,   212,
     215,    28,  -179,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,  -179,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,    18,    69,    18,   230,  -179,
      -7,   298,   102,   298,   122,   -28,   282,  -179,   122,  -179,
    -179,  -179,    99,  -179,   313,    71,   331,    90,    90,    50,
      50,  -179,  -179,  -179,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,  -179,  -179,  -179,   204,  -179,
    -179,  -179,  -179,  -179,  -179,   204,   204,   204,   204,   204,
     204,   -26,   146,  -179,   298,   122,   122,   122,  -179,   298,
     298,   298,   298,   298,   298,  -179,   109,   116,   119,   147,
    -179,   175,  -179,  -179,  -179,  -179,  -179,  -179,   122,   204,
    -179,  -179,   -23,  -179,  -179,  -179,   133,   130,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,   140,   190,   -15,    23,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,   113,  -102,  -179,  -174,   -41,
    -178,  -179,   144,  -179,   -87,  -179,    15,   -27,   161
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      55,    23,    32,     3,   152,   153,   152,   153,   187,   152,
     153,    17,    69,   195,    57,   197,    20,   162,    62,    77,
      78,    22,    63,    79,    64,    11,    55,   151,   207,   118,
     205,   161,   154,    25,   175,   108,   111,   196,   113,     5,
      58,     6,     7,    29,    24,     8,    59,   148,   -20,    67,
      35,    36,    31,   149,    33,    24,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   181,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   178,   179,
     180,   105,    45,    62,    62,   191,    61,    63,    63,   123,
     145,    46,   198,    28,    15,    16,    47,    90,    91,    92,
      72,   192,    65,   206,    66,    50,   109,    85,    70,   165,
      73,   166,   167,   168,    86,    87,    88,    89,    90,    91,
      92,   164,   146,    16,    74,    67,    35,    36,   169,   170,
     171,   172,   173,   174,   182,    88,    89,    90,    91,    92,
     186,     4,   188,   189,     5,    75,     6,     7,   120,   194,
       8,   152,   153,    62,   199,   150,   163,   202,    45,   203,
     204,   176,   113,    34,    35,    36,   208,    46,   183,   184,
      37,    38,    47,   114,    39,    40,    41,    42,    43,    44,
     153,    50,   185,    67,    35,    36,   200,    81,    35,    36,
     201,    80,    10,   122,    37,    38,    45,    82,    39,    40,
      41,    42,    43,    44,   193,    46,    76,    67,    35,    36,
      47,     0,     0,    48,     0,     0,    45,     0,    49,    50,
      45,     5,     0,     6,     7,    46,     0,     8,     0,    46,
      47,     0,     0,    68,    47,     0,     0,    48,     0,    50,
      45,     0,    49,    50,     0,     0,    83,    84,    85,    46,
       0,     0,     0,     0,    47,    86,    87,    88,    89,    90,
      91,    92,     0,    50,    83,    84,    85,     0,     0,     0,
       0,     0,   121,    86,    87,    88,    89,    90,    91,    92,
      83,    84,    85,     0,     0,     0,   147,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    83,    84,    85,    93,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,   117,    83,    84,    85,   155,
     156,   157,   158,   159,   160,    86,    87,    88,    89,    90,
      91,    92,    83,    84,    85,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    86,    87,    88,    89,    90,    91,
      92
};

static const yytype_int16 yycheck[] =
{
      27,    16,     4,     0,    32,    33,    32,    33,   182,    32,
      33,     3,    39,   191,    29,   193,    59,   119,    55,    46,
      47,     3,    59,    50,    61,     2,    53,   114,   206,    70,
     204,   118,    60,    57,    60,    62,    63,    60,    65,     6,
      54,     8,     9,    20,    55,    12,    60,    54,    59,     3,
       4,     5,    58,    60,    56,    55,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   168,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   165,   166,
     167,    58,    36,    55,    55,   187,    56,    59,    59,    61,
     105,    45,   194,    60,    53,    54,    50,    47,    48,    49,
      53,   188,    59,   205,    59,    59,    60,    36,    59,   150,
      53,   152,   153,   154,    43,    44,    45,    46,    47,    48,
      49,   148,    53,    54,     3,     3,     4,     5,   155,   156,
     157,   158,   159,   160,   175,    45,    46,    47,    48,    49,
     181,     3,   183,   184,     6,     3,     8,     9,    53,   190,
      12,    32,    33,    55,   195,    53,    57,   198,    36,   200,
     201,    15,   189,     3,     4,     5,   207,    45,    59,    53,
      10,    11,    50,    51,    14,    15,    16,    17,    18,    19,
      33,    59,     7,     3,     4,     5,    53,     3,     4,     5,
      60,    51,     2,    80,    10,    11,    36,    53,    14,    15,
      16,    17,    18,    19,   189,    45,    45,     3,     4,     5,
      50,    -1,    -1,    53,    -1,    -1,    36,    -1,    58,    59,
      36,     6,    -1,     8,     9,    45,    -1,    12,    -1,    45,
      50,    -1,    -1,    53,    50,    -1,    -1,    53,    -1,    59,
      36,    -1,    58,    59,    -1,    -1,    34,    35,    36,    45,
      -1,    -1,    -1,    -1,    50,    43,    44,    45,    46,    47,
      48,    49,    -1,    59,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    60,    43,    44,    45,    46,    47,    48,    49,
      34,    35,    36,    -1,    -1,    -1,    56,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    34,    35,    36,    53,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    43,    44,    45,    46,    47,    48,
      49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,     3,     6,     8,     9,    12,    65,
      67,    69,    70,    71,    72,    53,    54,     3,    68,    77,
      59,    73,     3,    68,    55,    57,    78,    83,    60,    69,
      74,    58,     4,    56,     3,     4,     5,    10,    11,    14,
      15,    16,    17,    18,    19,    36,    45,    50,    53,    58,
      59,    75,    76,    79,    84,    89,    90,    68,    54,    60,
      66,    56,    55,    59,    61,    59,    59,     3,    53,    89,
      59,    81,    53,    53,     3,     3,    90,    89,    89,    89,
      66,     3,    84,    34,    35,    36,    43,    44,    45,    46,
      47,    48,    49,    53,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    69,    67,    69,    89,    60,
      87,    89,    88,    89,    51,    86,    89,    53,    81,    80,
      53,    60,    77,    61,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    68,    53,    56,    54,    60,
      53,    86,    32,    33,    60,    37,    38,    39,    40,    41,
      42,    86,    78,    57,    89,    81,    81,    81,    81,    89,
      89,    89,    89,    89,    89,    60,    15,    85,    86,    86,
      86,    78,    81,    59,    53,     7,    81,    80,    81,    81,
      82,    78,    86,    88,    81,    82,    60,    82,    78,    81,
      53,    60,    81,    81,    81,    80,    78,    82,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 45 "cgram.y"
    {}
    break;

  case 3:
#line 48 "cgram.y"
    {}
    break;

  case 4:
#line 49 "cgram.y"
    {}
    break;

  case 5:
#line 52 "cgram.y"
    {}
    break;

  case 6:
#line 53 "cgram.y"
    {}
    break;

  case 7:
#line 56 "cgram.y"
    {}
    break;

  case 8:
#line 57 "cgram.y"
    {}
    break;

  case 9:
#line 60 "cgram.y"
    { (yyval.id_ptr) = dcl((yyvsp[(2) - (2)].id_ptr), (yyvsp[(1) - (2)].inttype), 0); }
    break;

  case 10:
#line 61 "cgram.y"
    { (yyval.id_ptr) = dcl((yyvsp[(3) - (3)].id_ptr), (yyvsp[(1) - (3)].id_ptr)->i_type&~T_ARRAY, 0); }
    break;

  case 11:
#line 64 "cgram.y"
    { (yyval.id_ptr) = dclr((yyvsp[(1) - (1)].str_ptr), 0, 1); }
    break;

  case 12:
#line 65 "cgram.y"
    { (yyval.id_ptr) = dclr((yyvsp[(1) - (3)].str_ptr), T_ARRAY, 1); }
    break;

  case 13:
#line 66 "cgram.y"
    { (yyval.id_ptr) = dclr((yyvsp[(1) - (4)].str_ptr), T_ARRAY, atoi((yyvsp[(3) - (4)].str_ptr))); }
    break;

  case 14:
#line 69 "cgram.y"
    { (yyval.inttype) = T_INT; }
    break;

  case 15:
#line 70 "cgram.y"
    { (yyval.inttype) = T_DOUBLE; }
    break;

  case 16:
#line 71 "cgram.y"
    { (yyval.inttype) = T_DOUBLE; }
    break;

  case 17:
#line 72 "cgram.y"
    { (yyval.inttype) = T_INT; }
    break;

  case 18:
#line 75 "cgram.y"
    { ftail(); }
    break;

  case 19:
#line 78 "cgram.y"
    { fhead((yyvsp[(1) - (4)].id_ptr)); }
    break;

  case 20:
#line 81 "cgram.y"
    { (yyval.id_ptr) = fname((yyvsp[(1) - (2)].inttype), (yyvsp[(2) - (2)].str_ptr)); }
    break;

  case 21:
#line 82 "cgram.y"
    { (yyval.id_ptr) = fname(T_INT, (yyvsp[(1) - (1)].str_ptr)); }
    break;

  case 22:
#line 85 "cgram.y"
    { enterblock(); }
    break;

  case 23:
#line 86 "cgram.y"
    { enterblock(); }
    break;

  case 24:
#line 89 "cgram.y"
    { dcl((yyvsp[(2) - (2)].id_ptr), (yyvsp[(1) - (2)].inttype), PARAM); }
    break;

  case 25:
#line 90 "cgram.y"
    { dcl((yyvsp[(4) - (4)].id_ptr), (yyvsp[(3) - (4)].inttype), PARAM); }
    break;

  case 26:
#line 93 "cgram.y"
    { blockdcl(); }
    break;

  case 27:
#line 95 "cgram.y"
    { btail(); }
    break;

  case 28:
#line 98 "cgram.y"
    { }
    break;

  case 29:
#line 99 "cgram.y"
    { }
    break;

  case 30:
#line 102 "cgram.y"
    { }
    break;

  case 31:
#line 103 "cgram.y"
    { }
    break;

  case 32:
#line 106 "cgram.y"
    { labeldcl((yyvsp[(1) - (2)].str_ptr)); }
    break;

  case 33:
#line 107 "cgram.y"
    { labeldcl((yyvsp[(2) - (3)].str_ptr)); }
    break;

  case 34:
#line 110 "cgram.y"
    { startloopscope(); }
    break;

  case 35:
#line 113 "cgram.y"
    { (yyval.inttype) = m(); }
    break;

  case 36:
#line 116 "cgram.y"
    { (yyval.rec_ptr) = n(); }
    break;

  case 37:
#line 119 "cgram.y"
    { bgnstmt(); }
    break;

  case 38:
#line 123 "cgram.y"
    { }
    break;

  case 39:
#line 125 "cgram.y"
    { doif((yyvsp[(3) - (7)].rec_ptr), (yyvsp[(5) - (7)].inttype), (yyvsp[(7) - (7)].inttype)); }
    break;

  case 40:
#line 127 "cgram.y"
    { doifelse((yyvsp[(3) - (11)].rec_ptr), (yyvsp[(5) - (11)].inttype), (yyvsp[(8) - (11)].rec_ptr), (yyvsp[(9) - (11)].inttype), (yyvsp[(11) - (11)].inttype)); }
    break;

  case 41:
#line 129 "cgram.y"
    { dowhile((yyvsp[(3) - (10)].inttype), (yyvsp[(4) - (10)].rec_ptr), (yyvsp[(6) - (10)].inttype), (yyvsp[(9) - (10)].rec_ptr), (yyvsp[(10) - (10)].inttype)); }
    break;

  case 42:
#line 131 "cgram.y"
    { dodo((yyvsp[(2) - (11)].inttype), (yyvsp[(7) - (11)].inttype), (yyvsp[(8) - (11)].rec_ptr), (yyvsp[(11) - (11)].inttype)); }
    break;

  case 43:
#line 133 "cgram.y"
    { dofor((yyvsp[(5) - (16)].inttype), (yyvsp[(6) - (16)].rec_ptr), (yyvsp[(8) - (16)].inttype), (yyvsp[(10) - (16)].rec_ptr), (yyvsp[(12) - (16)].inttype), (yyvsp[(15) - (16)].rec_ptr), (yyvsp[(16) - (16)].inttype)); }
    break;

  case 44:
#line 135 "cgram.y"
    { docontinue(); }
    break;

  case 45:
#line 137 "cgram.y"
    { dobreak(); }
    break;

  case 46:
#line 139 "cgram.y"
    { dogoto((yyvsp[(2) - (3)].str_ptr)); }
    break;

  case 47:
#line 141 "cgram.y"
    { doret((struct sem_rec *) NULL); }
    break;

  case 48:
#line 143 "cgram.y"
    { doret((yyvsp[(2) - (3)].rec_ptr)); }
    break;

  case 49:
#line 145 "cgram.y"
    { }
    break;

  case 50:
#line 147 "cgram.y"
    { }
    break;

  case 51:
#line 150 "cgram.y"
    { (yyval.rec_ptr) = node(0, 0, n(), 0); }
    break;

  case 52:
#line 151 "cgram.y"
    {}
    break;

  case 53:
#line 154 "cgram.y"
    { (yyval.rec_ptr) = rel("==", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 54:
#line 155 "cgram.y"
    { (yyval.rec_ptr) = rel("!=", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 55:
#line 156 "cgram.y"
    { (yyval.rec_ptr) = rel("<=", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 56:
#line 157 "cgram.y"
    { (yyval.rec_ptr) = rel(">=", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 57:
#line 158 "cgram.y"
    { (yyval.rec_ptr) = rel("<",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 58:
#line 159 "cgram.y"
    { (yyval.rec_ptr) = rel(">",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 59:
#line 160 "cgram.y"
    { (yyval.rec_ptr) = ccand((yyvsp[(1) - (4)].rec_ptr), (yyvsp[(3) - (4)].inttype), (yyvsp[(4) - (4)].rec_ptr)); }
    break;

  case 60:
#line 161 "cgram.y"
    { (yyval.rec_ptr) = ccor((yyvsp[(1) - (4)].rec_ptr), (yyvsp[(3) - (4)].inttype), (yyvsp[(4) - (4)].rec_ptr)); }
    break;

  case 61:
#line 162 "cgram.y"
    { (yyval.rec_ptr) = ccnot((yyvsp[(2) - (2)].rec_ptr)); }
    break;

  case 62:
#line 163 "cgram.y"
    { (yyval.rec_ptr) = ccexpr((yyvsp[(1) - (1)].rec_ptr)); }
    break;

  case 63:
#line 166 "cgram.y"
    { (yyval.rec_ptr) = (yyvsp[(1) - (1)].rec_ptr); }
    break;

  case 64:
#line 167 "cgram.y"
    { (yyval.rec_ptr) = exprs((yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 65:
#line 170 "cgram.y"
    {}
    break;

  case 66:
#line 171 "cgram.y"
    {}
    break;

  case 67:
#line 174 "cgram.y"
    { (yyval.rec_ptr) = set("",   (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 68:
#line 175 "cgram.y"
    { (yyval.rec_ptr) = set("|",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 69:
#line 176 "cgram.y"
    { (yyval.rec_ptr) = set("^",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 70:
#line 177 "cgram.y"
    { (yyval.rec_ptr) = set("&",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 71:
#line 178 "cgram.y"
    { (yyval.rec_ptr) = set("<<", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 72:
#line 179 "cgram.y"
    { (yyval.rec_ptr) = set(">>", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 73:
#line 180 "cgram.y"
    { (yyval.rec_ptr) = set("+",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 74:
#line 181 "cgram.y"
    { (yyval.rec_ptr) = set("-",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 75:
#line 182 "cgram.y"
    { (yyval.rec_ptr) = set("*",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 76:
#line 183 "cgram.y"
    { (yyval.rec_ptr) = set("/",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 77:
#line 184 "cgram.y"
    { (yyval.rec_ptr) = set("%",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 78:
#line 185 "cgram.y"
    { (yyval.rec_ptr) = opb("|",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 79:
#line 186 "cgram.y"
    { (yyval.rec_ptr) = opb("^",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 80:
#line 187 "cgram.y"
    { (yyval.rec_ptr) = opb("&",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 81:
#line 188 "cgram.y"
    { (yyval.rec_ptr) = opb("<<", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 82:
#line 189 "cgram.y"
    { (yyval.rec_ptr) = opb(">>", (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 83:
#line 190 "cgram.y"
    { (yyval.rec_ptr) = op2("+",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 84:
#line 191 "cgram.y"
    { (yyval.rec_ptr) = op2("-",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 85:
#line 192 "cgram.y"
    { (yyval.rec_ptr) = op2("*",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 86:
#line 193 "cgram.y"
    { (yyval.rec_ptr) = op2("/",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 87:
#line 194 "cgram.y"
    { (yyval.rec_ptr) = op2("%",  (yyvsp[(1) - (3)].rec_ptr), (yyvsp[(3) - (3)].rec_ptr)); }
    break;

  case 88:
#line 196 "cgram.y"
    { (yyval.rec_ptr) = (yyvsp[(2) - (2)].rec_ptr); }
    break;

  case 89:
#line 197 "cgram.y"
    { (yyval.rec_ptr) = op1("-",      (yyvsp[(2) - (2)].rec_ptr)); }
    break;

  case 90:
#line 198 "cgram.y"
    { (yyval.rec_ptr) = op1("~",      (yyvsp[(2) - (2)].rec_ptr)); }
    break;

  case 91:
#line 199 "cgram.y"
    { (yyval.rec_ptr) = op1("@",      (yyvsp[(1) - (1)].rec_ptr)); }
    break;

  case 92:
#line 200 "cgram.y"
    { (yyval.rec_ptr) = call((yyvsp[(1) - (3)].str_ptr), (struct sem_rec *) NULL); }
    break;

  case 93:
#line 201 "cgram.y"
    { (yyval.rec_ptr) = call((yyvsp[(1) - (4)].str_ptr), (yyvsp[(3) - (4)].rec_ptr)); }
    break;

  case 94:
#line 202 "cgram.y"
    { (yyval.rec_ptr) = (yyvsp[(2) - (3)].rec_ptr); }
    break;

  case 95:
#line 203 "cgram.y"
    { (yyval.rec_ptr) = con((yyvsp[(1) - (1)].str_ptr)); }
    break;

  case 96:
#line 204 "cgram.y"
    { (yyval.rec_ptr) = string((yyvsp[(1) - (1)].str_ptr)); }
    break;

  case 97:
#line 207 "cgram.y"
    { (yyval.rec_ptr) = id((yyvsp[(1) - (1)].str_ptr)); }
    break;

  case 98:
#line 208 "cgram.y"
    { (yyval.rec_ptr) = index1(id((yyvsp[(1) - (4)].str_ptr)), (yyvsp[(3) - (4)].rec_ptr)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2133 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 210 "cgram.y"

# include <stdio.h>

extern int lineno;

/* 
 * main - read a program, and parse it
 */
main(int argc, char *argv)
{

   enterblock();
   initlex();
   enterblock();
   if (yyparse())
      yyerror("syntax error");
   leaveblock();
   leaveblock();
   exit(0);
}

/*
 * yyerror - issue error message
 */
yyerror(char msg[])
{
   fprintf(stderr, " %s.  Line %d\n", msg, lineno);
}

