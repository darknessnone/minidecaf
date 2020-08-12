#include "VarAllocVisitor.h"
#include <typeinfo>

antlrcpp::Any VarAllocVisitor::visitToplv(MiniDecafParser::ToplvContext *ctx) {
    visitChildren(ctx);
    return std::make_tuple(varTab, typeTab, sizeTab);
} 

antlrcpp::Any VarAllocVisitor::visitProg(MiniDecafParser::ProgContext *ctx) {
    if (ctx->SEMICOLON()) {
        std::string varName = ctx->ID(0)->getText();
        if (varTab["global"].count(varName) > 0) {
            std::cerr << "[error] redefinition of variable " << varName << "\n";
            exit(1);
        }
        varTab["global"][varName] = -1;
        std::tuple<int, std::vector<int> > rvalueType = visit(ctx->type(0));
        typeTab["global"][varName] = std::get<0>(rvalueType);
        sizeTab["global"][varName] = std::get<1>(rvalueType);
    } else {
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
            std::tuple<int, std::vector<int> > rvalueType = visit(ctx->type(i));
            typeTab[curFunc][varName] = std::get<0>(rvalueType);
            sizeTab[curFunc][varName] = std::get<1>(rvalueType);
        }
        visit(ctx->stmts());
    }
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitVarDef(MiniDecafParser::VarDefContext *ctx) {
    std::string varName = ctx->ID()->getText();
    if (ctx->type()) {
        if (varTab[curFunc].count(varName) > 0) {
            std::cerr << "[error] redefinition of variable " << varName << "\n";
            exit(1);
        }
        varTab[curFunc][varName] = offset++;
        std::tuple<int, std::vector<int> > rvalueType = visit(ctx->type());
        typeTab[curFunc][varName] = std::get<0>(rvalueType);
        sizeTab[curFunc][varName] = std::get<1>(rvalueType);
    } else {
        if (varTab[curFunc].count(varName) == 0 &&
        varTab["global"].count(varName) == 0) {
            std::cerr << "[error] Undeclared variable " << varName << " Used\n";
            exit(1);
        }
    }
    return nullptr;
}

antlrcpp::Any VarAllocVisitor::visitType(MiniDecafParser::TypeContext *ctx) {
    std::vector<int> rawTab;
    if (ctx->MUL().size() == 0) {
        rawTab.push_back(1);
        return std::make_tuple(int(VarType::INT), rawTab);
    } else {
        rawTab.push_back(1);
        rawTab.push_back(int(ctx->MUL().size()));
        return std::make_tuple(int(VarType::INT_PTR), rawTab);
    }
    return nullptr;
}