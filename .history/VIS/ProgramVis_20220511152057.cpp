#include "VIS.h"

using namespace std;

string Program::Vis() {
    cout << "Program" << endl;
    return Out("Program", vector<string>{head->Vis(), routine->Vis()});
}

string Program_head::Vis() {
    return Out("Program_head", Out(name));
}

string Routine::Vis() {
    cout << "Routine" << endl;
    return Out("Routine", vector<string>{head->Vis(), body->Vis()});
}

string Routine_head::Vis() {
    cout << "Routine_head" << endl;
    vector<string> routine_part_out;
    for (auto routinedecl : *routine_part) {
        routine_part_out.push_back(routinedecl->Vis());
    }
    cout << "B" << endl;
    vector<string> children;
    if (const_part) {
        children.push_back(const_part->Vis());
    }
    if (type_part) {
        children.push_back(type_part->Vis());
    }
    if (var_part) {
        children.push_back(var_part->Vis());
    }
    children.push_back(Out("Routine_part", routine_part_out));
    return Out("Routine_head", children);
}

string Routine_body::Vis() {
    cout << "Routine_body" << endl;
    vector<string> stmt_out;
    for (auto stmt : *stmt_list) {
        stmt_out.push_back(stmt->Vis());
    }
    return Out("Routine_body", Out("Stmt_list", stmt_out));
}

string Va_para_list::Vis() {
    vector<string> para_out;
    for (auto name : *name_list) {
        para_out.push_back(name->Vis());
    }
    if (is_var_para) {
        return Out("Var_para_list", Out("Name_list", para_out));
    } 
    else {
        return Out("Val_para_list", Out("Name_list", para_out));
    }
}

string Para_decl::Vis() {
    return Out("Para_decl", vector<string>{va_para_list->Vis(), simple_type_decl->Vis()});
}

string Function_head::Vis() {
    vector<string> para_out;
    for (auto para : *parameters) {
        para_out.push_back(para->Vis());
    }
    if (!return_type) {
        return Out("Procedure_head", vector<string>{id->Vis(), Out("Para_decl_list", para_out)});
    }
    else {
        return Out("Function_head", vector<string>{id->Vis(), Out("Para_decl_list", para_out), return_type->Vis()});
    }
}

string Function_decl::Vis() {
    if(!subroutine) {
        return Out("Function_decl", vector<string>{function_head->Vis()});
    }
    else {
        return Out("Function_decl", vector<string>{function_head->Vis(), subroutine->Vis()});
    }
}