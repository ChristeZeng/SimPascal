#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

#include "Node.h"
#include "Program.h"
using namespace std;

class Var_decl : public Node {
private:
    Name_list *name_list;
    Type_decl *type_decl;
public:
    Var_decl(Name_list *name_list, Type_decl *type_decl) : name_list(name_list), type_decl(type_decl) {}
    llvm::Value *codegen();
};

using Var_decl_list = vector<Var_decl *>;

class Var_part : public Node {
private:
    Var_decl_list *var_decl_list;
public:
    Var_part(Var_decl_list *var_decl_list) : var_decl_list(var_decl_list) {}
    llvm::Value *codegen();
};

/*Routine Part*/
// let Function_decl == Procedure_decl
class Va_para_list : public Node {
private:
    Name_list *name_list;
    bool is_var_para;
public:
    Va_para_list(Name_list *name_list, bool is_var_para) : name_list(name_list), is_var_para(is_var_para) {}
    llvm::Value *codegen();
};

class Para_decl : public Node {
private:
    Simple_type_decl *simple_type_decl;
    Va_para_list *va_para_list;
public:
    Para_decl(Simple_type_decl *simple_type_decl, Va_para_list *va_para_list) : simple_type_decl(simple_type_decl), va_para_list(va_para_list) {}
    llvm::Value *codegen();
};

using Para_decl_list = vector<Para_decl *>;

class Function_head : public Node {
private:
    Identifier *id;
    Para_decl_list *parameters;
    Simple_type_decl *return_type;
public:
    Function_head(Identifier *id, Para_decl_list *parameters, Simple_type_decl *return_type) : id(id), parameters(parameters), return_type(return_type) {}
    llvm::Value *codegen();
};

class Function_decl : public Node {
private:
    Function_head *function_head;
    Routine *subroutine;
public:
    Function_decl(Function_head *function_head, Routine *subroutine) : function_head(function_head), subroutine(subroutine) {}
    llvm::Value *codegen();
};

using Routine_part = vector<Function_decl *>;