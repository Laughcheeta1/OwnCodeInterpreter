#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include "../Header/Token.h"
#include "../Header/lexer.h"

    // Constructor
    Lexer::Lexer() {   }

    std::vector<Token> Lexer::processResult(std::vector<Token> vec) // TODO finish the method
    {
        position = 0;
        while (position < vec.size())
        {
            if (!vec[position].value.compare("<") && !vec[position + 1].value.compare("="))
            {
                vec.erase(vec.begin() + position);
                vec[position].value = "<=";
                vec[position].name = "LESSER EQUAL";
            }
            else if (!vec[position].value.compare(">") && !vec[position + 1].value.compare("="))
            {
                vec.erase(vec.begin() + position);
                vec[position].value = ">=";
                vec[position].name = "GREATER EQUAL";
            }
            else if (!vec[position].value.compare("log") || !vec[position].value.compare("LOG"))
            {
                processLog(vec);
            }
            else if (!vec[position].value.compare("ln") || !vec[position].value.compare("LN"))
            {
                processLn(vec);
            }
            else if (!vec[position].value.compare("raiz") || !vec[position].value.compare("RAIZ"))
            {
                processRaiz(vec);
            }

            position++;
        }
    }

    void Lexer::processLog(std::vector<Token> vec)
    {
        // TODO: finish this
        // leave the LOG in the form "log(number1, number2)"
    }

    void Lexer::processLn(std::vector<Token> vec)
    {
        // TODO: finish this
        // leave the LN in the form "ln(number1)"
    }

    void Lexer::processRaiz(std::vector<Token> vec)
    {
        // TODO: finish this
        // leave the RAIZ in the form "raiz(number1, number2)"
    }

    std::vector<Token> Lexer::readLine(std::string in)
    {
        // Initialize the necessary variables
        position = -1;
        size = in.size();
        line = in;
        std::vector<Token> tokens;

        while (++position < size)
        {
            if (in[position] == ' ') // Theres no need to check for "\n", since the getline() function does not actually read it
            // The 10 in ASCII is "Line feed", basically the "enter" key
                continue;

            token = getToken(in[position]); // Get the token of the current position

            if (token.name.compare("ILLEGAL") == 0)
            {
                std::cout << "Illegal Token '" << token.value << "'\n";
                tokens.clear();
                return tokens;
            }

            tokens.push_back(token);
        }

        return processResult(tokens);
    }

    // When detecting a numerical char, there can be more digits to the number following it, so we read until we have a space, to grab the whole number
    Token Lexer::readNumber() {
        std::string numberValue;
        bool isFloat = false;
        while (position < size && (std::isdigit(line[position]) || line[position] == '.')) {
            if (line[position] == '.')
                isFloat = true;

            numberValue += line[position];
            position++;
        }

        position --; // So the position ends up pointing to the last char read

        return (isFloat) ? Token {"FLOAT", numberValue} : Token {"INTEGER", numberValue};
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
        return Token {"WORD", word};
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
            return Token {"PLUS", "+"};
        }
        else if (currentChar == '-')
        {
            return Token {"MINUS", "-"};
        }
        else if (currentChar == '*')
        {
            return Token {"MULTIPLICATION", "*"};
        }
        else if (currentChar == '/')
        {
            return Token {"DIVISION", "/"};
        }
        else if (currentChar == '^')
        {
            return Token {"POWER", "^"};
        }
        else if (currentChar == '(')
        {
            return Token {"LPAREN", "("};
        }
        else if (currentChar == ')')
        {
            return Token {"RPAREN", ")"};
        }
        else if (currentChar == '[')
        {
            return Token {"LSBRACE", "["};
        }
        else if (currentChar == ']')
        {
            return Token{"RSBRACE", "]"};
        }
        else if (currentChar == '{')
        {
            return Token {"LBRACE", "{"};
        }
        else if (currentChar == '}')
        {
            return Token {"RBRACE", "}"};
        }
        else if (currentChar == '=')
        {
            return Token {"EQUAL", "="};
        }
        else if (currentChar == ',')
        {
            return Token {"COMMA", ","};
        }
        else if (currentChar == '?')
        {
            return Token {"QUESTIONMARK", "?"};
        }
        else if (currentChar == ':')
        {
            return Token {"ASSIGN", ":"};
        }
        else if (currentChar == '<')
        {
            return Token {"LESS THAN", "<"};
        }
        else if (currentChar == '>')
        {
            return Token {"GREATER THAN", ">"};
        }


        position = size; // End the line if Ilegal token
        std::string str = "";
        return Token{"ILLEGAL", str.append(1, currentChar)}; // If is none of the above, it must be illegal
    }
