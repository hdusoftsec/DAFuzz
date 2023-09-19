
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RespVisitor.h"


/**
 * This class provides an empty implementation of RespVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RespBaseVisitor : public RespVisitor {
public:

  virtual antlrcpp::Any visitCommands(RespParser::CommandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommand(RespParser::CommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTelnetcommand(RespParser::TelnetcommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBulkarray(RespParser::BulkarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBulkstrings(RespParser::BulkstringsContext *ctx) override {
    return visitChildren(ctx);
  }


};

