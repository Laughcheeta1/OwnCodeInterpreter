#include <iostream>
#include <string>
#include <cctype>
#include "../Header/Token.h"
#include "../Header/lexer.h"

    // Constructor
    Lexer::Lexer() {   }

    void Lexer::readLine(std::string in)
    {
        // Initialize the necessary variables
        position = -1;
        size = in.size();
        line = in;

        while (++position < size)
        {
            if (in[position] == ' ') // Theres no need to check for "\n", since the getline() function does not actually read it
            // The 10 in ASCII is "Line feed", basically the "enter" key
                continue;

            token = getToken(in[position]); // Get the token of the current position

            std::cout << "Token: name = " << token.name << ", type = " << token.placement << ", value = '" << token.value << "'\n"; // Show the token
        }
    }

    // When detecting a numerical char, there can be more digits to the number following it, so we read until we have a space, to grab the whole number
    Token Lexer::readNumber() {
        std::string numberValue;
        while (position < size && std::isdigit(line[position])) {
            numberValue += line[position];
            position++;
        }

        position --; // So the position ends up pointing to the last char read
        return Token{"NUMBER", NUMBER, numberValue};
    }

    // When detected a alphabetical char, it means there can be a string following it, so we read that string as a whole word
    Token Lexer::readWords()
    {
        std::string word = "";
        while (position < size && std::isalpha(line[position]))
        {
            word.append(1, line[position]);
            position++;
        }

        position --; // So the position ends up pointing to the last char read
        return Token {"WORD", WORD, word};
    }

    // Given a char, return the token it reprents.
    Token Lexer::getToken(char currentChar) {
        if (std::isdigit(currentChar)) {
            return readNumber();
        }
        else if (std::isalpha(currentChar))
        {
            return readWords();
        }
        else if (currentChar == '+')
        {
            return Token {"PLUS", PLUS, "+"};
        }
        else if (currentChar == '-')
        {
            return Token {"MINUS", MINUS, "-"};
        }
        else if (currentChar == '*')
        {
            return Token {"MINUS", MULTIPLICATION, "*"};
        }
        else if (currentChar == '/')
        {
            return Token {"DIVISION", DIVISION, "/"};
        }
        else if (currentChar == '(')
        {
            return Token {"LPAREN", LPAREN, "("};
        }
        else if (currentChar == ')')
        {
            return Token {"RPAREN", RPAREN, ")"};
        }
        else if (currentChar == '[')
        {
            return Token {"LSBRACE", LSBRACE, "["};
        }
        else if (currentChar == ']')
        {
            return Token {"RSBRACE", RSBRACE, "]"};
        }
        else if (currentChar == '{')
        {
            return Token {"LBRACE", LBRACE, "{"};
        }
        else if (currentChar == '}')
        {
            return Token {"RBRACE", RBRACE, "}"};
        }
        else if (currentChar == '=')
        {
            return Token {"ASSIGN", ASSIGN, "="};
        }
        else if (currentChar == ',')
        {
            return Token {"COMMA", COMMA, ","};
        }
        else if (currentChar == '?')
        {
            return Token {"QUESTIONMARK", QUESTIONMARK, "?"};
        }

        return Token{"ILLEGAL", ILLEGAL, ""}; // If is none of the above, it must be illegal
    }
