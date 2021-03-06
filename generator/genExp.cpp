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
            if (flag) return codeGenerator.builder.CreateFDiv(lv, rv, "divtmp");
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
    Array_type_decl *arr = codeGenerator.arrMap[name];
    if(arr->get_idx_type() == Pas_type::CONSTRANGE){
        print("idx is const range");
        idxValue = arr->get_idx(index->codegen(codeGenerator), codeGenerator);
    }else{
        throw runtime_error("idx is not const range");
    }
    vector<Value*> idxs;
    idxs.push_back(codeGenerator.builder.getInt32(0));
    idxs.push_back(idxValue);
    ArrayType *arrType = (ArrayType*)(arr->get_llvm_type(codeGenerator));
    if(etype == DARRAY_ACCESS){
        int size1, size2; // actually not be used
        size1 = arr->get_size();
        size2 = arr->get_sub_size();
        //get first-level Ptr
        arrValue = codeGenerator.builder.CreateInBoundsGEP(arrType, arrValue, idxs);
        //Update arrType to next-level arrayType
        arrType = (ArrayType*)(arr->get_sub_llvm_type(codeGenerator));
        idxs.pop_back();
        // update index
        idxValue = arr->get_sub_idx(findex->codegen(codeGenerator), codeGenerator);
        idxs.push_back(idxValue);
    }
   
    return codeGenerator.builder.CreateInBoundsGEP(arrType, arrValue, idxs);
}

Value *Record_access::codegen(CodeGenerator &codeGenerator) {
    print("Record_access::codegen");
    //return nullptr;
    return codeGenerator.builder.CreateLoad(getPtr(codeGenerator), "arrPtr");
}

Value *Record_access::getPtr(CodeGenerator &codeGenerator) {
    print("Record_access::getPtr");
    std::string name = id->name;
    Value *recValue = codeGenerator.getValue(name), *idxValue;
    Record_type_decl *rec = codeGenerator.recMap[name];
    std::string target_name = field_id->name;
    int idx = 0;
    for(auto in_name : rec->name_list){
        if(in_name == target_name)break;
        idx++;
    }
    idxValue = codeGenerator.builder.getInt32(idx);
    vector<Value*> idxs;
    idxs.push_back(codeGenerator.builder.getInt32(0));
    idxs.push_back(idxValue);
    return codeGenerator.builder.CreateInBoundsGEP(recValue, idxs);
}