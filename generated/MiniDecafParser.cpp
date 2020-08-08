
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
    setState(11);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
      | (1ULL << MiniDecafParser::ADD)
      | (1ULL << MiniDecafParser::SUB)
      | (1ULL << MiniDecafParser::MUL)
      | (1ULL << MiniDecafParser::AND)
      | (1ULL << MiniDecafParser::LPAREN)
      | (1ULL << MiniDecafParser::LBRACE)
      | (1ULL << MiniDecafParser::INT)
      | (1ULL << MiniDecafParser::RET)
      | (1ULL << MiniDecafParser::IF)
      | (1ULL << MiniDecafParser::WHILE)
      | (1ULL << MiniDecafParser::FOR)
      | (1ULL << MiniDecafParser::ID))) != 0)) {
      setState(8);
      stmts();
      setState(13);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(14);
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

std::vector<MiniDecafParser::TypeContext *> MiniDecafParser::FuncDefContext::type() {
  return getRuleContexts<MiniDecafParser::TypeContext>();
}

MiniDecafParser::TypeContext* MiniDecafParser::FuncDefContext::type(size_t i) {
  return getRuleContext<MiniDecafParser::TypeContext>(i);
}

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
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ReturnContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(16);
      match(MiniDecafParser::RET);
      setState(17);
      expr(0);
      setState(18);
      match(MiniDecafParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(20);
      match(MiniDecafParser::IF);
      setState(21);
      match(MiniDecafParser::LPAREN);
      setState(22);
      expr(0);
      setState(23);
      match(MiniDecafParser::RPAREN);
      setState(24);
      stmts();
      setState(27);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(25);
        match(MiniDecafParser::ELSE);
        setState(26);
        stmts();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(29);
      match(MiniDecafParser::WHILE);
      setState(30);
      match(MiniDecafParser::LPAREN);
      setState(31);
      expr(0);
      setState(32);
      match(MiniDecafParser::RPAREN);
      setState(33);
      stmts();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ForLoopContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(35);
      match(MiniDecafParser::FOR);
      setState(36);
      match(MiniDecafParser::LPAREN);
      setState(38);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(37);
        expr(0);
      }
      setState(40);
      match(MiniDecafParser::SEMICOLON);
      setState(42);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(41);
        expr(0);
      }
      setState(44);
      match(MiniDecafParser::SEMICOLON);
      setState(46);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(45);
        expr(0);
      }
      setState(48);
      match(MiniDecafParser::RPAREN);
      setState(49);
      stmts();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::FuncDefContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(50);
      type();
      setState(51);
      match(MiniDecafParser::ID);
      setState(52);
      match(MiniDecafParser::LPAREN);
      setState(59);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(53);
          type();
          setState(54);
          match(MiniDecafParser::ID);
          setState(55);
          match(MiniDecafParser::COMMA); 
        }
        setState(61);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      }
      setState(65);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::INT) {
        setState(62);
        type();
        setState(63);
        match(MiniDecafParser::ID);
      }
      setState(67);
      match(MiniDecafParser::RPAREN);
      setState(68);
      stmts();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(70);
      expr(0);
      setState(71);
      match(MiniDecafParser::SEMICOLON);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(73);
      match(MiniDecafParser::LBRACE);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::LBRACE)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::RET)
        | (1ULL << MiniDecafParser::IF)
        | (1ULL << MiniDecafParser::WHILE)
        | (1ULL << MiniDecafParser::FOR)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(74);
        stmts();
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
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

