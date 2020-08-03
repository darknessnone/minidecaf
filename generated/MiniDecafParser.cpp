
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


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

MiniDecafParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::Constant() {
  return getToken(MiniDecafParser::Constant, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(MiniDecafParser::StringLiteral);
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(MiniDecafParser::StringLiteral, i);
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::PrimaryExpressionContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

MiniDecafParser::GenericSelectionContext* MiniDecafParser::PrimaryExpressionContext::genericSelection() {
  return getRuleContext<MiniDecafParser::GenericSelectionContext>(0);
}

MiniDecafParser::CompoundStatementContext* MiniDecafParser::PrimaryExpressionContext::compoundStatement() {
  return getRuleContext<MiniDecafParser::CompoundStatementContext>(0);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::PrimaryExpressionContext::unaryExpression() {
  return getRuleContext<MiniDecafParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::PrimaryExpressionContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::PrimaryExpressionContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}


size_t MiniDecafParser::PrimaryExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RulePrimaryExpression;
}


antlrcpp::Any MiniDecafParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::PrimaryExpressionContext* MiniDecafParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniDecafParser::RulePrimaryExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(174);
      match(MiniDecafParser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      match(MiniDecafParser::Constant);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(177); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(176);
                match(MiniDecafParser::StringLiteral);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(179); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(181);
      match(MiniDecafParser::LeftParen);
      setState(182);
      expression(0);
      setState(183);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(185);
      genericSelection();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(187);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::T__0) {
        setState(186);
        match(MiniDecafParser::T__0);
      }
      setState(189);
      match(MiniDecafParser::LeftParen);
      setState(190);
      compoundStatement();
      setState(191);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(193);
      match(MiniDecafParser::T__1);
      setState(194);
      match(MiniDecafParser::LeftParen);
      setState(195);
      unaryExpression();
      setState(196);
      match(MiniDecafParser::Comma);
      setState(197);
      typeName();
      setState(198);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(200);
      match(MiniDecafParser::T__2);
      setState(201);
      match(MiniDecafParser::LeftParen);
      setState(202);
      typeName();
      setState(203);
      match(MiniDecafParser::Comma);
      setState(204);
      unaryExpression();
      setState(205);
      match(MiniDecafParser::RightParen);
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

//----------------- GenericSelectionContext ------------------------------------------------------------------

MiniDecafParser::GenericSelectionContext::GenericSelectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::GenericSelectionContext::Generic() {
  return getToken(MiniDecafParser::Generic, 0);
}

tree::TerminalNode* MiniDecafParser::GenericSelectionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::GenericSelectionContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::GenericSelectionContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

MiniDecafParser::GenericAssocListContext* MiniDecafParser::GenericSelectionContext::genericAssocList() {
  return getRuleContext<MiniDecafParser::GenericAssocListContext>(0);
}

tree::TerminalNode* MiniDecafParser::GenericSelectionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}


size_t MiniDecafParser::GenericSelectionContext::getRuleIndex() const {
  return MiniDecafParser::RuleGenericSelection;
}


antlrcpp::Any MiniDecafParser::GenericSelectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGenericSelection(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GenericSelectionContext* MiniDecafParser::genericSelection() {
  GenericSelectionContext *_localctx = _tracker.createInstance<GenericSelectionContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniDecafParser::RuleGenericSelection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(MiniDecafParser::Generic);
    setState(210);
    match(MiniDecafParser::LeftParen);
    setState(211);
    assignmentExpression();
    setState(212);
    match(MiniDecafParser::Comma);
    setState(213);
    genericAssocList(0);
    setState(214);
    match(MiniDecafParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericAssocListContext ------------------------------------------------------------------

MiniDecafParser::GenericAssocListContext::GenericAssocListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::GenericAssociationContext* MiniDecafParser::GenericAssocListContext::genericAssociation() {
  return getRuleContext<MiniDecafParser::GenericAssociationContext>(0);
}

MiniDecafParser::GenericAssocListContext* MiniDecafParser::GenericAssocListContext::genericAssocList() {
  return getRuleContext<MiniDecafParser::GenericAssocListContext>(0);
}

tree::TerminalNode* MiniDecafParser::GenericAssocListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::GenericAssocListContext::getRuleIndex() const {
  return MiniDecafParser::RuleGenericAssocList;
}


antlrcpp::Any MiniDecafParser::GenericAssocListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGenericAssocList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::GenericAssocListContext* MiniDecafParser::genericAssocList() {
   return genericAssocList(0);
}

MiniDecafParser::GenericAssocListContext* MiniDecafParser::genericAssocList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::GenericAssocListContext *_localctx = _tracker.createInstance<GenericAssocListContext>(_ctx, parentState);
  MiniDecafParser::GenericAssocListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MiniDecafParser::RuleGenericAssocList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(217);
    genericAssociation();
    _ctx->stop = _input->LT(-1);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<GenericAssocListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleGenericAssocList);
        setState(219);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(220);
        match(MiniDecafParser::Comma);
        setState(221);
        genericAssociation(); 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GenericAssociationContext ------------------------------------------------------------------

MiniDecafParser::GenericAssociationContext::GenericAssociationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::TypeNameContext* MiniDecafParser::GenericAssociationContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::GenericAssociationContext::Colon() {
  return getToken(MiniDecafParser::Colon, 0);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::GenericAssociationContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::GenericAssociationContext::Default() {
  return getToken(MiniDecafParser::Default, 0);
}


size_t MiniDecafParser::GenericAssociationContext::getRuleIndex() const {
  return MiniDecafParser::RuleGenericAssociation;
}


antlrcpp::Any MiniDecafParser::GenericAssociationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGenericAssociation(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GenericAssociationContext* MiniDecafParser::genericAssociation() {
  GenericAssociationContext *_localctx = _tracker.createInstance<GenericAssociationContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniDecafParser::RuleGenericAssociation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(234);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__0:
      case MiniDecafParser::T__3:
      case MiniDecafParser::T__4:
      case MiniDecafParser::T__5:
      case MiniDecafParser::T__6:
      case MiniDecafParser::Char:
      case MiniDecafParser::Const:
      case MiniDecafParser::Double:
      case MiniDecafParser::Enum:
      case MiniDecafParser::Float:
      case MiniDecafParser::Int:
      case MiniDecafParser::Long:
      case MiniDecafParser::Restrict:
      case MiniDecafParser::Short:
      case MiniDecafParser::Signed:
      case MiniDecafParser::Struct:
      case MiniDecafParser::Union:
      case MiniDecafParser::Unsigned:
      case MiniDecafParser::Void:
      case MiniDecafParser::Volatile:
      case MiniDecafParser::Atomic:
      case MiniDecafParser::Bool:
      case MiniDecafParser::Complex:
      case MiniDecafParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(227);
        typeName();
        setState(228);
        match(MiniDecafParser::Colon);
        setState(229);
        assignmentExpression();
        break;
      }

      case MiniDecafParser::Default: {
        enterOuterAlt(_localctx, 2);
        setState(231);
        match(MiniDecafParser::Default);
        setState(232);
        match(MiniDecafParser::Colon);
        setState(233);
        assignmentExpression();
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

//----------------- PostfixExpressionContext ------------------------------------------------------------------

MiniDecafParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::PrimaryExpressionContext* MiniDecafParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<MiniDecafParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::PostfixExpressionContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::LeftBrace() {
  return getToken(MiniDecafParser::LeftBrace, 0);
}

MiniDecafParser::InitializerListContext* MiniDecafParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<MiniDecafParser::InitializerListContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::RightBrace() {
  return getToken(MiniDecafParser::RightBrace, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

MiniDecafParser::PostfixExpressionContext* MiniDecafParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<MiniDecafParser::PostfixExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::LeftBracket() {
  return getToken(MiniDecafParser::LeftBracket, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::PostfixExpressionContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::RightBracket() {
  return getToken(MiniDecafParser::RightBracket, 0);
}

MiniDecafParser::ArgumentExpressionListContext* MiniDecafParser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContext<MiniDecafParser::ArgumentExpressionListContext>(0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::Dot() {
  return getToken(MiniDecafParser::Dot, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::Arrow() {
  return getToken(MiniDecafParser::Arrow, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::PlusPlus() {
  return getToken(MiniDecafParser::PlusPlus, 0);
}

tree::TerminalNode* MiniDecafParser::PostfixExpressionContext::MinusMinus() {
  return getToken(MiniDecafParser::MinusMinus, 0);
}


size_t MiniDecafParser::PostfixExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RulePostfixExpression;
}


antlrcpp::Any MiniDecafParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::PostfixExpressionContext* MiniDecafParser::postfixExpression() {
   return postfixExpression(0);
}

MiniDecafParser::PostfixExpressionContext* MiniDecafParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  MiniDecafParser::PostfixExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, MiniDecafParser::RulePostfixExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(237);
      primaryExpression();
      break;
    }

    case 2: {
      setState(238);
      match(MiniDecafParser::LeftParen);
      setState(239);
      typeName();
      setState(240);
      match(MiniDecafParser::RightParen);
      setState(241);
      match(MiniDecafParser::LeftBrace);
      setState(242);
      initializerList(0);
      setState(243);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 3: {
      setState(245);
      match(MiniDecafParser::LeftParen);
      setState(246);
      typeName();
      setState(247);
      match(MiniDecafParser::RightParen);
      setState(248);
      match(MiniDecafParser::LeftBrace);
      setState(249);
      initializerList(0);
      setState(250);
      match(MiniDecafParser::Comma);
      setState(251);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 4: {
      setState(253);
      match(MiniDecafParser::T__0);
      setState(254);
      match(MiniDecafParser::LeftParen);
      setState(255);
      typeName();
      setState(256);
      match(MiniDecafParser::RightParen);
      setState(257);
      match(MiniDecafParser::LeftBrace);
      setState(258);
      initializerList(0);
      setState(259);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 5: {
      setState(261);
      match(MiniDecafParser::T__0);
      setState(262);
      match(MiniDecafParser::LeftParen);
      setState(263);
      typeName();
      setState(264);
      match(MiniDecafParser::RightParen);
      setState(265);
      match(MiniDecafParser::LeftBrace);
      setState(266);
      initializerList(0);
      setState(267);
      match(MiniDecafParser::Comma);
      setState(268);
      match(MiniDecafParser::RightBrace);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(295);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(293);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(272);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(273);
          match(MiniDecafParser::LeftBracket);
          setState(274);
          expression(0);
          setState(275);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(277);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(278);
          match(MiniDecafParser::LeftParen);
          setState(280);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
            | (1ULL << MiniDecafParser::T__1)
            | (1ULL << MiniDecafParser::T__2)
            | (1ULL << MiniDecafParser::Sizeof)
            | (1ULL << MiniDecafParser::Alignof)
            | (1ULL << MiniDecafParser::Generic)
            | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
            | (1ULL << (MiniDecafParser::PlusPlus - 71))
            | (1ULL << (MiniDecafParser::Minus - 71))
            | (1ULL << (MiniDecafParser::MinusMinus - 71))
            | (1ULL << (MiniDecafParser::Star - 71))
            | (1ULL << (MiniDecafParser::And - 71))
            | (1ULL << (MiniDecafParser::AndAnd - 71))
            | (1ULL << (MiniDecafParser::Not - 71))
            | (1ULL << (MiniDecafParser::Tilde - 71))
            | (1ULL << (MiniDecafParser::Identifier - 71))
            | (1ULL << (MiniDecafParser::Constant - 71))
            | (1ULL << (MiniDecafParser::DigitSequence - 71))
            | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
            setState(279);
            argumentExpressionList(0);
          }
          setState(282);
          match(MiniDecafParser::RightParen);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(283);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(284);
          match(MiniDecafParser::Dot);
          setState(285);
          match(MiniDecafParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(286);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(287);
          match(MiniDecafParser::Arrow);
          setState(288);
          match(MiniDecafParser::Identifier);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(289);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(290);
          match(MiniDecafParser::PlusPlus);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(291);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(292);
          match(MiniDecafParser::MinusMinus);
          break;
        }

        } 
      }
      setState(297);
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

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

MiniDecafParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

MiniDecafParser::ArgumentExpressionListContext* MiniDecafParser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<MiniDecafParser::ArgumentExpressionListContext>(0);
}

tree::TerminalNode* MiniDecafParser::ArgumentExpressionListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::ArgumentExpressionListContext::getRuleIndex() const {
  return MiniDecafParser::RuleArgumentExpressionList;
}


antlrcpp::Any MiniDecafParser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ArgumentExpressionListContext* MiniDecafParser::argumentExpressionList() {
   return argumentExpressionList(0);
}

MiniDecafParser::ArgumentExpressionListContext* MiniDecafParser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  MiniDecafParser::ArgumentExpressionListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, MiniDecafParser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(299);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(306);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(301);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(302);
        match(MiniDecafParser::Comma);
        setState(303);
        assignmentExpression(); 
      }
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

MiniDecafParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::PostfixExpressionContext* MiniDecafParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<MiniDecafParser::PostfixExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::PlusPlus() {
  return getToken(MiniDecafParser::PlusPlus, 0);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<MiniDecafParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::MinusMinus() {
  return getToken(MiniDecafParser::MinusMinus, 0);
}

MiniDecafParser::UnaryOperatorContext* MiniDecafParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<MiniDecafParser::UnaryOperatorContext>(0);
}

MiniDecafParser::CastExpressionContext* MiniDecafParser::UnaryExpressionContext::castExpression() {
  return getRuleContext<MiniDecafParser::CastExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::Sizeof() {
  return getToken(MiniDecafParser::Sizeof, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::UnaryExpressionContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::Alignof() {
  return getToken(MiniDecafParser::Alignof, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::AndAnd() {
  return getToken(MiniDecafParser::AndAnd, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryExpressionContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}


size_t MiniDecafParser::UnaryExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleUnaryExpression;
}


antlrcpp::Any MiniDecafParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniDecafParser::RuleUnaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(331);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(309);
      postfixExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(310);
      match(MiniDecafParser::PlusPlus);
      setState(311);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(312);
      match(MiniDecafParser::MinusMinus);
      setState(313);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(314);
      unaryOperator();
      setState(315);
      castExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(317);
      match(MiniDecafParser::Sizeof);
      setState(318);
      unaryExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(319);
      match(MiniDecafParser::Sizeof);
      setState(320);
      match(MiniDecafParser::LeftParen);
      setState(321);
      typeName();
      setState(322);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(324);
      match(MiniDecafParser::Alignof);
      setState(325);
      match(MiniDecafParser::LeftParen);
      setState(326);
      typeName();
      setState(327);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(329);
      match(MiniDecafParser::AndAnd);
      setState(330);
      match(MiniDecafParser::Identifier);
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

//----------------- UnaryOperatorContext ------------------------------------------------------------------

MiniDecafParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::And() {
  return getToken(MiniDecafParser::And, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::Star() {
  return getToken(MiniDecafParser::Star, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::Plus() {
  return getToken(MiniDecafParser::Plus, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::Minus() {
  return getToken(MiniDecafParser::Minus, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::Tilde() {
  return getToken(MiniDecafParser::Tilde, 0);
}

tree::TerminalNode* MiniDecafParser::UnaryOperatorContext::Not() {
  return getToken(MiniDecafParser::Not, 0);
}


size_t MiniDecafParser::UnaryOperatorContext::getRuleIndex() const {
  return MiniDecafParser::RuleUnaryOperator;
}


antlrcpp::Any MiniDecafParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::UnaryOperatorContext* MiniDecafParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniDecafParser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    _la = _input->LA(1);
    if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
      | (1ULL << (MiniDecafParser::Minus - 71))
      | (1ULL << (MiniDecafParser::Star - 71))
      | (1ULL << (MiniDecafParser::And - 71))
      | (1ULL << (MiniDecafParser::Not - 71))
      | (1ULL << (MiniDecafParser::Tilde - 71)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExpressionContext ------------------------------------------------------------------

MiniDecafParser::CastExpressionContext::CastExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::CastExpressionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::CastExpressionContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::CastExpressionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

MiniDecafParser::CastExpressionContext* MiniDecafParser::CastExpressionContext::castExpression() {
  return getRuleContext<MiniDecafParser::CastExpressionContext>(0);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<MiniDecafParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::CastExpressionContext::DigitSequence() {
  return getToken(MiniDecafParser::DigitSequence, 0);
}


size_t MiniDecafParser::CastExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleCastExpression;
}


antlrcpp::Any MiniDecafParser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::CastExpressionContext* MiniDecafParser::castExpression() {
  CastExpressionContext *_localctx = _tracker.createInstance<CastExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniDecafParser::RuleCastExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(335);
      match(MiniDecafParser::LeftParen);
      setState(336);
      typeName();
      setState(337);
      match(MiniDecafParser::RightParen);
      setState(338);
      castExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(340);
      match(MiniDecafParser::T__0);
      setState(341);
      match(MiniDecafParser::LeftParen);
      setState(342);
      typeName();
      setState(343);
      match(MiniDecafParser::RightParen);
      setState(344);
      castExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(346);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(347);
      match(MiniDecafParser::DigitSequence);
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

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

MiniDecafParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::CastExpressionContext* MiniDecafParser::MultiplicativeExpressionContext::castExpression() {
  return getRuleContext<MiniDecafParser::CastExpressionContext>(0);
}

MiniDecafParser::MultiplicativeExpressionContext* MiniDecafParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<MiniDecafParser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::MultiplicativeExpressionContext::Star() {
  return getToken(MiniDecafParser::Star, 0);
}

tree::TerminalNode* MiniDecafParser::MultiplicativeExpressionContext::Div() {
  return getToken(MiniDecafParser::Div, 0);
}

tree::TerminalNode* MiniDecafParser::MultiplicativeExpressionContext::Mod() {
  return getToken(MiniDecafParser::Mod, 0);
}


size_t MiniDecafParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleMultiplicativeExpression;
}


antlrcpp::Any MiniDecafParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::MultiplicativeExpressionContext* MiniDecafParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

MiniDecafParser::MultiplicativeExpressionContext* MiniDecafParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  MiniDecafParser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, MiniDecafParser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(351);
    castExpression();
    _ctx->stop = _input->LT(-1);
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(362);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(353);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(354);
          match(MiniDecafParser::Star);
          setState(355);
          castExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(356);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(357);
          match(MiniDecafParser::Div);
          setState(358);
          castExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(359);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(360);
          match(MiniDecafParser::Mod);
          setState(361);
          castExpression();
          break;
        }

        } 
      }
      setState(366);
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

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

MiniDecafParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::MultiplicativeExpressionContext* MiniDecafParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<MiniDecafParser::MultiplicativeExpressionContext>(0);
}

MiniDecafParser::AdditiveExpressionContext* MiniDecafParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<MiniDecafParser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::AdditiveExpressionContext::Plus() {
  return getToken(MiniDecafParser::Plus, 0);
}

tree::TerminalNode* MiniDecafParser::AdditiveExpressionContext::Minus() {
  return getToken(MiniDecafParser::Minus, 0);
}


size_t MiniDecafParser::AdditiveExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleAdditiveExpression;
}


antlrcpp::Any MiniDecafParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::AdditiveExpressionContext* MiniDecafParser::additiveExpression() {
   return additiveExpression(0);
}

MiniDecafParser::AdditiveExpressionContext* MiniDecafParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  MiniDecafParser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, MiniDecafParser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(368);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(378);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(376);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(370);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(371);
          match(MiniDecafParser::Plus);
          setState(372);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(373);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(374);
          match(MiniDecafParser::Minus);
          setState(375);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(380);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftExpressionContext ------------------------------------------------------------------

MiniDecafParser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AdditiveExpressionContext* MiniDecafParser::ShiftExpressionContext::additiveExpression() {
  return getRuleContext<MiniDecafParser::AdditiveExpressionContext>(0);
}

MiniDecafParser::ShiftExpressionContext* MiniDecafParser::ShiftExpressionContext::shiftExpression() {
  return getRuleContext<MiniDecafParser::ShiftExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ShiftExpressionContext::LeftShift() {
  return getToken(MiniDecafParser::LeftShift, 0);
}

tree::TerminalNode* MiniDecafParser::ShiftExpressionContext::RightShift() {
  return getToken(MiniDecafParser::RightShift, 0);
}


size_t MiniDecafParser::ShiftExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleShiftExpression;
}


antlrcpp::Any MiniDecafParser::ShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ShiftExpressionContext* MiniDecafParser::shiftExpression() {
   return shiftExpression(0);
}

MiniDecafParser::ShiftExpressionContext* MiniDecafParser::shiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, parentState);
  MiniDecafParser::ShiftExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, MiniDecafParser::RuleShiftExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(382);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(392);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(390);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(384);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(385);
          match(MiniDecafParser::LeftShift);
          setState(386);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(387);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(388);
          match(MiniDecafParser::RightShift);
          setState(389);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(394);
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

//----------------- RelationalExpressionContext ------------------------------------------------------------------

MiniDecafParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ShiftExpressionContext* MiniDecafParser::RelationalExpressionContext::shiftExpression() {
  return getRuleContext<MiniDecafParser::ShiftExpressionContext>(0);
}

MiniDecafParser::RelationalExpressionContext* MiniDecafParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<MiniDecafParser::RelationalExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::RelationalExpressionContext::Less() {
  return getToken(MiniDecafParser::Less, 0);
}

tree::TerminalNode* MiniDecafParser::RelationalExpressionContext::Greater() {
  return getToken(MiniDecafParser::Greater, 0);
}

tree::TerminalNode* MiniDecafParser::RelationalExpressionContext::LessEqual() {
  return getToken(MiniDecafParser::LessEqual, 0);
}

tree::TerminalNode* MiniDecafParser::RelationalExpressionContext::GreaterEqual() {
  return getToken(MiniDecafParser::GreaterEqual, 0);
}


size_t MiniDecafParser::RelationalExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleRelationalExpression;
}


antlrcpp::Any MiniDecafParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::RelationalExpressionContext* MiniDecafParser::relationalExpression() {
   return relationalExpression(0);
}

MiniDecafParser::RelationalExpressionContext* MiniDecafParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  MiniDecafParser::RelationalExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MiniDecafParser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(396);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(412);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(410);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(398);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(399);
          match(MiniDecafParser::Less);
          setState(400);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(401);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(402);
          match(MiniDecafParser::Greater);
          setState(403);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(404);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(405);
          match(MiniDecafParser::LessEqual);
          setState(406);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(407);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(408);
          match(MiniDecafParser::GreaterEqual);
          setState(409);
          shiftExpression(0);
          break;
        }

        } 
      }
      setState(414);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

MiniDecafParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::RelationalExpressionContext* MiniDecafParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<MiniDecafParser::RelationalExpressionContext>(0);
}

MiniDecafParser::EqualityExpressionContext* MiniDecafParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<MiniDecafParser::EqualityExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::EqualityExpressionContext::Equal() {
  return getToken(MiniDecafParser::Equal, 0);
}

tree::TerminalNode* MiniDecafParser::EqualityExpressionContext::NotEqual() {
  return getToken(MiniDecafParser::NotEqual, 0);
}


size_t MiniDecafParser::EqualityExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleEqualityExpression;
}


antlrcpp::Any MiniDecafParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::EqualityExpressionContext* MiniDecafParser::equalityExpression() {
   return equalityExpression(0);
}

MiniDecafParser::EqualityExpressionContext* MiniDecafParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  MiniDecafParser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MiniDecafParser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(416);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(426);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(424);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(418);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(419);
          match(MiniDecafParser::Equal);
          setState(420);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(421);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(422);
          match(MiniDecafParser::NotEqual);
          setState(423);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(428);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

MiniDecafParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::EqualityExpressionContext* MiniDecafParser::AndExpressionContext::equalityExpression() {
  return getRuleContext<MiniDecafParser::EqualityExpressionContext>(0);
}

MiniDecafParser::AndExpressionContext* MiniDecafParser::AndExpressionContext::andExpression() {
  return getRuleContext<MiniDecafParser::AndExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::AndExpressionContext::And() {
  return getToken(MiniDecafParser::And, 0);
}


size_t MiniDecafParser::AndExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleAndExpression;
}


antlrcpp::Any MiniDecafParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::AndExpressionContext* MiniDecafParser::andExpression() {
   return andExpression(0);
}

MiniDecafParser::AndExpressionContext* MiniDecafParser::andExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, parentState);
  MiniDecafParser::AndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, MiniDecafParser::RuleAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(430);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(437);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(432);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(433);
        match(MiniDecafParser::And);
        setState(434);
        equalityExpression(0); 
      }
      setState(439);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

MiniDecafParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AndExpressionContext* MiniDecafParser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContext<MiniDecafParser::AndExpressionContext>(0);
}

MiniDecafParser::ExclusiveOrExpressionContext* MiniDecafParser::ExclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<MiniDecafParser::ExclusiveOrExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ExclusiveOrExpressionContext::Caret() {
  return getToken(MiniDecafParser::Caret, 0);
}


size_t MiniDecafParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleExclusiveOrExpression;
}


antlrcpp::Any MiniDecafParser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ExclusiveOrExpressionContext* MiniDecafParser::exclusiveOrExpression() {
   return exclusiveOrExpression(0);
}

MiniDecafParser::ExclusiveOrExpressionContext* MiniDecafParser::exclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, parentState);
  MiniDecafParser::ExclusiveOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, MiniDecafParser::RuleExclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(441);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(448);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(443);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(444);
        match(MiniDecafParser::Caret);
        setState(445);
        andExpression(0); 
      }
      setState(450);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InclusiveOrExpressionContext ------------------------------------------------------------------

MiniDecafParser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ExclusiveOrExpressionContext* MiniDecafParser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<MiniDecafParser::ExclusiveOrExpressionContext>(0);
}

MiniDecafParser::InclusiveOrExpressionContext* MiniDecafParser::InclusiveOrExpressionContext::inclusiveOrExpression() {
  return getRuleContext<MiniDecafParser::InclusiveOrExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::InclusiveOrExpressionContext::Or() {
  return getToken(MiniDecafParser::Or, 0);
}


size_t MiniDecafParser::InclusiveOrExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleInclusiveOrExpression;
}


antlrcpp::Any MiniDecafParser::InclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitInclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::InclusiveOrExpressionContext* MiniDecafParser::inclusiveOrExpression() {
   return inclusiveOrExpression(0);
}

MiniDecafParser::InclusiveOrExpressionContext* MiniDecafParser::inclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, parentState);
  MiniDecafParser::InclusiveOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, MiniDecafParser::RuleInclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(452);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(459);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(454);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(455);
        match(MiniDecafParser::Or);
        setState(456);
        exclusiveOrExpression(0); 
      }
      setState(461);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

MiniDecafParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::InclusiveOrExpressionContext* MiniDecafParser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContext<MiniDecafParser::InclusiveOrExpressionContext>(0);
}

MiniDecafParser::LogicalAndExpressionContext* MiniDecafParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<MiniDecafParser::LogicalAndExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::LogicalAndExpressionContext::AndAnd() {
  return getToken(MiniDecafParser::AndAnd, 0);
}


size_t MiniDecafParser::LogicalAndExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleLogicalAndExpression;
}


antlrcpp::Any MiniDecafParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::LogicalAndExpressionContext* MiniDecafParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

MiniDecafParser::LogicalAndExpressionContext* MiniDecafParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  MiniDecafParser::LogicalAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MiniDecafParser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(463);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(470);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(465);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(466);
        match(MiniDecafParser::AndAnd);
        setState(467);
        inclusiveOrExpression(0); 
      }
      setState(472);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

MiniDecafParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::LogicalAndExpressionContext* MiniDecafParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<MiniDecafParser::LogicalAndExpressionContext>(0);
}

MiniDecafParser::LogicalOrExpressionContext* MiniDecafParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<MiniDecafParser::LogicalOrExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::LogicalOrExpressionContext::OrOr() {
  return getToken(MiniDecafParser::OrOr, 0);
}


size_t MiniDecafParser::LogicalOrExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleLogicalOrExpression;
}


antlrcpp::Any MiniDecafParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::LogicalOrExpressionContext* MiniDecafParser::logicalOrExpression() {
   return logicalOrExpression(0);
}

MiniDecafParser::LogicalOrExpressionContext* MiniDecafParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  MiniDecafParser::LogicalOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, MiniDecafParser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(474);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(481);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(476);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(477);
        match(MiniDecafParser::OrOr);
        setState(478);
        logicalAndExpression(0); 
      }
      setState(483);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

MiniDecafParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::LogicalOrExpressionContext* MiniDecafParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<MiniDecafParser::LogicalOrExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ConditionalExpressionContext::Question() {
  return getToken(MiniDecafParser::Question, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::ConditionalExpressionContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ConditionalExpressionContext::Colon() {
  return getToken(MiniDecafParser::Colon, 0);
}

MiniDecafParser::ConditionalExpressionContext* MiniDecafParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<MiniDecafParser::ConditionalExpressionContext>(0);
}


size_t MiniDecafParser::ConditionalExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleConditionalExpression;
}


antlrcpp::Any MiniDecafParser::ConditionalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitConditionalExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ConditionalExpressionContext* MiniDecafParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniDecafParser::RuleConditionalExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    logicalOrExpression(0);
    setState(490);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(485);
      match(MiniDecafParser::Question);
      setState(486);
      expression(0);
      setState(487);
      match(MiniDecafParser::Colon);
      setState(488);
      conditionalExpression();
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

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

MiniDecafParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ConditionalExpressionContext* MiniDecafParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<MiniDecafParser::ConditionalExpressionContext>(0);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<MiniDecafParser::UnaryExpressionContext>(0);
}

MiniDecafParser::AssignmentOperatorContext* MiniDecafParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<MiniDecafParser::AssignmentOperatorContext>(0);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(MiniDecafParser::DigitSequence, 0);
}


size_t MiniDecafParser::AssignmentExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleAssignmentExpression;
}


antlrcpp::Any MiniDecafParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniDecafParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(498);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(492);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(493);
      unaryExpression();
      setState(494);
      assignmentOperator();
      setState(495);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(497);
      match(MiniDecafParser::DigitSequence);
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

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

MiniDecafParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::Assign() {
  return getToken(MiniDecafParser::Assign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::StarAssign() {
  return getToken(MiniDecafParser::StarAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::DivAssign() {
  return getToken(MiniDecafParser::DivAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::ModAssign() {
  return getToken(MiniDecafParser::ModAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(MiniDecafParser::PlusAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(MiniDecafParser::MinusAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::LeftShiftAssign() {
  return getToken(MiniDecafParser::LeftShiftAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::RightShiftAssign() {
  return getToken(MiniDecafParser::RightShiftAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::AndAssign() {
  return getToken(MiniDecafParser::AndAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::XorAssign() {
  return getToken(MiniDecafParser::XorAssign, 0);
}

tree::TerminalNode* MiniDecafParser::AssignmentOperatorContext::OrAssign() {
  return getToken(MiniDecafParser::OrAssign, 0);
}


size_t MiniDecafParser::AssignmentOperatorContext::getRuleIndex() const {
  return MiniDecafParser::RuleAssignmentOperator;
}


antlrcpp::Any MiniDecafParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::AssignmentOperatorContext* MiniDecafParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 42, MiniDecafParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(500);
    _la = _input->LA(1);
    if (!(((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (MiniDecafParser::Assign - 89))
      | (1ULL << (MiniDecafParser::StarAssign - 89))
      | (1ULL << (MiniDecafParser::DivAssign - 89))
      | (1ULL << (MiniDecafParser::ModAssign - 89))
      | (1ULL << (MiniDecafParser::PlusAssign - 89))
      | (1ULL << (MiniDecafParser::MinusAssign - 89))
      | (1ULL << (MiniDecafParser::LeftShiftAssign - 89))
      | (1ULL << (MiniDecafParser::RightShiftAssign - 89))
      | (1ULL << (MiniDecafParser::AndAssign - 89))
      | (1ULL << (MiniDecafParser::XorAssign - 89))
      | (1ULL << (MiniDecafParser::OrAssign - 89)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MiniDecafParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::ExpressionContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ExpressionContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::ExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleExpression;
}


antlrcpp::Any MiniDecafParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ExpressionContext* MiniDecafParser::expression() {
   return expression(0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MiniDecafParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, MiniDecafParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(503);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(510);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(505);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(506);
        match(MiniDecafParser::Comma);
        setState(507);
        assignmentExpression(); 
      }
      setState(512);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

MiniDecafParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ConditionalExpressionContext* MiniDecafParser::ConstantExpressionContext::conditionalExpression() {
  return getRuleContext<MiniDecafParser::ConditionalExpressionContext>(0);
}


size_t MiniDecafParser::ConstantExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleConstantExpression;
}


antlrcpp::Any MiniDecafParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, MiniDecafParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    conditionalExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

MiniDecafParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclarationSpecifiersContext* MiniDecafParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<MiniDecafParser::DeclarationSpecifiersContext>(0);
}

MiniDecafParser::InitDeclaratorListContext* MiniDecafParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<MiniDecafParser::InitDeclaratorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::DeclarationContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

MiniDecafParser::StaticAssertDeclarationContext* MiniDecafParser::DeclarationContext::staticAssertDeclaration() {
  return getRuleContext<MiniDecafParser::StaticAssertDeclarationContext>(0);
}


size_t MiniDecafParser::DeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleDeclaration;
}


antlrcpp::Any MiniDecafParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DeclarationContext* MiniDecafParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, MiniDecafParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(523);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(515);
      declarationSpecifiers();
      setState(516);
      initDeclaratorList(0);
      setState(517);
      match(MiniDecafParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(519);
      declarationSpecifiers();
      setState(520);
      match(MiniDecafParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(522);
      staticAssertDeclaration();
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

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

MiniDecafParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniDecafParser::DeclarationSpecifierContext *> MiniDecafParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<MiniDecafParser::DeclarationSpecifierContext>();
}

MiniDecafParser::DeclarationSpecifierContext* MiniDecafParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<MiniDecafParser::DeclarationSpecifierContext>(i);
}


size_t MiniDecafParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return MiniDecafParser::RuleDeclarationSpecifiers;
}


antlrcpp::Any MiniDecafParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DeclarationSpecifiersContext* MiniDecafParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 50, MiniDecafParser::RuleDeclarationSpecifiers);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(526); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(525);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(528); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiers2Context ------------------------------------------------------------------

MiniDecafParser::DeclarationSpecifiers2Context::DeclarationSpecifiers2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniDecafParser::DeclarationSpecifierContext *> MiniDecafParser::DeclarationSpecifiers2Context::declarationSpecifier() {
  return getRuleContexts<MiniDecafParser::DeclarationSpecifierContext>();
}

MiniDecafParser::DeclarationSpecifierContext* MiniDecafParser::DeclarationSpecifiers2Context::declarationSpecifier(size_t i) {
  return getRuleContext<MiniDecafParser::DeclarationSpecifierContext>(i);
}


size_t MiniDecafParser::DeclarationSpecifiers2Context::getRuleIndex() const {
  return MiniDecafParser::RuleDeclarationSpecifiers2;
}


antlrcpp::Any MiniDecafParser::DeclarationSpecifiers2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers2(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DeclarationSpecifiers2Context* MiniDecafParser::declarationSpecifiers2() {
  DeclarationSpecifiers2Context *_localctx = _tracker.createInstance<DeclarationSpecifiers2Context>(_ctx, getState());
  enterRule(_localctx, 52, MiniDecafParser::RuleDeclarationSpecifiers2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(531); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(530);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(533); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

MiniDecafParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::StorageClassSpecifierContext* MiniDecafParser::DeclarationSpecifierContext::storageClassSpecifier() {
  return getRuleContext<MiniDecafParser::StorageClassSpecifierContext>(0);
}

MiniDecafParser::TypeSpecifierContext* MiniDecafParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<MiniDecafParser::TypeSpecifierContext>(0);
}

MiniDecafParser::TypeQualifierContext* MiniDecafParser::DeclarationSpecifierContext::typeQualifier() {
  return getRuleContext<MiniDecafParser::TypeQualifierContext>(0);
}

MiniDecafParser::FunctionSpecifierContext* MiniDecafParser::DeclarationSpecifierContext::functionSpecifier() {
  return getRuleContext<MiniDecafParser::FunctionSpecifierContext>(0);
}

MiniDecafParser::AlignmentSpecifierContext* MiniDecafParser::DeclarationSpecifierContext::alignmentSpecifier() {
  return getRuleContext<MiniDecafParser::AlignmentSpecifierContext>(0);
}


size_t MiniDecafParser::DeclarationSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleDeclarationSpecifier;
}


antlrcpp::Any MiniDecafParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DeclarationSpecifierContext* MiniDecafParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 54, MiniDecafParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(535);
      storageClassSpecifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(536);
      typeSpecifier(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(537);
      typeQualifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(538);
      functionSpecifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(539);
      alignmentSpecifier();
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

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

MiniDecafParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::InitDeclaratorContext* MiniDecafParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContext<MiniDecafParser::InitDeclaratorContext>(0);
}

MiniDecafParser::InitDeclaratorListContext* MiniDecafParser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<MiniDecafParser::InitDeclaratorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::InitDeclaratorListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::InitDeclaratorListContext::getRuleIndex() const {
  return MiniDecafParser::RuleInitDeclaratorList;
}


antlrcpp::Any MiniDecafParser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::InitDeclaratorListContext* MiniDecafParser::initDeclaratorList() {
   return initDeclaratorList(0);
}

MiniDecafParser::InitDeclaratorListContext* MiniDecafParser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  MiniDecafParser::InitDeclaratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, MiniDecafParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(543);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(550);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(545);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(546);
        match(MiniDecafParser::Comma);
        setState(547);
        initDeclarator(); 
      }
      setState(552);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

MiniDecafParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::InitDeclaratorContext::declarator() {
  return getRuleContext<MiniDecafParser::DeclaratorContext>(0);
}

tree::TerminalNode* MiniDecafParser::InitDeclaratorContext::Assign() {
  return getToken(MiniDecafParser::Assign, 0);
}

MiniDecafParser::InitializerContext* MiniDecafParser::InitDeclaratorContext::initializer() {
  return getRuleContext<MiniDecafParser::InitializerContext>(0);
}


size_t MiniDecafParser::InitDeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleInitDeclarator;
}


antlrcpp::Any MiniDecafParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::InitDeclaratorContext* MiniDecafParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 58, MiniDecafParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(558);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(553);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(554);
      declarator();
      setState(555);
      match(MiniDecafParser::Assign);
      setState(556);
      initializer();
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

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

MiniDecafParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::Typedef() {
  return getToken(MiniDecafParser::Typedef, 0);
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::Extern() {
  return getToken(MiniDecafParser::Extern, 0);
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::Static() {
  return getToken(MiniDecafParser::Static, 0);
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::ThreadLocal() {
  return getToken(MiniDecafParser::ThreadLocal, 0);
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::Auto() {
  return getToken(MiniDecafParser::Auto, 0);
}

tree::TerminalNode* MiniDecafParser::StorageClassSpecifierContext::Register() {
  return getToken(MiniDecafParser::Register, 0);
}


size_t MiniDecafParser::StorageClassSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleStorageClassSpecifier;
}


antlrcpp::Any MiniDecafParser::StorageClassSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStorageClassSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StorageClassSpecifierContext* MiniDecafParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 60, MiniDecafParser::RuleStorageClassSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::Auto)
      | (1ULL << MiniDecafParser::Extern)
      | (1ULL << MiniDecafParser::Register)
      | (1ULL << MiniDecafParser::Static)
      | (1ULL << MiniDecafParser::Typedef)
      | (1ULL << MiniDecafParser::ThreadLocal))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

MiniDecafParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Void() {
  return getToken(MiniDecafParser::Void, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Char() {
  return getToken(MiniDecafParser::Char, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Short() {
  return getToken(MiniDecafParser::Short, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Int() {
  return getToken(MiniDecafParser::Int, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Long() {
  return getToken(MiniDecafParser::Long, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Float() {
  return getToken(MiniDecafParser::Float, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Double() {
  return getToken(MiniDecafParser::Double, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Signed() {
  return getToken(MiniDecafParser::Signed, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Unsigned() {
  return getToken(MiniDecafParser::Unsigned, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Bool() {
  return getToken(MiniDecafParser::Bool, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::Complex() {
  return getToken(MiniDecafParser::Complex, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

tree::TerminalNode* MiniDecafParser::TypeSpecifierContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

MiniDecafParser::AtomicTypeSpecifierContext* MiniDecafParser::TypeSpecifierContext::atomicTypeSpecifier() {
  return getRuleContext<MiniDecafParser::AtomicTypeSpecifierContext>(0);
}

MiniDecafParser::StructOrUnionSpecifierContext* MiniDecafParser::TypeSpecifierContext::structOrUnionSpecifier() {
  return getRuleContext<MiniDecafParser::StructOrUnionSpecifierContext>(0);
}

MiniDecafParser::EnumSpecifierContext* MiniDecafParser::TypeSpecifierContext::enumSpecifier() {
  return getRuleContext<MiniDecafParser::EnumSpecifierContext>(0);
}

MiniDecafParser::TypedefNameContext* MiniDecafParser::TypeSpecifierContext::typedefName() {
  return getRuleContext<MiniDecafParser::TypedefNameContext>(0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::TypeSpecifierContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}

MiniDecafParser::TypeSpecifierContext* MiniDecafParser::TypeSpecifierContext::typeSpecifier() {
  return getRuleContext<MiniDecafParser::TypeSpecifierContext>(0);
}

MiniDecafParser::PointerContext* MiniDecafParser::TypeSpecifierContext::pointer() {
  return getRuleContext<MiniDecafParser::PointerContext>(0);
}


size_t MiniDecafParser::TypeSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleTypeSpecifier;
}


antlrcpp::Any MiniDecafParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::TypeSpecifierContext* MiniDecafParser::typeSpecifier() {
   return typeSpecifier(0);
}

MiniDecafParser::TypeSpecifierContext* MiniDecafParser::typeSpecifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, parentState);
  MiniDecafParser::TypeSpecifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, MiniDecafParser::RuleTypeSpecifier, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(577);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__3:
      case MiniDecafParser::T__4:
      case MiniDecafParser::T__5:
      case MiniDecafParser::Char:
      case MiniDecafParser::Double:
      case MiniDecafParser::Float:
      case MiniDecafParser::Int:
      case MiniDecafParser::Long:
      case MiniDecafParser::Short:
      case MiniDecafParser::Signed:
      case MiniDecafParser::Unsigned:
      case MiniDecafParser::Void:
      case MiniDecafParser::Bool:
      case MiniDecafParser::Complex: {
        setState(563);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::T__3)
          | (1ULL << MiniDecafParser::T__4)
          | (1ULL << MiniDecafParser::T__5)
          | (1ULL << MiniDecafParser::Char)
          | (1ULL << MiniDecafParser::Double)
          | (1ULL << MiniDecafParser::Float)
          | (1ULL << MiniDecafParser::Int)
          | (1ULL << MiniDecafParser::Long)
          | (1ULL << MiniDecafParser::Short)
          | (1ULL << MiniDecafParser::Signed)
          | (1ULL << MiniDecafParser::Unsigned)
          | (1ULL << MiniDecafParser::Void)
          | (1ULL << MiniDecafParser::Bool)
          | (1ULL << MiniDecafParser::Complex))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case MiniDecafParser::T__0: {
        setState(564);
        match(MiniDecafParser::T__0);
        setState(565);
        match(MiniDecafParser::LeftParen);
        setState(566);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::T__3)
          | (1ULL << MiniDecafParser::T__4)
          | (1ULL << MiniDecafParser::T__5))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(567);
        match(MiniDecafParser::RightParen);
        break;
      }

      case MiniDecafParser::Atomic: {
        setState(568);
        atomicTypeSpecifier();
        break;
      }

      case MiniDecafParser::Struct:
      case MiniDecafParser::Union: {
        setState(569);
        structOrUnionSpecifier();
        break;
      }

      case MiniDecafParser::Enum: {
        setState(570);
        enumSpecifier();
        break;
      }

      case MiniDecafParser::Identifier: {
        setState(571);
        typedefName();
        break;
      }

      case MiniDecafParser::T__6: {
        setState(572);
        match(MiniDecafParser::T__6);
        setState(573);
        match(MiniDecafParser::LeftParen);
        setState(574);
        constantExpression();
        setState(575);
        match(MiniDecafParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(583);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeSpecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeSpecifier);
        setState(579);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(580);
        pointer(); 
      }
      setState(585);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructOrUnionSpecifierContext ------------------------------------------------------------------

MiniDecafParser::StructOrUnionSpecifierContext::StructOrUnionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::StructOrUnionContext* MiniDecafParser::StructOrUnionSpecifierContext::structOrUnion() {
  return getRuleContext<MiniDecafParser::StructOrUnionContext>(0);
}

tree::TerminalNode* MiniDecafParser::StructOrUnionSpecifierContext::LeftBrace() {
  return getToken(MiniDecafParser::LeftBrace, 0);
}

MiniDecafParser::StructDeclarationListContext* MiniDecafParser::StructOrUnionSpecifierContext::structDeclarationList() {
  return getRuleContext<MiniDecafParser::StructDeclarationListContext>(0);
}

tree::TerminalNode* MiniDecafParser::StructOrUnionSpecifierContext::RightBrace() {
  return getToken(MiniDecafParser::RightBrace, 0);
}

tree::TerminalNode* MiniDecafParser::StructOrUnionSpecifierContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}


size_t MiniDecafParser::StructOrUnionSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructOrUnionSpecifier;
}


antlrcpp::Any MiniDecafParser::StructOrUnionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructOrUnionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StructOrUnionSpecifierContext* MiniDecafParser::structOrUnionSpecifier() {
  StructOrUnionSpecifierContext *_localctx = _tracker.createInstance<StructOrUnionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 64, MiniDecafParser::RuleStructOrUnionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(597);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(586);
      structOrUnion();
      setState(588);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::Identifier) {
        setState(587);
        match(MiniDecafParser::Identifier);
      }
      setState(590);
      match(MiniDecafParser::LeftBrace);
      setState(591);
      structDeclarationList(0);
      setState(592);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(594);
      structOrUnion();
      setState(595);
      match(MiniDecafParser::Identifier);
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

//----------------- StructOrUnionContext ------------------------------------------------------------------

MiniDecafParser::StructOrUnionContext::StructOrUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::StructOrUnionContext::Struct() {
  return getToken(MiniDecafParser::Struct, 0);
}

tree::TerminalNode* MiniDecafParser::StructOrUnionContext::Union() {
  return getToken(MiniDecafParser::Union, 0);
}


size_t MiniDecafParser::StructOrUnionContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructOrUnion;
}


antlrcpp::Any MiniDecafParser::StructOrUnionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructOrUnion(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StructOrUnionContext* MiniDecafParser::structOrUnion() {
  StructOrUnionContext *_localctx = _tracker.createInstance<StructOrUnionContext>(_ctx, getState());
  enterRule(_localctx, 66, MiniDecafParser::RuleStructOrUnion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    _la = _input->LA(1);
    if (!(_la == MiniDecafParser::Struct

    || _la == MiniDecafParser::Union)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationListContext ------------------------------------------------------------------

MiniDecafParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::StructDeclarationContext* MiniDecafParser::StructDeclarationListContext::structDeclaration() {
  return getRuleContext<MiniDecafParser::StructDeclarationContext>(0);
}

MiniDecafParser::StructDeclarationListContext* MiniDecafParser::StructDeclarationListContext::structDeclarationList() {
  return getRuleContext<MiniDecafParser::StructDeclarationListContext>(0);
}


size_t MiniDecafParser::StructDeclarationListContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructDeclarationList;
}


antlrcpp::Any MiniDecafParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::StructDeclarationListContext* MiniDecafParser::structDeclarationList() {
   return structDeclarationList(0);
}

MiniDecafParser::StructDeclarationListContext* MiniDecafParser::structDeclarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, parentState);
  MiniDecafParser::StructDeclarationListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, MiniDecafParser::RuleStructDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(602);
    structDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(608);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclarationList);
        setState(604);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(605);
        structDeclaration(); 
      }
      setState(610);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

MiniDecafParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::SpecifierQualifierListContext* MiniDecafParser::StructDeclarationContext::specifierQualifierList() {
  return getRuleContext<MiniDecafParser::SpecifierQualifierListContext>(0);
}

tree::TerminalNode* MiniDecafParser::StructDeclarationContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

MiniDecafParser::StructDeclaratorListContext* MiniDecafParser::StructDeclarationContext::structDeclaratorList() {
  return getRuleContext<MiniDecafParser::StructDeclaratorListContext>(0);
}

MiniDecafParser::StaticAssertDeclarationContext* MiniDecafParser::StructDeclarationContext::staticAssertDeclaration() {
  return getRuleContext<MiniDecafParser::StaticAssertDeclarationContext>(0);
}


size_t MiniDecafParser::StructDeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructDeclaration;
}


antlrcpp::Any MiniDecafParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StructDeclarationContext* MiniDecafParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 70, MiniDecafParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(618);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__0:
      case MiniDecafParser::T__3:
      case MiniDecafParser::T__4:
      case MiniDecafParser::T__5:
      case MiniDecafParser::T__6:
      case MiniDecafParser::Char:
      case MiniDecafParser::Const:
      case MiniDecafParser::Double:
      case MiniDecafParser::Enum:
      case MiniDecafParser::Float:
      case MiniDecafParser::Int:
      case MiniDecafParser::Long:
      case MiniDecafParser::Restrict:
      case MiniDecafParser::Short:
      case MiniDecafParser::Signed:
      case MiniDecafParser::Struct:
      case MiniDecafParser::Union:
      case MiniDecafParser::Unsigned:
      case MiniDecafParser::Void:
      case MiniDecafParser::Volatile:
      case MiniDecafParser::Atomic:
      case MiniDecafParser::Bool:
      case MiniDecafParser::Complex:
      case MiniDecafParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(611);
        specifierQualifierList();
        setState(613);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 59) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 59)) & ((1ULL << (MiniDecafParser::LeftParen - 59))
          | (1ULL << (MiniDecafParser::Star - 59))
          | (1ULL << (MiniDecafParser::Caret - 59))
          | (1ULL << (MiniDecafParser::Colon - 59))
          | (1ULL << (MiniDecafParser::Identifier - 59)))) != 0)) {
          setState(612);
          structDeclaratorList(0);
        }
        setState(615);
        match(MiniDecafParser::Semi);
        break;
      }

      case MiniDecafParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(617);
        staticAssertDeclaration();
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

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

MiniDecafParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::TypeSpecifierContext* MiniDecafParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContext<MiniDecafParser::TypeSpecifierContext>(0);
}

MiniDecafParser::SpecifierQualifierListContext* MiniDecafParser::SpecifierQualifierListContext::specifierQualifierList() {
  return getRuleContext<MiniDecafParser::SpecifierQualifierListContext>(0);
}

MiniDecafParser::TypeQualifierContext* MiniDecafParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContext<MiniDecafParser::TypeQualifierContext>(0);
}


size_t MiniDecafParser::SpecifierQualifierListContext::getRuleIndex() const {
  return MiniDecafParser::RuleSpecifierQualifierList;
}


antlrcpp::Any MiniDecafParser::SpecifierQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitSpecifierQualifierList(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::SpecifierQualifierListContext* MiniDecafParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 72, MiniDecafParser::RuleSpecifierQualifierList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(628);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(620);
      typeSpecifier(0);
      setState(622);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
      case 1: {
        setState(621);
        specifierQualifierList();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(624);
      typeQualifier();
      setState(626);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
      case 1: {
        setState(625);
        specifierQualifierList();
        break;
      }

      }
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

//----------------- StructDeclaratorListContext ------------------------------------------------------------------

MiniDecafParser::StructDeclaratorListContext::StructDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::StructDeclaratorContext* MiniDecafParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContext<MiniDecafParser::StructDeclaratorContext>(0);
}

MiniDecafParser::StructDeclaratorListContext* MiniDecafParser::StructDeclaratorListContext::structDeclaratorList() {
  return getRuleContext<MiniDecafParser::StructDeclaratorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::StructDeclaratorListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::StructDeclaratorListContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructDeclaratorList;
}


antlrcpp::Any MiniDecafParser::StructDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::StructDeclaratorListContext* MiniDecafParser::structDeclaratorList() {
   return structDeclaratorList(0);
}

MiniDecafParser::StructDeclaratorListContext* MiniDecafParser::structDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, parentState);
  MiniDecafParser::StructDeclaratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, MiniDecafParser::RuleStructDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(631);
    structDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(638);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclaratorList);
        setState(633);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(634);
        match(MiniDecafParser::Comma);
        setState(635);
        structDeclarator(); 
      }
      setState(640);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclaratorContext ------------------------------------------------------------------

MiniDecafParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::StructDeclaratorContext::declarator() {
  return getRuleContext<MiniDecafParser::DeclaratorContext>(0);
}

tree::TerminalNode* MiniDecafParser::StructDeclaratorContext::Colon() {
  return getToken(MiniDecafParser::Colon, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::StructDeclaratorContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}


size_t MiniDecafParser::StructDeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleStructDeclarator;
}


antlrcpp::Any MiniDecafParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StructDeclaratorContext* MiniDecafParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 76, MiniDecafParser::RuleStructDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(647);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(641);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(643);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 59) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 59)) & ((1ULL << (MiniDecafParser::LeftParen - 59))
        | (1ULL << (MiniDecafParser::Star - 59))
        | (1ULL << (MiniDecafParser::Caret - 59))
        | (1ULL << (MiniDecafParser::Identifier - 59)))) != 0)) {
        setState(642);
        declarator();
      }
      setState(645);
      match(MiniDecafParser::Colon);
      setState(646);
      constantExpression();
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

//----------------- EnumSpecifierContext ------------------------------------------------------------------

MiniDecafParser::EnumSpecifierContext::EnumSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::EnumSpecifierContext::Enum() {
  return getToken(MiniDecafParser::Enum, 0);
}

tree::TerminalNode* MiniDecafParser::EnumSpecifierContext::LeftBrace() {
  return getToken(MiniDecafParser::LeftBrace, 0);
}

MiniDecafParser::EnumeratorListContext* MiniDecafParser::EnumSpecifierContext::enumeratorList() {
  return getRuleContext<MiniDecafParser::EnumeratorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::EnumSpecifierContext::RightBrace() {
  return getToken(MiniDecafParser::RightBrace, 0);
}

tree::TerminalNode* MiniDecafParser::EnumSpecifierContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::EnumSpecifierContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::EnumSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleEnumSpecifier;
}


antlrcpp::Any MiniDecafParser::EnumSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEnumSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::EnumSpecifierContext* MiniDecafParser::enumSpecifier() {
  EnumSpecifierContext *_localctx = _tracker.createInstance<EnumSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 78, MiniDecafParser::RuleEnumSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(668);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(649);
      match(MiniDecafParser::Enum);
      setState(651);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::Identifier) {
        setState(650);
        match(MiniDecafParser::Identifier);
      }
      setState(653);
      match(MiniDecafParser::LeftBrace);
      setState(654);
      enumeratorList(0);
      setState(655);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(657);
      match(MiniDecafParser::Enum);
      setState(659);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::Identifier) {
        setState(658);
        match(MiniDecafParser::Identifier);
      }
      setState(661);
      match(MiniDecafParser::LeftBrace);
      setState(662);
      enumeratorList(0);
      setState(663);
      match(MiniDecafParser::Comma);
      setState(664);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(666);
      match(MiniDecafParser::Enum);
      setState(667);
      match(MiniDecafParser::Identifier);
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

//----------------- EnumeratorListContext ------------------------------------------------------------------

MiniDecafParser::EnumeratorListContext::EnumeratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::EnumeratorContext* MiniDecafParser::EnumeratorListContext::enumerator() {
  return getRuleContext<MiniDecafParser::EnumeratorContext>(0);
}

MiniDecafParser::EnumeratorListContext* MiniDecafParser::EnumeratorListContext::enumeratorList() {
  return getRuleContext<MiniDecafParser::EnumeratorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::EnumeratorListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::EnumeratorListContext::getRuleIndex() const {
  return MiniDecafParser::RuleEnumeratorList;
}


antlrcpp::Any MiniDecafParser::EnumeratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEnumeratorList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::EnumeratorListContext* MiniDecafParser::enumeratorList() {
   return enumeratorList(0);
}

MiniDecafParser::EnumeratorListContext* MiniDecafParser::enumeratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::EnumeratorListContext *_localctx = _tracker.createInstance<EnumeratorListContext>(_ctx, parentState);
  MiniDecafParser::EnumeratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, MiniDecafParser::RuleEnumeratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(671);
    enumerator();
    _ctx->stop = _input->LT(-1);
    setState(678);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EnumeratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEnumeratorList);
        setState(673);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(674);
        match(MiniDecafParser::Comma);
        setState(675);
        enumerator(); 
      }
      setState(680);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EnumeratorContext ------------------------------------------------------------------

MiniDecafParser::EnumeratorContext::EnumeratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::EnumerationConstantContext* MiniDecafParser::EnumeratorContext::enumerationConstant() {
  return getRuleContext<MiniDecafParser::EnumerationConstantContext>(0);
}

tree::TerminalNode* MiniDecafParser::EnumeratorContext::Assign() {
  return getToken(MiniDecafParser::Assign, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::EnumeratorContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}


size_t MiniDecafParser::EnumeratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleEnumerator;
}


antlrcpp::Any MiniDecafParser::EnumeratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEnumerator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::EnumeratorContext* MiniDecafParser::enumerator() {
  EnumeratorContext *_localctx = _tracker.createInstance<EnumeratorContext>(_ctx, getState());
  enterRule(_localctx, 82, MiniDecafParser::RuleEnumerator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(686);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(681);
      enumerationConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(682);
      enumerationConstant();
      setState(683);
      match(MiniDecafParser::Assign);
      setState(684);
      constantExpression();
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

//----------------- EnumerationConstantContext ------------------------------------------------------------------

MiniDecafParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::EnumerationConstantContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}


size_t MiniDecafParser::EnumerationConstantContext::getRuleIndex() const {
  return MiniDecafParser::RuleEnumerationConstant;
}


antlrcpp::Any MiniDecafParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::EnumerationConstantContext* MiniDecafParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 84, MiniDecafParser::RuleEnumerationConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(688);
    match(MiniDecafParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicTypeSpecifierContext ------------------------------------------------------------------

MiniDecafParser::AtomicTypeSpecifierContext::AtomicTypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::AtomicTypeSpecifierContext::Atomic() {
  return getToken(MiniDecafParser::Atomic, 0);
}

tree::TerminalNode* MiniDecafParser::AtomicTypeSpecifierContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::AtomicTypeSpecifierContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::AtomicTypeSpecifierContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}


size_t MiniDecafParser::AtomicTypeSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleAtomicTypeSpecifier;
}


antlrcpp::Any MiniDecafParser::AtomicTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAtomicTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::AtomicTypeSpecifierContext* MiniDecafParser::atomicTypeSpecifier() {
  AtomicTypeSpecifierContext *_localctx = _tracker.createInstance<AtomicTypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 86, MiniDecafParser::RuleAtomicTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    match(MiniDecafParser::Atomic);
    setState(691);
    match(MiniDecafParser::LeftParen);
    setState(692);
    typeName();
    setState(693);
    match(MiniDecafParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierContext ------------------------------------------------------------------

MiniDecafParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::TypeQualifierContext::Const() {
  return getToken(MiniDecafParser::Const, 0);
}

tree::TerminalNode* MiniDecafParser::TypeQualifierContext::Restrict() {
  return getToken(MiniDecafParser::Restrict, 0);
}

tree::TerminalNode* MiniDecafParser::TypeQualifierContext::Volatile() {
  return getToken(MiniDecafParser::Volatile, 0);
}

tree::TerminalNode* MiniDecafParser::TypeQualifierContext::Atomic() {
  return getToken(MiniDecafParser::Atomic, 0);
}


size_t MiniDecafParser::TypeQualifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleTypeQualifier;
}


antlrcpp::Any MiniDecafParser::TypeQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTypeQualifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::TypeQualifierContext* MiniDecafParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 88, MiniDecafParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
      | (1ULL << MiniDecafParser::Restrict)
      | (1ULL << MiniDecafParser::Volatile)
      | (1ULL << MiniDecafParser::Atomic))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionSpecifierContext ------------------------------------------------------------------

MiniDecafParser::FunctionSpecifierContext::FunctionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::FunctionSpecifierContext::Inline() {
  return getToken(MiniDecafParser::Inline, 0);
}

tree::TerminalNode* MiniDecafParser::FunctionSpecifierContext::Noreturn() {
  return getToken(MiniDecafParser::Noreturn, 0);
}

MiniDecafParser::GccAttributeSpecifierContext* MiniDecafParser::FunctionSpecifierContext::gccAttributeSpecifier() {
  return getRuleContext<MiniDecafParser::GccAttributeSpecifierContext>(0);
}

tree::TerminalNode* MiniDecafParser::FunctionSpecifierContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

tree::TerminalNode* MiniDecafParser::FunctionSpecifierContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::FunctionSpecifierContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}


size_t MiniDecafParser::FunctionSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleFunctionSpecifier;
}


antlrcpp::Any MiniDecafParser::FunctionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitFunctionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::FunctionSpecifierContext* MiniDecafParser::functionSpecifier() {
  FunctionSpecifierContext *_localctx = _tracker.createInstance<FunctionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 90, MiniDecafParser::RuleFunctionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(703);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__7:
      case MiniDecafParser::T__8:
      case MiniDecafParser::Inline:
      case MiniDecafParser::Noreturn: {
        enterOuterAlt(_localctx, 1);
        setState(697);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::T__7)
          | (1ULL << MiniDecafParser::T__8)
          | (1ULL << MiniDecafParser::Inline)
          | (1ULL << MiniDecafParser::Noreturn))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case MiniDecafParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(698);
        gccAttributeSpecifier();
        break;
      }

      case MiniDecafParser::T__9: {
        enterOuterAlt(_localctx, 3);
        setState(699);
        match(MiniDecafParser::T__9);
        setState(700);
        match(MiniDecafParser::LeftParen);
        setState(701);
        match(MiniDecafParser::Identifier);
        setState(702);
        match(MiniDecafParser::RightParen);
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

//----------------- AlignmentSpecifierContext ------------------------------------------------------------------

MiniDecafParser::AlignmentSpecifierContext::AlignmentSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::AlignmentSpecifierContext::Alignas() {
  return getToken(MiniDecafParser::Alignas, 0);
}

tree::TerminalNode* MiniDecafParser::AlignmentSpecifierContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::AlignmentSpecifierContext::typeName() {
  return getRuleContext<MiniDecafParser::TypeNameContext>(0);
}

tree::TerminalNode* MiniDecafParser::AlignmentSpecifierContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::AlignmentSpecifierContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}


size_t MiniDecafParser::AlignmentSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleAlignmentSpecifier;
}


antlrcpp::Any MiniDecafParser::AlignmentSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAlignmentSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::AlignmentSpecifierContext* MiniDecafParser::alignmentSpecifier() {
  AlignmentSpecifierContext *_localctx = _tracker.createInstance<AlignmentSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 92, MiniDecafParser::RuleAlignmentSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(715);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(705);
      match(MiniDecafParser::Alignas);
      setState(706);
      match(MiniDecafParser::LeftParen);
      setState(707);
      typeName();
      setState(708);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(710);
      match(MiniDecafParser::Alignas);
      setState(711);
      match(MiniDecafParser::LeftParen);
      setState(712);
      constantExpression();
      setState(713);
      match(MiniDecafParser::RightParen);
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

//----------------- DeclaratorContext ------------------------------------------------------------------

MiniDecafParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DirectDeclaratorContext* MiniDecafParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<MiniDecafParser::DirectDeclaratorContext>(0);
}

MiniDecafParser::PointerContext* MiniDecafParser::DeclaratorContext::pointer() {
  return getRuleContext<MiniDecafParser::PointerContext>(0);
}

std::vector<MiniDecafParser::GccDeclaratorExtensionContext *> MiniDecafParser::DeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<MiniDecafParser::GccDeclaratorExtensionContext>();
}

MiniDecafParser::GccDeclaratorExtensionContext* MiniDecafParser::DeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<MiniDecafParser::GccDeclaratorExtensionContext>(i);
}


size_t MiniDecafParser::DeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleDeclarator;
}


antlrcpp::Any MiniDecafParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 94, MiniDecafParser::RuleDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(718);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MiniDecafParser::Star

    || _la == MiniDecafParser::Caret) {
      setState(717);
      pointer();
    }
    setState(720);
    directDeclarator(0);
    setState(724);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(721);
        gccDeclaratorExtension(); 
      }
      setState(726);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

MiniDecafParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<MiniDecafParser::DeclaratorContext>(0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::Colon() {
  return getToken(MiniDecafParser::Colon, 0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::DigitSequence() {
  return getToken(MiniDecafParser::DigitSequence, 0);
}

MiniDecafParser::PointerContext* MiniDecafParser::DirectDeclaratorContext::pointer() {
  return getRuleContext<MiniDecafParser::PointerContext>(0);
}

MiniDecafParser::DirectDeclaratorContext* MiniDecafParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<MiniDecafParser::DirectDeclaratorContext>(0);
}

MiniDecafParser::TypeSpecifierContext* MiniDecafParser::DirectDeclaratorContext::typeSpecifier() {
  return getRuleContext<MiniDecafParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::LeftBracket() {
  return getToken(MiniDecafParser::LeftBracket, 0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::RightBracket() {
  return getToken(MiniDecafParser::RightBracket, 0);
}

MiniDecafParser::TypeQualifierListContext* MiniDecafParser::DirectDeclaratorContext::typeQualifierList() {
  return getRuleContext<MiniDecafParser::TypeQualifierListContext>(0);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::DirectDeclaratorContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::Static() {
  return getToken(MiniDecafParser::Static, 0);
}

tree::TerminalNode* MiniDecafParser::DirectDeclaratorContext::Star() {
  return getToken(MiniDecafParser::Star, 0);
}

MiniDecafParser::ParameterTypeListContext* MiniDecafParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<MiniDecafParser::ParameterTypeListContext>(0);
}

MiniDecafParser::IdentifierListContext* MiniDecafParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<MiniDecafParser::IdentifierListContext>(0);
}


size_t MiniDecafParser::DirectDeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleDirectDeclarator;
}


antlrcpp::Any MiniDecafParser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::DirectDeclaratorContext* MiniDecafParser::directDeclarator() {
   return directDeclarator(0);
}

MiniDecafParser::DirectDeclaratorContext* MiniDecafParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  MiniDecafParser::DirectDeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, MiniDecafParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(744);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(728);
      match(MiniDecafParser::Identifier);
      break;
    }

    case 2: {
      setState(729);
      match(MiniDecafParser::LeftParen);
      setState(730);
      declarator();
      setState(731);
      match(MiniDecafParser::RightParen);
      break;
    }

    case 3: {
      setState(733);
      match(MiniDecafParser::Identifier);
      setState(734);
      match(MiniDecafParser::Colon);
      setState(735);
      match(MiniDecafParser::DigitSequence);
      break;
    }

    case 4: {
      setState(736);
      match(MiniDecafParser::LeftParen);
      setState(738);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__3)
        | (1ULL << MiniDecafParser::T__4)
        | (1ULL << MiniDecafParser::T__5)
        | (1ULL << MiniDecafParser::T__6)
        | (1ULL << MiniDecafParser::Char)
        | (1ULL << MiniDecafParser::Double)
        | (1ULL << MiniDecafParser::Enum)
        | (1ULL << MiniDecafParser::Float)
        | (1ULL << MiniDecafParser::Int)
        | (1ULL << MiniDecafParser::Long)
        | (1ULL << MiniDecafParser::Short)
        | (1ULL << MiniDecafParser::Signed)
        | (1ULL << MiniDecafParser::Struct)
        | (1ULL << MiniDecafParser::Union)
        | (1ULL << MiniDecafParser::Unsigned)
        | (1ULL << MiniDecafParser::Void)
        | (1ULL << MiniDecafParser::Atomic)
        | (1ULL << MiniDecafParser::Bool)
        | (1ULL << MiniDecafParser::Complex))) != 0) || _la == MiniDecafParser::Identifier) {
        setState(737);
        typeSpecifier(0);
      }
      setState(740);
      pointer();
      setState(741);
      directDeclarator(0);
      setState(742);
      match(MiniDecafParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(791);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(789);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(746);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(747);
          match(MiniDecafParser::LeftBracket);
          setState(749);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Atomic))) != 0)) {
            setState(748);
            typeQualifierList(0);
          }
          setState(752);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
            | (1ULL << MiniDecafParser::T__1)
            | (1ULL << MiniDecafParser::T__2)
            | (1ULL << MiniDecafParser::Sizeof)
            | (1ULL << MiniDecafParser::Alignof)
            | (1ULL << MiniDecafParser::Generic)
            | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
            | (1ULL << (MiniDecafParser::PlusPlus - 71))
            | (1ULL << (MiniDecafParser::Minus - 71))
            | (1ULL << (MiniDecafParser::MinusMinus - 71))
            | (1ULL << (MiniDecafParser::Star - 71))
            | (1ULL << (MiniDecafParser::And - 71))
            | (1ULL << (MiniDecafParser::AndAnd - 71))
            | (1ULL << (MiniDecafParser::Not - 71))
            | (1ULL << (MiniDecafParser::Tilde - 71))
            | (1ULL << (MiniDecafParser::Identifier - 71))
            | (1ULL << (MiniDecafParser::Constant - 71))
            | (1ULL << (MiniDecafParser::DigitSequence - 71))
            | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
            setState(751);
            assignmentExpression();
          }
          setState(754);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(755);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(756);
          match(MiniDecafParser::LeftBracket);
          setState(757);
          match(MiniDecafParser::Static);
          setState(759);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Atomic))) != 0)) {
            setState(758);
            typeQualifierList(0);
          }
          setState(761);
          assignmentExpression();
          setState(762);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(764);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(765);
          match(MiniDecafParser::LeftBracket);
          setState(766);
          typeQualifierList(0);
          setState(767);
          match(MiniDecafParser::Static);
          setState(768);
          assignmentExpression();
          setState(769);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(771);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(772);
          match(MiniDecafParser::LeftBracket);
          setState(774);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Atomic))) != 0)) {
            setState(773);
            typeQualifierList(0);
          }
          setState(776);
          match(MiniDecafParser::Star);
          setState(777);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(778);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(779);
          match(MiniDecafParser::LeftParen);
          setState(780);
          parameterTypeList();
          setState(781);
          match(MiniDecafParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(783);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(784);
          match(MiniDecafParser::LeftParen);
          setState(786);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MiniDecafParser::Identifier) {
            setState(785);
            identifierList(0);
          }
          setState(788);
          match(MiniDecafParser::RightParen);
          break;
        }

        } 
      }
      setState(793);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GccDeclaratorExtensionContext ------------------------------------------------------------------

MiniDecafParser::GccDeclaratorExtensionContext::GccDeclaratorExtensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::GccDeclaratorExtensionContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

tree::TerminalNode* MiniDecafParser::GccDeclaratorExtensionContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccDeclaratorExtensionContext::StringLiteral() {
  return getTokens(MiniDecafParser::StringLiteral);
}

tree::TerminalNode* MiniDecafParser::GccDeclaratorExtensionContext::StringLiteral(size_t i) {
  return getToken(MiniDecafParser::StringLiteral, i);
}

MiniDecafParser::GccAttributeSpecifierContext* MiniDecafParser::GccDeclaratorExtensionContext::gccAttributeSpecifier() {
  return getRuleContext<MiniDecafParser::GccAttributeSpecifierContext>(0);
}


size_t MiniDecafParser::GccDeclaratorExtensionContext::getRuleIndex() const {
  return MiniDecafParser::RuleGccDeclaratorExtension;
}


antlrcpp::Any MiniDecafParser::GccDeclaratorExtensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGccDeclaratorExtension(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GccDeclaratorExtensionContext* MiniDecafParser::gccDeclaratorExtension() {
  GccDeclaratorExtensionContext *_localctx = _tracker.createInstance<GccDeclaratorExtensionContext>(_ctx, getState());
  enterRule(_localctx, 98, MiniDecafParser::RuleGccDeclaratorExtension);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(803);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__10: {
        enterOuterAlt(_localctx, 1);
        setState(794);
        match(MiniDecafParser::T__10);
        setState(795);
        match(MiniDecafParser::LeftParen);
        setState(797); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(796);
          match(MiniDecafParser::StringLiteral);
          setState(799); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MiniDecafParser::StringLiteral);
        setState(801);
        match(MiniDecafParser::RightParen);
        break;
      }

      case MiniDecafParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(802);
        gccAttributeSpecifier();
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

//----------------- GccAttributeSpecifierContext ------------------------------------------------------------------

MiniDecafParser::GccAttributeSpecifierContext::GccAttributeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccAttributeSpecifierContext::LeftParen() {
  return getTokens(MiniDecafParser::LeftParen);
}

tree::TerminalNode* MiniDecafParser::GccAttributeSpecifierContext::LeftParen(size_t i) {
  return getToken(MiniDecafParser::LeftParen, i);
}

MiniDecafParser::GccAttributeListContext* MiniDecafParser::GccAttributeSpecifierContext::gccAttributeList() {
  return getRuleContext<MiniDecafParser::GccAttributeListContext>(0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccAttributeSpecifierContext::RightParen() {
  return getTokens(MiniDecafParser::RightParen);
}

tree::TerminalNode* MiniDecafParser::GccAttributeSpecifierContext::RightParen(size_t i) {
  return getToken(MiniDecafParser::RightParen, i);
}


size_t MiniDecafParser::GccAttributeSpecifierContext::getRuleIndex() const {
  return MiniDecafParser::RuleGccAttributeSpecifier;
}


antlrcpp::Any MiniDecafParser::GccAttributeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGccAttributeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GccAttributeSpecifierContext* MiniDecafParser::gccAttributeSpecifier() {
  GccAttributeSpecifierContext *_localctx = _tracker.createInstance<GccAttributeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 100, MiniDecafParser::RuleGccAttributeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(805);
    match(MiniDecafParser::T__11);
    setState(806);
    match(MiniDecafParser::LeftParen);
    setState(807);
    match(MiniDecafParser::LeftParen);
    setState(808);
    gccAttributeList();
    setState(809);
    match(MiniDecafParser::RightParen);
    setState(810);
    match(MiniDecafParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeListContext ------------------------------------------------------------------

MiniDecafParser::GccAttributeListContext::GccAttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniDecafParser::GccAttributeContext *> MiniDecafParser::GccAttributeListContext::gccAttribute() {
  return getRuleContexts<MiniDecafParser::GccAttributeContext>();
}

MiniDecafParser::GccAttributeContext* MiniDecafParser::GccAttributeListContext::gccAttribute(size_t i) {
  return getRuleContext<MiniDecafParser::GccAttributeContext>(i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccAttributeListContext::Comma() {
  return getTokens(MiniDecafParser::Comma);
}

tree::TerminalNode* MiniDecafParser::GccAttributeListContext::Comma(size_t i) {
  return getToken(MiniDecafParser::Comma, i);
}


size_t MiniDecafParser::GccAttributeListContext::getRuleIndex() const {
  return MiniDecafParser::RuleGccAttributeList;
}


antlrcpp::Any MiniDecafParser::GccAttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGccAttributeList(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GccAttributeListContext* MiniDecafParser::gccAttributeList() {
  GccAttributeListContext *_localctx = _tracker.createInstance<GccAttributeListContext>(_ctx, getState());
  enterRule(_localctx, 102, MiniDecafParser::RuleGccAttributeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(821);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(812);
      gccAttribute();
      setState(817);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MiniDecafParser::Comma) {
        setState(813);
        match(MiniDecafParser::Comma);
        setState(814);
        gccAttribute();
        setState(819);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

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

//----------------- GccAttributeContext ------------------------------------------------------------------

MiniDecafParser::GccAttributeContext::GccAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::GccAttributeContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccAttributeContext::LeftParen() {
  return getTokens(MiniDecafParser::LeftParen);
}

tree::TerminalNode* MiniDecafParser::GccAttributeContext::LeftParen(size_t i) {
  return getToken(MiniDecafParser::LeftParen, i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::GccAttributeContext::RightParen() {
  return getTokens(MiniDecafParser::RightParen);
}

tree::TerminalNode* MiniDecafParser::GccAttributeContext::RightParen(size_t i) {
  return getToken(MiniDecafParser::RightParen, i);
}

MiniDecafParser::ArgumentExpressionListContext* MiniDecafParser::GccAttributeContext::argumentExpressionList() {
  return getRuleContext<MiniDecafParser::ArgumentExpressionListContext>(0);
}


size_t MiniDecafParser::GccAttributeContext::getRuleIndex() const {
  return MiniDecafParser::RuleGccAttribute;
}


antlrcpp::Any MiniDecafParser::GccAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitGccAttribute(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::GccAttributeContext* MiniDecafParser::gccAttribute() {
  GccAttributeContext *_localctx = _tracker.createInstance<GccAttributeContext>(_ctx, getState());
  enterRule(_localctx, 104, MiniDecafParser::RuleGccAttribute);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(832);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::T__0:
      case MiniDecafParser::T__1:
      case MiniDecafParser::T__2:
      case MiniDecafParser::T__3:
      case MiniDecafParser::T__4:
      case MiniDecafParser::T__5:
      case MiniDecafParser::T__6:
      case MiniDecafParser::T__7:
      case MiniDecafParser::T__8:
      case MiniDecafParser::T__9:
      case MiniDecafParser::T__10:
      case MiniDecafParser::T__11:
      case MiniDecafParser::T__12:
      case MiniDecafParser::T__13:
      case MiniDecafParser::Auto:
      case MiniDecafParser::Break:
      case MiniDecafParser::Case:
      case MiniDecafParser::Char:
      case MiniDecafParser::Const:
      case MiniDecafParser::Continue:
      case MiniDecafParser::Default:
      case MiniDecafParser::Do:
      case MiniDecafParser::Double:
      case MiniDecafParser::Else:
      case MiniDecafParser::Enum:
      case MiniDecafParser::Extern:
      case MiniDecafParser::Float:
      case MiniDecafParser::For:
      case MiniDecafParser::Goto:
      case MiniDecafParser::If:
      case MiniDecafParser::Inline:
      case MiniDecafParser::Int:
      case MiniDecafParser::Long:
      case MiniDecafParser::Register:
      case MiniDecafParser::Restrict:
      case MiniDecafParser::Return:
      case MiniDecafParser::Short:
      case MiniDecafParser::Signed:
      case MiniDecafParser::Sizeof:
      case MiniDecafParser::Static:
      case MiniDecafParser::Struct:
      case MiniDecafParser::Switch:
      case MiniDecafParser::Typedef:
      case MiniDecafParser::Union:
      case MiniDecafParser::Unsigned:
      case MiniDecafParser::Void:
      case MiniDecafParser::Volatile:
      case MiniDecafParser::While:
      case MiniDecafParser::Alignas:
      case MiniDecafParser::Alignof:
      case MiniDecafParser::Atomic:
      case MiniDecafParser::Bool:
      case MiniDecafParser::Complex:
      case MiniDecafParser::Generic:
      case MiniDecafParser::Imaginary:
      case MiniDecafParser::Noreturn:
      case MiniDecafParser::StaticAssert:
      case MiniDecafParser::ThreadLocal:
      case MiniDecafParser::LeftBracket:
      case MiniDecafParser::RightBracket:
      case MiniDecafParser::LeftBrace:
      case MiniDecafParser::RightBrace:
      case MiniDecafParser::Less:
      case MiniDecafParser::LessEqual:
      case MiniDecafParser::Greater:
      case MiniDecafParser::GreaterEqual:
      case MiniDecafParser::LeftShift:
      case MiniDecafParser::RightShift:
      case MiniDecafParser::Plus:
      case MiniDecafParser::PlusPlus:
      case MiniDecafParser::Minus:
      case MiniDecafParser::MinusMinus:
      case MiniDecafParser::Star:
      case MiniDecafParser::Div:
      case MiniDecafParser::Mod:
      case MiniDecafParser::And:
      case MiniDecafParser::Or:
      case MiniDecafParser::AndAnd:
      case MiniDecafParser::OrOr:
      case MiniDecafParser::Caret:
      case MiniDecafParser::Not:
      case MiniDecafParser::Tilde:
      case MiniDecafParser::Question:
      case MiniDecafParser::Colon:
      case MiniDecafParser::Semi:
      case MiniDecafParser::Assign:
      case MiniDecafParser::StarAssign:
      case MiniDecafParser::DivAssign:
      case MiniDecafParser::ModAssign:
      case MiniDecafParser::PlusAssign:
      case MiniDecafParser::MinusAssign:
      case MiniDecafParser::LeftShiftAssign:
      case MiniDecafParser::RightShiftAssign:
      case MiniDecafParser::AndAssign:
      case MiniDecafParser::XorAssign:
      case MiniDecafParser::OrAssign:
      case MiniDecafParser::Equal:
      case MiniDecafParser::NotEqual:
      case MiniDecafParser::Arrow:
      case MiniDecafParser::Dot:
      case MiniDecafParser::Ellipsis:
      case MiniDecafParser::Identifier:
      case MiniDecafParser::Constant:
      case MiniDecafParser::DigitSequence:
      case MiniDecafParser::StringLiteral:
      case MiniDecafParser::ComplexDefine:
      case MiniDecafParser::IncludeDirective:
      case MiniDecafParser::AsmBlock:
      case MiniDecafParser::LineAfterPreprocessing:
      case MiniDecafParser::LineDirective:
      case MiniDecafParser::PragmaDirective:
      case MiniDecafParser::Whitespace:
      case MiniDecafParser::Newline:
      case MiniDecafParser::BlockComment:
      case MiniDecafParser::LineComment: {
        enterOuterAlt(_localctx, 1);
        setState(823);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (((((_la - 59) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 59)) & ((1ULL << (MiniDecafParser::LeftParen - 59))
          | (1ULL << (MiniDecafParser::RightParen - 59))
          | (1ULL << (MiniDecafParser::Comma - 59)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(829);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MiniDecafParser::LeftParen) {
          setState(824);
          match(MiniDecafParser::LeftParen);
          setState(826);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
            | (1ULL << MiniDecafParser::T__1)
            | (1ULL << MiniDecafParser::T__2)
            | (1ULL << MiniDecafParser::Sizeof)
            | (1ULL << MiniDecafParser::Alignof)
            | (1ULL << MiniDecafParser::Generic)
            | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
            | (1ULL << (MiniDecafParser::PlusPlus - 71))
            | (1ULL << (MiniDecafParser::Minus - 71))
            | (1ULL << (MiniDecafParser::MinusMinus - 71))
            | (1ULL << (MiniDecafParser::Star - 71))
            | (1ULL << (MiniDecafParser::And - 71))
            | (1ULL << (MiniDecafParser::AndAnd - 71))
            | (1ULL << (MiniDecafParser::Not - 71))
            | (1ULL << (MiniDecafParser::Tilde - 71))
            | (1ULL << (MiniDecafParser::Identifier - 71))
            | (1ULL << (MiniDecafParser::Constant - 71))
            | (1ULL << (MiniDecafParser::DigitSequence - 71))
            | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
            setState(825);
            argumentExpressionList(0);
          }
          setState(828);
          match(MiniDecafParser::RightParen);
        }
        break;
      }

      case MiniDecafParser::RightParen:
      case MiniDecafParser::Comma: {
        enterOuterAlt(_localctx, 2);

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

//----------------- NestedParenthesesBlockContext ------------------------------------------------------------------

MiniDecafParser::NestedParenthesesBlockContext::NestedParenthesesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MiniDecafParser::NestedParenthesesBlockContext::LeftParen() {
  return getTokens(MiniDecafParser::LeftParen);
}

tree::TerminalNode* MiniDecafParser::NestedParenthesesBlockContext::LeftParen(size_t i) {
  return getToken(MiniDecafParser::LeftParen, i);
}

std::vector<MiniDecafParser::NestedParenthesesBlockContext *> MiniDecafParser::NestedParenthesesBlockContext::nestedParenthesesBlock() {
  return getRuleContexts<MiniDecafParser::NestedParenthesesBlockContext>();
}

MiniDecafParser::NestedParenthesesBlockContext* MiniDecafParser::NestedParenthesesBlockContext::nestedParenthesesBlock(size_t i) {
  return getRuleContext<MiniDecafParser::NestedParenthesesBlockContext>(i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::NestedParenthesesBlockContext::RightParen() {
  return getTokens(MiniDecafParser::RightParen);
}

tree::TerminalNode* MiniDecafParser::NestedParenthesesBlockContext::RightParen(size_t i) {
  return getToken(MiniDecafParser::RightParen, i);
}


size_t MiniDecafParser::NestedParenthesesBlockContext::getRuleIndex() const {
  return MiniDecafParser::RuleNestedParenthesesBlock;
}


antlrcpp::Any MiniDecafParser::NestedParenthesesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitNestedParenthesesBlock(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::NestedParenthesesBlockContext* MiniDecafParser::nestedParenthesesBlock() {
  NestedParenthesesBlockContext *_localctx = _tracker.createInstance<NestedParenthesesBlockContext>(_ctx, getState());
  enterRule(_localctx, 106, MiniDecafParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(841);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
      | (1ULL << MiniDecafParser::T__1)
      | (1ULL << MiniDecafParser::T__2)
      | (1ULL << MiniDecafParser::T__3)
      | (1ULL << MiniDecafParser::T__4)
      | (1ULL << MiniDecafParser::T__5)
      | (1ULL << MiniDecafParser::T__6)
      | (1ULL << MiniDecafParser::T__7)
      | (1ULL << MiniDecafParser::T__8)
      | (1ULL << MiniDecafParser::T__9)
      | (1ULL << MiniDecafParser::T__10)
      | (1ULL << MiniDecafParser::T__11)
      | (1ULL << MiniDecafParser::T__12)
      | (1ULL << MiniDecafParser::T__13)
      | (1ULL << MiniDecafParser::Auto)
      | (1ULL << MiniDecafParser::Break)
      | (1ULL << MiniDecafParser::Case)
      | (1ULL << MiniDecafParser::Char)
      | (1ULL << MiniDecafParser::Const)
      | (1ULL << MiniDecafParser::Continue)
      | (1ULL << MiniDecafParser::Default)
      | (1ULL << MiniDecafParser::Do)
      | (1ULL << MiniDecafParser::Double)
      | (1ULL << MiniDecafParser::Else)
      | (1ULL << MiniDecafParser::Enum)
      | (1ULL << MiniDecafParser::Extern)
      | (1ULL << MiniDecafParser::Float)
      | (1ULL << MiniDecafParser::For)
      | (1ULL << MiniDecafParser::Goto)
      | (1ULL << MiniDecafParser::If)
      | (1ULL << MiniDecafParser::Inline)
      | (1ULL << MiniDecafParser::Int)
      | (1ULL << MiniDecafParser::Long)
      | (1ULL << MiniDecafParser::Register)
      | (1ULL << MiniDecafParser::Restrict)
      | (1ULL << MiniDecafParser::Return)
      | (1ULL << MiniDecafParser::Short)
      | (1ULL << MiniDecafParser::Signed)
      | (1ULL << MiniDecafParser::Sizeof)
      | (1ULL << MiniDecafParser::Static)
      | (1ULL << MiniDecafParser::Struct)
      | (1ULL << MiniDecafParser::Switch)
      | (1ULL << MiniDecafParser::Typedef)
      | (1ULL << MiniDecafParser::Union)
      | (1ULL << MiniDecafParser::Unsigned)
      | (1ULL << MiniDecafParser::Void)
      | (1ULL << MiniDecafParser::Volatile)
      | (1ULL << MiniDecafParser::While)
      | (1ULL << MiniDecafParser::Alignas)
      | (1ULL << MiniDecafParser::Alignof)
      | (1ULL << MiniDecafParser::Atomic)
      | (1ULL << MiniDecafParser::Bool)
      | (1ULL << MiniDecafParser::Complex)
      | (1ULL << MiniDecafParser::Generic)
      | (1ULL << MiniDecafParser::Imaginary)
      | (1ULL << MiniDecafParser::Noreturn)
      | (1ULL << MiniDecafParser::StaticAssert)
      | (1ULL << MiniDecafParser::ThreadLocal)
      | (1ULL << MiniDecafParser::LeftParen)
      | (1ULL << MiniDecafParser::LeftBracket)
      | (1ULL << MiniDecafParser::RightBracket)
      | (1ULL << MiniDecafParser::LeftBrace))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MiniDecafParser::RightBrace - 64))
      | (1ULL << (MiniDecafParser::Less - 64))
      | (1ULL << (MiniDecafParser::LessEqual - 64))
      | (1ULL << (MiniDecafParser::Greater - 64))
      | (1ULL << (MiniDecafParser::GreaterEqual - 64))
      | (1ULL << (MiniDecafParser::LeftShift - 64))
      | (1ULL << (MiniDecafParser::RightShift - 64))
      | (1ULL << (MiniDecafParser::Plus - 64))
      | (1ULL << (MiniDecafParser::PlusPlus - 64))
      | (1ULL << (MiniDecafParser::Minus - 64))
      | (1ULL << (MiniDecafParser::MinusMinus - 64))
      | (1ULL << (MiniDecafParser::Star - 64))
      | (1ULL << (MiniDecafParser::Div - 64))
      | (1ULL << (MiniDecafParser::Mod - 64))
      | (1ULL << (MiniDecafParser::And - 64))
      | (1ULL << (MiniDecafParser::Or - 64))
      | (1ULL << (MiniDecafParser::AndAnd - 64))
      | (1ULL << (MiniDecafParser::OrOr - 64))
      | (1ULL << (MiniDecafParser::Caret - 64))
      | (1ULL << (MiniDecafParser::Not - 64))
      | (1ULL << (MiniDecafParser::Tilde - 64))
      | (1ULL << (MiniDecafParser::Question - 64))
      | (1ULL << (MiniDecafParser::Colon - 64))
      | (1ULL << (MiniDecafParser::Semi - 64))
      | (1ULL << (MiniDecafParser::Comma - 64))
      | (1ULL << (MiniDecafParser::Assign - 64))
      | (1ULL << (MiniDecafParser::StarAssign - 64))
      | (1ULL << (MiniDecafParser::DivAssign - 64))
      | (1ULL << (MiniDecafParser::ModAssign - 64))
      | (1ULL << (MiniDecafParser::PlusAssign - 64))
      | (1ULL << (MiniDecafParser::MinusAssign - 64))
      | (1ULL << (MiniDecafParser::LeftShiftAssign - 64))
      | (1ULL << (MiniDecafParser::RightShiftAssign - 64))
      | (1ULL << (MiniDecafParser::AndAssign - 64))
      | (1ULL << (MiniDecafParser::XorAssign - 64))
      | (1ULL << (MiniDecafParser::OrAssign - 64))
      | (1ULL << (MiniDecafParser::Equal - 64))
      | (1ULL << (MiniDecafParser::NotEqual - 64))
      | (1ULL << (MiniDecafParser::Arrow - 64))
      | (1ULL << (MiniDecafParser::Dot - 64))
      | (1ULL << (MiniDecafParser::Ellipsis - 64))
      | (1ULL << (MiniDecafParser::Identifier - 64))
      | (1ULL << (MiniDecafParser::Constant - 64))
      | (1ULL << (MiniDecafParser::DigitSequence - 64))
      | (1ULL << (MiniDecafParser::StringLiteral - 64))
      | (1ULL << (MiniDecafParser::ComplexDefine - 64))
      | (1ULL << (MiniDecafParser::IncludeDirective - 64))
      | (1ULL << (MiniDecafParser::AsmBlock - 64))
      | (1ULL << (MiniDecafParser::LineAfterPreprocessing - 64))
      | (1ULL << (MiniDecafParser::LineDirective - 64))
      | (1ULL << (MiniDecafParser::PragmaDirective - 64))
      | (1ULL << (MiniDecafParser::Whitespace - 64))
      | (1ULL << (MiniDecafParser::Newline - 64))
      | (1ULL << (MiniDecafParser::BlockComment - 64))
      | (1ULL << (MiniDecafParser::LineComment - 64)))) != 0)) {
      setState(839);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MiniDecafParser::T__0:
        case MiniDecafParser::T__1:
        case MiniDecafParser::T__2:
        case MiniDecafParser::T__3:
        case MiniDecafParser::T__4:
        case MiniDecafParser::T__5:
        case MiniDecafParser::T__6:
        case MiniDecafParser::T__7:
        case MiniDecafParser::T__8:
        case MiniDecafParser::T__9:
        case MiniDecafParser::T__10:
        case MiniDecafParser::T__11:
        case MiniDecafParser::T__12:
        case MiniDecafParser::T__13:
        case MiniDecafParser::Auto:
        case MiniDecafParser::Break:
        case MiniDecafParser::Case:
        case MiniDecafParser::Char:
        case MiniDecafParser::Const:
        case MiniDecafParser::Continue:
        case MiniDecafParser::Default:
        case MiniDecafParser::Do:
        case MiniDecafParser::Double:
        case MiniDecafParser::Else:
        case MiniDecafParser::Enum:
        case MiniDecafParser::Extern:
        case MiniDecafParser::Float:
        case MiniDecafParser::For:
        case MiniDecafParser::Goto:
        case MiniDecafParser::If:
        case MiniDecafParser::Inline:
        case MiniDecafParser::Int:
        case MiniDecafParser::Long:
        case MiniDecafParser::Register:
        case MiniDecafParser::Restrict:
        case MiniDecafParser::Return:
        case MiniDecafParser::Short:
        case MiniDecafParser::Signed:
        case MiniDecafParser::Sizeof:
        case MiniDecafParser::Static:
        case MiniDecafParser::Struct:
        case MiniDecafParser::Switch:
        case MiniDecafParser::Typedef:
        case MiniDecafParser::Union:
        case MiniDecafParser::Unsigned:
        case MiniDecafParser::Void:
        case MiniDecafParser::Volatile:
        case MiniDecafParser::While:
        case MiniDecafParser::Alignas:
        case MiniDecafParser::Alignof:
        case MiniDecafParser::Atomic:
        case MiniDecafParser::Bool:
        case MiniDecafParser::Complex:
        case MiniDecafParser::Generic:
        case MiniDecafParser::Imaginary:
        case MiniDecafParser::Noreturn:
        case MiniDecafParser::StaticAssert:
        case MiniDecafParser::ThreadLocal:
        case MiniDecafParser::LeftBracket:
        case MiniDecafParser::RightBracket:
        case MiniDecafParser::LeftBrace:
        case MiniDecafParser::RightBrace:
        case MiniDecafParser::Less:
        case MiniDecafParser::LessEqual:
        case MiniDecafParser::Greater:
        case MiniDecafParser::GreaterEqual:
        case MiniDecafParser::LeftShift:
        case MiniDecafParser::RightShift:
        case MiniDecafParser::Plus:
        case MiniDecafParser::PlusPlus:
        case MiniDecafParser::Minus:
        case MiniDecafParser::MinusMinus:
        case MiniDecafParser::Star:
        case MiniDecafParser::Div:
        case MiniDecafParser::Mod:
        case MiniDecafParser::And:
        case MiniDecafParser::Or:
        case MiniDecafParser::AndAnd:
        case MiniDecafParser::OrOr:
        case MiniDecafParser::Caret:
        case MiniDecafParser::Not:
        case MiniDecafParser::Tilde:
        case MiniDecafParser::Question:
        case MiniDecafParser::Colon:
        case MiniDecafParser::Semi:
        case MiniDecafParser::Comma:
        case MiniDecafParser::Assign:
        case MiniDecafParser::StarAssign:
        case MiniDecafParser::DivAssign:
        case MiniDecafParser::ModAssign:
        case MiniDecafParser::PlusAssign:
        case MiniDecafParser::MinusAssign:
        case MiniDecafParser::LeftShiftAssign:
        case MiniDecafParser::RightShiftAssign:
        case MiniDecafParser::AndAssign:
        case MiniDecafParser::XorAssign:
        case MiniDecafParser::OrAssign:
        case MiniDecafParser::Equal:
        case MiniDecafParser::NotEqual:
        case MiniDecafParser::Arrow:
        case MiniDecafParser::Dot:
        case MiniDecafParser::Ellipsis:
        case MiniDecafParser::Identifier:
        case MiniDecafParser::Constant:
        case MiniDecafParser::DigitSequence:
        case MiniDecafParser::StringLiteral:
        case MiniDecafParser::ComplexDefine:
        case MiniDecafParser::IncludeDirective:
        case MiniDecafParser::AsmBlock:
        case MiniDecafParser::LineAfterPreprocessing:
        case MiniDecafParser::LineDirective:
        case MiniDecafParser::PragmaDirective:
        case MiniDecafParser::Whitespace:
        case MiniDecafParser::Newline:
        case MiniDecafParser::BlockComment:
        case MiniDecafParser::LineComment: {
          setState(834);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == MiniDecafParser::LeftParen

          || _la == MiniDecafParser::RightParen)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case MiniDecafParser::LeftParen: {
          setState(835);
          match(MiniDecafParser::LeftParen);
          setState(836);
          nestedParenthesesBlock();
          setState(837);
          match(MiniDecafParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(843);
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

//----------------- PointerContext ------------------------------------------------------------------

MiniDecafParser::PointerContext::PointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::PointerContext::Star() {
  return getToken(MiniDecafParser::Star, 0);
}

MiniDecafParser::TypeQualifierListContext* MiniDecafParser::PointerContext::typeQualifierList() {
  return getRuleContext<MiniDecafParser::TypeQualifierListContext>(0);
}

MiniDecafParser::PointerContext* MiniDecafParser::PointerContext::pointer() {
  return getRuleContext<MiniDecafParser::PointerContext>(0);
}

tree::TerminalNode* MiniDecafParser::PointerContext::Caret() {
  return getToken(MiniDecafParser::Caret, 0);
}


size_t MiniDecafParser::PointerContext::getRuleIndex() const {
  return MiniDecafParser::RulePointer;
}


antlrcpp::Any MiniDecafParser::PointerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitPointer(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::PointerContext* MiniDecafParser::pointer() {
  PointerContext *_localctx = _tracker.createInstance<PointerContext>(_ctx, getState());
  enterRule(_localctx, 108, MiniDecafParser::RulePointer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(862);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(844);
      match(MiniDecafParser::Star);
      setState(846);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
      case 1: {
        setState(845);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(848);
      match(MiniDecafParser::Star);
      setState(850);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
        | (1ULL << MiniDecafParser::Restrict)
        | (1ULL << MiniDecafParser::Volatile)
        | (1ULL << MiniDecafParser::Atomic))) != 0)) {
        setState(849);
        typeQualifierList(0);
      }
      setState(852);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(853);
      match(MiniDecafParser::Caret);
      setState(855);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
      case 1: {
        setState(854);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(857);
      match(MiniDecafParser::Caret);
      setState(859);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
        | (1ULL << MiniDecafParser::Restrict)
        | (1ULL << MiniDecafParser::Volatile)
        | (1ULL << MiniDecafParser::Atomic))) != 0)) {
        setState(858);
        typeQualifierList(0);
      }
      setState(861);
      pointer();
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

//----------------- TypeQualifierListContext ------------------------------------------------------------------

MiniDecafParser::TypeQualifierListContext::TypeQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::TypeQualifierContext* MiniDecafParser::TypeQualifierListContext::typeQualifier() {
  return getRuleContext<MiniDecafParser::TypeQualifierContext>(0);
}

MiniDecafParser::TypeQualifierListContext* MiniDecafParser::TypeQualifierListContext::typeQualifierList() {
  return getRuleContext<MiniDecafParser::TypeQualifierListContext>(0);
}


size_t MiniDecafParser::TypeQualifierListContext::getRuleIndex() const {
  return MiniDecafParser::RuleTypeQualifierList;
}


antlrcpp::Any MiniDecafParser::TypeQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTypeQualifierList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::TypeQualifierListContext* MiniDecafParser::typeQualifierList() {
   return typeQualifierList(0);
}

MiniDecafParser::TypeQualifierListContext* MiniDecafParser::typeQualifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::TypeQualifierListContext *_localctx = _tracker.createInstance<TypeQualifierListContext>(_ctx, parentState);
  MiniDecafParser::TypeQualifierListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 110;
  enterRecursionRule(_localctx, 110, MiniDecafParser::RuleTypeQualifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(865);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(871);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(867);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(868);
        typeQualifier(); 
      }
      setState(873);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

MiniDecafParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ParameterListContext* MiniDecafParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<MiniDecafParser::ParameterListContext>(0);
}

tree::TerminalNode* MiniDecafParser::ParameterTypeListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

tree::TerminalNode* MiniDecafParser::ParameterTypeListContext::Ellipsis() {
  return getToken(MiniDecafParser::Ellipsis, 0);
}


size_t MiniDecafParser::ParameterTypeListContext::getRuleIndex() const {
  return MiniDecafParser::RuleParameterTypeList;
}


antlrcpp::Any MiniDecafParser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ParameterTypeListContext* MiniDecafParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 112, MiniDecafParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(879);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(874);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(875);
      parameterList(0);
      setState(876);
      match(MiniDecafParser::Comma);
      setState(877);
      match(MiniDecafParser::Ellipsis);
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

//----------------- ParameterListContext ------------------------------------------------------------------

MiniDecafParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ParameterDeclarationContext* MiniDecafParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<MiniDecafParser::ParameterDeclarationContext>(0);
}

MiniDecafParser::ParameterListContext* MiniDecafParser::ParameterListContext::parameterList() {
  return getRuleContext<MiniDecafParser::ParameterListContext>(0);
}

tree::TerminalNode* MiniDecafParser::ParameterListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::ParameterListContext::getRuleIndex() const {
  return MiniDecafParser::RuleParameterList;
}


antlrcpp::Any MiniDecafParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ParameterListContext* MiniDecafParser::parameterList() {
   return parameterList(0);
}

MiniDecafParser::ParameterListContext* MiniDecafParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  MiniDecafParser::ParameterListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 114;
  enterRecursionRule(_localctx, 114, MiniDecafParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(882);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(889);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(884);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(885);
        match(MiniDecafParser::Comma);
        setState(886);
        parameterDeclaration(); 
      }
      setState(891);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

MiniDecafParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclarationSpecifiersContext* MiniDecafParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<MiniDecafParser::DeclarationSpecifiersContext>(0);
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<MiniDecafParser::DeclaratorContext>(0);
}

MiniDecafParser::DeclarationSpecifiers2Context* MiniDecafParser::ParameterDeclarationContext::declarationSpecifiers2() {
  return getRuleContext<MiniDecafParser::DeclarationSpecifiers2Context>(0);
}

MiniDecafParser::AbstractDeclaratorContext* MiniDecafParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<MiniDecafParser::AbstractDeclaratorContext>(0);
}


size_t MiniDecafParser::ParameterDeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleParameterDeclaration;
}


antlrcpp::Any MiniDecafParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ParameterDeclarationContext* MiniDecafParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 116, MiniDecafParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(899);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(892);
      declarationSpecifiers();
      setState(893);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(895);
      declarationSpecifiers2();
      setState(897);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
      case 1: {
        setState(896);
        abstractDeclarator();
        break;
      }

      }
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

//----------------- IdentifierListContext ------------------------------------------------------------------

MiniDecafParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::IdentifierListContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

MiniDecafParser::IdentifierListContext* MiniDecafParser::IdentifierListContext::identifierList() {
  return getRuleContext<MiniDecafParser::IdentifierListContext>(0);
}

tree::TerminalNode* MiniDecafParser::IdentifierListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::IdentifierListContext::getRuleIndex() const {
  return MiniDecafParser::RuleIdentifierList;
}


antlrcpp::Any MiniDecafParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::IdentifierListContext* MiniDecafParser::identifierList() {
   return identifierList(0);
}

MiniDecafParser::IdentifierListContext* MiniDecafParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  MiniDecafParser::IdentifierListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 118;
  enterRecursionRule(_localctx, 118, MiniDecafParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(902);
    match(MiniDecafParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(909);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(904);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(905);
        match(MiniDecafParser::Comma);
        setState(906);
        match(MiniDecafParser::Identifier); 
      }
      setState(911);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

MiniDecafParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::SpecifierQualifierListContext* MiniDecafParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<MiniDecafParser::SpecifierQualifierListContext>(0);
}

MiniDecafParser::AbstractDeclaratorContext* MiniDecafParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<MiniDecafParser::AbstractDeclaratorContext>(0);
}


size_t MiniDecafParser::TypeNameContext::getRuleIndex() const {
  return MiniDecafParser::RuleTypeName;
}


antlrcpp::Any MiniDecafParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::TypeNameContext* MiniDecafParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 120, MiniDecafParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(912);
    specifierQualifierList();
    setState(914);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (MiniDecafParser::LeftParen - 59))
      | (1ULL << (MiniDecafParser::LeftBracket - 59))
      | (1ULL << (MiniDecafParser::Star - 59))
      | (1ULL << (MiniDecafParser::Caret - 59)))) != 0)) {
      setState(913);
      abstractDeclarator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

MiniDecafParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::PointerContext* MiniDecafParser::AbstractDeclaratorContext::pointer() {
  return getRuleContext<MiniDecafParser::PointerContext>(0);
}

MiniDecafParser::DirectAbstractDeclaratorContext* MiniDecafParser::AbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<MiniDecafParser::DirectAbstractDeclaratorContext>(0);
}

std::vector<MiniDecafParser::GccDeclaratorExtensionContext *> MiniDecafParser::AbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<MiniDecafParser::GccDeclaratorExtensionContext>();
}

MiniDecafParser::GccDeclaratorExtensionContext* MiniDecafParser::AbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<MiniDecafParser::GccDeclaratorExtensionContext>(i);
}


size_t MiniDecafParser::AbstractDeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleAbstractDeclarator;
}


