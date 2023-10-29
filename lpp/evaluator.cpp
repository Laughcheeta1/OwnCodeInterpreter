#include "../Header/evaluator.h"

std::vector<Token> Evaluator::evaluate(std::vector<Token> input)
{
    Evaluator e;
    e.processTokens();
    e.vec = input;
}

std::vector<Token> Evaluator::processTokens() // TODO finish the method
{
    position = 0;
    while (position < (int)vec.size())
    {
        if (!vec[position].name.compare(VAR))
        {
            position ++;
            return evaluateFunction();
        }
        if (!vec[position].name.compare(FUNCTION))
        {
            position ++;
            return evaluateIf();
        }
        else if (!vec[position].value.compare("<") && position + 1 < (int)vec.size() && !vec[position + 1].value.compare("="))
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

std::vector<Token> Evaluator::evaluateFunction()
{
    if (!(position < (int)vec.size() && position == 1 && !vec[position].name.compare(WORD)))
    {
        printf("Illegal expresion, VAR must be the first thing in the line\n");
        vec.clear();
        return vec;
    }
}

std::vector<Token> Evaluator::evaluateIf()
{
    if (!(position == 0 && position + 1 < (int)vec.size() && !vec[position + 1].value.compare(WORD)))
    {
        printf("Illegal expresion, MILF statement used incorrectly\n");
        vec.clear();
        return vec;
    }
}