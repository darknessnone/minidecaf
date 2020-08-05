
// Generated from MiniDecaf.g4 by ANTLR 4.8


#include "MiniDecafLexer.h"


using namespace antlr4;


MiniDecafLexer::MiniDecafLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MiniDecafLexer::~MiniDecafLexer() {
  delete _interpreter;
}

std::string MiniDecafLexer::getGrammarFileName() const {
  return "MiniDecaf.g4";
}

const std::vector<std::string>& MiniDecafLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& MiniDecafLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& MiniDecafLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& MiniDecafLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& MiniDecafLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> MiniDecafLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& MiniDecafLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> MiniDecafLexer::_decisionToDFA;
atn::PredictionContextCache MiniDecafLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MiniDecafLexer::_atn;
std::vector<uint16_t> MiniDecafLexer::_serializedATN;

std::vector<std::string> MiniDecafLexer::_ruleNames = {
  u8"WS", u8"INT", u8"SEMICOLON", u8"ADD", u8"SUB", u8"MUL", u8"DIV", u8"LPAREN", 
  u8"RPAREN", u8"EQ", u8"NEQ", u8"LT", u8"LE", u8"GT", u8"GE", u8"ASSIGN", 
  u8"ID", u8"RET"
};

std::vector<std::string> MiniDecafLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> MiniDecafLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> MiniDecafLexer::_literalNames = {
  "", "", "", u8"';'", u8"'+'", u8"'-'", u8"'*'", u8"'/'", u8"'('", u8"')'", 
  u8"'=='", u8"'!='", u8"'<'", u8"'<='", u8"'>'", u8"'>='", u8"'='", "", 
  u8"'return '"
};

std::vector<std::string> MiniDecafLexer::_symbolicNames = {
  "", u8"WS", u8"INT", u8"SEMICOLON", u8"ADD", u8"SUB", u8"MUL", u8"DIV", 
  u8"LPAREN", u8"RPAREN", u8"EQ", u8"NEQ", u8"LT", u8"LE", u8"GT", u8"GE", 
  u8"ASSIGN", u8"ID", u8"RET"
};

dfa::Vocabulary MiniDecafLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MiniDecafLexer::_tokenNames;

MiniDecafLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x14, 0x5f, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
    0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 
    0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 
    0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 
    0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0x2d, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0x2e, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x7, 0x12, 0x53, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x56, 0xb, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x2, 0x2, 0x14, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 
    0x7, 0xd, 0x8, 0xf, 0x9, 0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 
    0x19, 0xe, 0x1b, 0xf, 0x1d, 0x10, 0x1f, 0x11, 0x21, 0x12, 0x23, 0x13, 
    0x25, 0x14, 0x3, 0x2, 0x6, 0x5, 0x2, 0xb, 0xc, 0xf, 0xf, 0x22, 0x22, 
    0x3, 0x2, 0x32, 0x3b, 0x5, 0x2, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 
    0x6, 0x2, 0x32, 0x3b, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 0x2, 0x60, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x3, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x5, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x7, 0x30, 0x3, 0x2, 0x2, 0x2, 
    0x9, 0x32, 0x3, 0x2, 0x2, 0x2, 0xb, 0x34, 0x3, 0x2, 0x2, 0x2, 0xd, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0x38, 0x3, 0x2, 0x2, 0x2, 0x11, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x13, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x15, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x41, 0x3, 0x2, 0x2, 0x2, 0x19, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x46, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x21, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x25, 0x57, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 
    0x9, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x8, 
    0x2, 0x2, 0x2, 0x2a, 0x4, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x9, 0x3, 
    0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x6, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x3d, 0x2, 0x2, 0x31, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0x2d, 0x2, 0x2, 0x33, 0xa, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x2f, 0x2, 0x2, 0x35, 0xc, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x2c, 0x2, 0x2, 0x37, 0xe, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x39, 0x7, 0x31, 0x2, 0x2, 0x39, 0x10, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x3b, 0x7, 0x2a, 0x2, 0x2, 0x3b, 0x12, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x7, 0x2b, 0x2, 0x2, 0x3d, 0x14, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3f, 0x7, 0x3f, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x3f, 0x2, 0x2, 0x40, 0x16, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x23, 0x2, 0x2, 0x42, 0x43, 0x7, 
    0x3f, 0x2, 0x2, 0x43, 0x18, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x3e, 
    0x2, 0x2, 0x45, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x3e, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x3f, 0x2, 0x2, 0x48, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x40, 0x2, 0x2, 0x4a, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4c, 0x7, 0x40, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x3f, 0x2, 0x2, 0x4d, 0x20, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x3f, 0x2, 0x2, 0x4f, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x54, 0x9, 0x4, 0x2, 0x2, 0x51, 0x53, 0x9, 0x5, 
    0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x24, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x58, 0x7, 0x74, 0x2, 0x2, 0x58, 0x59, 0x7, 0x67, 0x2, 0x2, 0x59, 0x5a, 
    0x7, 0x76, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x77, 0x2, 0x2, 0x5b, 0x5c, 0x7, 
    0x74, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x70, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x22, 
    0x2, 0x2, 0x5e, 0x26, 0x3, 0x2, 0x2, 0x2, 0x5, 0x2, 0x2e, 0x54, 0x3, 
    0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MiniDecafLexer::Initializer MiniDecafLexer::_init;
