/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "SimPascal.y"

using namespace std;

int yyerror(const char *s);
int yywrap(void);
extern int yylex(void);

#line 78 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "SimPascal.y"

#include "AST/AST.h"
#include <iostream>
#include <string>

Program *root;

#line 129 "parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    EQ = 259,
    NE = 260,
    LE = 261,
    LT = 262,
    GE = 263,
    GT = 264,
    PROGRAM = 265,
    CONST = 266,
    ARRAY = 267,
    VAR = 268,
    FUNCTION = 269,
    PROCEDURE = 270,
    PBEGIN = 271,
    END = 272,
    TYPE = 273,
    RECORD = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    REPEAT = 278,
    UNTIL = 279,
    WHILE = 280,
    DO = 281,
    FOR = 282,
    TO = 283,
    DOWNTO = 284,
    CASE = 285,
    OF = 286,
    GOTO = 287,
    PLUS = 288,
    MINUS = 289,
    MUL = 290,
    DIV = 291,
    MOD = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    DOT = 296,
    DOTDOT = 297,
    SEMI = 298,
    LP = 299,
    RP = 300,
    LS = 301,
    RS = 302,
    COMMA = 303,
    COLON = 304,
    PACKED = 305,
    INTEGER = 306,
    REAL = 307,
    ID = 308,
    SYS_CON = 309,
    SYS_FUNCT = 310,
    SYS_PROC = 311,
    SYS_TYPE = 312,
    READ = 313,
    CHAR = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "SimPascal.y"

    int ival;
    double dval;
    string *sval;
    char cval;

    Identifier *id;
    Name_list *name_list;
    Program *program;
    Program_head *program_head;
    Routine *routine;
    Routine_head *routine_head;
    Routine_body *routine_body;
    Const_part *const_part;
    Type_part *type_part;
    Var_part *var_part;
    Var_decl *var_decl;
    Var_decl_list *var_decl_list;
    Routine_part *routine_part;
    Const_expr_list *const_expr_list;
    Const_value *const_value;
    Type_decl_list *type_decl_list;
    Type_definition *type_definition;
    Type_decl *type_decl;
    Simple_type_decl *simple_type_decl;
    Array_type_decl *array_type_decl;
    Record_type_decl *record_type_decl;
    Field_decl_list *field_decl_list;
    Field_decl *field_decl;
    Function_decl *function_decl; 
    Function_head *function_head;
    Para_decl *para_type_list;
    Para_decl_list *para_decl_list;
    Va_para_list *val_para_list;
    Va_para_list *var_para_list;
    Stmt_list *stmt_list;
    Stmt *stmt;
    Expression *expression;
    Expression_list *expression_list;
    Direction *direction;
    Case_expr_list *case_expr_list;
    Case_expr *case_expr;
    Args_list *args_list;

