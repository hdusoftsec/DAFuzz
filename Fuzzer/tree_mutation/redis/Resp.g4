grammar Resp;

//antlr4 -Dlanguage=Cpp -visitor Resp.g4

commands : command+ ;

command: bulkarray | telnetcommand;

telnetcommand : TEXTCMD NEWLINE;

bulkarray : '*' INT NEWLINE bulkstrings[$INT.int];

bulkstrings [int n]
locals [int i = 1;]
      :  ( {$i<=$n}? Bulkstring {$i++;} )* // match n bulkstring
      ;

Bulkstring : '$' INT NEWLINE (.)*? NEWLINE;

INT :   [0-9]+ ;             // match integers
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
