
// Generated from Memcached.g4 by ANTLR 4.9.3


#include "MemcachedListener.h"
#include "MemcachedVisitor.h"

#include "MemcachedParser.h"


using namespace antlrcpp;
using namespace antlr4;

MemcachedParser::MemcachedParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MemcachedParser::~MemcachedParser() {
  delete _interpreter;
}

std::string MemcachedParser::getGrammarFileName() const {
  return "Memcached.g4";
}

const std::vector<std::string>& MemcachedParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MemcachedParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CommandsContext ------------------------------------------------------------------

MemcachedParser::CommandsContext::CommandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemcachedParser::CommandContext *> MemcachedParser::CommandsContext::command() {
  return getRuleContexts<MemcachedParser::CommandContext>();
}

MemcachedParser::CommandContext* MemcachedParser::CommandsContext::command(size_t i) {
  return getRuleContext<MemcachedParser::CommandContext>(i);
}


size_t MemcachedParser::CommandsContext::getRuleIndex() const {
  return MemcachedParser::RuleCommands;
}

void MemcachedParser::CommandsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommands(this);
}

void MemcachedParser::CommandsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommands(this);
}


antlrcpp::Any MemcachedParser::CommandsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemcachedVisitor*>(visitor))
    return parserVisitor->visitCommands(this);
  else
    return visitor->visitChildren(this);
}

MemcachedParser::CommandsContext* MemcachedParser::commands() {
  CommandsContext *_localctx = _tracker.createInstance<CommandsContext>(_ctx, getState());
  enterRule(_localctx, 0, MemcachedParser::RuleCommands);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(8);
      command();
      setState(11); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MemcachedParser::Storagecmd

    || _la == MemcachedParser::TEXTCMD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

MemcachedParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemcachedParser::StoragecmdContext* MemcachedParser::CommandContext::storagecmd() {
  return getRuleContext<MemcachedParser::StoragecmdContext>(0);
}

MemcachedParser::OthercommandContext* MemcachedParser::CommandContext::othercommand() {
  return getRuleContext<MemcachedParser::OthercommandContext>(0);
}


size_t MemcachedParser::CommandContext::getRuleIndex() const {
  return MemcachedParser::RuleCommand;
}

void MemcachedParser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void MemcachedParser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}


antlrcpp::Any MemcachedParser::CommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemcachedVisitor*>(visitor))
    return parserVisitor->visitCommand(this);
  else
    return visitor->visitChildren(this);
}

MemcachedParser::CommandContext* MemcachedParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 2, MemcachedParser::RuleCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(15);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemcachedParser::Storagecmd: {
        enterOuterAlt(_localctx, 1);
        setState(13);
        storagecmd();
        break;
      }

      case MemcachedParser::TEXTCMD: {
        enterOuterAlt(_localctx, 2);
        setState(14);
        othercommand();
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

//----------------- StoragecmdContext ------------------------------------------------------------------

MemcachedParser::StoragecmdContext::StoragecmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemcachedParser::StoragecmdContext::Storagecmd() {
  return getToken(MemcachedParser::Storagecmd, 0);
}


size_t MemcachedParser::StoragecmdContext::getRuleIndex() const {
  return MemcachedParser::RuleStoragecmd;
}

void MemcachedParser::StoragecmdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStoragecmd(this);
}

void MemcachedParser::StoragecmdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStoragecmd(this);
}


antlrcpp::Any MemcachedParser::StoragecmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemcachedVisitor*>(visitor))
    return parserVisitor->visitStoragecmd(this);
  else
    return visitor->visitChildren(this);
}

MemcachedParser::StoragecmdContext* MemcachedParser::storagecmd() {
  StoragecmdContext *_localctx = _tracker.createInstance<StoragecmdContext>(_ctx, getState());
  enterRule(_localctx, 4, MemcachedParser::RuleStoragecmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(MemcachedParser::Storagecmd);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OthercommandContext ------------------------------------------------------------------

MemcachedParser::OthercommandContext::OthercommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemcachedParser::OthercommandContext::TEXTCMD() {
  return getToken(MemcachedParser::TEXTCMD, 0);
}

tree::TerminalNode* MemcachedParser::OthercommandContext::NEWLINE() {
  return getToken(MemcachedParser::NEWLINE, 0);
}


size_t MemcachedParser::OthercommandContext::getRuleIndex() const {
  return MemcachedParser::RuleOthercommand;
}

void MemcachedParser::OthercommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOthercommand(this);
}

void MemcachedParser::OthercommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemcachedListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOthercommand(this);
}


antlrcpp::Any MemcachedParser::OthercommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemcachedVisitor*>(visitor))
    return parserVisitor->visitOthercommand(this);
  else
    return visitor->visitChildren(this);
}

MemcachedParser::OthercommandContext* MemcachedParser::othercommand() {
  OthercommandContext *_localctx = _tracker.createInstance<OthercommandContext>(_ctx, getState());
  enterRule(_localctx, 6, MemcachedParser::RuleOthercommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    match(MemcachedParser::TEXTCMD);
    setState(20);
    match(MemcachedParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MemcachedParser::_decisionToDFA;
atn::PredictionContextCache MemcachedParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MemcachedParser::_atn;
std::vector<uint16_t> MemcachedParser::_serializedATN;

std::vector<std::string> MemcachedParser::_ruleNames = {
  "commands", "command", "storagecmd", "othercommand"
};

std::vector<std::string> MemcachedParser::_literalNames = {
  "", "", "'\r\n'"
};

std::vector<std::string> MemcachedParser::_symbolicNames = {
  "", "Storagecmd", "NEWLINE", "TEXTCMD"
};

dfa::Vocabulary MemcachedParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MemcachedParser::_tokenNames;

MemcachedParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x5, 0x19, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x6, 0x2, 0xc, 0xa, 0x2, 
       0xd, 0x2, 0xe, 0x2, 0xd, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x12, 0xa, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x2, 0x2, 0x16, 0x2, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x4, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0x8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 0x4, 
       0x3, 0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 
       0xe, 0x3, 0x3, 0x2, 0x2, 0x2, 0xf, 0x12, 0x5, 0x6, 0x4, 0x2, 0x10, 
       0x12, 0x5, 0x8, 0x5, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x10, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0x5, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x7, 
       0x3, 0x2, 0x2, 0x14, 0x7, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x5, 
       0x2, 0x2, 0x16, 0x17, 0x7, 0x4, 0x2, 0x2, 0x17, 0x9, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0xd, 0x11, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MemcachedParser::Initializer MemcachedParser::_init;
