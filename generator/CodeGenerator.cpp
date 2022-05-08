#include "CodeGenerator.h"
#include "../AST/AST.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    root.codegen(*this);
    
    string s;
    raw_string_ostream os{s};
    module->print(os, nullptr);
}