/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "2005053.y"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include "2005053-SymbolTable.cpp"
#include "2005053-ParseTree.cpp"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
FILE *logout;
FILE *errorout;
FILE *parseout;
SymbolTable symtable(11);
SymbolInfo *temp;
ParseTree obj;
vector<SymbolInfo*>parameterList;
vector<SymbolInfo*>varDeclarationList;
string varType;
int errors=0;
int store=0;

bool errorflag=false;
string retType;

void yyerror(char *s)
{   
	
	/*write your code*/
}


#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 42 "2005053.y"
typedef union YYSTYPE
{
    SymbolInfo *symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 75 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    9,    9,   23,   22,
   24,   22,    6,    6,    6,    6,    3,    3,    7,    4,
    4,    4,    5,    5,    5,    5,   11,   11,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   16,   16,    8,
    8,   12,   12,   21,   21,   19,   19,   17,   17,   20,
   20,   18,   18,   18,   13,   13,   13,   13,   13,   13,
   13,   15,   15,   14,   14,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    6,    5,    0,    7,
    0,    6,    4,    3,    2,    1,    3,    2,    3,    1,
    1,    1,    3,    6,    1,    4,    1,    2,    1,    1,
    1,    7,    5,    7,    5,    5,    3,    1,    2,    1,
    4,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    2,    2,    1,    1,    4,    3,    1,    1,    2,
    2,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         0,
   20,   21,   22,    0,    0,    3,    0,    4,    5,    6,
    2,    0,    0,    0,    0,   19,    0,    0,    0,    0,
    0,    0,   26,    8,    0,   15,    0,    0,    0,    0,
   12,    7,    0,    0,    0,    0,    0,    0,    0,   38,
   18,    0,   58,   59,    0,    0,    0,    0,   31,    0,
   29,    0,   27,    0,    0,   54,   30,    0,   50,    0,
    0,   42,   10,   13,   24,    0,    0,    0,    0,   53,
   52,    0,    0,    0,    0,    0,    0,   60,   61,    0,
   17,   28,   39,    0,    0,    0,    0,    0,   37,   57,
    0,    0,    0,   65,    0,    0,    0,   43,    0,    0,
   45,   51,    0,   41,    0,   56,    0,    0,    0,    0,
   64,    0,   35,   36,    0,    0,   34,   32,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  281,  282,  283,  291,  292,  293,  295,  298,  300,  313,
  293,  278,  296,  261,  265,  269,  272,  275,  266,  295,
  297,  278,  262,  269,  315,  278,  266,  272,  261,  270,
  294,  269,  314,  295,  275,  258,  260,  265,  268,  269,
  271,  273,  275,  276,  278,  279,  280,  284,  294,  295,
  298,  299,  301,  302,  303,  304,  307,  308,  309,  310,
  311,  312,  294,  278,  262,  265,  303,  303,  299,  309,
  309,  261,  265,  265,  265,  265,  278,  263,  264,  267,
  271,  301,  269,  257,  273,  277,  274,  303,  269,  266,
  303,  305,  306,  312,  307,  303,  278,  312,  308,  311,
  310,  309,  266,  262,  272,  266,  307,  266,  266,  301,
  312,  303,  301,  269,  259,  266,  301,  301,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
    5,    6,   49,   50,   13,   21,   51,   52,    9,   53,
   54,   55,   56,   92,   93,   57,   58,   59,   60,   61,
   62,   10,   33,   25,
};
static const YYINT yysindex[] = {                      -136,
    0,    0,    0,    0, -136,    0, -260,    0,    0,    0,
    0, -218, -192, -244, -241,    0, -232, -217, -205, -221,
 -250, -186,    0,    0, -181,    0, -172, -136, -173, -197,
    0,    0, -181, -160, -141, -146,  -40,  -40,  -40,    0,
    0,  -40,    0,    0, -145, -134, -131, -122,    0, -149,
    0, -171,    0, -170, -121,    0,    0, -243,    0, -127,
 -118,    0,    0,    0,    0,  -40,  -99,  -95, -140,    0,
    0,  -40,  -40,  -46,  -40, -106,  -68,    0,    0,  -40,
    0,    0,    0,  -40,  -40,  -40,  -40,  -76,    0,    0,
  -70,  -67,  -63,    0,  -46,  -58,  -57,    0,  -77, -118,
    0,    0, -116,    0,  -40,    0,  -40, -116,  -55,  -41,
    0,  -42,    0,    0, -116, -116,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  220,    0,    0,    0,    0,    0,
    0, -178,    0,    0,    0,    0,    0,    0,  -44, -233,
    0, -165,    0,    0,    0,    0,  -39,    0,    0,    0,
    0,    0,    0, -212,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -88,    0,    0,    0,    0,    0,
    0,  -62,    0,    0,    0,    0,    0, -210,    0, -111,
 -245,    0,    0,    0,    0,    0,    0,    0,  -75,    0,
    0,    0,  -29,    0,    0,    0, -178,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -27,    0,    0,    0,    0,    0,    0,  -89,  -56,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -143,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  229,  -14,    8,    0,    0,   15,  -36,    0,  -50,
    0,  -37,    0,    0,    0,  -69,  156,  -32,  155,  157,
  -71,    0,    0,    0,
};
#define YYTABLESIZE 242
static const YYINT yytable[] = {                         67,
   68,   94,   69,   82,   95,   69,   70,    7,   98,   71,
   31,   48,    7,   84,    8,   27,   48,   12,   63,    8,
   48,   28,   20,   48,   19,  107,   48,   48,   88,   85,
   18,   48,   16,  111,   91,   34,   69,   96,   16,    1,
    2,    3,   14,   69,   23,   22,   15,   69,   69,   69,
   69,   46,  110,   14,  102,   46,   26,  113,   46,   14,
   36,   46,   37,   24,  117,  118,   46,   38,   69,  112,
   39,   40,   30,   41,   29,   42,   16,   43,   44,   17,
   45,   46,   47,    1,    2,    3,   48,   36,   30,   37,
   25,   78,   79,   25,   38,   80,   32,   39,   40,   30,
   81,   35,   42,   23,   43,   44,   23,   45,   46,   47,
    1,    2,    3,   48,   33,   72,   33,   64,   66,   73,
   65,   33,   78,   79,   33,   33,   33,   33,   77,   33,
   74,   33,   33,   75,   33,   33,   33,   33,   33,   33,
   33,   36,   76,   37,    1,    2,    3,   83,   38,   86,
   44,   39,   40,   30,   44,   87,   42,   44,   43,   44,
   44,   45,   46,   47,    1,    2,    3,   48,   40,   89,
   90,   97,   47,   40,   40,   40,   47,   40,   40,   47,
   40,   55,   47,   40,   40,   40,   55,   47,   40,  103,
   55,  104,   14,   55,   55,   85,   55,   55,   55,   55,
   49,   55,  106,   55,  105,   49,   55,  108,  109,   49,
   55,   55,   49,  114,   55,   49,   49,  115,   38,    1,
   49,   39,   40,  116,   38,   11,   42,   39,   43,   44,
    9,   45,   42,   11,   43,   44,   63,   45,   62,   99,
  101,  100,
};
static const YYINT yycheck[] = {                         37,
   38,   73,   39,   54,   74,   42,   39,    0,   80,   42,
   25,  257,    5,  257,    0,  266,  262,  278,   33,    5,
  266,  272,   15,  269,  266,   95,  272,  273,   66,  273,
  275,  277,  266,  105,   72,   28,   73,   75,  272,  281,
  282,  283,  261,   80,  262,  278,  265,   84,   85,   86,
   87,  262,  103,  266,   87,  266,  278,  108,  269,  272,
  258,  272,  260,  269,  115,  116,  277,  265,  105,  107,
  268,  269,  270,  271,  261,  273,  269,  275,  276,  272,
  278,  279,  280,  281,  282,  283,  284,  258,  270,  260,
  269,  263,  264,  272,  265,  267,  269,  268,  269,  270,
  271,  275,  273,  269,  275,  276,  272,  278,  279,  280,
  281,  282,  283,  284,  258,  261,  260,  278,  265,  265,
  262,  265,  263,  264,  268,  269,  270,  271,  278,  273,
  265,  275,  276,  265,  278,  279,  280,  281,  282,  283,
  284,  258,  265,  260,  281,  282,  283,  269,  265,  277,
  262,  268,  269,  270,  266,  274,  273,  269,  275,  276,
  272,  278,  279,  280,  281,  282,  283,  284,  257,  269,
  266,  278,  262,  262,  263,  264,  266,  266,  267,  269,
  269,  257,  272,  272,  273,  274,  262,  277,  277,  266,
  266,  262,  261,  269,  257,  273,  272,  273,  274,  262,
  257,  277,  266,  266,  272,  262,  269,  266,  266,  266,
  273,  274,  269,  269,  277,  272,  273,  259,  265,    0,
  277,  268,  269,  266,  265,  270,  273,  268,  275,  276,
  270,  278,  273,    5,  275,  276,  266,  278,  266,   84,
   86,   85,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#define YYUNDFTOKEN 316
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","RELOP","IF","ELSE","RETURN",
"LTHIRD","RTHIRD","INCOP","DECOP","LPAREN","RPAREN","ASSIGNOP","NOT",
"SEMICOLON","LCURL","RCURL","COMMA","ADDOP","MULOP","CONST_INT","CONST_FLOAT",
"LOGICOP","ID","FOR","WHILE","INT","FLOAT","VOID","PRINTLN","CHAR","CONST_CHAR",
"DO","BITOP","LOW_PREC","$accept","start","program","unit","compound_statement",
"type_specifier","declaration_list","parameter_list","var_declaration",
"variable","func_declaration","statement","statements","expression","factor",
"arguments","argument_list","expression_statement","simple_expression",
"unary_expression","rel_expression","term","logic_expression","func_definition",
"$$1","$$2","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : program",
"program : program unit",
"program : unit",
"unit : var_declaration",
"unit : func_declaration",
"unit : func_definition",
"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",
"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON",
"$$1 :",
"func_definition : type_specifier ID LPAREN parameter_list RPAREN $$1 compound_statement",
"$$2 :",
"func_definition : type_specifier ID LPAREN RPAREN $$2 compound_statement",
"parameter_list : parameter_list COMMA type_specifier ID",
"parameter_list : parameter_list COMMA type_specifier",
"parameter_list : type_specifier ID",
"parameter_list : type_specifier",
"compound_statement : LCURL statements RCURL",
"compound_statement : LCURL RCURL",
"var_declaration : type_specifier declaration_list SEMICOLON",
"type_specifier : INT",
"type_specifier : FLOAT",
"type_specifier : VOID",
"declaration_list : declaration_list COMMA ID",
"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",
"declaration_list : ID",
"declaration_list : ID LTHIRD CONST_INT RTHIRD",
"statements : statement",
"statements : statements statement",
"statement : var_declaration",
"statement : expression_statement",
"statement : compound_statement",
"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement",
"statement : IF LPAREN expression RPAREN statement",
"statement : IF LPAREN expression RPAREN statement ELSE statement",
"statement : WHILE LPAREN expression RPAREN statement",
"statement : PRINTLN LPAREN ID RPAREN SEMICOLON",
"statement : RETURN expression SEMICOLON",
"expression_statement : SEMICOLON",
"expression_statement : expression SEMICOLON",
"variable : ID",
"variable : ID LTHIRD expression RTHIRD",
"expression : logic_expression",
"expression : variable ASSIGNOP logic_expression",
"logic_expression : rel_expression",
"logic_expression : rel_expression LOGICOP rel_expression",
"rel_expression : simple_expression",
"rel_expression : simple_expression RELOP simple_expression",
"simple_expression : term",
"simple_expression : simple_expression ADDOP term",
"term : unary_expression",
"term : term MULOP unary_expression",
"unary_expression : ADDOP unary_expression",
"unary_expression : NOT unary_expression",
"unary_expression : factor",
"factor : variable",
"factor : ID LPAREN argument_list RPAREN",
"factor : LPAREN expression RPAREN",
"factor : CONST_INT",
"factor : CONST_FLOAT",
"factor : variable INCOP",
"factor : variable DECOP",
"argument_list : arguments",
"argument_list :",
"arguments : arguments COMMA logic_expression",
"arguments : logic_expression",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 1039 "2005053.y"

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
	//tokenout= fopen("token.txt","w");
	yyin= fin;
	yyparse();
	fclose(yyin);
	//fclose(tokenout);
	fclose(logout);
	return 0;
} 

