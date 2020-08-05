#pragma once

#include "MiniDecafBaseVisitor.h"
#include <string>

class CodeGenVisitor : public MiniDecafBaseVisitor {
public:
    antlrcpp::Any visitProg(MiniDecafParser::ProgContext* ctx); 
    antlrcpp::Any visitPrintExpr(MiniDecafParser::PrintExprContext *ctx);
    antlrcpp::Any visitLiteral(MiniDecafParser::LiteralContext *ctx);
private:
    std::ostringstream code_;
};

