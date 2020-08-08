
// Generated from MiniDecaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniDecafVisitor.h"


/**
 * This class provides an empty implementation of MiniDecafVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MiniDecafBaseVisitor : public MiniDecafVisitor {
public:

  virtual antlrcpp::Any visitProg(MiniDecafParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn(MiniDecafParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(MiniDecafParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(MiniDecafParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLoop(MiniDecafParser::ForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(MiniDecafParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintExpr(MiniDecafParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtBlock(MiniDecafParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(MiniDecafParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDiv(MiniDecafParser::MulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSub(MiniDecafParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqual(MiniDecafParser::EqualContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(MiniDecafParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallFunc(MiniDecafParser::CallFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(MiniDecafParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLessGreat(MiniDecafParser::LessGreatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary(MiniDecafParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParen(MiniDecafParser::ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(MiniDecafParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

