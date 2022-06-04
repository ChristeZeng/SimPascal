#include "VIS.h"

using namespace std;

string Assign_stmt::Vis() {
    cout << "Assign_stmt" << endl; 
    if(fexpression) {
        return Out("Assign_stmt", vector<string>{lid->Vis(), lexpression->Vis(), fexpression->Vis(), rexpression->Vis()});
    }
    else if(!lexpression && !fid) {
        return Out("Assign_stmt", vector<string>{lid->Vis(), rexpression->Vis()});
    }
    else if(!fid) {
        return Out("Assign_stmt", vector<string>{lid->Vis(), lexpression->Vis(), rexpression->Vis()});
    }
    else {
        return Out("Assign_stmt", vector<string>{lid->Vis(), rexpression->Vis(), fid->Vis()});
    }
}

string Proc_stmt::Vis() {
    vector<string> Args_out;
    if (args_list) {
        for(auto arg : *args_list) {
            Args_out.push_back(arg->Vis());
        }
        return Out("Proc_stmt", vector<string>{id->Vis(), Out("Args_list", Args_out)});
    }
    return Out("Proc_stmt", id->Vis());
}

string Sysproc_stmt::Vis() {
    if (!args_list) {
        switch (func) {
            case S_READ:
                return Out("Sysproc_stmt", Out("READ"));
            case S_WRITE:
                return Out("Sysproc_stmt", Out("WRITE"));
            case S_WRITELN:
                return Out("Sysproc_stmt", Out("WRITELN"));
            case S_WRITE_10:
                return Out("Sysproc_stmt", Out("WRITE_10"));
            case S_WRITELN_10:
                return Out("Sysproc_stmt", Out("WRITELN_10"));
            case S_ADS:
                return Out("Sysproc_stmt", Out("ADS"));
            case S_CHR:
                return Out("Sysproc_stmt", Out("CHR"));
            case S_ORD:
                return Out("Sysproc_stmt", Out("ORD"));
            case S_ODD:
                return Out("Sysproc_stmt", Out("ODD"));
            case S_PRED:
                return Out("Sysproc_stmt", Out("PRED"));
            case S_SUCC:
                return Out("Sysproc_stmt", Out("SUCC"));
            case S_SQR:
                return Out("Sysproc_stmt", Out("SQR"));
            case S_SQRT:
                return Out("Sysproc_stmt", Out("SQRT"));
            default:
                return "";
        }
    }
    else {
        vector<string> Args_out;
        for(auto arg : *args_list) {
            Args_out.push_back(arg->Vis());
        }
        switch (func) {
            case S_READ:
                return Out("Sysproc_stmt", vector<string>{Out("READ"), Out("Args_list", Args_out)});
            case S_WRITE:
                return Out("Sysproc_stmt", vector<string>{Out("WRITE"), Out("Args_list", Args_out)});
            case S_WRITELN:
                return Out("Sysproc_stmt", vector<string>{Out("WRITELN"), Out("Args_list", Args_out)});
            case S_ADS:
                return Out("Sysproc_stmt", vector<string>{Out("ADS"), Out("Args_list", Args_out)});
            case S_CHR:
                return Out("Sysproc_stmt", vector<string>{Out("CHR"), Out("Args_list", Args_out)});
            case S_ORD:
                return Out("Sysproc_stmt", vector<string>{Out("ORD"), Out("Args_list", Args_out)});
            case S_ODD:
                return Out("Sysproc_stmt", vector<string>{Out("ODD"), Out("Args_list", Args_out)});
            case S_PRED:
                return Out("Sysproc_stmt", vector<string>{Out("PRED"), Out("Args_list", Args_out)});
            case S_SUCC:
                return Out("Sysproc_stmt", vector<string>{Out("SUCC"), Out("Args_list", Args_out)});
            case S_SQR:
                return Out("Sysproc_stmt", vector<string>{Out("SQR"), Out("Args_list", Args_out)});
            case S_SQRT:
                return Out("Sysproc_stmt", vector<string>{Out("SQRT"), Out("Args_list", Args_out)});
            default:
                return "";
        }
    }
}

string Func_stmt::Vis() {
    vector<string> Args_out;
    if (args_list) {
        for(auto arg : *args_list) {
            Args_out.push_back(arg->Vis());
        }
    }
    return Out("Func_stmt", vector<string>{id->Vis(), Out("Args_list", Args_out)});
}

