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
#line 11 "/home/bcct/code/SimPascal/SimPascal.y"

int yyerror(const char *s);
int yywrap(void);
extern int yylex(void);

#line 76 "parser.cpp"

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
#line 1 "/home/bcct/code/SimPascal/SimPascal.y"

#include "AST/AST.h"
#include "generator/CodeGenerator.h"
#include <iostream>
#include <string>
extern Program *root;
using namespace std;


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
/* Tokens.  */
#define ASSIGN 258
#define EQ 259
#define NE 260
#define LE 261
#define LT 262
#define GE 263
#define GT 264
#define PROGRAM 265
#define CONST 266
#define ARRAY 267
#define VAR 268
#define FUNCTION 269
#define PROCEDURE 270
#define PBEGIN 271
#define END 272
#define TYPE 273
#define RECORD 274
#define IF 275
#define THEN 276
#define ELSE 277
#define REPEAT 278
#define UNTIL 279
#define WHILE 280
#define DO 281
#define FOR 282
#define TO 283
#define DOWNTO 284
#define CASE 285
#define OF 286
#define GOTO 287
#define PLUS 288
#define MINUS 289
#define MUL 290
#define DIV 291
#define MOD 292
#define AND 293
#define OR 294
#define NOT 295
#define DOT 296
#define DOTDOT 297
#define SEMI 298
#define LP 299
#define RP 300
#define LS 301
#define RS 302
#define COMMA 303
#define COLON 304
#define PACKED 305
#define INTEGER 306
#define REAL 307
#define ID 308
#define SYS_CON 309
#define SYS_FUNCT 310
#define SYS_PROC 311
#define SYS_TYPE 312
#define READ 313
#define CHAR 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "/home/bcct/code/SimPascal/SimPascal.y"

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

