#include <iostream>
#include <string>
#include "../Header/lexer.h"

using namespace std;

/*
Theophile Arnould
Sebastian Ruiz
Santiago Yepes
*/

int main() {
    cout << "C--\nEl Frances, El Rockero, El Mamado y el Bitchless\nc-- Registered Trademark\nEscriba '.exit' para salir.\n\nc-- >>> ";
    string input;
    Lexer lexer;

    while (getline(cin, input) && input.compare(".exit")) // If the input == ".exit", the method will return a 0, value that is interpreted by the language as a false
    {
        lexer.readLine(input);
        cout << "\nc-- >>> ";
    }
    return 0;
}