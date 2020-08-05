#include "CodeGenVisitor.h"
#include <typeinfo>

antlrcpp::Any CodeGenVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    code_ << ".global main\n"
          << "main:\n";
    visitChildren(ctx);
    return code_.str();
}

antlrcpp::Any CodeGenVisitor::visitPrintExpr(MiniDecafParser::PrintExprContext *ctx) {
    visitChildren(ctx);
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitLiteral(MiniDecafParser::LiteralContext *ctx) {
    code_ << "\tli a0, " << ctx->getText() << "\n"
          << "\tret\n";
    return NULL;
}