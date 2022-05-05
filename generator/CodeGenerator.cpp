#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    root.codegen(*this);
}

Value *Const_part::codegen(CodeGenerator &generator) {
    for (auto const_expr : *const_expr_list) {
        const_expr->codegen(generator);
    }
    return nullptr;
}

Value *Const_expr::codegen(CodeGenerator &generator) {
    Value *value = const_value->codegen(generator);
    generator.addConstant(id->name, value);
    return nullptr;
}

Value *Const_value::codegen(CodeGenerator &generator) {
    switch (base_type) {
        case Base_type::S_INT:
            return ConstantInt::get(context, APInt(32, Value.int_value));
        case Base_type::S_REAL:
            return ConstantFP::get(context, APFloat(Value.double_value));
        case Base_type::S_CHAR:
            return ConstantInt::get(context, APInt(8, Value.char_value));
        case Base_type::S_BOOLEN:
            return ConstantInt::get(context, APInt(1, Value.bool_value));
        default:
            return nullptr;
    }
}

Value *Identifier::codegen(CodeGenerator &generator) {
    return generator.getConstant(name);
}

Value *Type_part::codegen(CodeGenerator &generator) {
    for (auto type_definition : *type_decl_list) {
        type_definition->codegen(generator);
    }
    return nullptr;
}

Value *Type_definition::codegen(CodeGenerator &generator) {
    generator.addType(id->name, type_decl->codegen(generator));
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
