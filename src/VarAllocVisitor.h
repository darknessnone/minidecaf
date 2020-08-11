#pragma once

#include "MiniDecafBaseVisitor.h"
#include <string>
#include <unordered_map>
#include <tuple>

template<typename T> 
using symTab = std::unordered_map<std::string, std::unordered_map<std::string, T> >;


class VarAllocVisitor : public MiniDecafBaseVisitor {
public:
    antlrcpp::Any visitToplv(MiniDecafParser::ToplvContext *ctx);
    antlrcpp::Any visitProg(MiniDecafParser::ProgContext *ctx);
    // antlrcpp::Any visitReturn(MiniDecafParser::ReturnContext *ctx);
    
    antlrcpp::Any visitPureAssign(MiniDecafParser::PureAssignContext *ctx);
    antlrcpp::Any visitAssign(MiniDecafParser::AssignContext *ctx);
    antlrcpp::Any visitIdentifier(MiniDecafParser::IdentifierContext *ctx);
    antlrcpp::Any visitType(MiniDecafParser::TypeContext *ctx);

private:
    symTab<int> varTab, typeTab;
    symTab<std::vector<int> > sizeTab;
    enum VarType {
        INT, INT_PTR, INT_ARR, UNDEF
    };

    int offset;
    std::string curFunc;
};
