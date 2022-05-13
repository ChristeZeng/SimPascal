#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

Value *Assign_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Assign_stmt::codegen");
    if((!lexpression)&&(!fid)){ //id assignment
        print("Assign_stmt::codegen: id");
        return codeGenerator.builder.CreateStore(rexpression->codegen(codeGenerator), codeGenerator.getValue(lid->name));
    } else if(lexpression) { // array assignment
        print("Assign_stmt::codegen: array");
        return codeGenerator.builder.CreateStore(rexpression->codegen(codeGenerator), (new Array_access(lid, lexpression))->getPtr(codeGenerator));
    } else if(fid) { //record assignment
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
    Value *cond = expression->codegen(codeGenerator);
    if (cond->getType() != codeGenerator.builder.getInt1Ty()) throw logic_error("If condition type error!");
    cond = codeGenerator.builder.CreateICmpNE(cond, ConstantInt::get(codeGenerator.context, APInt(1, 0)), "ifcond");

    Function *function = codeGenerator.getFunc();
    BasicBlock *mergeblock = BasicBlock::Create(codeGenerator.context, "ifcont", function);
    BasicBlock *thenblock = BasicBlock::Create(codeGenerator.context, "then", function);
    BasicBlock *elseblock = BasicBlock::Create(codeGenerator.context, "else", function);
    codeGenerator.builder.CreateCondBr(cond, thenblock, elseblock);

    codeGenerator.builder.SetInsertPoint(thenblock);
    stmt->codegen(codeGenerator);
    codeGenerator.builder.CreateBr(mergeblock);
    thenblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(elseblock);
    if(else_stmt) else_stmt->codegen(codeGenerator);
    codeGenerator.builder.CreateBr(mergeblock);
    elseblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(mergeblock);

    return nullptr;
}

Value *While_stmt::codegen(CodeGenerator &codeGenerator) {
    print("while_stmt::codegen");
    Function *function = codeGenerator.getFunc();
    BasicBlock *mergeblock = BasicBlock::Create(codeGenerator.context, "whilecont", function);
    BasicBlock *bodyblock = BasicBlock::Create(codeGenerator.context, "body", function);
    BasicBlock *condblock = BasicBlock::Create(codeGenerator.context, "cond", function);

    codeGenerator.builder.CreateBr(condblock);
    codeGenerator.builder.SetInsertPoint(condblock);
    Value *cond = expression->codegen(codeGenerator);
    if (cond->getType() != codeGenerator.builder.getInt1Ty()) throw logic_error("While condition type error!");
    cond = codeGenerator.builder.CreateICmpNE(cond, ConstantInt::get(codeGenerator.context, APInt(1, 0)), "whilecond");
    codeGenerator.builder.CreateCondBr(cond, bodyblock, mergeblock);

    codeGenerator.builder.SetInsertPoint(bodyblock);
    stmt->codegen(codeGenerator);

    codeGenerator.builder.CreateBr(condblock);
    bodyblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(mergeblock);
    return nullptr;
}

Value *Repeat_stmt::codegen(CodeGenerator &codeGenerator) {
    print("Repeat_stmt::codegen");

    Function *function = codeGenerator.getFunc();
    BasicBlock *mergeblock = BasicBlock::Create(codeGenerator.context, "repeatcont", function);
    BasicBlock *bodyblock = BasicBlock::Create(codeGenerator.context, "body", function);
    BasicBlock *condblock = BasicBlock::Create(codeGenerator.context, "cond", function);

    codeGenerator.builder.CreateBr(bodyblock);
    codeGenerator.builder.SetInsertPoint(bodyblock);

    for(auto stmt : *stmt_list){
        stmt->codegen(codeGenerator);
    }

    codeGenerator.builder.CreateBr(condblock);
    bodyblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(condblock);
    Value *cond = expression->codegen(codeGenerator);
    if (cond->getType() != codeGenerator.builder.getInt1Ty()) throw logic_error("Repeat condition type error!");
    cond = codeGenerator.builder.CreateICmpNE(cond, ConstantInt::get(codeGenerator.context, APInt(1, 1)), "repeatcond");
    codeGenerator.builder.CreateCondBr(cond, bodyblock, mergeblock);

    codeGenerator.builder.SetInsertPoint(mergeblock);
    return nullptr;
}

