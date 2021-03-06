#pragma once
#include "AST.h"
#include "Node.h"

using namespace std;

class CodeGenerator;
class Const_part;
class Const_expr;
class Const_value;

using Const_expr_list = vector<Const_expr *>;

class Const_part : public Node {
private:
    Const_expr_list *const_expr_list;
public:
    Const_part(Const_expr_list *const_expr_list) : const_expr_list(const_expr_list) {}
    void setGlobalValues();
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Const_expr : public Node {
private:
    Identifier *id;
    Const_value *const_value;
    bool is_global=false;
public:
    Const_expr(Identifier *id, Const_value *const_value) : id(id), const_value(const_value) {}
    void setGlobalValues(){ is_global = true;}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Const_value : public Expression {
private:
    Base_type base_type;

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
    Const_value(Base_type base_type, int value) : base_type(base_type) {
        this->Value.int_value = value;
    }
    Const_value(Base_type base_type, double value) : base_type(base_type) {
        this->Value.double_value = value;
    }
    Const_value(Base_type base_type, char value) : base_type(base_type) {
        this->Value.char_value = value;
    }
    Const_value(Base_type base_type, string value) : base_type(base_type) {
        this->Value.string_value = value;
    }
    Const_value(Base_type base_type, bool value) : base_type(base_type) {
        this->Value.bool_value = value;
    }

    Const_value *operator-() {
        switch (base_type) {
        case S_INT:
            return new Const_value(S_INT, -Value.int_value);
        case S_REAL:
            return new Const_value(S_REAL, -Value.double_value);
        case S_CHAR:
            return new Const_value(S_CHAR, -Value.char_value);
        case S_BOOLEAN:
            return new Const_value(S_BOOLEAN, !Value.bool_value);
        default:
            return nullptr;
        }
    }
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    llvm::Constant *get_constant(CodeGenerator &codeGenerator);
    string Vis();
    Base_type get_type(){ return base_type;};
    int get_value();
};