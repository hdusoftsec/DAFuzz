
// Generated from Memcached.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "MemcachedVisitor.h"


/**
 * This class provides an empty implementation of MemcachedVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MemcachedBaseVisitor : public MemcachedVisitor {
public:

  virtual antlrcpp::Any visitCommands(MemcachedParser::CommandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommand(MemcachedParser::CommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStoragecmd(MemcachedParser::StoragecmdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOthercommand(MemcachedParser::OthercommandContext *ctx) override {
    return visitChildren(ctx);
  }


};

