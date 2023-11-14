#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Token.h"
#include "environment.h"
#include <vector>
#include <string>


/*
The purpose of this class is for recieving a line of code and decide what to do with it
*/
class Environment;

class Evaluator 
{
    private:
        int position;
        int size;
        std::vector<Token> vec;
        Environment* env;

        std::string evaluateExpression();
        std::string evaluateRegularExpression();
        void declareVariable();
        std::vector<Token> getArguments();
        
    public:
        explicit Evaluator(std::vector<Token> vector, Environment* environment);
        static std::string evaluate(std::vector<Token> input, Environment* env);
        static std::string getTypeOfVariable(std::string variable);
};

#endif
