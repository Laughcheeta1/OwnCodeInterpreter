#include <iostream>
#include <string>
#include "../Header/Lexer.h"

using namespace std;

int main() {
    cout << "commence\n";
    string input;
    Token token;

    while (getline(cin, input) && token.type != ILLEGAL)
    {
        Lexer lexer(input);
        token = lexer.getNextToken();
        cout << "Token: type = " << token.type << ", value = '" << token.value << "'\n";

    }
    return 0;
}