#line 585 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 61 "2005053.y"
	{
		fprintf(logout,"start : program\n");
		fprintf(logout,"Total Lines: %d\n",line_count);
		fprintf(logout,"Total Errors: %d\n",errors);
		yyval.symbol=new SymbolInfo();
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("start : program");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		/*cout<<"hello"<<endl;*/
		/*cout<<$$->childArr.size()<<endl;*/
		obj.printParse(parseout,yyval.symbol);
		/*delete $$;*/
	}
#line 1272 "y.tab.c"
break;
case 2:
#line 79 "2005053.y"
	{
        fprintf(logout,"program : program unit \n");
        /*$1->nameSetter();*/
        /*$$=$1;*/
		yyval.symbol=new SymbolInfo();
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("program : program unit");
		yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
    }
#line 1287 "y.tab.c"
break;
case 3:
#line 91 "2005053.y"
	{
        fprintf(logout,"program : unit\n");
        yyval.symbol=new SymbolInfo();
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("program : unit");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
    }
#line 1300 "y.tab.c"
break;
case 4:
#line 103 "2005053.y"
	{
         fprintf(logout,"unit : var_declaration\n");
         yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("unit : var_declaration");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
     }
#line 1313 "y.tab.c"
break;
case 5:
#line 113 "2005053.y"
	{
         fprintf(logout,"unit : func_declaration\n");
         yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("unit : func_declaration");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
     }
