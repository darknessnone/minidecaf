#include "VarAllocVisitor.h"
#include <typeinfo>

antlrcpp::Any VarAllocVisitor::visitToplv(MiniDecafParser::ToplvContext *ctx) {
    visitChildren(ctx);
    return std::make_tuple(varTab, typeTab, sizeTab);
} 

antlrcpp::Any VarAllocVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    curFunc = ctx->ID(0)->getText();
    if (varTab.count(curFunc) > 0) {
        std::cerr << "[error] Function " << curFunc << "defined more than once\n";
        exit(1); 
    }

    varTab[curFunc] = std::unordered_map<std::string, int> ();
    offset = 0;

    for (auto i = 1; i < ctx->ID().size(); ++i) {
        std::string varName = ctx->ID(i)->getText();
        varTab[curFunc][varName] = offset++;
        std::tuple<int, int> rvalueType = visit(ctx->type(i));
        typeTab[curFunc][varName] = std::get<0>(rvalueType);
        sizeTab[curFunc][varName] = std::vector<int>(1, std::get<1>(rvalueType));
    }
    visit(ctx->stmts());
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitAssign(MiniDecafParser::AssignContext *ctx) {
    std::string varName = ctx->ID()->getText();
    if (varTab[curFunc].count(varName) > 0) {
        std::cerr << "[error] Redefinition of variable " << varName << "\n";
        exit(1);
    }
    std::tuple<int, int> rvalueType = visit(ctx->type());
    typeTab[curFunc][varName] = std::get<0>(rvalueType);
    sizeTab[curFunc][varName] = std::vector<int>(1, std::get<1>(rvalueType));

    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitIdentifier(MiniDecafParser::IdentifierContext *ctx) {
    if (varTab[curFunc].count(ctx->getText()) == 0) {
        std::cerr << "[error] Undeclared variable " << ctx->getText() << " Used\n";
        exit(1);
    }
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitType(MiniDecafParser::TypeContext *ctx) {
    if (ctx->MUL().size() == 0) {
        return std::make_tuple(int(VarType::INT), 0);
    } else {
        return std::make_tuple(int(VarType::INT_PTR), ctx->MUL().size());
    }
    return nullptr;
}