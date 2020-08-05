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

antlrcpp::Any CodeGenVisitor::visitAddSub(MiniDecafParser::AddSubContext *ctx) {
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
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitMulDiv(MiniDecafParser::MulDivContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));
    if (ctx->op->getType() == MiniDecafParser::MUL) {
        code_ << this->pop
              << "\tmul a0, t0, t1\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::DIV) {
        code_ << this->pop 
              << "\tdiv a0, t0, t1\n"
              << this->push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return NULL;

}

antlrcpp::Any CodeGenVisitor::visitUnary(MiniDecafParser::UnaryContext *ctx) {
    visitChildren(ctx);
    if (ctx->SUB()) {
        code_ << this->pop1
              << "\tsub a0, x0, t0\n"
              << this->push;
    }
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitParen(MiniDecafParser::ParenContext *ctx) {
    visitChildren(ctx);
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitLiteral(MiniDecafParser::LiteralContext *ctx) {
    std::string literal = ctx->getText();
    if (!std::all_of(literal.begin(), literal.end(), ::isdigit)) {
        std::cerr << "[error] Non-number value given when computing.\n";
        exit(1);
    }
    code_ << "\tli a0, " << literal << "\n"
          << this->push;
    return NULL;
}
