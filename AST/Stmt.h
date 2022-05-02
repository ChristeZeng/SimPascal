#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

#include "Node.h"

using namespace std;

class Stmt;
class Expression;
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

using Stmt_list = vector<Stmt *>;
using Args_list = vector<Expression *>;


class Stmt : public Node {
private:
    int label = -1;

public:
    virtual llvm::Value *codegen() = 0;
};

class Expression : public Node {};


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
    llvm::Value *codegen();
};

/*系统调用还未考虑*/
class Proc_stmt : public Stmt {
private:
    Identifier *id;
    Args_list *args_list;
public:
    Proc_stmt(Identifier *id) : id(id) {}
    Proc_stmt(Identifier *id, Args_list *args_list) : id(id), args_list(args_list) {}
    llvm::Value *codegen();
};

class If_stmt : public Stmt {
private:
    Expression *expression;
    Stmt *stmt;
    Stmt *else_stmt;
public:
    If_stmt(Expression *expression, Stmt *stmt) : expression(expression), stmt(stmt) {}
    If_stmt(Expression *expression, Stmt *stmt, Stmt *else_stmt) : expression(expression), stmt(stmt), else_stmt(else_stmt) {}
    llvm::Value *codegen();
};

class Repeat_stmt : public Stmt {
private:
    Stmt_list *stmt_list;
    Expression *expression;
public:
    Repeat_stmt(Stmt_list *stmt_list, Expression *expression) : stmt_list(stmt_list), expression(expression) {}
    llvm::Value *codegen();
};

class While_stmt : public Stmt {
private:
    Expression *expression;
    Stmt *stmt;
public:
    While_stmt(Expression *expression, Stmt *stmt) : expression(expression), stmt(stmt) {}
    llvm::Value *codegen();
};

class Direction : public Node {
private:
    enum Direction_type {
        TO,
        DOWNTO
    } type;
public:
    Direction(Direction_type type) : type(type) {}
};

class Case_expr : public Node {
private:
    Const_expr *const_expr;
    Identifier *id;
    Stmt *stmt;
public:
    Case_expr(Const_expr *const_expr, Stmt *stmt) : const_expr(const_expr), stmt(stmt) {}
    Case_expr(Identifier *id, Stmt *stmt) : id(id), stmt(stmt) {}
    llvm::Value *codegen();
};

using Case_expr_list = vector<Case_expr *>;

class Case_stmt : public Stmt {
private:
    Expression *expression;
    Case_expr_list *case_exper_list;
public:
    Case_stmt(Expression *expression, Case_expr_list *case_exper_list) : expression(expression), case_exper_list(case_exper_list) {}
    llvm::Value *codegen();
};

class Goto_stmt : public Stmt {
private:
    int label;
public:
    Goto_stmt(int label) : label(label) {}
    llvm::Value *codegen();
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
    llvm::Value *codegen();
};

class Binary_expression : public Expression {
private:
    enum Binary_op {
        PLUS,
        MINIUS,
        MUL,
        DIV,
        MOD,
        AND,
        OR,
        GE,
        GT,
        LE,
        LT,
        EQ,
        NE,
        NOT,
    } op;
    Expression *lexpression;
    Expression *rexpression;
public:
    Binary_expression(Binary_op op, Expression *lexpression, Expression *rexpression) : op(op), lexpression(lexpression), rexpression(rexpression) {}
    llvm::Value *codegen();
};