#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Function_decl::codegen(CodeGenerator &codeGenerator) {
    print("Function_decl");
    Value *function = function_head->codegen(codeGenerator);
    subroutine->codegen(codeGenerator);

    if (function_head->return_type->Type_name == function_head->return_type->VOID){
        codeGenerator.builder.CreateRetVoid();
    } else {
        codeGenerator.builder.CreateRet(function_head->id->codegen(codeGenerator));
    }
    
    codeGenerator.popFunc();
    codeGenerator.builder.SetInsertPoint(&(codeGenerator.getFunc())->getBasicBlockList().back());
    return function;
}
    
Value *Function_head::codegen(CodeGenerator &codeGenerator) {
    print("Function_head");
    vector<Type*> types;
    for(auto para : *parameters) {
        if(para->va_para_list->is_var_para){
            types.insert(types.end(), para->va_para_list->name_list->size(), para->simple_type_decl->codegen(codeGenerator)->getType());
        } else {
            types.insert(types.end(), para->va_para_list->name_list->size(), para->simple_type_decl->codegen(codeGenerator)->getType());
        }
    }

    FunctionType *funcType = FunctionType::get(return_type->codegen(codeGenerator)->getType(), types, false);
    Function *function = Function::Create(funcType, GlobalValue::InternalLinkage, id->name, codeGenerator.module);
    codeGenerator.pushFunc(function);
    BasicBlock *newBlock = BasicBlock::Create(codeGenerator.context, "entrypoint", function, nullptr);
    codeGenerator.builder.SetInsertPoint(newBlock);

    Function::arg_iterator iter = function->arg_begin();
    for (auto para : *parameters) {
        for (auto name : *para->va_para_list->name_list){
            Value *alloc = nullptr;
            if(para->va_para_list->is_var_para){
                //tbd
                alloc = codeGenerator.CreateEntryBlockAlloca(function, name->name, para->simple_type_decl->codegen(codeGenerator)->getType());
                codeGenerator.builder.CreateStore(iter, alloc);
                iter++;
            } else {
                alloc = codeGenerator.CreateEntryBlockAlloca(function, name->name, para->simple_type_decl->codegen(codeGenerator)->getType());
                codeGenerator.builder.CreateStore(iter, alloc);
                iter++;
            }
        }
    }

    Value *ret;
    if(return_type->Type_name == return_type->VOID){
        ret = nullptr;
    } else {
        ret = codeGenerator.CreateEntryBlockAlloca(function, id->name, return_type->codegen(codeGenerator)->getType());
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