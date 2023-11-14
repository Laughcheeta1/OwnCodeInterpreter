#include "../Header/evaluator.h"
#include "../Header/ast.h"
#include "../Header/parser.h"
#include "../Header/ifExpression.h"
#include "../Header/milf.h"


std::string Evaluator::evaluate(std::vector<Token> input, Environment* env)
{
    Evaluator e(input, env);
    return e.evaluateExpression();
}

Evaluator::Evaluator(std::vector<Token> vector, Environment* environment)
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
        return "Finished if expression";
    }

    else if (!vec[0].name.compare(FUNCTION))
    {
        env -> functions[vec[1].value] = new Milf(vec, vec[1].value); // Enter the new function to the environment
        return "Function was declared";
    }

    else if (!vec[0].name.compare(VAR))
    {
        declareVariable();
        return "Variable has been declared";
    }
    
    // Must be a case 1
    return evaluateRegularExpression();
}

std::string Evaluator::evaluateRegularExpression()
{
    int x = vec.size();
    std::vector<Token> newExpression;
    for ( ; position < x; position++)
    {
        if (env -> variables.count(vec[position].value) != 0) // If it is a variable
        {
            newExpression.push_back(env -> variables[vec[position].value]);
        }
        else if (env -> functions.count(vec[position].value) != 0) // It is a function
        {
            std::string funcName = vec[position].value; // Store the func name, since we continue changing i
            position += 2; // After the function name there is a parenthesis, so += 2 to skip that parenthesis
            std::vector<Token> arguments = getArguments();

            std::string result = env -> functions[funcName] -> callFunction(arguments);

            newExpression.push_back(Token {Evaluator::getTypeOfVariable(result), result});
        }
        else
            newExpression.push_back(vec[position]);
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
    env -> variables[vec[1].value] = Token {Evaluator::getTypeOfVariable(result), result};
}

std::string Evaluator::getTypeOfVariable(std::string variable)
{
    if (isalpha(variable[0]))
    {
        return WORD;
    }
    
    int i = 0;
    while (i < (int)variable.size() && variable[i] != '.')
    {
        i ++;
    }

    return (i < (int)variable.size()) ? DECIMAL : INTEGER;
}

std::vector<Token> Evaluator::getArguments()
{
    std::vector<Token> result;
    std::string evaluateExpressionResult;
    while (position < size && vec[position].name.compare(RPAREN))
    {
        std::vector<Token> expression; // Since we can get something like (3 + 5, 9), we need to convert that expressions into a single thing
        while (position < size && vec[position].name.compare(COMMA) && vec[position].name.compare(RPAREN))
        {
            expression.push_back(vec[position]);
            position++;
        }

        evaluateExpressionResult = Evaluator::evaluate(expression, env);
        result.push_back(Token {getTypeOfVariable(evaluateExpressionResult), evaluateExpressionResult});

        position++;
    }
    
    return result;
}