#include "../Header/evaluator.h"
#include "../Header/ast.h"
#include "../Header/parser.h"
#include "../Header/if.h"

/*
Cases that can be passed to us:
    1-  5 + 7   This is a direct expression
    2-  x + y  This is a direct expression, but with variables
    3-  if() []  This is an if
    4-  func()  This is a function calling
    5-  var x = ...  This is a variable declaration
    6-  milf func() []  This is a fucntion declaration
*/


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

std::string Evaluator::evaluateExpression()
{
    if (!vec[0].name.compare(WORD)) // If the first token is a name, it could be either a case 2 or 4
    {
        evaluateVarOrFunc();
        return NULL;
    }

    else if (!vec[0].name.compare(IFEXPRESSION))
    {
        If::evaluateIf(vec, env);
        return NULL;
    }

    else if (!vec[0].name.compare(FUNCTION))
    {
        declareFunction();
        return NULL;
    }

    else if (!vec[0].name.compare(VAR))
    {
        declareVariable();
        return NULL;
    }
    
    // Must be a case 1
    return evaluateExpression();
}

std::string Evaluator::evaluateExpression()
{
    NodeAST* n = ast::makeTree(vec);
    std::string result = Parser::evaluateTree(n);
    ast::freeTree(n);

    return result;
}

void Evaluator::evaluateIf()
{
    
}

std::string Evaluator::evaluateVarOrFunc()
{
    
}

void Evaluator::declareVariable()
{
    
}

void Evaluator::declareFunction()
{
    
}