tree::TerminalNode* MiniDecafParser::LiteralContext::INTEGER() {
  return getToken(MiniDecafParser::INTEGER, 0);
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

MiniDecafParser::TypeContext* MiniDecafParser::AssignContext::type() {
  return getRuleContext<MiniDecafParser::TypeContext>(0);
}

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

tree::TerminalNode* MiniDecafParser::UnaryContext::MUL() {
  return getToken(MiniDecafParser::MUL, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryContext::AND() {
  return getToken(MiniDecafParser::AND, 0);
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
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(84);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(85);
      expr(10);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(86);
      type();
      setState(87);
      match(MiniDecafParser::ID);
      setState(88);
      match(MiniDecafParser::ASSIGN);
      setState(89);
      expr(5);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CallFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(91);
      match(MiniDecafParser::ID);
      setState(92);
      match(MiniDecafParser::LPAREN);
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(93);
          expr(0);
          setState(94);
          match(MiniDecafParser::COMMA); 
        }
        setState(100);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(102);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(101);
        expr(0);
      }
      setState(104);
      match(MiniDecafParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(105);
      match(MiniDecafParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(106);
      match(MiniDecafParser::INTEGER);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(107);
      match(MiniDecafParser::LPAREN);
      setState(108);
      expr(0);
      setState(109);
      match(MiniDecafParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(127);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(125);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(113);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(114);
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
          setState(115);
          expr(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(116);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(117);
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
          setState(118);
          expr(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LessGreatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(119);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(120);
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
          setState(121);
          expr(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(122);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(123);
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
          setState(124);
          expr(7);
          break;
        }

        } 
      }
      setState(129);
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

//----------------- TypeContext ------------------------------------------------------------------

MiniDecafParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::TypeContext::INT() {
  return getToken(MiniDecafParser::INT, 0);
}


size_t MiniDecafParser::TypeContext::getRuleIndex() const {
  return MiniDecafParser::RuleType;
}


antlrcpp::Any MiniDecafParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::TypeContext* MiniDecafParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniDecafParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(MiniDecafParser::INT);
   
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
  "prog", "stmts", "expr", "type"
};

std::vector<std::string> MiniDecafParser::_literalNames = {
  "", "", "", "';'", "','", "'+'", "'-'", "'*'", "'&'", "'/'", "'('", "')'", 
  "'{'", "'}'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'='", "'int'", 
  "'return'", "'if'", "'else'", "'while'", "'for'"
};

std::vector<std::string> MiniDecafParser::_symbolicNames = {
  "", "WS", "INTEGER", "SEMICOLON", "COMMA", "ADD", "SUB", "MUL", "AND", 
  "DIV", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "EQ", "NEQ", "LT", "LE", 
  "GT", "GE", "ASSIGN", "INT", "RET", "IF", "ELSE", "WHILE", "FOR", "ID"
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
    0x3, 0x1d, 0x87, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x7, 0x2, 0xc, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0xf, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x1e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x29, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3c, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3f, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x44, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4e, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x51, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 0x54, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x63, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x66, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0x69, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x72, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x80, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x83, 0xb, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x3, 0x6, 0x6, 0x2, 0x4, 0x6, 
    0x8, 0x2, 0x7, 0x3, 0x2, 0x7, 0xa, 0x4, 0x2, 0x9, 0x9, 0xb, 0xb, 0x3, 
    0x2, 0x7, 0x8, 0x3, 0x2, 0x12, 0x15, 0x3, 0x2, 0x10, 0x11, 0x2, 0x9b, 
    0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4, 0x53, 0x3, 0x2, 0x2, 0x2, 0x6, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x84, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 0x4, 
    0x3, 0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x7, 0x2, 
    0x2, 0x3, 0x11, 0x3, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x7, 0x18, 0x2, 
    0x2, 0x13, 0x14, 0x5, 0x6, 0x4, 0x2, 0x14, 0x15, 0x7, 0x5, 0x2, 0x2, 
    0x15, 0x54, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x7, 0x19, 0x2, 0x2, 0x17, 
    0x18, 0x7, 0xc, 0x2, 0x2, 0x18, 0x19, 0x5, 0x6, 0x4, 0x2, 0x19, 0x1a, 
    0x7, 0xd, 0x2, 0x2, 0x1a, 0x1d, 0x5, 0x4, 0x3, 0x2, 0x1b, 0x1c, 0x7, 
    0x1a, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x20, 0x7, 0x1b, 0x2, 0x2, 0x20, 0x21, 0x7, 0xc, 0x2, 0x2, 
    0x21, 0x22, 0x5, 0x6, 0x4, 0x2, 0x22, 0x23, 0x7, 0xd, 0x2, 0x2, 0x23, 
    0x24, 0x5, 0x4, 0x3, 0x2, 0x24, 0x54, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 
    0x7, 0x1c, 0x2, 0x2, 0x26, 0x28, 0x7, 0xc, 0x2, 0x2, 0x27, 0x29, 0x5, 
    0x6, 0x4, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x7, 0x5, 0x2, 
    0x2, 0x2b, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x30, 0x7, 0x5, 0x2, 0x2, 0x2f, 0x31, 0x5, 0x6, 0x4, 0x2, 0x30, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0xd, 0x2, 0x2, 0x33, 0x54, 0x5, 0x4, 
    0x3, 0x2, 0x34, 0x35, 0x5, 0x8, 0x5, 0x2, 0x35, 0x36, 0x7, 0x1d, 0x2, 
    0x2, 0x36, 0x3d, 0x7, 0xc, 0x2, 0x2, 0x37, 0x38, 0x5, 0x8, 0x5, 0x2, 
    0x38, 0x39, 0x7, 0x1d, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x6, 0x2, 0x2, 0x3a, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x41, 0x5, 0x8, 0x5, 0x2, 0x41, 0x42, 0x7, 0x1d, 0x2, 
    0x2, 0x42, 0x44, 0x3, 0x2, 0x2, 0x2, 0x43, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x46, 0x7, 0xd, 0x2, 0x2, 0x46, 0x47, 0x5, 0x4, 0x3, 0x2, 0x47, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x5, 0x6, 0x4, 0x2, 0x49, 0x4a, 0x7, 
    0x5, 0x2, 0x2, 0x4a, 0x54, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4f, 0x7, 0xe, 
    0x2, 0x2, 0x4c, 0x4e, 0x5, 0x4, 0x3, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x7, 0xf, 0x2, 0x2, 0x53, 0x12, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x16, 0x3, 0x2, 0x2, 0x2, 0x53, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x25, 0x3, 0x2, 0x2, 0x2, 0x53, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x48, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x8, 0x4, 0x1, 0x2, 
    0x56, 0x57, 0x9, 0x2, 0x2, 0x2, 0x57, 0x72, 0x5, 0x6, 0x4, 0xc, 0x58, 
    0x59, 0x5, 0x8, 0x5, 0x2, 0x59, 0x5a, 0x7, 0x1d, 0x2, 0x2, 0x5a, 0x5b, 
    0x7, 0x16, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x6, 0x4, 0x7, 0x5c, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x1d, 0x2, 0x2, 0x5e, 0x64, 0x7, 0xc, 
    0x2, 0x2, 0x5f, 0x60, 0x5, 0x6, 0x4, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 
    0x2, 0x61, 0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x69, 0x5, 0x6, 0x4, 0x2, 0x68, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x72, 0x7, 0xd, 0x2, 0x2, 0x6b, 0x72, 0x7, 0x1d, 0x2, 
    0x2, 0x6c, 0x72, 0x7, 0x4, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0xc, 0x2, 0x2, 
    0x6e, 0x6f, 0x5, 0x6, 0x4, 0x2, 0x6f, 0x70, 0x7, 0xd, 0x2, 0x2, 0x70, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x71, 0x55, 0x3, 0x2, 0x2, 0x2, 0x71, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x71, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x81, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0xc, 0xb, 0x2, 
    0x2, 0x74, 0x75, 0x9, 0x3, 0x2, 0x2, 0x75, 0x80, 0x5, 0x6, 0x4, 0xc, 
    0x76, 0x77, 0xc, 0xa, 0x2, 0x2, 0x77, 0x78, 0x9, 0x4, 0x2, 0x2, 0x78, 
    0x80, 0x5, 0x6, 0x4, 0xb, 0x79, 0x7a, 0xc, 0x9, 0x2, 0x2, 0x7a, 0x7b, 
    0x9, 0x5, 0x2, 0x2, 0x7b, 0x80, 0x5, 0x6, 0x4, 0xa, 0x7c, 0x7d, 0xc, 
    0x8, 0x2, 0x2, 0x7d, 0x7e, 0x9, 0x6, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x6, 
    0x4, 0x9, 0x7f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x7, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x17, 0x2, 0x2, 0x85, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0xd, 0x1d, 0x28, 0x2c, 0x30, 0x3d, 0x43, 0x4f, 
    0x53, 0x64, 0x68, 0x71, 0x7f, 0x81, 
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
