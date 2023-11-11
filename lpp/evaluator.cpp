#include "../Header/evaluator.h"



std::vector<Token> Evaluator::evaluate(std::vector<Token> input, Environment env)
{
    Evaluator e(input, env);
    e.evaluateExpression();
}

Evaluator::Evaluator(std::vector<Token> vector, Environment environment)
{
    vec = vector;
    size = vector.size();
    position = 0;
    env = environment;
}

void Evaluator::evaluateExpression()
{

}

std::vector<Token> Evaluator::evaluateFunction()
{
    
}

std::vector<Token> Evaluator::evaluateIf()
{
    
}