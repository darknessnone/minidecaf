#pragma once

#include "MiniDecafBaseVisitor.h"
#include <string>
#include <unordered_map>
#include <tuple>

template<typename T>
using symTab = std::unordered_map<std::string, std::unordered_map<std::string, T> >;


class CodeGenVisitor : public MiniDecafBaseVisitor {
public:
    antlrcpp::Any visitToplv(MiniDecafParser::ToplvContext *ctx, std::tuple<symTab<int>, symTab<int>, symTab<std::vector<int> > >& symbol_);
    antlrcpp::Any visitProg(MiniDecafParser::ProgContext *ctx); 
    antlrcpp::Any visitReturn(MiniDecafParser::ReturnContext *ctx);
    antlrcpp::Any visitIfStmt(MiniDecafParser::IfStmtContext *ctx);
    antlrcpp::Any visitWhileLoop(MiniDecafParser::WhileLoopContext *ctx);
    antlrcpp::Any visitForLoop(MiniDecafParser::ForLoopContext *ctx);
    antlrcpp::Any visitPrintExpr(MiniDecafParser::PrintExprContext *ctx);
    antlrcpp::Any visitStmtBlock(MiniDecafParser::StmtBlockContext *ctx);
    antlrcpp::Any visitAddSub(MiniDecafParser::AddSubContext *ctx);
    antlrcpp::Any visitMulDiv(MiniDecafParser::MulDivContext *ctx);
    antlrcpp::Any visitEqual(MiniDecafParser::EqualContext *ctx);
    antlrcpp::Any visitLiteral(MiniDecafParser::LiteralContext *ctx);
    antlrcpp::Any visitParen(MiniDecafParser::ParenContext *ctx);
    antlrcpp::Any visitUnary(MiniDecafParser::UnaryContext *ctx);
    antlrcpp::Any visitTernary(MiniDecafParser::TernaryContext *ctx);
    antlrcpp::Any visitLAND(MiniDecafParser::LANDContext *ctx);
    antlrcpp::Any visitLOR(MiniDecafParser::LORContext *ctx);
    antlrcpp::Any visitLessGreat(MiniDecafParser::LessGreatContext *ctx);
    antlrcpp::Any visitCallFunc(MiniDecafParser::CallFuncContext *ctx);
    antlrcpp::Any visitSizeOf(MiniDecafParser::SizeOfContext *ctx);
    antlrcpp::Any visitVarDef(MiniDecafParser::VarDefContext *ctx);
    // antlrcpp::Any visitArrayCall(MiniDecafParser::ArrayCallContext *ctx);
    // antlrcpp::Any visitArrayDef(MiniDecafParser::ArrayDefContext *ctx);

private:
    std::ostringstream code_;
    std::ostringstream data_;
    std::ostringstream bss_;

    symTab<int> varTab, typeTab;
    symTab<std::vector<int> > sizeTab;
    enum VarType {
        INT, INT_PTR, INT_ARR, UNDEF
    };

    std::string curFunc;
    int blockOrder, blockDep;
    int labelOrder;
    bool retState;
    /* A simple stack machine model */
    const char* push = "\taddi sp, sp, -8\n"
                       "\tsd a0, (sp)\n";
    const char* pop = "\tld t0, 8(sp)\n"
                      "\tld t1, (sp)\n"
                      "\taddi sp, sp, 16\n";
    const char* pop1 = "\tld t0, (sp)\n"
                       "\taddi sp, sp, 8\n";
};

