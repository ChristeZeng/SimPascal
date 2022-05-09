/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 1 "/home/phoenix/CS/compiler/SimPascal/SimPascal.y"

#include "AST/AST.h"
#include "generator/CodeGenerator.h"
#include <iostream>
#include <string>
extern Program *root;
using namespace std;


#line 58 "parser.hpp"

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
#line 17 "/home/phoenix/CS/compiler/SimPascal/SimPascal.y"

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

#line 232 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