antlrcpp::Any MiniDecafParser::AbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::AbstractDeclaratorContext* MiniDecafParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 122, MiniDecafParser::RuleAbstractDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(927);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(916);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(918);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniDecafParser::Star

      || _la == MiniDecafParser::Caret) {
        setState(917);
        pointer();
      }
      setState(920);
      directAbstractDeclarator(0);
      setState(924);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(921);
          gccDeclaratorExtension(); 
        }
        setState(926);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      }
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

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

MiniDecafParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::AbstractDeclaratorContext* MiniDecafParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<MiniDecafParser::AbstractDeclaratorContext>(0);
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

std::vector<MiniDecafParser::GccDeclaratorExtensionContext *> MiniDecafParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<MiniDecafParser::GccDeclaratorExtensionContext>();
}

MiniDecafParser::GccDeclaratorExtensionContext* MiniDecafParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<MiniDecafParser::GccDeclaratorExtensionContext>(i);
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::LeftBracket() {
  return getToken(MiniDecafParser::LeftBracket, 0);
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::RightBracket() {
  return getToken(MiniDecafParser::RightBracket, 0);
}

MiniDecafParser::TypeQualifierListContext* MiniDecafParser::DirectAbstractDeclaratorContext::typeQualifierList() {
  return getRuleContext<MiniDecafParser::TypeQualifierListContext>(0);
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::DirectAbstractDeclaratorContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::Static() {
  return getToken(MiniDecafParser::Static, 0);
}

tree::TerminalNode* MiniDecafParser::DirectAbstractDeclaratorContext::Star() {
  return getToken(MiniDecafParser::Star, 0);
}

MiniDecafParser::ParameterTypeListContext* MiniDecafParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<MiniDecafParser::ParameterTypeListContext>(0);
}

MiniDecafParser::DirectAbstractDeclaratorContext* MiniDecafParser::DirectAbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<MiniDecafParser::DirectAbstractDeclaratorContext>(0);
}


size_t MiniDecafParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return MiniDecafParser::RuleDirectAbstractDeclarator;
}


antlrcpp::Any MiniDecafParser::DirectAbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::DirectAbstractDeclaratorContext* MiniDecafParser::directAbstractDeclarator() {
   return directAbstractDeclarator(0);
}

MiniDecafParser::DirectAbstractDeclaratorContext* MiniDecafParser::directAbstractDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, parentState);
  MiniDecafParser::DirectAbstractDeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 124;
  enterRecursionRule(_localctx, 124, MiniDecafParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(975);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      setState(930);
      match(MiniDecafParser::LeftParen);
      setState(931);
      abstractDeclarator();
      setState(932);
      match(MiniDecafParser::RightParen);
      setState(936);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(933);
          gccDeclaratorExtension(); 
        }
        setState(938);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      break;
    }

    case 2: {
      setState(939);
      match(MiniDecafParser::LeftBracket);
      setState(941);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
        | (1ULL << MiniDecafParser::Restrict)
        | (1ULL << MiniDecafParser::Volatile)
        | (1ULL << MiniDecafParser::Atomic))) != 0)) {
        setState(940);
        typeQualifierList(0);
      }
      setState(944);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(943);
        assignmentExpression();
      }
      setState(946);
      match(MiniDecafParser::RightBracket);
      break;
    }

    case 3: {
      setState(947);
      match(MiniDecafParser::LeftBracket);
      setState(948);
      match(MiniDecafParser::Static);
      setState(950);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
        | (1ULL << MiniDecafParser::Restrict)
        | (1ULL << MiniDecafParser::Volatile)
        | (1ULL << MiniDecafParser::Atomic))) != 0)) {
        setState(949);
        typeQualifierList(0);
      }
      setState(952);
      assignmentExpression();
      setState(953);
      match(MiniDecafParser::RightBracket);
      break;
    }

    case 4: {
      setState(955);
      match(MiniDecafParser::LeftBracket);
      setState(956);
      typeQualifierList(0);
      setState(957);
      match(MiniDecafParser::Static);
      setState(958);
      assignmentExpression();
      setState(959);
      match(MiniDecafParser::RightBracket);
      break;
    }

    case 5: {
      setState(961);
      match(MiniDecafParser::LeftBracket);
      setState(962);
      match(MiniDecafParser::Star);
      setState(963);
      match(MiniDecafParser::RightBracket);
      break;
    }

    case 6: {
      setState(964);
      match(MiniDecafParser::LeftParen);
      setState(966);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__3)
        | (1ULL << MiniDecafParser::T__4)
        | (1ULL << MiniDecafParser::T__5)
        | (1ULL << MiniDecafParser::T__6)
        | (1ULL << MiniDecafParser::T__7)
        | (1ULL << MiniDecafParser::T__8)
        | (1ULL << MiniDecafParser::T__9)
        | (1ULL << MiniDecafParser::T__11)
        | (1ULL << MiniDecafParser::Auto)
        | (1ULL << MiniDecafParser::Char)
        | (1ULL << MiniDecafParser::Const)
        | (1ULL << MiniDecafParser::Double)
        | (1ULL << MiniDecafParser::Enum)
        | (1ULL << MiniDecafParser::Extern)
        | (1ULL << MiniDecafParser::Float)
        | (1ULL << MiniDecafParser::Inline)
        | (1ULL << MiniDecafParser::Int)
        | (1ULL << MiniDecafParser::Long)
        | (1ULL << MiniDecafParser::Register)
        | (1ULL << MiniDecafParser::Restrict)
        | (1ULL << MiniDecafParser::Short)
        | (1ULL << MiniDecafParser::Signed)
        | (1ULL << MiniDecafParser::Static)
        | (1ULL << MiniDecafParser::Struct)
        | (1ULL << MiniDecafParser::Typedef)
        | (1ULL << MiniDecafParser::Union)
        | (1ULL << MiniDecafParser::Unsigned)
        | (1ULL << MiniDecafParser::Void)
        | (1ULL << MiniDecafParser::Volatile)
        | (1ULL << MiniDecafParser::Alignas)
        | (1ULL << MiniDecafParser::Atomic)
        | (1ULL << MiniDecafParser::Bool)
        | (1ULL << MiniDecafParser::Complex)
        | (1ULL << MiniDecafParser::Noreturn)
        | (1ULL << MiniDecafParser::ThreadLocal))) != 0) || _la == MiniDecafParser::Identifier) {
        setState(965);
        parameterTypeList();
      }
      setState(968);
      match(MiniDecafParser::RightParen);
      setState(972);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(969);
          gccDeclaratorExtension(); 
        }
        setState(974);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
      }
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1020);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1018);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(977);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(978);
          match(MiniDecafParser::LeftBracket);
          setState(980);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Atomic))) != 0)) {
            setState(979);
            typeQualifierList(0);
          }
          setState(983);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
            | (1ULL << MiniDecafParser::T__1)
            | (1ULL << MiniDecafParser::T__2)
            | (1ULL << MiniDecafParser::Sizeof)
            | (1ULL << MiniDecafParser::Alignof)
            | (1ULL << MiniDecafParser::Generic)
            | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
            | (1ULL << (MiniDecafParser::PlusPlus - 71))
            | (1ULL << (MiniDecafParser::Minus - 71))
            | (1ULL << (MiniDecafParser::MinusMinus - 71))
            | (1ULL << (MiniDecafParser::Star - 71))
            | (1ULL << (MiniDecafParser::And - 71))
            | (1ULL << (MiniDecafParser::AndAnd - 71))
            | (1ULL << (MiniDecafParser::Not - 71))
            | (1ULL << (MiniDecafParser::Tilde - 71))
            | (1ULL << (MiniDecafParser::Identifier - 71))
            | (1ULL << (MiniDecafParser::Constant - 71))
            | (1ULL << (MiniDecafParser::DigitSequence - 71))
            | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
            setState(982);
            assignmentExpression();
          }
          setState(985);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(986);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(987);
          match(MiniDecafParser::LeftBracket);
          setState(988);
          match(MiniDecafParser::Static);
          setState(990);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Atomic))) != 0)) {
            setState(989);
            typeQualifierList(0);
          }
          setState(992);
          assignmentExpression();
          setState(993);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(995);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(996);
          match(MiniDecafParser::LeftBracket);
          setState(997);
          typeQualifierList(0);
          setState(998);
          match(MiniDecafParser::Static);
          setState(999);
          assignmentExpression();
          setState(1000);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1002);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1003);
          match(MiniDecafParser::LeftBracket);
          setState(1004);
          match(MiniDecafParser::Star);
          setState(1005);
          match(MiniDecafParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1006);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1007);
          match(MiniDecafParser::LeftParen);
          setState(1009);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
            | (1ULL << MiniDecafParser::T__3)
            | (1ULL << MiniDecafParser::T__4)
            | (1ULL << MiniDecafParser::T__5)
            | (1ULL << MiniDecafParser::T__6)
            | (1ULL << MiniDecafParser::T__7)
            | (1ULL << MiniDecafParser::T__8)
            | (1ULL << MiniDecafParser::T__9)
            | (1ULL << MiniDecafParser::T__11)
            | (1ULL << MiniDecafParser::Auto)
            | (1ULL << MiniDecafParser::Char)
            | (1ULL << MiniDecafParser::Const)
            | (1ULL << MiniDecafParser::Double)
            | (1ULL << MiniDecafParser::Enum)
            | (1ULL << MiniDecafParser::Extern)
            | (1ULL << MiniDecafParser::Float)
            | (1ULL << MiniDecafParser::Inline)
            | (1ULL << MiniDecafParser::Int)
            | (1ULL << MiniDecafParser::Long)
            | (1ULL << MiniDecafParser::Register)
            | (1ULL << MiniDecafParser::Restrict)
            | (1ULL << MiniDecafParser::Short)
            | (1ULL << MiniDecafParser::Signed)
            | (1ULL << MiniDecafParser::Static)
            | (1ULL << MiniDecafParser::Struct)
            | (1ULL << MiniDecafParser::Typedef)
            | (1ULL << MiniDecafParser::Union)
            | (1ULL << MiniDecafParser::Unsigned)
            | (1ULL << MiniDecafParser::Void)
            | (1ULL << MiniDecafParser::Volatile)
            | (1ULL << MiniDecafParser::Alignas)
            | (1ULL << MiniDecafParser::Atomic)
            | (1ULL << MiniDecafParser::Bool)
            | (1ULL << MiniDecafParser::Complex)
            | (1ULL << MiniDecafParser::Noreturn)
            | (1ULL << MiniDecafParser::ThreadLocal))) != 0) || _la == MiniDecafParser::Identifier) {
            setState(1008);
            parameterTypeList();
          }
          setState(1011);
          match(MiniDecafParser::RightParen);
          setState(1015);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(1012);
              gccDeclaratorExtension(); 
            }
            setState(1017);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
          }
          break;
        }

        } 
      }
      setState(1022);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypedefNameContext ------------------------------------------------------------------

MiniDecafParser::TypedefNameContext::TypedefNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::TypedefNameContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}


size_t MiniDecafParser::TypedefNameContext::getRuleIndex() const {
  return MiniDecafParser::RuleTypedefName;
}


antlrcpp::Any MiniDecafParser::TypedefNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTypedefName(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::TypedefNameContext* MiniDecafParser::typedefName() {
  TypedefNameContext *_localctx = _tracker.createInstance<TypedefNameContext>(_ctx, getState());
  enterRule(_localctx, 126, MiniDecafParser::RuleTypedefName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1023);
    match(MiniDecafParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

MiniDecafParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::InitializerContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::InitializerContext::LeftBrace() {
  return getToken(MiniDecafParser::LeftBrace, 0);
}

MiniDecafParser::InitializerListContext* MiniDecafParser::InitializerContext::initializerList() {
  return getRuleContext<MiniDecafParser::InitializerListContext>(0);
}

tree::TerminalNode* MiniDecafParser::InitializerContext::RightBrace() {
  return getToken(MiniDecafParser::RightBrace, 0);
}

tree::TerminalNode* MiniDecafParser::InitializerContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::InitializerContext::getRuleIndex() const {
  return MiniDecafParser::RuleInitializer;
}


antlrcpp::Any MiniDecafParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::InitializerContext* MiniDecafParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 128, MiniDecafParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1035);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1025);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1026);
      match(MiniDecafParser::LeftBrace);
      setState(1027);
      initializerList(0);
      setState(1028);
      match(MiniDecafParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1030);
      match(MiniDecafParser::LeftBrace);
      setState(1031);
      initializerList(0);
      setState(1032);
      match(MiniDecafParser::Comma);
      setState(1033);
      match(MiniDecafParser::RightBrace);
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

//----------------- InitializerListContext ------------------------------------------------------------------

MiniDecafParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::InitializerContext* MiniDecafParser::InitializerListContext::initializer() {
  return getRuleContext<MiniDecafParser::InitializerContext>(0);
}

MiniDecafParser::DesignationContext* MiniDecafParser::InitializerListContext::designation() {
  return getRuleContext<MiniDecafParser::DesignationContext>(0);
}

MiniDecafParser::InitializerListContext* MiniDecafParser::InitializerListContext::initializerList() {
  return getRuleContext<MiniDecafParser::InitializerListContext>(0);
}

tree::TerminalNode* MiniDecafParser::InitializerListContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::InitializerListContext::getRuleIndex() const {
  return MiniDecafParser::RuleInitializerList;
}


antlrcpp::Any MiniDecafParser::InitializerListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitInitializerList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::InitializerListContext* MiniDecafParser::initializerList() {
   return initializerList(0);
}

MiniDecafParser::InitializerListContext* MiniDecafParser::initializerList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, parentState);
  MiniDecafParser::InitializerListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, MiniDecafParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1039);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MiniDecafParser::LeftBracket

    || _la == MiniDecafParser::Dot) {
      setState(1038);
      designation();
    }
    setState(1041);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(1051);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(1043);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1044);
        match(MiniDecafParser::Comma);
        setState(1046);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MiniDecafParser::LeftBracket

        || _la == MiniDecafParser::Dot) {
          setState(1045);
          designation();
        }
        setState(1048);
        initializer(); 
      }
      setState(1053);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

MiniDecafParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DesignatorListContext* MiniDecafParser::DesignationContext::designatorList() {
  return getRuleContext<MiniDecafParser::DesignatorListContext>(0);
}

tree::TerminalNode* MiniDecafParser::DesignationContext::Assign() {
  return getToken(MiniDecafParser::Assign, 0);
}


size_t MiniDecafParser::DesignationContext::getRuleIndex() const {
  return MiniDecafParser::RuleDesignation;
}


antlrcpp::Any MiniDecafParser::DesignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDesignation(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DesignationContext* MiniDecafParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 132, MiniDecafParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1054);
    designatorList(0);
    setState(1055);
    match(MiniDecafParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

MiniDecafParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DesignatorContext* MiniDecafParser::DesignatorListContext::designator() {
  return getRuleContext<MiniDecafParser::DesignatorContext>(0);
}

MiniDecafParser::DesignatorListContext* MiniDecafParser::DesignatorListContext::designatorList() {
  return getRuleContext<MiniDecafParser::DesignatorListContext>(0);
}


size_t MiniDecafParser::DesignatorListContext::getRuleIndex() const {
  return MiniDecafParser::RuleDesignatorList;
}


antlrcpp::Any MiniDecafParser::DesignatorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDesignatorList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::DesignatorListContext* MiniDecafParser::designatorList() {
   return designatorList(0);
}

MiniDecafParser::DesignatorListContext* MiniDecafParser::designatorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, parentState);
  MiniDecafParser::DesignatorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 134;
  enterRecursionRule(_localctx, 134, MiniDecafParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1058);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(1064);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(1060);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1061);
        designator(); 
      }
      setState(1066);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

MiniDecafParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::DesignatorContext::LeftBracket() {
  return getToken(MiniDecafParser::LeftBracket, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::DesignatorContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::DesignatorContext::RightBracket() {
  return getToken(MiniDecafParser::RightBracket, 0);
}

tree::TerminalNode* MiniDecafParser::DesignatorContext::Dot() {
  return getToken(MiniDecafParser::Dot, 0);
}

tree::TerminalNode* MiniDecafParser::DesignatorContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}


size_t MiniDecafParser::DesignatorContext::getRuleIndex() const {
  return MiniDecafParser::RuleDesignator;
}


antlrcpp::Any MiniDecafParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::DesignatorContext* MiniDecafParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 136, MiniDecafParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1073);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(1067);
        match(MiniDecafParser::LeftBracket);
        setState(1068);
        constantExpression();
        setState(1069);
        match(MiniDecafParser::RightBracket);
        break;
      }

      case MiniDecafParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(1071);
        match(MiniDecafParser::Dot);
        setState(1072);
        match(MiniDecafParser::Identifier);
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

//----------------- StaticAssertDeclarationContext ------------------------------------------------------------------

MiniDecafParser::StaticAssertDeclarationContext::StaticAssertDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::StaticAssert() {
  return getToken(MiniDecafParser::StaticAssert, 0);
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::StaticAssertDeclarationContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::StaticAssertDeclarationContext::StringLiteral() {
  return getTokens(MiniDecafParser::StringLiteral);
}

tree::TerminalNode* MiniDecafParser::StaticAssertDeclarationContext::StringLiteral(size_t i) {
  return getToken(MiniDecafParser::StringLiteral, i);
}


size_t MiniDecafParser::StaticAssertDeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleStaticAssertDeclaration;
}


antlrcpp::Any MiniDecafParser::StaticAssertDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStaticAssertDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StaticAssertDeclarationContext* MiniDecafParser::staticAssertDeclaration() {
  StaticAssertDeclarationContext *_localctx = _tracker.createInstance<StaticAssertDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 138, MiniDecafParser::RuleStaticAssertDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1075);
    match(MiniDecafParser::StaticAssert);
    setState(1076);
    match(MiniDecafParser::LeftParen);
    setState(1077);
    constantExpression();
    setState(1078);
    match(MiniDecafParser::Comma);
    setState(1080); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1079);
      match(MiniDecafParser::StringLiteral);
      setState(1082); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MiniDecafParser::StringLiteral);
    setState(1084);
    match(MiniDecafParser::RightParen);
    setState(1085);
    match(MiniDecafParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MiniDecafParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::LabeledStatementContext* MiniDecafParser::StatementContext::labeledStatement() {
  return getRuleContext<MiniDecafParser::LabeledStatementContext>(0);
}

MiniDecafParser::CompoundStatementContext* MiniDecafParser::StatementContext::compoundStatement() {
  return getRuleContext<MiniDecafParser::CompoundStatementContext>(0);
}

MiniDecafParser::ExpressionStatementContext* MiniDecafParser::StatementContext::expressionStatement() {
  return getRuleContext<MiniDecafParser::ExpressionStatementContext>(0);
}

MiniDecafParser::SelectionStatementContext* MiniDecafParser::StatementContext::selectionStatement() {
  return getRuleContext<MiniDecafParser::SelectionStatementContext>(0);
}

MiniDecafParser::IterationStatementContext* MiniDecafParser::StatementContext::iterationStatement() {
  return getRuleContext<MiniDecafParser::IterationStatementContext>(0);
}

MiniDecafParser::JumpStatementContext* MiniDecafParser::StatementContext::jumpStatement() {
  return getRuleContext<MiniDecafParser::JumpStatementContext>(0);
}

tree::TerminalNode* MiniDecafParser::StatementContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

tree::TerminalNode* MiniDecafParser::StatementContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

tree::TerminalNode* MiniDecafParser::StatementContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

tree::TerminalNode* MiniDecafParser::StatementContext::Volatile() {
  return getToken(MiniDecafParser::Volatile, 0);
}

std::vector<MiniDecafParser::LogicalOrExpressionContext *> MiniDecafParser::StatementContext::logicalOrExpression() {
  return getRuleContexts<MiniDecafParser::LogicalOrExpressionContext>();
}

MiniDecafParser::LogicalOrExpressionContext* MiniDecafParser::StatementContext::logicalOrExpression(size_t i) {
  return getRuleContext<MiniDecafParser::LogicalOrExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::StatementContext::Colon() {
  return getTokens(MiniDecafParser::Colon);
}

tree::TerminalNode* MiniDecafParser::StatementContext::Colon(size_t i) {
  return getToken(MiniDecafParser::Colon, i);
}

std::vector<tree::TerminalNode *> MiniDecafParser::StatementContext::Comma() {
  return getTokens(MiniDecafParser::Comma);
}

tree::TerminalNode* MiniDecafParser::StatementContext::Comma(size_t i) {
  return getToken(MiniDecafParser::Comma, i);
}


size_t MiniDecafParser::StatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleStatement;
}


antlrcpp::Any MiniDecafParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::StatementContext* MiniDecafParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 140, MiniDecafParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1087);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1088);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1089);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1090);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1091);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1092);
      jumpStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1093);
      _la = _input->LA(1);
      if (!(_la == MiniDecafParser::T__10

      || _la == MiniDecafParser::T__12)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1094);
      _la = _input->LA(1);
      if (!(_la == MiniDecafParser::T__13

      || _la == MiniDecafParser::Volatile)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1095);
      match(MiniDecafParser::LeftParen);
      setState(1104);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1096);
        logicalOrExpression(0);
        setState(1101);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MiniDecafParser::Comma) {
          setState(1097);
          match(MiniDecafParser::Comma);
          setState(1098);
          logicalOrExpression(0);
          setState(1103);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1119);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MiniDecafParser::Colon) {
        setState(1106);
        match(MiniDecafParser::Colon);
        setState(1115);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
          | (1ULL << MiniDecafParser::T__1)
          | (1ULL << MiniDecafParser::T__2)
          | (1ULL << MiniDecafParser::Sizeof)
          | (1ULL << MiniDecafParser::Alignof)
          | (1ULL << MiniDecafParser::Generic)
          | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
          | (1ULL << (MiniDecafParser::PlusPlus - 71))
          | (1ULL << (MiniDecafParser::Minus - 71))
          | (1ULL << (MiniDecafParser::MinusMinus - 71))
          | (1ULL << (MiniDecafParser::Star - 71))
          | (1ULL << (MiniDecafParser::And - 71))
          | (1ULL << (MiniDecafParser::AndAnd - 71))
          | (1ULL << (MiniDecafParser::Not - 71))
          | (1ULL << (MiniDecafParser::Tilde - 71))
          | (1ULL << (MiniDecafParser::Identifier - 71))
          | (1ULL << (MiniDecafParser::Constant - 71))
          | (1ULL << (MiniDecafParser::DigitSequence - 71))
          | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
          setState(1107);
          logicalOrExpression(0);
          setState(1112);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MiniDecafParser::Comma) {
            setState(1108);
            match(MiniDecafParser::Comma);
            setState(1109);
            logicalOrExpression(0);
            setState(1114);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(1121);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1122);
      match(MiniDecafParser::RightParen);
      setState(1123);
      match(MiniDecafParser::Semi);
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

//----------------- LabeledStatementContext ------------------------------------------------------------------

MiniDecafParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::LabeledStatementContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::LabeledStatementContext::Colon() {
  return getToken(MiniDecafParser::Colon, 0);
}

MiniDecafParser::StatementContext* MiniDecafParser::LabeledStatementContext::statement() {
  return getRuleContext<MiniDecafParser::StatementContext>(0);
}

tree::TerminalNode* MiniDecafParser::LabeledStatementContext::Case() {
  return getToken(MiniDecafParser::Case, 0);
}

MiniDecafParser::ConstantExpressionContext* MiniDecafParser::LabeledStatementContext::constantExpression() {
  return getRuleContext<MiniDecafParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::LabeledStatementContext::Default() {
  return getToken(MiniDecafParser::Default, 0);
}


size_t MiniDecafParser::LabeledStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleLabeledStatement;
}


antlrcpp::Any MiniDecafParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::LabeledStatementContext* MiniDecafParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 142, MiniDecafParser::RuleLabeledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(1126);
        match(MiniDecafParser::Identifier);
        setState(1127);
        match(MiniDecafParser::Colon);
        setState(1128);
        statement();
        break;
      }

      case MiniDecafParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(1129);
        match(MiniDecafParser::Case);
        setState(1130);
        constantExpression();
        setState(1131);
        match(MiniDecafParser::Colon);
        setState(1132);
        statement();
        break;
      }

      case MiniDecafParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(1134);
        match(MiniDecafParser::Default);
        setState(1135);
        match(MiniDecafParser::Colon);
        setState(1136);
        statement();
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

//----------------- CompoundStatementContext ------------------------------------------------------------------

MiniDecafParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::CompoundStatementContext::LeftBrace() {
  return getToken(MiniDecafParser::LeftBrace, 0);
}

tree::TerminalNode* MiniDecafParser::CompoundStatementContext::RightBrace() {
  return getToken(MiniDecafParser::RightBrace, 0);
}

MiniDecafParser::BlockItemListContext* MiniDecafParser::CompoundStatementContext::blockItemList() {
  return getRuleContext<MiniDecafParser::BlockItemListContext>(0);
}


size_t MiniDecafParser::CompoundStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleCompoundStatement;
}


antlrcpp::Any MiniDecafParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::CompoundStatementContext* MiniDecafParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 144, MiniDecafParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1139);
    match(MiniDecafParser::LeftBrace);
    setState(1141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
      | (1ULL << MiniDecafParser::T__1)
      | (1ULL << MiniDecafParser::T__2)
      | (1ULL << MiniDecafParser::T__3)
      | (1ULL << MiniDecafParser::T__4)
      | (1ULL << MiniDecafParser::T__5)
      | (1ULL << MiniDecafParser::T__6)
      | (1ULL << MiniDecafParser::T__7)
      | (1ULL << MiniDecafParser::T__8)
      | (1ULL << MiniDecafParser::T__9)
      | (1ULL << MiniDecafParser::T__10)
      | (1ULL << MiniDecafParser::T__11)
      | (1ULL << MiniDecafParser::T__12)
      | (1ULL << MiniDecafParser::Auto)
      | (1ULL << MiniDecafParser::Break)
      | (1ULL << MiniDecafParser::Case)
      | (1ULL << MiniDecafParser::Char)
      | (1ULL << MiniDecafParser::Const)
      | (1ULL << MiniDecafParser::Continue)
      | (1ULL << MiniDecafParser::Default)
      | (1ULL << MiniDecafParser::Do)
      | (1ULL << MiniDecafParser::Double)
      | (1ULL << MiniDecafParser::Enum)
      | (1ULL << MiniDecafParser::Extern)
      | (1ULL << MiniDecafParser::Float)
      | (1ULL << MiniDecafParser::For)
      | (1ULL << MiniDecafParser::Goto)
      | (1ULL << MiniDecafParser::If)
      | (1ULL << MiniDecafParser::Inline)
      | (1ULL << MiniDecafParser::Int)
      | (1ULL << MiniDecafParser::Long)
      | (1ULL << MiniDecafParser::Register)
      | (1ULL << MiniDecafParser::Restrict)
      | (1ULL << MiniDecafParser::Return)
      | (1ULL << MiniDecafParser::Short)
      | (1ULL << MiniDecafParser::Signed)
      | (1ULL << MiniDecafParser::Sizeof)
      | (1ULL << MiniDecafParser::Static)
      | (1ULL << MiniDecafParser::Struct)
      | (1ULL << MiniDecafParser::Switch)
      | (1ULL << MiniDecafParser::Typedef)
      | (1ULL << MiniDecafParser::Union)
      | (1ULL << MiniDecafParser::Unsigned)
      | (1ULL << MiniDecafParser::Void)
      | (1ULL << MiniDecafParser::Volatile)
      | (1ULL << MiniDecafParser::While)
      | (1ULL << MiniDecafParser::Alignas)
      | (1ULL << MiniDecafParser::Alignof)
      | (1ULL << MiniDecafParser::Atomic)
      | (1ULL << MiniDecafParser::Bool)
      | (1ULL << MiniDecafParser::Complex)
      | (1ULL << MiniDecafParser::Generic)
      | (1ULL << MiniDecafParser::Noreturn)
      | (1ULL << MiniDecafParser::StaticAssert)
      | (1ULL << MiniDecafParser::ThreadLocal)
      | (1ULL << MiniDecafParser::LeftParen)
      | (1ULL << MiniDecafParser::LeftBrace))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
      | (1ULL << (MiniDecafParser::PlusPlus - 71))
      | (1ULL << (MiniDecafParser::Minus - 71))
      | (1ULL << (MiniDecafParser::MinusMinus - 71))
      | (1ULL << (MiniDecafParser::Star - 71))
      | (1ULL << (MiniDecafParser::And - 71))
      | (1ULL << (MiniDecafParser::AndAnd - 71))
      | (1ULL << (MiniDecafParser::Not - 71))
      | (1ULL << (MiniDecafParser::Tilde - 71))
      | (1ULL << (MiniDecafParser::Semi - 71))
      | (1ULL << (MiniDecafParser::Identifier - 71))
      | (1ULL << (MiniDecafParser::Constant - 71))
      | (1ULL << (MiniDecafParser::DigitSequence - 71))
      | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
      setState(1140);
      blockItemList(0);
    }
    setState(1143);
    match(MiniDecafParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

MiniDecafParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::BlockItemContext* MiniDecafParser::BlockItemListContext::blockItem() {
  return getRuleContext<MiniDecafParser::BlockItemContext>(0);
}

MiniDecafParser::BlockItemListContext* MiniDecafParser::BlockItemListContext::blockItemList() {
  return getRuleContext<MiniDecafParser::BlockItemListContext>(0);
}


size_t MiniDecafParser::BlockItemListContext::getRuleIndex() const {
  return MiniDecafParser::RuleBlockItemList;
}


antlrcpp::Any MiniDecafParser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::BlockItemListContext* MiniDecafParser::blockItemList() {
   return blockItemList(0);
}

MiniDecafParser::BlockItemListContext* MiniDecafParser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  MiniDecafParser::BlockItemListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 146;
  enterRecursionRule(_localctx, 146, MiniDecafParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1146);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(1152);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(1148);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1149);
        blockItem(); 
      }
      setState(1154);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

MiniDecafParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::StatementContext* MiniDecafParser::BlockItemContext::statement() {
  return getRuleContext<MiniDecafParser::StatementContext>(0);
}

MiniDecafParser::DeclarationContext* MiniDecafParser::BlockItemContext::declaration() {
  return getRuleContext<MiniDecafParser::DeclarationContext>(0);
}


size_t MiniDecafParser::BlockItemContext::getRuleIndex() const {
  return MiniDecafParser::RuleBlockItem;
}


antlrcpp::Any MiniDecafParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::BlockItemContext* MiniDecafParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 148, MiniDecafParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1155);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1156);
      declaration();
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

//----------------- ExpressionStatementContext ------------------------------------------------------------------

MiniDecafParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::ExpressionStatementContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::ExpressionStatementContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}


size_t MiniDecafParser::ExpressionStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleExpressionStatement;
}


antlrcpp::Any MiniDecafParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ExpressionStatementContext* MiniDecafParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 150, MiniDecafParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
      | (1ULL << MiniDecafParser::T__1)
      | (1ULL << MiniDecafParser::T__2)
      | (1ULL << MiniDecafParser::Sizeof)
      | (1ULL << MiniDecafParser::Alignof)
      | (1ULL << MiniDecafParser::Generic)
      | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
      | (1ULL << (MiniDecafParser::PlusPlus - 71))
      | (1ULL << (MiniDecafParser::Minus - 71))
      | (1ULL << (MiniDecafParser::MinusMinus - 71))
      | (1ULL << (MiniDecafParser::Star - 71))
      | (1ULL << (MiniDecafParser::And - 71))
      | (1ULL << (MiniDecafParser::AndAnd - 71))
      | (1ULL << (MiniDecafParser::Not - 71))
      | (1ULL << (MiniDecafParser::Tilde - 71))
      | (1ULL << (MiniDecafParser::Identifier - 71))
      | (1ULL << (MiniDecafParser::Constant - 71))
      | (1ULL << (MiniDecafParser::DigitSequence - 71))
      | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
      setState(1159);
      expression(0);
    }
    setState(1162);
    match(MiniDecafParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

MiniDecafParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::SelectionStatementContext::If() {
  return getToken(MiniDecafParser::If, 0);
}

tree::TerminalNode* MiniDecafParser::SelectionStatementContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::SelectionStatementContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::SelectionStatementContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

std::vector<MiniDecafParser::StatementContext *> MiniDecafParser::SelectionStatementContext::statement() {
  return getRuleContexts<MiniDecafParser::StatementContext>();
}

MiniDecafParser::StatementContext* MiniDecafParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<MiniDecafParser::StatementContext>(i);
}

tree::TerminalNode* MiniDecafParser::SelectionStatementContext::Else() {
  return getToken(MiniDecafParser::Else, 0);
}

tree::TerminalNode* MiniDecafParser::SelectionStatementContext::Switch() {
  return getToken(MiniDecafParser::Switch, 0);
}


size_t MiniDecafParser::SelectionStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleSelectionStatement;
}


antlrcpp::Any MiniDecafParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::SelectionStatementContext* MiniDecafParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 152, MiniDecafParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(1164);
        match(MiniDecafParser::If);
        setState(1165);
        match(MiniDecafParser::LeftParen);
        setState(1166);
        expression(0);
        setState(1167);
        match(MiniDecafParser::RightParen);
        setState(1168);
        statement();
        setState(1171);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx)) {
        case 1: {
          setState(1169);
          match(MiniDecafParser::Else);
          setState(1170);
          statement();
          break;
        }

        }
        break;
      }

      case MiniDecafParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(1173);
        match(MiniDecafParser::Switch);
        setState(1174);
        match(MiniDecafParser::LeftParen);
        setState(1175);
        expression(0);
        setState(1176);
        match(MiniDecafParser::RightParen);
        setState(1177);
        statement();
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

//----------------- IterationStatementContext ------------------------------------------------------------------

MiniDecafParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::While() {
  return getToken(MiniDecafParser::While, 0);
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::LeftParen() {
  return getToken(MiniDecafParser::LeftParen, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::IterationStatementContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::RightParen() {
  return getToken(MiniDecafParser::RightParen, 0);
}

MiniDecafParser::StatementContext* MiniDecafParser::IterationStatementContext::statement() {
  return getRuleContext<MiniDecafParser::StatementContext>(0);
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::Do() {
  return getToken(MiniDecafParser::Do, 0);
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

tree::TerminalNode* MiniDecafParser::IterationStatementContext::For() {
  return getToken(MiniDecafParser::For, 0);
}

MiniDecafParser::ForConditionContext* MiniDecafParser::IterationStatementContext::forCondition() {
  return getRuleContext<MiniDecafParser::ForConditionContext>(0);
}


size_t MiniDecafParser::IterationStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleIterationStatement;
}


antlrcpp::Any MiniDecafParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::IterationStatementContext* MiniDecafParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, MiniDecafParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniDecafParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(1181);
        match(MiniDecafParser::While);
        setState(1182);
        match(MiniDecafParser::LeftParen);
        setState(1183);
        expression(0);
        setState(1184);
        match(MiniDecafParser::RightParen);
        setState(1185);
        statement();
        break;
      }

      case MiniDecafParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(1187);
        match(MiniDecafParser::Do);
        setState(1188);
        statement();
        setState(1189);
        match(MiniDecafParser::While);
        setState(1190);
        match(MiniDecafParser::LeftParen);
        setState(1191);
        expression(0);
        setState(1192);
        match(MiniDecafParser::RightParen);
        setState(1193);
        match(MiniDecafParser::Semi);
        break;
      }

      case MiniDecafParser::For: {
        enterOuterAlt(_localctx, 3);
        setState(1195);
        match(MiniDecafParser::For);
        setState(1196);
        match(MiniDecafParser::LeftParen);
        setState(1197);
        forCondition();
        setState(1198);
        match(MiniDecafParser::RightParen);
        setState(1199);
        statement();
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

//----------------- ForConditionContext ------------------------------------------------------------------

MiniDecafParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ForDeclarationContext* MiniDecafParser::ForConditionContext::forDeclaration() {
  return getRuleContext<MiniDecafParser::ForDeclarationContext>(0);
}

std::vector<tree::TerminalNode *> MiniDecafParser::ForConditionContext::Semi() {
  return getTokens(MiniDecafParser::Semi);
}

tree::TerminalNode* MiniDecafParser::ForConditionContext::Semi(size_t i) {
  return getToken(MiniDecafParser::Semi, i);
}

std::vector<MiniDecafParser::ForExpressionContext *> MiniDecafParser::ForConditionContext::forExpression() {
  return getRuleContexts<MiniDecafParser::ForExpressionContext>();
}

MiniDecafParser::ForExpressionContext* MiniDecafParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<MiniDecafParser::ForExpressionContext>(i);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::ForConditionContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}


size_t MiniDecafParser::ForConditionContext::getRuleIndex() const {
  return MiniDecafParser::RuleForCondition;
}


antlrcpp::Any MiniDecafParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ForConditionContext* MiniDecafParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 156, MiniDecafParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1203);
      forDeclaration();
      setState(1204);
      match(MiniDecafParser::Semi);
      setState(1206);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1205);
        forExpression(0);
      }
      setState(1208);
      match(MiniDecafParser::Semi);
      setState(1210);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1209);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1213);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1212);
        expression(0);
      }
      setState(1215);
      match(MiniDecafParser::Semi);
      setState(1217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1216);
        forExpression(0);
      }
      setState(1219);
      match(MiniDecafParser::Semi);
      setState(1221);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1220);
        forExpression(0);
      }
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

//----------------- ForDeclarationContext ------------------------------------------------------------------

MiniDecafParser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclarationSpecifiersContext* MiniDecafParser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<MiniDecafParser::DeclarationSpecifiersContext>(0);
}

MiniDecafParser::InitDeclaratorListContext* MiniDecafParser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<MiniDecafParser::InitDeclaratorListContext>(0);
}


size_t MiniDecafParser::ForDeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleForDeclaration;
}


antlrcpp::Any MiniDecafParser::ForDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitForDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ForDeclarationContext* MiniDecafParser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 158, MiniDecafParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1225);
      declarationSpecifiers();
      setState(1226);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1228);
      declarationSpecifiers();
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

//----------------- ForExpressionContext ------------------------------------------------------------------

MiniDecafParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::AssignmentExpressionContext* MiniDecafParser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<MiniDecafParser::AssignmentExpressionContext>(0);
}

MiniDecafParser::ForExpressionContext* MiniDecafParser::ForExpressionContext::forExpression() {
  return getRuleContext<MiniDecafParser::ForExpressionContext>(0);
}

tree::TerminalNode* MiniDecafParser::ForExpressionContext::Comma() {
  return getToken(MiniDecafParser::Comma, 0);
}


size_t MiniDecafParser::ForExpressionContext::getRuleIndex() const {
  return MiniDecafParser::RuleForExpression;
}


antlrcpp::Any MiniDecafParser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::ForExpressionContext* MiniDecafParser::forExpression() {
   return forExpression(0);
}

MiniDecafParser::ForExpressionContext* MiniDecafParser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  MiniDecafParser::ForExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 160;
  enterRecursionRule(_localctx, 160, MiniDecafParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1232);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(1239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(1234);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1235);
        match(MiniDecafParser::Comma);
        setState(1236);
        assignmentExpression(); 
      }
      setState(1241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

MiniDecafParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Goto() {
  return getToken(MiniDecafParser::Goto, 0);
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Identifier() {
  return getToken(MiniDecafParser::Identifier, 0);
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Continue() {
  return getToken(MiniDecafParser::Continue, 0);
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Break() {
  return getToken(MiniDecafParser::Break, 0);
}

tree::TerminalNode* MiniDecafParser::JumpStatementContext::Return() {
  return getToken(MiniDecafParser::Return, 0);
}

MiniDecafParser::ExpressionContext* MiniDecafParser::JumpStatementContext::expression() {
  return getRuleContext<MiniDecafParser::ExpressionContext>(0);
}

MiniDecafParser::UnaryExpressionContext* MiniDecafParser::JumpStatementContext::unaryExpression() {
  return getRuleContext<MiniDecafParser::UnaryExpressionContext>(0);
}


size_t MiniDecafParser::JumpStatementContext::getRuleIndex() const {
  return MiniDecafParser::RuleJumpStatement;
}


antlrcpp::Any MiniDecafParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::JumpStatementContext* MiniDecafParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, MiniDecafParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1242);
      match(MiniDecafParser::Goto);
      setState(1243);
      match(MiniDecafParser::Identifier);
      setState(1244);
      match(MiniDecafParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1245);
      match(MiniDecafParser::Continue);
      setState(1246);
      match(MiniDecafParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1247);
      match(MiniDecafParser::Break);
      setState(1248);
      match(MiniDecafParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1249);
      match(MiniDecafParser::Return);
      setState(1251);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
        | (1ULL << MiniDecafParser::T__1)
        | (1ULL << MiniDecafParser::T__2)
        | (1ULL << MiniDecafParser::Sizeof)
        | (1ULL << MiniDecafParser::Alignof)
        | (1ULL << MiniDecafParser::Generic)
        | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (MiniDecafParser::Plus - 71))
        | (1ULL << (MiniDecafParser::PlusPlus - 71))
        | (1ULL << (MiniDecafParser::Minus - 71))
        | (1ULL << (MiniDecafParser::MinusMinus - 71))
        | (1ULL << (MiniDecafParser::Star - 71))
        | (1ULL << (MiniDecafParser::And - 71))
        | (1ULL << (MiniDecafParser::AndAnd - 71))
        | (1ULL << (MiniDecafParser::Not - 71))
        | (1ULL << (MiniDecafParser::Tilde - 71))
        | (1ULL << (MiniDecafParser::Identifier - 71))
        | (1ULL << (MiniDecafParser::Constant - 71))
        | (1ULL << (MiniDecafParser::DigitSequence - 71))
        | (1ULL << (MiniDecafParser::StringLiteral - 71)))) != 0)) {
        setState(1250);
        expression(0);
      }
      setState(1253);
      match(MiniDecafParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1254);
      match(MiniDecafParser::Goto);
      setState(1255);
      unaryExpression();
      setState(1256);
      match(MiniDecafParser::Semi);
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

//----------------- CompilationUnitContext ------------------------------------------------------------------

MiniDecafParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniDecafParser::CompilationUnitContext::EOF() {
  return getToken(MiniDecafParser::EOF, 0);
}

MiniDecafParser::TranslationUnitContext* MiniDecafParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<MiniDecafParser::TranslationUnitContext>(0);
}


size_t MiniDecafParser::CompilationUnitContext::getRuleIndex() const {
  return MiniDecafParser::RuleCompilationUnit;
}


