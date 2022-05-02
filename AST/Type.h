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

using Type_decl_list = vector<Type_definition *>;

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