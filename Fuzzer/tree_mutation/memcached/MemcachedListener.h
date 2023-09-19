
// Generated from Memcached.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "MemcachedParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MemcachedParser.
 */
class  MemcachedListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCommands(MemcachedParser::CommandsContext *ctx) = 0;
  virtual void exitCommands(MemcachedParser::CommandsContext *ctx) = 0;

  virtual void enterCommand(MemcachedParser::CommandContext *ctx) = 0;
  virtual void exitCommand(MemcachedParser::CommandContext *ctx) = 0;

  virtual void enterStoragecmd(MemcachedParser::StoragecmdContext *ctx) = 0;
  virtual void exitStoragecmd(MemcachedParser::StoragecmdContext *ctx) = 0;

  virtual void enterOthercommand(MemcachedParser::OthercommandContext *ctx) = 0;
  virtual void exitOthercommand(MemcachedParser::OthercommandContext *ctx) = 0;


};

