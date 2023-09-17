#include "Token.h"
#include <exception>
#include <string>

class IllegalToken : public std::exception
{
    private:
        std::string token; // Value of the illegal token

    public:
        explicit IllegalToken(std::string tok);
        std::string what();
};

class UncompletedExpression : public std::exception
{
    private:
        std::string token; // Value of the illegal token

    public:
        explicit UncompletedExpression(std::string tok);
        std::string what();
};