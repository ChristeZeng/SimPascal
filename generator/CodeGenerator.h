#pragma once
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Target/TargetMachine.h>

#include "../AST/AST.h"
#include "../AST/Node.h"
#include "../AST/Const.h"
#include "../AST/Type.h"
#include "../AST/Stmt.h"
#include "../AST/Program.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace llvm;
using namespace std;

class Program;

static LLVMContext context;
static IRBuilder<> builder(context);

static void print(string s) {
    cout << s << endl;
}

class CodeGenerator{
public:
    Module *module;
    Function *mainFunction;
    BasicBlock *block;
    unsigned int addrSpace;
    vector<Function*> funcStack;
    Function *printf, *scanf;
    CodeGenerator(){
        module = new Module("main", context);
        addrSpace = module->getDataLayout().getAllocaAddrSpace();
    }
    void generateCode(Program& root);
    Function* getCurFunction(){return funcStack.back();}
    void pushFunction(Function* func){funcStack.push_back(func);}
    void popFunction(){funcStack.pop_back();}

    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type* type){
        IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
        return TmpB.CreateAlloca(type, nullptr, VarName);
    }

    Value* getValue(string & name){
        Value * result = nullptr;
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
        if ((result = module->getGlobalVariable(name)) == nullptr)
        {
            throw logic_error("[ERROR]Undeclared variable: " + name);
        }
        cout << "Find " << name << " in global" << endl;
        return result;
    }

    Function* createPrintf()
    {
        vector<Type*> arg_types;
        arg_types.push_back(builder.getInt8PtrTy());
        auto printf_type = FunctionType::get(builder.getInt32Ty(), makeArrayRef(arg_types), true);
        auto func = Function::Create(printf_type, Function::ExternalLinkage, Twine("printf"), module);
        func->setCallingConv(CallingConv::C);
        return func;
    }
    
    Function* createScanf()
    {
        auto scanf_type = FunctionType::get(builder.getInt32Ty(), true);
        auto func = Function::Create(scanf_type, Function::ExternalLinkage, Twine("scanf"), module);
        func->setCallingConv(CallingConv::C);
        return func;
    }
};
