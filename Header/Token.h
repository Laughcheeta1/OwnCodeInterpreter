#ifndef TOKEN_H
#define TOKEN_H

#include <string>

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
