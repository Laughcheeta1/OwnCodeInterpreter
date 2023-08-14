using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "tokens.h"

class Lexer {
    public:
    Lexer(const std::string& input) : input(input), position(0) {}

    Token getNextToken() {
        while (position < input.size()) {
            char currentChar = input[position];

            if (std::isdigit(currentChar)) {
                return readNumber();
            }

            switch (currentChar) {
                case '+':
                    position++;
                    return Token{ADD, "+"};
                case '-':
                    position++;
                    return Token{SUBTRACT, "-"};
                case '*':
                    position++;
                    return Token{MULTIPLY, "*"};
                case '/':
                    position++;
                    return Token{DIVIDE, "/"};
                case '(':
                    position++;
                    return Token{LPAREN, "("};
                case ')':
                    position++;
                    return Token{RPAREN, ")"};
                default:
                    // Skip whitespace characters
                    if (std::isspace(currentChar)) {
                        position++;
                        continue;
                    }

                    std::cerr << "Error: Unexpected character '" << currentChar << "'" << std::endl;
                    exit(1);
            }
        }

        return Token{END, ""};
    }

    private:

    const std::string& input;
    size_t position;

    Token readNumber() {
        std::string numberValue;
        while (position < input.size() && std::isdigit(input[position])) {
            numberValue += input[position];
            position++;
        }
        return Token{NUMBER, numberValue};
    }

};