#line 1326 "y.tab.c"
break;
case 6:
#line 123 "2005053.y"
	{
         fprintf(logout,"unit : func_definition\n");
         yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("unit : func_definition");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
     }
#line 1339 "y.tab.c"
break;
case 7:
#line 135 "2005053.y"
	{
          fprintf(logout,"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
          yyval.symbol=new SymbolInfo(); 
		  obj.currSymbolSetter(yyval.symbol);
		  yyval.symbol->exprSetter("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		  yyval.symbol->addChild({yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		  yyval.symbol->startlineSetter(yystack.l_mark[-5].symbol->startlineGetter());
		  yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		  errorflag=symtable.Insert(yystack.l_mark[-4].symbol->nameGetter(),"ID");
		  temp=symtable.LookUp(yystack.l_mark[-4].symbol->nameGetter());
		/*   if(errorflag==false)*/
		/*   {*/
		/* 	//printf("Hello");*/
		/* 	if(temp->checkFunctionGetter())*/
		/* 	{*/
		/* 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());*/
		/* 	}*/
		/* 	else{*/
		/* 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());*/
		/* 	}*/
		/* 	errors++;*/
		/*   } */
		  /*else{*/
          temp->checkFunctionSetter(true);
          temp->listOfParameter=parameterList;
          temp->retTypeSetter(yystack.l_mark[-5].symbol->varTypeGetter());
          parameterList.clear();
		 /* }*/
        }
#line 1372 "y.tab.c"
break;
case 8:
#line 165 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		    yyval.symbol->addChild({yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-4].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			errorflag=symtable.Insert(yystack.l_mark[-3].symbol->nameGetter(),"ID");
			/* if(errorflag==false)*/
		    /* {*/
			/* //printf("Hello");*/
			/*   errors++;*/
	        /*   fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());*/
		    /* } */
			temp=symtable.LookUp(yystack.l_mark[-3].symbol->nameGetter());
			temp->checkFunctionSetter(true);
            temp->retTypeSetter(yystack.l_mark[-4].symbol->varTypeGetter());
            fprintf(logout,"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");			

		}
#line 1396 "y.tab.c"
break;
case 9:
#line 187 "2005053.y"
	{
        symtable.EnterScope();
		for(int i=0;i<parameterList.size();i++)
		{   
			string name=parameterList[i]->nameGetter();
			string s=parameterList[i]->varTypeGetter();
			errorflag=symtable.Insert(name,"ID");
			if(errorflag)
			{
				temp=symtable.LookUp(name);
				temp->varTypeSetter(s);
			}
			else{
				 errors++;
	             fprintf(errorout,"Line# %d: Redefinition of parameter '%s'\n",line_count,name.c_str());
			}
		}	
		}
#line 1418 "y.tab.c"
break;
case 10:
#line 206 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yystack.l_mark[-5].symbol->retTypeSetter(yystack.l_mark[-6].symbol->varTypeGetter());
			symtable.ExitScope();
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		    yyval.symbol->addChild({yystack.l_mark[-6].symbol,yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-6].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");			
			errorflag=symtable.Insert(yystack.l_mark[-5].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[-5].symbol->nameGetter());
			if(errorflag==false)
			{   
				if(temp->checkFunctionGetter()==false)
				{
					fprintf(errorout,"Line# %d: '%s'redeclared as different kind of symbol\n",store,yystack.l_mark[-5].symbol->nameGetter().c_str());
					errors++;
				}
				else if(temp->retTypeGetter()!=yystack.l_mark[-6].symbol->varTypeGetter())
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,yystack.l_mark[-5].symbol->nameGetter().c_str());
					errors++;
				}
				
			}	
			if(errorflag)
			{
				temp->retTypeSetter(yystack.l_mark[-6].symbol->varTypeGetter());
				temp->checkFunctionSetter(true);
			}						
			for(int i=0;i<parameterList.size();i++)
		    {   
				temp->listOfParameter.push_back(parameterList[i]);
		    }	
			parameterList.clear();
			
			/*symtable.PrintAllScope(logout);*/
		}
