#include "CodeGenVisitor.h"
#include <typeinfo>

antlrcpp::Any CodeGenVisitor::visitToplv(MiniDecafParser::ToplvContext *ctx,
    std::tuple<symTab<int>, symTab<int>, symTab<std::vector<int> > >& symbol_) {
    
    code_ << ".section .text\n"
          << ".globl main\n";
    varTab = std::get<0>(symbol_);
    typeTab = std::get<1>(symbol_);
    sizeTab = std::get<2>(symbol_);
    labelOrder = 0;
    visitChildren(ctx);
    return code_.str() + data_.str() + bss_.str();
}

antlrcpp::Any CodeGenVisitor::visitProg(MiniDecafParser::ProgContext *ctx) { 
    curFunc = ctx->ID(0)->getText();
    code_ << curFunc << ":\n"
          << "\tsd ra, -8(sp)\n"
          << "\taddi sp, sp, -8\n"
          << "\tsd fp, -8(sp)\n"
          << "\taddi fp, sp, -8\n"
          << "\taddi sp, fp, " << -8 * (int)varTab[curFunc].size() << "\n";
    for (auto i = 1; i < ctx->ID().size(); ++i) {
        code_ << "\tld t0, " << 16 + 8 * varTab[curFunc][ctx->ID(i)->getText()] << "(fp)\n";
        code_ << "\tsd t0, " << -8 - 8 * varTab[curFunc][ctx->ID(i)->getText()] << "(fp)\n";
    }
    visit(ctx->stmts());
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitPrintExpr(MiniDecafParser::PrintExprContext *ctx) {
    visit(ctx->expr());
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitCallFunc(MiniDecafParser::CallFuncContext *ctx) {
    for (int i = ctx->expr().size()-1; i >= 0; --i) {
        visit(ctx->expr(i));
    }
    code_ << "\tcall " << ctx->ID()->getText() << "\n";
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitReturn(MiniDecafParser::ReturnContext *ctx) {
    visit(ctx->expr());
    code_ << "\tld ra, 8(fp)\n" 
          << "\taddi sp, fp, 8\n"
          << "\tld fp, -8(sp)\n"
          << "\tret\n";
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitAssign(MiniDecafParser::AssignContext *ctx) {
    visit(ctx->expr());
    code_ << "\tsd a0, " << -8 - 8 * varTab[curFunc][ctx->ID()->getText()] << "(fp)\n";
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitSizeOf(MiniDecafParser::SizeOfContext *ctx) {
    std::string varName = ctx->ID()->getText();
    if (typeTab[curFunc][varName] == VarType::INT ||
        typeTab[curFunc][varName] == VarType::INT_PTR) {
        
        code_ << "\tli a0, 8\n" 
              << push;
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitIdentifier(MiniDecafParser::IdentifierContext *ctx) {
    std::string varName = ctx->ID()->getText();
    if (varTab[curFunc].count(varName) == 0) {
        std::cerr << "[error] Var " << varName << " is used before define\n";
        exit(1);
    } else {
        code_ << "\tld a0, " << -8 - 8 * varTab[curFunc][varName] << "(fp)\n"
              << push;
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitAddSub(MiniDecafParser::AddSubContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));
    if (ctx->op->getType() == MiniDecafParser::ADD) {
        code_ << pop 
              << "\tadd a0, t0, t1\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::SUB) {
        code_ << pop 
              << "\tsub a0, t0, t1\n"
              << push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitMulDiv(MiniDecafParser::MulDivContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));
    if (ctx->op->getType() == MiniDecafParser::MUL) {
        code_ << pop
              << "\tmul a0, t0, t1\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::DIV) {
        code_ << pop 
              << "\tdiv a0, t0, t1\n"
              << push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return nullptr;

}

antlrcpp::Any CodeGenVisitor::visitUnary(MiniDecafParser::UnaryContext *ctx) {
    visitChildren(ctx);
    if (ctx->SUB()) {
        code_ << pop1
              << "\tsub a0, x0, t0\n"
              << push;
    } else if (ctx->MUL()) {
        code_ << pop1
              << "\tld a0, (t0)\n"
              << push;
    } else if (ctx->AND()) {
        code_ << pop1
              << "\taddi a0, fp, " << -8 - 8 * varTab[curFunc][ctx->expr()->getText()] << "\n"
              << push;
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitParen(MiniDecafParser::ParenContext *ctx) {
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitEqual(MiniDecafParser::EqualContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));

    if (ctx->op->getType() == MiniDecafParser::EQ) {
        code_ << pop
              << "\tsub t0, t0, t1\n"
              << "\t seqz a0, t0\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::NEQ) {
        code_ << pop
              << "\tsub t0, t0, t1\n"
              << "\tsnez a0, t0\n"
              << push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return nullptr;

}

antlrcpp::Any CodeGenVisitor::visitLessGreat(MiniDecafParser::LessGreatContext *ctx) {
    visit(ctx->expr(0));
    visit(ctx->expr(1));

    if (ctx->op->getType() == MiniDecafParser::LE) {
        code_ << pop
              << "\tsgt a0, t0, t1\n"
              << "\txori a0, a0, 1\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::LT) {
        code_ << pop
              << "\tslt a0, t0, t1\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::GE) {
        code_ << pop
              << "\tslt a0, t0, t1\n"
              << "\txori a0, a0, 1\n"
              << push;
    } else if (ctx->op->getType() == MiniDecafParser::GT) {
        code_ << pop
              << "\tsgt a0, t0, t1\n"
              << push;
    } else {
        std::cerr << "[error] Illegal operation given to the calculator.\n";
        exit(1);
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(MiniDecafParser::IfStmtContext *ctx) {
    visit(ctx->expr());
    if (ctx->ELSE()) {
        int elseBranch = labelOrder++;
        int endBranch = labelOrder++;
        code_ << "\tbeqz a0, label_" << elseBranch << "\n";
        visit(ctx->stmts(0));
        code_ << "\tj label_" << endBranch << "\n";
        code_ << "label_" << elseBranch << ":\n";
        visit(ctx->stmts(1));
        code_ << "label_" << endBranch << ":\n";
    } else {
        int endBranch = labelOrder++;
        code_ << "\tbeqz a0, label_" << endBranch << "\n";
        visit(ctx->stmts(0));
        code_ << "label_" << endBranch << ":\n";
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitWhileLoop(MiniDecafParser::WhileLoopContext *ctx) {
    int startBranch = labelOrder++;
    int endBranch = labelOrder++;
    code_ << "label_" << startBranch << ":\n";
    visit(ctx->expr());
    code_ << "\tbeqz a0, label_" << endBranch << "\n";
    visit(ctx->stmts());
    code_ << "\tj label_" << startBranch << "\n"
                << "label_" << endBranch << ":\n";
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitForLoop(MiniDecafParser::ForLoopContext *ctx) {
    int startBranch = labelOrder++;
    int endBranch = labelOrder++;
    visit(ctx->expr(0));
    code_ << "label_" << startBranch << ":\n";
    if (ctx->expr(1)) {
        visit(ctx->expr(1));
        code_ << "\tbeqz a0, label_" << endBranch << "\n";
    } else {
        std::cerr << "[error] Missing forloop control expr\n";
        exit(1);
    }
    visit(ctx->stmts());
    visit(ctx->expr(2));
    code_ << "\tj label_" << startBranch << "\n"
                << "label_" << endBranch << ":\n";
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitStmtBlock(MiniDecafParser::StmtBlockContext *ctx) {
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitLiteral(MiniDecafParser::LiteralContext *ctx) {
    std::string literal = ctx->getText();
    if (!std::all_of(literal.begin(), literal.end(), ::isdigit)) {
        std::cerr << "[error] Non-number value given when computing.\n";
        exit(1);
    }
    code_ << "\tli a0, " << literal << "\n"
          << push;
    return nullptr;
}
