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
        Token readLessGreaterEqual(char t);
        std::vector<Token> processResult(std::vector<Token> vec);
        void processLog(std::vector<Token> vec, int index);
        void processLn(std::vector<Token> vec, int index);
        void processRaiz(std::vector<Token> vec, int index);

    public:
        explicit Lexer();
        Token getToken(char currentChar);
        std::vector<Token> readLine(std::string in);
};
#endif