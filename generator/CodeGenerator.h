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

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "../AST/AST.h"

using namespace llvm;
using namespace std;

static void print(string s) {
    cout << s << endl;
}

template <typename T> static std::string Print_value(T* value_or_type) {
    std::string str;
    llvm::raw_string_ostream stream(str);
    value_or_type->print(stream);
    return str;
}

class CodeGenerator{
public:
    LLVMContext context;
    IRBuilder<> builder;
    Module *module;
    Function *mainFunction;
    BasicBlock *block;
    unsigned int addrSpace;
    vector<Function*> functions;
    Function *read, *write;
    map<string, Array_type_decl*> arrMap;
    map<string, Record_type_decl*> recMap;
    CodeGenerator():builder(context) {
        module = new Module("main", context);
        addrSpace = module->getDataLayout().getAllocaAddrSpace();
    }
    void generateCode(Program& root);
    Function* getFunc(){return functions.back();}
    void pushFunc(Function* func){functions.push_back(func);}
    void popFunc(){functions.pop_back();}

    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type* type);
    Value* getValue(string & name);
    Function* setWrite();   
    Function* setRead();
};

Value *Binary_operation(Value* lv, Binary_op op, Value* rv, CodeGenerator &codeGenerator);

