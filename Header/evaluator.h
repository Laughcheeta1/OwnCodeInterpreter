#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Token.h"
#include <vector>

class Evaluator 
{
    private:
        int position;
        std::vector<Token> vec;
        std::vector<Token> evaluateFunction();
        std::vector<Token> evaluateIf();
        
    public:
        std::vector<Token> processTokens(); // Convert complex tokens (Tokens made by more than one token) into a single token
        static std::vector<Token> evaluate(std::vector<Token> input);
};

#endif