#line 1461 "y.tab.c"
break;
case 11:
#line 245 "2005053.y"
	{
			symtable.EnterScope();
		}
#line 1468 "y.tab.c"
break;
case 12:
#line 249 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yystack.l_mark[-4].symbol->retTypeSetter(yystack.l_mark[-5].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
			symtable.ExitScope();
		    yyval.symbol->exprSetter("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		    yyval.symbol->addChild({yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-5].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");			
			symtable.Insert(yystack.l_mark[-4].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[-4].symbol->nameGetter());
			temp->retTypeSetter(yystack.l_mark[-5].symbol->varTypeGetter());
			temp->checkFunctionSetter(true);
			/*symtable.PrintAllScope(logout);*/
		}
#line 1488 "y.tab.c"
break;
case 13:
#line 269 "2005053.y"
	{   
			yyval.symbol = new SymbolInfo();
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier ID\n");
			yystack.l_mark[0].symbol->varTypeSetter(varType);
			yystack.l_mark[0].symbol->retTypeSetter(yystack.l_mark[-1].symbol->retTypeGetter());
			parameterList.push_back(yystack.l_mark[0].symbol);
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("parameter_list  : parameter_list COMMA type_specifier ID");
		    yyval.symbol->addChild({yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-3].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		}
#line 1504 "y.tab.c"
break;
case 14:
#line 282 "2005053.y"
	{
			yyval.symbol = new SymbolInfo();
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("parameter_list  : parameter_list COMMA type_specifier");
		    yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier\n");
		}
#line 1517 "y.tab.c"
break;
case 15:
#line 292 "2005053.y"
	{   
			yyval.symbol=new SymbolInfo();
			parameterList.clear();
			parameterList.push_back(yystack.l_mark[0].symbol);
			yystack.l_mark[0].symbol->varTypeSetter(varType);
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("parameter_list  : type_specifier ID");
		    yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier ID\n");

		}
#line 1534 "y.tab.c"
break;
case 16:
#line 306 "2005053.y"
	{   
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(varType);
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("parameter_list  : type_specifier");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier\n");
			
		}
#line 1549 "y.tab.c"
break;
case 17:
#line 321 "2005053.y"
	{   
				yyval.symbol= new SymbolInfo();
				obj.currSymbolSetter(yyval.symbol);
		        yyval.symbol->exprSetter("compound_statement : LCURL statements RCURL");
		        yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
				yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		        yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
				fprintf(logout,"compound_statement : LCURL statements RCURL\n");
				symtable.PrintAllScope(logout);
			}
#line 1563 "y.tab.c"
break;
case 18:
#line 332 "2005053.y"
	{
				 yyval.symbol=new SymbolInfo();
				 obj.currSymbolSetter(yyval.symbol);
		         yyval.symbol->exprSetter("compound_statement : LCURL RCURL");
		         yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
				 yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    	 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
				 fprintf(logout,"compound_statement : LCURL RCURL\n");
				 symtable.PrintAllScope(logout);
			}
#line 1577 "y.tab.c"
break;
case 19:
#line 345 "2005053.y"
	{   
				fprintf(logout,"var_declaration : type_specifier declaration_list SEMICOLON\n");
				yyval.symbol= new SymbolInfo();
				yyval.symbol->varTypeSetter(yystack.l_mark[-2].symbol->nameGetter());
				obj.currSymbolSetter(yyval.symbol);
		        yyval.symbol->exprSetter("var_declaration : type_specifier declaration_list SEMICOLON");
		        yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
				yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		        yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
				if(yystack.l_mark[-2].symbol->varTypeGetter()=="VOID")
				{
					for(SymbolInfo *sym:varDeclarationList)
					{
						fprintf(errorout,"Line# %d: Variable or field '%s' declared void\n",line_count,sym->nameGetter().c_str());
						symtable.Remove(sym->nameGetter());
						errors++;					
					}
				}
				varDeclarationList.clear();			
			}
#line 1601 "y.tab.c"
break;
case 20:
#line 368 "2005053.y"
	{	
			fprintf(logout,"type_specifier	: INT\n");
			yyval.symbol=new SymbolInfo();
			varType="INT";
			yyval.symbol->varTypeSetter("INT");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("type_specifier	: INT");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			store=line_count;
		}
#line 1617 "y.tab.c"
break;
case 21:
#line 381 "2005053.y"
	{
			fprintf(logout,"type_specifier	: FLOAT\n");
			yyval.symbol=new SymbolInfo();
			varType="FLOAT";
			yyval.symbol->varTypeSetter("FLOAT");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("type_specifier	: FLOAT");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			store=line_count;
		}
#line 1633 "y.tab.c"
break;
case 22:
#line 394 "2005053.y"
	{
			fprintf(logout,"type_specifier	: VOID\n");
			yyval.symbol=new SymbolInfo();
			varType="VOID";
			yyval.symbol->varTypeSetter("VOID");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("type_specifier	: VOID");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			store=line_count;
		}
#line 1649 "y.tab.c"
break;
case 23:
#line 409 "2005053.y"
	{ 
			yyval.symbol=new SymbolInfo();
			errorflag=symtable.Insert(yystack.l_mark[0].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[0].symbol->nameGetter());
			if(errorflag)
			{
				temp->varTypeSetter(varType);
			}	
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}	
			fprintf(logout,"declaration_list : declaration_list COMMA ID\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("declaration_list : declaration_list COMMA ID");
		    yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			/*symtable.PrintAllScope(logout);*/
        
		  }
#line 1677 "y.tab.c"
break;
case 24:
#line 434 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			errorflag=symtable.Insert(yystack.l_mark[-3].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[-3].symbol->nameGetter());
			if(errorflag)
			{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
			}	
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}
			fprintf(logout,"declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n");	
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");
		    yyval.symbol->addChild({yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});	
			yyval.symbol->startlineSetter(yystack.l_mark[-5].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());	
				
		  }
