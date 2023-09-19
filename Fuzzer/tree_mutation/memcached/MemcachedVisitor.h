
// Generated from Memcached.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "MemcachedParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MemcachedParser.
 */
class  MemcachedVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MemcachedParser.
   */
    virtual antlrcpp::Any visitCommands(MemcachedParser::CommandsContext *context) = 0;

    virtual antlrcpp::Any visitCommand(MemcachedParser::CommandContext *context) = 0;

    virtual antlrcpp::Any visitStoragecmd(MemcachedParser::StoragecmdContext *context) = 0;

    virtual antlrcpp::Any visitOthercommand(MemcachedParser::OthercommandContext *context) = 0;


};

