#include <iostream>
#include "../Header/Lexer.h"

int main() {
    std::string input = "3 + 4 * (2 - 1)";
    Lexer lexer(input);

    Token token;
    do {
        token = lexer.getNextToken();
        std::cout << "Token: type=" << token.type << ", value='" << token.value << "'" << std::endl;
    } while (token.type != ILLEGAL);

    return 0;
}