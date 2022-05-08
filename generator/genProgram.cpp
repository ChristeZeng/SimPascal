#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Program::codegen(CodeGenerator &generator) {
    print("Program::codegen");
    vector<llvm::Type*> argTypes;
    llvm::FunctionType * funcType = llvm::FunctionType::get(builder.getVoidTy(), makeArrayRef(argTypes), false);
    generator.mainFunction = llvm::Function::Create(funcType, llvm::GlobalValue::InternalLinkage, "main", generator.module);
    llvm::BasicBlock * basicBlock = llvm::BasicBlock::Create(context, "entrypoint", generator.mainFunction, 0);
    
    generator.pushFunction(generator.mainFunction);
    builder.SetInsertPoint(basicBlock);

    generator.printf = generator.createPrintf();
    generator.scanf = generator.createScanf();

    // routine->setGlobal();
    routine->codegen(generator);
    builder.CreateRetVoid();
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
    const_part->codegen(generator);
    type_part->codegen(generator);
    var_part->codegen(generator);
    for (auto routine : *routine_part) {
        routine->codegen(generator);
    }
    return nullptr;
}

Value *Routine_body::codegen(CodeGenerator &generator) {
    print("Routine_body::codegen");
    // forward(generator);
    for (auto statement : *stmt_list) {
        statement->codegen(generator);
    }
    // backward(generator);
    return nullptr;
}