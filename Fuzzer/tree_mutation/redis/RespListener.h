
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RespParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RespParser.
 */
class  RespListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCommands(RespParser::CommandsContext *ctx) = 0;
  virtual void exitCommands(RespParser::CommandsContext *ctx) = 0;

  virtual void enterCommand(RespParser::CommandContext *ctx) = 0;
  virtual void exitCommand(RespParser::CommandContext *ctx) = 0;

  virtual void enterTelnetcommand(RespParser::TelnetcommandContext *ctx) = 0;
  virtual void exitTelnetcommand(RespParser::TelnetcommandContext *ctx) = 0;

  virtual void enterBulkarray(RespParser::BulkarrayContext *ctx) = 0;
  virtual void exitBulkarray(RespParser::BulkarrayContext *ctx) = 0;

  virtual void enterBulkstrings(RespParser::BulkstringsContext *ctx) = 0;
  virtual void exitBulkstrings(RespParser::BulkstringsContext *ctx) = 0;


};