#line 303 "parser.cpp"

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
#define YYLAST   424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

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
     276,   277,   278,   279,   280,   283,   284,   285,   286,   289,
     290,   291,   297,   303,   308,   311,   312,   315,   318,   321,
     324,   325,   328,   331,   332,   335,   336,   339,   342,   343,
     346,   347,   348,   349,   350,   351,   352,   355,   356,   357,
     358,   361,   362,   363,   364,   365,   368,   369,   370,   388,
     406,   407,   408,   409,   410,   411,   412,   415,   416
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

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -40,    41,    48,    26,  -121,    21,    38,    67,    70,
    -121,  -121,    81,    21,  -121,  -121,  -121,  -121,    21,    95,
     104,   111,   241,   113,    21,  -121,    21,    82,  -121,  -121,
    -121,  -121,    77,   104,  -121,   305,  -121,   305,    21,   305,
      85,    83,    94,   102,    19,  -121,   108,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,   118,  -121,  -121,    61,
      21,  -121,    21,    21,    82,  -121,   110,  -121,   116,  -121,
     117,   305,   305,   305,   103,   -17,  -121,   391,    28,    91,
    -121,   256,   379,   158,   236,  -121,   288,   305,   305,   305,
      21,   305,   305,  -121,   122,    21,   104,    21,  -121,   131,
     132,   121,  -121,  -121,  -121,    21,   118,  -121,   134,   134,
    -121,  -121,    48,    48,  -121,  -121,  -121,   328,   305,    21,
     305,   305,   305,   305,   305,   305,   305,   305,   273,   305,
     305,   305,   305,   305,   305,   305,   305,   273,   305,   196,
    -121,   -34,   409,   138,   409,   182,   409,   -20,    30,   317,
     -13,  -121,    92,   144,     7,    21,   104,  -121,  -121,   154,
     -10,   149,  -121,   156,    67,   160,  -121,    33,  -121,    45,
      40,    28,    28,    28,    28,    28,    28,   179,    91,    91,
      91,  -121,  -121,  -121,  -121,   409,  -121,   373,   155,   157,
     128,  -121,  -121,   305,  -121,   305,  -121,   305,    12,   169,
    -121,  -121,   118,    60,  -121,  -121,  -121,  -121,    21,   159,
     -12,  -121,   168,   170,   317,  -121,  -121,  -121,  -121,  -121,
     172,   273,  -121,  -121,  -121,   305,   273,   273,  -121,  -121,
     409,   409,   409,   305,   305,   174,   184,   104,  -121,   159,
     -10,  -121,   317,   317,  -121,   305,  -121,   385,   187,   188,
     409,   186,   118,  -121,  -121,  -121,  -121,  -121,   205,   273,
    -121,  -121,   222,  -121,  -121,  -121,   305,   409
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,     0,    17,
       4,     2,     0,     8,     3,    63,     5,    60,     0,    39,
       0,     0,     0,     0,    16,    19,     0,    47,    12,    13,
      15,    14,     0,     0,    61,     0,    63,     0,     0,     0,
       0,     0,    81,     0,    79,    68,     0,    65,    66,    67,
      69,    70,    71,    72,    73,    74,     0,    18,    37,     0,
      38,    41,     0,     0,     7,    45,     0,    46,     0,    11,
       0,     0,     0,     0,   118,   116,   120,     0,   106,   110,
     115,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    24,    25,
       0,     0,    21,    22,    23,     0,     0,    40,    53,    53,
      43,    44,     9,     9,    10,   123,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    99,     0,    75,     0,   128,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    20,    36,     0,
       0,     0,    51,     0,     0,     0,   121,     0,   126,     0,
       0,   104,   105,   102,   103,   100,   101,    86,   107,   108,
     109,   111,   112,   113,   114,    87,    88,     0,     0,     0,
       0,    94,    82,     0,    83,     0,    80,     0,     0,     0,
      32,    33,     0,     0,    26,    30,    27,    42,     0,    59,
       0,    55,     0,     0,     0,    48,     6,    50,   119,   117,
     124,     0,    84,    90,    91,     0,     0,     0,    92,    93,
      98,    78,   127,     0,     0,     0,     0,     0,    28,    58,
       0,    52,     0,     0,    49,     0,    85,     0,     0,     0,
      76,     0,     0,    35,    29,    54,    56,    57,     0,     0,
      96,    95,     0,    31,   125,    89,     0,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,    -6,  -121,  -121,  -121,   119,   232,  -121,  -121,   -14,
    -121,  -121,   215,  -104,  -119,  -121,  -121,  -121,   101,   -74,
    -121,  -121,   199,  -121,   192,  -121,   201,  -121,   151,  -121,
      35,  -121,  -121,   105,    -7,   234,  -120,   191,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,    88,  -121,
    -121,    29,   297,   -26,   -62,   -67
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
      12,    17,   159,   208,   200,     1,    32,    21,   177,   115,
     116,   192,    23,     4,   193,   233,    44,   186,    23,    70,
      58,   152,    89,   154,   119,   196,   143,   120,   197,   121,
     199,   240,    83,   241,   122,   123,   124,   125,   126,   127,
      11,     5,   100,    11,   122,   123,   124,   125,   126,   127,
      99,   167,   204,   169,    58,   105,   108,   109,   234,     6,
      90,   129,   130,    91,    77,    92,    82,   131,    84,    10,
     181,   182,   183,   184,    11,    44,   152,   198,   218,    14,
      44,   197,   153,    15,   145,    20,   209,   220,    18,    58,
     219,    58,   100,   197,   237,   244,    62,    63,   236,   158,
      99,   246,   117,   178,   179,   180,   248,   249,    26,   105,
     106,    28,    29,   168,    30,    33,   142,    56,   144,    31,
      69,   148,    44,   256,   257,   189,   132,   133,   134,   135,
      94,    44,    86,   188,   239,   100,    85,    95,    87,   265,
     105,   202,   206,    99,    58,   228,    88,   118,   263,   205,
     170,    93,    96,   112,    58,    28,    29,    17,    30,   113,
     114,   138,    97,    31,   157,   185,   209,   187,   149,    28,
      29,    11,    30,   155,   156,    98,   189,    31,   160,    28,
      29,    11,    30,   194,   188,   195,   203,    31,   100,   238,
     122,   123,   124,   125,   126,   127,    99,   207,   214,   215,
     100,   221,    58,   217,   226,   252,   227,   105,    99,   122,
     123,   124,   125,   126,   127,    44,   235,   242,   245,   243,
      44,    44,   230,   254,   231,   266,   232,   253,   100,   100,
     260,   261,   165,   262,    58,     8,    99,    99,   100,    57,
     122,   123,   124,   125,   126,   127,    99,    28,    29,    11,
      30,   201,   264,    44,   247,    31,   110,    15,    34,   107,
     162,    35,   250,   251,    36,   111,    37,   139,    38,   216,
      81,    39,    15,    40,   258,   255,    35,   140,   229,    36,
     136,    37,     0,    38,     0,     0,    39,     0,    40,    15,
       0,     0,    41,    35,    11,   267,    36,    42,    37,    43,
      38,     0,     0,    39,    15,    40,     0,    41,    35,    11,
       0,    36,    42,    37,    43,    38,     0,     0,    39,     0,
      40,     0,     0,     0,    41,     0,    11,     0,     0,    42,
       0,    43,   122,   123,   124,   125,   126,   127,     0,    71,
       0,    11,     0,     0,    42,    72,    43,     0,     0,    73,
       0,    96,     0,     0,     0,     0,    28,    29,    11,    30,
      74,    97,     0,     0,    31,     0,     0,     0,    28,    29,
      11,    30,     0,   166,    98,     0,    31,   122,   123,   124,
     125,   126,   127,   122,   123,   124,   125,   126,   127,   122,
     123,   124,   125,   126,   127,   122,   123,   124,   125,   126,
     127,   223,   224,     0,     0,   137,     0,     0,     0,     0,
       0,   259,   128,   122,   123,   124,   125,   126,   127,   171,
     172,   173,   174,   175,   176
};

