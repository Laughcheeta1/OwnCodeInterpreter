#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <map>
#include <string>
#include "milf.h"
#include "Token.h"

class Milf;

class Environment
{
    public:
        std::map<std::string, Token> variables;
        std::map<std::string, Milf*> functions;
};

#endif