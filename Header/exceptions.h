#include "Token.h"
#include <exception>
#include <string>

class IllegalToken : public std::exception
{
    public:
        std::string what(Token tok);
};

class UncompletedExpression : public std::exception
{
    public:
        std::string what(Token tok);
};