#include "../Header/milf.h"
#include "../Header/evaluator.h"
#include "../Header/environment.h"

Milf::Milf(std::vector<Token> funDeclarationExpression)
{
    
    int i = 0;
    while (funDeclarationExpression[i].name.compare(LPAREN) != 0){
        i++;
    }
    //stock the function declaration that will be executed every time
    //cant make the three here because it's missing the variables
    std::vector<Token> subVect {funDeclarationExpression.begin() + i, funDeclarationExpression.end()};
        this->funDeclarationExpression = subVect;
}

std::string Milf::callFunction(std::vector<Token> arguments)
{
    Environment* envMilf = new Environment();
    int i = 0;
    //create variables and put there value
    for(; i < (int)arguments.size() * 3 ; i += 3){//for every argument create variable with funDeclarationExpression begining and argument value
        envMilf -> variables[vec[1].value] = Token {Evaluator::getTypeOfVariable(this->funDeclarationExpression.at(i+1)), arguments.at(2*i/3)}; // (var a, var b) (1,2) 
    }

    //evaluate the rest
    i++ //pass the LSBRACE

    std::vector<Token> aux;

    while(this->funDeclarationExpression[i].name.compare(NEWLINE) != 0 && this->funDeclarationExpression[i].name.compare(RSBRACE) != 0){

        aux.insert(aux.end(),this->funDeclarationExpression[i]);
        i = i + 1;

        if(this->funDeclarationExpression[i].name.compare(RETURN)){
            std::string result = Evaluator::evaluate(aux,envMilf);
            return result;
        }
    }

}