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

using namespace llvm;
using namespace std;

static llvm::LLVMContext context;
static llvm::IRBuilder<> builder(context);

class CodeGenerator{
public:
    Module *module;
    Function *function;
    BasicBlock *block;
    map<string, Value *> constants;
    map<string, Value*> types;
    unsigned int addrSpace;
    CodeGenerator(){
        module = new llvm::Module("main", context);
        addrSpace = module->getDataLayout().getAllocaAddrSpace();
    }
    void generateCode(Program& root);
    void addConstant(string name, Value *value) {constants[name] = value;}
    Value *getConstant(string name) {return constants[name];}
    void addType(string name, Value *type) {types[name] = type;}
};
