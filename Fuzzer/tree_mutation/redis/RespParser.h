
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  RespParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, Bulkstring = 2, INT = 3, NEWLINE = 4, TEXTCMD = 5
  };

  enum {
    RuleCommands = 0, RuleCommand = 1, RuleTelnetcommand = 2, RuleBulkarray = 3, 
    RuleBulkstrings = 4
  };

  explicit RespParser(antlr4::TokenStream *input);
  ~RespParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CommandsContext;
  class CommandContext;
  class TelnetcommandContext;
  class BulkarrayContext;
  class BulkstringsContext; 

  class  CommandsContext : public antlr4::ParserRuleContext {
  public:
    CommandsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CommandContext *> command();
    CommandContext* command(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandsContext* commands();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BulkarrayContext *bulkarray();
    TelnetcommandContext *telnetcommand();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandContext* command();

  class  TelnetcommandContext : public antlr4::ParserRuleContext {
  public:
    TelnetcommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXTCMD();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TelnetcommandContext* telnetcommand();

  class  BulkarrayContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *intToken = nullptr;
    BulkarrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *NEWLINE();
    BulkstringsContext *bulkstrings();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BulkarrayContext* bulkarray();

  class  BulkstringsContext : public antlr4::ParserRuleContext {
  public:
    int n;
    int i = 1;;
    BulkstringsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    BulkstringsContext(antlr4::ParserRuleContext *parent, size_t invokingState, int n);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Bulkstring();
    antlr4::tree::TerminalNode* Bulkstring(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BulkstringsContext* bulkstrings(int n);


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool bulkstringsSempred(BulkstringsContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

