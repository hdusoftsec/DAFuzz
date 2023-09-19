
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once

#include <iostream>
#include <vector>

#include "antlr4-runtime.h"
#include "MemcachedBaseVisitor.h"

using namespace std;
using namespace antlr4;

/**
 * This class provides an empty implementation of RespVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MemcachedCustomBaseVisitor : public MemcachedBaseVisitor {
public:

    vector<misc::Interval> intervals;
    vector<string> texts;
    BufferedTokenStream *tokens;

    MemcachedCustomBaseVisitor(BufferedTokenStream &in_tokens)
    {
        this->tokens = &in_tokens;
    }

  virtual antlrcpp::Any visitCommands(MemcachedParser::CommandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommand(MemcachedParser::CommandContext *ctx) override {
   //intervals.push_back(ctx->getSourceInterval());
   //texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStoragecmd(MemcachedParser::StoragecmdContext* ctx) override {
      intervals.push_back(ctx->getSourceInterval());
      texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));
      return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOthercommand(MemcachedParser::OthercommandContext* ctx) override {
      intervals.push_back(ctx->getSourceInterval());
      texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));    intervals.push_back(ctx->getSourceInterval());
      return visitChildren(ctx);
  }


};

