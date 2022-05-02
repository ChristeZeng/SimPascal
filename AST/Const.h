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
    Const_value(Const_type type, int value) : type(type) {
        this->Value.int_value = value;
    }
    Const_value(Const_type type, double value) : type(type) {
        this->Value.double_value = value;
    }
    Const_value(Const_type type, char value) : type(type) {
        this->Value.char_value = value;
    }
    Const_value(Const_type type, string value) : type(type) {
        new(&this->Value.string_value) string(value);
    }
    Const_value(Const_type type, bool value) : type(type) {
        this->Value.bool_value = value;
    }
    Const_type get_type() {
        return type;
    }
    llvm::Value *codegen();
};