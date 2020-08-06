
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

tree::TerminalNode* MiniDecafParser::AssignContext::SEMICOLON() {
  return getToken(MiniDecafParser::SEMICOLON, 0);
}

MiniDecafParser::AssignContext::AssignContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
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
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
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
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(18);
      match(MiniDecafParser::ID);
      setState(19);
      match(MiniDecafParser::ASSIGN);
      setState(20);
      expr(0);
      setState(21);
      match(MiniDecafParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(23);
      match(MiniDecafParser::IF);
      setState(24);
      match(MiniDecafParser::LPAREN);
      setState(25);
      expr(0);
      setState(26);
      match(MiniDecafParser::RPAREN);
      setState(27);
      stmts();
      setState(30);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(28);
        match(MiniDecafParser::ELSE);
        setState(29);
        stmts();
        break;
      }

      }
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(32);
      match(MiniDecafParser::WHILE);
      setState(33);
      match(MiniDecafParser::LPAREN);
      setState(34);
      expr(0);
      setState(35);
      match(MiniDecafParser::RPAREN);
      setState(36);
      stmts();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(38);
      match(MiniDecafParser::FOR);
      setState(39);
      match(MiniDecafParser::LPAREN);
      setState(41);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(40);
        expr(0);
      }
      setState(43);
      match(MiniDecafParser::SEMICOLON);
      setState(45);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(44);
        expr(0);
      }
      setState(47);
      match(MiniDecafParser::SEMICOLON);
      setState(49);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(48);
        expr(0);
      }
      setState(51);
      match(MiniDecafParser::RPAREN);
      setState(52);
      stmts();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(53);
      expr(0);
      setState(54);
      match(MiniDecafParser::SEMICOLON);
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
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::ADD:
      case MiniDecafParser::SUB: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(59);
        _la = _input->LA(1);
        if (!(_la == MiniDecafParser::ADD

        || _la == MiniDecafParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(60);
        expr(8);
        break;
      }

      case MiniDecafParser::ID: {
        _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(61);
        match(MiniDecafParser::ID);
        break;
      }

      case MiniDecafParser::INT: {
        _localctx = _tracker.createInstance<LiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(62);
        match(MiniDecafParser::INT);
        break;
      }

      case MiniDecafParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(63);
        match(MiniDecafParser::LPAREN);
        setState(64);
        expr(0);
        setState(65);
        match(MiniDecafParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(81);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(69);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(70);
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
          setState(71);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(72);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(73);
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
          setState(74);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LessGreatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(75);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(76);
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
          setState(77);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(78);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(79);
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
          setState(80);
          expr(5);
          break;
        }

        } 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

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
  "", "", "", "';'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'=='", "'!='", 
  "'<'", "'<='", "'>'", "'>='", "'='", "'return'", "'if'", "'else'", "'while'", 
  "'for'"
};

std::vector<std::string> MiniDecafParser::_symbolicNames = {
  "", "WS", "INT", "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "LPAREN", "RPAREN", 
  "EQ", "NEQ", "LT", "LE", "GT", "GE", "ASSIGN", "RET", "IF", "ELSE", "WHILE", 
  "FOR", "ID"
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
    0x3, 0x18, 0x59, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x7, 0x2, 0xa, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x30, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x34, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3b, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x46, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x54, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x57, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 0x4, 0x6, 0x2, 0x6, 
    0x3, 0x2, 0x6, 0x7, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0xe, 0x11, 0x3, 0x2, 
    0xc, 0xd, 0x2, 0x66, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x45, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 
    0x9, 0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x7, 0x2, 0x2, 0x3, 
    0xf, 0x3, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x7, 0x13, 0x2, 0x2, 0x11, 
    0x12, 0x5, 0x6, 0x4, 0x2, 0x12, 0x13, 0x7, 0x5, 0x2, 0x2, 0x13, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 0x18, 0x2, 0x2, 0x15, 0x16, 0x7, 
    0x12, 0x2, 0x2, 0x16, 0x17, 0x5, 0x6, 0x4, 0x2, 0x17, 0x18, 0x7, 0x5, 
    0x2, 0x2, 0x18, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x14, 0x2, 
    0x2, 0x1a, 0x1b, 0x7, 0xa, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x6, 0x4, 0x2, 
    0x1c, 0x1d, 0x7, 0xb, 0x2, 0x2, 0x1d, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1e, 
    0x1f, 0x7, 0x15, 0x2, 0x2, 0x1f, 0x21, 0x5, 0x4, 0x3, 0x2, 0x20, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x16, 0x2, 0x2, 0x23, 0x24, 0x7, 0xa, 
    0x2, 0x2, 0x24, 0x25, 0x5, 0x6, 0x4, 0x2, 0x25, 0x26, 0x7, 0xb, 0x2, 
    0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x7, 0x17, 0x2, 0x2, 0x29, 0x2b, 0x7, 0xa, 0x2, 0x2, 0x2a, 
    0x2c, 0x5, 0x6, 0x4, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x7, 
    0x5, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x6, 0x4, 0x2, 0x2f, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x33, 0x7, 0x5, 0x2, 0x2, 0x32, 0x34, 0x5, 0x6, 0x4, 0x2, 
    0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0xb, 0x2, 0x2, 0x36, 0x3b, 
    0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x5, 0x6, 0x4, 0x2, 0x38, 0x39, 0x7, 
    0x5, 0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x10, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x14, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x22, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3d, 0x8, 0x4, 0x1, 0x2, 0x3d, 0x3e, 0x9, 0x2, 0x2, 0x2, 0x3e, 0x46, 
    0x5, 0x6, 0x4, 0xa, 0x3f, 0x46, 0x7, 0x18, 0x2, 0x2, 0x40, 0x46, 0x7, 
    0x4, 0x2, 0x2, 0x41, 0x42, 0x7, 0xa, 0x2, 0x2, 0x42, 0x43, 0x5, 0x6, 
    0x4, 0x2, 0x43, 0x44, 0x7, 0xb, 0x2, 0x2, 0x44, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x40, 0x3, 0x2, 0x2, 0x2, 0x45, 0x41, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0xc, 0x9, 0x2, 0x2, 0x48, 0x49, 
    0x9, 0x3, 0x2, 0x2, 0x49, 0x54, 0x5, 0x6, 0x4, 0xa, 0x4a, 0x4b, 0xc, 
    0x8, 0x2, 0x2, 0x4b, 0x4c, 0x9, 0x2, 0x2, 0x2, 0x4c, 0x54, 0x5, 0x6, 
    0x4, 0x9, 0x4d, 0x4e, 0xc, 0x7, 0x2, 0x2, 0x4e, 0x4f, 0x9, 0x4, 0x2, 
    0x2, 0x4f, 0x54, 0x5, 0x6, 0x4, 0x8, 0x50, 0x51, 0xc, 0x6, 0x2, 0x2, 
    0x51, 0x52, 0x9, 0x5, 0x2, 0x2, 0x52, 0x54, 0x5, 0x6, 0x4, 0x7, 0x53, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x7, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0xb, 0xb, 0x20, 0x2b, 0x2f, 0x33, 0x3a, 0x45, 0x53, 0x55, 
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
