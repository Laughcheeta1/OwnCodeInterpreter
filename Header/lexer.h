#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <vector>

class Lexer {
    private:
        Token token;
        std::string line;
        long size;
        long position;
        Token readNumber();
        Token readWords();
        

    public:
        explicit Lexer();
        Token getToken(char currentChar);
        std::vector<Token> readLine(std::string in);
};
#endif