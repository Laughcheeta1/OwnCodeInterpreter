#include <vector>
#include <iostream>
#include "../Header/lexer.h"
#include "../Header/Token.h"
#include "../Header/evaluator.h"
#include "../Header/environment.h"

int main()
{
    std::cout << "C--\nEl Frances, El Mamado y el Bitchless\nc-- Registered Trademark\nEscriba '.exit' para salir.\n\nc-- >>> ";
    std::string input;
    Lexer lexer;
    Environment env;
    while (std::getline(std::cin, input) && input.compare(".exit")) // If the input == ".exit", the method will return a 0, value that is interpreted by the language as a false
    {
        std::vector<Token> v = lexer.readLine(input);
        
        std::string result = Evaluator::evaluate(v, env);

        std::cout << "The result is: " << result << std::endl;

        std::cout << "\nc-- >>> ";
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
    // x + 1 
    
    // y -3

    // z * 4
// ]

// eParce, (, ... expresion ..., ), [, x, +, 1, \n, y, -, 3, \n, z, *, 4, ] 

// createIf()