static const yytype_int16 yycheck[] =
{
       6,     8,   106,    13,    17,    10,    20,    13,   128,    71,
      72,    45,    18,    53,    48,     3,    22,   137,    24,    33,
      26,    95,     3,    97,    41,    45,    88,    44,    48,    46,
     149,    43,    38,    45,     4,     5,     6,     7,     8,     9,
      53,     0,    56,    53,     4,     5,     6,     7,     8,     9,
      56,   118,    45,   120,    60,    48,    62,    63,    46,    11,
      41,    33,    34,    44,    35,    46,    37,    39,    39,    43,
     132,   133,   134,   135,    53,    81,   150,    47,    45,    41,
      86,    48,    96,    16,    90,     4,   160,    47,    18,    95,
      45,    97,   106,    48,    34,   214,    14,    15,   202,   105,
     106,   221,    73,   129,   130,   131,   226,   227,    13,    48,
      49,    51,    52,   119,    54,     4,    87,     4,    89,    59,
      43,    92,   128,   242,   243,   139,    35,    36,    37,    38,
      12,   137,    49,   139,   208,   149,    51,    19,    44,   259,
      48,    49,   156,   149,   150,    17,    44,    44,   252,   155,
     121,    43,    34,    43,   160,    51,    52,   164,    54,    43,
      43,     3,    44,    59,    43,   136,   240,   138,    46,    51,
      52,    53,    54,    42,    42,    57,   190,    59,    44,    51,
      52,    53,    54,    45,   190,     3,    42,    59,   202,   203,
       4,     5,     6,     7,     8,     9,   202,    43,    49,    43,
     214,    22,   208,    43,    49,    31,    49,    48,   214,     4,
       5,     6,     7,     8,     9,   221,    47,    49,    46,    49,
     226,   227,   193,   237,   195,     3,   197,    43,   242,   243,
      43,    43,   113,    47,   240,     3,   242,   243,   252,    24,
       4,     5,     6,     7,     8,     9,   252,    51,    52,    53,
      54,   150,    47,   259,   225,    59,    64,    16,    17,    60,
     109,    20,   233,   234,    23,    64,    25,    31,    27,   164,
      36,    30,    16,    32,   245,   240,    20,    86,   190,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    32,    16,
      -1,    -1,    51,    20,    53,   266,    23,    56,    25,    58,
      27,    -1,    -1,    30,    16,    32,    -1,    51,    20,    53,
      -1,    23,    56,    25,    58,    27,    -1,    -1,    30,    -1,
      32,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      -1,    58,     4,     5,     6,     7,     8,     9,    -1,    34,
      -1,    53,    -1,    -1,    56,    40,    58,    -1,    -1,    44,
      -1,    34,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    44,    -1,    -1,    59,    -1,    -1,    -1,    51,    52,
      53,    54,    -1,    45,    57,    -1,    59,     4,     5,     6,
       7,     8,     9,     4,     5,     6,     7,     8,     9,     4,
       5,     6,     7,     8,     9,     4,     5,     6,     7,     8,
       9,    28,    29,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    26,    21,     4,     5,     6,     7,     8,     9,   122,
     123,   124,   125,   126,   127
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
     111,   111,   111,     3,    46,    47,    73,    34,    69,    79,
      43,    45,    49,    49,    74,    46,    96,   111,    96,    96,
     111,   111,    31,    43,    69,    90,    74,    74,   111,    26,
      43,    43,    47,    73,    47,    96,     3,   111
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
      97,    97,    97,    97,    97,    98,    98,    98,    98,    99,
      99,    99,    99,    99,   100,   101,   101,   102,   103,   104,
     105,   105,   106,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115
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
       1,     1,     1,     1,     1,     3,     6,     9,     5,     1,
       4,     1,     4,     4,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     7,     3,     3,     1
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
#line 113 "/home/bcct/code/SimPascal/SimPascal.y"
                     { (yyval.id) = new Identifier(*(yyvsp[0].sval)); }
#line 1702 "parser.cpp"
    break;

  case 3:
#line 116 "/home/bcct/code/SimPascal/SimPascal.y"
                                           { (yyval.program) = new Program((yyvsp[-2].program_head), (yyvsp[-1].routine)); root = (yyval.program);}
#line 1708 "parser.cpp"
    break;

  case 4:
#line 119 "/home/bcct/code/SimPascal/SimPascal.y"
                                  { (yyval.program_head) = new Program_head(*(yyvsp[-1].sval)); }
#line 1714 "parser.cpp"
    break;

  case 5:
#line 122 "/home/bcct/code/SimPascal/SimPascal.y"
                                            { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 1720 "parser.cpp"
    break;

  case 6:
#line 125 "/home/bcct/code/SimPascal/SimPascal.y"
                                            { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 1726 "parser.cpp"
    break;

  case 7:
#line 128 "/home/bcct/code/SimPascal/SimPascal.y"
                                                             { (yyval.routine_head) = new Routine_head((yyvsp[-3].const_part), (yyvsp[-2].type_part), (yyvsp[-1].var_part), (yyvsp[0].routine_part)); }
#line 1732 "parser.cpp"
    break;

  case 8:
#line 131 "/home/bcct/code/SimPascal/SimPascal.y"
                                        { (yyval.const_part) = new Const_part((yyvsp[0].const_expr_list)); }
#line 1738 "parser.cpp"
    break;

  case 9:
#line 132 "/home/bcct/code/SimPascal/SimPascal.y"
                                        { (yyval.const_part) = nullptr; }
#line 1744 "parser.cpp"
    break;

  case 10:
#line 135 "/home/bcct/code/SimPascal/SimPascal.y"
                                                           { (yyval.const_expr_list) = (yyvsp[-4].const_expr_list); (yyval.const_expr_list)->push_back(new Const_expr((yyvsp[-3].id), (yyvsp[-1].const_value))); }
#line 1750 "parser.cpp"
    break;

  case 11:
#line 136 "/home/bcct/code/SimPascal/SimPascal.y"
                                                           { (yyval.const_expr_list) = new Const_expr_list(); (yyval.const_expr_list)->push_back(new Const_expr((yyvsp[-3].id), (yyvsp[-1].const_value))); }
#line 1756 "parser.cpp"
    break;

  case 12:
#line 139 "/home/bcct/code/SimPascal/SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_INT, (yyvsp[0].ival)); }
#line 1762 "parser.cpp"
    break;

  case 13:
#line 140 "/home/bcct/code/SimPascal/SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_REAL, (yyvsp[0].dval)); }
#line 1768 "parser.cpp"
    break;

  case 14:
#line 141 "/home/bcct/code/SimPascal/SimPascal.y"
                          { (yyval.const_value) = new Const_value(S_CHAR, (yyvsp[0].cval)); }
#line 1774 "parser.cpp"
    break;

  case 15:
#line 142 "/home/bcct/code/SimPascal/SimPascal.y"
                          { 
                            if (*(yyvsp[0].sval) == "true") {
                                (yyval.const_value) = new Const_value(S_BOOLEAN, true); 
                            }
                            else if (*(yyvsp[0].sval) == "false") {
                                (yyval.const_value) = new Const_value(S_BOOLEAN, false);
                            }
                            else {
                                (yyval.const_value) = new Const_value(S_INT, 0x7FFFFFFF);
                            }
                          }
#line 1790 "parser.cpp"
    break;

  case 16:
#line 155 "/home/bcct/code/SimPascal/SimPascal.y"
                                      { (yyval.type_part) = new Type_part((yyvsp[0].type_decl_list)); }
#line 1796 "parser.cpp"
    break;

  case 17:
#line 156 "/home/bcct/code/SimPascal/SimPascal.y"
                                      { (yyval.type_part) = nullptr; }
#line 1802 "parser.cpp"
    break;

  case 18:
#line 159 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_decl_list) = (yyvsp[-1].type_decl_list); (yyval.type_decl_list)->push_back((yyvsp[0].type_definition)); }
#line 1808 "parser.cpp"
    break;

  case 19:
#line 160 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_decl_list) = new Type_decl_list(); (yyval.type_decl_list)->push_back((yyvsp[0].type_definition)); }
#line 1814 "parser.cpp"
    break;

  case 20:
#line 163 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_definition) = new Type_definition((yyvsp[-3].id), (yyvsp[-1].type_decl)); }
#line 1820 "parser.cpp"
    break;

  case 21:
#line 166 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].simple_type_decl)); }
#line 1826 "parser.cpp"
    break;

  case 22:
#line 167 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].array_type_decl)); }
#line 1832 "parser.cpp"
    break;

  case 23:
#line 168 "/home/bcct/code/SimPascal/SimPascal.y"
                                                 { (yyval.type_decl) = new Type_decl((yyvsp[0].record_type_decl)); }
#line 1838 "parser.cpp"
    break;

  case 24:
#line 171 "/home/bcct/code/SimPascal/SimPascal.y"
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
                                                    else if (*(yyvsp[0].sval) == "boolen") {
                                                        (yyval.simple_type_decl) = new Simple_type_decl(S_BOOLEAN);
                                                    }
                                                }
#line 1857 "parser.cpp"
    break;

  case 25:
#line 185 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl((yyvsp[0].id)); }
#line 1863 "parser.cpp"
    break;

  case 26:
#line 186 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Enum_Type((yyvsp[-1].name_list))); }
#line 1869 "parser.cpp"
    break;

  case 27:
#line 187 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range((yyvsp[-2].const_value), (yyvsp[0].const_value))); }
#line 1875 "parser.cpp"
    break;

  case 28:
#line 188 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range(-*(yyvsp[-2].const_value), (yyvsp[0].const_value))); }
#line 1881 "parser.cpp"
    break;

  case 29:
#line 189 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Const_range(-*(yyvsp[-3].const_value), -*(yyvsp[0].const_value))); }
#line 1887 "parser.cpp"
    break;

  case 30:
#line 190 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.simple_type_decl) = new Simple_type_decl(new Enum_range((yyvsp[-2].id), (yyvsp[0].id))); }
#line 1893 "parser.cpp"
    break;

  case 31:
#line 193 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.array_type_decl) = new Array_type_decl((yyvsp[-3].simple_type_decl), (yyvsp[0].type_decl)); }
#line 1899 "parser.cpp"
    break;

  case 32:
#line 196 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.record_type_decl) = new Record_type_decl((yyvsp[-1].field_decl_list)); }
#line 1905 "parser.cpp"
    break;

  case 33:
#line 199 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.field_decl_list) = (yyvsp[-1].field_decl_list); (yyval.field_decl_list)->push_back((yyvsp[0].field_decl)); }
#line 1911 "parser.cpp"
    break;

  case 34:
#line 200 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.field_decl_list) = new Field_decl_list(); (yyval.field_decl_list)->push_back((yyvsp[0].field_decl)); }
#line 1917 "parser.cpp"
    break;

  case 35:
#line 203 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.field_decl) = new Field_decl((yyvsp[-3].name_list), (yyvsp[-1].type_decl)); }
#line 1923 "parser.cpp"
    break;

  case 36:
#line 206 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.name_list) = (yyvsp[-2].name_list); (yyval.name_list)->push_back((yyvsp[0].id)); }
#line 1929 "parser.cpp"
    break;

  case 37:
#line 207 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.name_list) = new Name_list(); (yyval.name_list)->push_back((yyvsp[0].id)); }
#line 1935 "parser.cpp"
    break;

  case 38:
#line 210 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_part) = new Var_part((yyvsp[0].var_decl_list)); }
#line 1941 "parser.cpp"
    break;

  case 39:
#line 211 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_part) = nullptr; }
#line 1947 "parser.cpp"
    break;

  case 40:
#line 214 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_decl_list) = (yyvsp[-1].var_decl_list); (yyval.var_decl_list)->push_back((yyvsp[0].var_decl)); }
#line 1953 "parser.cpp"
    break;

  case 41:
#line 215 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_decl_list) = new Var_decl_list(); (yyval.var_decl_list)->push_back((yyvsp[0].var_decl)); }
#line 1959 "parser.cpp"
    break;

  case 42:
#line 218 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_decl) = new Var_decl((yyvsp[-3].name_list), (yyvsp[-1].type_decl)); }
#line 1965 "parser.cpp"
    break;

  case 43:
#line 221 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_part) = (yyvsp[-1].routine_part); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1971 "parser.cpp"
    break;

  case 44:
#line 222 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_part) = (yyvsp[-1].routine_part); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1977 "parser.cpp"
    break;

  case 45:
#line 223 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1983 "parser.cpp"
    break;

  case 46:
#line 224 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); (yyval.routine_part)->push_back((yyvsp[0].function_decl)); }
#line 1989 "parser.cpp"
    break;

  case 47:
#line 225 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_part) = new Routine_part(); }
#line 1995 "parser.cpp"
    break;

  case 48:
#line 228 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.function_decl) = new Function_decl((yyvsp[-3].function_head), (yyvsp[-1].routine)); }
#line 2001 "parser.cpp"
    break;

  case 49:
#line 231 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.function_head) = new Function_head((yyvsp[-3].id), (yyvsp[-2].para_decl_list), (yyvsp[0].simple_type_decl)); }
#line 2007 "parser.cpp"
    break;

  case 50:
#line 234 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.function_decl) = new Function_decl((yyvsp[-3].function_head), (yyvsp[-1].routine)); }
#line 2013 "parser.cpp"
    break;

  case 51:
#line 237 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.function_head) = new Function_head((yyvsp[-1].id), (yyvsp[0].para_decl_list)); }
#line 2019 "parser.cpp"
    break;

  case 52:
#line 240 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_decl_list) = (yyvsp[-1].para_decl_list); }
#line 2025 "parser.cpp"
    break;

  case 53:
#line 241 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_decl_list) = new Para_decl_list(); }
#line 2031 "parser.cpp"
    break;

  case 54:
#line 244 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_decl_list) = (yyvsp[-2].para_decl_list); (yyval.para_decl_list)->push_back((yyvsp[0].para_type_list)); }
#line 2037 "parser.cpp"
    break;

  case 55:
#line 245 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_decl_list) = new Para_decl_list(); (yyval.para_decl_list)->push_back((yyvsp[0].para_type_list)); }
#line 2043 "parser.cpp"
    break;

  case 56:
#line 248 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_type_list) = new Para_decl((yyvsp[-2].var_para_list), (yyvsp[0].simple_type_decl)); }
#line 2049 "parser.cpp"
    break;

  case 57:
#line 249 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.para_type_list) = new Para_decl((yyvsp[-2].val_para_list), (yyvsp[0].simple_type_decl)); }
#line 2055 "parser.cpp"
    break;

  case 58:
#line 252 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.var_para_list) = new Va_para_list((yyvsp[0].name_list), true); }
#line 2061 "parser.cpp"
    break;

  case 59:
#line 255 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.val_para_list) = new Va_para_list((yyvsp[0].name_list), false); }
#line 2067 "parser.cpp"
    break;

  case 60:
#line 258 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.routine_body) = (yyvsp[0].routine_body); }
#line 2073 "parser.cpp"
    break;

  case 61:
#line 261 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                     { (yyval.routine_body) = new Routine_body((yyvsp[-1].stmt_list)); }
#line 2079 "parser.cpp"
    break;

  case 62:
#line 264 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt_list) = (yyvsp[-2].stmt_list); (yyval.stmt_list)->push_back((yyvsp[-1].stmt)); }
#line 2085 "parser.cpp"
    break;

  case 63:
#line 265 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt_list) = new Stmt_list(); }
#line 2091 "parser.cpp"
    break;

  case 64:
#line 268 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); (yyvsp[0].stmt)->Setlabel((yyvsp[-2].ival)); }
#line 2097 "parser.cpp"
    break;

  case 65:
#line 269 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2103 "parser.cpp"
    break;

  case 66:
#line 272 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2109 "parser.cpp"
    break;

  case 67:
#line 273 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2115 "parser.cpp"
    break;

  case 68:
#line 274 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].routine_body); }
#line 2121 "parser.cpp"
    break;

  case 69:
#line 275 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2127 "parser.cpp"
    break;

  case 70:
#line 276 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2133 "parser.cpp"
    break;

  case 71:
#line 277 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2139 "parser.cpp"
    break;

  case 72:
#line 278 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2145 "parser.cpp"
    break;

  case 73:
#line 279 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2151 "parser.cpp"
    break;

  case 74:
#line 280 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2157 "parser.cpp"
    break;

  case 75:
#line 283 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.stmt) = new Assign_stmt((yyvsp[-2].id), (yyvsp[0].expression)); }
#line 2163 "parser.cpp"
    break;

  case 76:
#line 284 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.stmt) = new Assign_stmt((yyvsp[-5].id), (yyvsp[-3].expression), (yyvsp[0].expression)); }
#line 2169 "parser.cpp"
    break;

  case 77:
#line 285 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                           { (yyval.stmt) = new Assign_stmt((yyvsp[-8].id), (yyvsp[-6].expression), (yyvsp[-3].expression), (yyvsp[0].expression)); }
#line 2175 "parser.cpp"
    break;

  case 78:
#line 286 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.stmt) = new Assign_stmt((yyvsp[-4].id), (yyvsp[0].expression), (yyvsp[-2].id)); }
#line 2181 "parser.cpp"
    break;

  case 79:
#line 289 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.stmt) = new Proc_stmt((yyvsp[0].id)); }
#line 2187 "parser.cpp"
    break;

  case 80:
#line 290 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                      { (yyval.stmt) = new Proc_stmt((yyvsp[-3].id), (yyvsp[-1].args_list)); }
#line 2193 "parser.cpp"
    break;

  case 81:
#line 291 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    {
                                                                        if (*(yyvsp[0].sval) == "write")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITE); 
                                                                        else if (*(yyvsp[0].sval) == "writeln") 
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITELN);
                                                                    }