#line 1705 "y.tab.c"
break;
case 25:
#line 459 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			errorflag=symtable.Insert(yystack.l_mark[0].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[0].symbol->nameGetter());
			if(errorflag)
			{
				temp->varTypeSetter(varType);
			}
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}
			varDeclarationList.push_back(temp);
			fprintf(logout,"declaration_list : ID\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("declaration_list : ID");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});		
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			
			/*symtable.PrintAllScope(logout);*/
		  }
#line 1734 "y.tab.c"
break;
case 26:
#line 485 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			symtable.Insert(yystack.l_mark[-3].symbol->nameGetter(),"ID");
			temp=symtable.LookUp(yystack.l_mark[-3].symbol->nameGetter());
			if(errorflag)
			{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
			}
			fprintf(logout,"declaration_list : ID LSQUARE CONST_INT RSQUARE\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("declaration_list : ID LSQUARE CONST_INT RSQUARE");
		    yyval.symbol->addChild({yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-3].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());		
		  }
#line 1754 "y.tab.c"
break;
case 27:
#line 504 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			fprintf(logout,"statements : statement\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("statements : statement");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		}
#line 1767 "y.tab.c"
break;
case 28:
#line 514 "2005053.y"
	{
		    yyval.symbol=new SymbolInfo();
			fprintf(logout,"statements : statements statement\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("statements : statements statement");
		    yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());		
	   }
