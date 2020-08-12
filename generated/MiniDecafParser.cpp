
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


//----------------- ToplvContext ------------------------------------------------------------------

MiniDecafParser::ToplvContext::ToplvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::ToplvContext::EOF() {
  return getToken(MiniDecafParser::EOF, 0);
}

std::vector<MiniDecafParser::ProgContext *> MiniDecafParser::ToplvContext::prog() {
  return getRuleContexts<MiniDecafParser::ProgContext>();
}

MiniDecafParser::ProgContext* MiniDecafParser::ToplvContext::prog(size_t i) {
  return getRuleContext<MiniDecafParser::ProgContext>(i);
}


size_t MiniDecafParser::ToplvContext::getRuleIndex() const {
  return MiniDecafParser::RuleToplv;
}


antlrcpp::Any MiniDecafParser::ToplvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitToplv(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ToplvContext* MiniDecafParser::toplv() {
  ToplvContext *_localctx = _tracker.createInstance<ToplvContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniDecafParser::RuleToplv);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(13);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniDecafParser::INT) {
      setState(10);
      prog();
      setState(15);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(16);
    match(MiniDecafParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

MiniDecafParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniDecafParser::TypeContext *> MiniDecafParser::ProgContext::type() {
  return getRuleContexts<MiniDecafParser::TypeContext>();
}

MiniDecafParser::TypeContext* MiniDecafParser::ProgContext::type(size_t i) {
  return getRuleContext<MiniDecafParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ProgContext::ID() {
  return getTokens(MiniDecafParser::ID);
}

tree::TerminalNode* MiniDecafParser::ProgContext::ID(size_t i) {
  return getToken(MiniDecafParser::ID, i);
}

tree::TerminalNode* MiniDecafParser::ProgContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

tree::TerminalNode* MiniDecafParser::ProgContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::StmtsContext* MiniDecafParser::ProgContext::stmts() {
  return getRuleContext<MiniDecafParser::StmtsContext>(0);
}

tree::TerminalNode* MiniDecafParser::ProgContext::SEMICOLON() {
  return getToken(MiniDecafParser::SEMICOLON, 0);
}

tree::TerminalNode* MiniDecafParser::ProgContext::ASSIGN() {
  return getToken(MiniDecafParser::ASSIGN, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ProgContext::INTEGER() {
  return getTokens(MiniDecafParser::INTEGER);
}

tree::TerminalNode* MiniDecafParser::ProgContext::INTEGER(size_t i) {
  return getToken(MiniDecafParser::INTEGER, i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ProgContext::COMMA() {
  return getTokens(MiniDecafParser::COMMA);
}

tree::TerminalNode* MiniDecafParser::ProgContext::COMMA(size_t i) {
  return getToken(MiniDecafParser::COMMA, i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ProgContext::LSQUBRACE() {
  return getTokens(MiniDecafParser::LSQUBRACE);
}

tree::TerminalNode* MiniDecafParser::ProgContext::LSQUBRACE(size_t i) {
  return getToken(MiniDecafParser::LSQUBRACE, i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ProgContext::RSQUBRACE() {
  return getTokens(MiniDecafParser::RSQUBRACE);
}

tree::TerminalNode* MiniDecafParser::ProgContext::RSQUBRACE(size_t i) {
  return getToken(MiniDecafParser::RSQUBRACE, i);
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
  enterRule(_localctx, 2, MiniDecafParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(18);
    type();
    setState(19);
    match(MiniDecafParser::ID);
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::LPAREN: {
        setState(20);
        match(MiniDecafParser::LPAREN);
        setState(27);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(21);
            type();
            setState(22);
            match(MiniDecafParser::ID);
            setState(23);
            match(MiniDecafParser::COMMA); 
          }
          setState(29);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        }
        setState(33);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MiniDecafParser::INT) {
          setState(30);
          type();
          setState(31);
          match(MiniDecafParser::ID);
        }
        setState(35);
        match(MiniDecafParser::RPAREN);
        setState(36);
        stmts();
        break;
      }

      case MiniDecafParser::SEMICOLON:
      case MiniDecafParser::LSQUBRACE: {
        setState(42);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MiniDecafParser::LSQUBRACE) {
          setState(37);
          match(MiniDecafParser::LSQUBRACE);
          setState(38);
          match(MiniDecafParser::INTEGER);
          setState(39);
          match(MiniDecafParser::RSQUBRACE);
          setState(44);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(45);
        match(MiniDecafParser::SEMICOLON);
        break;
      }

      case MiniDecafParser::ASSIGN: {
        setState(46);
        match(MiniDecafParser::ASSIGN);
        setState(47);
        match(MiniDecafParser::INTEGER);
        setState(48);
        match(MiniDecafParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
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
//----------------- DowhileContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::DowhileContext::DO() {
  return getToken(MiniDecafParser::DO, 0);
}

MiniDecafParser::StmtsContext* MiniDecafParser::DowhileContext::stmts() {
  return getRuleContext<MiniDecafParser::StmtsContext>(0);
}

tree::TerminalNode* MiniDecafParser::DowhileContext::WHILE() {
  return getToken(MiniDecafParser::WHILE, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::DowhileContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

MiniDecafParser::DowhileContext::DowhileContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::DowhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDowhile(this);
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
//----------------- NopContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::NopContext::SEMICOLON() {
  return getToken(MiniDecafParser::SEMICOLON, 0);
}

MiniDecafParser::NopContext::NopContext(StmtsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::NopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitNop(this);
  else
    return visitor->visitChildren(this);
}
MiniDecafParser::StmtsContext* MiniDecafParser::stmts() {
  StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniDecafParser::RuleStmts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::RET: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ReturnContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(51);
        match(MiniDecafParser::RET);
        setState(52);
        expr(0);
        setState(53);
        match(MiniDecafParser::SEMICOLON);
        break;
      }

      case MiniDecafParser::IF: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::IfStmtContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(55);
        match(MiniDecafParser::IF);
        setState(56);
        match(MiniDecafParser::LPAREN);
        setState(57);
        expr(0);
        setState(58);
        match(MiniDecafParser::RPAREN);
        setState(59);
        stmts();
        setState(62);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          setState(60);
          match(MiniDecafParser::ELSE);
          setState(61);
          stmts();
          break;
        }

        }
        break;
      }

      case MiniDecafParser::WHILE: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::WhileLoopContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(64);
        match(MiniDecafParser::WHILE);
        setState(65);
        match(MiniDecafParser::LPAREN);
        setState(66);
        expr(0);
        setState(67);
        match(MiniDecafParser::RPAREN);
        setState(68);
        stmts();
        break;
      }

      case MiniDecafParser::FOR: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::ForLoopContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(70);
        match(MiniDecafParser::FOR);
        setState(71);
        match(MiniDecafParser::LPAREN);
        setState(73);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
          | (1ULL << MiniDecafParser::ADD)
          | (1ULL << MiniDecafParser::SUB)
          | (1ULL << MiniDecafParser::MUL)
          | (1ULL << MiniDecafParser::AND)
          | (1ULL << MiniDecafParser::NOT)
          | (1ULL << MiniDecafParser::BITNOT)
          | (1ULL << MiniDecafParser::LPAREN)
          | (1ULL << MiniDecafParser::SIZEOF)
          | (1ULL << MiniDecafParser::INT)
          | (1ULL << MiniDecafParser::CONTINUE)
          | (1ULL << MiniDecafParser::BREAK)
          | (1ULL << MiniDecafParser::ID))) != 0)) {
          setState(72);
          expr(0);
        }
        setState(75);
        match(MiniDecafParser::SEMICOLON);
        setState(77);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
          | (1ULL << MiniDecafParser::ADD)
          | (1ULL << MiniDecafParser::SUB)
          | (1ULL << MiniDecafParser::MUL)
          | (1ULL << MiniDecafParser::AND)
          | (1ULL << MiniDecafParser::NOT)
          | (1ULL << MiniDecafParser::BITNOT)
          | (1ULL << MiniDecafParser::LPAREN)
          | (1ULL << MiniDecafParser::SIZEOF)
          | (1ULL << MiniDecafParser::INT)
          | (1ULL << MiniDecafParser::CONTINUE)
          | (1ULL << MiniDecafParser::BREAK)
          | (1ULL << MiniDecafParser::ID))) != 0)) {
          setState(76);
          expr(0);
        }
        setState(79);
        match(MiniDecafParser::SEMICOLON);
        setState(81);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
          | (1ULL << MiniDecafParser::ADD)
          | (1ULL << MiniDecafParser::SUB)
          | (1ULL << MiniDecafParser::MUL)
          | (1ULL << MiniDecafParser::AND)
          | (1ULL << MiniDecafParser::NOT)
          | (1ULL << MiniDecafParser::BITNOT)
          | (1ULL << MiniDecafParser::LPAREN)
          | (1ULL << MiniDecafParser::SIZEOF)
          | (1ULL << MiniDecafParser::INT)
          | (1ULL << MiniDecafParser::CONTINUE)
          | (1ULL << MiniDecafParser::BREAK)
          | (1ULL << MiniDecafParser::ID))) != 0)) {
          setState(80);
          expr(0);
        }
        setState(83);
        match(MiniDecafParser::RPAREN);
        setState(84);
        stmts();
        break;
      }

      case MiniDecafParser::DO: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::DowhileContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(85);
        match(MiniDecafParser::DO);
        setState(86);
        stmts();
        setState(87);
        match(MiniDecafParser::WHILE);
        setState(88);
        expr(0);
        break;
      }

      case MiniDecafParser::INTEGER:
      case MiniDecafParser::ADD:
      case MiniDecafParser::SUB:
      case MiniDecafParser::MUL:
      case MiniDecafParser::AND:
      case MiniDecafParser::NOT:
      case MiniDecafParser::BITNOT:
      case MiniDecafParser::LPAREN:
      case MiniDecafParser::SIZEOF:
      case MiniDecafParser::INT:
      case MiniDecafParser::CONTINUE:
      case MiniDecafParser::BREAK:
      case MiniDecafParser::ID: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::PrintExprContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(90);
        expr(0);
        setState(91);
        match(MiniDecafParser::SEMICOLON);
        break;
      }

      case MiniDecafParser::LBRACE: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::StmtBlockContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(93);
        match(MiniDecafParser::LBRACE);
        setState(97);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
          | (1ULL << MiniDecafParser::SEMICOLON)
          | (1ULL << MiniDecafParser::ADD)
          | (1ULL << MiniDecafParser::SUB)
          | (1ULL << MiniDecafParser::MUL)
          | (1ULL << MiniDecafParser::AND)
          | (1ULL << MiniDecafParser::NOT)
          | (1ULL << MiniDecafParser::BITNOT)
          | (1ULL << MiniDecafParser::LPAREN)
          | (1ULL << MiniDecafParser::LBRACE)
          | (1ULL << MiniDecafParser::SIZEOF)
          | (1ULL << MiniDecafParser::INT)
          | (1ULL << MiniDecafParser::RET)
          | (1ULL << MiniDecafParser::IF)
          | (1ULL << MiniDecafParser::WHILE)
          | (1ULL << MiniDecafParser::FOR)
          | (1ULL << MiniDecafParser::CONTINUE)
          | (1ULL << MiniDecafParser::BREAK)
          | (1ULL << MiniDecafParser::DO)
          | (1ULL << MiniDecafParser::ID))) != 0)) {
          setState(94);
          stmts();
          setState(99);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(100);
        match(MiniDecafParser::RBRACE);
        break;
      }

      case MiniDecafParser::SEMICOLON: {
        _localctx = dynamic_cast<StmtsContext *>(_tracker.createInstance<MiniDecafParser::NopContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(101);
        match(MiniDecafParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
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

tree::TerminalNode* MiniDecafParser::MulDivContext::MOD() {
  return getToken(MiniDecafParser::MOD, 0);
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
//----------------- TernaryContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::TernaryContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::TernaryContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::TernaryContext::QUES() {
  return getToken(MiniDecafParser::QUES, 0);
}

tree::TerminalNode* MiniDecafParser::TernaryContext::COLON() {
  return getToken(MiniDecafParser::COLON, 0);
}

MiniDecafParser::TernaryContext::TernaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::TernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTernary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDefContext ------------------------------------------------------------------

MiniDecafParser::TypeContext* MiniDecafParser::ArrayDefContext::type() {
  return getRuleContext<MiniDecafParser::TypeContext>(0);
}

tree::TerminalNode* MiniDecafParser::ArrayDefContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

tree::TerminalNode* MiniDecafParser::ArrayDefContext::LSQUBRACE() {
  return getToken(MiniDecafParser::LSQUBRACE, 0);
}

tree::TerminalNode* MiniDecafParser::ArrayDefContext::INTEGER() {
  return getToken(MiniDecafParser::INTEGER, 0);
}

tree::TerminalNode* MiniDecafParser::ArrayDefContext::RSQUBRACE() {
  return getToken(MiniDecafParser::RSQUBRACE, 0);
}

MiniDecafParser::ArrayDefContext::ArrayDefContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ArrayDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitArrayDef(this);
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
//----------------- BreakContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::BreakContext::BREAK() {
  return getToken(MiniDecafParser::BREAK, 0);
}

MiniDecafParser::BreakContext::BreakContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::BreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LANDContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::LANDContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::LANDContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::LANDContext::LAND() {
  return getToken(MiniDecafParser::LAND, 0);
}

MiniDecafParser::LANDContext::LANDContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::LANDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLAND(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayCallContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::ArrayCallContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

tree::TerminalNode* MiniDecafParser::ArrayCallContext::LSQUBRACE() {
  return getToken(MiniDecafParser::LSQUBRACE, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::ArrayCallContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

tree::TerminalNode* MiniDecafParser::ArrayCallContext::RSQUBRACE() {
  return getToken(MiniDecafParser::RSQUBRACE, 0);
}

MiniDecafParser::ArrayCallContext::ArrayCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ArrayCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitArrayCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::ContinueContext::CONTINUE() {
  return getToken(MiniDecafParser::CONTINUE, 0);
}

MiniDecafParser::ContinueContext::ContinueContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::ContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitContinue(this);
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

tree::TerminalNode* MiniDecafParser::UnaryContext::NOT() {
  return getToken(MiniDecafParser::NOT, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryContext::BITNOT() {
  return getToken(MiniDecafParser::BITNOT, 0);
}

MiniDecafParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LORContext ------------------------------------------------------------------

std::vector<MiniDecafParser::ExprContext *> MiniDecafParser::LORContext::expr() {
  return getRuleContexts<MiniDecafParser::ExprContext>();
}

MiniDecafParser::ExprContext* MiniDecafParser::LORContext::expr(size_t i) {
  return getRuleContext<MiniDecafParser::ExprContext>(i);
}

tree::TerminalNode* MiniDecafParser::LORContext::LOR() {
  return getToken(MiniDecafParser::LOR, 0);
}

MiniDecafParser::LORContext::LORContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::LORContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLOR(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDefContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::VarDefContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

MiniDecafParser::TypeContext* MiniDecafParser::VarDefContext::type() {
  return getRuleContext<MiniDecafParser::TypeContext>(0);
}

tree::TerminalNode* MiniDecafParser::VarDefContext::ASSIGN() {
  return getToken(MiniDecafParser::ASSIGN, 0);
}

MiniDecafParser::ExprContext* MiniDecafParser::VarDefContext::expr() {
  return getRuleContext<MiniDecafParser::ExprContext>(0);
}

MiniDecafParser::VarDefContext::VarDefContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
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
//----------------- SizeOfContext ------------------------------------------------------------------

tree::TerminalNode* MiniDecafParser::SizeOfContext::SIZEOF() {
  return getToken(MiniDecafParser::SIZEOF, 0);
}

tree::TerminalNode* MiniDecafParser::SizeOfContext::LPAREN() {
  return getToken(MiniDecafParser::LPAREN, 0);
}

tree::TerminalNode* MiniDecafParser::SizeOfContext::ID() {
  return getToken(MiniDecafParser::ID, 0);
}

tree::TerminalNode* MiniDecafParser::SizeOfContext::RPAREN() {
  return getToken(MiniDecafParser::RPAREN, 0);
}

MiniDecafParser::SizeOfContext::SizeOfContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniDecafParser::SizeOfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitSizeOf(this);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, MiniDecafParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(105);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::NOT)
        | (1ULL << MiniDecafParser::BITNOT))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(106);
      expr(17);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VarDefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(108);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::INT) {
        setState(107);
        type();
      }
      setState(110);
      match(MiniDecafParser::ID);
      setState(113);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(111);
        match(MiniDecafParser::ASSIGN);
        setState(112);
        expr(0);
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ArrayDefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(115);
      type();
      setState(116);
      match(MiniDecafParser::ID);
      setState(117);
      match(MiniDecafParser::LSQUBRACE);
      setState(118);
      match(MiniDecafParser::INTEGER);
      setState(119);
      match(MiniDecafParser::RSQUBRACE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CallFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(MiniDecafParser::ID);
      setState(122);
      match(MiniDecafParser::LPAREN);
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(123);
          expr(0);
          setState(124);
          match(MiniDecafParser::COMMA); 
        }
        setState(130);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      setState(132);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::INTEGER)
        | (1ULL << MiniDecafParser::ADD)
        | (1ULL << MiniDecafParser::SUB)
        | (1ULL << MiniDecafParser::MUL)
        | (1ULL << MiniDecafParser::AND)
        | (1ULL << MiniDecafParser::NOT)
        | (1ULL << MiniDecafParser::BITNOT)
        | (1ULL << MiniDecafParser::LPAREN)
        | (1ULL << MiniDecafParser::SIZEOF)
        | (1ULL << MiniDecafParser::INT)
        | (1ULL << MiniDecafParser::CONTINUE)
        | (1ULL << MiniDecafParser::BREAK)
        | (1ULL << MiniDecafParser::ID))) != 0)) {
        setState(131);
        expr(0);
      }
      setState(134);
      match(MiniDecafParser::RPAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SizeOfContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(MiniDecafParser::SIZEOF);
      setState(136);
      match(MiniDecafParser::LPAREN);
      setState(137);
      match(MiniDecafParser::ID);
      setState(138);
      match(MiniDecafParser::RPAREN);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      match(MiniDecafParser::ID);
      setState(140);
      match(MiniDecafParser::LSQUBRACE);
      setState(141);
      expr(0);
      setState(142);
      match(MiniDecafParser::RSQUBRACE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(144);
      match(MiniDecafParser::INTEGER);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(145);
      match(MiniDecafParser::LPAREN);
      setState(146);
      expr(0);
      setState(147);
      match(MiniDecafParser::RPAREN);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BreakContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(149);
      match(MiniDecafParser::BREAK);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ContinueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(150);
      match(MiniDecafParser::CONTINUE);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(179);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(177);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(153);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(154);
          dynamic_cast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::MUL)
            | (1ULL << MiniDecafParser::DIV)
            | (1ULL << MiniDecafParser::MOD))) != 0))) {
            dynamic_cast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(155);
          expr(17);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(156);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(157);
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
          setState(158);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LessGreatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(159);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(160);
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
          setState(161);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(162);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(163);
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
          setState(164);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LANDContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(166);
          dynamic_cast<LANDContext *>(_localctx)->op = match(MiniDecafParser::LAND);
          setState(167);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LORContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(168);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(169);
          dynamic_cast<LORContext *>(_localctx)->op = match(MiniDecafParser::LOR);
          setState(170);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<TernaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(171);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(172);
          match(MiniDecafParser::QUES);
          setState(173);
          expr(0);
          setState(174);
          match(MiniDecafParser::COLON);
          setState(175);
          expr(11);
          break;
        }

        } 
      }
      setState(181);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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

