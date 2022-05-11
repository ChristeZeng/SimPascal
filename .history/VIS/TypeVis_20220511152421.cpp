#include "VIS.h"

using namespace std;

string Simple_type_decl::Vis() {
    cout << "Simple_type_decl" << endl;
    if (id) {
        return Out("UserDefinedType", id->Vis());
    }
    else if (const_range) {
        return Out("ConstRangeType", const_range->Vis());
    }
    else if (enum_range) {
        return Out("EnumRangeType", enum_range->Vis());
    }
    else if (enum_type) {
        return Out("EnumType", enum_type->Vis());
    }
    else {
        switch (base_type) {
            case S_INT:
                return Out("IntType");
            case S_REAL:
                return Out("RealType");
            case S_CHAR:
                return Out("CharType");
            case S_BOOLEN:
                return Out("BoolenType");
            default:
                return Out("VoidType");
        }
    }
}

string Type_part::Vis() {
    vector<string> children;
    for (auto &type_decl : *type_decl_list) {
        children.push_back(type_decl->Vis());
    }
    return Out("TypePart", Out("Type_decl_list", children));
}

string Type_definition::Vis() {
    return Out("Type_definition", vector<string>{id->Vis(), type_decl->Vis()});
}

string Const_range::Vis() {
    return Out("ConstRange", vector<string>{lower->Vis(), upper->Vis()});
}

string Enum_Type::Vis() {
    vector<string> children;
    for (auto &id : *name_list) {
        children.push_back(id->Vis());
    }
    return Out("EnumType", Out("Name_list", children));
}

string Enum_range::Vis() {
    return Out("EnumRange", vector<string>{lower_id->Vis(), upper_id->Vis()});
}

string Array_type_decl::Vis() {
    return Out("ArrayTypeDecl", vector<string>{simple_type_decl->Vis(), type_decl->Vis()});
}

string Field_decl::Vis() {
    vector<string> children;
    for(auto &name : *name_list) {
        children.push_back(name->Vis());
    }
    return Out("FieldDecl", vector<string>{Out("Name_list", children), type_decl->Vis()});
}

string Record_type_decl::Vis() {
    vector<string> children;
    for(auto &field_decl : *field_decl_list) {
        children.push_back(field_decl->Vis());
    }
    return Out("RecordTypeDecl", Out("Field_decl_list", children));
}

string Type_decl::Vis() {
    cout << "Type_decl" << endl;
    if (array_type_decl) {
        cout << "Array_type_decl" << endl;
        return Out("Type_decl", array_type_decl->Vis());
    }
    else if (record_type_decl) {
        cout << "Record_type_decl" << endl;
        return Out("Type_decl", record_type_decl->Vis());
    }
    else {
        return Out("Type_decl", simple_type_decl->Vis());
    }
}

string Var_decl::Vis() {
    cout << "Var_decl" << endl;
    vector<string> children;
    for(auto &name: *name_list) {
        children.push_back(name->Vis());
    }
    return Out("Var_decl", vector<string>{Out("Name_list", children), type_decl->Vis()});
}

string Var_part::Vis() {
    cout << "Var_part" << endl;
    vector<string> children;
    for(auto &var_decl : *var_decl_list) {
        children.push_back(var_decl->Vis());
    }
    return Out("Var_part", Out("Var_decl_list", children));
}