antlrcpp::Any MiniDecafParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::CompilationUnitContext* MiniDecafParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 164, MiniDecafParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1261);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
      | (1ULL << MiniDecafParser::T__3)
      | (1ULL << MiniDecafParser::T__4)
      | (1ULL << MiniDecafParser::T__5)
      | (1ULL << MiniDecafParser::T__6)
      | (1ULL << MiniDecafParser::T__7)
      | (1ULL << MiniDecafParser::T__8)
      | (1ULL << MiniDecafParser::T__9)
      | (1ULL << MiniDecafParser::T__11)
      | (1ULL << MiniDecafParser::Auto)
      | (1ULL << MiniDecafParser::Char)
      | (1ULL << MiniDecafParser::Const)
      | (1ULL << MiniDecafParser::Double)
      | (1ULL << MiniDecafParser::Enum)
      | (1ULL << MiniDecafParser::Extern)
      | (1ULL << MiniDecafParser::Float)
      | (1ULL << MiniDecafParser::Inline)
      | (1ULL << MiniDecafParser::Int)
      | (1ULL << MiniDecafParser::Long)
      | (1ULL << MiniDecafParser::Register)
      | (1ULL << MiniDecafParser::Restrict)
      | (1ULL << MiniDecafParser::Short)
      | (1ULL << MiniDecafParser::Signed)
      | (1ULL << MiniDecafParser::Static)
      | (1ULL << MiniDecafParser::Struct)
      | (1ULL << MiniDecafParser::Typedef)
      | (1ULL << MiniDecafParser::Union)
      | (1ULL << MiniDecafParser::Unsigned)
      | (1ULL << MiniDecafParser::Void)
      | (1ULL << MiniDecafParser::Volatile)
      | (1ULL << MiniDecafParser::Alignas)
      | (1ULL << MiniDecafParser::Atomic)
      | (1ULL << MiniDecafParser::Bool)
      | (1ULL << MiniDecafParser::Complex)
      | (1ULL << MiniDecafParser::Noreturn)
      | (1ULL << MiniDecafParser::StaticAssert)
      | (1ULL << MiniDecafParser::ThreadLocal)
      | (1ULL << MiniDecafParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (MiniDecafParser::Star - 75))
      | (1ULL << (MiniDecafParser::Caret - 75))
      | (1ULL << (MiniDecafParser::Semi - 75))
      | (1ULL << (MiniDecafParser::Identifier - 75)))) != 0)) {
      setState(1260);
      translationUnit(0);
    }
    setState(1263);
    match(MiniDecafParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

MiniDecafParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::ExternalDeclarationContext* MiniDecafParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<MiniDecafParser::ExternalDeclarationContext>(0);
}

MiniDecafParser::TranslationUnitContext* MiniDecafParser::TranslationUnitContext::translationUnit() {
  return getRuleContext<MiniDecafParser::TranslationUnitContext>(0);
}


size_t MiniDecafParser::TranslationUnitContext::getRuleIndex() const {
  return MiniDecafParser::RuleTranslationUnit;
}


antlrcpp::Any MiniDecafParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::TranslationUnitContext* MiniDecafParser::translationUnit() {
   return translationUnit(0);
}

MiniDecafParser::TranslationUnitContext* MiniDecafParser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  MiniDecafParser::TranslationUnitContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 166;
  enterRecursionRule(_localctx, 166, MiniDecafParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1266);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(1272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(1268);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1269);
        externalDeclaration(); 
      }
      setState(1274);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

MiniDecafParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::FunctionDefinitionContext* MiniDecafParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<MiniDecafParser::FunctionDefinitionContext>(0);
}

MiniDecafParser::DeclarationContext* MiniDecafParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<MiniDecafParser::DeclarationContext>(0);
}

tree::TerminalNode* MiniDecafParser::ExternalDeclarationContext::Semi() {
  return getToken(MiniDecafParser::Semi, 0);
}


size_t MiniDecafParser::ExternalDeclarationContext::getRuleIndex() const {
  return MiniDecafParser::RuleExternalDeclaration;
}


antlrcpp::Any MiniDecafParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::ExternalDeclarationContext* MiniDecafParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 168, MiniDecafParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1275);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1276);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1277);
      match(MiniDecafParser::Semi);
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

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

MiniDecafParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclaratorContext* MiniDecafParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<MiniDecafParser::DeclaratorContext>(0);
}

MiniDecafParser::CompoundStatementContext* MiniDecafParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<MiniDecafParser::CompoundStatementContext>(0);
}

MiniDecafParser::DeclarationSpecifiersContext* MiniDecafParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<MiniDecafParser::DeclarationSpecifiersContext>(0);
}

MiniDecafParser::DeclarationListContext* MiniDecafParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<MiniDecafParser::DeclarationListContext>(0);
}


size_t MiniDecafParser::FunctionDefinitionContext::getRuleIndex() const {
  return MiniDecafParser::RuleFunctionDefinition;
}


antlrcpp::Any MiniDecafParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

MiniDecafParser::FunctionDefinitionContext* MiniDecafParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 170, MiniDecafParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1281);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
    case 1: {
      setState(1280);
      declarationSpecifiers();
      break;
    }

    }
    setState(1283);
    declarator();
    setState(1285);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniDecafParser::T__0)
      | (1ULL << MiniDecafParser::T__3)
      | (1ULL << MiniDecafParser::T__4)
      | (1ULL << MiniDecafParser::T__5)
      | (1ULL << MiniDecafParser::T__6)
      | (1ULL << MiniDecafParser::T__7)
      | (1ULL << MiniDecafParser::T__8)
      | (1ULL << MiniDecafParser::T__9)
      | (1ULL << MiniDecafParser::T__11)
      | (1ULL << MiniDecafParser::Auto)
      | (1ULL << MiniDecafParser::Char)
      | (1ULL << MiniDecafParser::Const)
      | (1ULL << MiniDecafParser::Double)
      | (1ULL << MiniDecafParser::Enum)
      | (1ULL << MiniDecafParser::Extern)
      | (1ULL << MiniDecafParser::Float)
      | (1ULL << MiniDecafParser::Inline)
      | (1ULL << MiniDecafParser::Int)
      | (1ULL << MiniDecafParser::Long)
      | (1ULL << MiniDecafParser::Register)
      | (1ULL << MiniDecafParser::Restrict)
      | (1ULL << MiniDecafParser::Short)
      | (1ULL << MiniDecafParser::Signed)
      | (1ULL << MiniDecafParser::Static)
      | (1ULL << MiniDecafParser::Struct)
      | (1ULL << MiniDecafParser::Typedef)
      | (1ULL << MiniDecafParser::Union)
      | (1ULL << MiniDecafParser::Unsigned)
      | (1ULL << MiniDecafParser::Void)
      | (1ULL << MiniDecafParser::Volatile)
      | (1ULL << MiniDecafParser::Alignas)
      | (1ULL << MiniDecafParser::Atomic)
      | (1ULL << MiniDecafParser::Bool)
      | (1ULL << MiniDecafParser::Complex)
      | (1ULL << MiniDecafParser::Noreturn)
      | (1ULL << MiniDecafParser::StaticAssert)
      | (1ULL << MiniDecafParser::ThreadLocal))) != 0) || _la == MiniDecafParser::Identifier) {
      setState(1284);
      declarationList(0);
    }
    setState(1287);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

MiniDecafParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniDecafParser::DeclarationContext* MiniDecafParser::DeclarationListContext::declaration() {
  return getRuleContext<MiniDecafParser::DeclarationContext>(0);
}

MiniDecafParser::DeclarationListContext* MiniDecafParser::DeclarationListContext::declarationList() {
  return getRuleContext<MiniDecafParser::DeclarationListContext>(0);
}


size_t MiniDecafParser::DeclarationListContext::getRuleIndex() const {
  return MiniDecafParser::RuleDeclarationList;
}


antlrcpp::Any MiniDecafParser::DeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniDecafVisitor*>(visitor))
    return parserVisitor->visitDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


MiniDecafParser::DeclarationListContext* MiniDecafParser::declarationList() {
   return declarationList(0);
}