#line 1780 "y.tab.c"
break;
case 29:
#line 526 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : var_declaration");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});	
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : var_declaration\n");
	  }
#line 1793 "y.tab.c"
break;
case 30:
#line 536 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : expression_statement");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});	
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : expression_statement\n");
	  }
#line 1806 "y.tab.c"
break;
case 31:
#line 546 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : compound_statement");
		 yyval.symbol->addChild({yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : compound_statement\n");
	  }
#line 1819 "y.tab.c"
break;
case 32:
#line 556 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		 yyval.symbol->addChild({yystack.l_mark[-6].symbol,yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-6].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
	  }
#line 1832 "y.tab.c"
break;
case 33:
#line 566 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : IF LPAREN expression RPAREN statement");
		 yyval.symbol->addChild({yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-4].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement\n");
	  }
#line 1845 "y.tab.c"
break;
case 34:
#line 576 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : IF LPAREN expression RPAREN statement ELSE statement");
		 yyval.symbol->addChild({yystack.l_mark[-6].symbol,yystack.l_mark[-5].symbol,yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-6].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement ELSE statement\n");
	  }
#line 1858 "y.tab.c"
break;
case 35:
#line 586 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : WHILE LPAREN expression RPAREN statement");
		 yyval.symbol->addChild({yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-4].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : WHILE LPAREN expression RPAREN statement\n");
	  }
#line 1871 "y.tab.c"
break;
case 36:
#line 596 "2005053.y"
	{  
		 yyval.symbol=new SymbolInfo();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		 yyval.symbol->addChild({yystack.l_mark[-4].symbol,yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-4].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
	  }
#line 1884 "y.tab.c"
break;
case 37:
#line 606 "2005053.y"
	{
		 yyval.symbol=new SymbolInfo();
		 retType=yystack.l_mark[-1].symbol->varTypeGetter();
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("statement : RETURN expression SEMICOLON");
		 yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 fprintf(logout,"statement : RETURN expression SEMICOLON\n");
	  }
#line 1898 "y.tab.c"
break;
case 38:
#line 619 "2005053.y"
	{
				yyval.symbol=new SymbolInfo();
				obj.currSymbolSetter(yyval.symbol);
		 		yyval.symbol->exprSetter("expression_statement : SEMICOLON");
		 		yyval.symbol->addChild({yystack.l_mark[0].symbol});
				yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		   		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		        fprintf(logout,"expression_statement : SEMICOLON\n");
			 }
#line 1911 "y.tab.c"
break;
case 39:
#line 629 "2005053.y"
	{
				yyval.symbol=new SymbolInfo("","expression_statement");
				obj.currSymbolSetter(yyval.symbol);
		 		yyval.symbol->exprSetter("expression_statement : expression SEMICOLON");
		 		yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
				yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    	yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		        fprintf(logout,"expression_statement : expression SEMICOLON \n");
			}
#line 1924 "y.tab.c"
break;
case 40:
#line 641 "2005053.y"
	{  
		yyval.symbol=new SymbolInfo();
		temp=symtable.LookUp(yystack.l_mark[0].symbol->nameGetter());
		if(temp!=NULL)
		{
			yyval.symbol->varTypeSetter(temp->varTypeGetter());
		}
		else{
			fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,yystack.l_mark[0].symbol->nameGetter().c_str());
			errors++;
		}
		fprintf(logout,"variable : ID\n");
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("variable : ID");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());

	 }
#line 1947 "y.tab.c"
break;
case 41:
#line 661 "2005053.y"
	{  
		yyval.symbol=new SymbolInfo();
		temp=symtable.LookUp(yystack.l_mark[-3].symbol->nameGetter());
		if(temp!=NULL)
		{
			yyval.symbol->varTypeSetter(temp->varTypeGetter());
		}
		else{
			fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,yystack.l_mark[-3].symbol->nameGetter().c_str());
			errors++;
		}
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("variable : ID LSQUARE expression RSQUARE");
		yyval.symbol->addChild({yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-3].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"variable : ID LSQUARE expression RSQUARE\n");
	 }
