#include "CodeGenerator.h"
#include "../AST/AST.h"

using namespace std;
using namespace llvm;

Value *Binary_expression::codegen(CodeGenerator &generator) {
    print("Binary_expression::codegen");
    Value *lhs = lexpression->codegen(generator);
    Value *rhs = rexpression->codegen(generator);
    bool flag = lhs->getType()->isDoubleTy() || rhs->getType()->isDoubleTy();

    switch (op) {
        case Binary_op::S_PLUS:
            if (flag) return builder.CreateFAdd(lhs, rhs, "addtmp");
            return builder.CreateAdd(lhs, rhs, "addtmp");
        case Binary_op::S_MINUS:
            if (flag) return builder.CreateFSub(lhs, rhs, "subtmp");
            return builder.CreateSub(lhs, rhs, "subtmp");
        case Binary_op::S_MUL:
            if (flag) return builder.CreateFMul(lhs, rhs, "multmp");
            return builder.CreateMul(lhs, rhs, "multmp");
        case Binary_op::S_DIV:
            return builder.CreateSDiv(lhs, rhs, "divtmp");
        case Binary_op::S_MOD:
            return builder.CreateSRem(lhs, rhs, "modtmp");
        case Binary_op::S_AND:
            return builder.CreateAnd(lhs, rhs, "andtmp");
        case Binary_op::S_OR:
            return builder.CreateOr(lhs, rhs, "ortmp");
        case Binary_op::S_GE:
            return builder.CreateICmpSGE(lhs, rhs, "getmp");
        case Binary_op::S_GT:
            return builder.CreateICmpSGT(lhs, rhs, "gtmp");
        case Binary_op::S_LE:
            return builder.CreateICmpSLE(lhs, rhs, "letmp");
        case Binary_op::S_LT:
            return builder.CreateICmpSLT(lhs, rhs, "ltmp");
        case Binary_op::S_EQ:
            return builder.CreateICmpEQ(lhs, rhs, "eqtmp");
        case Binary_op::S_NE:
            return builder.CreateICmpNE(lhs, rhs, "netmp");
        case Binary_op::S_NOT:
            return builder.CreateNot(lhs, "nottmp");
    }
}

Value *Array_access::codegen(CodeGenerator &generator) {
    print("Array_access::codegen");
    return nullptr;
}

Value *Record_access::codegen(CodeGenerator &generator) {
    print("Record_access::codegen");
    return nullptr;
}