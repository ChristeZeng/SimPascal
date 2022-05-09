#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Program::codegen(CodeGenerator &generator) {
    print("Program::codegen");
    vector<llvm::Type*> argTypes;
    llvm::FunctionType * funcType = llvm::FunctionType::get(generator.builder.getVoidTy(), makeArrayRef(argTypes), false);
    generator.mainFunction = llvm::Function::Create(funcType, llvm::GlobalValue::InternalLinkage, "main", generator.module.get());
    llvm::BasicBlock * basicBlock = llvm::BasicBlock::Create(generator.context, "entry", generator.mainFunction, 0);
    
    generator.pushFunction(generator.mainFunction);
    generator.builder.SetInsertPoint(basicBlock);

    generator.write = generator.setWrite();
    generator.read = generator.setRead();

    // routine->setGlobal();
    routine->codegen(generator);
    generator.builder.CreateRetVoid();
    generator.popFunction();
    
    return nullptr;
}
Value *Program_head::codegen(CodeGenerator &generator) {
    print("Program_head::codegen");
    return nullptr;
}

Value *Routine::codegen(CodeGenerator &generator) {
    print("Routine::codegen");
    head->codegen(generator);
    body->codegen(generator);
    return nullptr;
}

Value *Routine_head::codegen(CodeGenerator &generator) {
    print("Routine_head::codegen");
    if(const_part!=nullptr) const_part->codegen(generator);
    if(type_part!=nullptr) type_part->codegen(generator);
    if(var_part!=nullptr) var_part->codegen(generator);
    for (auto routine : *routine_part) {
        routine->codegen(generator);
    }
    return nullptr;
}

Value *Routine_body::codegen(CodeGenerator &generator) {
    print("Routine_body::codegen");
    for (auto statement : *stmt_list) {
        statement->codegen(generator);
    }
    return nullptr;
}