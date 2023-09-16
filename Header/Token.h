#ifndef TOKEN_H
#define TOKEN_H

#include <string>

/*
    The tokes:
        Numerical:
            INTEGER
            FLOATNUMBER

        Mathematical:
            PLUS
            MINUS
            MULTIPLICATION
            DIVISION
            POWER
            ROOT
            LOG
            LN
        
        Logical:
            NEGATION
            EQUAL
            LESS THAN
            GREATER THAN
            LESSER EQUAL
            GREATER EQUAL

        Programming wise
            ASSIGN

        Word:
            WORD
            LPAREN
            RPAREN

        Other:
            ILLEGAL
        



*/
struct Token {
    std::string name;
    std::string value;
};

#endif // TOKEN_H
