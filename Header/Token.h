#ifndef TOKEN_H
#define TOKEN_H

#include <string>

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
        QUESTIONMARK
    };

struct Token {
    std::string name;
    TokenType placement;
    std::string value;
};

#endif // TOKEN_H
