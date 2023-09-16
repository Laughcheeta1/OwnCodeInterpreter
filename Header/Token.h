#ifndef TOKEN_H
#define TOKEN_H

#include <string>

/*
enum TokenType
    {
        ILLEGAL,
        WORD,
        ASSIGN, 
        COMMA,
        DIVISION,
        EQ,
        //EOF,
        FOR,
        FUNCTION,
        GT,
        GTE,
        IDENT,
        INT,
        LSBRACE,
        LBRACE,
        LET, 
        LPAREN,
        LT,
        LTE,
        MINUS,
        MULTIPLICATION,
        NEGATION,
        NEQ,
        INTEGER,
        FLOATNUMBER
        PLUS,
        RBRACE,
        RSBRACE,
        RPAREN,
        SEMICOLON,
        QUESTIONMARK,
        EQUAL
        LESSER EQUAL,
        GREATER EQUAL,
        LESS THAN
        GREATER THAN
        POWER,
        ROOT,
        LOG,
        LN
    };
*/
struct Token {
    std::string name;
    std::string value;
};

#endif // TOKEN_H
