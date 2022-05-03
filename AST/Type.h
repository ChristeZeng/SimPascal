#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

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

using Type_decl_list = vector<Type_definition *>;
using Var_decl_list = vector<Var_decl *>;

class Type_part : public Node {
private:
    Type_decl_list *type_decl_list;
public:
    Type_part(Type_decl_list *type_decl_list) : type_decl_list(type_decl_list) {}
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

class Const_range : public Node {
private:
    Const_value *lower;
    Const_value *upper;
public:
    Const_range(Const_value *lower, Const_value *upper) : lower(lower), upper(upper) {}
    llvm::Value *codegen();
};

class Enum_Type : public Node {
private:
    Name_list *name_list;
public:
    Enum_Type(Name_list *name_list) : name_list(name_list) {}
    llvm::Value *codegen();
};

class Enum_range : public Node {
private:
    Identifier *lower_id;
    Identifier *upper_id;
public:
    Enum_range(Identifier *lower_id, Identifier *upper_id) : lower_id(lower_id), upper_id(upper_id) {}
    llvm::Value *codegen();
};

class Simple_type_decl : public Node {
private:
    enum {
        BASE,
        ARRARY,
        RECORD,
        ENUM,
        CONSTRANGE,
        ENUMRANGE,
        USERDEFINED,
        VOID,
    } Type_name;

    Identifier *id;
    Const_range *const_range;
    Enum_range *enum_range;
    Enum_Type *enum_type;
    Base_type base_type;
public:
    Simple_type_decl(Identifier *id) : id(id), Type_name(USERDEFINED) {}
    Simple_type_decl(Const_range *const_range) : const_range(const_range), Type_name(CONSTRANGE) {}
    Simple_type_decl(Enum_range *enum_range) : enum_range(enum_range), Type_name(ENUMRANGE) {}
    Simple_type_decl(Enum_Type *enum_type) : enum_type(enum_type), Type_name(ENUM) {}
    Simple_type_decl(Base_type base_type) : base_type(base_type), Type_name(BASE) {}
    Simple_type_decl() : Type_name(VOID) {}
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

class Var_decl : public Node {
private:
    Name_list *name_list;
    Type_decl *type_decl;
public:
    Var_decl(Name_list *name_list, Type_decl *type_decl) : name_list(name_list), type_decl(type_decl) {}
    llvm::Value *codegen();
};

class Var_part : public Node {
private:
    Var_decl_list *var_decl_list;
public:
    Var_part(Var_decl_list *var_decl_list) : var_decl_list(var_decl_list) {}
    llvm::Value *codegen();
};