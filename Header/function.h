#ifndef FUNCTION_H
#define FUNCTION_H
#include <vector>
#include <string>
#include "Token.h"

class Function
{
    private:
        
    public:
        /// @brief Constructor of the function class
        /// @param function the array of tokens containing the funcion in question
        explicit Function(std::vector<Token> function);

        /// @brief runs this function
        /// @param arguments the arguments the function should recieve
        /// @return the return value of the function
        std::string callFunction(std::vector<Token> arguments);
};

#endif