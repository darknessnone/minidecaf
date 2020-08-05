#include "CodeGenVisitor.h"
#include <typeinfo>

antlrcpp::Any CodeGenVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    code_ << ".global main\n"
          << "main:\n";
    visitChildren(ctx);
    code_ << "\tret\n";
    return code_.str();
}

antlrcpp::Any CodeGenVisitor::visitPrintExpr(MiniDecafParser::PrintExprContext *ctx) {
    visitChildren(ctx);
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitAddSub(MiniDecafParser::AddSubContext* ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));
    if (ctx->op->getType() == MiniDecafParser::ADD) {
        code_ << this->pop 
              << "\tadd a0, t0, t1\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::SUB) {
        code_ << this->pop 
              << "\tsub a0, t0, t1\n"
              << this->push;
    }
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitLiteral(MiniDecafParser::LiteralContext *ctx) {
    code_ << "\tli a0, " << ctx->getText() << "\n"
          << this->push;
    return NULL;
}
