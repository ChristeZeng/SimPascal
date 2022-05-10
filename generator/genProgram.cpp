#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Program::codegen(CodeGenerator &codeGenerator) {
    print("Program::codegen");
    vector<Type*> argTypes;
    FunctionType * funcType = FunctionType::get(codeGenerator.builder.getVoidTy(), makeArrayRef(argTypes), false);
    codeGenerator.mainFunction = Function::Create(funcType, GlobalValue::InternalLinkage, "main", codeGenerator.module);
    BasicBlock * basicBlock = BasicBlock::Create(codeGenerator.context, "entrypoint", codeGenerator.mainFunction, 0);
    
    codeGenerator.pushFunc(codeGenerator.mainFunction);
    codeGenerator.builder.SetInsertPoint(basicBlock);

    codeGenerator.write = codeGenerator.setWrite();
    codeGenerator.read = codeGenerator.setRead();

    routine->setGlobalValues();
    routine->codegen(codeGenerator);
    codeGenerator.builder.CreateRetVoid();
    codeGenerator.popFunc();
    
    return nullptr;
}
Value *Program_head::codegen(CodeGenerator &codeGenerator) {
    print("Program_head::codegen");
    return nullptr;
}

void Routine_head::setGlobalValues(){ 
    if (const_part) const_part->setGlobalValues();
    if (var_part) var_part->setGlobalValues();
}

void Routine::setGlobalValues(){ 
    head->setGlobalValues();
}

Value *Routine::codegen(CodeGenerator &codeGenerator) {
    print("Routine::codegen");
    head->codegen(codeGenerator);
    body->codegen(codeGenerator);
    return nullptr;
}

Value *Routine_head::codegen(CodeGenerator &codeGenerator) {
    print("Routine_head::codegen");
    if(const_part!=nullptr) const_part->codegen(codeGenerator);
    if(type_part!=nullptr) type_part->codegen(codeGenerator);
    if(var_part!=nullptr) var_part->codegen(codeGenerator);
    for (auto routine : *routine_part) {
        routine->codegen(codeGenerator);
    }
    return nullptr;
}

Value *Routine_body::codegen(CodeGenerator &codeGenerator) {
    print("Routine_body::codegen");
    for (auto statement : *stmt_list) {
        statement->codegen(codeGenerator);
    }
    return nullptr;
}