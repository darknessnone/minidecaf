
// Generated from MiniDecaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  MiniDecafLexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, INTEGER = 2, SEMICOLON = 3, COMMA = 4, ADD = 5, SUB = 6, MUL = 7, 
    AND = 8, DIV = 9, NOT = 10, BITNOT = 11, LPAREN = 12, RPAREN = 13, LBRACE = 14, 
    RBRACE = 15, LSQUBRACE = 16, RSQUBRACE = 17, EQ = 18, NEQ = 19, LT = 20, 
    LE = 21, GT = 22, GE = 23, LAND = 24, LOR = 25, ASSIGN = 26, SIZEOF = 27, 
    INT = 28, RET = 29, IF = 30, ELSE = 31, WHILE = 32, FOR = 33, ID = 34
  };

  MiniDecafLexer(antlr4::CharStream *input);
  ~MiniDecafLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