#line 2204 "parser.cpp"
    break;

  case 82:
#line 297 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { 
                                                                        if (*(yyvsp[-3].sval) == "write")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITE, (yyvsp[-1].expression_list)); 
                                                                        else if (*(yyvsp[-3].sval) == "writeln")
                                                                            (yyval.stmt) = new Sysproc_stmt(S_WRITELN, (yyvsp[-1].expression_list));
                                                                    }
#line 2215 "parser.cpp"
    break;

  case 83:
#line 303 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { 
                                                                        (yyval.stmt) = new Sysproc_stmt(S_READ, (yyvsp[-1].expression)); 
                                                                    }
#line 2223 "parser.cpp"
    break;

  case 84:
#line 308 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = new If_stmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].stmt)); }
#line 2229 "parser.cpp"
    break;

  case 85:
#line 311 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2235 "parser.cpp"
    break;

  case 86:
#line 312 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = nullptr; }
#line 2241 "parser.cpp"
    break;

  case 87:
#line 315 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = new Repeat_stmt((yyvsp[-2].stmt_list), (yyvsp[0].expression)); }
#line 2247 "parser.cpp"
    break;

  case 88:
#line 318 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                    { (yyval.stmt) = new While_stmt((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2253 "parser.cpp"
    break;

  case 89:
#line 321 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                              { (yyval.stmt) = new For_stmt((yyvsp[-6].id), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2259 "parser.cpp"
    break;

  case 90:
#line 324 "/home/bcct/code/SimPascal/SimPascal.y"
                                                { (yyval.direction) = new Direction(S_TO); }
#line 2265 "parser.cpp"
    break;

  case 91:
#line 325 "/home/bcct/code/SimPascal/SimPascal.y"
                                                { (yyval.direction) = new Direction(S_DOWNTO); }
#line 2271 "parser.cpp"
    break;

  case 92:
#line 328 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.stmt) = new Case_stmt((yyvsp[-3].expression), (yyvsp[-1].case_expr_list)); }
#line 2277 "parser.cpp"
    break;

  case 93:
#line 331 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.case_expr_list) = (yyvsp[-1].case_expr_list); (yyval.case_expr_list)->push_back((yyvsp[0].case_expr)); }
#line 2283 "parser.cpp"
    break;

  case 94:
#line 332 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.case_expr_list) = new Case_expr_list(); (yyval.case_expr_list)->push_back((yyvsp[0].case_expr)); }
#line 2289 "parser.cpp"
    break;

  case 95:
#line 335 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.case_expr) = new Case_expr((yyvsp[-3].const_value), (yyvsp[-1].stmt)); }
#line 2295 "parser.cpp"
    break;

  case 96:
