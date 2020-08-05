
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
  u8"WS", u8"INT", u8"SEMICOLON"
};

std::vector<std::string> MiniDecafLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> MiniDecafLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> MiniDecafLexer::_literalNames = {
  "", "", "", u8"';'"
};

std::vector<std::string> MiniDecafLexer::_symbolicNames = {
  "", u8"WS", u8"INT", u8"SEMICOLON"
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
    0x2, 0x5, 0x14, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 
    0x3, 0xf, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x10, 0x3, 0x4, 0x3, 0x4, 0x2, 
    0x2, 0x5, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x3, 0x2, 0x4, 0x5, 0x2, 0xb, 
    0xc, 0xf, 0xf, 0x22, 0x22, 0x3, 0x2, 0x32, 0x3b, 0x2, 0x14, 0x2, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x3, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x7, 0x12, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x9, 0x2, 0x2, 0x2, 0xa, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x8, 0x2, 0x2, 0x2, 0xc, 0x4, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0xf, 0x9, 0x3, 0x2, 0x2, 0xe, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x10, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x6, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 
    0x7, 0x3d, 0x2, 0x2, 0x13, 0x8, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2, 0x10, 
    0x3, 0x8, 0x2, 0x2, 
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
