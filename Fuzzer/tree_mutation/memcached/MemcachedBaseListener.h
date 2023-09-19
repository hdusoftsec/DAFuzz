
// Generated from Memcached.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "MemcachedListener.h"


/**
 * This class provides an empty implementation of MemcachedListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MemcachedBaseListener : public MemcachedListener {
public:

  virtual void enterCommands(MemcachedParser::CommandsContext * /*ctx*/) override { }
  virtual void exitCommands(MemcachedParser::CommandsContext * /*ctx*/) override { }

  virtual void enterCommand(MemcachedParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(MemcachedParser::CommandContext * /*ctx*/) override { }

  virtual void enterStoragecmd(MemcachedParser::StoragecmdContext * /*ctx*/) override { }
  virtual void exitStoragecmd(MemcachedParser::StoragecmdContext * /*ctx*/) override { }

  virtual void enterOthercommand(MemcachedParser::OthercommandContext * /*ctx*/) override { }
  virtual void exitOthercommand(MemcachedParser::OthercommandContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

