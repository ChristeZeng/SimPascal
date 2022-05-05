#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

#include "Node.h"
#include "Const.h"
using namespace std;

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

using Args_list = vector<Expression *>;
using Expression_list = vector<Expression *>;

class Assign_stmt : public Stmt {
private:
    Identifier *lid;
    Expression *lexpression;
    Expression *rexpression;
    Identifier *fid;
public:
    Assign_stmt(Identifier *lid, Expression *rexpression) : lid(lid), rexpression(rexpression) {}
    Assign_stmt(Identifier *lid, Expression *lexpression, Expression *rexpression) : lid(lid), lexpression(lexpression), rexpression(rexpression) {}
    Assign_stmt(Identifier *lid, Expression *rexpression, Identifier *fid) : lid(lid), rexpression(rexpression), fid(fid) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Proc_stmt : public Stmt {
private:
    Identifier *id;
    Args_list *args_list;
public:
    Proc_stmt(Identifier *id) : id(id) {}
    Proc_stmt(Identifier *id, Args_list *args_list) : id(id), args_list(args_list) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Sysproc_stmt : public Stmt {
private:
    SysFunc func;
    Args_list *args_list;
public:
    Sysproc_stmt(SysFunc func) : func(func) {}
    Sysproc_stmt(SysFunc func, Args_list *args_list) : func(func), args_list(args_list) {}
    Sysproc_stmt(SysFunc func, Expression *expression) : func(func) {
        this->args_list = new Args_list();
        this->args_list->push_back(expression);
    }
    llvm::Value *codegen(CodeGenerator &generator);
};

class Func_stmt : public Expression {
private:
    Identifier *id;
    Args_list *args_list;
public:
    Func_stmt(Identifier *id) : id(id) {}
    Func_stmt(Identifier *id, Args_list *args_list) : id(id), args_list(args_list) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Sysfunc_stmt : public Expression {
private:
    SysFunc func;
    Args_list *args_list;
public:
    Sysfunc_stmt(SysFunc func) : func(func) {}
    Sysfunc_stmt(SysFunc func, Args_list *args_list) : func(func), args_list(args_list) {}
    llvm::Value *codegen(CodeGenerator &generator);
};



class If_stmt : public Stmt {
private:
    Expression *expression;
    Stmt *stmt;
    Stmt *else_stmt;
public:
    If_stmt(Expression *expression, Stmt *stmt) : expression(expression), stmt(stmt) {}
    If_stmt(Expression *expression, Stmt *stmt, Stmt *else_stmt) : expression(expression), stmt(stmt), else_stmt(else_stmt) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Repeat_stmt : public Stmt {
private:
    Stmt_list *stmt_list;
    Expression *expression;
public:
    Repeat_stmt(Stmt_list *stmt_list, Expression *expression) : stmt_list(stmt_list), expression(expression) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class While_stmt : public Stmt {
private:
    Expression *expression;
    Stmt *stmt;
public:
    While_stmt(Expression *expression, Stmt *stmt) : expression(expression), stmt(stmt) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Direction : public Node {
private:
    Direction_type direction_type;
public:
    Direction(Direction_type direction_type) : direction_type(direction_type) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Case_expr : public Node {
private:
    Const_value *const_value;
    Identifier *id;
    Stmt *stmt;
public:
    Case_expr(Const_value *const_value, Stmt *stmt) : const_value(const_value), stmt(stmt) {}
    Case_expr(Identifier *id, Stmt *stmt) : id(id), stmt(stmt) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

using Case_expr_list = vector<Case_expr *>;

class Case_stmt : public Stmt {
private:
    Expression *expression;
    Case_expr_list *case_exper_list;
public:
    Case_stmt(Expression *expression, Case_expr_list *case_exper_list) : expression(expression), case_exper_list(case_exper_list) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Goto_stmt : public Stmt {
private:
    int label;
public:
    Goto_stmt(int label) : label(label) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class For_stmt : public Stmt {
private:
    Identifier *id;
    Expression *Out_expression;
    Direction *direction;
    Expression *In_expression;
    Stmt *stmt;
public:
    For_stmt(Identifier *id, Expression *Out_expression, Direction *direction, Expression *In_expression, Stmt *stmt)
        : id(id), Out_expression(Out_expression), direction(direction), In_expression(In_expression), stmt(stmt) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Binary_expression : public Expression {
private:
    Binary_op op;
    Expression *lexpression;
    Expression *rexpression;
public:
    Binary_expression(Binary_op op, Expression *lexpression, Expression *rexpression) : op(op), lexpression(lexpression), rexpression(rexpression) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Array_access : public Expression {
private:
    Identifier *id;
    Expression *index;
public:
    Array_access(Identifier *id, Expression *index) : id(id), index(index) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Record_access : public Expression {
private:
    Identifier *id;
    Identifier *field_id;
public:
    Record_access(Identifier *id, Identifier *field_id) : id(id), field_id(field_id) {}
    llvm::Value *codegen(CodeGenerator &generator);
};