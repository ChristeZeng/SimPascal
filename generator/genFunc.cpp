#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Function_decl::codegen(CodeGenerator &codeGenerator) {
    print("Function_decl");
    Value *function = function_head->codegen(codeGenerator);
    subroutine->codegen(codeGenerator);

    if (!function_head->getReturnType()){
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
    for(auto para : *parameters) {
        if(para->getVaParaList()->getIsVarPara()){
            types.insert(types.end(), para->getVaParaList()->getNameList()->size(), para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
        } else {
            types.insert(types.end(), para->getVaParaList()->getNameList()->size(), para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
        }
    }

    Type *retType;
    if(return_type) {
        retType = return_type->codegen(codeGenerator)->getType();
    } else {
        retType = codeGenerator.builder.getVoidTy();
    }
    FunctionType *funcType = FunctionType::get(retType, types, false);
    Function *function = Function::Create(funcType, GlobalValue::InternalLinkage, id->name, codeGenerator.module);
    codeGenerator.pushFunc(function);
    BasicBlock *newBlock = BasicBlock::Create(codeGenerator.context, "entrypoint", function, nullptr);
    codeGenerator.builder.SetInsertPoint(newBlock);

    Function::arg_iterator iter = function->arg_begin();
    for (auto para : *parameters) {
        for (auto name : *para->getVaParaList()->getNameList()){
            Value *alloc = nullptr;
            if(para->getVaParaList()->getIsVarPara()){
                //tbd
                alloc = codeGenerator.CreateEntryBlockAlloca(function, name->name, para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
                codeGenerator.builder.CreateStore(iter, alloc);
                iter++;
            } else {
                alloc = codeGenerator.CreateEntryBlockAlloca(function, name->name, para->getSimpleTypeDecl()->codegen(codeGenerator)->getType());
                codeGenerator.builder.CreateStore(iter, alloc);
                iter++;
            }
        }
    }

    codeGenerator.CreateEntryBlockAlloca(function, id->name, retType);
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