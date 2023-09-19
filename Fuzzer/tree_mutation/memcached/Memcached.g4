grammar Memcached;

//antlr4 -Dlanguage=Cpp -visitor Memcached.g4
// https://github.com/memcached/memcached/blob/master/doc/protocol.txt

commands : command+ ;

command: storagecmd | othercommand;

storagecmd: Storagecmd;

Storagecmd: (SET|ADD|REPLACE|APPEND|PREPEND|CAS|META_SET) (.)*? NEWLINE (.)*? NEWLINE;


othercommand : TEXTCMD NEWLINE;


fragment SET: 'set';
fragment ADD: 'add';
fragment REPLACE: 'replace';
fragment APPEND: 'append';
fragment PREPEND: 'prepend';
fragment CAS: 'cas';

fragment META_SET: 'ms';

NEWLINE:'\r\n' ;	  

TEXTCMD : [a-zA-Z] ~[\n\r]+ ;

// Below cannot be used in ANTLR4
// https://stackoverflow.com/questions/4010549/antlr-rule-to-consume-fixed-number-of-characters
//Bulkstring : '$' INT {int byteNum = Integer.parseInt($INT.text);} NEWLINE ( {if (byteNum == 0) break;} . {byteNum = byteNum-1;} )* NEWLINE ;

/*
bulkstring : '$' INT NEWLINE bytevalues[$INT.int] NEWLINE;

bytevalues [int m]
locals [int j = 1;]
      :  ( {$j<=$m}? BYTE {$j++;} )* // match m bytes
      ;
*/	  



/*
BYTE
   : '\u0000' .. '\u00FF'
   ;
   */


//WS  :   [ \t\n\r]+ -> skip ; // toss out all whitespace
