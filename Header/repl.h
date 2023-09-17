#ifndef REPL_H
#define REPL_H
#include "../Header/ast.h"
#include "../Header/lexer.h"
#include "../Header/parser.h"
#include "../Header/Token.h"
#include <iostream>
#include <string>

void startTerminal()
{
    std::cout << "C--\nEl Frances, El Mamado y el Bitchless\nc-- Registered Trademark\nEscriba '.exit' para salir.\n\nc-- >>> ";
    std::string input;
    Lexer lexer;

    while (std::getline(std::cin, input) && input.compare(".exit")) // If the input == ".exit", the method will return a 0, value that is interpreted by the language as a false
    {
        lexer.readLine(input);
        std::cout << "\nc-- >>> ";
    }
}

#endif