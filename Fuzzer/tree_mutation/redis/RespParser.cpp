
// Generated from Resp.g4 by ANTLR 4.9.3


#include "RespListener.h"
#include "RespVisitor.h"

#include "RespParser.h"


using namespace antlrcpp;
using namespace antlr4;

RespParser::RespParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RespParser::~RespParser() {
  delete _interpreter;
}

std::string RespParser::getGrammarFileName() const {
  return "Resp.g4";
}

const std::vector<std::string>& RespParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RespParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CommandsContext ------------------------------------------------------------------

RespParser::CommandsContext::CommandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RespParser::CommandContext *> RespParser::CommandsContext::command() {
  return getRuleContexts<RespParser::CommandContext>();
}

RespParser::CommandContext* RespParser::CommandsContext::command(size_t i) {
  return getRuleContext<RespParser::CommandContext>(i);
}


size_t RespParser::CommandsContext::getRuleIndex() const {
  return RespParser::RuleCommands;
}

void RespParser::CommandsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommands(this);
}

void RespParser::CommandsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommands(this);
}


antlrcpp::Any RespParser::CommandsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RespVisitor*>(visitor))
    return parserVisitor->visitCommands(this);
  else
    return visitor->visitChildren(this);
}

RespParser::CommandsContext* RespParser::commands() {
  CommandsContext *_localctx = _tracker.createInstance<CommandsContext>(_ctx, getState());
  enterRule(_localctx, 0, RespParser::RuleCommands);
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
    setState(11); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(10);
      command();
      setState(13); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RespParser::T__0

    || _la == RespParser::TEXTCMD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

RespParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RespParser::BulkarrayContext* RespParser::CommandContext::bulkarray() {
  return getRuleContext<RespParser::BulkarrayContext>(0);
}

RespParser::TelnetcommandContext* RespParser::CommandContext::telnetcommand() {
  return getRuleContext<RespParser::TelnetcommandContext>(0);
}


size_t RespParser::CommandContext::getRuleIndex() const {
  return RespParser::RuleCommand;
}

void RespParser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void RespParser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}


antlrcpp::Any RespParser::CommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RespVisitor*>(visitor))
    return parserVisitor->visitCommand(this);
  else
    return visitor->visitChildren(this);
}

RespParser::CommandContext* RespParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 2, RespParser::RuleCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(17);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RespParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(15);
        bulkarray();
        break;
      }

      case RespParser::TEXTCMD: {
        enterOuterAlt(_localctx, 2);
        setState(16);
        telnetcommand();
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

//----------------- TelnetcommandContext ------------------------------------------------------------------

RespParser::TelnetcommandContext::TelnetcommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RespParser::TelnetcommandContext::TEXTCMD() {
  return getToken(RespParser::TEXTCMD, 0);
}

tree::TerminalNode* RespParser::TelnetcommandContext::NEWLINE() {
  return getToken(RespParser::NEWLINE, 0);
}


size_t RespParser::TelnetcommandContext::getRuleIndex() const {
  return RespParser::RuleTelnetcommand;
}

void RespParser::TelnetcommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTelnetcommand(this);
}

void RespParser::TelnetcommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTelnetcommand(this);
}


antlrcpp::Any RespParser::TelnetcommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RespVisitor*>(visitor))
    return parserVisitor->visitTelnetcommand(this);
  else
    return visitor->visitChildren(this);
}

RespParser::TelnetcommandContext* RespParser::telnetcommand() {
  TelnetcommandContext *_localctx = _tracker.createInstance<TelnetcommandContext>(_ctx, getState());
  enterRule(_localctx, 4, RespParser::RuleTelnetcommand);

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
    match(RespParser::TEXTCMD);
    setState(20);
    match(RespParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BulkarrayContext ------------------------------------------------------------------

RespParser::BulkarrayContext::BulkarrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RespParser::BulkarrayContext::INT() {
  return getToken(RespParser::INT, 0);
}

tree::TerminalNode* RespParser::BulkarrayContext::NEWLINE() {
  return getToken(RespParser::NEWLINE, 0);
}

RespParser::BulkstringsContext* RespParser::BulkarrayContext::bulkstrings() {
  return getRuleContext<RespParser::BulkstringsContext>(0);
}


size_t RespParser::BulkarrayContext::getRuleIndex() const {
  return RespParser::RuleBulkarray;
}

void RespParser::BulkarrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBulkarray(this);
}

void RespParser::BulkarrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBulkarray(this);
}


antlrcpp::Any RespParser::BulkarrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RespVisitor*>(visitor))
    return parserVisitor->visitBulkarray(this);
  else
    return visitor->visitChildren(this);
}

