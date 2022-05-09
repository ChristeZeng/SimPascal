#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
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
    Value * result;
    for (auto it = funcStack.rbegin(); it != funcStack.rend(); it++)
    {
        if ((result=(*it)->getValueSymbolTable()->lookup(name)) != nullptr)
        {
            cout << "Find " << name << " in " << string((*it)->getName()) << endl;
            return result;
        }
        else
        {
            cout << "Not Find " << name << " in " << string((*it)->getName()) << endl;
        }
    }
    result = module->getGlobalVariable(name);
    if (result == nullptr)
    {
        cout<<"Undefined variable: " << name << endl;
    }
    cout << "Find " << name << " in global" << endl;
    return result;
}

Function* CodeGenerator::setWrite()
{
    vector<Type*> arg_types;
    arg_types.push_back(builder.getInt8PtrTy());
    auto printf_type = FunctionType::get(builder.getInt32Ty(), makeArrayRef(arg_types), true);
    auto func = Function::Create(printf_type, Function::ExternalLinkage, Twine("printf"), module.get());
    func->setCallingConv(CallingConv::C);
    return func;
}

Function* CodeGenerator::setRead()
{
    auto scanf_type = FunctionType::get(builder.getInt32Ty(), true);
    auto func = Function::Create(scanf_type, Function::ExternalLinkage, Twine("scanf"), module.get());
    func->setCallingConv(CallingConv::C);
    return func;
}