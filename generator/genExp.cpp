#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Binary_operation(Value* lv, Binary_op op, Value* rv, CodeGenerator &codeGenerator){
    print("binary operation");
    bool flag = lv->getType()->isDoubleTy() || rv->getType()->isDoubleTy();

    switch (op) {
        case Binary_op::S_PLUS:
            if (flag) return codeGenerator.builder.CreateFAdd(lv, rv, "addtmp");
            return codeGenerator.builder.CreateAdd(lv, rv, "addtmp");
        case Binary_op::S_MINUS:
            if (flag) return codeGenerator.builder.CreateFSub(lv, rv, "subtmp");
            return codeGenerator.builder.CreateSub(lv, rv, "subtmp");
        case Binary_op::S_MUL:
            if (flag) return codeGenerator.builder.CreateFMul(lv, rv, "multmp");
            return codeGenerator.builder.CreateMul(lv, rv, "multmp");
        case Binary_op::S_DIV:
            return codeGenerator.builder.CreateSDiv(lv, rv, "divtmp");
        case Binary_op::S_MOD:
            return codeGenerator.builder.CreateSRem(lv, rv, "modtmp");
        case Binary_op::S_AND:
            return codeGenerator.builder.CreateAnd(lv, rv, "andtmp");
        case Binary_op::S_OR:
            return codeGenerator.builder.CreateOr(lv, rv, "ortmp");
        case Binary_op::S_GE:
            return codeGenerator.builder.CreateICmpSGE(lv, rv, "getmp");
        case Binary_op::S_GT:
            return codeGenerator.builder.CreateICmpSGT(lv, rv, "gtmp");
        case Binary_op::S_LE:
            return codeGenerator.builder.CreateICmpSLE(lv, rv, "letmp");
        case Binary_op::S_LT:
            return codeGenerator.builder.CreateICmpSLT(lv, rv, "ltmp");
        case Binary_op::S_EQ:
            return codeGenerator.builder.CreateICmpEQ(lv, rv, "eqtmp");
        case Binary_op::S_NE:
            return codeGenerator.builder.CreateICmpNE(lv, rv, "netmp");
        case Binary_op::S_NOT:
            return codeGenerator.builder.CreateNot(lv, "nottmp");
        default:
            return nullptr;
    }
}

Value *Binary_expression::codegen(CodeGenerator &codeGenerator) {
    print("Binary_expression::codegen");
    Value *lv = lexpression->codegen(codeGenerator);
    Value *rv = rexpression->codegen(codeGenerator);
    return Binary_operation(lv, op, rv, codeGenerator);
}

Value *Array_access::codegen(CodeGenerator &codeGenerator) {
    print("Array_access::codegen");
    return codeGenerator.builder.CreateLoad(getPtr(codeGenerator), "arrPtr");
}

Value *Array_access::getPtr(CodeGenerator &codeGenerator) {
    print("get array item pointer");
    std::string name = id->name;
    Value *arrValue = codeGenerator.getValue(name), *idxValue;
    if(codeGenerator.arrMap[name]->get_idx_type() == Pas_type::CONSTRANGE){
        print("idx is const range");
        idxValue = codeGenerator.arrMap[name]->get_idx(index->codegen(codeGenerator), codeGenerator);
    }else{
        print("not const range");
    }
    vector<Value*> idxs;
    idxs.push_back(codeGenerator.builder.getInt32(0));
    idxs.push_back(idxValue);
    return codeGenerator.builder.CreateInBoundsGEP(arrValue, idxs);
}

Value *Record_access::codegen(CodeGenerator &codeGenerator) {
    print("Record_access::codegen");
    return nullptr;
}