MiniDecafParser::DeclarationListContext* MiniDecafParser::declarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniDecafParser::DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, parentState);
  MiniDecafParser::DeclarationListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 172;
  enterRecursionRule(_localctx, 172, MiniDecafParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1290);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(1296);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(1292);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1293);
        declaration(); 
      }
      setState(1298);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx);
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
    case 2: return genericAssocListSempred(dynamic_cast<GenericAssocListContext *>(context), predicateIndex);
    case 4: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 5: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 9: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 10: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 11: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 12: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 13: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 14: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 15: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 16: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 17: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 18: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 22: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 28: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 31: return typeSpecifierSempred(dynamic_cast<TypeSpecifierContext *>(context), predicateIndex);
    case 34: return structDeclarationListSempred(dynamic_cast<StructDeclarationListContext *>(context), predicateIndex);
    case 37: return structDeclaratorListSempred(dynamic_cast<StructDeclaratorListContext *>(context), predicateIndex);
    case 40: return enumeratorListSempred(dynamic_cast<EnumeratorListContext *>(context), predicateIndex);
    case 48: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 55: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 57: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 59: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 62: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 65: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 67: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 73: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 80: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 83: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 86: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::genericAssocListSempred(GenericAssocListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);
    case 14: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 4);
    case 16: return precpred(_ctx, 3);
    case 17: return precpred(_ctx, 2);
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 2);
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::typeSpecifierSempred(TypeSpecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::structDeclarationListSempred(StructDeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::structDeclaratorListSempred(StructDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::enumeratorListSempred(EnumeratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 32: return precpred(_ctx, 8);
    case 33: return precpred(_ctx, 7);
    case 34: return precpred(_ctx, 6);
    case 35: return precpred(_ctx, 5);
    case 36: return precpred(_ctx, 4);
    case 37: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 38: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 39: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 40: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 41: return precpred(_ctx, 5);
    case 42: return precpred(_ctx, 4);
    case 43: return precpred(_ctx, 3);
    case 44: return precpred(_ctx, 2);
    case 45: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 46: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 47: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 48: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 49: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 50: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniDecafParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 51: return precpred(_ctx, 1);

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
  "primaryExpression", "genericSelection", "genericAssocList", "genericAssociation", 
  "postfixExpression", "argumentExpressionList", "unaryExpression", "unaryOperator", 
  "castExpression", "multiplicativeExpression", "additiveExpression", "shiftExpression", 
  "relationalExpression", "equalityExpression", "andExpression", "exclusiveOrExpression", 
  "inclusiveOrExpression", "logicalAndExpression", "logicalOrExpression", 
  "conditionalExpression", "assignmentExpression", "assignmentOperator", 
  "expression", "constantExpression", "declaration", "declarationSpecifiers", 
  "declarationSpecifiers2", "declarationSpecifier", "initDeclaratorList", 
  "initDeclarator", "storageClassSpecifier", "typeSpecifier", "structOrUnionSpecifier", 
  "structOrUnion", "structDeclarationList", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "enumSpecifier", "enumeratorList", 
  "enumerator", "enumerationConstant", "atomicTypeSpecifier", "typeQualifier", 
  "functionSpecifier", "alignmentSpecifier", "declarator", "directDeclarator", 
  "gccDeclaratorExtension", "gccAttributeSpecifier", "gccAttributeList", 
  "gccAttribute", "nestedParenthesesBlock", "pointer", "typeQualifierList", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "typeName", "abstractDeclarator", "directAbstractDeclarator", "typedefName", 
  "initializer", "initializerList", "designation", "designatorList", "designator", 
  "staticAssertDeclaration", "statement", "labeledStatement", "compoundStatement", 
  "blockItemList", "blockItem", "expressionStatement", "selectionStatement", 
  "iterationStatement", "forCondition", "forDeclaration", "forExpression", 
  "jumpStatement", "compilationUnit", "translationUnit", "externalDeclaration", 
  "functionDefinition", "declarationList"
};

std::vector<std::string> MiniDecafParser::_literalNames = {
  "", "'__extension__'", "'__builtin_va_arg'", "'__builtin_offsetof'", "'__m128'", 
  "'__m128d'", "'__m128i'", "'__typeof__'", "'__inline__'", "'__stdcall'", 
  "'__declspec'", "'__asm'", "'__attribute__'", "'__asm__'", "'__volatile__'", 
  "'auto'", "'break'", "'case'", "'char'", "'const'", "'continue'", "'default'", 
  "'do'", "'double'", "'else'", "'enum'", "'extern'", "'float'", "'for'", 
  "'goto'", "'if'", "'inline'", "'int'", "'long'", "'register'", "'restrict'", 
  "'return'", "'short'", "'signed'", "'sizeof'", "'static'", "'struct'", 
  "'switch'", "'typedef'", "'union'", "'unsigned'", "'void'", "'volatile'", 
  "'while'", "'_Alignas'", "'_Alignof'", "'_Atomic'", "'_Bool'", "'_Complex'", 
  "'_Generic'", "'_Imaginary'", "'_Noreturn'", "'_Static_assert'", "'_Thread_local'", 
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", 
  "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", "'&'", 
  "'|'", "'&&'", "'||'", "'^'", "'!'", "'~'", "'?'", "':'", "';'", "','", 
  "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", 
  "'^='", "'|='", "'=='", "'!='", "'->'", "'.'", "'...'"
};

std::vector<std::string> MiniDecafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Auto", "Break", 
  "Case", "Char", "Const", "Continue", "Default", "Do", "Double", "Else", 
  "Enum", "Extern", "Float", "For", "Goto", "If", "Inline", "Int", "Long", 
  "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", "Static", 
  "Struct", "Switch", "Typedef", "Union", "Unsigned", "Void", "Volatile", 
  "While", "Alignas", "Alignof", "Atomic", "Bool", "Complex", "Generic", 
  "Imaginary", "Noreturn", "StaticAssert", "ThreadLocal", "LeftParen", "RightParen", 
  "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", 
  "Greater", "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", 
  "Minus", "MinusMinus", "Star", "Div", "Mod", "And", "Or", "AndAnd", "OrOr", 
  "Caret", "Not", "Tilde", "Question", "Colon", "Semi", "Comma", "Assign", 
  "StarAssign", "DivAssign", "ModAssign", "PlusAssign", "MinusAssign", "LeftShiftAssign", 
  "RightShiftAssign", "AndAssign", "XorAssign", "OrAssign", "Equal", "NotEqual", 
  "Arrow", "Dot", "Ellipsis", "Identifier", "Constant", "DigitSequence", 
  "StringLiteral", "ComplexDefine", "IncludeDirective", "AsmBlock", "LineAfterPreprocessing", 
  "LineDirective", "PragmaDirective", "Whitespace", "Newline", "BlockComment", 
  "LineComment"
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
    0x3, 0x78, 0x516, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x6, 0x2, 0xb4, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xb5, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xbe, 
    0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xd2, 0xa, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0xe1, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xe4, 0xb, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xed, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x111, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x11b, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x128, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x12b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x7, 0x7, 0x133, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x136, 0xb, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x14e, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x15f, 0xa, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x16d, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x170, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0x17b, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x17e, 0xb, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0x189, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x18c, 0xb, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x7, 0xe, 0x19d, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x1a0, 
    0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1ab, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0x1ae, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x7, 0x10, 0x1b6, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0x1b9, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x1c1, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1c4, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x7, 0x12, 0x1cc, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1cf, 0xb, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x1d7, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x1da, 0xb, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 
    0x14, 0x1e2, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x1e5, 0xb, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0x1ed, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x1f5, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x1ff, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x202, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x20e, 0xa, 0x1a, 0x3, 0x1b, 0x6, 0x1b, 
    0x211, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 0x212, 0x3, 0x1c, 0x6, 0x1c, 
    0x216, 0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 0x217, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x21f, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x227, 
    0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x22a, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x231, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x244, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0x248, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x24b, 
    0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x24f, 0xa, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
    0x22, 0x258, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x261, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x264, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x268, 
    0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x26d, 0xa, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x271, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x5, 0x26, 0x275, 0xa, 0x26, 0x5, 0x26, 0x277, 0xa, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x27f, 
    0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x282, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x5, 0x28, 0x286, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x28a, 
    0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x28e, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x296, 
    0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x29f, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x2a7, 0xa, 0x2a, 
    0xc, 0x2a, 0xe, 0x2a, 0x2aa, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2b1, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x2c2, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x2ce, 0xa, 0x30, 0x3, 0x31, 0x5, 0x31, 0x2d1, 0xa, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x7, 0x31, 0x2d5, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 
    0x2d8, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 
    0x32, 0x2e5, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x5, 0x32, 0x2eb, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x2f0, 0xa, 0x32, 0x3, 0x32, 0x5, 0x32, 0x2f3, 0xa, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x2fa, 0xa, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x5, 0x32, 0x309, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 
    0x32, 0x315, 0xa, 0x32, 0x3, 0x32, 0x7, 0x32, 0x318, 0xa, 0x32, 0xc, 
    0x32, 0xe, 0x32, 0x31b, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x6, 0x33, 0x320, 0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x321, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x326, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x7, 0x35, 0x332, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x335, 0xb, 
    0x35, 0x3, 0x35, 0x5, 0x35, 0x338, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x5, 0x36, 0x33d, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x340, 
    0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x343, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x34a, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x34d, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x351, 
    0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x355, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x35a, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x35e, 0xa, 0x38, 0x3, 0x38, 0x5, 0x38, 0x361, 0xa, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x368, 
    0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x36b, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x372, 0xa, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x37a, 
    0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x37d, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x384, 0xa, 0x3c, 0x5, 0x3c, 
    0x386, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x7, 0x3d, 0x38e, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x391, 
    0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x395, 0xa, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x5, 0x3f, 0x399, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 
    0x39d, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x3a0, 0xb, 0x3f, 0x5, 0x3f, 
    0x3a2, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x7, 0x40, 0x3a9, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x3ac, 0xb, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3b0, 0xa, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x3b3, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x3b9, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3c9, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x7, 0x40, 0x3cd, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x3d0, 
    0xb, 0x40, 0x5, 0x40, 0x3d2, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x3d7, 0xa, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3da, 0xa, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3e1, 
    0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3f4, 
    0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x3f8, 0xa, 0x40, 0xc, 0x40, 
    0xe, 0x40, 0x3fb, 0xb, 0x40, 0x7, 0x40, 0x3fd, 0xa, 0x40, 0xc, 0x40, 
    0xe, 0x40, 0x400, 0xb, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x5, 0x42, 0x40e, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 
    0x5, 0x43, 0x412, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x5, 0x43, 0x419, 0xa, 0x43, 0x3, 0x43, 0x7, 0x43, 0x41c, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x41f, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
    0x45, 0x429, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x42c, 0xb, 0x45, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 
    0x434, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x6, 0x47, 0x43b, 0xa, 0x47, 0xd, 0x47, 0xe, 0x47, 0x43c, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x7, 0x48, 0x44e, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x451, 
    0xb, 0x48, 0x5, 0x48, 0x453, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x7, 0x48, 0x459, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x45c, 
    0xb, 0x48, 0x5, 0x48, 0x45e, 0xa, 0x48, 0x7, 0x48, 0x460, 0xa, 0x48, 
    0xc, 0x48, 0xe, 0x48, 0x463, 0xb, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 
    0x467, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 
    0x49, 0x474, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x478, 0xa, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x3, 0x4b, 0x7, 0x4b, 0x481, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x484, 
    0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x488, 0xa, 0x4c, 0x3, 0x4d, 
    0x5, 0x4d, 0x48b, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x496, 
    0xa, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x5, 0x4e, 0x49e, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x4b4, 0xa, 0x4f, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x4b9, 0xa, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4bd, 0xa, 0x50, 0x3, 0x50, 0x5, 0x50, 0x4c0, 
    0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x4c4, 0xa, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4c8, 0xa, 0x50, 0x5, 0x50, 0x4ca, 0xa, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x4d0, 0xa, 0x51, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 
    0x52, 0x4d8, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 0x4db, 0xb, 0x52, 0x3, 
    0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x4e6, 0xa, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x4ed, 0xa, 0x53, 0x3, 0x54, 
    0x5, 0x54, 0x4f0, 0xa, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x4f9, 0xa, 0x55, 0xc, 0x55, 
    0xe, 0x55, 0x4fc, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 
    0x501, 0xa, 0x56, 0x3, 0x57, 0x5, 0x57, 0x504, 0xa, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x5, 0x57, 0x508, 0xa, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x511, 0xa, 0x58, 
    0xc, 0x58, 0xe, 0x58, 0x514, 0xb, 0x58, 0x3, 0x58, 0x2, 0x20, 0x6, 0xa, 
    0xc, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x2e, 
    0x3a, 0x40, 0x46, 0x4c, 0x52, 0x62, 0x70, 0x74, 0x78, 0x7e, 0x84, 0x88, 
    0x94, 0xa2, 0xa8, 0xae, 0x59, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0x2, 0xe, 0x7, 0x2, 0x49, 
    0x49, 0x4b, 0x4b, 0x4d, 0x4d, 0x50, 0x50, 0x55, 0x56, 0x3, 0x2, 0x5b, 
    0x65, 0x8, 0x2, 0x11, 0x11, 0x1c, 0x1c, 0x24, 0x24, 0x2a, 0x2a, 0x2d, 
    0x2d, 0x3c, 0x3c, 0xa, 0x2, 0x6, 0x8, 0x14, 0x14, 0x19, 0x19, 0x1d, 
    0x1d, 0x22, 0x23, 0x27, 0x28, 0x2f, 0x30, 0x36, 0x37, 0x3, 0x2, 0x6, 
    0x8, 0x4, 0x2, 0x2b, 0x2b, 0x2e, 0x2e, 0x6, 0x2, 0x15, 0x15, 0x25, 0x25, 
    0x31, 0x31, 0x35, 0x35, 0x5, 0x2, 0xa, 0xb, 0x21, 0x21, 0x3a, 0x3a, 
    0x4, 0x2, 0x3d, 0x3e, 0x5a, 0x5a, 0x3, 0x2, 0x3d, 0x3e, 0x4, 0x2, 0xd, 
    0xd, 0xf, 0xf, 0x4, 0x2, 0x10, 0x10, 0x31, 0x31, 0x2, 0x58b, 0x2, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x6, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xec, 0x3, 0x2, 0x2, 0x2, 0xa, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0xc, 0x12c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x160, 0x3, 0x2, 0x2, 0x2, 0x16, 0x171, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17f, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1ba, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1d0, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1e6, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x30, 0x203, 0x3, 0x2, 0x2, 0x2, 0x32, 0x20d, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x210, 0x3, 0x2, 0x2, 0x2, 0x36, 0x215, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x220, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x230, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x232, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x243, 0x3, 0x2, 0x2, 0x2, 0x42, 0x257, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x259, 0x3, 0x2, 0x2, 0x2, 0x46, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x26c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x276, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x278, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x289, 0x3, 0x2, 0x2, 0x2, 0x50, 0x29e, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2b0, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2b4, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2c1, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x2ea, 0x3, 0x2, 0x2, 0x2, 0x64, 0x325, 0x3, 0x2, 0x2, 0x2, 0x66, 0x327, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x337, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x342, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x360, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x362, 0x3, 0x2, 0x2, 0x2, 0x72, 0x371, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x373, 0x3, 0x2, 0x2, 0x2, 0x76, 0x385, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x387, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x392, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x3a1, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x80, 0x401, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x40f, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x420, 0x3, 0x2, 0x2, 0x2, 0x88, 0x423, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x433, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x435, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x466, 0x3, 0x2, 0x2, 0x2, 0x90, 0x473, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x475, 0x3, 0x2, 0x2, 0x2, 0x94, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x487, 0x3, 0x2, 0x2, 0x2, 0x98, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x49d, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x4b3, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x4c9, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x4cf, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x4d1, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x4ef, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0x4f3, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x500, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0x503, 0x3, 0x2, 0x2, 0x2, 0xae, 0x50b, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xd2, 0x7, 0x6b, 0x2, 0x2, 0xb1, 0xd2, 0x7, 0x6c, 0x2, 0x2, 0xb2, 0xb4, 
    0x7, 0x6e, 0x2, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x3d, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x2e, 0x18, 0x2, 0xb9, 0xba, 0x7, 0x3e, 0x2, 0x2, 
    0xba, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xd2, 0x5, 0x4, 0x3, 0x2, 0xbc, 
    0xbe, 0x7, 0x3, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 
    0x3d, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x92, 0x4a, 0x2, 0xc1, 0xc2, 0x7, 0x3e, 
    0x2, 0x2, 0xc2, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x4, 0x2, 
    0x2, 0xc4, 0xc5, 0x7, 0x3d, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0xe, 0x8, 0x2, 
    0xc6, 0xc7, 0x7, 0x5a, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x7a, 0x3e, 0x2, 0xc8, 
    0xc9, 0x7, 0x3e, 0x2, 0x2, 0xc9, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 
    0x7, 0x5, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x3d, 0x2, 0x2, 0xcc, 0xcd, 0x5, 
    0x7a, 0x3e, 0x2, 0xcd, 0xce, 0x7, 0x5a, 0x2, 0x2, 0xce, 0xcf, 0x5, 0xe, 
    0x8, 0x2, 0xcf, 0xd0, 0x7, 0x3e, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x38, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x3d, 
    0x2, 0x2, 0xd5, 0xd6, 0x5, 0x2a, 0x16, 0x2, 0xd6, 0xd7, 0x7, 0x5a, 0x2, 
    0x2, 0xd7, 0xd8, 0x5, 0x6, 0x4, 0x2, 0xd8, 0xd9, 0x7, 0x3e, 0x2, 0x2, 
    0xd9, 0x5, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x8, 0x4, 0x1, 0x2, 0xdb, 
    0xdc, 0x5, 0x8, 0x5, 0x2, 0xdc, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 
    0xc, 0x3, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x5a, 0x2, 0x2, 0xdf, 0xe1, 0x5, 
    0x8, 0x5, 0x2, 0xe0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0x7, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xe6, 0x5, 0x7a, 0x3e, 0x2, 0xe6, 0xe7, 0x7, 0x58, 0x2, 0x2, 0xe7, 
    0xe8, 0x5, 0x2a, 0x16, 0x2, 0xe8, 0xed, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 
    0x7, 0x17, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x58, 0x2, 0x2, 0xeb, 0xed, 0x5, 
    0x2a, 0x16, 0x2, 0xec, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0x9, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x8, 0x6, 0x1, 
    0x2, 0xef, 0x111, 0x5, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x3d, 0x2, 0x2, 
    0xf1, 0xf2, 0x5, 0x7a, 0x3e, 0x2, 0xf2, 0xf3, 0x7, 0x3e, 0x2, 0x2, 0xf3, 
    0xf4, 0x7, 0x41, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x84, 0x43, 0x2, 0xf5, 0xf6, 
    0x7, 0x42, 0x2, 0x2, 0xf6, 0x111, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 
    0x3d, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x7a, 0x3e, 0x2, 0xf9, 0xfa, 0x7, 0x3e, 
    0x2, 0x2, 0xfa, 0xfb, 0x7, 0x41, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x84, 0x43, 
    0x2, 0xfc, 0xfd, 0x7, 0x5a, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x42, 0x2, 0x2, 
    0xfe, 0x111, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x3, 0x2, 0x2, 0x100, 
    0x101, 0x7, 0x3d, 0x2, 0x2, 0x101, 0x102, 0x5, 0x7a, 0x3e, 0x2, 0x102, 
    0x103, 0x7, 0x3e, 0x2, 0x2, 0x103, 0x104, 0x7, 0x41, 0x2, 0x2, 0x104, 
    0x105, 0x5, 0x84, 0x43, 0x2, 0x105, 0x106, 0x7, 0x42, 0x2, 0x2, 0x106, 
    0x111, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0x3, 0x2, 0x2, 0x108, 
    0x109, 0x7, 0x3d, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x7a, 0x3e, 0x2, 0x10a, 
    0x10b, 0x7, 0x3e, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x41, 0x2, 0x2, 0x10c, 
    0x10d, 0x5, 0x84, 0x43, 0x2, 0x10d, 0x10e, 0x7, 0x5a, 0x2, 0x2, 0x10e, 
    0x10f, 0x7, 0x42, 0x2, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x110, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x110, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0xff, 0x3, 0x2, 0x2, 0x2, 0x110, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x129, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0xc, 
    0xc, 0x2, 0x2, 0x113, 0x114, 0x7, 0x3f, 0x2, 0x2, 0x114, 0x115, 0x5, 
    0x2e, 0x18, 0x2, 0x115, 0x116, 0x7, 0x40, 0x2, 0x2, 0x116, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x118, 0xc, 0xb, 0x2, 0x2, 0x118, 0x11a, 0x7, 
    0x3d, 0x2, 0x2, 0x119, 0x11b, 0x5, 0xc, 0x7, 0x2, 0x11a, 0x119, 0x3, 
    0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x128, 0x7, 0x3e, 0x2, 0x2, 0x11d, 0x11e, 0xc, 
    0xa, 0x2, 0x2, 0x11e, 0x11f, 0x7, 0x69, 0x2, 0x2, 0x11f, 0x128, 0x7, 
    0x6b, 0x2, 0x2, 0x120, 0x121, 0xc, 0x9, 0x2, 0x2, 0x121, 0x122, 0x7, 
    0x68, 0x2, 0x2, 0x122, 0x128, 0x7, 0x6b, 0x2, 0x2, 0x123, 0x124, 0xc, 
    0x8, 0x2, 0x2, 0x124, 0x128, 0x7, 0x4a, 0x2, 0x2, 0x125, 0x126, 0xc, 
    0x7, 0x2, 0x2, 0x126, 0x128, 0x7, 0x4c, 0x2, 0x2, 0x127, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x117, 0x3, 0x2, 0x2, 0x2, 0x127, 0x11d, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x120, 0x3, 0x2, 0x2, 0x2, 0x127, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12d, 0x8, 0x7, 0x1, 0x2, 0x12d, 0x12e, 0x5, 0x2a, 
    0x16, 0x2, 0x12e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0xc, 0x3, 
    0x2, 0x2, 0x130, 0x131, 0x7, 0x5a, 0x2, 0x2, 0x131, 0x133, 0x5, 0x2a, 
    0x16, 0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0xd, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x14e, 0x5, 0xa, 0x6, 0x2, 0x138, 0x139, 0x7, 0x4a, 0x2, 
    0x2, 0x139, 0x14e, 0x5, 0xe, 0x8, 0x2, 0x13a, 0x13b, 0x7, 0x4c, 0x2, 
    0x2, 0x13b, 0x14e, 0x5, 0xe, 0x8, 0x2, 0x13c, 0x13d, 0x5, 0x10, 0x9, 
    0x2, 0x13d, 0x13e, 0x5, 0x12, 0xa, 0x2, 0x13e, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x13f, 0x140, 0x7, 0x29, 0x2, 0x2, 0x140, 0x14e, 0x5, 0xe, 0x8, 
    0x2, 0x141, 0x142, 0x7, 0x29, 0x2, 0x2, 0x142, 0x143, 0x7, 0x3d, 0x2, 
    0x2, 0x143, 0x144, 0x5, 0x7a, 0x3e, 0x2, 0x144, 0x145, 0x7, 0x3e, 0x2, 
    0x2, 0x145, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x34, 0x2, 
    0x2, 0x147, 0x148, 0x7, 0x3d, 0x2, 0x2, 0x148, 0x149, 0x5, 0x7a, 0x3e, 
    0x2, 0x149, 0x14a, 0x7, 0x3e, 0x2, 0x2, 0x14a, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14c, 0x7, 0x52, 0x2, 0x2, 0x14c, 0x14e, 0x7, 0x6b, 0x2, 
    0x2, 0x14d, 0x137, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x9, 0x2, 0x2, 0x2, 
    0x150, 0x11, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x3d, 0x2, 0x2, 
    0x152, 0x153, 0x5, 0x7a, 0x3e, 0x2, 0x153, 0x154, 0x7, 0x3e, 0x2, 0x2, 
    0x154, 0x155, 0x5, 0x12, 0xa, 0x2, 0x155, 0x15f, 0x3, 0x2, 0x2, 0x2, 
    0x156, 0x157, 0x7, 0x3, 0x2, 0x2, 0x157, 0x158, 0x7, 0x3d, 0x2, 0x2, 
    0x158, 0x159, 0x5, 0x7a, 0x3e, 0x2, 0x159, 0x15a, 0x7, 0x3e, 0x2, 0x2, 
    0x15a, 0x15b, 0x5, 0x12, 0xa, 0x2, 0x15b, 0x15f, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x15f, 0x5, 0xe, 0x8, 0x2, 0x15d, 0x15f, 0x7, 0x6d, 0x2, 0x2, 
    0x15e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x156, 0x3, 0x2, 0x2, 0x2, 
    0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x8, 0xb, 0x1, 0x2, 0x161, 
    0x162, 0x5, 0x12, 0xa, 0x2, 0x162, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x164, 0xc, 0x5, 0x2, 0x2, 0x164, 0x165, 0x7, 0x4d, 0x2, 0x2, 0x165, 
    0x16d, 0x5, 0x12, 0xa, 0x2, 0x166, 0x167, 0xc, 0x4, 0x2, 0x2, 0x167, 
    0x168, 0x7, 0x4e, 0x2, 0x2, 0x168, 0x16d, 0x5, 0x12, 0xa, 0x2, 0x169, 
    0x16a, 0xc, 0x3, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x4f, 0x2, 0x2, 0x16b, 
    0x16d, 0x5, 0x12, 0xa, 0x2, 0x16c, 0x163, 0x3, 0x2, 0x2, 0x2, 0x16c, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16d, 
    0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x8, 0xc, 0x1, 0x2, 0x172, 0x173, 
    0x5, 0x14, 0xb, 0x2, 0x173, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 
    0xc, 0x4, 0x2, 0x2, 0x175, 0x176, 0x7, 0x49, 0x2, 0x2, 0x176, 0x17b, 
    0x5, 0x14, 0xb, 0x2, 0x177, 0x178, 0xc, 0x3, 0x2, 0x2, 0x178, 0x179, 
    0x7, 0x4b, 0x2, 0x2, 0x179, 0x17b, 0x5, 0x14, 0xb, 0x2, 0x17a, 0x174, 
    0x3, 0x2, 0x2, 0x2, 0x17a, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 
    0x3, 0x2, 0x2, 0x2, 0x17d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x17f, 0x180, 0x8, 0xd, 0x1, 0x2, 0x180, 0x181, 0x5, 
    0x16, 0xc, 0x2, 0x181, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0xc, 
    0x4, 0x2, 0x2, 0x183, 0x184, 0x7, 0x47, 0x2, 0x2, 0x184, 0x189, 0x5, 
    0x16, 0xc, 0x2, 0x185, 0x186, 0xc, 0x3, 0x2, 0x2, 0x186, 0x187, 0x7, 
    0x48, 0x2, 0x2, 0x187, 0x189, 0x5, 0x16, 0xc, 0x2, 0x188, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x188, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 
    0x2, 0x2, 0x2, 0x18b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x18e, 0x8, 0xe, 0x1, 0x2, 0x18e, 0x18f, 0x5, 0x18, 
    0xd, 0x2, 0x18f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0xc, 0x6, 
    0x2, 0x2, 0x191, 0x192, 0x7, 0x43, 0x2, 0x2, 0x192, 0x19d, 0x5, 0x18, 
    0xd, 0x2, 0x193, 0x194, 0xc, 0x5, 0x2, 0x2, 0x194, 0x195, 0x7, 0x45, 
    0x2, 0x2, 0x195, 0x19d, 0x5, 0x18, 0xd, 0x2, 0x196, 0x197, 0xc, 0x4, 
    0x2, 0x2, 0x197, 0x198, 0x7, 0x44, 0x2, 0x2, 0x198, 0x19d, 0x5, 0x18, 
    0xd, 0x2, 0x199, 0x19a, 0xc, 0x3, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x46, 
    0x2, 0x2, 0x19b, 0x19d, 0x5, 0x18, 0xd, 0x2, 0x19c, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x193, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 
    0x2, 0x2, 0x19f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x1a2, 0x8, 0xf, 0x1, 0x2, 0x1a2, 0x1a3, 0x5, 0x1a, 0xe, 
    0x2, 0x1a3, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0xc, 0x4, 0x2, 
    0x2, 0x1a5, 0x1a6, 0x7, 0x66, 0x2, 0x2, 0x1a6, 0x1ab, 0x5, 0x1a, 0xe, 
    0x2, 0x1a7, 0x1a8, 0xc, 0x3, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x67, 0x2, 
    0x2, 0x1a9, 0x1ab, 0x5, 0x1a, 0xe, 0x2, 0x1aa, 0x1a4, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x1b0, 0x8, 0x10, 0x1, 0x2, 0x1b0, 0x1b1, 0x5, 0x1c, 0xf, 0x2, 
    0x1b1, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0xc, 0x3, 0x2, 0x2, 
    0x1b3, 0x1b4, 0x7, 0x50, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x1c, 0xf, 0x2, 
    0x1b5, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
    0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
    0x1bb, 0x8, 0x11, 0x1, 0x2, 0x1bb, 0x1bc, 0x5, 0x1e, 0x10, 0x2, 0x1bc, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0xc, 0x3, 0x2, 0x2, 0x1be, 
    0x1bf, 0x7, 0x54, 0x2, 0x2, 0x1bf, 0x1c1, 0x5, 0x1e, 0x10, 0x2, 0x1c0, 
    0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 
    0x8, 0x12, 0x1, 0x2, 0x1c6, 0x1c7, 0x5, 0x20, 0x11, 0x2, 0x1c7, 0x1cd, 
    0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0xc, 0x3, 0x2, 0x2, 0x1c9, 0x1ca, 
    0x7, 0x51, 0x2, 0x2, 0x1ca, 0x1cc, 0x5, 0x20, 0x11, 0x2, 0x1cb, 0x1c8, 
    0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 
    0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x8, 
    0x13, 0x1, 0x2, 0x1d1, 0x1d2, 0x5, 0x22, 0x12, 0x2, 0x1d2, 0x1d8, 0x3, 
    0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0xc, 0x3, 0x2, 0x2, 0x1d4, 0x1d5, 0x7, 
    0x52, 0x2, 0x2, 0x1d5, 0x1d7, 0x5, 0x22, 0x12, 0x2, 0x1d6, 0x1d3, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d6, 0x3, 
    0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x8, 0x14, 
    0x1, 0x2, 0x1dc, 0x1dd, 0x5, 0x24, 0x13, 0x2, 0x1dd, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x1de, 0x1df, 0xc, 0x3, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x53, 
    0x2, 0x2, 0x1e0, 0x1e2, 0x5, 0x24, 0x13, 0x2, 0x1e1, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1e2, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e1, 0x3, 0x2, 
    0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1ec, 0x5, 0x26, 0x14, 
    0x2, 0x1e7, 0x1e8, 0x7, 0x57, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x2e, 0x18, 
    0x2, 0x1e9, 0x1ea, 0x7, 0x58, 0x2, 0x2, 0x1ea, 0x1eb, 0x5, 0x28, 0x15, 
    0x2, 0x1eb, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1e7, 0x3, 0x2, 0x2, 
    0x2, 0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x1ee, 0x1f5, 0x5, 0x28, 0x15, 0x2, 0x1ef, 0x1f0, 0x5, 0xe, 0x8, 0x2, 
    0x1f0, 0x1f1, 0x5, 0x2c, 0x17, 0x2, 0x1f1, 0x1f2, 0x5, 0x2a, 0x16, 0x2, 
    0x1f2, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x7, 0x6d, 0x2, 0x2, 
    0x1f4, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1ef, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1f6, 
    0x1f7, 0x9, 0x3, 0x2, 0x2, 0x1f7, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 
    0x8, 0x18, 0x1, 0x2, 0x1f9, 0x1fa, 0x5, 0x2a, 0x16, 0x2, 0x1fa, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0xc, 0x3, 0x2, 0x2, 0x1fc, 0x1fd, 
    0x7, 0x5a, 0x2, 0x2, 0x1fd, 0x1ff, 0x5, 0x2a, 0x16, 0x2, 0x1fe, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1fe, 
    0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x5, 
    0x28, 0x15, 0x2, 0x204, 0x31, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x5, 
    0x34, 0x1b, 0x2, 0x206, 0x207, 0x5, 0x3a, 0x1e, 0x2, 0x207, 0x208, 0x7, 
    0x59, 0x2, 0x2, 0x208, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x5, 
    0x34, 0x1b, 0x2, 0x20a, 0x20b, 0x7, 0x59, 0x2, 0x2, 0x20b, 0x20e, 0x3, 
    0x2, 0x2, 0x2, 0x20c, 0x20e, 0x5, 0x8c, 0x47, 0x2, 0x20d, 0x205, 0x3, 
    0x2, 0x2, 0x2, 0x20d, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20c, 0x3, 
    0x2, 0x2, 0x2, 0x20e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x211, 0x5, 0x38, 
    0x1d, 0x2, 0x210, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x3, 0x2, 
    0x2, 0x2, 0x213, 0x35, 0x3, 0x2, 0x2, 0x2, 0x214, 0x216, 0x5, 0x38, 
    0x1d, 0x2, 0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 
    0x2, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 
    0x2, 0x2, 0x218, 0x37, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21f, 0x5, 0x3e, 
    0x20, 0x2, 0x21a, 0x21f, 0x5, 0x40, 0x21, 0x2, 0x21b, 0x21f, 0x5, 0x5a, 
    0x2e, 0x2, 0x21c, 0x21f, 0x5, 0x5c, 0x2f, 0x2, 0x21d, 0x21f, 0x5, 0x5e, 
    0x30, 0x2, 0x21e, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21a, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21c, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x220, 0x221, 0x8, 0x1e, 0x1, 0x2, 0x221, 0x222, 0x5, 0x3c, 0x1f, 
    0x2, 0x222, 0x228, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0xc, 0x3, 0x2, 
    0x2, 0x224, 0x225, 0x7, 0x5a, 0x2, 0x2, 0x225, 0x227, 0x5, 0x3c, 0x1f, 
    0x2, 0x226, 0x223, 0x3, 0x2, 0x2, 0x2, 0x227, 0x22a, 0x3, 0x2, 0x2, 
    0x2, 0x228, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x228, 0x3, 0x2, 0x2, 0x2, 
    0x22b, 0x231, 0x5, 0x60, 0x31, 0x2, 0x22c, 0x22d, 0x5, 0x60, 0x31, 0x2, 
    0x22d, 0x22e, 0x7, 0x5b, 0x2, 0x2, 0x22e, 0x22f, 0x5, 0x82, 0x42, 0x2, 
    0x22f, 0x231, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x230, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x231, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x232, 
    0x233, 0x9, 0x4, 0x2, 0x2, 0x233, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 
    0x8, 0x21, 0x1, 0x2, 0x235, 0x244, 0x9, 0x5, 0x2, 0x2, 0x236, 0x237, 
    0x7, 0x3, 0x2, 0x2, 0x237, 0x238, 0x7, 0x3d, 0x2, 0x2, 0x238, 0x239, 
    0x9, 0x6, 0x2, 0x2, 0x239, 0x244, 0x7, 0x3e, 0x2, 0x2, 0x23a, 0x244, 
    0x5, 0x58, 0x2d, 0x2, 0x23b, 0x244, 0x5, 0x42, 0x22, 0x2, 0x23c, 0x244, 
    0x5, 0x50, 0x29, 0x2, 0x23d, 0x244, 0x5, 0x80, 0x41, 0x2, 0x23e, 0x23f, 
    0x7, 0x9, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x3d, 0x2, 0x2, 0x240, 0x241, 
    0x5, 0x30, 0x19, 0x2, 0x241, 0x242, 0x7, 0x3e, 0x2, 0x2, 0x242, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x243, 0x234, 0x3, 0x2, 0x2, 0x2, 0x243, 0x236, 
    0x3, 0x2, 0x2, 0x2, 0x243, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x243, 0x23b, 
    0x3, 0x2, 0x2, 0x2, 0x243, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x243, 0x23d, 
    0x3, 0x2, 0x2, 0x2, 0x243, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x244, 0x249, 
    0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0xc, 0x3, 0x2, 0x2, 0x246, 0x248, 
    0x5, 0x6e, 0x38, 0x2, 0x247, 0x245, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24b, 
    0x3, 0x2, 0x2, 0x2, 0x249, 0x247, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 
    0x3, 0x2, 0x2, 0x2, 0x24a, 0x41, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x249, 0x3, 
    0x2, 0x2, 0x2, 0x24c, 0x24e, 0x5, 0x44, 0x23, 0x2, 0x24d, 0x24f, 0x7, 
    0x6b, 0x2, 0x2, 0x24e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 
    0x2, 0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x7, 
    0x41, 0x2, 0x2, 0x251, 0x252, 0x5, 0x46, 0x24, 0x2, 0x252, 0x253, 0x7, 
    0x42, 0x2, 0x2, 0x253, 0x258, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x5, 
    0x44, 0x23, 0x2, 0x255, 0x256, 0x7, 0x6b, 0x2, 0x2, 0x256, 0x258, 0x3, 
    0x2, 0x2, 0x2, 0x257, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x257, 0x254, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x43, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x9, 0x7, 
    0x2, 0x2, 0x25a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x8, 0x24, 
    0x1, 0x2, 0x25c, 0x25d, 0x5, 0x48, 0x25, 0x2, 0x25d, 0x262, 0x3, 0x2, 
    0x2, 0x2, 0x25e, 0x25f, 0xc, 0x3, 0x2, 0x2, 0x25f, 0x261, 0x5, 0x48, 
    0x25, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x261, 0x264, 0x3, 0x2, 
    0x2, 0x2, 0x262, 0x260, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 
    0x2, 0x2, 0x263, 0x47, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 
    0x2, 0x265, 0x267, 0x5, 0x4a, 0x26, 0x2, 0x266, 0x268, 0x5, 0x4c, 0x27, 
    0x2, 0x267, 0x266, 0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 0x3, 0x2, 0x2, 
    0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x7, 0x59, 0x2, 
    0x2, 0x26a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26d, 0x5, 0x8c, 0x47, 
    0x2, 0x26c, 0x265, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26b, 0x3, 0x2, 0x2, 
    0x2, 0x26d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x270, 0x5, 0x40, 0x21, 
    0x2, 0x26f, 0x271, 0x5, 0x4a, 0x26, 0x2, 0x270, 0x26f, 0x3, 0x2, 0x2, 
    0x2, 0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 0x271, 0x277, 0x3, 0x2, 0x2, 
    0x2, 0x272, 0x274, 0x5, 0x5a, 0x2e, 0x2, 0x273, 0x275, 0x5, 0x4a, 0x26, 
    0x2, 0x274, 0x273, 0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 
    0x2, 0x275, 0x277, 0x3, 0x2, 0x2, 0x2, 0x276, 0x26e, 0x3, 0x2, 0x2, 
    0x2, 0x276, 0x272, 0x3, 0x2, 0x2, 0x2, 0x277, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x279, 0x8, 0x27, 0x1, 0x2, 0x279, 0x27a, 0x5, 0x4e, 0x28, 0x2, 
    0x27a, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0xc, 0x3, 0x2, 0x2, 
    0x27c, 0x27d, 0x7, 0x5a, 0x2, 0x2, 0x27d, 0x27f, 0x5, 0x4e, 0x28, 0x2, 
    0x27e, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0x280, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x282, 0x280, 0x3, 0x2, 0x2, 0x2, 0x283, 
    0x28a, 0x5, 0x60, 0x31, 0x2, 0x284, 0x286, 0x5, 0x60, 0x31, 0x2, 0x285, 
    0x284, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 
    0x287, 0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x7, 0x58, 0x2, 0x2, 0x288, 
    0x28a, 0x5, 0x30, 0x19, 0x2, 0x289, 0x283, 0x3, 0x2, 0x2, 0x2, 0x289, 
    0x285, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28d, 
    0x7, 0x1b, 0x2, 0x2, 0x28c, 0x28e, 0x7, 0x6b, 0x2, 0x2, 0x28d, 0x28c, 
    0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 
    0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x7, 0x41, 0x2, 0x2, 0x290, 0x291, 
    0x5, 0x52, 0x2a, 0x2, 0x291, 0x292, 0x7, 0x42, 0x2, 0x2, 0x292, 0x29f, 
    0x3, 0x2, 0x2, 0x2, 0x293, 0x295, 0x7, 0x1b, 0x2, 0x2, 0x294, 0x296, 
    0x7, 0x6b, 0x2, 0x2, 0x295, 0x294, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 
    0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 0x297, 0x298, 
    0x7, 0x41, 0x2, 0x2, 0x298, 0x299, 0x5, 0x52, 0x2a, 0x2, 0x299, 0x29a, 
    0x7, 0x5a, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x42, 0x2, 0x2, 0x29b, 0x29f, 
    0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x1b, 0x2, 0x2, 0x29d, 0x29f, 
    0x7, 0x6b, 0x2, 0x2, 0x29e, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x293, 
    0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x8, 0x2a, 0x1, 0x2, 0x2a1, 0x2a2, 0x5, 
    0x54, 0x2b, 0x2, 0x2a2, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0xc, 
    0x3, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x5a, 0x2, 0x2, 0x2a5, 0x2a7, 0x5, 
    0x54, 0x2b, 0x2, 0x2a6, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2aa, 0x3, 
    0x2, 0x2, 0x2, 0x2a8, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x3, 
    0x2, 0x2, 0x2, 0x2a9, 0x53, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a8, 0x3, 0x2, 
    0x2, 0x2, 0x2ab, 0x2b1, 0x5, 0x56, 0x2c, 0x2, 0x2ac, 0x2ad, 0x5, 0x56, 
    0x2c, 0x2, 0x2ad, 0x2ae, 0x7, 0x5b, 0x2, 0x2, 0x2ae, 0x2af, 0x5, 0x30, 
    0x19, 0x2, 0x2af, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ab, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x2b2, 0x2b3, 0x7, 0x6b, 0x2, 0x2, 0x2b3, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x2b4, 0x2b5, 0x7, 0x35, 0x2, 0x2, 0x2b5, 0x2b6, 0x7, 0x3d, 0x2, 
    0x2, 0x2b6, 0x2b7, 0x5, 0x7a, 0x3e, 0x2, 0x2b7, 0x2b8, 0x7, 0x3e, 0x2, 
    0x2, 0x2b8, 0x59, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x9, 0x8, 0x2, 0x2, 
    0x2ba, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2c2, 0x9, 0x9, 0x2, 0x2, 0x2bc, 
    0x2c2, 0x5, 0x66, 0x34, 0x2, 0x2bd, 0x2be, 0x7, 0xc, 0x2, 0x2, 0x2be, 
    0x2bf, 0x7, 0x3d, 0x2, 0x2, 0x2bf, 0x2c0, 0x7, 0x6b, 0x2, 0x2, 0x2c0, 
    0x2c2, 0x7, 0x3e, 0x2, 0x2, 0x2c1, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
    0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c2, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x7, 0x33, 0x2, 0x2, 0x2c4, 
    0x2c5, 0x7, 0x3d, 0x2, 0x2, 0x2c5, 0x2c6, 0x5, 0x7a, 0x3e, 0x2, 0x2c6, 
    0x2c7, 0x7, 0x3e, 0x2, 0x2, 0x2c7, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2c9, 0x7, 0x33, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x3d, 0x2, 0x2, 0x2ca, 
    0x2cb, 0x5, 0x30, 0x19, 0x2, 0x2cb, 0x2cc, 0x7, 0x3e, 0x2, 0x2, 0x2cc, 
    0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
    0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d1, 
    0x5, 0x6e, 0x38, 0x2, 0x2d0, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 
    0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d6, 
    0x5, 0x62, 0x32, 0x2, 0x2d3, 0x2d5, 0x5, 0x64, 0x33, 0x2, 0x2d4, 0x2d3, 
    0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d4, 
    0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x8, 
    0x32, 0x1, 0x2, 0x2da, 0x2eb, 0x7, 0x6b, 0x2, 0x2, 0x2db, 0x2dc, 0x7, 
    0x3d, 0x2, 0x2, 0x2dc, 0x2dd, 0x5, 0x60, 0x31, 0x2, 0x2dd, 0x2de, 0x7, 
    0x3e, 0x2, 0x2, 0x2de, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 
    0x6b, 0x2, 0x2, 0x2e0, 0x2e1, 0x7, 0x58, 0x2, 0x2, 0x2e1, 0x2eb, 0x7, 
    0x6d, 0x2, 0x2, 0x2e2, 0x2e4, 0x7, 0x3d, 0x2, 0x2, 0x2e3, 0x2e5, 0x5, 
    0x40, 0x21, 0x2, 0x2e4, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x3, 
    0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x5, 
    0x6e, 0x38, 0x2, 0x2e7, 0x2e8, 0x5, 0x62, 0x32, 0x2, 0x2e8, 0x2e9, 0x7, 
    0x3e, 0x2, 0x2, 0x2e9, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2d9, 0x3, 
    0x2, 0x2, 0x2, 0x2ea, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2df, 0x3, 
    0x2, 0x2, 0x2, 0x2ea, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x319, 0x3, 
    0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0xc, 0xa, 0x2, 0x2, 0x2ed, 0x2ef, 0x7, 
    0x3f, 0x2, 0x2, 0x2ee, 0x2f0, 0x5, 0x70, 0x39, 0x2, 0x2ef, 0x2ee, 0x3, 
    0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x3, 
    0x2, 0x2, 0x2, 0x2f1, 0x2f3, 0x5, 0x2a, 0x16, 0x2, 0x2f2, 0x2f1, 0x3, 
    0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 
    0x2, 0x2, 0x2, 0x2f4, 0x318, 0x7, 0x40, 0x2, 0x2, 0x2f5, 0x2f6, 0xc, 
    0x9, 0x2, 0x2, 0x2f6, 0x2f7, 0x7, 0x3f, 0x2, 0x2, 0x2f7, 0x2f9, 0x7, 
    0x2a, 0x2, 0x2, 0x2f8, 0x2fa, 0x5, 0x70, 0x39, 0x2, 0x2f9, 0x2f8, 0x3, 
    0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x3, 
    0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x5, 0x2a, 0x16, 0x2, 0x2fc, 0x2fd, 0x7, 
    0x40, 0x2, 0x2, 0x2fd, 0x318, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0xc, 
    0x8, 0x2, 0x2, 0x2ff, 0x300, 0x7, 0x3f, 0x2, 0x2, 0x300, 0x301, 0x5, 
    0x70, 0x39, 0x2, 0x301, 0x302, 0x7, 0x2a, 0x2, 0x2, 0x302, 0x303, 0x5, 
    0x2a, 0x16, 0x2, 0x303, 0x304, 0x7, 0x40, 0x2, 0x2, 0x304, 0x318, 0x3, 
    0x2, 0x2, 0x2, 0x305, 0x306, 0xc, 0x7, 0x2, 0x2, 0x306, 0x308, 0x7, 
    0x3f, 0x2, 0x2, 0x307, 0x309, 0x5, 0x70, 0x39, 0x2, 0x308, 0x307, 0x3, 
    0x2, 0x2, 0x2, 0x308, 0x309, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 0x3, 
    0x2, 0x2, 0x2, 0x30a, 0x30b, 0x7, 0x4d, 0x2, 0x2, 0x30b, 0x318, 0x7, 
    0x40, 0x2, 0x2, 0x30c, 0x30d, 0xc, 0x6, 0x2, 0x2, 0x30d, 0x30e, 0x7, 
    0x3d, 0x2, 0x2, 0x30e, 0x30f, 0x5, 0x72, 0x3a, 0x2, 0x30f, 0x310, 0x7, 
    0x3e, 0x2, 0x2, 0x310, 0x318, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0xc, 
    0x5, 0x2, 0x2, 0x312, 0x314, 0x7, 0x3d, 0x2, 0x2, 0x313, 0x315, 0x5, 
    0x78, 0x3d, 0x2, 0x314, 0x313, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 0x3, 
    0x2, 0x2, 0x2, 0x315, 0x316, 0x3, 0x2, 0x2, 0x2, 0x316, 0x318, 0x7, 
    0x3e, 0x2, 0x2, 0x317, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x317, 0x2f5, 0x3, 
    0x2, 0x2, 0x2, 0x317, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x317, 0x305, 0x3, 
    0x2, 0x2, 0x2, 0x317, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x317, 0x311, 0x3, 
    0x2, 0x2, 0x2, 0x318, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x319, 0x317, 0x3, 
    0x2, 0x2, 0x2, 0x319, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x31b, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x7, 0xd, 
    0x2, 0x2, 0x31d, 0x31f, 0x7, 0x3d, 0x2, 0x2, 0x31e, 0x320, 0x7, 0x6e, 
    0x2, 0x2, 0x31f, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0x3, 0x2, 
    0x2, 0x2, 0x321, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 
    0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 0x323, 0x326, 0x7, 0x3e, 
    0x2, 0x2, 0x324, 0x326, 0x5, 0x66, 0x34, 0x2, 0x325, 0x31c, 0x3, 0x2, 
    0x2, 0x2, 0x325, 0x324, 0x3, 0x2, 0x2, 0x2, 0x326, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x327, 0x328, 0x7, 0xe, 0x2, 0x2, 0x328, 0x329, 0x7, 0x3d, 0x2, 
    0x2, 0x329, 0x32a, 0x7, 0x3d, 0x2, 0x2, 0x32a, 0x32b, 0x5, 0x68, 0x35, 
    0x2, 0x32b, 0x32c, 0x7, 0x3e, 0x2, 0x2, 0x32c, 0x32d, 0x7, 0x3e, 0x2, 
    0x2, 0x32d, 0x67, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x333, 0x5, 0x6a, 0x36, 
    0x2, 0x32f, 0x330, 0x7, 0x5a, 0x2, 0x2, 0x330, 0x332, 0x5, 0x6a, 0x36, 
    0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x332, 0x335, 0x3, 0x2, 0x2, 
    0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x338, 0x3, 0x2, 0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 
    0x2, 0x336, 0x338, 0x3, 0x2, 0x2, 0x2, 0x337, 0x32e, 0x3, 0x2, 0x2, 
    0x2, 0x337, 0x336, 0x3, 0x2, 0x2, 0x2, 0x338, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x339, 0x33f, 0xa, 0xa, 0x2, 0x2, 0x33a, 0x33c, 0x7, 0x3d, 0x2, 0x2, 
    0x33b, 0x33d, 0x5, 0xc, 0x7, 0x2, 0x33c, 0x33b, 0x3, 0x2, 0x2, 0x2, 
    0x33c, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33e, 0x3, 0x2, 0x2, 0x2, 
    0x33e, 0x340, 0x7, 0x3e, 0x2, 0x2, 0x33f, 0x33a, 0x3, 0x2, 0x2, 0x2, 
    0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x343, 0x3, 0x2, 0x2, 0x2, 
    0x341, 0x343, 0x3, 0x2, 0x2, 0x2, 0x342, 0x339, 0x3, 0x2, 0x2, 0x2, 
    0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x344, 
    0x34a, 0xa, 0xb, 0x2, 0x2, 0x345, 0x346, 0x7, 0x3d, 0x2, 0x2, 0x346, 
    0x347, 0x5, 0x6c, 0x37, 0x2, 0x347, 0x348, 0x7, 0x3e, 0x2, 0x2, 0x348, 
    0x34a, 0x3, 0x2, 0x2, 0x2, 0x349, 0x344, 0x3, 0x2, 0x2, 0x2, 0x349, 
    0x345, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34b, 
    0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x350, 
    0x7, 0x4d, 0x2, 0x2, 0x34f, 0x351, 0x5, 0x70, 0x39, 0x2, 0x350, 0x34f, 
    0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 0x3, 0x2, 0x2, 0x2, 0x351, 0x361, 
    0x3, 0x2, 0x2, 0x2, 0x352, 0x354, 0x7, 0x4d, 0x2, 0x2, 0x353, 0x355, 
    0x5, 0x70, 0x39, 0x2, 0x354, 0x353, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 
    0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x3, 0x2, 0x2, 0x2, 0x356, 0x361, 
    0x5, 0x6e, 0x38, 0x2, 0x357, 0x359, 0x7, 0x54, 0x2, 0x2, 0x358, 0x35a, 
    0x5, 0x70, 0x39, 0x2, 0x359, 0x358, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 
    0x3, 0x2, 0x2, 0x2, 0x35a, 0x361, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35d, 
    0x7, 0x54, 0x2, 0x2, 0x35c, 0x35e, 0x5, 0x70, 0x39, 0x2, 0x35d, 0x35c, 
    0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 
    0x3, 0x2, 0x2, 0x2, 0x35f, 0x361, 0x5, 0x6e, 0x38, 0x2, 0x360, 0x34e, 
    0x3, 0x2, 0x2, 0x2, 0x360, 0x352, 0x3, 0x2, 0x2, 0x2, 0x360, 0x357, 
    0x3, 0x2, 0x2, 0x2, 0x360, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x361, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x362, 0x363, 0x8, 0x39, 0x1, 0x2, 0x363, 0x364, 0x5, 
    0x5a, 0x2e, 0x2, 0x364, 0x369, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 0xc, 
    0x3, 0x2, 0x2, 0x366, 0x368, 0x5, 0x5a, 0x2e, 0x2, 0x367, 0x365, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x369, 0x367, 0x3, 
    0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x372, 0x5, 0x74, 
    0x3b, 0x2, 0x36d, 0x36e, 0x5, 0x74, 0x3b, 0x2, 0x36e, 0x36f, 0x7, 0x5a, 
    0x2, 0x2, 0x36f, 0x370, 0x7, 0x6a, 0x2, 0x2, 0x370, 0x372, 0x3, 0x2, 
    0x2, 0x2, 0x371, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x371, 0x36d, 0x3, 0x2, 
    0x2, 0x2, 0x372, 0x73, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x8, 0x3b, 
    0x1, 0x2, 0x374, 0x375, 0x5, 0x76, 0x3c, 0x2, 0x375, 0x37b, 0x3, 0x2, 
    0x2, 0x2, 0x376, 0x377, 0xc, 0x3, 0x2, 0x2, 0x377, 0x378, 0x7, 0x5a, 
    0x2, 0x2, 0x378, 0x37a, 0x5, 0x76, 0x3c, 0x2, 0x379, 0x376, 0x3, 0x2, 
    0x2, 0x2, 0x37a, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x379, 0x3, 0x2, 
    0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x37d, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x37f, 0x5, 0x34, 0x1b, 
    0x2, 0x37f, 0x380, 0x5, 0x60, 0x31, 0x2, 0x380, 0x386, 0x3, 0x2, 0x2, 
    0x2, 0x381, 0x383, 0x5, 0x36, 0x1c, 0x2, 0x382, 0x384, 0x5, 0x7c, 0x3f, 
    0x2, 0x383, 0x382, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 
    0x2, 0x384, 0x386, 0x3, 0x2, 0x2, 0x2, 0x385, 0x37e, 0x3, 0x2, 0x2, 
    0x2, 0x385, 0x381, 0x3, 0x2, 0x2, 0x2, 0x386, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x387, 0x388, 0x8, 0x3d, 0x1, 0x2, 0x388, 0x389, 0x7, 0x6b, 0x2, 0x2, 
    0x389, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0xc, 0x3, 0x2, 0x2, 
    0x38b, 0x38c, 0x7, 0x5a, 0x2, 0x2, 0x38c, 0x38e, 0x7, 0x6b, 0x2, 0x2, 
    0x38d, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x391, 0x3, 0x2, 0x2, 0x2, 
    0x38f, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 
    0x390, 0x79, 0x3, 0x2, 0x2, 0x2, 0x391, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x392, 
    0x394, 0x5, 0x4a, 0x26, 0x2, 0x393, 0x395, 0x5, 0x7c, 0x3f, 0x2, 0x394, 
    0x393, 0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 0x2, 0x2, 0x2, 0x395, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x396, 0x3a2, 0x5, 0x6e, 0x38, 0x2, 0x397, 
    0x399, 0x5, 0x6e, 0x38, 0x2, 0x398, 0x397, 0x3, 0x2, 0x2, 0x2, 0x398, 
    0x399, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x39a, 
    0x39e, 0x5, 0x7e, 0x40, 0x2, 0x39b, 0x39d, 0x5, 0x64, 0x33, 0x2, 0x39c, 
    0x39b, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x39e, 
    0x39c, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 
    0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
    0x396, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x398, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x8, 0x40, 0x1, 0x2, 0x3a4, 
    0x3a5, 0x7, 0x3d, 0x2, 0x2, 0x3a5, 0x3a6, 0x5, 0x7c, 0x3f, 0x2, 0x3a6, 
    0x3aa, 0x7, 0x3e, 0x2, 0x2, 0x3a7, 0x3a9, 0x5, 0x64, 0x33, 0x2, 0x3a8, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
    0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ad, 
    0x3af, 0x7, 0x3f, 0x2, 0x2, 0x3ae, 0x3b0, 0x5, 0x70, 0x39, 0x2, 0x3af, 
    0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 
    0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b3, 0x5, 0x2a, 0x16, 0x2, 0x3b2, 
    0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 
    0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3d2, 0x7, 0x40, 0x2, 0x2, 0x3b5, 
    0x3b6, 0x7, 0x3f, 0x2, 0x2, 0x3b6, 0x3b8, 0x7, 0x2a, 0x2, 0x2, 0x3b7, 
    0x3b9, 0x5, 0x70, 0x39, 0x2, 0x3b8, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b8, 
    0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3ba, 
    0x3bb, 0x5, 0x2a, 0x16, 0x2, 0x3bb, 0x3bc, 0x7, 0x40, 0x2, 0x2, 0x3bc, 
    0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x7, 0x3f, 0x2, 0x2, 0x3be, 
    0x3bf, 0x5, 0x70, 0x39, 0x2, 0x3bf, 0x3c0, 0x7, 0x2a, 0x2, 0x2, 0x3c0, 
    0x3c1, 0x5, 0x2a, 0x16, 0x2, 0x3c1, 0x3c2, 0x7, 0x40, 0x2, 0x2, 0x3c2, 
    0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x7, 0x3f, 0x2, 0x2, 0x3c4, 
    0x3c5, 0x7, 0x4d, 0x2, 0x2, 0x3c5, 0x3d2, 0x7, 0x40, 0x2, 0x2, 0x3c6, 
    0x3c8, 0x7, 0x3d, 0x2, 0x2, 0x3c7, 0x3c9, 0x5, 0x72, 0x3a, 0x2, 0x3c8, 
    0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3ce, 0x7, 0x3e, 0x2, 0x2, 0x3cb, 
    0x3cd, 0x5, 0x64, 0x33, 0x2, 0x3cc, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cd, 
    0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
    0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d0, 
    0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
    0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
    0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
    0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3d3, 
    0x3d4, 0xc, 0x7, 0x2, 0x2, 0x3d4, 0x3d6, 0x7, 0x3f, 0x2, 0x2, 0x3d5, 
    0x3d7, 0x5, 0x70, 0x39, 0x2, 0x3d6, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d6, 
    0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3d8, 
    0x3da, 0x5, 0x2a, 0x16, 0x2, 0x3d9, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3d9, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3db, 
    0x3fd, 0x7, 0x40, 0x2, 0x2, 0x3dc, 0x3dd, 0xc, 0x6, 0x2, 0x2, 0x3dd, 
    0x3de, 0x7, 0x3f, 0x2, 0x2, 0x3de, 0x3e0, 0x7, 0x2a, 0x2, 0x2, 0x3df, 
    0x3e1, 0x5, 0x70, 0x39, 0x2, 0x3e0, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
    0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3e3, 0x5, 0x2a, 0x16, 0x2, 0x3e3, 0x3e4, 0x7, 0x40, 0x2, 0x2, 0x3e4, 
    0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0xc, 0x5, 0x2, 0x2, 0x3e6, 
    0x3e7, 0x7, 0x3f, 0x2, 0x2, 0x3e7, 0x3e8, 0x5, 0x70, 0x39, 0x2, 0x3e8, 
    0x3e9, 0x7, 0x2a, 0x2, 0x2, 0x3e9, 0x3ea, 0x5, 0x2a, 0x16, 0x2, 0x3ea, 
    0x3eb, 0x7, 0x40, 0x2, 0x2, 0x3eb, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3ec, 
    0x3ed, 0xc, 0x4, 0x2, 0x2, 0x3ed, 0x3ee, 0x7, 0x3f, 0x2, 0x2, 0x3ee, 
    0x3ef, 0x7, 0x4d, 0x2, 0x2, 0x3ef, 0x3fd, 0x7, 0x40, 0x2, 0x2, 0x3f0, 
    0x3f1, 0xc, 0x3, 0x2, 0x2, 0x3f1, 0x3f3, 0x7, 0x3d, 0x2, 0x2, 0x3f2, 
    0x3f4, 0x5, 0x72, 0x3a, 0x2, 0x3f3, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
    0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f5, 
    0x3f9, 0x7, 0x3e, 0x2, 0x2, 0x3f6, 0x3f8, 0x5, 0x64, 0x33, 0x2, 0x3f7, 
    0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3f9, 
    0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x3fa, 
    0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
    0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
    0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
    0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x400, 0x3, 0x2, 0x2, 0x2, 0x3fe, 
    0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3ff, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x400, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x401, 0x402, 
    0x7, 0x6b, 0x2, 0x2, 0x402, 0x81, 0x3, 0x2, 0x2, 0x2, 0x403, 0x40e, 
    0x5, 0x2a, 0x16, 0x2, 0x404, 0x405, 0x7, 0x41, 0x2, 0x2, 0x405, 0x406, 
    0x5, 0x84, 0x43, 0x2, 0x406, 0x407, 0x7, 0x42, 0x2, 0x2, 0x407, 0x40e, 
    0x3, 0x2, 0x2, 0x2, 0x408, 0x409, 0x7, 0x41, 0x2, 0x2, 0x409, 0x40a, 
    0x5, 0x84, 0x43, 0x2, 0x40a, 0x40b, 0x7, 0x5a, 0x2, 0x2, 0x40b, 0x40c, 
    0x7, 0x42, 0x2, 0x2, 0x40c, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x403, 
    0x3, 0x2, 0x2, 0x2, 0x40d, 0x404, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x408, 
    0x3, 0x2, 0x2, 0x2, 0x40e, 0x83, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x411, 0x8, 
    0x43, 0x1, 0x2, 0x410, 0x412, 0x5, 0x86, 0x44, 0x2, 0x411, 0x410, 0x3, 
    0x2, 0x2, 0x2, 0x411, 0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 
    0x2, 0x2, 0x2, 0x413, 0x414, 0x5, 0x82, 0x42, 0x2, 0x414, 0x41d, 0x3, 
    0x2, 0x2, 0x2, 0x415, 0x416, 0xc, 0x3, 0x2, 0x2, 0x416, 0x418, 0x7, 
    0x5a, 0x2, 0x2, 0x417, 0x419, 0x5, 0x86, 0x44, 0x2, 0x418, 0x417, 0x3, 
    0x2, 0x2, 0x2, 0x418, 0x419, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 0x3, 
    0x2, 0x2, 0x2, 0x41a, 0x41c, 0x5, 0x82, 0x42, 0x2, 0x41b, 0x415, 0x3, 
    0x2, 0x2, 0x2, 0x41c, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x41b, 0x3, 
    0x2, 0x2, 0x2, 0x41d, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x41f, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 0x5, 0x88, 
    0x45, 0x2, 0x421, 0x422, 0x7, 0x5b, 0x2, 0x2, 0x422, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x423, 0x424, 0x8, 0x45, 0x1, 0x2, 0x424, 0x425, 0x5, 0x8a, 
    0x46, 0x2, 0x425, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x426, 0x427, 0xc, 0x3, 
    0x2, 0x2, 0x427, 0x429, 0x5, 0x8a, 0x46, 0x2, 0x428, 0x426, 0x3, 0x2, 
    0x2, 0x2, 0x429, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x428, 0x3, 0x2, 
    0x2, 0x2, 0x42a, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x42c, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42e, 0x7, 0x3f, 0x2, 
    0x2, 0x42e, 0x42f, 0x5, 0x30, 0x19, 0x2, 0x42f, 0x430, 0x7, 0x40, 0x2, 
    0x2, 0x430, 0x434, 0x3, 0x2, 0x2, 0x2, 0x431, 0x432, 0x7, 0x69, 0x2, 
    0x2, 0x432, 0x434, 0x7, 0x6b, 0x2, 0x2, 0x433, 0x42d, 0x3, 0x2, 0x2, 
    0x2, 0x433, 0x431, 0x3, 0x2, 0x2, 0x2, 0x434, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x435, 0x436, 0x7, 0x3b, 0x2, 0x2, 0x436, 0x437, 0x7, 0x3d, 0x2, 0x2, 
    0x437, 0x438, 0x5, 0x30, 0x19, 0x2, 0x438, 0x43a, 0x7, 0x5a, 0x2, 0x2, 
    0x439, 0x43b, 0x7, 0x6e, 0x2, 0x2, 0x43a, 0x439, 0x3, 0x2, 0x2, 0x2, 
    0x43b, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43a, 0x3, 0x2, 0x2, 0x2, 
    0x43c, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x3, 0x2, 0x2, 0x2, 
    0x43e, 0x43f, 0x7, 0x3e, 0x2, 0x2, 0x43f, 0x440, 0x7, 0x59, 0x2, 0x2, 
    0x440, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x441, 0x467, 0x5, 0x90, 0x49, 0x2, 
    0x442, 0x467, 0x5, 0x92, 0x4a, 0x2, 0x443, 0x467, 0x5, 0x98, 0x4d, 0x2, 
    0x444, 0x467, 0x5, 0x9a, 0x4e, 0x2, 0x445, 0x467, 0x5, 0x9c, 0x4f, 0x2, 
    0x446, 0x467, 0x5, 0xa4, 0x53, 0x2, 0x447, 0x448, 0x9, 0xc, 0x2, 0x2, 
    0x448, 0x449, 0x9, 0xd, 0x2, 0x2, 0x449, 0x452, 0x7, 0x3d, 0x2, 0x2, 
    0x44a, 0x44f, 0x5, 0x26, 0x14, 0x2, 0x44b, 0x44c, 0x7, 0x5a, 0x2, 0x2, 
    0x44c, 0x44e, 0x5, 0x26, 0x14, 0x2, 0x44d, 0x44b, 0x3, 0x2, 0x2, 0x2, 
    0x44e, 0x451, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x44d, 0x3, 0x2, 0x2, 0x2, 
    0x44f, 0x450, 0x3, 0x2, 0x2, 0x2, 0x450, 0x453, 0x3, 0x2, 0x2, 0x2, 
    0x451, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x452, 0x44a, 0x3, 0x2, 0x2, 0x2, 
    0x452, 0x453, 0x3, 0x2, 0x2, 0x2, 0x453, 0x461, 0x3, 0x2, 0x2, 0x2, 
    0x454, 0x45d, 0x7, 0x58, 0x2, 0x2, 0x455, 0x45a, 0x5, 0x26, 0x14, 0x2, 
    0x456, 0x457, 0x7, 0x5a, 0x2, 0x2, 0x457, 0x459, 0x5, 0x26, 0x14, 0x2, 
    0x458, 0x456, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45c, 0x3, 0x2, 0x2, 0x2, 
    0x45a, 0x458, 0x3, 0x2, 0x2, 0x2, 0x45a, 0x45b, 0x3, 0x2, 0x2, 0x2, 
    0x45b, 0x45e, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45a, 0x3, 0x2, 0x2, 0x2, 
    0x45d, 0x455, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x45e, 0x3, 0x2, 0x2, 0x2, 
    0x45e, 0x460, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x454, 0x3, 0x2, 0x2, 0x2, 
    0x460, 0x463, 0x3, 0x2, 0x2, 0x2, 0x461, 0x45f, 0x3, 0x2, 0x2, 0x2, 
    0x461, 0x462, 0x3, 0x2, 0x2, 0x2, 0x462, 0x464, 0x3, 0x2, 0x2, 0x2, 
    0x463, 0x461, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 0x7, 0x3e, 0x2, 0x2, 
    0x465, 0x467, 0x7, 0x59, 0x2, 0x2, 0x466, 0x441, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x442, 0x3, 0x2, 0x2, 0x2, 0x466, 0x443, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x444, 0x3, 0x2, 0x2, 0x2, 0x466, 0x445, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x446, 0x3, 0x2, 0x2, 0x2, 0x466, 0x447, 0x3, 0x2, 0x2, 0x2, 
    0x467, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x468, 0x469, 0x7, 0x6b, 0x2, 0x2, 
    0x469, 0x46a, 0x7, 0x58, 0x2, 0x2, 0x46a, 0x474, 0x5, 0x8e, 0x48, 0x2, 
    0x46b, 0x46c, 0x7, 0x13, 0x2, 0x2, 0x46c, 0x46d, 0x5, 0x30, 0x19, 0x2, 
    0x46d, 0x46e, 0x7, 0x58, 0x2, 0x2, 0x46e, 0x46f, 0x5, 0x8e, 0x48, 0x2, 
    0x46f, 0x474, 0x3, 0x2, 0x2, 0x2, 0x470, 0x471, 0x7, 0x17, 0x2, 0x2, 
    0x471, 0x472, 0x7, 0x58, 0x2, 0x2, 0x472, 0x474, 0x5, 0x8e, 0x48, 0x2, 
    0x473, 0x468, 0x3, 0x2, 0x2, 0x2, 0x473, 0x46b, 0x3, 0x2, 0x2, 0x2, 
    0x473, 0x470, 0x3, 0x2, 0x2, 0x2, 0x474, 0x91, 0x3, 0x2, 0x2, 0x2, 0x475, 
    0x477, 0x7, 0x41, 0x2, 0x2, 0x476, 0x478, 0x5, 0x94, 0x4b, 0x2, 0x477, 
    0x476, 0x3, 0x2, 0x2, 0x2, 0x477, 0x478, 0x3, 0x2, 0x2, 0x2, 0x478, 
    0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 0x47a, 0x7, 0x42, 0x2, 0x2, 0x47a, 
    0x93, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47c, 0x8, 0x4b, 0x1, 0x2, 0x47c, 
    0x47d, 0x5, 0x96, 0x4c, 0x2, 0x47d, 0x482, 0x3, 0x2, 0x2, 0x2, 0x47e, 
    0x47f, 0xc, 0x3, 0x2, 0x2, 0x47f, 0x481, 0x5, 0x96, 0x4c, 0x2, 0x480, 
    0x47e, 0x3, 0x2, 0x2, 0x2, 0x481, 0x484, 0x3, 0x2, 0x2, 0x2, 0x482, 
    0x480, 0x3, 0x2, 0x2, 0x2, 0x482, 0x483, 0x3, 0x2, 0x2, 0x2, 0x483, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x484, 0x482, 0x3, 0x2, 0x2, 0x2, 0x485, 0x488, 
    0x5, 0x8e, 0x48, 0x2, 0x486, 0x488, 0x5, 0x32, 0x1a, 0x2, 0x487, 0x485, 
    0x3, 0x2, 0x2, 0x2, 0x487, 0x486, 0x3, 0x2, 0x2, 0x2, 0x488, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x489, 0x48b, 0x5, 0x2e, 0x18, 0x2, 0x48a, 0x489, 0x3, 
    0x2, 0x2, 0x2, 0x48a, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x48c, 0x3, 
    0x2, 0x2, 0x2, 0x48c, 0x48d, 0x7, 0x59, 0x2, 0x2, 0x48d, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x48e, 0x48f, 0x7, 0x20, 0x2, 0x2, 0x48f, 0x490, 0x7, 
    0x3d, 0x2, 0x2, 0x490, 0x491, 0x5, 0x2e, 0x18, 0x2, 0x491, 0x492, 0x7, 
    0x3e, 0x2, 0x2, 0x492, 0x495, 0x5, 0x8e, 0x48, 0x2, 0x493, 0x494, 0x7, 
    0x1a, 0x2, 0x2, 0x494, 0x496, 0x5, 0x8e, 0x48, 0x2, 0x495, 0x493, 0x3, 
    0x2, 0x2, 0x2, 0x495, 0x496, 0x3, 0x2, 0x2, 0x2, 0x496, 0x49e, 0x3, 
    0x2, 0x2, 0x2, 0x497, 0x498, 0x7, 0x2c, 0x2, 0x2, 0x498, 0x499, 0x7, 
    0x3d, 0x2, 0x2, 0x499, 0x49a, 0x5, 0x2e, 0x18, 0x2, 0x49a, 0x49b, 0x7, 
    0x3e, 0x2, 0x2, 0x49b, 0x49c, 0x5, 0x8e, 0x48, 0x2, 0x49c, 0x49e, 0x3, 
    0x2, 0x2, 0x2, 0x49d, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x49d, 0x497, 0x3, 
    0x2, 0x2, 0x2, 0x49e, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a0, 0x7, 0x32, 
    0x2, 0x2, 0x4a0, 0x4a1, 0x7, 0x3d, 0x2, 0x2, 0x4a1, 0x4a2, 0x5, 0x2e, 
    0x18, 0x2, 0x4a2, 0x4a3, 0x7, 0x3e, 0x2, 0x2, 0x4a3, 0x4a4, 0x5, 0x8e, 
    0x48, 0x2, 0x4a4, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a6, 0x7, 0x18, 
    0x2, 0x2, 0x4a6, 0x4a7, 0x5, 0x8e, 0x48, 0x2, 0x4a7, 0x4a8, 0x7, 0x32, 
    0x2, 0x2, 0x4a8, 0x4a9, 0x7, 0x3d, 0x2, 0x2, 0x4a9, 0x4aa, 0x5, 0x2e, 
    0x18, 0x2, 0x4aa, 0x4ab, 0x7, 0x3e, 0x2, 0x2, 0x4ab, 0x4ac, 0x7, 0x59, 
    0x2, 0x2, 0x4ac, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 0x7, 0x1e, 
    0x2, 0x2, 0x4ae, 0x4af, 0x7, 0x3d, 0x2, 0x2, 0x4af, 0x4b0, 0x5, 0x9e, 
    0x50, 0x2, 0x4b0, 0x4b1, 0x7, 0x3e, 0x2, 0x2, 0x4b1, 0x4b2, 0x5, 0x8e, 
    0x48, 0x2, 0x4b2, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x49f, 0x3, 0x2, 
    0x2, 0x2, 0x4b3, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4ad, 0x3, 0x2, 
    0x2, 0x2, 0x4b4, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4b6, 0x5, 0xa0, 
    0x51, 0x2, 0x4b6, 0x4b8, 0x7, 0x59, 0x2, 0x2, 0x4b7, 0x4b9, 0x5, 0xa2, 
    0x52, 0x2, 0x4b8, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b9, 0x3, 0x2, 
    0x2, 0x2, 0x4b9, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bc, 0x7, 0x59, 
    0x2, 0x2, 0x4bb, 0x4bd, 0x5, 0xa2, 0x52, 0x2, 0x4bc, 0x4bb, 0x3, 0x2, 
    0x2, 0x2, 0x4bc, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4ca, 0x3, 0x2, 
    0x2, 0x2, 0x4be, 0x4c0, 0x5, 0x2e, 0x18, 0x2, 0x4bf, 0x4be, 0x3, 0x2, 
    0x2, 0x2, 0x4bf, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c1, 0x3, 0x2, 
    0x2, 0x2, 0x4c1, 0x4c3, 0x7, 0x59, 0x2, 0x2, 0x4c2, 0x4c4, 0x5, 0xa2, 
    0x52, 0x2, 0x4c3, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c4, 0x3, 0x2, 
    0x2, 0x2, 0x4c4, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c7, 0x7, 0x59, 
    0x2, 0x2, 0x4c6, 0x4c8, 0x5, 0xa2, 0x52, 0x2, 0x4c7, 0x4c6, 0x3, 0x2, 
    0x2, 0x2, 0x4c7, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4ca, 0x3, 0x2, 
    0x2, 0x2, 0x4c9, 0x4b5, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4bf, 0x3, 0x2, 
    0x2, 0x2, 0x4ca, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cc, 0x5, 0x34, 
    0x1b, 0x2, 0x4cc, 0x4cd, 0x5, 0x3a, 0x1e, 0x2, 0x4cd, 0x4d0, 0x3, 0x2, 
    0x2, 0x2, 0x4ce, 0x4d0, 0x5, 0x34, 0x1b, 0x2, 0x4cf, 0x4cb, 0x3, 0x2, 
    0x2, 0x2, 0x4cf, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x4d1, 0x4d2, 0x8, 0x52, 0x1, 0x2, 0x4d2, 0x4d3, 0x5, 0x2a, 0x16, 
    0x2, 0x4d3, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 0xc, 0x3, 0x2, 
    0x2, 0x4d5, 0x4d6, 0x7, 0x5a, 0x2, 0x2, 0x4d6, 0x4d8, 0x5, 0x2a, 0x16, 
    0x2, 0x4d7, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d8, 0x4db, 0x3, 0x2, 0x2, 
    0x2, 0x4d9, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4da, 0x3, 0x2, 0x2, 
    0x2, 0x4da, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x4db, 0x4d9, 0x3, 0x2, 0x2, 0x2, 
    0x4dc, 0x4dd, 0x7, 0x1f, 0x2, 0x2, 0x4dd, 0x4de, 0x7, 0x6b, 0x2, 0x2, 
    0x4de, 0x4ed, 0x7, 0x59, 0x2, 0x2, 0x4df, 0x4e0, 0x7, 0x16, 0x2, 0x2, 
    0x4e0, 0x4ed, 0x7, 0x59, 0x2, 0x2, 0x4e1, 0x4e2, 0x7, 0x12, 0x2, 0x2, 
    0x4e2, 0x4ed, 0x7, 0x59, 0x2, 0x2, 0x4e3, 0x4e5, 0x7, 0x26, 0x2, 0x2, 
    0x4e4, 0x4e6, 0x5, 0x2e, 0x18, 0x2, 0x4e5, 0x4e4, 0x3, 0x2, 0x2, 0x2, 
    0x4e5, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e7, 0x3, 0x2, 0x2, 0x2, 
    0x4e7, 0x4ed, 0x7, 0x59, 0x2, 0x2, 0x4e8, 0x4e9, 0x7, 0x1f, 0x2, 0x2, 
    0x4e9, 0x4ea, 0x5, 0xe, 0x8, 0x2, 0x4ea, 0x4eb, 0x7, 0x59, 0x2, 0x2, 
    0x4eb, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4dc, 0x3, 0x2, 0x2, 0x2, 
    0x4ec, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4e1, 0x3, 0x2, 0x2, 0x2, 
    0x4ec, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4e8, 0x3, 0x2, 0x2, 0x2, 
    0x4ed, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4f0, 0x5, 0xa8, 0x55, 0x2, 
    0x4ef, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x3, 0x2, 0x2, 0x2, 
    0x4f0, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f2, 0x7, 0x2, 0x2, 0x3, 
    0x4f2, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f4, 0x8, 0x55, 0x1, 0x2, 
    0x4f4, 0x4f5, 0x5, 0xaa, 0x56, 0x2, 0x4f5, 0x4fa, 0x3, 0x2, 0x2, 0x2, 
    0x4f6, 0x4f7, 0xc, 0x3, 0x2, 0x2, 0x4f7, 0x4f9, 0x5, 0xaa, 0x56, 0x2, 
    0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fc, 0x3, 0x2, 0x2, 0x2, 
    0x4fa, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4fb, 0x3, 0x2, 0x2, 0x2, 
    0x4fb, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
    0x501, 0x5, 0xac, 0x57, 0x2, 0x4fe, 0x501, 0x5, 0x32, 0x1a, 0x2, 0x4ff, 
    0x501, 0x7, 0x59, 0x2, 0x2, 0x500, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x500, 
    0x4fe, 0x3, 0x2, 0x2, 0x2, 0x500, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x501, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x502, 0x504, 0x5, 0x34, 0x1b, 0x2, 0x503, 
    0x502, 0x3, 0x2, 0x2, 0x2, 0x503, 0x504, 0x3, 0x2, 0x2, 0x2, 0x504, 
    0x505, 0x3, 0x2, 0x2, 0x2, 0x505, 0x507, 0x5, 0x60, 0x31, 0x2, 0x506, 
    0x508, 0x5, 0xae, 0x58, 0x2, 0x507, 0x506, 0x3, 0x2, 0x2, 0x2, 0x507, 
    0x508, 0x3, 0x2, 0x2, 0x2, 0x508, 0x509, 0x3, 0x2, 0x2, 0x2, 0x509, 
    0x50a, 0x5, 0x92, 0x4a, 0x2, 0x50a, 0xad, 0x3, 0x2, 0x2, 0x2, 0x50b, 
    0x50c, 0x8, 0x58, 0x1, 0x2, 0x50c, 0x50d, 0x5, 0x32, 0x1a, 0x2, 0x50d, 
    0x512, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x50f, 0xc, 0x3, 0x2, 0x2, 0x50f, 
    0x511, 0x5, 0x32, 0x1a, 0x2, 0x510, 0x50e, 0x3, 0x2, 0x2, 0x2, 0x511, 
    0x514, 0x3, 0x2, 0x2, 0x2, 0x512, 0x510, 0x3, 0x2, 0x2, 0x2, 0x512, 
    0x513, 0x3, 0x2, 0x2, 0x2, 0x513, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x514, 0x512, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0xb5, 0xbd, 0xd1, 0xe2, 0xec, 0x110, 0x11a, 
    0x127, 0x129, 0x134, 0x14d, 0x15e, 0x16c, 0x16e, 0x17a, 0x17c, 0x188, 
    0x18a, 0x19c, 0x19e, 0x1aa, 0x1ac, 0x1b7, 0x1c2, 0x1cd, 0x1d8, 0x1e3, 
    0x1ec, 0x1f4, 0x200, 0x20d, 0x212, 0x217, 0x21e, 0x228, 0x230, 0x243, 
    0x249, 0x24e, 0x257, 0x262, 0x267, 0x26c, 0x270, 0x274, 0x276, 0x280, 
    0x285, 0x289, 0x28d, 0x295, 0x29e, 0x2a8, 0x2b0, 0x2c1, 0x2cd, 0x2d0, 
    0x2d6, 0x2e4, 0x2ea, 0x2ef, 0x2f2, 0x2f9, 0x308, 0x314, 0x317, 0x319, 
    0x321, 0x325, 0x333, 0x337, 0x33c, 0x33f, 0x342, 0x349, 0x34b, 0x350, 
    0x354, 0x359, 0x35d, 0x360, 0x369, 0x371, 0x37b, 0x383, 0x385, 0x38f, 
    0x394, 0x398, 0x39e, 0x3a1, 0x3aa, 0x3af, 0x3b2, 0x3b8, 0x3c8, 0x3ce, 
    0x3d1, 0x3d6, 0x3d9, 0x3e0, 0x3f3, 0x3f9, 0x3fc, 0x3fe, 0x40d, 0x411, 
    0x418, 0x41d, 0x42a, 0x433, 0x43c, 0x44f, 0x452, 0x45a, 0x45d, 0x461, 
    0x466, 0x473, 0x477, 0x482, 0x487, 0x48a, 0x495, 0x49d, 0x4b3, 0x4b8, 
    0x4bc, 0x4bf, 0x4c3, 0x4c7, 0x4c9, 0x4cf, 0x4d9, 0x4e5, 0x4ec, 0x4ef, 
    0x4fa, 0x500, 0x503, 0x507, 0x512, 
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
