#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Function_decl::codegen(CodeGenerator &generator) {
    print("Function_decl");
    Value *function = function_head->codegen(generator);
    subroutine->codegen(generator);

    if (function_head->return_type->Type_name == function_head->return_type->VOID)
    {
        generator.builder.CreateRetVoid();
    }
    else
    {
        auto returnInst = function_head->id->codegen(generator);
        generator.builder.CreateRet(returnInst);
    }
    
    //Pop back
    generator.popFunction();
    generator.builder.SetInsertPoint(&(generator.getCurFunction())->getBasicBlockList().back());
    return function;
}
    
Value *Function_head::codegen(CodeGenerator &generator) {
    print("Function_head");
    vector<Type*> arg_types;
    for(auto para : *parameters) {
        if(para->va_para_list->is_var_para){
            arg_types.insert(arg_types.end(), para->va_para_list->name_list->size(), para->simple_type_decl->codegen(generator)->getType());
        } else {
            arg_types.insert(arg_types.end(), para->va_para_list->name_list->size(), para->simple_type_decl->codegen(generator)->getType());
        }
    }

    llvm::FunctionType *funcType = FunctionType::get(return_type->codegen(generator)->getType(), arg_types, false);
    llvm::Function *function = llvm::Function::Create(funcType, llvm::GlobalValue::InternalLinkage, id->name, generator.module.get());
    generator.pushFunction(function);
    BasicBlock *newBlock = llvm::BasicBlock::Create(generator.context, "entrypoint", function, nullptr);
    generator.builder.SetInsertPoint(newBlock);

    Function::arg_iterator argIt = function->arg_begin();
    int index = 1;
    for (auto para : *parameters) {
        for (auto name : *para->va_para_list->name_list){
            Value *alloc = nullptr;
            if(para->va_para_list->is_var_para){
                //tbd
                alloc = generator.CreateEntryBlockAlloca(function, name->name, para->simple_type_decl->codegen(generator)->getType());
                generator.builder.CreateStore(argIt, alloc);
                argIt++;
            } else {
                alloc = generator.CreateEntryBlockAlloca(function, name->name, para->simple_type_decl->codegen(generator)->getType());
                generator.builder.CreateStore(argIt, alloc);
                argIt++;
            }
        }
    }

    Value *res;
    if(return_type->Type_name == return_type->VOID){
        res = nullptr;
    } else {
        res = generator.CreateEntryBlockAlloca(function, id->name, return_type->codegen(generator)->getType());
    }
    return function;
}

Value *Para_decl::codegen(CodeGenerator &generator) {
    print("Para_decl");
    return nullptr;
}

Value *Va_para_list::codegen(CodeGenerator &generator) {
    print("Va_para_list");
    for(auto name : *name_list){
        if(is_var_para){
            return generator.builder.getInt32(0);
        } else {
            return generator.builder.getInt32(0);
        }
    }
    return nullptr;
}