#line 1969 "y.tab.c"
break;
case 42:
#line 682 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
		fprintf(logout,"expression : logic_expression\n");
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("expression : logic_expression	");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	   }
#line 1983 "y.tab.c"
break;
case 43:
#line 693 "2005053.y"
	{ 
		 yyval.symbol=new SymbolInfo();
		 yyval.symbol->varTypeSetter(yystack.l_mark[-2].symbol->varTypeGetter());
		 fprintf(logout,"expression : variable ASSIGNOP logic_expression\n");
		 obj.currSymbolSetter(yyval.symbol);
		 yyval.symbol->exprSetter("expression : variable ASSIGNOP logic_expression");
		 yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		 yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		 yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	   }
#line 1997 "y.tab.c"
break;
case 44:
#line 706 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("logic_expression : rel_expression");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression\n");

		 }
#line 2012 "y.tab.c"
break;
case 45:
#line 718 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[-2].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("logic_expression : rel_expression LOGICOP rel_expression");
		    yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression LOGICOP rel_expression\n");
		 }
#line 2026 "y.tab.c"
break;
case 46:
#line 731 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("rel_expression	: simple_expression");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression\n");
		}
#line 2040 "y.tab.c"
break;
case 47:
#line 742 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[-2].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("rel_expression	: simple_expression RELOP simple_expression");
		    yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression RELOP simple_expression\n");
		}
#line 2054 "y.tab.c"
break;
case 48:
#line 755 "2005053.y"
	{ 
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("simple_expression : term");
		    yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			fprintf(logout,"simple_expression : term\n");
		  }
#line 2068 "y.tab.c"
break;
case 49:
#line 766 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			fprintf(logout,"simple_expression : simple_expression ADDOP term\n");
			if(yystack.l_mark[-2].symbol->varTypeGetter()=="INT" && yystack.l_mark[0].symbol->varTypeGetter()=="INT")
			{
				yyval.symbol->varTypeSetter("INT");
			}
			else if(yystack.l_mark[-2].symbol->varTypeGetter()=="FLOAT" && yystack.l_mark[0].symbol->varTypeGetter()=="FLOAT")
			{
				yyval.symbol->varTypeSetter("FLOAT");
			}
			else if(yystack.l_mark[-2].symbol->varTypeGetter()=="VOID" ||yystack.l_mark[0].symbol->varTypeGetter()=="VOID")
		    {
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
		    }
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("simple_expression : simple_expression ADDOP term");
		    yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		  }
#line 2094 "y.tab.c"
break;
case 50:
#line 791 "2005053.y"
	{  
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("term :	unary_expression");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"term :	unary_expression\n");
	 }
#line 2108 "y.tab.c"
break;
case 51:
#line 802 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		fprintf(logout,"term : term MULOP unary_expression\n");
		if(yystack.l_mark[-2].symbol->varTypeGetter()=="INT" && yystack.l_mark[0].symbol->varTypeGetter()=="INT")
		{
			yyval.symbol->varTypeSetter("INT");
		}
		else if(yystack.l_mark[-2].symbol->varTypeGetter()=="FLOAT" && yystack.l_mark[0].symbol->varTypeGetter()=="FLOAT")
		{
			yyval.symbol->varTypeSetter("FLOAT");
		}
        else if(yystack.l_mark[-2].symbol->varTypeGetter()=="VOID" ||yystack.l_mark[0].symbol->varTypeGetter()=="VOID")
		{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
		}
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("term : term MULOP unary_expression");
		yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	 }
#line 2134 "y.tab.c"
break;
case 52:
#line 827 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			if(yystack.l_mark[0].symbol->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			}
		    fprintf(logout,"unary_expression : ADDOP unary_expression\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("unary_expression : ADDOP unary_expression");
			yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 }
#line 2155 "y.tab.c"
break;
case 53:
#line 845 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			if(yystack.l_mark[0].symbol->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			}
		    fprintf(logout,"unary_expression : NOT unary_expression\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("unary_expression : NOT unary_expression");
			yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 }
#line 2177 "y.tab.c"
break;
case 54:
#line 864 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			if(yystack.l_mark[0].symbol->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
			}

		    fprintf(logout,"unary_expression : factor\n");
			obj.currSymbolSetter(yyval.symbol);
		    yyval.symbol->exprSetter("unary_expression : factor");
			yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		 }
#line 2199 "y.tab.c"
break;
case 55:
#line 885 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->varTypeGetter());
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor	: variable");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"factor	: variable\n");
	}
