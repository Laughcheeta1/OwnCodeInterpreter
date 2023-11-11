#include "../Header/evaluator.h"

std::vector<Token> Evaluator::purifyTokens()
{
    position = 0;
    while (position < (int)vec.size())
    {
        if (!vec[position].value.compare("<") && position + 1 < (int)vec.size() && !vec[position + 1].value.compare("="))
        {
            vec.erase(vec.begin() + position);
            vec[position].value = "<=";
            vec[position].name = LESSEREQUAL;
        }
        else if (!vec[position].value.compare(">") && position + 1 < (int)vec.size() && !vec[position + 1].value.compare("="))
        {
            vec.erase(vec.begin() + position);
            vec[position].value = ">=";
            vec[position].name = GREATEREQUAL;
        }
        else if (!vec[position].value.compare("log") || !vec[position].value.compare("LOG"))
        {
            // processLog(vec);
        }
        else if (!vec[position].value.compare("ln") || !vec[position].value.compare("LN"))
        {
            // processLn(vec);
        }
        else if (!vec[position].value.compare("raiz") || !vec[position].value.compare("RAIZ"))
        {
            // processRaiz(vec);
        }
        else if (!vec[position].value.compare(TRUE))
        {
            vec[position].name = TRUE;
        }
        else if (!vec[position].value.compare(FALSE))
        {
            vec[position].name = FALSE;
        }

        position++;
    }

    return vec;
}

std::vector<Token> Evaluator::evaluate(std::vector<Token> input, Environment env)
{
    Evaluator e(input, env);
    e.purifyTokens();
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