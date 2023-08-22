#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "Token.h"

class Lexer {
public:
    Lexer(const std::string input);

    Token getNextToken();

private:
    Token readNumber();

    const std::string input;
    size_t position;
};

#endif // LEXER_H