RespParser::BulkarrayContext* RespParser::bulkarray() {
  BulkarrayContext *_localctx = _tracker.createInstance<BulkarrayContext>(_ctx, getState());
  enterRule(_localctx, 6, RespParser::RuleBulkarray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    match(RespParser::T__0);
    setState(23);
    antlrcpp::downCast<BulkarrayContext *>(_localctx)->intToken = match(RespParser::INT);
    setState(24);
    match(RespParser::NEWLINE);
    setState(25);
    bulkstrings((antlrcpp::downCast<BulkarrayContext *>(_localctx)->intToken != nullptr ? std::stoi(antlrcpp::downCast<BulkarrayContext *>(_localctx)->intToken->getText()) : 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BulkstringsContext ------------------------------------------------------------------

RespParser::BulkstringsContext::BulkstringsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RespParser::BulkstringsContext::BulkstringsContext(ParserRuleContext *parent, size_t invokingState, int n)
  : ParserRuleContext(parent, invokingState) {
  this->n = n;
}

std::vector<tree::TerminalNode *> RespParser::BulkstringsContext::Bulkstring() {
  return getTokens(RespParser::Bulkstring);
}

tree::TerminalNode* RespParser::BulkstringsContext::Bulkstring(size_t i) {
  return getToken(RespParser::Bulkstring, i);
}


size_t RespParser::BulkstringsContext::getRuleIndex() const {
  return RespParser::RuleBulkstrings;
}

void RespParser::BulkstringsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBulkstrings(this);
}

void RespParser::BulkstringsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RespListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBulkstrings(this);
}


antlrcpp::Any RespParser::BulkstringsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RespVisitor*>(visitor))
    return parserVisitor->visitBulkstrings(this);
  else
    return visitor->visitChildren(this);
}

RespParser::BulkstringsContext* RespParser::bulkstrings(int n) {
  BulkstringsContext *_localctx = _tracker.createInstance<BulkstringsContext>(_ctx, getState(), n);
  enterRule(_localctx, 8, RespParser::RuleBulkstrings);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(32);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(27);

        if (!(_localctx->i<=_localctx->n)) throw FailedPredicateException(this, "$i<=$n");
        setState(28);
        match(RespParser::Bulkstring);
        _localctx->i++; 
      }
      setState(34);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool RespParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return bulkstringsSempred(antlrcpp::downCast<BulkstringsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RespParser::bulkstringsSempred(BulkstringsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return _localctx->i<=_localctx->n;

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> RespParser::_decisionToDFA;
atn::PredictionContextCache RespParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RespParser::_atn;
std::vector<uint16_t> RespParser::_serializedATN;

std::vector<std::string> RespParser::_ruleNames = {
  "commands", "command", "telnetcommand", "bulkarray", "bulkstrings"
};

std::vector<std::string> RespParser::_literalNames = {
  "", "'*'", "", "", "'\r\n'"
};

std::vector<std::string> RespParser::_symbolicNames = {
  "", "", "Bulkstring", "INT", "NEWLINE", "TEXTCMD"
};

dfa::Vocabulary RespParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RespParser::_tokenNames;

RespParser::Initializer::Initializer() {
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
       0x3, 0x7, 0x26, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x6, 
       0x2, 0xe, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xf, 0x3, 0x3, 0x3, 0x3, 
       0x5, 0x3, 0x14, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x7, 0x6, 0x21, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x24, 0xb, 0x6, 
       0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x2, 0x2, 
       0x23, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4, 0x13, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8, 0x18, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x22, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe, 0x5, 0x4, 0x3, 0x2, 0xd, 0xc, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x3, 0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0xf, 0x10, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x11, 0x14, 0x5, 0x8, 0x5, 0x2, 0x12, 0x14, 0x5, 0x6, 0x4, 
       0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x12, 0x3, 0x2, 0x2, 0x2, 
       0x14, 0x5, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x7, 0x2, 0x2, 0x16, 
       0x17, 0x7, 0x6, 0x2, 0x2, 0x17, 0x7, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 
       0x7, 0x3, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x5, 0x2, 0x2, 0x1a, 0x1b, 0x7, 
       0x6, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0xa, 0x6, 0x2, 0x1c, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0x1d, 0x1e, 0x6, 0x6, 0x2, 0x3, 0x1e, 0x1f, 0x7, 0x4, 0x2, 
       0x2, 0x1f, 0x21, 0x8, 0x6, 0x1, 0x2, 0x20, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0x21, 0x24, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 
       0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0xb, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 
       0x3, 0x2, 0x2, 0x2, 0x5, 0xf, 0x13, 0x22, 
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

RespParser::Initializer RespParser::_init;
