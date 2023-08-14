#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType
    {
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
        ILLEGAL,
        INT,
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
        RPAREN,
        SEMICOLON
    };

struct Token {
    TokenType type;
    std::string value;
};

#endif // TOKEN_H
