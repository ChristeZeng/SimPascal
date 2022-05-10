#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    cout<<"Begin Gen"<<endl;
    root.codegen(*this);
    cout<<"Finish Gen"<<endl;
    
    // string s;
    // raw_string_ostream os(s);
    // module->print(os, nullptr);
    // cout<<s<<endl;
    module->print(llvm::errs(), nullptr);
    // cout<<"Finish"<<endl;
}

AllocaInst *CodeGenerator::CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type* type){
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(type, nullptr, VarName);
}

Value* CodeGenerator::getValue(string & name){
    Value *ret;
    for (auto iter = functions.rbegin(); iter != functions.rend(); iter++){
        ret=(*iter)->getValueSymbolTable()->lookup(name);
        if (ret != nullptr){
            cout<<"Find "<<name<<" in "<<string((*iter)->getName())<<endl;
            return ret;
        }else{
            cout<<"Not Find "<<name<<" in "<<string((*iter)->getName())<< endl;
        }
    }
    ret = module->getGlobalVariable(name);
    if (ret == nullptr) cout<<"Undefined variable: "<<name<<endl;
    cout<<"Find "<<name<<" in global"<<endl;
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