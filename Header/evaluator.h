#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Token.h"
#include "environment.h"
#include <vector>

class Evaluator 
{
    private:
        int position;
        int size;
        std::vector<Token> vec;
        Environment env;

        std::vector<Token> evaluateFunction();
        std::vector<Token> evaluateIf();

        /// @brief Convert complex tokens (Tokens made by more than one token) into a single tokens
        /// @return the purified tokens
        std::vector<Token> purifyTokens();
        void evaluateExpression(); // TODO: Still have to make this function
        
    public:
        explicit Evaluator(std::vector<Token> vector, Environment environment);
        static std::vector<Token> evaluate(std::vector<Token> input, Environment env);
};

#endif
