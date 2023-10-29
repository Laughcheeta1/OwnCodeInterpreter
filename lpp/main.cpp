#include <vector>
#include <iostream>
#include "../Header/ast.h"
#include "../Header/lexer.h"
#include "../Header/Token.h"
#include "../Header/parser.h"

int main()
{
    std::cout << "C--\nEl Frances, El Mamado y el Bitchless\nc-- Registered Trademark\nEscriba '.exit' para salir.\n\nc-- >>> ";
    std::string input;
    Lexer lexer;
    while (std::getline(std::cin, input) && input.compare(".exit")) // If the input == ".exit", the method will return a 0, value that is interpreted by the language as a false
    {
        std::vector<Token> v = lexer.readLine(input);
        
        // NodeAST* n = ast::makeTree(v);

        // std::cout << "The result is: " << Parser::evaluateTree(n) << std::endl;
        // std::cout << "\nc-- >>> ";

        // ast::freeTree(n);
    }

    return 0;
}

// Funcion:
// Tokens [FUNC, WORD, LPAREN, ..., RPAREN, LSBRACE, ..., RSBRACE]

// milf sum (var a, var b)
// [
//     bdsm a + b
// ]

// createFunc()




// If:
// Tokens [IF, LPAREN, ... expresion ..., RPAREN, LSBRACE, ..., RSBRACE]

// eParce ()
// [

// ]

// createIf()