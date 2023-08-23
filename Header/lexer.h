#ifndef LEXER_H
#define LEXER_H
#include "Token.h"

class Lexer {
    private:
        std::string input;
        size_t position;
        Token readNumber();


    public:
        explicit Lexer(std::string in);
        Token getNextToken();
};
#endif