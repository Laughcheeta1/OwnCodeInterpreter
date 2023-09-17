#include "../Header/exceptions.h"

// Illegal Token
    IllegalToken::IllegalToken(std::string tok)
    {
        token = tok;
    }

    std::string IllegalToken::what()
    {
        return "Illegal expression " + token;
    }

// Uncompleted Expresion
    UncompletedExpression::UncompletedExpression(std::string tok)
    {
        token = tok;
    }

    std::string UncompletedExpression::what()
    {
        return "Uncompleted expresion " + token;
    }