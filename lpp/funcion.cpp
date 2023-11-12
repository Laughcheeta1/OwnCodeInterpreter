/*
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include <string.h>
#include "../Header/Token.h"
#include "../Header/lexer.h"
#include "../Header/ast.h"
#include "../Header/parser.h"

#include "../Header/function.h"


Function::Function(std::vector<Token> function)
{
    
    std::vector<Token> ar;

    int i = 2;

    while (function[i].value.compare(")") != 0){

        i = i + 1;

        ar.insert(ar.end(),function[i]);
    }

    NodeAST* n = ast::makeTree(ar);
    
}

std::string Function::callFunction(std::vector<std::string> arguments)
{
    return "Not implemented yet";
}

*/
