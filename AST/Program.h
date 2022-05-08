#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "Node.h"
#include "Const.h"
#include "Type.h"
using namespace std;

// 类型申明
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

using Routine_part = vector<Function_decl *>;
using Para_decl_list = vector<Para_decl *>;
using Para_type_list = vector<Simple_type_decl *>;

class Program : public Node {
private:
    Program_head *head;
    Routine *routine;
public:
    Program(Program_head *head, Routine *routine) : head(head), routine(routine) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Program_head : public Node {
private:
    string name;
public:
    Program_head(string name) : name(name) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Routine : public Node {
private:
    Routine_head *head;
    Routine_body *body;
public:
    Routine(Routine_head *head, Routine_body *body) : head(head), body(body) {}
    llvm::Value *codegen(CodeGenerator &generator);
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
    llvm::Value *codegen(CodeGenerator &generator);
};

class Routine_body : public Stmt {
private:
    Stmt_list *stmt_list;
public:
    Routine_body(Stmt_list *stmt_list) : stmt_list(stmt_list) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

/*Routine Part*/
class Va_para_list : public Node {
public:
    Name_list *name_list;
    bool is_var_para;
    Va_para_list(Name_list *name_list, bool is_var_para) : name_list(name_list), is_var_para(is_var_para) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

// This is para_type_list
class Para_decl : public Node {
public:
    Va_para_list *va_para_list;
    Simple_type_decl *simple_type_decl;
    Para_decl(Va_para_list *va_para_list, Simple_type_decl *simple_type_decl) : va_para_list(va_para_list), simple_type_decl(simple_type_decl) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Function_head : public Node {
public:
    Identifier *id;
    Para_decl_list *parameters;
    Simple_type_decl *return_type;
public:
    Function_head(Identifier *id, Para_decl_list *parameters, Simple_type_decl *return_type) : id(id), parameters(parameters), return_type(return_type) {}
    Function_head(Identifier *id, Para_decl_list *parameters) : id(id), parameters(parameters) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Function_decl : public Node {
private:
    Function_head *function_head;
    Routine *subroutine;
public:
    Function_decl(Function_head *function_head, Routine *subroutine) : function_head(function_head), subroutine(subroutine) {}
    llvm::Value *codegen(CodeGenerator &generator);
};