#line 2213 "y.tab.c"
break;
case 56:
#line 896 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		temp=symtable.LookUp(yystack.l_mark[-3].symbol->nameGetter());
		if(temp!=NULL)
		{   
			temp->varTypeSetter(temp->retTypeGetter());
			
			if(parameterList.size()>temp->listOfParameter.size())
			{
				fprintf(errorout,"Line# %d: Too many arguments to function '%s'\n",line_count,yystack.l_mark[-3].symbol->nameGetter().c_str());
				errors++;
			}
			else if(parameterList.size()<temp->listOfParameter.size())
			{
				fprintf(errorout,"Line# %d: Too few arguments to function '%s'\n",line_count,yystack.l_mark[-3].symbol->nameGetter().c_str());
				errors++;
			}
			else {
				for(int i=0;i<parameterList.size();i++)
				{   
                    if(parameterList[i]->checkArrayGetter()!=temp->listOfParameter[i]->checkArrayGetter())
					{
						fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,yystack.l_mark[-3].symbol->nameGetter().c_str());
				        errors++;
					}
					else if(parameterList[i]->varTypeGetter()!=temp->listOfParameter[i]->varTypeGetter())
					{
						fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,yystack.l_mark[-3].symbol->nameGetter().c_str());
				        errors++;
					}
				}
			}

		}
		else{
			fprintf(errorout,"Line# %d: Undeclared function '%s'\n",line_count,yystack.l_mark[-3].symbol->nameGetter().c_str());
			errors++;
		}
		parameterList.clear();
		fprintf(logout,"factor : ID LPAREN argument_list RPAREN\n");
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : ID LPAREN argument_list RPAREN");
		yyval.symbol->addChild({yystack.l_mark[-3].symbol,yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->varTypeSetter(yystack.l_mark[-3].symbol->retTypeGetter());
		yyval.symbol->startlineSetter(yystack.l_mark[-3].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	}
#line 2264 "y.tab.c"
break;
case 57:
#line 944 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[-1].symbol->varTypeGetter());
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : LPAREN expression RPAREN");
		yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"factor : LPAREN expression RPAREN\n");
	}
#line 2278 "y.tab.c"
break;
case 58:
#line 955 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->typeGetter());
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : CONST_INT");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"factor : CONST_INT\n");
	}
#line 2292 "y.tab.c"
break;
case 59:
#line 966 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[0].symbol->typeGetter());
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : CONST_FLOAT");
		yyval.symbol->addChild({yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		fprintf(logout,"factor : CONST_FLOAT\n");
	}
#line 2306 "y.tab.c"
break;
case 60:
#line 977 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[-1].symbol->varTypeGetter());
		fprintf(logout,"factor : variable INCOP\n");
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : variable INCOP");
		yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	}
#line 2320 "y.tab.c"
break;
case 61:
#line 988 "2005053.y"
	{
		yyval.symbol=new SymbolInfo();
		yyval.symbol->varTypeSetter(yystack.l_mark[-1].symbol->varTypeGetter());
		fprintf(logout,"factor : variable DECOP\n");
		obj.currSymbolSetter(yyval.symbol);
		yyval.symbol->exprSetter("factor : variable DECOP");
		yyval.symbol->addChild({yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
		yyval.symbol->startlineSetter(yystack.l_mark[-1].symbol->startlineGetter());
		yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
	}
#line 2334 "y.tab.c"
break;
case 62:
#line 1001 "2005053.y"
	{
				yyval.symbol=new SymbolInfo();
		        fprintf(logout,"argument_list : arguments\n");
				obj.currSymbolSetter(yyval.symbol);
				yyval.symbol->exprSetter("argument_list : arguments");
				yyval.symbol->addChild({yystack.l_mark[0].symbol});
				yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		        yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
			  }
#line 2347 "y.tab.c"
break;
case 63:
#line 1010 "2005053.y"
	{ }
#line 2352 "y.tab.c"
break;
case 64:
#line 1014 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			parameterList.push_back(yystack.l_mark[0].symbol);
		    fprintf(logout,"arguments : arguments COMMA logic_expression\n");
			obj.currSymbolSetter(yyval.symbol);
			yyval.symbol->exprSetter("arguments : arguments COMMA logic_expression");
			yyval.symbol->addChild({yystack.l_mark[-2].symbol,yystack.l_mark[-1].symbol,yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[-2].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		  }
#line 2366 "y.tab.c"
break;
case 65:
#line 1025 "2005053.y"
	{
			yyval.symbol=new SymbolInfo();
			parameterList.push_back(yystack.l_mark[0].symbol);
		    fprintf(logout,"arguments : logic_expression\n");
			obj.currSymbolSetter(yyval.symbol);
			yyval.symbol->exprSetter("arguments : logic_expression");
			yyval.symbol->addChild({yystack.l_mark[0].symbol});
			yyval.symbol->startlineSetter(yystack.l_mark[0].symbol->startlineGetter());
		    yyval.symbol->endlineSetter(yystack.l_mark[0].symbol->endlineGetter());
		  }
#line 2380 "y.tab.c"
break;
#line 2382 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