string Sysfunc_stmt::Vis() {
    if (!args_list) {
        switch (func) {
            case S_READ:
                return Out("Sysfunc_stmt", Out("READ"));
            case S_WRITE:
                return Out("Sysfunc_stmt", Out("WRITE"));
            case S_WRITELN:
                return Out("Sysfunc_stmt", Out("WRITELN"));
            case S_ADS:
                return Out("Sysfunc_stmt", Out("ADS"));
            case S_CHR:
                return Out("Sysfunc_stmt", Out("CHR"));
            case S_ORD:
                return Out("Sysfunc_stmt", Out("ORD"));
            case S_ODD:
                return Out("Sysfunc_stmt", Out("ODD"));
            case S_PRED:
                return Out("Sysfunc_stmt", Out("PRED"));
            case S_SUCC:
                return Out("Sysfunc_stmt", Out("SUCC"));
            case S_SQR:
                return Out("Sysfunc_stmt", Out("SQR"));
            case S_SQRT:
                return Out("Sysfunc_stmt", Out("SQRT"));
            default:
                return "";
        }
    }
    else {
        vector<string> Args_out;
        for(auto arg : *args_list) {
            Args_out.push_back(arg->Vis());
        }
        switch (func) {
            case S_READ:
                return Out("Sysfunc_stmt", vector<string>{Out("READ"), Out("Args_list", Args_out)});
            case S_WRITE:
                return Out("Sysfunc_stmt", vector<string>{Out("WRITE"), Out("Args_list", Args_out)});
            case S_WRITELN:
                return Out("Sysfunc_stmt", vector<string>{Out("WRITELN"), Out("Args_list", Args_out)});
            case S_ADS:
                return Out("Sysfunc_stmt", vector<string>{Out("ADS"), Out("Args_list", Args_out)});
            case S_CHR:
                return Out("Sysfunc_stmt", vector<string>{Out("CHR"), Out("Args_list", Args_out)});
            case S_ORD:
                return Out("Sysfunc_stmt", vector<string>{Out("ORD"), Out("Args_list", Args_out)});
            case S_ODD:
                return Out("Sysfunc_stmt", vector<string>{Out("ODD"), Out("Args_list", Args_out)});
            case S_PRED:
                return Out("Sysfunc_stmt", vector<string>{Out("PRED"), Out("Args_list", Args_out)});
            case S_SUCC:
                return Out("Sysfunc_stmt", vector<string>{Out("SUCC"), Out("Args_list", Args_out)});
            case S_SQR:
                return Out("Sysfunc_stmt", vector<string>{Out("SQR"), Out("Args_list", Args_out)});
            case S_SQRT:
                return Out("Sysfunc_stmt", vector<string>{Out("SQRT"), Out("Args_list", Args_out)});
            default:
                return "";
        }
    }
}

string If_stmt::Vis() {
    if(!else_stmt) {
        return Out("if_stmt", vector<string>{expression->Vis(), stmt->Vis()});
    }
    else {
        return Out("if_stmt", vector<string>{expression->Vis(), stmt->Vis(), else_stmt->Vis()});
    }
}

string Repeat_stmt::Vis() {
    vector<string> Stmts_out;
    for(auto stmt : *stmt_list) {
        Stmts_out.push_back(stmt->Vis());
    }
    return Out("repeat_stmt", vector<string>{expression->Vis(), Out("Stmt_list", Stmts_out)});
}

string While_stmt::Vis() {
    return Out("while_stmt", vector<string>{expression->Vis(), stmt->Vis()});
}

string Direction::Vis() {
    switch (direction_type) {
        case S_TO:
            return Out("Direction", Out("TO"));
        case S_DOWNTO:
            return Out("Direction", Out("DOWNTO"));
        default:
            return "";
    }
}

string Case_expr::Vis() {
    if(!id) {
        return Out("case_expr", vector<string>{const_value->Vis(), stmt->Vis()});
    }
    else {
        return Out("case_expr", vector<string>{id->Vis(), stmt->Vis()});
    }
}

string Case_stmt::Vis() {
    vector<string> Case_expr_out;
    for(auto case_expr : *case_expr_list) {
        Case_expr_out.push_back(case_expr->Vis());
    }
    return Out("case_stmt", vector<string>{expression->Vis(), Out("Case_expr_list", Case_expr_out)});
}

string Goto_stmt::Vis() {
    return Out("goto_stmt", Out(to_string(label)));
}

string For_stmt::Vis() {
    return Out("for_stmt", vector<string>{id->Vis(), Out_expression->Vis(), direction->Vis(), In_expression->Vis(), stmt->Vis()});
}

string Binary_expression::Vis() {
    switch(op) {
        case S_PLUS:
            return Out("binary_expression", vector<string>{Out("PLUS"), lexpression->Vis(), rexpression->Vis()});
        case S_MINUS:
            return Out("binary_expression", vector<string>{Out("MINUS"), lexpression->Vis(), rexpression->Vis()});
        case S_MUL:
            return Out("binary_expression", vector<string>{Out("MUL"), lexpression->Vis(), rexpression->Vis()});
        case S_DIV:
            return Out("binary_expression", vector<string>{Out("DIV"), lexpression->Vis(), rexpression->Vis()});
        case S_MOD:
            return Out("binary_expression", vector<string>{Out("MOD"), lexpression->Vis(), rexpression->Vis()});
        case S_AND:
            return Out("binary_expression", vector<string>{Out("AND"), lexpression->Vis(), rexpression->Vis()});
        case S_OR:
            return Out("binary_expression", vector<string>{Out("OR"), lexpression->Vis(), rexpression->Vis()});
        case S_EQ:
            return Out("binary_expression", vector<string>{Out("EQ"), lexpression->Vis(), rexpression->Vis()});
        case S_NE:
            return Out("binary_expression", vector<string>{Out("NE"), lexpression->Vis(), rexpression->Vis()});
        case S_LT:
            return Out("binary_expression", vector<string>{Out("LT"), lexpression->Vis(), rexpression->Vis()});
        case S_GT:
            return Out("binary_expression", vector<string>{Out("GT"), lexpression->Vis(), rexpression->Vis()});
        case S_LE:
            return Out("binary_expression", vector<string>{Out("LE"), lexpression->Vis(), rexpression->Vis()});
        case S_GE:
            return Out("binary_expression", vector<string>{Out("GE"), lexpression->Vis(), rexpression->Vis()});
        case S_NOT:
            return Out("binary_expression", vector<string>{Out("NOT"), lexpression->Vis()});
        default:
            return "";
    }
}

string Array_access::Vis() {
    if (findex)
        return Out("array_access", vector<string>{id->Vis(), index->Vis(), findex->Vis()});
    else
        return Out("array_access", vector<string>{id->Vis(), index->Vis()});
}

string Record_access::Vis() {
    return Out("record_access", vector<string>{id->Vis(), field_id->Vis()});
}