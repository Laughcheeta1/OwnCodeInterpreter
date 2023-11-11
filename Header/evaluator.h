#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Token.h"
#include "environment.h"
#include <vector>
#include <string>


/*
The purpose of this class is for recieving a line of code and decide what to do with it
*/
class Evaluator 
{
    private:
        int position;
        int size;
        std::vector<Token> vec;
        Environment env;

        std::string evaluateExpression();
        void evaluateIf();
        std::string evaluateVarOrFunc();
        void declareVariable();
        void declareFunction();
        
    public:
        explicit Evaluator(std::vector<Token> vector, Environment environment);
        static std::vector<Token> evaluate(std::vector<Token> input, Environment env);
};

#endif
