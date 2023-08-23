#ifndef LEXER_H
#define LEXER_H
#include "Token.h"

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
        void readLine(std::string in);
};
#endif