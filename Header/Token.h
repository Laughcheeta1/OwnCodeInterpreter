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
        NUMBER,
        PLUS,
        RBRACE,
        RSBRACE,
        RPAREN,
        SEMICOLON,
        QUESTIONMARK,
        LESSER EQUAL,
        GREATER EQUAL,
        POWER,
        LOG,
        LN
    };
*/
struct Token {
    std::string name;
    std::string value;
};

#endif // TOKEN_H
