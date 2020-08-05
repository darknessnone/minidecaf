#pragma once

#include "MiniDecafBaseVisitor.h"
#include <string>
#include <unordered_map>

class VarAllocVisitor : public MiniDecafBaseVisitor {
public:
    antlrcpp::Any visitProg(MiniDecafParser::ProgContext *ctx);
    antlrcpp::Any visitAssign(MiniDecafParser::AssignContext *ctx);
    antlrcpp::Any visitIdentifier(MiniDecafParser::IdentifierContext *ctx);

private:
    // std::unordered_map<std::string, std::unordered_map<std::string, int> > symbol;
    std::unordered_map<std::string, int> symbol;
    int offset;
};
