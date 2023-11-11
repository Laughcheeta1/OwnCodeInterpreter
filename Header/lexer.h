#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <vector>



/// @brief This class is intended for converting a string of code, into tokens, that then will be processed by the evaluator class
class Lexer {
    private:
        // Global variables intended for the functioning of the class
        Token token;
        std::string line;
        long size;
        long position;
        std::vector<Token> tokens;


        /// @brief Reads a complete number, and determines wheter it is a float or integer, positive or negative
        /// @return a token corresponding to the number in question
        Token readNumber();

        /// @brief Reads a word
        /// @return a token corresponding to a word
        Token readWords();


        /// @brief Clear the input string from all white space
        /// @param line the input string
        /// @return the line string without any white space
        std::string stripWhiteSpace(std::string line);

        // void processLog();
        // void processLn();
        // void processRaiz(); 

        /// @brief Get the token a char/word/number corresponds to
        /// @param currentChar 
        /// @return token in question
        Token getToken(char currentChar);

        void processVariable();

        /// @brief Create the vector for a function, does not check if the arguments or the inside code is valid, only gets the function
        void processFunction();

        /// @brief Create the token vector for a if, does not check the validity of the inside code
        void processIf();

        // TODO: identify strings
        // TODO: I think every word needs to be asumed either a variable or a function, after that, check if it is valid or nah

    public:
        static std::string getTypeOfValue(std::string str); // Given a string, returns wheter it corresponds to a INTEGER, FLOATNUMBER or a bool
        std::vector<Token> readLine(std::string in); // Reads a line of input, and returns a vector of tokens
};
#endif