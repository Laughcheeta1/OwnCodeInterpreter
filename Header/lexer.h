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
        std::vector<Token> tokens;
        Token readNumber(); // Reads a complete number, and determines wheter it is a float or integer, positive or negative
        Token readWords(); // Reads a word
        std::string stripWhiteSpace(std::string line); // Clear the input string from all white space
        void processLog();
        void processLn();
        void processRaiz(); 
        Token getToken(char currentChar); // Returns the token the char corresponds to

        void processVariable();
        void processFunction(); // Create the vector for a function, does not
            // check if the arguments or the inside code is valid, only gets the function
        void processIf();

        // TODO: identify strings
        // TODO: I think every word needs to be asumed either a variable or a function, after that, check if it is valid or nah

    public:
        static std::string getTypeOfValue(std::string str); // Given a string, returns wheter it corresponds to a INTEGER, FLOATNUMBER or a bool
        std::vector<Token> readLine(std::string in); // Reads a line of input, and returns a vector of tokens
};
#endif