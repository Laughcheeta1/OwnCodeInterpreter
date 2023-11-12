#ifndef MILF_H
#define MILF_H

#include "Token.h"
#include <vector>

class Milf
{
    public:
        explicit Milf(std::vector<Token> funDeclarationExpression);
        std::string callFunction(std::vector<Token> arguments);
};

#endif