#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Function_decl::codegen(CodeGenerator &codeGenerator) {
    print("Function_decl");
    Value *function = function_head->codegen(codeGenerator);
    subroutine->codegen(codeGenerator);

     if (!function_head->getReturnType()){
        codeGenerator.builder.CreateRetVoid();
    } else if(!function_head->getReturnType()->codegen(codeGenerator)){
        codeGenerator.builder.CreateRetVoid();
    } else {
        codeGenerator.builder.CreateRet(function_head->getId()->codegen(codeGenerator));
    }
    
    codeGenerator.popFunc();
    codeGenerator.builder.SetInsertPoint(&(codeGenerator.getFunc())->getBasicBlockList().back());
    return function;
}
    
Value *Function_head::codegen(CodeGenerator &codeGenerator) {
    print("Function_head");
    vector<Type*> types;
    if (parameters) {
        for(auto para : *parameters) {
            if(para->getVaParaList()->getIsVarPara()){
                Type *type = para->getSimpleTypeDecl()->codegen(codeGenerator)->getType();
                Type *ptrType;
                if(type->isIntegerTy()){
                    if(type->getIntegerBitWidth() == 8){
                        ptrType = Type::getInt8PtrTy(codeGenerator.context);
                    } else if(type->getIntegerBitWidth() == 32){
                        ptrType = Type::getInt32PtrTy(codeGenerator.context);
                    } else if(type->getIntegerBitWidth() == 1){
                        ptrType = Type::getInt1PtrTy(codeGenerator.context);
                    }
                } else if(type->isDoubleTy()){
                    ptrType = Type::getDoublePtrTy(codeGenerator.context);
                } else if(type->isFloatTy()){
                    ptrType = Type::getFloatPtrTy(codeGenerator.context);
                }
                types.insert(types.end(), para->getVaParaList()->getNameList()->size(), ptrType);
            } else {
                types.insert(types.end(), para->getVaParaList()->getNameList()->size(), para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
            }
        }
    }
    Type *retType;
    if(return_type) {
        Value *ret = return_type->codegen(codeGenerator);
        if(ret) retType = ret->getType();
        else retType = codeGenerator.builder.getVoidTy();
    } else {
        retType = codeGenerator.builder.getVoidTy();
    }
    FunctionType *funcType = FunctionType::get(retType, types, false);
    Function *function = Function::Create(funcType, GlobalValue::InternalLinkage, id->name, codeGenerator.module);
    codeGenerator.pushFunc(function);
    BasicBlock *newBlock = BasicBlock::Create(codeGenerator.context, "entrypoint", function, nullptr);
    codeGenerator.builder.SetInsertPoint(newBlock);

    Function::arg_iterator iter = function->arg_begin();
    int idx = 1;
    if (parameters) {
        for (auto para : *parameters) {
            for (auto name : *para->getVaParaList()->getNameList()){
                Value *alloc = nullptr;
                if(para->getVaParaList()->getIsVarPara()){
                    function->addAttribute(idx, Attribute::NonNull);
                    alloc = codeGenerator.builder.CreateGEP(iter, codeGenerator.builder.getInt32(0),name->name);
                    iter++;idx++;
                } else {
                    alloc = codeGenerator.CreateEntryBlockAlloca(function, name->name, para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
                    codeGenerator.builder.CreateStore(iter, alloc);
                    iter++;idx++;
                }
            }
        }
    }
    if(retType != codeGenerator.builder.getVoidTy()){
        codeGenerator.CreateEntryBlockAlloca(function, id->name, retType);
    }
    return function;
}

Value *Para_decl::codegen(CodeGenerator &codeGenerator) {
    print("Para_decl");
    return nullptr;
}

Value *Va_para_list::codegen(CodeGenerator &codeGenerator) {
    print("Va_para_list");
    for(auto name : *name_list){
        if(is_var_para){
            return codeGenerator.builder.getInt32(0);
        } else {
            return codeGenerator.builder.getInt32(0);
        }
    }
    return nullptr;
}