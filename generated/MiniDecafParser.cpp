
// Generated from MiniDecaf.g4 by ANTLR 4.8


#include "MiniDecafVisitor.h"

#include "MiniDecafParser.h"


using namespace antlrcpp;
using namespace antlr4;

MiniDecafParser::MiniDecafParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MiniDecafParser::~MiniDecafParser() {
  delete _interpreter;
}

std::string MiniDecafParser::getGrammarFileName() const {
  return "MiniDecaf.g4";
}

const std::vector<std::string>& MiniDecafParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MiniDecafParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniDecafParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::ProgContext::EOF() {
  return getToken(MiniDecafParser::EOF, 0);
}

std::vector<MiniDecafParser::StmtsContext *> MiniDecafParser::ProgContext::stmts() {
  return getRuleContexts<MiniDecafParser::StmtsContext>();
}

MiniDecafParser::StmtsContext* MiniDecafParser::ProgContext::stmts(size_t i) {
  return getRuleContext<MiniDecafParser::StmtsContext>(i);
}


size_t MiniDecafParser::ProgContext::getRuleIndex() const {
  return MiniDecafParser::RuleProg;
}


antlrcpp::Any MiniDecafParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ProgContext* MiniDecafParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniDecafParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
      | (1ULL << MiniDecafParser::ADD)
      | (1ULL << MiniDecafParser::SUB)
      | (1ULL << MiniDecafParser::LPAREN)
      | (1ULL << MiniDecafParser::LBRACE)
      | (1ULL << MiniDecafParser::RET)
      | (1ULL << MiniDecafParser::IF)
      | (1ULL << MiniDecafParser::WHILE)
      | (1ULL << MiniDecafParser::FOR)
      | (1ULL << MiniDecafParser::ID))) != 0)) {
      setState(6);
      stmts();
      setState(11);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(12);
    match(MiniDecafParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtsContext ------------------------------------------------------------------

MiniDecafParser::StmtsContext::StmtsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniDecafParser::StmtsContext::getRuleIndex() const {
  return MiniDecafParser::RuleStmts;
}

void MiniDecafParser::StmtsContext::copyFrom(StmtsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::ReturnContext::RET() {
  return getToken(MiniDecafParser::RET, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::ReturnContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::ReturnContext::SEMICOLON() {
  return getToken(MiniDecafParser::SEMICOLON, 0);
}

MiniDecafParser::ReturnContext::ReturnContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::IfStmtContext::IF() {
  return getToken(MiniDecafParser::IF, 0);
}

tree::TerminalNode* MiniDecafParser::IfStmtContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::IfStmtContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::IfStmtContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

std::vector<MiniDecafParser::StmtsContext *> MiniDecafParser::IfStmtContext::stmts() {
  return getRuleContexts<MiniDecafParser::StmtsContext>();
}

MiniDecafParser::StmtsContext* MiniDecafParser::IfStmtContext::stmts(size_t i) {
  return getRuleContext<MiniDecafParser::StmtsContext>(i);
}

tree::TerminalNode* MiniDecafParser::IfStmtContext::ELSE() {
  return getToken(MiniDecafParser::ELSE, 0);
}

MiniDecafParser::IfStmtContext::IfStmtContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtBlockContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::StmtBlockContext::LBRACE() {
  return getToken(MiniDecafParser::LBRACE, 0);
}

tree::TerminalNode* MiniDecafParser::StmtBlockContext::RBRACE() {
  return getToken(MiniDecafParser::RBRACE, 0);
}

std::vector<MiniDecafParser::StmtsContext *> MiniDecafParser::StmtBlockContext::stmts() {
  return getRuleContexts<MiniDecafParser::StmtsContext>();
}

MiniDecafParser::StmtsContext* MiniDecafParser::StmtBlockContext::stmts(size_t i) {
  return getRuleContext<MiniDecafParser::StmtsContext>(i);
}

MiniDecafParser::StmtBlockContext::StmtBlockContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::StmtBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStmtBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLoopContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::ForLoopContext::FOR() {
  return getToken(MiniDecafParser::FOR, 0);
}

tree::TerminalNode* MiniDecafParser::ForLoopContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ForLoopContext::SEMICOLON() {
  return getTokens(MiniDecafParser::SEMICOLON);
}

tree::TerminalNode* MiniDecafParser::ForLoopContext::SEMICOLON(size_t i) {
  return getToken(MiniDecafParser::SEMICOLON, i);
}

tree::TerminalNode* MiniDecafParser::ForLoopContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::StmtsContext* MiniDecafParser::ForLoopContext::stmts() {
  return getRuleContext<MiniDecafParser::StmtsContext>(0);
}

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::ForLoopContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::ForLoopContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

MiniDecafParser::ForLoopContext::ForLoopContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncDefContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> MiniDecafParser::FuncDefContext::ID() {
  return getTokens(MiniDecafParser::ID);
}

tree::TerminalNode* MiniDecafParser::FuncDefContext::ID(size_t i) {
  return getToken(MiniDecafParser::ID, i);
}

tree::TerminalNode* MiniDecafParser::FuncDefContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

tree::TerminalNode* MiniDecafParser::FuncDefContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::StmtsContext* MiniDecafParser::FuncDefContext::stmts() {
  return getRuleContext<MiniDecafParser::StmtsContext>(0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::FuncDefContext::COMMA() {
  return getTokens(MiniDecafParser::COMMA);
}

tree::TerminalNode* MiniDecafParser::FuncDefContext::COMMA(size_t i) {
  return getToken(MiniDecafParser::COMMA, i);
}

MiniDecafParser::FuncDefContext::FuncDefContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::WhileLoopContext::WHILE() {
  return getToken(MiniDecafParser::WHILE, 0);
}

tree::TerminalNode* MiniDecafParser::WhileLoopContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::WhileLoopContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::WhileLoopContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::StmtsContext* MiniDecafParser::WhileLoopContext::stmts() {
  return getRuleContext<MiniDecafParser::StmtsContext>(0);
}

MiniDecafParser::WhileLoopContext::WhileLoopContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

MiniDecafParser::ExprContext* MiniDecafParser::PrintExprContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::PrintExprContext::SEMICOLON() {
  return getToken(MiniDecafParser::SEMICOLON, 0);
}

MiniDecafParser::PrintExprContext::PrintExprContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
MiniDecafParser::StmtsContext* MiniDecafParser::stmts() {
  StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniDecafParser::RuleStmts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ReturnContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(14);
      match(MiniDecafParser::RET);
      setState(15);
      expr(0);
      setState(16);
      match(MiniDecafParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(18);
      match(MiniDecafParser::IF);
      setState(19);
      match(MiniDecafParser::LPAREN);
      setState(20);
      expr(0);
      setState(21);
      match(MiniDecafParser::RPAREN);
      setState(22);
      stmts();
      setState(25);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(23);
        match(MiniDecafParser::ELSE);
        setState(24);
        stmts();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(27);
      match(MiniDecafParser::WHILE);
      setState(28);
      match(MiniDecafParser::LPAREN);
      setState(29);
      expr(0);
      setState(30);
      match(MiniDecafParser::RPAREN);
      setState(31);
      stmts();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(33);
      match(MiniDecafParser::FOR);
      setState(34);
      match(MiniDecafParser::LPAREN);
      setState(36);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(35);
        expr(0);
      }
      setState(38);
      match(MiniDecafParser::SEMICOLON);
      setState(40);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(39);
        expr(0);
      }
      setState(42);
      match(MiniDecafParser::SEMICOLON);
      setState(44);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(43);
        expr(0);
      }
      setState(46);
      match(MiniDecafParser::RPAREN);
      setState(47);
      stmts();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::FuncDefContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(48);
      match(MiniDecafParser::ID);
      setState(49);
      match(MiniDecafParser::LPAREN);
      setState(54);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(50);
          match(MiniDecafParser::ID);
          setState(51);
          match(MiniDecafParser::COMMA); 
        }
        setState(56);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      }
      setState(58);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::ID) {
        setState(57);
        match(MiniDecafParser::ID);
      }
      setState(60);
      match(MiniDecafParser::RPAREN);
      setState(61);
      stmts();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(62);
      expr(0);
      setState(63);
      match(MiniDecafParser::SEMICOLON);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(65);
      match(MiniDecafParser::LBRACE);
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::LBRACE)
        | (1ULL << MiniDecafParser::RET)
        | (1ULL << MiniDecafParser::IF)
        | (1ULL << MiniDecafParser::WHILE)
        | (1ULL << MiniDecafParser::FOR)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(66);
        stmts();
        setState(71);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(72);
      match(MiniDecafParser::RBRACE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniDecafParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniDecafParser::ExprContext::getRuleIndex() const {
  return MiniDecafParser::RuleExpr;
}

void MiniDecafParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::IdentifierContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

MiniDecafParser::IdentifierContext::IdentifierContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::MulDivContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::MulDivContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::MulDivContext::MUL() {
  return getToken(MiniDecafParser::MUL, 0);
}

tree::TerminalNode* MiniDecafParser::MulDivContext::DIV() {
  return getToken(MiniDecafParser::DIV, 0);
}

MiniDecafParser::MulDivContext::MulDivContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::AddSubContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::AddSubContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::AddSubContext::ADD() {
  return getToken(MiniDecafParser::ADD, 0);
}

tree::TerminalNode* MiniDecafParser::AddSubContext::SUB() {
  return getToken(MiniDecafParser::SUB, 0);
}

MiniDecafParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::EqualContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::EqualContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::EqualContext::EQ() {
  return getToken(MiniDecafParser::EQ, 0);
}

tree::TerminalNode* MiniDecafParser::EqualContext::NEQ() {
  return getToken(MiniDecafParser::NEQ, 0);
}

MiniDecafParser::EqualContext::EqualContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::EqualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEqual(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::LiteralContext::INT() {
  return getToken(MiniDecafParser::INT, 0);
}

MiniDecafParser::LiteralContext::LiteralContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallFuncContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::CallFuncContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

tree::TerminalNode* MiniDecafParser::CallFuncContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

tree::TerminalNode* MiniDecafParser::CallFuncContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::CallFuncContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::CallFuncContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::CallFuncContext::COMMA() {
  return getTokens(MiniDecafParser::COMMA);
}

tree::TerminalNode* MiniDecafParser::CallFuncContext::COMMA(size_t i) {
  return getToken(MiniDecafParser::COMMA, i);
}

MiniDecafParser::CallFuncContext::CallFuncContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::CallFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitCallFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::AssignContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

tree::TerminalNode* MiniDecafParser::AssignContext::ASSIGN() {
  return getToken(MiniDecafParser::ASSIGN, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::AssignContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

MiniDecafParser::AssignContext::AssignContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LessGreatContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::LessGreatContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::LessGreatContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::LessGreatContext::LT() {
  return getToken(MiniDecafParser::LT, 0);
}

tree::TerminalNode* MiniDecafParser::LessGreatContext::LE() {
  return getToken(MiniDecafParser::LE, 0);
}

tree::TerminalNode* MiniDecafParser::LessGreatContext::GT() {
  return getToken(MiniDecafParser::GT, 0);
}

tree::TerminalNode* MiniDecafParser::LessGreatContext::GE() {
  return getToken(MiniDecafParser::GE, 0);
}

MiniDecafParser::LessGreatContext::LessGreatContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::LessGreatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLessGreat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

MiniDecafParser::ExprContext* MiniDecafParser::UnaryContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::UnaryContext::ADD() {
  return getToken(MiniDecafParser::ADD, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryContext::SUB() {
  return getToken(MiniDecafParser::SUB, 0);
}

MiniDecafParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::ParenContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::ParenContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::ParenContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::ParenContext::ParenContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitParen(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ExprContext* MiniDecafParser::expr() {
   return expr(0);
}

MiniDecafParser::ExprContext* MiniDecafParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MiniDecafParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MiniDecafParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(76);
      _la = _input->LA(1);
      if (!(_la == MiniDecafParser::ADD

      || _la == MiniDecafParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(77);
      expr(10);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(78);
      match(MiniDecafParser::ID);
      setState(79);
      match(MiniDecafParser::ASSIGN);
      setState(80);
      expr(5);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CallFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(81);
      match(MiniDecafParser::ID);
      setState(82);
      match(MiniDecafParser::LPAREN);
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(83);
          expr(0);
          setState(84);
          match(MiniDecafParser::COMMA); 
        }
        setState(90);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(92);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(91);
        expr(0);
      }
      setState(94);
      match(MiniDecafParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(95);
      match(MiniDecafParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(96);
      match(MiniDecafParser::INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(MiniDecafParser::LPAREN);
      setState(98);
      expr(0);
      setState(99);
      match(MiniDecafParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(117);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(115);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(103);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(104);
          dynamic_cast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniDecafParser::MUL

          || _la == MiniDecafParser::DIV)) {
            dynamic_cast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(105);
          expr(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(106);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(107);
          dynamic_cast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniDecafParser::ADD

          || _la == MiniDecafParser::SUB)) {
            dynamic_cast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(108);
          expr(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LessGreatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(109);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(110);
          dynamic_cast<LessGreatContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::LT)
            | (1ULL << MiniDecafParser::LE)
            | (1ULL << MiniDecafParser::GT)
            | (1ULL << MiniDecafParser::GE))) != 0))) {
            dynamic_cast<LessGreatContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(111);
          expr(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(113);
          dynamic_cast<EqualContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniDecafParser::EQ

          || _la == MiniDecafParser::NEQ)) {
            dynamic_cast<EqualContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(114);
          expr(7);
          break;
        }

        } 
      }
      setState(119);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool MiniDecafParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MiniDecafParser::_decisionToDFA;
atn::PredictionContextCache MiniDecafParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MiniDecafParser::_atn;
std::vector<uint16_t> MiniDecafParser::_serializedATN;

std::vector<std::string> MiniDecafParser::_ruleNames = {
  "prog", "stmts", "expr"
};

std::vector<std::string> MiniDecafParser::_literalNames = {
  "", "", "", "';'", "','", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", 
  "'}'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'='", "'return'", 
  "'if'", "'else'", "'while'", "'for'"
};

std::vector<std::string> MiniDecafParser::_symbolicNames = {
  "", "WS", "INT", "SEMICOLON", "COMMA", "ADD", "SUB", "MUL", "DIV", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "EQ", "NEQ", "LT", "LE", "GT", "GE", "ASSIGN", 
  "RET", "IF", "ELSE", "WHILE", "FOR", "ID"
};

dfa::Vocabulary MiniDecafParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MiniDecafParser::_tokenNames;

MiniDecafParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1b, 0x7b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x7, 0x2, 0xa, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x1c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x2f, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x37, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3a, 0xb, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x3d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x46, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x49, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4c, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x59, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x5c, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5f, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x68, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x76, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x79, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 
    0x5, 0x2, 0x4, 0x6, 0x2, 0x6, 0x3, 0x2, 0x7, 0x8, 0x3, 0x2, 0x9, 0xa, 
    0x3, 0x2, 0x11, 0x14, 0x3, 0x2, 0xf, 0x10, 0x2, 0x90, 0x2, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 0x9, 0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 
    0x2, 0x2, 0x2, 0xc, 0xe, 0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xe, 0xf, 0x7, 0x2, 0x2, 0x3, 0xf, 0x3, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x11, 0x7, 0x16, 0x2, 0x2, 0x11, 0x12, 0x5, 0x6, 0x4, 0x2, 0x12, 0x13, 
    0x7, 0x5, 0x2, 0x2, 0x13, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 
    0x17, 0x2, 0x2, 0x15, 0x16, 0x7, 0xb, 0x2, 0x2, 0x16, 0x17, 0x5, 0x6, 
    0x4, 0x2, 0x17, 0x18, 0x7, 0xc, 0x2, 0x2, 0x18, 0x1b, 0x5, 0x4, 0x3, 
    0x2, 0x19, 0x1a, 0x7, 0x18, 0x2, 0x2, 0x1a, 0x1c, 0x5, 0x4, 0x3, 0x2, 
    0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x19, 0x2, 0x2, 0x1e, 0x1f, 
    0x7, 0xb, 0x2, 0x2, 0x1f, 0x20, 0x5, 0x6, 0x4, 0x2, 0x20, 0x21, 0x7, 
    0xc, 0x2, 0x2, 0x21, 0x22, 0x5, 0x4, 0x3, 0x2, 0x22, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x23, 0x24, 0x7, 0x1a, 0x2, 0x2, 0x24, 0x26, 0x7, 0xb, 0x2, 
    0x2, 0x25, 0x27, 0x5, 0x6, 0x4, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x2a, 0x7, 0x5, 0x2, 0x2, 0x29, 0x2b, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2e, 0x7, 0x5, 0x2, 0x2, 0x2d, 0x2f, 0x5, 0x6, 
    0x4, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0xc, 0x2, 0x2, 
    0x31, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x32, 0x33, 0x7, 0x1b, 0x2, 0x2, 0x33, 
    0x38, 0x7, 0xb, 0x2, 0x2, 0x34, 0x35, 0x7, 0x1b, 0x2, 0x2, 0x35, 0x37, 
    0x7, 0x6, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3d, 0x7, 0x1b, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3f, 0x7, 0xc, 0x2, 0x2, 0x3f, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x40, 0x41, 
    0x5, 0x6, 0x4, 0x2, 0x41, 0x42, 0x7, 0x5, 0x2, 0x2, 0x42, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x47, 0x7, 0xd, 0x2, 0x2, 0x44, 0x46, 0x5, 0x4, 
    0x3, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x4c, 0x7, 0xe, 0x2, 0x2, 0x4b, 0x10, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x32, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x43, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x8, 0x4, 0x1, 0x2, 0x4e, 0x4f, 0x9, 0x2, 0x2, 0x2, 
    0x4f, 0x68, 0x5, 0x6, 0x4, 0xc, 0x50, 0x51, 0x7, 0x1b, 0x2, 0x2, 0x51, 
    0x52, 0x7, 0x15, 0x2, 0x2, 0x52, 0x68, 0x5, 0x6, 0x4, 0x7, 0x53, 0x54, 
    0x7, 0x1b, 0x2, 0x2, 0x54, 0x5a, 0x7, 0xb, 0x2, 0x2, 0x55, 0x56, 0x5, 
    0x6, 0x4, 0x2, 0x56, 0x57, 0x7, 0x6, 0x2, 0x2, 0x57, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x55, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5f, 0x5, 0x6, 0x4, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x68, 0x7, 
    0xc, 0x2, 0x2, 0x61, 0x68, 0x7, 0x1b, 0x2, 0x2, 0x62, 0x68, 0x7, 0x4, 
    0x2, 0x2, 0x63, 0x64, 0x7, 0xb, 0x2, 0x2, 0x64, 0x65, 0x5, 0x6, 0x4, 
    0x2, 0x65, 0x66, 0x7, 0xc, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x67, 0x50, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x67, 0x61, 0x3, 0x2, 0x2, 0x2, 0x67, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x63, 0x3, 0x2, 0x2, 0x2, 0x68, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0xc, 0xb, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x3, 
    0x2, 0x2, 0x6b, 0x76, 0x5, 0x6, 0x4, 0xc, 0x6c, 0x6d, 0xc, 0xa, 0x2, 
    0x2, 0x6d, 0x6e, 0x9, 0x2, 0x2, 0x2, 0x6e, 0x76, 0x5, 0x6, 0x4, 0xb, 
    0x6f, 0x70, 0xc, 0x9, 0x2, 0x2, 0x70, 0x71, 0x9, 0x4, 0x2, 0x2, 0x71, 
    0x76, 0x5, 0x6, 0x4, 0xa, 0x72, 0x73, 0xc, 0x8, 0x2, 0x2, 0x73, 0x74, 
    0x9, 0x5, 0x2, 0x2, 0x74, 0x76, 0x5, 0x6, 0x4, 0x9, 0x75, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x75, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x72, 0x3, 0x2, 0x2, 0x2, 0x76, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x7, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xb, 0x1b, 0x26, 0x2a, 0x2e, 0x38, 0x3c, 0x47, 0x4b, 0x5a, 0x5e, 0x67, 
    0x75, 0x77, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MiniDecafParser::Initializer MiniDecafParser::_init;
