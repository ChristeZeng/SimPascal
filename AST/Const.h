#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Const_part;
class Const_expr;
class Const_value;

using Const_expr_list = vector<Const_expr *>;

class Const_part : public Node {
private:
    Const_expr_list *const_expr_list;
public:
    Const_part(Const_expr_list *const_expr_list) : const_expr_list(const_expr_list) {}
    llvm::Value *codegen();
};

class Const_expr : public Node {
private:
    Identifier *id;
    Const_value *const_value;
public:
    Const_expr(Identifier *id, Const_value *const_value) : id(id), const_value(const_value) {}
    llvm::Value *codegen();
};

class Const_value : public Node {
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
        case INT:
            return new Const_value(INT, -Value.int_value);
        case REAL:
            return new Const_value(REAL, -Value.double_value);
        case CHAR:
            return new Const_value(CHAR, -Value.char_value);
        case BOOLEN:
            return new Const_value(BOOLEN, !Value.bool_value);
        default:
            return nullptr;
        }
    }
    llvm::Value *codegen();
};