#pragma once
#include "AST.h"

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value *codegen(CodeGenerator &generator) {return nullptr;};
};

class Expression : public Node {};

class Identifier : public Expression {
public:
    string name;
public:
    Identifier(string name) : name(name) {}
    llvm::Value *codegen(CodeGenerator &generator);
};

class Stmt : public Node {
private:
    int label = -1;

public:
    void Setlabel(int label) {
        this->label = label;
    }
    virtual llvm::Value *codegen(CodeGenerator &generator) {return nullptr;};
};