std::vector<tree::TerminalNode *> MiniDecafParser::TypeContext::MUL() {
  return getTokens(MiniDecafParser::MUL);
}

tree::TerminalNode* MiniDecafParser::TypeContext::MUL(size_t i) {
  return getToken(MiniDecafParser::MUL, i);
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
  enterRule(_localctx, 8, MiniDecafParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(MiniDecafParser::INT);
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniDecafParser::MUL) {
      setState(183);
      match(MiniDecafParser::MUL);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
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
    case 3: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 16);
    case 1: return precpred(_ctx, 15);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);

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
  "toplv", "prog", "stmts", "expr", "type"
};

std::vector<std::string> MiniDecafParser::_literalNames = {
  "", "", "", "';'", "','", "'+'", "'-'", "'*'", "'&'", "'/'", "'!'", "'%'", 
  "'?'", "':'", "'~'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'=='", 
  "'!='", "'<'", "'<='", "'>'", "'>='", "'&&'", "'||'", "'='", "'sizeof'", 
  "'int'", "'return'", "'if'", "'else'", "'while'", "'for'", "'continue'", 
  "'break'", "'do'"
};

std::vector<std::string> MiniDecafParser::_symbolicNames = {
  "", "WS", "INTEGER", "SEMICOLON", "COMMA", "ADD", "SUB", "MUL", "AND", 
  "DIV", "NOT", "MOD", "QUES", "COLON", "BITNOT", "LPAREN", "RPAREN", "LBRACE", 
  "RBRACE", "LSQUBRACE", "RSQUBRACE", "EQ", "NEQ", "LT", "LE", "GT", "GE", 
  "LAND", "LOR", "ASSIGN", "SIZEOF", "INT", "RET", "IF", "ELSE", "WHILE", 
  "FOR", "CONTINUE", "BREAK", "DO", "ID"
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
    0x3, 0x2a, 0xc0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x7, 0x2, 0xe, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x11, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x1c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1f, 0xb, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x24, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2b, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2e, 
    0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x34, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x50, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x54, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x62, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x65, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x69, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6f, 0xa, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x74, 0xa, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x81, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x84, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 0x87, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x9a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0xb4, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xb7, 0xb, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0xbb, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xbe, 0xb, 0x6, 
    0x3, 0x6, 0x2, 0x3, 0x8, 0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x7, 0x5, 
    0x2, 0x7, 0xa, 0xc, 0xc, 0x10, 0x10, 0x5, 0x2, 0x9, 0x9, 0xb, 0xb, 0xd, 
    0xd, 0x3, 0x2, 0x7, 0x8, 0x3, 0x2, 0x19, 0x1c, 0x3, 0x2, 0x17, 0x18, 
    0x2, 0xe1, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4, 0x14, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x68, 0x3, 0x2, 0x2, 0x2, 0x8, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xe, 0x5, 0x4, 0x3, 0x2, 0xd, 0xc, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x10, 0x3, 0x2, 0x2, 0x2, 0x10, 0x12, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x7, 0x2, 0x2, 0x3, 0x13, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0xa, 0x6, 0x2, 0x15, 0x33, 0x7, 
    0x2a, 0x2, 0x2, 0x16, 0x1d, 0x7, 0x11, 0x2, 0x2, 0x17, 0x18, 0x5, 0xa, 
    0x6, 0x2, 0x18, 0x19, 0x7, 0x2a, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x6, 0x2, 
    0x2, 0x1a, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x5, 0xa, 0x6, 0x2, 0x21, 0x22, 0x7, 
    0x2a, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x20, 0x3, 0x2, 
    0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x26, 0x7, 0x12, 0x2, 0x2, 0x26, 0x34, 0x5, 0x6, 0x4, 0x2, 
    0x27, 0x28, 0x7, 0x15, 0x2, 0x2, 0x28, 0x29, 0x7, 0x4, 0x2, 0x2, 0x29, 
    0x2b, 0x7, 0x16, 0x2, 0x2, 0x2a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x34, 0x7, 0x5, 0x2, 0x2, 0x30, 0x31, 0x7, 0x1f, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x4, 0x2, 0x2, 0x32, 0x34, 0x7, 0x5, 0x2, 0x2, 
    0x33, 0x16, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x30, 0x3, 0x2, 0x2, 0x2, 0x34, 0x5, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x7, 0x22, 0x2, 0x2, 0x36, 0x37, 0x5, 0x8, 0x5, 0x2, 0x37, 0x38, 0x7, 
    0x5, 0x2, 0x2, 0x38, 0x69, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x23, 
    0x2, 0x2, 0x3a, 0x3b, 0x7, 0x11, 0x2, 0x2, 0x3b, 0x3c, 0x5, 0x8, 0x5, 
    0x2, 0x3c, 0x3d, 0x7, 0x12, 0x2, 0x2, 0x3d, 0x40, 0x5, 0x6, 0x4, 0x2, 
    0x3e, 0x3f, 0x7, 0x24, 0x2, 0x2, 0x3f, 0x41, 0x5, 0x6, 0x4, 0x2, 0x40, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x25, 0x2, 0x2, 0x43, 0x44, 0x7, 
    0x11, 0x2, 0x2, 0x44, 0x45, 0x5, 0x8, 0x5, 0x2, 0x45, 0x46, 0x7, 0x12, 
    0x2, 0x2, 0x46, 0x47, 0x5, 0x6, 0x4, 0x2, 0x47, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x7, 0x26, 0x2, 0x2, 0x49, 0x4b, 0x7, 0x11, 0x2, 0x2, 
    0x4a, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 
    0x7, 0x5, 0x2, 0x2, 0x4e, 0x50, 0x5, 0x8, 0x5, 0x2, 0x4f, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x53, 0x7, 0x5, 0x2, 0x2, 0x52, 0x54, 0x5, 0x8, 0x5, 
    0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x12, 0x2, 0x2, 0x56, 
    0x69, 0x5, 0x6, 0x4, 0x2, 0x57, 0x58, 0x7, 0x29, 0x2, 0x2, 0x58, 0x59, 
    0x5, 0x6, 0x4, 0x2, 0x59, 0x5a, 0x7, 0x25, 0x2, 0x2, 0x5a, 0x5b, 0x5, 
    0x8, 0x5, 0x2, 0x5b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x8, 
    0x5, 0x2, 0x5d, 0x5e, 0x7, 0x5, 0x2, 0x2, 0x5e, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x63, 0x7, 0x13, 0x2, 0x2, 0x60, 0x62, 0x5, 0x6, 0x4, 0x2, 
    0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x7, 
    0x14, 0x2, 0x2, 0x67, 0x69, 0x7, 0x5, 0x2, 0x2, 0x68, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x39, 0x3, 0x2, 0x2, 0x2, 0x68, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x48, 0x3, 0x2, 0x2, 0x2, 0x68, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x68, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x8, 0x5, 0x1, 0x2, 0x6b, 0x6c, 0x9, 0x2, 0x2, 0x2, 0x6c, 0x9a, 0x5, 
    0x8, 0x5, 0x13, 0x6d, 0x6f, 0x5, 0xa, 0x6, 0x2, 0x6e, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x73, 0x7, 0x2a, 0x2, 0x2, 0x71, 0x72, 0x7, 0x1f, 0x2, 0x2, 
    0x72, 0x74, 0x5, 0x8, 0x5, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x5, 0xa, 0x6, 0x2, 0x76, 0x77, 0x7, 0x2a, 0x2, 0x2, 0x77, 0x78, 0x7, 
    0x15, 0x2, 0x2, 0x78, 0x79, 0x7, 0x4, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x16, 
    0x2, 0x2, 0x7a, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x2a, 0x2, 
    0x2, 0x7c, 0x82, 0x7, 0x11, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x8, 0x5, 0x2, 
    0x7e, 0x7f, 0x7, 0x6, 0x2, 0x2, 0x7f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x5, 0x8, 
    0x5, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x9a, 0x7, 0x12, 0x2, 0x2, 
    0x89, 0x8a, 0x7, 0x20, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x11, 0x2, 0x2, 0x8b, 
    0x8c, 0x7, 0x2a, 0x2, 0x2, 0x8c, 0x9a, 0x7, 0x12, 0x2, 0x2, 0x8d, 0x8e, 
    0x7, 0x2a, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x15, 0x2, 0x2, 0x8f, 0x90, 0x5, 
    0x8, 0x5, 0x2, 0x90, 0x91, 0x7, 0x16, 0x2, 0x2, 0x91, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x9a, 0x7, 0x4, 0x2, 0x2, 0x93, 0x94, 0x7, 0x11, 0x2, 
    0x2, 0x94, 0x95, 0x5, 0x8, 0x5, 0x2, 0x95, 0x96, 0x7, 0x12, 0x2, 0x2, 
    0x96, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9a, 0x7, 0x28, 0x2, 0x2, 0x98, 
    0x9a, 0x7, 0x27, 0x2, 0x2, 0x99, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x75, 0x3, 0x2, 0x2, 0x2, 0x99, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x89, 0x3, 0x2, 0x2, 0x2, 0x99, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x92, 0x3, 0x2, 0x2, 0x2, 0x99, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0xc, 0x12, 0x2, 0x2, 0x9c, 
    0x9d, 0x9, 0x3, 0x2, 0x2, 0x9d, 0xb4, 0x5, 0x8, 0x5, 0x13, 0x9e, 0x9f, 
    0xc, 0x11, 0x2, 0x2, 0x9f, 0xa0, 0x9, 0x4, 0x2, 0x2, 0xa0, 0xb4, 0x5, 
    0x8, 0x5, 0x12, 0xa1, 0xa2, 0xc, 0x10, 0x2, 0x2, 0xa2, 0xa3, 0x9, 0x5, 
    0x2, 0x2, 0xa3, 0xb4, 0x5, 0x8, 0x5, 0x11, 0xa4, 0xa5, 0xc, 0xf, 0x2, 
    0x2, 0xa5, 0xa6, 0x9, 0x6, 0x2, 0x2, 0xa6, 0xb4, 0x5, 0x8, 0x5, 0x10, 
    0xa7, 0xa8, 0xc, 0xe, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x1d, 0x2, 0x2, 0xa9, 
    0xb4, 0x5, 0x8, 0x5, 0xf, 0xaa, 0xab, 0xc, 0xd, 0x2, 0x2, 0xab, 0xac, 
    0x7, 0x1e, 0x2, 0x2, 0xac, 0xb4, 0x5, 0x8, 0x5, 0xe, 0xad, 0xae, 0xc, 
    0xc, 0x2, 0x2, 0xae, 0xaf, 0x7, 0xe, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x8, 
    0x5, 0x2, 0xb0, 0xb1, 0x7, 0xf, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x8, 0x5, 
    0xd, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xbc, 0x7, 0x21, 0x2, 0x2, 0xb9, 0xbb, 0x7, 0x9, 0x2, 0x2, 
    0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x15, 0xf, 0x1d, 
    0x23, 0x2c, 0x33, 0x40, 0x4b, 0x4f, 0x53, 0x63, 0x68, 0x6e, 0x73, 0x82, 
    0x86, 0x99, 0xb3, 0xb5, 0xbc, 
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
