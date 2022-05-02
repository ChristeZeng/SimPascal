#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

#include "Node.h"
using namespace std;

/*Const Part*/
/*暂时没有考虑类型的问题*/
class Const_expr : public Node {
private:
    Identifier *id;
    
    enum class Const_type {
        INT,
        FLOAT,
        CHAR,
        STRING,
        BOOL
    } type;

    union value {
        int int_value;
        double double_value;
        char char_value;
        string string_value;
        bool bool_value;
    public:
        value() { new(&string_value) string(); }
        ~value() { string_value.~string(); }
    } Value;

public:
    Const_expr(Identifier *id, Const_type type, int int_value) : id(id), type(type) {
        this->Value.int_value = int_value;
    }
    Const_expr(Identifier *id, Const_type type, double double_value) : id(id), type(type) {
        this->Value.double_value = double_value;
    }
    Const_expr(Identifier *id, Const_type type, char char_value) : id(id), type(type) {
        this->Value.char_value = char_value;
    }
    Const_expr(Identifier *id, Const_type type, string string_value) : id(id), type(type) {
        this->Value.string_value = string_value;
    }
    Const_expr(Identifier *id, Const_type type, bool bool_value) : id(id), type(type) {
        this->Value.bool_value = bool_value;
    }

    llvm::Value *codegen();
};

using Const_expr_list = vector<Const_expr *>;

class Const_part : public Node {
private:
    Const_expr_list *const_expr_list;
public:
    Const_part(Const_expr_list *const_expr_list) : const_expr_list(const_expr_list) {}
    llvm::Value *codegen();
};


/*Type part*/
class Simple_type_decl : public Node {
private:
    Identifier *id;
    string type_name;
public:
    Simple_type_decl(Identifier *id, string type_name) : id(id), type_name(type_name) {}
    llvm::Value *codegen();
};

class Array_type_decl : public Node {
private:
    Simple_type_decl *simple_type_decl;
    Type_decl *type_decl;
public:
    Array_type_decl(Simple_type_decl *simple_type_decl, Type_decl *type_decl) : simple_type_decl(simple_type_decl), type_decl(type_decl) {}
    llvm::Value *codegen();
};


using Name_list = vector<Identifier *>;

class Field_decl : public Node {
private:
    Name_list *name_list;
    Type_decl *type_decl;
public:
    Field_decl(Name_list *name_list, Type_decl *type_decl) : name_list(name_list), type_decl(type_decl) {}
    llvm::Value *codegen();
};

using Field_decl_list = vector<Field_decl *>;

class Record_type_decl : public Node {
private:
    Field_decl_list *field_decl_list;
public:
    Record_type_decl(Field_decl_list *field_decl_list) : field_decl_list(field_decl_list) {}
    llvm::Value *codegen();
};

class Type_decl : public Node {
private:
    Simple_type_decl *simple_type_decl;
    Array_type_decl *array_type_decl;
    Record_type_decl *record_type_decl;
public:
    Type_decl(Simple_type_decl *simple_type_decl) : simple_type_decl(simple_type_decl) {}
    Type_decl(Array_type_decl *array_type_decl) : array_type_decl(array_type_decl) {}
    Type_decl(Record_type_decl *record_type_decl) : record_type_decl(record_type_decl) {}
    llvm::Value *codegen();
};

class Type_definition : public Node {
private:
    Identifier *id;
    Type_decl *type_decl;
public:
    Type_definition(Identifier *id, Type_decl *type_decl) : id(id), type_decl(type_decl) {}
    llvm::Value *codegen();
};

using Type_decl_list = vector<Type_definition *>;

class Type_part : public Node {
private:
    Type_decl_list *type_decl_list;
public:
    Type_part(Type_decl_list *type_decl_list) : type_decl_list(type_decl_list) {}
    llvm::Value *codegen();
};

/*Var part*/
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

class Program : public Node {
private:
    Program_head *head;
    Routine *routine;
public:
    Program(Program_head *head, Routine *routine) : head(head), routine(routine) {}
    llvm::Value *codegen();
};