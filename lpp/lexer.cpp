#include <iostream>
#include <string>
#include <cctype>
#include "../Header/Token.h"
#include "../Header/lexer.h"


    Lexer::Lexer(std::string in) {
        input = in;
        position = 0;
    }

    Token Lexer::readNumber() {
        std::string numberValue;
        while (position < input.size() && std::isdigit(input[position])) {
            numberValue += input[position];
            position++;
        }
        return Token{NUMBER, numberValue};//Number ?
    }

    Token Lexer::getNextToken() {
        while (position < input.size()) {
            char currentChar = input[position];

            if (std::isdigit(currentChar)) {
                return readNumber();
            }

            switch (currentChar) {
                case '+':
                    position++;
                    return Token{PLUS, "+"};
                case '-':
                    position++;
                    return Token{MINUS, "-"};
                case '*':
                    position++;
                    return Token{MULTIPLICATION, "*"};
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

        return Token{ILLEGAL, ""};
    }
