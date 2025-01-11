#ifndef _yy_defines_h_
#define _yy_defines_h_

#define RELOP 257
#define IF 258
#define ELSE 259
#define RETURN 260
#define LTHIRD 261
#define RTHIRD 262
#define INCOP 263
#define DECOP 264
#define LPAREN 265
#define RPAREN 266
#define ASSIGNOP 267
#define NOT 268
#define SEMICOLON 269
#define LCURL 270
#define RCURL 271
#define COMMA 272
#define ADDOP 273
#define MULOP 274
#define CONST_INT 275
#define CONST_FLOAT 276
#define LOGICOP 277
#define ID 278
#define FOR 279
#define WHILE 280
#define INT 281
#define FLOAT 282
#define VOID 283
#define PRINTLN 284
#define CHAR 285
#define CONST_CHAR 286
#define DO 287
#define BITOP 288
#define LOW_PREC 289
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE
{
    SymbolInfo *symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
