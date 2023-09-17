#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include "../Header/Token.h"
#include "../Header/lexer.h"

    // When detecting a numerical char, there can be more digits to the number following it, so we read until we have a space, to grab the whole number
    Token Lexer::readNumber() 
    {
        std::string numberValue = "";

        if (line[position] == '-')
            numberValue += line[position];

        bool isFloat = false, hasPoint = false;
        while (position < size && (std::isdigit(line[position]) || line[position] == '.')) {
            if (line[position] == '.')
            {
                if (hasPoint)
                    return Token {"ILLEGAL", ""};
                else
                    
                    
            }
                

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

        if (!word.compare("true"))
            return Token {"TRUE", "true"};
        
        else if (!word.compare("false"))
            return Token {"FALSE", "false"};
        
        else
            return Token {"WORD", word};
    }

    // Stripping the white space because this helps with checking things
    std::string Lexer::stripWhiteSpace(std::string line)
    {
        std::string result = "";
        int x = line.size();
        for (int i = 0; i < x; i++)
        {
            if (line[i] != ' ')
                result.append(1, line[i]);
        }

        return result;
    }

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

        return vec;
    }

    std::vector<Token> Lexer::readLine(std::string in)
    {
        // Initialize the necessary variables
        in = stripWhiteSpace(in); // This is for facilitating the lexxer process, with things like checking for a negative number

        position = -1;
        size = in.size();
        line = in;
        std::vector<Token> tokens;

        while (++position < size)
        {
            // No need to ignore whitespace since i got rid of it above
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
            if (position + 1 < size && isdigit(line[position + 1]) && (position >= 1 || !isdigit(line[position - 1])))
                // If it is the start of a negative number, the condition (position == 0) is in case the negative is the 
                    // first thing in the line
            {
                return readNumber();
            }
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
