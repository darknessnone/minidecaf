#include "VarAllocVisitor.h"
#include <typeinfo>

antlrcpp::Any VarAllocVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    visitChildren(ctx);
    return this->symbol;
}


antlrcpp::Any VarAllocVisitor::visitAssign(MiniDecafParser::AssignContext *ctx) {
    this->symbol[ctx->ID()->getText()] = this->offset++;
    return NULL;
}

antlrcpp::Any VarAllocVisitor::visitIdentifier(MiniDecafParser::IdentifierContext *ctx) {
    if (this->symbol.count(ctx->getText()) == 0) {
        this->symbol[ctx->getText()] = -1;
    }
    return NULL;
}