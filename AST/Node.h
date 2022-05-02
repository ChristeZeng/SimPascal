#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

using namespace std;

class Node;
class Identifier;
class Stmt;

using Stmt_list = vector<Stmt *>;
using Name_list = vector<Identifier *>;

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

class Stmt : public Node {
private:
    int label = -1;

public:
    virtual llvm::Value *codegen() = 0;
};