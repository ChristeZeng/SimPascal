#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void Const_part::setGlobalValues(){
    for (auto const_expr : *const_expr_list) {
        const_expr->setGlobalValues();
    }
}

void Var_part::setGlobalValues(){
    for(auto var_decl : *var_decl_list){
        var_decl->setGlobalValues();
    }
}

Value *Const_part::codegen(CodeGenerator &codeGenerator) {
    print("Const_part");
    for (auto const_expr : *const_expr_list) {
        const_expr->codegen(codeGenerator);
    }
    return nullptr;
}

Value *Const_expr::codegen(CodeGenerator &codeGenerator) {
    print("Const_expr");
    Constant *value = const_value->get_constant(codeGenerator);
    if(is_global){
        return new GlobalVariable(*codeGenerator.module, value->getType(), true, GlobalValue::ExternalLinkage, value, id->name);
    } else {
        auto alloc = codeGenerator.CreateEntryBlockAlloca(codeGenerator.getFunc(), id->name, value->getType());
        return codeGenerator.builder.CreateStore(value, alloc);
    }
}

Value *Const_value::codegen(CodeGenerator &codeGenerator) {
    print("Const_value::codegen");
    switch (base_type) {
        case Base_type::S_INT:
        {
            return codeGenerator.builder.getInt32(Value.int_value);
        }
        case Base_type::S_REAL:
            return llvm::ConstantFP::get(codeGenerator.builder.getDoubleTy(), Value.double_value);
        case Base_type::S_CHAR:
            return codeGenerator.builder.getInt8(Value.char_value);
        case Base_type::S_BOOLEAN:
            return codeGenerator.builder.getInt1(Value.bool_value);
        default:
            return nullptr;
    }
}

Base_type Const_value::get_type(){
    return base_type;
}

//need to make it look better
int Const_value::get_value(){
    switch (base_type) {
        case Base_type::S_INT:
            return Value.int_value;
        case Base_type::S_REAL:
            return Value.double_value;
        case Base_type::S_CHAR:
            return Value.char_value;
        case Base_type::S_BOOLEAN:
            return Value.bool_value;
        default:
            return 0;
    }
}

Constant *Const_value::get_constant(CodeGenerator &codeGenerator){
    print("get_constant");
    switch (base_type) {
        case Base_type::S_INT:
            return codeGenerator.builder.getInt32(Value.int_value);
        case Base_type::S_REAL:
            return llvm::ConstantFP::get(codeGenerator.builder.getDoubleTy(), Value.double_value);
        case Base_type::S_CHAR:
            return codeGenerator.builder.getInt8(Value.char_value);
        case Base_type::S_BOOLEAN:
            return codeGenerator.builder.getInt1(Value.bool_value);
        default:
            return nullptr;
    }
}

//Type part tbd
Value *Type_part::codegen(CodeGenerator &codeGenerator) {
    print("Type_part");
    for (auto type_definition : *type_decl_list) {
        type_definition->codegen(codeGenerator);
    }
    return nullptr;
}

Value *Type_definition::codegen(CodeGenerator &codeGenerator) {
    print("Type_definition");
    return nullptr;
}

Value *Type_decl::codegen(CodeGenerator &codeGenerator) {
    print("Type_decl");
    if(simple_type_decl) {
        return simple_type_decl->codegen(codeGenerator);
    } else if(array_type_decl) {
        return array_type_decl->codegen(codeGenerator);
    } else if(record_type_decl) {
        return record_type_decl->codegen(codeGenerator);
    } else {
        return nullptr;
    }
}

Value *Simple_type_decl::codegen(CodeGenerator &codeGenerator) {
    print("Simple_type_decl");
    switch(Type_name){
        case BASE:
            switch(base_type){
                case S_INT:
                    return codeGenerator.builder.getInt32(0);
                case S_REAL:
                    return ConstantFP::get(codeGenerator.builder.getDoubleTy(), 0.0);
                case S_CHAR:
                    return codeGenerator.builder.getInt8(0);
                case S_BOOLEAN:
                    return codeGenerator.builder.getInt1(0);
                default:
                    return nullptr;
            }
            case CONSTRANGE:
                const_range->codegen(codeGenerator);
                break;
        default:
            return nullptr;
    }
    return nullptr;
}

Value *Var_part::codegen(CodeGenerator &codeGenerator) {
    print("Var_part");
    for (auto var_decl : *var_decl_list) {
        var_decl->codegen(codeGenerator);
    }
    return nullptr;
}

Value *Var_decl::codegen(CodeGenerator &codeGenerator) {
    print("Var_decl");
    Value *value = type_decl->codegen(codeGenerator);
    for(auto name : *name_list) {
        if(is_global){
            Constant *constant = Constant::getNullValue(value->getType());
            return new GlobalVariable(*codeGenerator.module, value->getType(), false, GlobalValue::ExternalLinkage, constant, name->name);
        } else {
            auto alloc = codeGenerator.CreateEntryBlockAlloca(codeGenerator.getFunc(), name->name, value->getType());
            return codeGenerator.builder.CreateStore(value, alloc);
        }
    }
    return nullptr;
}

Value *Const_range::codegen(CodeGenerator &codeGenerator) {
    print("Const_range");
    // lower->get_constant(codeGenerator);
    // upper->get_constant(codeGenerator);
    int s;
    if(lower->get_type() == upper->get_type()){
        s = upper->get_value() - lower->get_value();
    }
    if(s <= 0){
        print("Invalid range");
    }
    size = s;
    std::cout << "size: " << size << endl;
    return nullptr;
}

Value *Enum_Type::codegen(CodeGenerator &codeGenerator) {
    print("Enum_Type_Decl");
    return nullptr;
}

Value *Enum_range::codegen(CodeGenerator &codeGenerator) {
    print("Enum_range");
    return nullptr;
}

Value *Array_type_decl::codegen(CodeGenerator &codeGenerator) {
    print("Array_type_decl");
    this->simple_type_decl->codegen(codeGenerator);
    Pas_type t = type_decl->get_type();
    if(t == Pas_type::BASE){
        Base_type Btype = type_decl->get_base_type();
        if(Btype == Base_type::S_INT)print("type: S_INT");
    }
    return nullptr;
}

Value *Field_decl::codegen(CodeGenerator &codeGenerator) {
    print("Field_decl");
    return nullptr;
}

Value *Record_type_decl::codegen(CodeGenerator &codeGenerator) {
    print("Record_type_decl");
    return nullptr;
}

Value *Identifier::codegen(CodeGenerator &codeGenerator) {
    print("Identifier");
    return new llvm::LoadInst(codeGenerator.getValue(name), "tmp", false, codeGenerator.builder.GetInsertBlock());
}