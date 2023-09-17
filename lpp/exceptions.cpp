#include "../Header/exceptions.h"

// Illegal Token
    std::string IllegalToken::what(Token tok)
    {
        return "Illegal expression " + tok.value;
    }

// Uncompleted Expresion
    std::string UncompletedExpression::what(Token tok)
    {
        return "Uncompleted expresion " + tok.value;
    }