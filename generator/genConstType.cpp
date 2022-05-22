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
        case Base_type::S_STRING:
            return codeGenerator.builder.CreateGlobalStringPtr(Value.string_value);
        default:
            return nullptr;
    }
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
        case Base_type::S_STRING:
            return codeGenerator.builder.CreateGlobalStringPtr(Value.string_value);
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

Type* Type_decl::get_llvm_type(CodeGenerator &codeGenerator){
    print("Type_decl");
    if(simple_type_decl) {
        return simple_type_decl->get_llvm_type(codeGenerator);
    } else if(array_type_decl) {
        return array_type_decl->get_llvm_type(codeGenerator);
    } else if(record_type_decl) {
        //TBD
    } else {
        return nullptr;
    }
}

llvm::Constant *Type_decl::get_init_value(CodeGenerator &codeGenerator, Const_value* v){
    if(v != nullptr){
        //TBD
    }else{
        if(simple_type_decl) {
            return Constant::getNullValue(simple_type_decl->get_llvm_type(codeGenerator));
        } else if(array_type_decl) {
            return array_type_decl->get_init_value(codeGenerator);
        } else if(record_type_decl) {
            //TBD
        } else {
            return nullptr;
    }
    }
    return nullptr;
}

llvm::Type* Simple_type_decl::get_llvm_type(CodeGenerator &codeGenerator){
    //print("get llvm type");
    switch(Type_name){
        case BASE:
            switch(base_type){
                case S_INT:
                    return codeGenerator.builder.getInt32Ty();
                case S_REAL:
                    return codeGenerator.builder.getDoubleTy();
                case S_CHAR:
                    return codeGenerator.builder.getInt8Ty();
                case S_BOOLEAN:
                    return codeGenerator.builder.getInt1Ty();
                default:
                    return nullptr;
            }
            case CONSTRANGE:
                return codeGenerator.builder.getInt32Ty();
                break;
        default:
            return nullptr;
    }
    return nullptr;
}

size_t Simple_type_decl::get_size(){ 
    return const_range->get_size(); 
}

llvm::Value *Simple_type_decl::get_idx(llvm::Value *originIdx, CodeGenerator &codeGenerator){\
    return const_range->get_abs_index(originIdx, codeGenerator);
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
                //print("cal size");
                const_range->cal_size();
                //return codeGenerator.builder.getInt32(const_range->get_size());
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
    Value *value = type_decl->codegen(codeGenerator);// if array, value is an element of type
    llvm::Type *varType;
    for(auto name : *name_list) {
        Constant *constant;
        if(type_decl->get_type() == Pas_type::ARRARY){
            print("Add array map");
            codeGenerator.arrMap[name->name] = type_decl->get_array_decl();
            varType = type_decl->get_llvm_type(codeGenerator);
            constant = type_decl->get_init_value(codeGenerator, nullptr);
            print("get constant");
        }else{
            varType = value->getType();
            constant = Constant::getNullValue(value->getType());
        }
        if(is_global){
            new GlobalVariable(*codeGenerator.module, varType, false, GlobalValue::ExternalLinkage, constant, name->name);
        } else {
            auto alloc = codeGenerator.CreateEntryBlockAlloca(codeGenerator.getFunc(), name->name, value->getType());
            codeGenerator.builder.CreateStore(value, alloc);
        }
    }
    return nullptr;
}

Value *Const_range::get_abs_index(llvm::Value* originIdx, CodeGenerator &codeGenerator){
    return Binary_operation(originIdx, Binary_op::S_MINUS, lower->codegen(codeGenerator), codeGenerator);
}

Value *Const_range::codegen(CodeGenerator &codeGenerator) {
    print("Const_range");
    // lower->get_constant(codeGenerator);
    // upper->get_constant(codeGenerator);
    
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

Pas_type Array_type_decl::get_idx_type(){
    return simple_type_decl->get_type(); 
}

int Array_type_decl::get_sub_size(){ return type_decl->get_array_size(); };

llvm::Type *Array_type_decl::get_llvm_type(CodeGenerator &codeGenerator){
    if(simple_type_decl->get_type() == CONSTRANGE){
        return ArrayType::get(type_decl->get_llvm_type(codeGenerator), simple_type_decl->get_size());
    }else{
        //enum TBD
    }
}

llvm::Type *Array_type_decl::get_sub_llvm_type(CodeGenerator &codeGenerator){
    return type_decl->get_llvm_type(codeGenerator);
}

llvm::Value* Array_type_decl::get_sub_idx(llvm::Value* originIdx, CodeGenerator &codeGenerator){
    return type_decl->get_idx(originIdx, codeGenerator);
}

llvm::Constant *Array_type_decl::get_init_value(CodeGenerator &codeGenerator){
    size_t size = simple_type_decl->get_size();
    if(type_decl->get_llvm_type(codeGenerator) == codeGenerator.builder.getInt32Ty()){
        print("type is int");
    }
    ArrayType* arrType = ArrayType::get(type_decl->get_llvm_type(codeGenerator), size);
    vector<llvm::Constant*> e;
    for(int i=0; i<=size; i++){
        e.push_back(type_decl->get_init_value(codeGenerator, nullptr));
    }          
    return ConstantArray::get(arrType, e);
}

Value *Array_type_decl::codegen(CodeGenerator &codeGenerator) {
    print("Array_type_decl");
    simple_type_decl->codegen(codeGenerator); //calculate size
    Pas_type idx_type = simple_type_decl->get_type();
    llvm::Type* e_type = simple_type_decl->get_llvm_type(codeGenerator);
    return type_decl->codegen(codeGenerator);
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