#line 336 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                          { (yyval.case_expr) = new Case_expr((yyvsp[-3].id), (yyvsp[-1].stmt)); }
#line 2301 "parser.cpp"
    break;

  case 97:
#line 339 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.stmt) = new Goto_stmt((yyvsp[0].ival)); }
#line 2307 "parser.cpp"
    break;

  case 98:
#line 342 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression_list) = (yyvsp[-2].expression_list); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 2313 "parser.cpp"
    break;

  case 99:
#line 343 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression_list) = new Expression_list(); (yyval.expression_list)->push_back((yyvsp[0].expression)); }
#line 2319 "parser.cpp"
    break;

  case 100:
#line 346 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_GE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2325 "parser.cpp"
    break;

  case 101:
#line 347 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_GT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2331 "parser.cpp"
    break;

  case 102:
#line 348 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_LE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2337 "parser.cpp"
    break;

  case 103:
#line 349 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_LT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2343 "parser.cpp"
    break;

  case 104:
#line 350 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_EQ, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2349 "parser.cpp"
    break;

  case 105:
#line 351 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_NE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2355 "parser.cpp"
    break;

  case 106:
#line 352 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2361 "parser.cpp"
    break;

  case 107:
#line 355 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_PLUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2367 "parser.cpp"
    break;

  case 108:
