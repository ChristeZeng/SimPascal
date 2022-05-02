#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "Node.h"

#include "Const.h"
#include "Type.h"
using namespace std;

class Program : public Node {
private:
    Program_head *head;
    Routine *routine;
public:
    Program(Program_head *head, Routine *routine) : head(head), routine(routine) {}
    llvm::Value *codegen();
};

class Program_head : public Node {
private:
    string name;
public:
    Program_head(string name) : name(name) {}
    llvm::Value *codegen();
};

class Routine : public Node {
private:
    Routine_head *head;
    Routine_body *body;
public:
    Routine(Routine_head *head, Routine_body *body) : head(head), body(body) {}
    llvm::Value *codegen();
};

class Routine_head : public Node {
private:
    Const_part *const_part;
    Type_part *type_part;
    Var_part *var_part;
    Routine_part *routine_part;
public:
    Routine_head(Const_part *const_part, Type_part *type_part, Var_part *var_part, Routine_part *routine_part)
        : const_part(const_part), type_part(type_part), var_part(var_part), routine_part(routine_part) {}
    llvm::Value *codegen();
};

class Routine_body : public Node {
private:
    Stmt_list *stmt_list;
public:
    Routine_body(Stmt_list *stmt_list) : stmt_list(stmt_list) {}
    llvm::Value *codegen();
};