#line 245 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   396

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   116,   119,   122,   125,   128,   131,   132,
     135,   136,   139,   140,   141,   142,   155,   156,   159,   160,
     163,   166,   167,   168,   171,   185,   186,   187,   188,   189,
     190,   193,   196,   199,   200,   203,   206,   207,   210,   211,
     214,   215,   218,   221,   222,   223,   224,   225,   228,   231,
     234,   237,   240,   241,   244,   245,   248,   249,   252,   255,
     258,   261,   264,   265,   268,   269,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   283,   284,   285,   288,   289,
     290,   296,   302,   307,   310,   311,   314,   317,   320,   323,
     324,   327,   330,   331,   334,   335,   338,   341,   342,   345,
     346,   347,   348,   349,   350,   351,   354,   355,   356,   357,
     360,   361,   362,   363,   364,   367,   368,   369,   387,   405,
     406,   407,   408,   409,   410,   413,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "EQ", "NE", "LE", "LT", "GE",
  "GT", "PROGRAM", "CONST", "ARRAY", "VAR", "FUNCTION", "PROCEDURE",
  "PBEGIN", "END", "TYPE", "RECORD", "IF", "THEN", "ELSE", "REPEAT",
  "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "OF", "GOTO",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "DOT",
  "DOTDOT", "SEMI", "LP", "RP", "LS", "RS", "COMMA", "COLON", "PACKED",
  "INTEGER", "REAL", "ID", "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE",
  "READ", "CHAR", "$accept", "name", "program", "program_head", "routine",
  "sub_routine", "routine_head", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,   -36,    43,    41,    31,  -136,    45,    55,    99,   101,
    -136,  -136,   117,    45,  -136,  -136,  -136,  -136,    45,   111,
     -12,   122,   234,   125,    45,  -136,    45,    15,  -136,  -136,
    -136,  -136,    91,   -12,  -136,   289,  -136,   289,    45,   289,
      84,    87,   102,   108,     0,  -136,   112,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   188,  -136,  -136,    34,
      45,  -136,    45,    45,    15,  -136,   118,  -136,   123,  -136,
     129,   289,   289,   289,   115,     7,  -136,   363,    38,   145,
    -136,   247,   351,   157,   308,  -136,   100,   289,   289,   289,
      45,   289,   289,  -136,   128,    45,   -12,    45,  -136,   134,
     135,   150,  -136,  -136,  -136,    45,   188,  -136,   151,   151,
    -136,  -136,    41,    41,  -136,  -136,  -136,   181,   289,    45,
     289,   289,   289,   289,   289,   289,   289,   289,   279,   289,
     289,   289,   289,   289,   289,   289,   289,   279,   289,   229,
    -136,   -43,   381,   133,   381,   194,   381,    10,    19,   160,
      14,  -136,    62,   156,    25,    45,   -12,  -136,  -136,   162,
       8,   161,  -136,   163,    99,   173,  -136,    33,  -136,    42,
      29,    38,    38,    38,    38,    38,    38,   177,   145,   145,
     145,  -136,  -136,  -136,  -136,   381,  -136,   345,   169,   174,
      88,  -136,  -136,   289,  -136,   289,  -136,   289,   221,   180,
    -136,  -136,   188,   116,  -136,  -136,  -136,  -136,    45,   186,
      17,  -136,   179,   195,   160,  -136,  -136,  -136,  -136,  -136,
    -136,   279,  -136,  -136,  -136,   289,   279,   279,  -136,  -136,
     381,   381,   381,   289,   198,   203,   -12,  -136,   186,     8,
    -136,   160,   160,  -136,  -136,   357,   205,   209,   381,   188,
    -136,  -136,  -136,  -136,  -136,   279,  -136,  -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,     0,    17,
       4,     2,     0,     8,     3,    63,     5,    60,     0,    39,
       0,     0,     0,     0,    16,    19,     0,    47,    12,    13,
      15,    14,     0,     0,    61,     0,    63,     0,     0,     0,
       0,     0,    80,     0,    78,    68,     0,    65,    66,    67,
      69,    70,    71,    72,    73,    74,     0,    18,    37,     0,
      38,    41,     0,     0,     7,    45,     0,    46,     0,    11,
       0,     0,     0,     0,   117,   115,   119,     0,   105,   109,
     114,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    24,    25,
       0,     0,    21,    22,    23,     0,     0,    40,    53,    53,
      43,    44,     9,     9,    10,   122,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    98,     0,    75,     0,   126,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    20,    36,     0,
       0,     0,    51,     0,     0,     0,   120,     0,   124,     0,
       0,   103,   104,   101,   102,    99,   100,    85,   106,   107,
     108,   110,   111,   112,   113,    86,    87,     0,     0,     0,
       0,    93,    81,     0,    82,     0,    79,     0,     0,     0,
      32,    33,     0,     0,    26,    30,    27,    42,     0,    59,
       0,    55,     0,     0,     0,    48,     6,    50,   118,   116,
     123,     0,    83,    89,    90,     0,     0,     0,    91,    92,
      97,    77,   125,     0,     0,     0,     0,    28,    58,     0,
      52,     0,     0,    49,    84,     0,     0,     0,    76,     0,
      35,    29,    54,    56,    57,     0,    95,    94,    31,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,    -6,  -136,  -136,  -136,   124,   250,  -136,  -136,   -11,
    -136,  -136,   231,   -98,  -135,  -136,  -136,  -136,   106,   -91,
    -136,  -136,   200,  -136,   201,  -136,   204,  -136,   149,  -136,
      23,  -136,  -136,   105,    -7,   237,  -118,   189,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,    86,  -136,
    -136,   -24,   269,   -37,    30,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,     2,     3,     7,   163,   164,     9,    13,    76,
      19,    24,    25,   101,   102,   103,   104,   150,   151,    59,
      27,    60,    61,    64,    65,    66,    67,    68,   161,   210,
     211,   212,   213,    16,    45,    22,    46,    47,    48,    49,
      50,   222,    51,    52,    53,   225,    54,   190,   191,    55,
     141,   146,    78,    79,    80,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    17,   192,    89,   152,   193,   154,    21,   159,    32,
     177,    77,    23,    82,   199,    84,    44,     4,    23,   186,
      58,   208,    70,   122,   123,   124,   125,   126,   127,    62,
      63,   200,    83,   122,   123,   124,   125,   126,   127,    28,
      29,    90,    30,     5,    91,   100,    92,    31,   119,   117,
      99,   120,     6,   121,    58,   196,   108,   109,   197,   152,
     239,    11,   240,   142,     1,   144,   198,    11,   148,   209,
     204,   129,   130,   105,    10,    44,   220,   131,   218,   243,
      44,   197,   105,   106,   145,   153,   167,   219,   169,    58,
     197,    58,   178,   179,   180,   100,    14,   170,    11,   158,
      99,   115,   116,   244,   235,   228,   253,   254,   246,   247,
     105,   202,   185,   168,   187,    15,    15,   238,   143,    18,
      35,    20,    44,    36,    26,    37,    33,    38,   189,    56,
      39,    44,    40,   188,    69,    85,    86,   259,   100,    28,
      29,    11,    30,    99,    58,   206,    87,    31,   209,   205,
     236,   258,    88,    11,    58,    93,    42,    17,    43,   118,
     138,   112,   181,   182,   183,   184,   113,    28,    29,   230,
      30,   231,   114,   232,   149,    31,   155,   156,   194,   189,
     132,   133,   134,   135,   188,   122,   123,   124,   125,   126,
     127,   100,   237,   157,    96,   160,    99,   195,   203,   221,
      94,   245,    58,   100,    97,   207,   215,    95,    99,   248,
     214,    28,    29,    11,    30,    44,   217,    98,   226,    31,
      44,    44,    96,   227,   233,   251,   166,   234,   241,   249,
     100,   100,    97,    58,   105,    99,    99,   165,   100,    28,
      29,    11,    30,    99,   242,    98,   250,    31,   256,    44,
      15,    34,   257,     8,    35,    57,   201,    36,   162,    37,
     107,    38,   252,    15,    39,   110,    40,    35,   111,   216,
      36,   136,    37,    81,    38,   140,   229,    39,     0,    40,
      28,    29,    11,    30,     0,    41,     0,    11,    31,     0,
      42,     0,    43,     0,     0,    15,     0,     0,    41,    35,
      11,     0,    36,    42,    37,    43,    38,     0,     0,    39,
       0,    40,   122,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,     0,    72,
      41,     0,    11,    73,     0,    42,     0,    43,     0,   139,
      28,    29,    11,    30,    74,     0,     0,     0,    31,   122,
     123,   124,   125,   126,   127,   122,   123,   124,   125,   126,
     127,   122,   123,   124,   125,   126,   127,   122,   123,   124,
     125,   126,   127,   223,   224,     0,     0,   137,     0,     0,
       0,     0,     0,   255,   128,   122,   123,   124,   125,   126,
     127,   171,   172,   173,   174,   175,   176
};

