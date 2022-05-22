#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    root.codegen(*this);
    module->print(llvm::errs(), nullptr);
}

AllocaInst *CodeGenerator::CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type* type){
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(type, nullptr, VarName);
}

Value* CodeGenerator::getValue(string & name){
    Value *ret;
    for (auto iter = functions.rbegin(); iter != functions.rend(); iter++){
        ret=(*iter)->getValueSymbolTable()->lookup(name);
        if (ret != nullptr) return ret;
    }
    ret = module->getGlobalVariable(name);
    if (ret == nullptr) throw runtime_error("undefined variable: " + name);
    return ret;
}

Function* CodeGenerator::setWrite()
{
    vector<Type*> types;
    types.push_back(builder.getInt8PtrTy());
    auto printf_type = FunctionType::get(builder.getInt32Ty(), makeArrayRef(types), true);
    auto func = Function::Create(printf_type, Function::ExternalLinkage, Twine("printf"), module);
    func->setCallingConv(CallingConv::C);
    return func;
}

Function* CodeGenerator::setRead()
{
    auto type = FunctionType::get(builder.getInt32Ty(), true);
    auto func = Function::Create(type, Function::ExternalLinkage, Twine("scanf"), module);
    func->setCallingConv(CallingConv::C);
    return func;
}