#line 356 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MINUS, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2373 "parser.cpp"
    break;

  case 109:
#line 357 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2379 "parser.cpp"
    break;

  case 110:
#line 358 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2385 "parser.cpp"
    break;

  case 111:
#line 361 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2391 "parser.cpp"
    break;

  case 112:
#line 362 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2397 "parser.cpp"
    break;

  case 113:
#line 363 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2403 "parser.cpp"
    break;

  case 114:
#line 364 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2409 "parser.cpp"
    break;

  case 115:
#line 365 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2415 "parser.cpp"
    break;

  case 116:
#line 368 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].id); }
#line 2421 "parser.cpp"
    break;

  case 117:
#line 369 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Func_stmt((yyvsp[-3].id), (yyvsp[-1].args_list)); }
#line 2427 "parser.cpp"
    break;

  case 118:
#line 370 "/home/bcct/code/SimPascal/SimPascal.y"
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
#line 2450 "parser.cpp"
    break;

  case 119:
#line 388 "/home/bcct/code/SimPascal/SimPascal.y"
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
#line 2473 "parser.cpp"
    break;

  case 120:
#line 406 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[0].const_value); }
#line 2479 "parser.cpp"
    break;

  case 121:
#line 407 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 2485 "parser.cpp"
    break;

  case 122:
#line 408 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_NOT, new Const_value(S_BOOLEAN, true), (yyvsp[0].expression)); }
#line 2491 "parser.cpp"
    break;

  case 123:
#line 409 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Binary_expression(S_MINUS, new Const_value(S_INT, 0), (yyvsp[0].expression)); }
#line 2497 "parser.cpp"
    break;

  case 124:
#line 410 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Array_access((yyvsp[-3].id), (yyvsp[-1].expression)); }
#line 2503 "parser.cpp"
    break;

  case 125:
#line 411 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Array_access((yyvsp[-6].id), (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 2509 "parser.cpp"
    break;

  case 126:
#line 412 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.expression) = new Record_access((yyvsp[-2].id), (yyvsp[0].id)); }
#line 2515 "parser.cpp"
    break;

  case 127:
#line 415 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.args_list) = (yyvsp[-2].args_list); (yyval.args_list)->push_back((yyvsp[0].expression)); }
#line 2521 "parser.cpp"
    break;

  case 128:
#line 416 "/home/bcct/code/SimPascal/SimPascal.y"
                                                                        { (yyval.args_list) = new Args_list(); (yyval.args_list)->push_back((yyvsp[0].expression)); }
#line 2527 "parser.cpp"
    break;


#line 2531 "parser.cpp"

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
#line 419 "/home/bcct/code/SimPascal/SimPascal.y"


int yyerror(const char *s) {
    printf("%s\n", s);
    return 0;
}

int yywrap() { 
   return 1;
}