static const yytype_int16 yycheck[] =
{
       6,     8,    45,     3,    95,    48,    97,    13,   106,    20,
     128,    35,    18,    37,   149,    39,    22,    53,    24,   137,
      26,    13,    33,     4,     5,     6,     7,     8,     9,    14,
      15,    17,    38,     4,     5,     6,     7,     8,     9,    51,
      52,    41,    54,     0,    44,    56,    46,    59,    41,    73,
      56,    44,    11,    46,    60,    45,    62,    63,    48,   150,
      43,    53,    45,    87,    10,    89,    47,    53,    92,   160,
      45,    33,    34,    48,    43,    81,    47,    39,    45,   214,
      86,    48,    48,    49,    90,    96,   118,    45,   120,    95,
      48,    97,   129,   130,   131,   106,    41,   121,    53,   105,
     106,    71,    72,   221,   202,    17,   241,   242,   226,   227,
      48,    49,   136,   119,   138,    16,    16,   208,    88,    18,
      20,     4,   128,    23,    13,    25,     4,    27,   139,     4,
      30,   137,    32,   139,    43,    51,    49,   255,   149,    51,
      52,    53,    54,   149,   150,   156,    44,    59,   239,   155,
      34,   249,    44,    53,   160,    43,    56,   164,    58,    44,
       3,    43,   132,   133,   134,   135,    43,    51,    52,   193,
      54,   195,    43,   197,    46,    59,    42,    42,    45,   190,
      35,    36,    37,    38,   190,     4,     5,     6,     7,     8,
       9,   202,   203,    43,    34,    44,   202,     3,    42,    22,
      12,   225,   208,   214,    44,    43,    43,    19,   214,   233,
      49,    51,    52,    53,    54,   221,    43,    57,    49,    59,
     226,   227,    34,    49,     3,   236,    45,    47,    49,    31,
     241,   242,    44,   239,    48,   241,   242,   113,   249,    51,
      52,    53,    54,   249,    49,    57,    43,    59,    43,   255,
      16,    17,    43,     3,    20,    24,   150,    23,   109,    25,
      60,    27,   239,    16,    30,    64,    32,    20,    64,   164,
      23,    24,    25,    36,    27,    86,   190,    30,    -1,    32,
      51,    52,    53,    54,    -1,    51,    -1,    53,    59,    -1,
      56,    -1,    58,    -1,    -1,    16,    -1,    -1,    51,    20,
      53,    -1,    23,    56,    25,    58,    27,    -1,    -1,    30,
      -1,    32,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,
      51,    -1,    53,    44,    -1,    56,    -1,    58,    -1,    31,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,     4,
       5,     6,     7,     8,     9,     4,     5,     6,     7,     8,
       9,     4,     5,     6,     7,     8,     9,     4,     5,     6,
       7,     8,     9,    28,    29,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    26,    21,     4,     5,     6,     7,     8,
       9,   122,   123,   124,   125,   126,   127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    62,    63,    53,     0,    11,    64,    66,    67,
      43,    53,    61,    68,    41,    16,    93,    94,    18,    70,
       4,    61,    95,    61,    71,    72,    13,    80,    51,    52,
      54,    59,    69,     4,    17,    20,    23,    25,    27,    30,
      32,    51,    56,    58,    61,    94,    96,    97,    98,    99,
     100,   102,   103,   104,   106,   109,     4,    72,    61,    79,
      81,    82,    14,    15,    83,    84,    85,    86,    87,    43,
      69,    34,    40,    44,    55,    61,    69,   111,   112,   113,
     114,    95,   111,    61,   111,    51,    49,    44,    44,     3,
      41,    44,    46,    43,    12,    19,    34,    44,    57,    61,
      69,    73,    74,    75,    76,    48,    49,    82,    61,    61,
      84,    86,    43,    43,    43,   114,   114,   111,    44,    41,
      44,    46,     4,     5,     6,     7,     8,     9,    21,    33,
      34,    39,    35,    36,    37,    38,    24,    26,     3,    31,
      97,   110,   111,   114,   111,    61,   111,   115,   111,    46,
      77,    78,    79,    69,    79,    42,    42,    43,    61,    73,
      44,    88,    88,    65,    66,    65,    45,   115,    61,   115,
     111,   112,   112,   112,   112,   112,   112,    96,   113,   113,
     113,   114,   114,   114,   114,   111,    96,   111,    61,    69,
     107,   108,    45,    48,    45,     3,    45,    48,    47,    74,
      17,    78,    49,    42,    45,    61,    69,    43,    13,    79,
      89,    90,    91,    92,    49,    43,    93,    43,    45,    45,
      47,    22,   101,    28,    29,   105,    49,    49,    17,   108,
     111,   111,   111,     3,    47,    73,    34,    69,    79,    43,
      45,    49,    49,    74,    96,   111,    96,    96,   111,    31,
      43,    69,    90,    74,    74,    26,    43,    43,    73,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    84,    85,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   101,   101,   102,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     4,     2,     0,
       5,     4,     1,     1,     1,     1,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     3,     3,     4,     5,
       3,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     1,     1,     0,     4,     5,
       4,     3,     3,     0,     3,     1,     3,     3,     2,     1,
       1,     3,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 113 "SimPascal.y"
                     { (yyval.id) = new Identifier(*(yyvsp[0].sval)); }
#line 1635 "parser.cpp"
    break;

  case 3:
#line 116 "SimPascal.y"
                                           { (yyval.program) = new Program((yyvsp[-2].program_head), (yyvsp[-1].routine)); root = (yyval.program); }
#line 1641 "parser.cpp"
    break;

  case 4:
#line 119 "SimPascal.y"
                                  { (yyval.program_head) = new Program_head(*(yyvsp[-1].sval)); }
#line 1647 "parser.cpp"
    break;

  case 5:
#line 122 "SimPascal.y"
                                            { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 1653 "parser.cpp"
    break;

  case 6:
#line 125 "SimPascal.y"
                                            { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 1659 "parser.cpp"
    break;

  case 7:
#line 128 "SimPascal.y"
                                                             { (yyval.routine_head) = new Routine_head((yyvsp[-3].const_part), (yyvsp[-2].type_part), (yyvsp[-1].var_part), (yyvsp[0].routine_part)); }
#line 1665 "parser.cpp"
    break;

  case 8:
#line 131 "SimPascal.y"
                                        { (yyval.const_part) = new Const_part((yyvsp[0].const_expr_list)); }
#line 1671 "parser.cpp"
    break;

  case 9:
#line 132 "SimPascal.y"
                                        { (yyval.const_part) = nullptr; }
#line 1677 "parser.cpp"
    break;

  case 10:
#line 135 "SimPascal.y"
                                                           { (yyval.const_expr_list) = (yyvsp[-4].const_expr_list); (yyval.const_expr_list)->push_back(new Const_expr((yyvsp[-3].id), (yyvsp[-1].const_value))); }
#line 1683 "parser.cpp"
    break;

  case 11:
#line 136 "SimPascal.y"
                                                           { (yyval.const_expr_list) = new Const_expr_list(); (yyval.const_expr_list)->push_back(new Const_expr((yyvsp[-3].id), (yyvsp[-1].const_value))); }
#line 1689 "parser.cpp"
    break;

  case 12:
#line 139 "SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_INT, (yyvsp[0].ival)); }
#line 1695 "parser.cpp"
    break;

  case 13:
#line 140 "SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_REAL, (yyvsp[0].dval)); }
#line 1701 "parser.cpp"
    break;

  case 14:
#line 141 "SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_CHAR, (yyvsp[0].cval)); }
#line 1707 "parser.cpp"
    break;

  case 15:
#line 142 "SimPascal.y"
                          { 
                            if (*(yyvsp[0].sval) == "true") {
                                (yyval.const_value) = new Const_value(S_BOOLEN, true); 
                            }
                            else if (*(yyvsp[0].sval) == "false") {
                                (yyval.const_value) = new Const_value(S_BOOLEN, false);
                            }
                            else {
                                (yyval.const_value) = new Const_value(S_INT, 0x7FFFFFFF);
                            }
                          }
#line 1723 "parser.cpp"
    break;

  case 16:
#line 155 "SimPascal.y"
                                      { (yyval.type_part) = new Type_part((yyvsp[0].type_decl_list)); }
#line 1729 "parser.cpp"
    break;

  case 17:
#line 156 "SimPascal.y"
                                      { (yyval.type_part) = nullptr; }
#line 1735 "parser.cpp"
    break;

  case 18:
#line 159 "SimPascal.y"
                                                 { (yyval.type_decl_list) = (yyvsp[-1].type_decl_list); (yyval.type_decl_list)->push_back((yyvsp[0].type_definition)); }
#line 1741 "parser.cpp"
    break;

  case 19:
#line 160 "SimPascal.y"
                                                 { (yyval.type_decl_list) = new Type_decl_list(); (yyval.type_decl_list)->push_back((yyvsp[0].type_definition)); }
#line 1747 "parser.cpp"
    break;

  case 20:
#line 163 "SimPascal.y"
                                                 { (yyval.type_definition) = new Type_definition((yyvsp[-3].id), (yyvsp[-1].type_decl)); }
#line 1753 "parser.cpp"
    break;

  case 21:
#line 166 "SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].simple_type_decl)); }
#line 1759 "parser.cpp"
    break;

  case 22:
#line 167 "SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].array_type_decl)); }
#line 1765 "parser.cpp"
    break;

  case 23:
#line 168 "SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].record_type_decl)); }
#line 1771 "parser.cpp"
    break;

  case 24:
#line 171 "SimPascal.y"
                                                { 
                                                    if (*(yyvsp[0].sval) == "integer") {
                                                        (yyval.simple_type_decl) = new Simple_type_decl(S_INT);
                                                    } 
                                                    else if (*(yyvsp[0].sval) == "real") {
                                                        (yyval.simple_type_decl) = new Simple_type_decl(S_REAL);
                                                    }
                                                    else if (*(yyvsp[0].sval) == "char") {
                                                        (yyval.simple_type_decl) = new Simple_type_decl(S_CHAR);
                                                    }
                                                    else if (*(yyvsp[0].sval) == "boolean") {
                                                        (yyval.simple_type_decl) = new Simple_type_decl(S_BOOLEN);
                                                    }
                                                }
#line 1790 "parser.cpp"
    break;

  case 25:
#line 185 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl((yyvsp[0].id)); }
#line 1796 "parser.cpp"
    break;

  case 26:
#line 186 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Enum_Type((yyvsp[-1].name_list))); }
#line 1802 "parser.cpp"
    break;

  case 27:
#line 187 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range((yyvsp[-2].const_value), (yyvsp[0].const_value))); }
#line 1808 "parser.cpp"
    break;

  case 28:
#line 188 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range(-*(yyvsp[-2].const_value), (yyvsp[0].const_value))); }
#line 1814 "parser.cpp"
    break;

  case 29:
#line 189 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range(-*(yyvsp[-3].const_value), -*(yyvsp[0].const_value))); }
#line 1820 "parser.cpp"
    break;

  case 30:
#line 190 "SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Enum_range((yyvsp[-2].id), (yyvsp[0].id))); }
#line 1826 "parser.cpp"
    break;

  case 31:
#line 193 "SimPascal.y"
                                                                    { (yyval.array_type_decl) = new Array_type_decl((yyvsp[-3].simple_type_decl), (yyvsp[0].type_decl)); }
#line 1832 "parser.cpp"
    break;

  case 32:
#line 196 "SimPascal.y"
                                                                    { (yyval.record_type_decl) = new Record_type_decl((yyvsp[-1].field_decl_list)); }
#line 1838 "parser.cpp"
    break;

  case 33:
#line 199 "SimPascal.y"
                                                                    { (yyval.field_decl_list) = (yyvsp[-1].field_decl_list); (yyval.field_decl_list)->push_back((yyvsp[0].field_decl)); }
#line 1844 "parser.cpp"
    break;

  case 34:
#line 200 "SimPascal.y"
                                                                    { (yyval.field_decl_list) = new Field_decl_list(); (yyval.field_decl_list)->push_back((yyvsp[0].field_decl)); }
#line 1850 "parser.cpp"
    break;

  case 35:
#line 203 "SimPascal.y"
                                                                    { (yyval.field_decl) = new Field_decl((yyvsp[-3].name_list), (yyvsp[-1].type_decl)); }
#line 1856 "parser.cpp"
    break;

  case 36:
#line 206 "SimPascal.y"
                                                                      { (yyval.name_list) = (yyvsp[-2].name_list); (yyval.name_list)->push_back((yyvsp[0].id)); }
#line 1862 "parser.cpp"
    break;

  case 37:
#line 207 "SimPascal.y"
                                                                      { (yyval.name_list) = new Name_list(); (yyval.name_list)->push_back((yyvsp[0].id)); }
#line 1868 "parser.cpp"
    break;

  case 38:
#line 210 "SimPascal.y"
                                                                    { (yyval.var_part) = new Var_part((yyvsp[0].var_decl_list)); }
#line 1874 "parser.cpp"
    break;

  case 39:
#line 211 "SimPascal.y"
                                                                    { (yyval.var_part) = nullptr; }
#line 1880 "parser.cpp"
    break;

  case 40:
#line 214 "SimPascal.y"
                                                                    { (yyval.var_decl_list) = (yyvsp[-1].var_decl_list); (yyval.var_decl_list)->push_back((yyvsp[0].var_decl)); }
#line 1886 "parser.cpp"
    break;

  case 41:
#line 215 "SimPascal.y"
                                                                    { (yyval.var_decl_list) = new Var_decl_list(); (yyval.var_decl_list)->push_back((yyvsp[0].var_decl)); }
#line 1892 "parser.cpp"
    break;

  case 42:
#line 218 "SimPascal.y"
                                                                    { (yyval.var_decl) = new Var_decl((yyvsp[-3].name_list), (yyvsp[-1].type_decl)); }
#line 1898 "parser.cpp"
    break;

  case 43:
#line 221 "SimPascal.y"
                                                                    { (yyval.routine_part) = (yyvsp[-1].routine_part); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1904 "parser.cpp"
    break;

  case 44:
#line 222 "SimPascal.y"
                                                                    { (yyval.routine_part) = (yyvsp[-1].routine_part); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1910 "parser.cpp"
    break;

  case 45:
#line 223 "SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1916 "parser.cpp"
    break;

  case 46:
#line 224 "SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1922 "parser.cpp"
    break;

  case 47:
#line 225 "SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); }
#line 1928 "parser.cpp"
    break;

  case 48:
#line 228 "SimPascal.y"
                                                                    { (yyval.function_decl) = new Function_decl((yyvsp[-3].function_head), (yyvsp[-1].routine)); }
#line 1934 "parser.cpp"
    break;

  case 49:
#line 231 "SimPascal.y"
                                                                    { (yyval.function_head) = new Function_head((yyvsp[-3].id), (yyvsp[-2].para_decl_list), (yyvsp[0].simple_type_decl)); }
#line 1940 "parser.cpp"
    break;

  case 50:
#line 234 "SimPascal.y"
                                                                    { (yyval.function_decl) = new Function_decl((yyvsp[-3].function_head), (yyvsp[-1].routine)); }
#line 1946 "parser.cpp"
    break;

  case 51:
#line 237 "SimPascal.y"
                                                                    { (yyval.function_head) = new Function_head((yyvsp[-1].id), (yyvsp[0].para_decl_list)); }
#line 1952 "parser.cpp"
    break;

  case 52:
#line 240 "SimPascal.y"
                                                                    { (yyval.para_decl_list) = (yyvsp[-1].para_decl_list); }
#line 1958 "parser.cpp"
    break;

  case 53:
#line 241 "SimPascal.y"
                                                                    { (yyval.para_decl_list) = new Para_decl_list(); }
#line 1964 "parser.cpp"
    break;

  case 54:
#line 244 "SimPascal.y"
                                                                    { (yyval.para_decl_list) = (yyvsp[-2].para_decl_list); (yyval.para_decl_list)->push_back((yyvsp[0].para_type_list)); }
#line 1970 "parser.cpp"
    break;

  case 55:
#line 245 "SimPascal.y"
                                                                    { (yyval.para_decl_list) = new Para_decl_list(); (yyval.para_decl_list)->push_back((yyvsp[0].para_type_list)); }
#line 1976 "parser.cpp"
    break;

  case 56:
#line 248 "SimPascal.y"
                                                                    { (yyval.para_type_list) = new Para_decl((yyvsp[-2].var_para_list), (yyvsp[0].simple_type_decl)); }
#line 1982 "parser.cpp"
    break;

  case 57:
#line 249 "SimPascal.y"
                                                                    { (yyval.para_type_list) = new Para_decl((yyvsp[-2].val_para_list), (yyvsp[0].simple_type_decl)); }
#line 1988 "parser.cpp"
    break;

  case 58:
#line 252 "SimPascal.y"
                                                                    { (yyval.var_para_list) = new Va_para_list((yyvsp[0].name_list), true); }
#line 1994 "parser.cpp"
    break;

  case 59:
#line 255 "SimPascal.y"
                                                                    { (yyval.val_para_list) = new Va_para_list((yyvsp[0].name_list), false); }
#line 2000 "parser.cpp"
    break;

  case 60:
#line 258 "SimPascal.y"
                                                                    { (yyval.routine_body) = (yyvsp[0].routine_body); }
#line 2006 "parser.cpp"
    break;

  case 61:
#line 261 "SimPascal.y"
                                                                     { (yyval.routine_body) = new Routine_body((yyvsp[-1].stmt_list)); }
#line 2012 "parser.cpp"
    break;

  case 62:
#line 264 "SimPascal.y"
                                                                    { (yyval.stmt_list) = (yyvsp[-2].stmt_list); (yyval.stmt_list)->push_back((yyvsp[-1].stmt)); }
#line 2018 "parser.cpp"
    break;

  case 63:
#line 265 "SimPascal.y"
                                                                    { (yyval.stmt_list) = new Stmt_list(); }
#line 2024 "parser.cpp"
    break;

  case 64:
#line 268 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); (yyvsp[0].stmt)->Setlabel((yyvsp[-2].ival)); }
#line 2030 "parser.cpp"
    break;

  case 65:
#line 269 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2036 "parser.cpp"
    break;

  case 66:
#line 272 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2042 "parser.cpp"
    break;

  case 67:
#line 273 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2048 "parser.cpp"
    break;

  case 68:
#line 274 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].routine_body); }
#line 2054 "parser.cpp"
    break;

  case 69:
#line 275 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2060 "parser.cpp"
    break;

  case 70:
#line 276 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2066 "parser.cpp"
    break;

  case 71:
#line 277 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2072 "parser.cpp"
    break;

  case 72:
#line 278 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2078 "parser.cpp"
    break;

  case 73:
#line 279 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2084 "parser.cpp"
    break;

  case 74:
#line 280 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2090 "parser.cpp"
    break;

  case 75:
#line 283 "SimPascal.y"
                                                                      { (yyval.stmt) = new Assign_stmt((yyvsp[-2].id), (yyvsp[0].expression)); }
#line 2096 "parser.cpp"
    break;

  case 76:
#line 284 "SimPascal.y"
                                                                      { (yyval.stmt) = new Assign_stmt((yyvsp[-5].id), (yyvsp[-3].expression), (yyvsp[0].expression)); }
#line 2102 "parser.cpp"
    break;

  case 77:
#line 285 "SimPascal.y"
                                                                        { (yyval.stmt) = new Assign_stmt((yyvsp[-4].id), (yyvsp[0].expression), (yyvsp[-2].id)); }
#line 2108 "parser.cpp"
    break;

  case 78:
#line 288 "SimPascal.y"
                                                                      { (yyval.stmt) = new Proc_stmt((yyvsp[0].id)); }
#line 2114 "parser.cpp"
    break;

  case 79:
#line 289 "SimPascal.y"
                                                                      { (yyval.stmt) = new Proc_stmt((yyvsp[-3].id), (yyvsp[-1].args_list)); }
#line 2120 "parser.cpp"
    break;

  case 80:
#line 290 "SimPascal.y"
                                                                    {
                                                                        if (*(yyvsp[0].sval) == "write")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITE); 
                                                                        else if (*(yyvsp[0].sval) == "writeln") 
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITELN);
                                                                    }
#line 2131 "parser.cpp"
    break;

  case 81:
#line 296 "SimPascal.y"
                                                                    { 
                                                                        if (*(yyvsp[-3].sval) == "write")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITE, (yyvsp[-1].expression_list)); 
                                                                        else if (*(yyvsp[-3].sval) == "writeln")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITELN, (yyvsp[-1].expression_list));
                                                                    }
#line 2142 "parser.cpp"
    break;

  case 82:
#line 302 "SimPascal.y"
                                                                    { 
                                                                        (yyval.stmt) = new Sysproc_stmt(S_READ, (yyvsp[-1].expression)); 
                                                                    }
#line 2150 "parser.cpp"
    break;

  case 83:
#line 307 "SimPascal.y"
                                                                    { (yyval.stmt) = new If_stmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].stmt)); }
