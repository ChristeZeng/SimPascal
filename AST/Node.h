#pragma once
#include "AST.h"
#include <string>
#include <vector>
using namespace std;
enum Base_type {
    S_INT,
    S_REAL,
    S_CHAR,
    S_BOOLEAN,
};

enum Pas_type{
    BASE,
    ARRARY,
    RECORD_Type,  //may be some bug
    ENUM,
    CONSTRANGE,
    ENUMRANGE,
    USERDEFINED,
    VOID,
};

enum exp_type{
    ARRAY_ACCESS,
};

enum SysFunc {
    S_READ,
    S_WRITE,
    S_WRITELN,
    S_ADS,
    S_CHR,
    S_ODD,
    S_ORD,
    S_PRED,
    S_SQR,
    S_SQRT,
    S_SUCC,
};

class Node;
class Identifier;
class Expression;
class Stmt;
class CodeGenerator;

using Stmt_list = vector<Stmt *>;
using Name_list = vector<Identifier *>;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value *codegen(CodeGenerator &codeGenerator) = 0;
    virtual string Vis() { return ""; };
};

class Expression : public Node {
public:
    exp_type etype;
};

class Identifier : public Expression {
public:
    string name;
    Identifier(string name) : name(name) {}
    llvm::Value *codegen(CodeGenerator &codeGenerator);
    string Vis();
};

class Stmt : public Node {
private:
    int label = -1;

public:
    void Setlabel(int label) {
        this->label = label;
    }
    virtual llvm::Value *codegen(CodeGenerator &codeGenerator) = 0;
};