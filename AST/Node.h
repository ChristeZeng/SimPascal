#pragma once
#include <llvm/IR/Value.h>
#include <string>
#include <vector>

using namespace std;

enum Base_type {
    INT,
    REAL,
    CHAR,
    BOOLEN,
};

enum SysFunc {
    READ,
    WRITE,
    WRITELN,
    ADS,
    CHR,
    ODD,
    ORD,
    PRED,
    SQR,
    SQRT,
    SUCC,
};

class Node;
class Identifier;
class Expression;
class Stmt;

using Stmt_list = vector<Stmt *>;
using Name_list = vector<Identifier *>;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value *codegen() = 0;
};

class Expression : public Node {};

class Stmt : public Node {
private:
    int label = -1;

public:
    void Setlabel(int label) {
        this->label = label;
    }
    virtual llvm::Value *codegen() = 0;
};

class Identifier : public Expression {
private:
    string name;
public:
    Identifier(string name) : name(name) {}
    llvm::Value *codegen();
};