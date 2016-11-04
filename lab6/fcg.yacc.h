#define ID 257
#define INTVAL 258
#define STRVAL 259
#define CHARVAL 260
#define DBLVAL 261
#define FLTVAL 262
#define EQ 263
#define NE 264
#define GE 265
#define LE 266
#define GT 267
#define LT 268
#define ADD 269
#define SUB 270
#define MUL 271
#define DIV 272
#define MOD 273
#define BITOR 274
#define BITAND 275
#define BITXOR 276
#define LSH 277
#define RSH 278
#define SET 279
#define RETURN 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define VOID 284
#define CHAR 285
#define SHORT 286
#define INT 287
#define LONG 288
#define FLOAT 289
#define DOUBLE 290
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char* id;
    int intval;
    double dblval;
    float fltval;
    char charval;
    char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
