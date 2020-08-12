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
    
    antlrcpp::Any visitVarDef(MiniDecafParser::VarDefContext *ctx);
    antlrcpp::Any visitType(MiniDecafParser::TypeContext *ctx);

    antlrcpp::Any visitStmtBlock(MiniDecafParser::StmtBlockContext *ctx);
    // antlrcpp::Any visitArrayCall(MiniDecafParser::ArrayCallContext *ctx);
    // antlrcpp::Any visitArrayDef(MiniDecafParser::ArrayDefContext *ctx);

private:
    symTab<int> varTab, typeTab;
    symTab<std::vector<int> > sizeTab;
    enum VarType {
        INT, INT_PTR, INT_ARR, UNDEF
    };

    int offset;
    std::string curFunc;
    int blockOrder, blockDep;
};
