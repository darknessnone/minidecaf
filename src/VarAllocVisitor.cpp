#include "VarAllocVisitor.h"
#include <typeinfo>

antlrcpp::Any VarAllocVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    visitChildren(ctx);
    return symbol;
}


antlrcpp::Any VarAllocVisitor::visitAssign(MiniDecafParser::AssignContext *ctx) {
    if (symbol[curFunc].count(ctx->ID()->getText()) == 0 ||
        symbol[curFunc][ctx->ID()->getText()] == -1) {
        symbol[curFunc][ctx->ID()->getText()] = offset++;
    }
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitIdentifier(MiniDecafParser::IdentifierContext *ctx) {
    if (symbol[curFunc].count(ctx->getText()) == 0) {
        symbol[curFunc][ctx->getText()] = -1;
    }
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitFuncDef(MiniDecafParser::FuncDefContext *ctx) {
    curFunc = ctx->ID(0)->getText();
    if (symbol.count(curFunc) > 0) {
        std::cerr << "[error] Function " << curFunc << "defined more than once\n";
        exit(1); 
    }

    symbol[curFunc] = std::unordered_map<std::string, int> ();
    offset = 0;
    for (auto i = 1; i < ctx->ID().size(); ++i) {
        symbol[curFunc][ctx->ID(i)->getText()] = offset++;
    }
    visit(ctx->stmts());
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitCallFunc(MiniDecafParser::CallFuncContext *ctx) {
    if (symbol.count(curFunc) == 0) {
        std::cerr << "[error] Use undeclared function " << curFunc << "\n";
        exit(1);
    }
    return nullptr;
}