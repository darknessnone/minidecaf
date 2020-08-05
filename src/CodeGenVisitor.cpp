#include "CodeGenVisitor.h"
#include <typeinfo>

antlrcpp::Any CodeGenVisitor::visitProg(MiniDecafParser::ProgContext *ctx, std::unordered_map<std::string, int>& symbol_) {
    code_ << ".global main\n"
          << "main:\n"
          << "\tsd fp, -8(sp)\n"
          << "\tmv fp, sp\n";
    this->symbol = symbol_;
    visitChildren(ctx);
    // code_ << "\tmv fp, sp\n"
    //       << "\tld fp, -8(sp)\n"
    //       << "\tret\n";
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

antlrcpp::Any CodeGenVisitor::visitEqual(MiniDecafParser::EqualContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));

    if (ctx->op->getType() == MiniDecafParser::EQ) {
        code_ << this->pop
              << "\tsub t0, t0, t1\n"
              << "\t seqz a0, t0\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::NEQ) {
        code_ << this->pop
              << "\tsub t0, t0, t1\n"
              << "\t snez a0, t0\n"
              << this->push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return NULL;

}

antlrcpp::Any CodeGenVisitor::visitLessGreat(MiniDecafParser::LessGreatContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));

    if (ctx->op->getType() == MiniDecafParser::LE) {
        code_ << this->pop
              << "\tsgt a0, t0, t1\n"
              << "\txori a0, a0, 1\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::LT) {
        code_ << this->pop
              << "\tslt a0, t0, t1\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::GE) {
        code_ << this->pop
              << "\tslt a0, t0, t1\n"
              << "\txori a0, a0, 1\n"
              << this->push;
    } else if (ctx->op->getType() == MiniDecafParser::GT) {
        code_ << this->pop
              << "\tsgt a0, t0, t1\n"
              << this->push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitAssign(MiniDecafParser::AssignContext *ctx) {
    this->code_ << "\taddi sp, fp, " << -8 - 8 * (int)symbol.size() << "\n";
    visit(ctx->expr());
    this->code_ << "\tsd a0, " << -16 - 8 * symbol[ctx->ID()->getText()] << "(fp)\n";
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitIdentifier(MiniDecafParser::IdentifierContext *ctx) {
    if (symbol[ctx->ID()->getText()] == -1) {
        std::cerr << "[error] Var " << ctx->ID()->getText() << " is used before define\n";
        exit(1);
    } else {
        this->code_ << "\tld a0, " << -16 - 8 * symbol[ctx->ID()->getText()] << "(fp)\n"
              << this->push;
    }
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitReturn(MiniDecafParser::ReturnContext *ctx) {
    visit(ctx->expr());
    this->code_ << "\tmv fp, sp\n"
          << "\tld fp, -8(sp)\n"
          << "\tret\n";
    return NULL;
}

antlrcpp::Any CodeGenVisitor::visitLiteral(MiniDecafParser::LiteralContext *ctx) {
    std::string literal = ctx->getText();
    if (!std::all_of(literal.begin(), literal.end(), ::isdigit)) {
        std::cerr << "[error] Non-number value given when computing.\n";
        exit(1);
    }
    this->code_ << "\tli a0, " << literal << "\n"
          << this->push;
    return NULL;
}
