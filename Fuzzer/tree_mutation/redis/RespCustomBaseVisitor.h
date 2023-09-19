
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once

#include <iostream>
#include <vector>

#include "antlr4-runtime.h"
#include "RespBaseVisitor.h"

using namespace std;
using namespace antlr4;

/**
 * This class provides an empty implementation of RespVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RespCustomBaseVisitor : public RespBaseVisitor {
public:

    vector<misc::Interval> intervals;
    vector<string> texts;
    BufferedTokenStream *tokens;

    RespCustomBaseVisitor(BufferedTokenStream &in_tokens)
    {
        this->tokens = &in_tokens;
    }

  virtual antlrcpp::Any visitCommands(RespParser::CommandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommand(RespParser::CommandContext *ctx) override {
   //intervals.push_back(ctx->getSourceInterval());
   //texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTelnetcommand(RespParser::TelnetcommandContext *ctx) override {
    intervals.push_back(ctx->getSourceInterval());
    texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBulkarray(RespParser::BulkarrayContext *ctx) override {
    intervals.push_back(ctx->getSourceInterval());
    texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBulkstrings(RespParser::BulkstringsContext *ctx) override {
    /*intervals.push_back(ctx->getSourceInterval());
    texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(), ctx->stop->getStopIndex())));

    for (int i = 0; i < ctx->children.size(); ++i)
    {
        intervals.push_back(ctx->children[i]->getSourceInterval());
        texts.push_back(ctx->children[i]->getText());
    }*/
    return visitChildren(ctx);
  }


};

