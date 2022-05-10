#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Assign_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Assign_stmt::codegen");
    if((!lexpression)&&(!fid)){
        return codeGenerator.builder.CreateStore(rexpression->codegen(codeGenerator), codeGenerator.getValue(lid->name));
    } else if(lexpression) {
        //tbd
    } else if(fid) {
        //tbd
    }
    return nullptr;
}

Value *Proc_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Proc_stmt::codegen");
    Function *function = codeGenerator.module->getFunction(id->name);
    if (function == nullptr) cout<<"Function not find: "<<id->name<<endl;
    vector<Value*> args;
    Function::arg_iterator iter =  function->arg_begin();
    for (auto arg : *args_list){
        //value pointer tbd
        args.push_back(arg->codegen(codeGenerator));
        iter++;
    }
    return codeGenerator.builder.CreateCall(function, args, "calltmp");;
}

Value *Func_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Func_stmt::codegen");
    Function *function = codeGenerator.module->getFunction(id->name);
    if (function == nullptr) cout<<"Function not find: "<<id->name<<endl;
    vector<Value*> args;
    Function::arg_iterator iter =  function->arg_begin();
    for (auto arg : *args_list){
        //value pointer tbd
        args.push_back(arg->codegen(codeGenerator));
        iter++;
    }
    Value* res = codeGenerator.builder.CreateCall(function, args, "calltmp");
    return res;
}

Value *Sysproc_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Sysproc_stmt::codegen");
    string Format = "";
    vector<Value*> sysargs;
    switch (func){
        case SysFunc::S_READ:
        {
            auto arg = args_list->at(0);
            Value *addr, *argValue;
            addr = codeGenerator.getValue(dynamic_cast<Identifier*>(arg)->name);
            argValue = arg->codegen(codeGenerator);
            if (argValue->getType() == codeGenerator.builder.getInt32Ty()||
                argValue->getType() == codeGenerator.builder.getInt1Ty()) Format = Format + "%d";
            else if (argValue->getType() == codeGenerator.builder.getInt8Ty()) Format = Format + "%c";
            else if (argValue->getType()->isDoubleTy()) Format = Format + "%lf";
            else throw logic_error("Read Type Error!");
            sysargs.push_back(addr);
            sysargs.insert(sysargs.begin(), codeGenerator.builder.CreateGlobalStringPtr(Format));
            return codeGenerator.builder.CreateCall(codeGenerator.read, sysargs, "read");
            break;
        }
        case SysFunc::S_WRITE:
        {
            for (auto arg : *args_list){
                Value* argValue = arg->codegen(codeGenerator);
                if (argValue->getType() == codeGenerator.builder.getInt32Ty()||
                    argValue->getType() == codeGenerator.builder.getInt1Ty()) Format = Format + "%d";
                else if (argValue->getType() == codeGenerator.builder.getInt8Ty()) Format = Format + "%c";
                else if (argValue->getType()->isDoubleTy()) Format = Format + "%lf";
                else throw logic_error("Write Type Error!");

                sysargs.push_back(argValue);
            }
            auto strConst = ConstantDataArray::getString(codeGenerator.context, Format.c_str());
            auto StrVar = new GlobalVariable(*(codeGenerator.module), ArrayType::get(codeGenerator.builder.getInt8Ty(), Format.size() + 1), true, GlobalValue::ExternalLinkage, strConst, ".str");
            auto nullvalue = Constant::getNullValue(codeGenerator.builder.getInt32Ty());
            Constant* indices[] = {nullvalue, nullvalue};
            auto reference = ConstantExpr::getGetElementPtr(StrVar->getType()->getElementType(), StrVar, indices);

            sysargs.insert(sysargs.begin(), reference);
            return codeGenerator.builder.CreateCall(codeGenerator.write, makeArrayRef(sysargs), "write");
            break;
        }
        case SysFunc::S_WRITELN:
        {
            for (auto arg : *args_list){
                Value* argValue = arg->codegen(codeGenerator);
                if (argValue->getType() == codeGenerator.builder.getInt32Ty()||
                    argValue->getType() == codeGenerator.builder.getInt1Ty()) Format = Format + "%d";
                else if (argValue->getType() == codeGenerator.builder.getInt8Ty()) Format = Format + "%c";
                else if (argValue->getType()->isDoubleTy()) Format = Format + "%lf";
                else throw logic_error("Write Type Error!");
                
                sysargs.push_back(argValue);
            }
            Format += "\n";
            auto strConst = ConstantDataArray::getString(codeGenerator.context, Format.c_str());
            auto StrVar = new GlobalVariable(*(codeGenerator.module), ArrayType::get(codeGenerator.builder.getInt8Ty(), Format.size() + 1), true, GlobalValue::ExternalLinkage, strConst, ".str");
            auto nullvalue = Constant::getNullValue(codeGenerator.builder.getInt32Ty());
            Constant* indices[] = {nullvalue, nullvalue};
            auto reference = ConstantExpr::getGetElementPtr(StrVar->getType()->getElementType(), StrVar, indices);
            
            sysargs.insert(sysargs.begin(), reference);
            Value *res = codeGenerator.builder.CreateCall(codeGenerator.write, makeArrayRef(sysargs), "write");
            return res;
            break;
        }
        default:
            return nullptr;
            break;
    }
}

Value *Sysfunc_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Sysfunc_stmt::codegen");
    return nullptr;
}

Value *If_stmt::codegen(CodeGenerator &codeGenerator) {
    print("If_stmt::codegen");
    return nullptr;
}

//tbd
Value *Repeat_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Repeat_stmt::codegen");
    return nullptr;
}

Value *While_stmt::codegen(CodeGenerator &codeGenerator) {
    print("while_stmt::codegen");
    return nullptr;
}

Value *For_stmt::codegen(CodeGenerator &codeGenerator) {
    print("for_stmt::codegen");
    return nullptr;
}

Value *Direction::codegen(CodeGenerator &codeGenerator) {
    print("direction::codegen");
    return nullptr;
}

Value *Case_stmt::codegen(CodeGenerator &codeGenerator) {
    print("case_stmt::codegen");
    return nullptr;
}

Value *Case_expr::codegen(CodeGenerator &codeGenerator) {
    print("case_expr_list::codegen");
    return nullptr;
}

Value *Goto_stmt::codegen(CodeGenerator &codeGenerator) {
    print("goto_stmt::codegen");
    return nullptr;
}

