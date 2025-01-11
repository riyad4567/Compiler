/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "2005053.y"

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include "2005053-SymbolTable.h"
#include "2005053-ParseTree.cpp"
#include "2005053-Icg.cpp"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
FILE *logout;
FILE *errorout;
FILE *parseout;
FILE *tokenout;
FILE *codeout;
FILE *codeasm;
SymbolTable symtable(11);
SymbolInfo *temp;
SymbolInfo *root;
ParseTree obj;
vector<SymbolInfo*>parameterList;
vector<SymbolInfo*>varDeclarationList;
vector<SymbolInfo*> globalVar;
string varType;
int errors=0;
int store=0;

bool errorflag=false;
string retType;

void yyerror(char *s)
{   
	
	//write your code
}



#line 117 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 244 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RELOP = 3,                      /* RELOP  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_LTHIRD = 7,                     /* LTHIRD  */
  YYSYMBOL_RTHIRD = 8,                     /* RTHIRD  */
  YYSYMBOL_INCOP = 9,                      /* INCOP  */
  YYSYMBOL_DECOP = 10,                     /* DECOP  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_ASSIGNOP = 13,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_LCURL = 16,                     /* LCURL  */
  YYSYMBOL_RCURL = 17,                     /* RCURL  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_ADDOP = 19,                     /* ADDOP  */
  YYSYMBOL_MULOP = 20,                     /* MULOP  */
  YYSYMBOL_CONST_INT = 21,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 22,               /* CONST_FLOAT  */
  YYSYMBOL_LOGICOP = 23,                   /* LOGICOP  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_VOID = 29,                      /* VOID  */
  YYSYMBOL_PRINTLN = 30,                   /* PRINTLN  */
  YYSYMBOL_CHAR = 31,                      /* CHAR  */
  YYSYMBOL_CONST_CHAR = 32,                /* CONST_CHAR  */
  YYSYMBOL_DO = 33,                        /* DO  */
  YYSYMBOL_BITOP = 34,                     /* BITOP  */
  YYSYMBOL_LOW_PREC = 35,                  /* LOW_PREC  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_start = 37,                     /* start  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_unit = 39,                      /* unit  */
  YYSYMBOL_func_declaration = 40,          /* func_declaration  */
  YYSYMBOL_func_definition = 41,           /* func_definition  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_parameter_list = 44,            /* parameter_list  */
  YYSYMBOL_compound_statement = 45,        /* compound_statement  */
  YYSYMBOL_var_declaration = 46,           /* var_declaration  */
  YYSYMBOL_type_specifier = 47,            /* type_specifier  */
  YYSYMBOL_declaration_list = 48,          /* declaration_list  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_expression_statement = 51,      /* expression_statement  */
  YYSYMBOL_variable = 52,                  /* variable  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_logic_expression = 54,          /* logic_expression  */
  YYSYMBOL_rel_expression = 55,            /* rel_expression  */
  YYSYMBOL_simple_expression = 56,         /* simple_expression  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_unary_expression = 58,          /* unary_expression  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_arguments = 61                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    84,    96,   108,   118,   128,   140,   158,
     176,   176,   242,   242,   268,   281,   291,   305,   320,   331,
     344,   370,   383,   396,   411,   437,   466,   493,   515,   525,
     537,   547,   557,   567,   577,   587,   597,   607,   619,   632,
     642,   654,   679,   701,   712,   725,   737,   750,   761,   774,
     785,   810,   821,   846,   864,   883,   904,   915,   964,   975,
     986,   997,  1008,  1021,  1031,  1034,  1045
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RELOP", "IF", "ELSE",
  "RETURN", "LTHIRD", "RTHIRD", "INCOP", "DECOP", "LPAREN", "RPAREN",
  "ASSIGNOP", "NOT", "SEMICOLON", "LCURL", "RCURL", "COMMA", "ADDOP",
  "MULOP", "CONST_INT", "CONST_FLOAT", "LOGICOP", "ID", "FOR", "WHILE",
  "INT", "FLOAT", "VOID", "PRINTLN", "CHAR", "CONST_CHAR", "DO", "BITOP",
  "LOW_PREC", "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -74,   -74,   -74,    17,     3,   -74,   -74,   -74,   -74,
      18,   -74,   -74,    38,     0,    19,    -3,   -74,    23,    53,
      50,     2,    44,    66,   -74,   -74,    58,    60,     3,   -74,
      56,    65,   -74,   -74,    58,    59,    70,    74,    22,    22,
      22,   -74,   -74,    22,   -74,   -74,    51,    77,    86,    88,
     -74,   -74,    76,    92,   -74,   -74,    47,    87,   -74,    78,
       9,    84,   -74,   -74,   -74,   -74,   -74,    22,    90,    98,
      54,   -74,   -74,    22,    22,   139,    22,    91,   105,   -74,
     -74,   -74,   -74,    22,   -74,    22,    22,    22,    22,   112,
     -74,   -74,   118,   -74,   115,   110,   139,   117,   120,   -74,
     -74,   123,    84,   -74,   119,   -74,   -74,    22,    22,   119,
     116,   131,   -74,   125,   -74,   -74,   119,   119,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    26,     0,     0,     0,    20,     0,     0,
      12,     0,    17,    24,    27,     9,     0,    10,     0,    16,
       0,     0,    13,     8,     0,    15,     0,     0,     0,     0,
       0,    39,    19,     0,    59,    60,    41,     0,     0,     0,
      32,    30,     0,     0,    28,    31,    56,     0,    43,    45,
      47,    49,    51,    55,    11,    14,    25,     0,     0,     0,
      56,    54,    53,     0,    64,     0,     0,     0,    26,    18,
      29,    61,    62,     0,    40,     0,     0,     0,     0,     0,
      38,    58,     0,    66,     0,    63,     0,     0,     0,    44,
      46,    48,    50,    52,     0,    42,    57,     0,     0,     0,
       0,    34,    65,     0,    36,    37,     0,     0,    35,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   134,   -74,   -74,   -74,   -74,   -74,    -7,
      16,     6,   -74,   -74,   -50,   -73,   -35,   -38,   -70,    67,
      69,    64,   -33,   -74,   -74,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    26,    21,    50,
      51,    52,    14,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    94,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    69,    96,    80,    93,    70,    10,    71,    70,    20,
      72,    10,    86,    99,    27,    17,     9,    11,    18,    32,
      28,     9,    22,   108,     1,     2,     3,    64,    87,    89,
       1,     2,     3,    39,    35,    92,    40,   112,    97,    70,
      19,    43,    13,    44,    45,    15,    46,    23,    70,    16,
      70,    70,    70,    70,   111,   103,    81,    82,    73,   114,
      83,    24,    74,    81,    82,    25,   118,   119,    29,    37,
     113,    38,    70,    30,    31,    33,    39,    36,    66,    40,
      41,    31,    42,    65,    43,    67,    44,    45,    75,    46,
      47,    48,     1,     2,     3,    49,    37,    76,    38,    77,
      78,    85,    84,    39,    88,    90,    40,    41,    31,    79,
      91,    43,    15,    44,    45,    98,    46,    47,    48,     1,
       2,     3,    49,    37,   104,    38,   105,   106,   107,   109,
      39,   115,   110,    40,    41,    31,   116,   117,    43,    12,
      44,    45,    87,    46,    47,    48,     1,     2,     3,    49,
      39,   102,   100,    40,    41,   101,     0,     0,    43,     0,
      44,    45,     0,    46
};

static const yytype_int8 yycheck[] =
{
      38,    39,    75,    53,    74,    40,     0,    40,    43,    12,
      43,     5,     3,    83,    12,    15,     0,     0,    18,    26,
      18,     5,    16,    96,    27,    28,    29,    34,    19,    67,
      27,    28,    29,    11,    28,    73,    14,   107,    76,    74,
      21,    19,    24,    21,    22,     7,    24,    24,    83,    11,
      85,    86,    87,    88,   104,    88,     9,    10,     7,   109,
      13,     8,    11,     9,    10,    15,   116,   117,    24,     4,
     108,     6,   107,     7,    16,    15,    11,    21,     8,    14,
      15,    16,    17,    24,    19,    11,    21,    22,    11,    24,
      25,    26,    27,    28,    29,    30,     4,    11,     6,    11,
      24,    23,    15,    11,    20,    15,    14,    15,    16,    17,
      12,    19,     7,    21,    22,    24,    24,    25,    26,    27,
      28,    29,    30,     4,    12,     6,     8,    12,    18,    12,
      11,    15,    12,    14,    15,    16,     5,    12,    19,     5,
      21,    22,    19,    24,    25,    26,    27,    28,    29,    30,
      11,    87,    85,    14,    15,    86,    -1,    -1,    19,    -1,
      21,    22,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    29,    37,    38,    39,    40,    41,    46,
      47,     0,    39,    24,    48,     7,    11,    15,    18,    21,
      12,    44,    47,    24,     8,    15,    43,    12,    18,    24,
       7,    16,    45,    15,    42,    47,    21,     4,     6,    11,
      14,    15,    17,    19,    21,    22,    24,    25,    26,    30,
      45,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    45,    24,     8,    11,    53,    53,
      52,    58,    58,     7,    11,    11,    11,    11,    24,    17,
      50,     9,    10,    13,    15,    23,     3,    19,    20,    53,
      15,    12,    53,    54,    60,    61,    51,    53,    24,    54,
      55,    56,    57,    58,    12,     8,    12,    18,    51,    12,
      12,    50,    54,    53,    50,    15,     5,    12,    50,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      42,    41,    43,    41,    44,    44,    44,    44,    45,    45,
      46,    47,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     3,     2,
       3,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     1,     7,     5,     7,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 66 "2005053.y"
        {
		fprintf(logout,"start : program\n");
		fprintf(logout,"Total Lines: %d\n",line_count);
		fprintf(logout,"Total Errors: %d\n",errors);
		(yyval.symbol)=new SymbolInfo();
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("start : program");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		//cout<<"hello"<<endl;
		//cout<<$$->childArr.size()<<endl;
		obj.printParse(parseout,(yyval.symbol));
		root=(yyval.symbol);
		//delete $$;
	}
#line 1385 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 85 "2005053.y"
    {
        fprintf(logout,"program : program unit \n");
        //$1->nameSetter();
        //$$=$1;
		(yyval.symbol)=new SymbolInfo();
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("program : program unit");
		(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
    }
#line 1401 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 97 "2005053.y"
    {
        fprintf(logout,"program : unit\n");
        (yyval.symbol)=new SymbolInfo();
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("program : unit");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
    }
#line 1415 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 109 "2005053.y"
     {
         fprintf(logout,"unit : var_declaration\n");
         (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("unit : var_declaration");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
     }
#line 1429 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 119 "2005053.y"
     {
         fprintf(logout,"unit : func_declaration\n");
         (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("unit : func_declaration");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
     }
#line 1443 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 129 "2005053.y"
     {
         fprintf(logout,"unit : func_definition\n");
         (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("unit : func_definition");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
     }
#line 1457 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 141 "2005053.y"
        {
          fprintf(logout,"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
          (yyval.symbol)=new SymbolInfo(); 
		  obj.currSymbolSetter((yyval.symbol));
		  (yyval.symbol)->exprSetter("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		  (yyval.symbol)->addChild({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		  (yyval.symbol)->startlineSetter((yyvsp[-5].symbol)->startlineGetter());
		  (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		  errorflag=symtable.Insert((yyvsp[-4].symbol)->nameGetter(),"ID");
		  temp=symtable.LookUp((yyvsp[-4].symbol)->nameGetter());
          temp->checkFunctionSetter(true);
          temp->listOfParameter=parameterList;
          temp->retTypeSetter((yyvsp[-5].symbol)->varTypeGetter());
		  (yyvsp[-4].symbol)=temp;
          parameterList.clear();
		 // }
        }
#line 1479 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 159 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		    (yyval.symbol)->addChild({(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-4].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			errorflag=symtable.Insert((yyvsp[-3].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[-3].symbol)->nameGetter());
			temp->checkFunctionSetter(true);
            temp->retTypeSetter((yyvsp[-4].symbol)->varTypeGetter());
			(yyvsp[-3].symbol)=temp;
            fprintf(logout,"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");			

		}
#line 1499 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 176 "2005053.y"
                                                                 {
        symtable.EnterScope();
		for(int i=0;i<parameterList.size();i++)
		{   
			string name=parameterList[i]->nameGetter();
			string s=parameterList[i]->varTypeGetter();
			errorflag=symtable.Insert(name,"ID");
			//if(errorflag)
			//{
				temp=symtable.LookUp(name);
				//temp->setScope(symtable.GetCurrent()->getId());
				temp->varTypeSetter(s);
				parameterList[i]=temp;
			//}
			//else{
				 //errors++;
	            // fprintf(errorout,"Line# %d: Redefinition of parameter '%s'\n",line_count,name.c_str());
			//}
		}	
		}
#line 1524 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 197 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			(yyvsp[-5].symbol)->retTypeSetter((yyvsp[-6].symbol)->varTypeGetter());
			symtable.ExitScope();
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		    
			(yyval.symbol)->startlineSetter((yyvsp[-6].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");			
			errorflag=symtable.Insert((yyvsp[-5].symbol)->nameGetter(),"ID");
			SymbolInfo *tmp=symtable.LookUp((yyvsp[-5].symbol)->nameGetter());
			//$$->setScope(symtable.GetCurrent()->getId());
			// if(errorflag==false)
			// {   
			// 	if(temp->checkFunctionGetter()==false)
			// 	{
			// 		fprintf(errorout,"Line# %d: '%s'redeclared as different kind of symbol\n",store,$2->nameGetter().c_str());
			// 		errors++;
			// 	}
			// 	else if(temp->retTypeGetter()!=$1->varTypeGetter())
			// 	{
			// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,$2->nameGetter().c_str());
			// 		errors++;
			// 	}
				
			// }	
			if(errorflag)
			{   
				tmp->retTypeSetter((yyvsp[-6].symbol)->varTypeGetter());
				tmp->checkFunctionSetter(true);
			}						
			for(int i=0;i<parameterList.size();i++)
		    {   
				//cout<<"1"<<endl;
				tmp->listOfParameter.push_back(parameterList[i]);
		    }	
			tmp->argNumberSetter(parameterList.size());
			tmp->retTypeSetter((yyvsp[-6].symbol)->varTypeGetter());
			parameterList.clear();
			(yyvsp[-5].symbol) = tmp;
			// cout<<$2->listOfParameter.size();
			// symtable.PrintAllScope(logout);
			(yyval.symbol)->addChild({(yyvsp[-6].symbol),(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[0].symbol)});
		}
#line 1574 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 242 "2005053.y"
                                                  {
			symtable.EnterScope();
		}
#line 1582 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 246 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			(yyvsp[-4].symbol)->retTypeSetter((yyvsp[-5].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
			symtable.ExitScope();
		    (yyval.symbol)->exprSetter("func_definition : type_specifier ID LPAREN RPAREN compound_statement"); 
			(yyval.symbol)->startlineSetter((yyvsp[-5].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");			
			symtable.Insert((yyvsp[-4].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[-4].symbol)->nameGetter());
			temp->retTypeSetter((yyvsp[-5].symbol)->varTypeGetter());
			temp->checkFunctionSetter(true);
			temp->argNumberSetter(parameterList.size());
			temp->retTypeSetter((yyvsp[-5].symbol)->varTypeGetter());
			(yyvsp[-4].symbol)=temp;
			(yyval.symbol)->addChild({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[0].symbol)});
			//symtable.PrintAllScope(logout);
		}
#line 1606 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 269 "2005053.y"
                {   
			(yyval.symbol) = new SymbolInfo();
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier ID\n");
			(yyvsp[0].symbol)->varTypeSetter(varType);
			(yyvsp[0].symbol)->retTypeSetter((yyvsp[-1].symbol)->retTypeGetter());
			parameterList.push_back((yyvsp[0].symbol));
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("parameter_list  : parameter_list COMMA type_specifier ID");
		    (yyval.symbol)->addChild({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-3].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		}
#line 1623 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 282 "2005053.y"
                {
			(yyval.symbol) = new SymbolInfo();
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("parameter_list  : parameter_list COMMA type_specifier");
		    (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier\n");
		}
#line 1637 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 292 "2005053.y"
                {   
			(yyval.symbol)=new SymbolInfo();
			//parameterList.clear();
			parameterList.push_back((yyvsp[0].symbol));
			(yyvsp[0].symbol)->varTypeSetter(varType);
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("parameter_list  : type_specifier ID");
		    (yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier ID\n");

		}
#line 1655 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 306 "2005053.y"
                {   
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter(varType);
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("parameter_list  : type_specifier");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier\n");
			
		}
#line 1671 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL statements RCURL  */
#line 321 "2005053.y"
                        {   
				(yyval.symbol)= new SymbolInfo();
				obj.currSymbolSetter((yyval.symbol));
		        (yyval.symbol)->exprSetter("compound_statement : LCURL statements RCURL");
		        (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		        (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
				fprintf(logout,"compound_statement : LCURL statements RCURL\n");
				symtable.PrintAllScope(logout);
			}
#line 1686 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL RCURL  */
#line 332 "2005053.y"
                        {
				 (yyval.symbol)=new SymbolInfo();
				 obj.currSymbolSetter((yyval.symbol));
		         (yyval.symbol)->exprSetter("compound_statement : LCURL RCURL");
		         (yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				 (yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    	 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
				 fprintf(logout,"compound_statement : LCURL RCURL\n");
				 symtable.PrintAllScope(logout);
			}
#line 1701 "y.tab.c"
    break;

  case 20: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 345 "2005053.y"
                        {   
				fprintf(logout,"var_declaration : type_specifier declaration_list SEMICOLON\n");
				(yyval.symbol)= new SymbolInfo();
				(yyval.symbol)->varTypeSetter((yyvsp[-2].symbol)->nameGetter());

				obj.currSymbolSetter((yyval.symbol));
		        (yyval.symbol)->exprSetter("var_declaration : type_specifier declaration_list SEMICOLON");
		        (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		        (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
				(yyval.symbol)->setScope(symtable.GetCurrent()->getId());
				(yyvsp[-1].symbol)->varList = varDeclarationList;
				// if($1->varTypeGetter()=="VOID")
				// {
				// 	for(SymbolInfo *sym:varDeclarationList)
				// 	{
				// 		fprintf(errorout,"Line# %d: Variable or field '%s' declared void\n",line_count,sym->nameGetter().c_str());
				// 		symtable.Remove(sym->nameGetter());
				// 		errors++;					
				// 	}
				// }
				varDeclarationList.clear();			
			}
#line 1729 "y.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 371 "2005053.y"
                {	
			fprintf(logout,"type_specifier	: INT\n");
			(yyval.symbol)=new SymbolInfo();
			varType="INT";
			(yyval.symbol)->varTypeSetter("INT");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("type_specifier	: INT");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			store=line_count;
		}
#line 1746 "y.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 384 "2005053.y"
                {
			fprintf(logout,"type_specifier	: FLOAT\n");
			(yyval.symbol)=new SymbolInfo();
			varType="FLOAT";
			(yyval.symbol)->varTypeSetter("FLOAT");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("type_specifier	: FLOAT");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			store=line_count;
		}
#line 1763 "y.tab.c"
    break;

  case 23: /* type_specifier: VOID  */
#line 397 "2005053.y"
                {
			fprintf(logout,"type_specifier	: VOID\n");
			(yyval.symbol)=new SymbolInfo();
			varType="VOID";
			(yyval.symbol)->varTypeSetter("VOID");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("type_specifier	: VOID");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			store=line_count;
		}
#line 1780 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID  */
#line 412 "2005053.y"
                  { 
			(yyval.symbol)=new SymbolInfo();
			errorflag=symtable.Insert((yyvsp[0].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[0].symbol)->nameGetter());
			if(errorflag)
			{
				temp->varTypeSetter(varType);
			}	
			// else{
			// 	if(temp->varTypeGetter()!=varType)
			// 	{
			// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
			// 		errors++;
			// 	}
			// }	
			fprintf(logout,"declaration_list : declaration_list COMMA ID\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("declaration_list : declaration_list COMMA ID");
		    (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			varDeclarationList.push_back(temp);
			//symtable.PrintAllScope(logout);
        
		  }
#line 1810 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 438 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			errorflag=symtable.Insert((yyvsp[-3].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[-3].symbol)->nameGetter());
			//if(errorflag)
			//{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
				//cout<<"Bye";
				temp->sizeSetter(atoi((yyvsp[-1].symbol)->nameGetter().c_str()));
				
			//}	
			// else{
			// 	if(temp->varTypeGetter()!=varType)
			// 	{
			// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
			// 		errors++;
			// 	}
			// }
			fprintf(logout,"declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n");	
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");
		    (yyval.symbol)->addChild({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});	
			(yyval.symbol)->startlineSetter((yyvsp[-5].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());	
			varDeclarationList.push_back(temp);
				
		  }
#line 1843 "y.tab.c"
    break;

  case 26: /* declaration_list: ID  */
#line 467 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			errorflag=symtable.Insert((yyvsp[0].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[0].symbol)->nameGetter());
			//if(errorflag)
			//{
				temp->varTypeSetter(varType);
			//}
			// else{
			// 	if(temp->varTypeGetter()!=varType)
			// 	{
			// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
			// 		errors++;
			// 	}
			// }
			varDeclarationList.push_back(temp);
			//$$->varList.push_back(temp);
			fprintf(logout,"declaration_list : ID\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("declaration_list : ID");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});		
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			
			//symtable.PrintAllScope(logout);
		  }
#line 1874 "y.tab.c"
    break;

  case 27: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 494 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			symtable.Insert((yyvsp[-3].symbol)->nameGetter(),"ID");
			temp=symtable.LookUp((yyvsp[-3].symbol)->nameGetter());
			//if(errorflag)
			//{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
				//cout<<"Hello";
				temp->sizeSetter(atoi((yyvsp[-1].symbol)->nameGetter().c_str()));
			//}
			fprintf(logout,"declaration_list : ID LSQUARE CONST_INT RSQUARE\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("declaration_list : ID LSQUARE CONST_INT RSQUARE");
		    (yyval.symbol)->addChild({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-3].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());		
			varDeclarationList.push_back(temp);
		  }
#line 1898 "y.tab.c"
    break;

  case 28: /* statements: statement  */
#line 516 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			fprintf(logout,"statements : statement\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("statements : statement");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		}
#line 1912 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 526 "2005053.y"
           {
		    (yyval.symbol)=new SymbolInfo();
			fprintf(logout,"statements : statements statement\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("statements : statements statement");
		    (yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());		
	   }
#line 1926 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 538 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : var_declaration");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});	
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : var_declaration\n");
	  }
#line 1940 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 548 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : expression_statement");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});	
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : expression_statement\n");
	  }
#line 1954 "y.tab.c"
    break;

  case 32: /* statement: compound_statement  */
#line 558 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : compound_statement");
		 (yyval.symbol)->addChild({(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : compound_statement\n");
	  }
#line 1968 "y.tab.c"
    break;

  case 33: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 568 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		 (yyval.symbol)->addChild({(yyvsp[-6].symbol),(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-6].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
	  }
#line 1982 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement  */
#line 578 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : IF LPAREN expression RPAREN statement");
		 (yyval.symbol)->addChild({(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-4].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement\n");
	  }
#line 1996 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 588 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : IF LPAREN expression RPAREN statement ELSE statement");
		 (yyval.symbol)->addChild({(yyvsp[-6].symbol),(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-6].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement ELSE statement\n");
	  }
#line 2010 "y.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 598 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : WHILE LPAREN expression RPAREN statement");
		 (yyval.symbol)->addChild({(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-4].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : WHILE LPAREN expression RPAREN statement\n");
	  }
#line 2024 "y.tab.c"
    break;

  case 37: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 608 "2005053.y"
          {  
		 (yyval.symbol)=new SymbolInfo();
		 temp=symtable.LookUp((yyvsp[-2].symbol)->nameGetter());
		 (yyvsp[-2].symbol)=temp;
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		 (yyval.symbol)->addChild({(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-4].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
	  }
#line 2040 "y.tab.c"
    break;

  case 38: /* statement: RETURN expression SEMICOLON  */
#line 620 "2005053.y"
          {
		 (yyval.symbol)=new SymbolInfo();
		 retType=(yyvsp[-1].symbol)->varTypeGetter();
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("statement : RETURN expression SEMICOLON");
		 (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 fprintf(logout,"statement : RETURN expression SEMICOLON\n");
	  }
#line 2055 "y.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 633 "2005053.y"
                         {
				(yyval.symbol)=new SymbolInfo();
				obj.currSymbolSetter((yyval.symbol));
		 		(yyval.symbol)->exprSetter("expression_statement : SEMICOLON");
		 		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
				(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		   		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		        fprintf(logout,"expression_statement : SEMICOLON\n");
			 }
#line 2069 "y.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 643 "2005053.y"
                        {
				(yyval.symbol)=new SymbolInfo("","expression_statement");
				obj.currSymbolSetter((yyval.symbol));
		 		(yyval.symbol)->exprSetter("expression_statement : expression SEMICOLON");
		 		(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    	(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		        fprintf(logout,"expression_statement : expression SEMICOLON \n");
			}
#line 2083 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 655 "2005053.y"
         {  
		(yyval.symbol)=new SymbolInfo();
		//cout << $1->nameGetter() << endl;
		temp=symtable.LookUp((yyvsp[0].symbol)->nameGetter());
		//cout << "tmp: " << temp->nameGetter() << " " << temp->typeGetter() << endl; 
		if(temp!=NULL)
		{   
			//cout<<"Hello :"<<temp->()<<endl;;
			(yyvsp[0].symbol) = temp;
			//$$=temp;
			(yyval.symbol)->varTypeSetter(temp->varTypeGetter());
		}
		// else{
		// 	fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,$1->nameGetter().c_str());
		// 	errors++;
		// }
		fprintf(logout,"variable : ID\n");
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("variable : ID");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());

	 }
#line 2112 "y.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 680 "2005053.y"
         {  
		(yyval.symbol)=new SymbolInfo();
		temp=symtable.LookUp((yyvsp[-3].symbol)->nameGetter());
		if(temp!=NULL)
		{ 
			(yyvsp[-3].symbol)=temp;
			(yyval.symbol)->varTypeSetter(temp->varTypeGetter());
		}
		// else{
		// 	fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,$1->nameGetter().c_str());
		// 	errors++;
		// }
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("variable : ID LSQUARE expression RSQUARE");
		(yyval.symbol)->addChild({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-3].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"variable : ID LSQUARE expression RSQUARE\n");
	 }
#line 2136 "y.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 702 "2005053.y"
           {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
		fprintf(logout,"expression : logic_expression\n");
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("expression : logic_expression");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	   }
#line 2151 "y.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 713 "2005053.y"
           { 
		 (yyval.symbol)=new SymbolInfo();
		 (yyval.symbol)->varTypeSetter((yyvsp[-2].symbol)->varTypeGetter());
		 fprintf(logout,"expression : variable ASSIGNOP logic_expression\n");
		 obj.currSymbolSetter((yyval.symbol));
		 (yyval.symbol)->exprSetter("expression : variable ASSIGNOP logic_expression");
		 (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		 (yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		 (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	   }
#line 2166 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 726 "2005053.y"
                 {
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("logic_expression : rel_expression");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression\n");

		 }
#line 2182 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 738 "2005053.y"
                 {
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[-2].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("logic_expression : rel_expression LOGICOP rel_expression");
		    (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression LOGICOP rel_expression\n");
		 }
#line 2197 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 751 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("rel_expression	: simple_expression");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression\n");
		}
#line 2212 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 762 "2005053.y"
                {
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[-2].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("rel_expression	: simple_expression RELOP simple_expression");
		    (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression RELOP simple_expression\n");
		}
#line 2227 "y.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 775 "2005053.y"
                  { 
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("simple_expression : term");
		    (yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			fprintf(logout,"simple_expression : term\n");
		  }
#line 2242 "y.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 786 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			fprintf(logout,"simple_expression : simple_expression ADDOP term\n");
			if((yyvsp[-2].symbol)->varTypeGetter()=="INT" && (yyvsp[0].symbol)->varTypeGetter()=="INT")
			{
				(yyval.symbol)->varTypeSetter("INT");
			}
			else if((yyvsp[-2].symbol)->varTypeGetter()=="FLOAT" && (yyvsp[0].symbol)->varTypeGetter()=="FLOAT")
			{
				(yyval.symbol)->varTypeSetter("FLOAT");
			}
			// else if($1->varTypeGetter()=="VOID" ||$3->varTypeGetter()=="VOID")
		    // {
			// 	fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			//     errors++;
		    // }
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("simple_expression : simple_expression ADDOP term");
		    (yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		  }
#line 2269 "y.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 811 "2005053.y"
         {  
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("term :	unary_expression");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"term :	unary_expression\n");
	 }
#line 2284 "y.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 822 "2005053.y"
         {
		(yyval.symbol)=new SymbolInfo();
		fprintf(logout,"term : term MULOP unary_expression\n");
		if((yyvsp[-2].symbol)->varTypeGetter()=="INT" && (yyvsp[0].symbol)->varTypeGetter()=="INT")
		{
			(yyval.symbol)->varTypeSetter("INT");
		}
		else if((yyvsp[-2].symbol)->varTypeGetter()=="FLOAT" && (yyvsp[0].symbol)->varTypeGetter()=="FLOAT")
		{
			(yyval.symbol)->varTypeSetter("FLOAT");
		}
        // else if($1->varTypeGetter()=="VOID" ||$3->varTypeGetter()=="VOID")
		// {
		// 		fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
		// 	    errors++;
		// }
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("term : term MULOP unary_expression");
		(yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	 }
#line 2311 "y.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 847 "2005053.y"
                 {
			(yyval.symbol)=new SymbolInfo();
			// if($2->varTypeGetter()=="VOID")
			// {
			// 	fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			//     errors++;
			// }
			// else{
			(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			//}
		    fprintf(logout,"unary_expression : ADDOP unary_expression\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("unary_expression : ADDOP unary_expression");
			(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 }
#line 2333 "y.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 865 "2005053.y"
                 {
			(yyval.symbol)=new SymbolInfo();
			(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			// if($2->varTypeGetter()=="VOID")
			// {
			// 	fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			//     errors++;
			// }
			// else{
				(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			//}
		    fprintf(logout,"unary_expression : NOT unary_expression\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("unary_expression : NOT unary_expression");
			(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 }
#line 2356 "y.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 884 "2005053.y"
                 {
			(yyval.symbol)=new SymbolInfo();
			// if($1->varTypeGetter()=="VOID")
			// {
			// 	fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			//     errors++;
			// }
			// else{
				(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
			//}

		    fprintf(logout,"unary_expression : factor\n");
			obj.currSymbolSetter((yyval.symbol));
		    (yyval.symbol)->exprSetter("unary_expression : factor");
			(yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		 }
#line 2379 "y.tab.c"
    break;

  case 56: /* factor: variable  */
#line 905 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->varTypeGetter());
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor	: variable");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"factor	: variable\n");
	}
#line 2394 "y.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 916 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		temp=symtable.LookUp((yyvsp[-3].symbol)->nameGetter());
		// if(temp!=NULL)
		// {   
		// 	temp->varTypeSetter(temp->retTypeGetter());
			
		// 	if(parameterList.size()>temp->listOfParameter.size())
		// 	{
		// 		fprintf(errorout,"Line# %d: Too many arguments to function '%s'\n",line_count,$1->nameGetter().c_str());
		// 		errors++;
		// 	}
		// 	else if(parameterList.size()<temp->listOfParameter.size())
		// 	{
		// 		fprintf(errorout,"Line# %d: Too few arguments to function '%s'\n",line_count,$1->nameGetter().c_str());
		// 		errors++;
		// 	}
		// 	else {
		// 		for(int i=0;i<parameterList.size();i++)
		// 		{   
        //             if(parameterList[i]->checkArrayGetter()!=temp->listOfParameter[i]->checkArrayGetter())
		// 			{
		// 				fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,$1->nameGetter().c_str());
		// 		        errors++;
		// 			}
		// 			else if(parameterList[i]->varTypeGetter()!=temp->listOfParameter[i]->varTypeGetter())
		// 			{
		// 				fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,$1->nameGetter().c_str());
		// 		        errors++;
		// 			}
		// 		}
		// 	}

		// }
		// else{
		// 	fprintf(errorout,"Line# %d: Undeclared function '%s'\n",line_count,$1->nameGetter().c_str());
		// 	errors++;
		// }
		//parameterList.clear();
		fprintf(logout,"factor : ID LPAREN argument_list RPAREN\n");
		obj.currSymbolSetter((yyval.symbol));
		(yyvsp[-3].symbol)=temp;
		(yyval.symbol)->exprSetter("factor : ID LPAREN argument_list RPAREN");
		(yyval.symbol)->addChild({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->varTypeSetter((yyvsp[-3].symbol)->retTypeGetter());
		(yyval.symbol)->startlineSetter((yyvsp[-3].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	}
#line 2447 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 965 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[-1].symbol)->varTypeGetter());
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor : LPAREN expression RPAREN");
		(yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"factor : LPAREN expression RPAREN\n");
	}
#line 2462 "y.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 976 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->typeGetter());
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor : CONST_INT");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"factor : CONST_INT\n");
	}
#line 2477 "y.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 987 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[0].symbol)->typeGetter());
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor : CONST_FLOAT");
		(yyval.symbol)->addChild({(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		fprintf(logout,"factor : CONST_FLOAT\n");
	}
#line 2492 "y.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 998 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[-1].symbol)->varTypeGetter());
		fprintf(logout,"factor : variable INCOP\n");
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor : variable INCOP");
		(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	}
#line 2507 "y.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 1009 "2005053.y"
        {
		(yyval.symbol)=new SymbolInfo();
		(yyval.symbol)->varTypeSetter((yyvsp[-1].symbol)->varTypeGetter());
		fprintf(logout,"factor : variable DECOP\n");
		obj.currSymbolSetter((yyval.symbol));
		(yyval.symbol)->exprSetter("factor : variable DECOP");
		(yyval.symbol)->addChild({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->startlineSetter((yyvsp[-1].symbol)->startlineGetter());
		(yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
	}
#line 2522 "y.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 1022 "2005053.y"
                          {
				(yyval.symbol)=new SymbolInfo();
		        fprintf(logout,"argument_list : arguments\n");
				obj.currSymbolSetter((yyval.symbol));
				(yyval.symbol)->exprSetter("argument_list : arguments");
				(yyval.symbol)->addChild({(yyvsp[0].symbol)});
				(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		        (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
			  }
#line 2536 "y.tab.c"
    break;

  case 64: /* argument_list: %empty  */
#line 1031 "2005053.y"
                            {(yyval.symbol)=new SymbolInfo(); (yyval.symbol)->exprSetter("");}
#line 2542 "y.tab.c"
    break;

  case 65: /* arguments: arguments COMMA logic_expression  */
#line 1035 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			//parameterList.push_back($3);
		    fprintf(logout,"arguments : arguments COMMA logic_expression\n");
			obj.currSymbolSetter((yyval.symbol));
			(yyval.symbol)->exprSetter("arguments : arguments COMMA logic_expression");
			(yyval.symbol)->addChild({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[-2].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		  }
#line 2557 "y.tab.c"
    break;

  case 66: /* arguments: logic_expression  */
#line 1046 "2005053.y"
                  {
			(yyval.symbol)=new SymbolInfo();
			//parameterList.push_back($1);
		    fprintf(logout,"arguments : logic_expression\n");
			obj.currSymbolSetter((yyval.symbol));
			(yyval.symbol)->exprSetter("arguments : logic_expression");
			(yyval.symbol)->addChild({(yyvsp[0].symbol)});
			(yyval.symbol)->startlineSetter((yyvsp[0].symbol)->startlineGetter());
		    (yyval.symbol)->endlineSetter((yyvsp[0].symbol)->endlineGetter());
		  }
#line 2572 "y.tab.c"
    break;


#line 2576 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1059 "2005053.y"


int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
    logout= fopen("log.txt","w");
	errorout= fopen("error.txt","w");
	parseout= fopen("parsetree.txt","w");
	codeout = fopen("code.txt","w");
	codeasm = fopen("code.asm","w");
	tokenout= fopen("token.txt","w");
	yyin= fin;
	yyparse();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	for(int i=0;i<11;i++)
	{   
		SymbolInfo *localSym=symtable.GetCurrent()->arr[i];
		if(localSym!=NULL)
		{
			if(!localSym->checkFunctionGetter())
			{   
				globalVar.push_back(localSym);
			}
		}
	}
	ICG object;
	object.fileVar(codeasm,codeout,globalVar);
	object.init();
	object.printGlobal();
	object.writeICG(root);
	object.printOut();
	object.printNewLine();
	fprintf(codeasm,"END main\n");
	return 0;
} 

