
// Generated from Resp.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RespParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by RespParser.
 */
class  RespVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RespParser.
   */
    virtual antlrcpp::Any visitCommands(RespParser::CommandsContext *context) = 0;

    virtual antlrcpp::Any visitCommand(RespParser::CommandContext *context) = 0;

    virtual antlrcpp::Any visitTelnetcommand(RespParser::TelnetcommandContext *context) = 0;

    virtual antlrcpp::Any visitBulkarray(RespParser::BulkarrayContext *context) = 0;

    virtual antlrcpp::Any visitBulkstrings(RespParser::BulkstringsContext *context) = 0;


};

