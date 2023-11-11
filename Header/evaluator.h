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

        void evaluateExpression(); // TODO: Still have to make this function
        
    public:
        explicit Evaluator(std::vector<Token> vector, Environment environment);
        static std::vector<Token> evaluate(std::vector<Token> input, Environment env);
};

#endif
