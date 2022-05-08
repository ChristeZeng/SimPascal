#pragma once

#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "../generator/CodeGenerator.h"

using namespace std;

enum Base_type {
    S_INT,
    S_REAL,
    S_CHAR,
    S_BOOLEN,
};

enum SysFunc {
    S_READ,
    S_WRITE,
    S_WRITELN,
    S_ADS,
    S_CHR,
    S_ODD,
    S_ORD,
    S_PRED,
    S_SQR,
    S_SQRT,
    S_SUCC,
};

enum Direction_type {
    S_TO,
    S_DOWNTO
};

enum Binary_op {
    S_PLUS,
    S_MINUS,
    S_MUL,
    S_DIV,
    S_MOD,
    S_AND,
    S_OR,
    S_GE,
    S_GT,
    S_LE,
    S_LT,
    S_EQ,
    S_NE,
    S_NOT,
};

class Node;
class Identifier;
class Expression;
class Stmt;
class CodeGenerator;
class Direction;
class Assign_stmt;
class Proc_stmt;
class If_stmt;
class Repeat_stmt;
class While_stmt;
class Case_stmt;
class Case_expr;
class Goto_stmt;
class For_stmt;
class Binary_expression;
class Expression;
class Stmt;
class Program;
class Program_head;
class Program_body;
class Routine;
class Routine_head;
class Routine_body;
class Function_head;
class Function_decl;
class Para_decl;
class Va_para_list;
class Type_part;
class Type_definition;
class Type_decl;
class Simple_type_decl;
class Array_type_decl;
class Record_type_decl;
class Const_range;
class Enum_range;
class Enum_Type;
class Var_part;
class Var_decl;
class Const_part;
class Const_expr;
class Const_value;

using Stmt_list = vector<Stmt *>;
using Name_list = vector<Identifier *>;

using Const_expr_list = vector<Const_expr *>;

using Routine_part = vector<Function_decl *>;
using Para_decl_list = vector<Para_decl *>;
using Para_type_list = vector<Simple_type_decl *>;

using Args_list = vector<Expression *>;
using Expression_list = vector<Expression *>;

using Stmt_list = vector<Stmt *>;
using Name_list = vector<Identifier *>;

using Type_decl_list = vector<Type_definition *>;
using Var_decl_list = vector<Var_decl *>;