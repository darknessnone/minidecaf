#pragma once

#include "MiniDecafBaseVisitor.h"
#include <string>

class CodeGenVisitor : public MiniDecafBaseVisitor {
public:
    antlrcpp::Any visitProg(MiniDecafParser::ProgContext* ctx); 
    antlrcpp::Any visitPrintExpr(MiniDecafParser::PrintExprContext *ctx);
    antlrcpp::Any visitLiteral(MiniDecafParser::LiteralContext *ctx);
    antlrcpp::Any visitAddSub(MiniDecafParser::AddSubContext *ctx);
    antlrcpp::Any visitMulDiv(MiniDecafParser::MulDivContext *ctx);
    antlrcpp::Any visitParen(MiniDecafParser::ParenContext *ctx);
    antlrcpp::Any visitUnary(MiniDecafParser::UnaryContext *ctx);
private:
    std::ostringstream code_;

    /* A simple stack machine model */
    const char* push = "\taddi sp, sp, -8\n"
                       "\tsd a0, (sp)\n";
    const char* pop = "\tld t0, 8(sp)\n"
                      "\tld t1, (sp)\n"
                      "\taddi sp, sp, 16\n";
    const char* pop1 = "\tld t0, (sp)\n"
                       "\taddi sp, sp, 8\n";
};

