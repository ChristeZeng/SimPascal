#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value *codegen() = 0;
};

class Identifier : public Node {
private:
    string name;
public:
    Identifier(string name) : name(name) {}
    llvm::Value *codegen();
};