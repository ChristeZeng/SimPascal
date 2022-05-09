#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Const_part::codegen(CodeGenerator &generator) {
    print("Const_part");
    for (auto const_expr : *const_expr_list) {
        const_expr->codegen(generator);
    }
    return nullptr;
}

Value *Const_expr::codegen(CodeGenerator &generator) {
    print("Const_expr");
    Constant *value = const_value->get_constant(generator);
    if(is_global){
        return new GlobalVariable(*generator.module, value->getType(), true, GlobalValue::ExternalLinkage, value, id->name);
    } else {
        auto alloc = generator.CreateEntryBlockAlloca(generator.getCurFunction(), id->name, value->getType());
        return generator.builder.CreateStore(value, alloc);
    }
}

Value *Const_value::codegen(CodeGenerator &generator) {
    print("Const_value::codegen");
    switch (base_type) {
        case Base_type::S_INT:
        {
            return generator.builder.getInt32(Value.int_value);
        }
        case Base_type::S_REAL:
            return llvm::ConstantFP::get(generator.builder.getDoubleTy(), Value.double_value);
        case Base_type::S_CHAR:
            return generator.builder.getInt8(Value.char_value);
        case Base_type::S_BOOLEN:
            return generator.builder.getInt1(Value.bool_value);
        default:
            return nullptr;
    }
}

Constant *Const_value::get_constant(CodeGenerator &generator){
    print("get_constant");
    switch (base_type) {
        case Base_type::S_INT:
            return generator.builder.getInt32(Value.int_value);
        case Base_type::S_REAL:
            return llvm::ConstantFP::get(generator.builder.getDoubleTy(), Value.double_value);
        case Base_type::S_CHAR:
            return generator.builder.getInt8(Value.char_value);
        case Base_type::S_BOOLEN:
            return generator.builder.getInt1(Value.bool_value);
        default:
            return nullptr;
    }
}

//Type part tbd
Value *Type_part::codegen(CodeGenerator &generator) {
    print("Type_part");
    for (auto type_definition : *type_decl_list) {
        type_definition->codegen(generator);
    }
    return nullptr;
}

Value *Type_definition::codegen(CodeGenerator &generator) {
    print("Type_definition");
    return nullptr;
}

Value *Type_decl::codegen(CodeGenerator &generator) {
    print("Type_decl");
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
                    return generator.builder.getInt32(0);
                case S_REAL:
                    return ConstantFP::get(generator.builder.getDoubleTy(), 0.0);
                case S_CHAR:
                    return generator.builder.getInt8(0);
                case S_BOOLEN:
                    return generator.builder.getInt1(0);
                default:
                    return nullptr;
            }
    }
    return nullptr;
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
            auto alloc = generator.CreateEntryBlockAlloca(generator.getCurFunction(), name->name, value->getType());
            return generator.builder.CreateStore(value, alloc);
        }
    }
    return nullptr;
}

Value *Const_range::codegen(CodeGenerator &generator) {
    print("Const_range");
    return nullptr;
}

Value *Enum_Type::codegen(CodeGenerator &generator) {
    print("Enum_Type_Decl");
    return nullptr;
}

Value *Enum_range::codegen(CodeGenerator &generator) {
    print("Enum_range");
    return nullptr;
}

Value *Array_type_decl::codegen(CodeGenerator &generator) {
    print("Array_type_decl");
    return nullptr;
}

Value *Field_decl::codegen(CodeGenerator &generator) {
    print("Field_decl");
    return nullptr;
}

Value *Record_type_decl::codegen(CodeGenerator &generator) {
    print("Record_type_decl");
    return nullptr;
}

Value *Identifier::codegen(CodeGenerator &generator) {
    print("Identifier");
    return new llvm::LoadInst(generator.getValue(name), "tmp", false, generator.builder.GetInsertBlock());
}