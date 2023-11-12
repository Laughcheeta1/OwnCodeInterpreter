#include "../Header/evaluator.h"
#include "../Header/ast.h"
#include "../Header/parser.h"
#include "../Header/ifExpression.h"
// #include "../Header/customFun.h"

/*
Cases that can be passed to us:
    1-  5 + 7   This is a direct expression
    2-  x + y  This is a direct expression, but with variables
    3-  if() []  This is an if
    4-  func()  This is a function calling
    5-  var x = ...  This is a variable declaration
    6-  milf func() []  This is a fucntion declaration
*/


std::string Evaluator::evaluate(std::vector<Token> input, Environment env)
{
    Evaluator e(input, env);
    return e.evaluateExpression();
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
    if (!vec[0].name.compare(IFEXPRESSION))
    {
        IfExpression::evaluateIfExpression(vec, env);
        return NULL;
    }

    else if (!vec[0].name.compare(FUNCTION))
    {
        // env.functions[vec[1].value] = CustomFun(vec); // Enter the new function to the environment
        return NULL;
    }

    else if (!vec[0].name.compare(VAR))
    {
        declareVariable();
        return NULL;
    }
    
    // Must be a case 1
    return evaluateRegularExpression();
}

std::string Evaluator::evaluateRegularExpression()
{
    int x = vec.size();
    std::vector<Token> newExpression;
    for (int i = 0; i < x; i++)
    {
        if (!vec[i].name.compare(WORD))
        {
            if (env.variables.count(vec[i].value) != 0) // If it is a variable
            {
                newExpression.push_back(env.variables[vec[i].value]);
            }
            // else if (env.functions.count(vec[i].value) != 0) // It is a function
            // {
            //     i += 2; // After the function name there is a parenthesis, so += 2 to skip that parenthesis
            //     int start = i;
            //     while (i < x && vec[i].name.compare(LPAREN))
            //     {
            //         i++;
            //     }
            //     std::vector<Token> arguments(vec.begin() + start, vec.begin() + i); // i finishes pointing to the left parenthesis

            //     std::string result = env.functions[vec[i].value].callFun(arguments);
            //     Token tok;
            //     tok.name = Evaluator::getTypeOfVariable(result);
            //     tok.value = result;

            //     newExpression.push_back(tok);
            // }
        }
        else
            newExpression.push_back(vec[i]);
    }


    NodeAST* n = ast::makeTree(newExpression);
    std::string result = Parser::evaluateTree(n);
    ast::freeTree(n);

    return result;
}

void Evaluator::declareVariable()
{
    std::vector<Token> expression(vec.begin() + 3, vec.end()); // thats the part after the assign
    std::string result = Evaluator::evaluate(expression, env);
    Token tok;
    tok.name = Evaluator::getTypeOfVariable(result);
    tok.value = result;
    env.variables[vec[1].value] = tok;
}

std::string Evaluator::getTypeOfVariable(std::string variable)
{
    if (isalpha(variable[0]))
    {
        return WORD;
    }
    
    int i = 0;
    while (i < variable.size() && variable[i] != '.')
    {
        i ++;
    }

    return (i < variable.size()) ? DECIMAL : INTEGER;
}