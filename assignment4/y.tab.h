/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RELOP = 258,                   /* RELOP  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    RETURN = 261,                  /* RETURN  */
    LTHIRD = 262,                  /* LTHIRD  */
    RTHIRD = 263,                  /* RTHIRD  */
    INCOP = 264,                   /* INCOP  */
    DECOP = 265,                   /* DECOP  */
    LPAREN = 266,                  /* LPAREN  */
    RPAREN = 267,                  /* RPAREN  */
    ASSIGNOP = 268,                /* ASSIGNOP  */
    NOT = 269,                     /* NOT  */
    SEMICOLON = 270,               /* SEMICOLON  */
    LCURL = 271,                   /* LCURL  */
    RCURL = 272,                   /* RCURL  */
    COMMA = 273,                   /* COMMA  */
    ADDOP = 274,                   /* ADDOP  */
    MULOP = 275,                   /* MULOP  */
    CONST_INT = 276,               /* CONST_INT  */
    CONST_FLOAT = 277,             /* CONST_FLOAT  */
    LOGICOP = 278,                 /* LOGICOP  */
    ID = 279,                      /* ID  */
    FOR = 280,                     /* FOR  */
    WHILE = 281,                   /* WHILE  */
    INT = 282,                     /* INT  */
    FLOAT = 283,                   /* FLOAT  */
    VOID = 284,                    /* VOID  */
    PRINTLN = 285,                 /* PRINTLN  */
    CHAR = 286,                    /* CHAR  */
    CONST_CHAR = 287,              /* CONST_CHAR  */
    DO = 288,                      /* DO  */
    BITOP = 289,                   /* BITOP  */
    LOW_PREC = 290                 /* LOW_PREC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RELOP 258
#define IF 259
#define ELSE 260
#define RETURN 261
#define LTHIRD 262
#define RTHIRD 263
#define INCOP 264
#define DECOP 265
#define LPAREN 266
#define RPAREN 267
#define ASSIGNOP 268
#define NOT 269
#define SEMICOLON 270
#define LCURL 271
#define RCURL 272
#define COMMA 273
#define ADDOP 274
#define MULOP 275
#define CONST_INT 276
#define CONST_FLOAT 277
#define LOGICOP 278
#define ID 279
#define FOR 280
#define WHILE 281
#define INT 282
#define FLOAT 283
#define VOID 284
#define PRINTLN 285
#define CHAR 286
#define CONST_CHAR 287
#define DO 288
#define BITOP 289
#define LOW_PREC 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "2005053.y"

    SymbolInfo *symbol;

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
