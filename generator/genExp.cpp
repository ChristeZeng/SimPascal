#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Binary_expression::codegen(CodeGenerator &codeGenerator) {
    print("Binary_expression::codegen");
    Value *lhs = lexpression->codegen(codeGenerator);
    Value *rhs = rexpression->codegen(codeGenerator);
    bool flag = lhs->getType()->isDoubleTy() || rhs->getType()->isDoubleTy();

    switch (op) {
        case Binary_op::S_PLUS:
            if (flag) return codeGenerator.builder.CreateFAdd(lhs, rhs, "addtmp");
            return codeGenerator.builder.CreateAdd(lhs, rhs, "addtmp");
        case Binary_op::S_MINUS:
            if (flag) return codeGenerator.builder.CreateFSub(lhs, rhs, "subtmp");
            return codeGenerator.builder.CreateSub(lhs, rhs, "subtmp");
        case Binary_op::S_MUL:
            if (flag) return codeGenerator.builder.CreateFMul(lhs, rhs, "multmp");
            return codeGenerator.builder.CreateMul(lhs, rhs, "multmp");
        case Binary_op::S_DIV:
            return codeGenerator.builder.CreateSDiv(lhs, rhs, "divtmp");
        case Binary_op::S_MOD:
            return codeGenerator.builder.CreateSRem(lhs, rhs, "modtmp");
        case Binary_op::S_AND:
            return codeGenerator.builder.CreateAnd(lhs, rhs, "andtmp");
        case Binary_op::S_OR:
            return codeGenerator.builder.CreateOr(lhs, rhs, "ortmp");
        case Binary_op::S_GE:
            return codeGenerator.builder.CreateICmpSGE(lhs, rhs, "getmp");
        case Binary_op::S_GT:
            return codeGenerator.builder.CreateICmpSGT(lhs, rhs, "gtmp");
        case Binary_op::S_LE:
            return codeGenerator.builder.CreateICmpSLE(lhs, rhs, "letmp");
        case Binary_op::S_LT:
            return codeGenerator.builder.CreateICmpSLT(lhs, rhs, "ltmp");
        case Binary_op::S_EQ:
            return codeGenerator.builder.CreateICmpEQ(lhs, rhs, "eqtmp");
        case Binary_op::S_NE:
            return codeGenerator.builder.CreateICmpNE(lhs, rhs, "netmp");
        case Binary_op::S_NOT:
            return codeGenerator.builder.CreateNot(lhs, "nottmp");
        default:
            return nullptr;
    }
}

Value *Array_access::codegen(CodeGenerator &codeGenerator) {
    print("Array_access::codegen");
    return nullptr;
}

Value *Record_access::codegen(CodeGenerator &codeGenerator) {
    print("Record_access::codegen");
    return nullptr;
}