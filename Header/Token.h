#ifndef TOKEN_H
#define TOKEN_H

#include <string>

const std::string INTEGER = "INTEGER";
const std::string DECIMALNUMBER = "FLOATNUMBER";
const std::string PLUS = "+";
const std::string MINUS = "-";
const std::string MULTIPLICATION = "*";
const std::string DIVISION = "/";
const std::string POWER = "^";
const std::string ROOT = "root";
const std::string LOG = "log";
const std::string LN = "ln";
const std::string TRUE = "true";
const std::string FALSE = "false";
const std::string NEGATION = "!";
const std::string EQUAL = "=";
const std::string LESSTHAN = "<";
const std::string GREATERTHAN = ">";
const std::string LESSEREQUAL = "<=";
const std::string GREATEREQUAL = ">=";
const std::string ASSIGN = ":";
const std::string LPAREN = "(";
const std::string RPAREN = ")";
const std::string COMMA = ",";


// TODO: hacer todos los nombres de las cosas como true y false en const strings, por si despues los queremos cambiar
/*
    The tokes:
        Numerical:
            INTEGER
            FLOATNUMBER

        Mathematical:
            PLUS : '+'
            MINUS : '-'
            MULTIPLICATION : '*'
            DIVISION : '/'
            POWER : '^'
            ROOT : 'root'
            LOG : 'log'
            LN : 'ln'
        
        Logical:
            TRUE : 'true' // TODO: have to do this
            FALSE : 'false' // TODO: have to do this
            NEGATION : '!' // TODO: have to do negation
            EQUAL : '='
            LESS THAN : '<'
            GREATER THAN : '>'
            LESSER EQUAL : '<='
            GREATER EQUAL : '>='

        Programming wise
            ASSIGN : ':'

        Texts:
            WORD
            LPAREN : '('
            RPAREN : ')'
            COMMA : ','
        
        Other:
            ILLEGAL
*/

struct Token {
    std::string name;
    std::string value;
};

#endif // TOKEN_H
