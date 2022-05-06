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
#include "../AST/AST.h"
#include <map>
#include <vector>
#include <iostream>

using namespace llvm;
using namespace std;

static llvm::LLVMContext context;
static llvm::IRBuilder<> builder(context);

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
    CodeGenerator(){
        module = new llvm::Module("main", context);
        addrSpace = module->getDataLayout().getAllocaAddrSpace();
    }
    void generateCode(Program& root);
    Function* getCurFunction(){return funcStack.back();}
    void pushFunction(Function* func){funcStack.push_back(func);}
    void popFunction(){funcStack.pop_back();}
};
