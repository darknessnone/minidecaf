
// Generated from MiniDecaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniDecafParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MiniDecafParser.
 */
class  MiniDecafVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MiniDecafParser.
   */
    virtual antlrcpp::Any visitProg(MiniDecafParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitPrintExpr(MiniDecafParser::PrintExprContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(MiniDecafParser::LiteralContext *context) = 0;


};

