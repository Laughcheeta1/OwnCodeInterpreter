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
        Token readNumber(); // Reads a complete number, and determines wheter it is a float or integer, positive or negative
        Token readWords(); // Reads a word
        std::string stripWhiteSpace(std::string line); // Clear the input string from all white space
        std::vector<Token> processResult(std::vector<Token> vec); // Converts complex tokens (Tokens formed by a combination of other 
            // tokens) into a single token
        void processLog(std::vector<Token> vec);
        void processLn(std::vector<Token> vec);
        void processRaiz(std::vector<Token> vec); 
        Token getToken(char currentChar); // Returns the token the char corresponds to

    public:
        std::string getTypeOfValue(std::string str); // Given a string, returns wheter it corresponds to a INTEGER, FLOATNUMBER or a bool
        std::vector<Token> readLine(std::string in); // Reads a line of input, and returns a vector of tokens
};
#endif