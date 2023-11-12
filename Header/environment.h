#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <map>
#include <string>
// #include "customFun.h"
#include "Token.h"

class Environment
{
    public:
        std::map<std::string, Token> variables;
        // std::map<std::string, CustomFun> functions;
};

#endif