Value *Direction::codegen(CodeGenerator &codeGenerator) {
    print("Direction::codegen");
    if(direction_type == Direction_type::S_TO) return ConstantInt::get(codeGenerator.context, APInt(1, 0));
    else return ConstantInt::get(codeGenerator.context, APInt(1, 1));
}

Value *For_stmt::codegen(CodeGenerator &codeGenerator) {
    print("for_stmt::codegen");
    Function *function = codeGenerator.getFunc();
    BasicBlock *mergeblock = BasicBlock::Create(codeGenerator.context, "forcont", function);
    BasicBlock *bodyblock = BasicBlock::Create(codeGenerator.context, "body", function);
    BasicBlock *condblock = BasicBlock::Create(codeGenerator.context, "cond", function);
    Value *intValue = codeGenerator.getValue(id->name);
    Value *initValue = Out_expression->codegen(codeGenerator);
    Value *endValue = In_expression->codegen(codeGenerator);

    codeGenerator.builder.CreateBr(condblock);
    codeGenerator.builder.SetInsertPoint(condblock);
    bool dirValue = direction->getDir();
    Value *condValue = id->codegen(codeGenerator);
    Value *cond;
    if(dirValue) {
        cond = codeGenerator.builder.CreateICmpSLT(condValue, endValue, "forcond");
    } else {
        cond = codeGenerator.builder.CreateICmpSGT(condValue, endValue, "forcond");
    }
    cond = codeGenerator.builder.CreateICmpNE(cond, ConstantInt::get(codeGenerator.context, APInt(1, 0)), "forcond");
    codeGenerator.builder.CreateCondBr(cond, bodyblock, mergeblock);
    condblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(bodyblock);
    stmt->codegen(codeGenerator);
    Value *nextValue = codeGenerator.builder.CreateAdd(condValue, codeGenerator.builder.getInt32(dirValue?1:-1), "next");
    codeGenerator.builder.CreateStore(nextValue, intValue);
    codeGenerator.builder.CreateBr(condblock);
    bodyblock = codeGenerator.builder.GetInsertBlock();

    codeGenerator.builder.SetInsertPoint(mergeblock);
    return nullptr;
}

Value *Case_stmt::codegen(CodeGenerator &codeGenerator) {
    print("case_stmt::codegen");
    Function *function = codeGenerator.getFunc();
    Value *expValue = expression->codegen(codeGenerator);
    vector<BasicBlock *> swtichblocks, caseblocks;
    BasicBlock *mergeblock = BasicBlock::Create(codeGenerator.context, "casecont", function);
    for(int i=0; i<(*case_expr_list).size(); i++) {
        swtichblocks.push_back(BasicBlock::Create(codeGenerator.context, "switch"+to_string(i), function));
        caseblocks.push_back(BasicBlock::Create(codeGenerator.context, "case"+to_string(i), function));
    }
    int i=0;
    for (auto expr : *case_expr_list) {
        if(i==0) codeGenerator.builder.CreateBr(swtichblocks[0]);
        codeGenerator.builder.SetInsertPoint(swtichblocks[i]);
        Value *cond = expr->getValue(codeGenerator);
        cond = codeGenerator.builder.CreateICmpEQ(cond, expValue, "casecond");
        if(expr!=case_expr_list->back()) {
            codeGenerator.builder.CreateCondBr(cond, caseblocks[i], swtichblocks[i+1]);
        } else {
            codeGenerator.builder.CreateCondBr(cond, caseblocks[i], mergeblock);
        }

        codeGenerator.builder.SetInsertPoint(caseblocks[i]);
        expr->codegen(codeGenerator);
        codeGenerator.builder.CreateBr(mergeblock);
        i++;
    }

    codeGenerator.builder.SetInsertPoint(mergeblock);
    return nullptr;
}

Value *Case_expr::codegen(CodeGenerator &codeGenerator) {
    print("case_expr_list::codegen");
    stmt->codegen(codeGenerator); 
    return nullptr;
}

Value *Case_expr::getValue(CodeGenerator &codeGenerator) {
    Value *ret;
    if(id){
        ret = id->codegen(codeGenerator);
    } else if(const_value){
        ret = const_value->codegen(codeGenerator);
    } else {
        ret = nullptr;
    }
    return ret;
}


Value *Goto_stmt::codegen(CodeGenerator &codeGenerator) {
    print("goto_stmt::codegen");
    return nullptr;
}

