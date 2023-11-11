#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <unordered_map>
#include <string>
#include "function.h"

class Environment
{
    public:
        std::unordered_map<std::string, std::string> variables;
        std::unordered_map<std::string, Function> functions;
};

#endif