#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    root.codegen(*this);
}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type* type)
{
  IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(type, nullptr, VarName);
}

Value *Const_part::codegen(CodeGenerator &generator) {
    print("Const_part");
    for (auto const_expr : *const_expr_list) {
        const_expr->codegen(generator);
    }
    return nullptr;
}

Value *Const_expr::codegen(CodeGenerator &generator) {
    print("Const_expr");
    Constant *value = const_value->codegen(generator);
    if(is_global){
        return new GlobalVariable(*generator.module, value->getType(), true, GlobalValue::ExternalLinkage, value, id->name);
    } else {
        auto alloc = CreateEntryBlockAlloca(generator.getCurFunction(), id->name, value->getType());
        return builder.CreateStore(value, alloc);
    }
}

Constant *Const_value::codegen(CodeGenerator &generator) {
    switch (base_type) {
        case Base_type::S_INT:
            return builder.getInt32(Value.int_value);
        case Base_type::S_REAL:
            return llvm::ConstantFP::get(builder.getDoubleTy(), Value.double_value);
        case Base_type::S_CHAR:
            return builder.getInt8(Value.char_value);
        case Base_type::S_BOOLEN:
            return builder.getInt1(Value.bool_value);
        default:
            return nullptr;
    }
}

//Type part to be done
Value *Type_part::codegen(CodeGenerator &generator) {
    for (auto type_definition : *type_decl_list) {
        type_definition->codegen(generator);
    }
    return nullptr;
}

Value *Type_definition::codegen(CodeGenerator &generator) {
    
    return nullptr;
}

Value *Type_decl::codegen(CodeGenerator &generator) {
    if(simple_type_decl) {
        return simple_type_decl->codegen(generator);
    } else if(array_type_decl) {
        return array_type_decl->codegen(generator);
    } else if(record_type_decl) {
        return record_type_decl->codegen(generator);
    } else {
        return nullptr;
    }
}

Value *Simple_type_decl::codegen(CodeGenerator &generator) {
    print("Simple_type_decl");
    switch(Type_name){
        case BASE:
            switch(base_type){
                case S_INT:
                    return builder.getInt32(0);
                case S_REAL:
                    return ConstantFP::get(builder.getDoubleTy(), 0.0);
                case S_CHAR:
                    return builder.getInt8(0);
                case S_BOOLEN:
                    return builder.getInt1(0);
                default:
                    return nullptr;
            }
    }
}

Value *Var_part::codegen(CodeGenerator &generator) {
    print("Var_part");
    for (auto var_decl : *var_decl_list) {
        var_decl->codegen(generator);
    }
    return nullptr;
}

Value *Var_decl::codegen(CodeGenerator &generator) {
    print("Var_decl");
    Value *value = type_decl->codegen(generator);
    for(auto name : *name_list) {
        if(is_global){
            Constant *constant = Constant::getNullValue(value->getType());
            return new GlobalVariable(*generator.module, value->getType(), false, GlobalValue::ExternalLinkage, constant, name->name);
        } else {
            auto alloc = CreateEntryBlockAlloca(generator.getCurFunction(), name->name, value->getType());
            return builder.CreateStore(value, alloc);
        }
    }
    return nullptr;
}

Value *Function_decl::codegen(CodeGenerator &generator) {
    print("Function_decl");
    function_head->codegen(generator);
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
    llvm::Function *function = llvm::Function::Create(funcType, llvm::GlobalValue::InternalLinkage, id->name, *generator.module);
    generator.pushFunction(function);
    BasicBlock *newBlock = llvm::BasicBlock::Create(context, "entrypoint", function, nullptr);
    builder.SetInsertPoint(newBlock);

    
}

Value *Para_decl::codegen(CodeGenerator &generator) {
    print("Para_decl");
}

Value *Va_para_list::codegen(CodeGenerator &generator) {
    print("Va_para_list");
    for(auto name : *name_list){
        if(is_var_para){
            return builder.getInt32(0);
        } else {
            return builder.getInt32(0);
        }
    }
}
