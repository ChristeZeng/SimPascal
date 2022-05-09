#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Binary_expression::codegen(CodeGenerator &generator) {
    print("Binary_expression::codegen");
    Value *lhs = lexpression->codegen(generator);
    Value *rhs = rexpression->codegen(generator);
    bool flag = lhs->getType()->isDoubleTy() || rhs->getType()->isDoubleTy();

    switch (op) {
        case Binary_op::S_PLUS:
            if (flag) return generator.builder.CreateFAdd(lhs, rhs, "addtmp");
            return generator.builder.CreateAdd(lhs, rhs, "addtmp");
        case Binary_op::S_MINUS:
            if (flag) return generator.builder.CreateFSub(lhs, rhs, "subtmp");
            return generator.builder.CreateSub(lhs, rhs, "subtmp");
        case Binary_op::S_MUL:
            if (flag) return generator.builder.CreateFMul(lhs, rhs, "multmp");
            return generator.builder.CreateMul(lhs, rhs, "multmp");
        case Binary_op::S_DIV:
            return generator.builder.CreateSDiv(lhs, rhs, "divtmp");
        case Binary_op::S_MOD:
            return generator.builder.CreateSRem(lhs, rhs, "modtmp");
        case Binary_op::S_AND:
            return generator.builder.CreateAnd(lhs, rhs, "andtmp");
        case Binary_op::S_OR:
            return generator.builder.CreateOr(lhs, rhs, "ortmp");
        case Binary_op::S_GE:
            return generator.builder.CreateICmpSGE(lhs, rhs, "getmp");
        case Binary_op::S_GT:
            return generator.builder.CreateICmpSGT(lhs, rhs, "gtmp");
        case Binary_op::S_LE:
            return generator.builder.CreateICmpSLE(lhs, rhs, "letmp");
        case Binary_op::S_LT:
            return generator.builder.CreateICmpSLT(lhs, rhs, "ltmp");
        case Binary_op::S_EQ:
            return generator.builder.CreateICmpEQ(lhs, rhs, "eqtmp");
        case Binary_op::S_NE:
            return generator.builder.CreateICmpNE(lhs, rhs, "netmp");
        case Binary_op::S_NOT:
            return generator.builder.CreateNot(lhs, "nottmp");
        default:
            return nullptr;
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