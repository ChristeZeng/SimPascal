#pragma once
#include "AST.h"
#include "Node.h"
#include "Const.h"

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

class Simple_type_decl : public Node {
public:
    Pas_type Type_name;

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
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
    Pas_type get_type(){ 
        //if(Type_name == Pas_type::CONSTRANGE)cout << "simple: get type const_range" << endl;
        return Type_name; };
    Base_type get_base_type() { return base_type; };
    llvm::Type* get_llvm_type(CodeGenerator &codeGenerator);
    size_t get_size();
    llvm::Value *get_idx(llvm::Value *originIdx, CodeGenerator &codeGenerator);
};

class Type_part : public Node {
private:
    Type_decl_list *type_decl_list;
public:
    Type_part(Type_decl_list *type_decl_list) : type_decl_list(type_decl_list) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Type_definition : public Node {
private:
    Identifier *id;
    Type_decl *type_decl;

    
public:
    Type_definition(Identifier *id, Type_decl *type_decl) : id(id), type_decl(type_decl) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Const_range : public Node {
private:
    Const_value *lower;
    Const_value *upper;
    size_t size;
public:
    Const_range(Const_value *lower, Const_value *upper) : lower(lower), upper(upper) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
    llvm::Value *get_abs_index(llvm::Value *originIdx, CodeGenerator &codeGenerator);
    void cal_size(){
        int s;
        if(lower->get_type() == upper->get_type()){
            s = upper->get_value() - lower->get_value() + 1;
        }
        if(s <= 0){
            //print("Invalid range");
        }
        size = s;
    }
    size_t get_size(){ return size; };
};


class Enum_Type : public Node {
private:
    Name_list *name_list;
public:
    Enum_Type(Name_list *name_list) : name_list(name_list) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Enum_range : public Node {
private:
    Identifier *lower_id;
    Identifier *upper_id;
public:
    Enum_range(Identifier *lower_id, Identifier *upper_id) : lower_id(lower_id), upper_id(upper_id) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Array_type_decl : public Node {
private:
    Simple_type_decl *simple_type_decl;
    Type_decl *type_decl;
public:
    Array_type_decl(Simple_type_decl *simple_type_decl, Type_decl *type_decl) : simple_type_decl(simple_type_decl), type_decl(type_decl) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
    int get_size(){ return simple_type_decl->get_size(); };
    int get_sub_size();
    Pas_type get_idx_type();
    llvm::Type *get_llvm_type(CodeGenerator &codeGenerator);
    llvm::Type *get_sub_llvm_type(CodeGenerator &codeGenerator);
    llvm::Constant *get_init_value(CodeGenerator &codeGenerator);
    llvm::Value* get_idx(llvm::Value* originIdx, CodeGenerator &codeGenerator){return simple_type_decl->get_idx(originIdx, codeGenerator);};
    llvm::Value* get_sub_idx(llvm::Value* originIdx, CodeGenerator &codeGenerator);
};

class Field_decl : public Node {
private:
    Name_list *name_list;
    Type_decl *type_decl;
public:
    Field_decl(Name_list *name_list, Type_decl *type_decl) : name_list(name_list), type_decl(type_decl) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
    int get_number() {return name_list->size(); }
    llvm::Type *get_llvm_type(CodeGenerator &codeGenerator);
    void merge(vector<string> *names);
};

using Field_decl_list = vector<Field_decl *>;

class Record_type_decl : public Node {
private:
    Field_decl_list *field_decl_list;
public:
    vector<string> name_list;
    Record_type_decl(Field_decl_list *field_decl_list) : field_decl_list(field_decl_list) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    llvm::Type *get_llvm_type(CodeGenerator &codeGenerator);
    llvm::Value *get_field_idx(string name, CodeGenerator &codeGenerator);
    string Vis();
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
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
    Pas_type get_type(){
        if(simple_type_decl) {
            return simple_type_decl->get_type();
        } else if(array_type_decl) {
            return Pas_type::ARRARY;
        } else if(record_type_decl) {
            return Pas_type::RECORD_Type;
        }
        return Pas_type::VOID;
    }
    llvm::Type *get_llvm_type(CodeGenerator &codeGenerator);
    llvm::Constant * get_init_value(CodeGenerator &codeGenerator, Const_value* v);
    Base_type get_base_type(){ return simple_type_decl->get_base_type(); };
    Array_type_decl *get_array_decl(){ 
        return array_type_decl; };
    Record_type_decl *get_record_decl(){ 
        return record_type_decl; };
    size_t get_array_size(){ return array_type_decl->get_size(); };
    llvm::Value *get_idx(llvm::Value* originIdx, CodeGenerator &codeGenerator){ return array_type_decl->get_idx(originIdx, codeGenerator); };
};

class Var_decl : public Node {
private:
    Name_list *name_list;
    Type_decl *type_decl;
    bool is_global=false;
public:
    Var_decl(Name_list *name_list, Type_decl *type_decl) : name_list(name_list), type_decl(type_decl) {}
    void setGlobalValues() { is_global = true; }
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Var_part : public Node {
private:
    Var_decl_list *var_decl_list;
public:
    Var_part(Var_decl_list *var_decl_list) : var_decl_list(var_decl_list) {}
    void setGlobalValues();
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};