#line 2156 "parser.cpp"
    break;

  case 84:
#line 310 "SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2162 "parser.cpp"
    break;

  case 85:
#line 311 "SimPascal.y"
                                                                    { (yyval.stmt) = nullptr; }
#line 2168 "parser.cpp"
    break;

  case 86:
#line 314 "SimPascal.y"
                                                                    { (yyval.stmt) = new Repeat_stmt((yyvsp[-2].stmt_list), (yyvsp[0].expression)); }
#line 2174 "parser.cpp"
    break;

  case 87:
#line 317 "SimPascal.y"
                                                                    { (yyval.stmt) = new While_stmt((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2180 "parser.cpp"
    break;

  case 88:
#line 320 "SimPascal.y"
                                                                              { (yyval.stmt) = new For_stmt((yyvsp[-6].id), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2186 "parser.cpp"
    break;

  case 89:
#line 323 "SimPascal.y"
                                                { (yyval.direction) = new Direction(S_TO); }
#line 2192 "parser.cpp"
    break;

  case 90:
#line 324 "SimPascal.y"
                                                { (yyval.direction) = new Direction(S_DOWNTO); }
#line 2198 "parser.cpp"
    break;

  case 91:
#line 327 "SimPascal.y"
                                                                        { (yyval.stmt) = new Case_stmt((yyvsp[-3].expression), (yyvsp[-1].case_expr_list)); }
#line 2204 "parser.cpp"
    break;

  case 92:
#line 330 "SimPascal.y"
                                                                        { (yyval.case_expr_list) = (yyvsp[-1].case_expr_list); (yyval.case_expr_list)->push_back((yyvsp[0].case_expr)); }
#line 2210 "parser.cpp"
    break;

  case 93:
#line 331 "SimPascal.y"
                                                                        { (yyval.case_expr_list) = new Case_expr_list(); (yyval.case_expr_list)->push_back((yyvsp[0].case_expr)); }
#line 2216 "parser.cpp"
    break;

  case 94:
#line 334 "SimPascal.y"
                                                                        { (yyval.case_expr) = new Case_expr((yyvsp[-3].const_value), (yyvsp[-1].stmt)); }
#line 2222 "parser.cpp"
    break;

  case 95:
#line 335 "SimPascal.y"
                                                                          { (yyval.case_expr) = new Case_expr((yyvsp[-3].id), (yyvsp[-1].stmt)); }
#line 2228 "parser.cpp"
    break;

  case 96:
#line 338 "SimPascal.y"
                                                                        { (yyval.stmt) = new Goto_stmt((yyvsp[0].ival)); }
#line 2234 "parser.cpp"
    break;

  case 97:
#line 341 "SimPascal.y"
                                                                        { (yyval.expression_list) = (yyvsp[-2].expression_list); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 2240 "parser.cpp"
    break;

  case 98:
#line 342 "SimPascal.y"
                                                                        { (yyval.expression_list) = new Expression_list(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 2246 "parser.cpp"
    break;

  case 99:
#line 345 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_GE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2252 "parser.cpp"
    break;

  case 100:
#line 346 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_GT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2258 "parser.cpp"
    break;

  case 101:
#line 347 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_LE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2264 "parser.cpp"
    break;

  case 102:
#line 348 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_LT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2270 "parser.cpp"
    break;

  case 103:
#line 349 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_EQ, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2276 "parser.cpp"
    break;

  case 104:
#line 350 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_NE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2282 "parser.cpp"
    break;

  case 105:
#line 351 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2288 "parser.cpp"
    break;

  case 106:
#line 354 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_PLUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2294 "parser.cpp"
    break;

  case 107:
#line 355 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MINUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2300 "parser.cpp"
    break;

  case 108:
#line 356 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2306 "parser.cpp"
    break;

  case 109:
#line 357 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2312 "parser.cpp"
    break;

  case 110:
#line 360 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2318 "parser.cpp"
    break;

  case 111:
#line 361 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2324 "parser.cpp"
    break;

  case 112:
#line 362 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2330 "parser.cpp"
    break;

  case 113:
#line 363 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2336 "parser.cpp"
    break;

  case 114:
#line 364 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2342 "parser.cpp"
    break;

  case 115:
#line 367 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].id); }
#line 2348 "parser.cpp"
    break;

  case 116:
#line 368 "SimPascal.y"
                                                                        { (yyval.expression) = new Func_stmt((yyvsp[-3].id), (yyvsp[-1].args_list)); }
#line 2354 "parser.cpp"
    break;

  case 117:
#line 369 "SimPascal.y"
                                                                        {
                                                                            if (*(yyvsp[0].sval) == "ads")  
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ADS);
                                                                            else if (*(yyvsp[0].sval) == "chr")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_CHR);
                                                                            else if (*(yyvsp[0].sval) == "odd")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ODD);
                                                                            else if (*(yyvsp[0].sval) == "ord")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ORD); 
                                                                            else if (*(yyvsp[0].sval) == "pred")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_PRED);
                                                                            else if (*(yyvsp[0].sval) == "sqr")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SQR);
                                                                            else if (*(yyvsp[0].sval) == "sqrt")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SQRT);
                                                                            else if (*(yyvsp[0].sval) == "succ")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SUCC);
                                                                        }
