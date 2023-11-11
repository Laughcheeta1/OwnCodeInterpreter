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

        if (line[position] == '-' && (position == 0 || !isdigit(line[position - 1]))
            && line[position - 1] != ')')
        {
            numberValue += line[position];
            position++;
        }

        bool isFloat = false;
        while (position < size && (std::isdigit(line[position]) || line[position] == '.')) {
            if (line[position] == '.')
            {
                if (isFloat)
                    return Token {ILLEGAL, numberValue += '.'};
                else
                    isFloat = true;
            }

            numberValue += line[position];
            position++;
        }

        position --; // So the position ends up pointing to the last char read

        return (isFloat) ? Token {DECIMAL, numberValue} : Token {INTEGER, numberValue};
    }

    // When detected a alphabetical char, it means there can be a string following it, so we read that string as a whole word
    Token Lexer::readWords()
    {
        std::string word = "";
        while (position < size && std::isalpha(line[position]))
        {
            word.append(1, line[position]);

            if (!word.compare(FUNCTION))
            {
                return Token {FUNCTION, FUNCTION};
            }
            else if (!word.compare(IF))
            {
                return Token {IF, IF};
            }
            else if (!word.compare(VAR))
            {
                return Token {VAR, VAR};
            }
            else if (!word.compare(RETURN))
            {
                return Token {RETURN, RETURN};
            }

            position++;
        }

        position --; // So the position ends up pointing to the last char read 

        return Token {WORD, word};
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

    std::vector<Token> Lexer::readLine(std::string in) // If encounter Illegal expression, return unitary expression with Illegal Token
    {
        // Initialize the necessary variables
        in = stripWhiteSpace(in); // This is for facilitating the lexxer process, with things like checking for a negative number

        position = -1;
        size = in.size();
        line = in;
        tokens.clear();

        while (++position < size)
        {
            // No need to ignore whitespace since i got rid of it above    
            token = getToken(line[position]); // Get the token of the current position
            
            if (token.name.compare(ILLEGAL) == 0)
            {
                tokens.clear();
                return tokens;
            }

            tokens.push_back(token);

            if (!token.name.compare(FUNCTION))
            {
                processFunction();
                break;
            }
            else if (!token.name.compare(IF))
            {
                processIf();
                break;
            }
        }

        return tokens;
    }

    std::string Lexer::getTypeOfValue(std::string str) // Returns the type of variable that is the string
    {
        if (!str.compare(TRUE))
        {
            return TRUE;
        }
        else if (!str.compare(FALSE))
        {
            return FALSE;
        }
        
        int i = 0, x = str.size();
        bool isFloat = false;
        while (i < x)
        {
            if (str[i] == '-')
            {   }
            else if (str[i] == '.')
                isFloat = true;
            
            else if (!isdigit(str[i]))
                return ILLEGAL;
            i++;
        }

        if (isFloat)
            return DECIMAL;
        else
            return INTEGER;
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
            return Token {PLUS, "+"};
        }
        else if (currentChar == '-')
        {
            if (position + 1 < size && isdigit(line[position + 1]) && (position == 0 || !isdigit(line[position - 1]))
                && line[position - 1] != ')')
                // If it is the start of a negative number, the condition (position == 0) is in case the negative is the 
                    // first thing in the line
            {
                return readNumber();
            }
            return Token {MINUS, "-"};
        }
        else if (currentChar == '*')
        {
            return Token {MULTIPLICATION, "*"};
        }
        else if (currentChar == '/')
        {
            return Token {DIVISION, "/"};
        }
        else if (currentChar == '^')
        {
            return Token {POWER, "^"};
        }
        else if (currentChar == '(')
        {
            return Token {LPAREN, "("};
        }
        else if (currentChar == ')')
        {
            return Token {RPAREN, ")"};
        }
        else if (currentChar == '[')
        {
            return Token {LSBRACE, "["};
        }
        else if (currentChar == ']')
        {
            return Token{RSBRACE, "]"};
        }
        else if (currentChar == '=')
        {
            return Token {EQUAL, "="};
        }
        else if (currentChar == ',')
        {
            return Token {COMMA, ","};
        }
        else if (currentChar == ':')
        {
            return Token {ASSIGN, ":"};
        }
        else if (currentChar == '<')
        {
            return Token {LESSTHAN, "<"};
        }
        else if (currentChar == '>')
        {
            return Token {GREATERTHAN, ">"};
        }
        else if (currentChar == '!')
        {
            return Token {NEGATION, "!"};
        }

        position = size; // End the line if Ilegal token
        std::string str = "";
        return Token{ILLEGAL, str.append(1, currentChar)}; // If is none of the above, it must be illegal
    }


    void Lexer::processFunction() 
    {
        position ++; // When comming from the readLine(), the position still 0

        token = getToken(line[position]);
        if (token.name.compare(WORD)) // If after 'milf' does not come the function name, it's an error
        {
            tokens.clear();
            return;
        }
        tokens.push_back(token); // Add the function name
        position ++; /* Add after, because else it will mess up with the other functions, as the position
            is shared beetween them, this because when reading a word, you are not reading the whole 
            word at a time, you read character by character, so messing with the position before time,
            messes up the reading of this words */

        token = getToken(line[position]);
        if (token.name.compare(LPAREN)) // if after the name does to come arguments, then is wrong
        {
            tokens.clear();
            return;
        }
        tokens.push_back(token);
        position ++;

        // Get all the arguments for the function
        while (position < size && token.name.compare(RPAREN))
        {
            token = getToken(line[position]);
            tokens.push_back(token);
            position ++;
        }

        std::cout << "----";
        bool start = false; // Whether a '[' has been reached or not
        bool close = false; // Whether a ']' has been reached or not
        while (!close && std::getline(std::cin, line))
        {
            line = stripWhiteSpace(line);
            size = line.size();
            position = -1;

            while (++position < size)
            {
                token = getToken(line[position]);
                if (!token.name.compare(LSBRACE) && token.name.compare(ILLEGAL))
                {
                    start = true; // We have found the starting brace
                    tokens.push_back(token);
                }
                else if (start && token.name.compare(ILLEGAL)) // Check that we have encountered a '[' before adding anything else
                {
                    if (!token.name.compare(RSBRACE))
                    {
                        close = true;
                    }

                    tokens.push_back(token);
                }
                else // If we have not encountered a '[' or a token is illegal there is an error
                {
                    tokens.clear();
                    return;
                }
            }

            if (!close) // Print the sign at the end of the line, meaninig that the function is processing
                std::cout << "----";
        }
    }


    void Lexer::processIf() // The processIf is basically the same as the processFunction, but excluding the name
    {
        // TODO: finish process if

        position ++; // When comming from the readLine(), the position still 0

        token = getToken(line[position]);
        if (token.name.compare(LPAREN)) // if it does not have arguments, then is wrong
        {
            tokens.clear();
            return;
        }
        tokens.push_back(token);
        position ++;

        // Get all the arguments
        while (position < size && token.name.compare(RPAREN))
        {
            token = getToken(line[position]);
            tokens.push_back(token);
            position ++;
        }

        std::cout << "----";
        bool start = false; // Whether a '[' has been reached or not
        bool close = false; // Whether a ']' has been reached or not
        while (!close && std::getline(std::cin, line))
        {
            line = stripWhiteSpace(line);
            size = line.size();
            position = -1;

            while (++position < size)
            {
                token = getToken(line[position]);
                if (!token.name.compare(LSBRACE) && token.name.compare(ILLEGAL))
                {
                    start = true; // We have found the starting brace
                    tokens.push_back(token);
                }
                else if (start && token.name.compare(ILLEGAL)) // Check that we have encountered a '[' before adding anything else
                {
                    if (!token.name.compare(RSBRACE))
                    {
                        close = true;
                    }

                    tokens.push_back(token);
                }
                else // If we have not encountered a '[' or a token is illegal there is an error
                {
                    tokens.clear();
                    return;
                }
            }

            if (!close) // Print the sign at the end of the line, meaninig that the if is processing
                std::cout << "----";
        }
    }