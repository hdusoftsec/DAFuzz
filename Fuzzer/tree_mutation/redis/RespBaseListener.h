
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RespListener.h"


/**
 * This class provides an empty implementation of RespListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RespBaseListener : public RespListener {
public:

  virtual void enterCommands(RespParser::CommandsContext * /*ctx*/) override { }
  virtual void exitCommands(RespParser::CommandsContext * /*ctx*/) override { }

  virtual void enterCommand(RespParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(RespParser::CommandContext * /*ctx*/) override { }

  virtual void enterTelnetcommand(RespParser::TelnetcommandContext * /*ctx*/) override { }
  virtual void exitTelnetcommand(RespParser::TelnetcommandContext * /*ctx*/) override { }

  virtual void enterBulkarray(RespParser::BulkarrayContext * /*ctx*/) override { }
  virtual void exitBulkarray(RespParser::BulkarrayContext * /*ctx*/) override { }

  virtual void enterBulkstrings(RespParser::BulkstringsContext * /*ctx*/) override { }
  virtual void exitBulkstrings(RespParser::BulkstringsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