#line 2377 "parser.cpp"
    break;

  case 118:
#line 387 "SimPascal.y"
                                                                        {
                                                                            if (*(yyvsp[-3].sval) == "ads")  
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ADS, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "chr")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_CHR, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "odd")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ODD, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "ord")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_ORD, (yyvsp[-1].args_list)); 
                                                                            else if (*(yyvsp[-3].sval) == "pred")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_PRED, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "sqr")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SQR, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "sqrt")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SQRT, (yyvsp[-1].args_list));
                                                                            else if (*(yyvsp[-3].sval) == "succ")
                                                                                (yyval.expression) = new Sysfunc_stmt(S_SUCC, (yyvsp[-1].args_list));
                                                                        }
#line 2400 "parser.cpp"
    break;

  case 119:
#line 405 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].const_value); }
#line 2406 "parser.cpp"
    break;

  case 120:
#line 406 "SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 2412 "parser.cpp"
    break;

  case 121:
#line 407 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_NOT, new Const_value(S_BOOLEN, true), (yyvsp[0].expression)); }
#line 2418 "parser.cpp"
    break;

  case 122:
#line 408 "SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MINUS, new Const_value(S_INT, 0), (yyvsp[0].expression)); }
#line 2424 "parser.cpp"
    break;

  case 123:
#line 409 "SimPascal.y"
                                                                          { (yyval.expression) = new Array_access((yyvsp[-3].id), (yyvsp[-1].expression)); }
#line 2430 "parser.cpp"
    break;

  case 124:
#line 410 "SimPascal.y"
                                                                            { (yyval.expression) = new Record_access((yyvsp[-2].id), (yyvsp[0].id)); }
#line 2436 "parser.cpp"
    break;

  case 125:
#line 413 "SimPascal.y"
                                                                        { (yyval.args_list) = (yyvsp[-2].args_list); (yyval.args_list)->push_back((yyvsp[0].expression)); }
#line 2442 "parser.cpp"
    break;

  case 126:
#line 414 "SimPascal.y"
                                                                        { (yyval.args_list) = new Args_list(); (yyval.args_list)->push_back((yyvsp[0].expression)); }
#line 2448 "parser.cpp"
    break;


#line 2452 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 417 "SimPascal.y"


int yyerror(const char *s) {
    printf("%s\n", s);
    return 0;
}

int yywrap() { 
   return 1;
}
