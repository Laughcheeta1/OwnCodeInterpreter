#include "../Header/milf.h"
#include "../Header/evaluator.h"
#include "../Header/environment.h"
#include <iostream>
#include <string>


Milf::Milf(std::vector<Token> funDeclarationExpression)
{
    std::cout << "here";
    /*
    //stock the function declaration that will be executed every time
    //cant make the three here because it's missing the variables
    this->functionContent = funDeclarationExpression;

    for (const auto& token : this->functionContent) {
            std::cout << token.value << " ";
        }

    
    if (!this->functionContent.empty()) {
        for (const auto& token : this->functionContent) {
            std::cout << token.value << " ";
        }
        std::cout << std::endl;  // Add a newline for clarity
    } else {
        std::cout << "The vector is empty." << std::endl;
    }
    */
    
    
}

std::string Milf::callFunction(std::vector<Token> arguments)
{
    int i = 0;

    std::vector<std::string> variableName = {};

    std::vector<std::string> variableValue = {};

    while (this->functionContent[i].name.compare(RPAREN))
    {
        std::cout << this->functionContent[i].value << " ";
    }

    /*
    //Environment* envMilf = new Environment();
    int i = 0;
    std::vector<std::string> variableName = {};

    std::vector<std::string> variableValue = {};

    //create variables and put there value
    while (this->funDeclarationExpression[i].name.compare(RPAREN))
    {
        std::cout << this->funDeclarationExpression[i].value << " ";
    }

    std::cout << "after" << std::endl;

    int j = 0;
    while (arguments[j].name.compare(RPAREN))
    {
        std::cout << arguments[j].value << " ";
    }


    

    //create variables and put there value
    
    for(; i < (int)arguments.size()  ; i++){//for every argument create variable with funDeclarationExpression begining and argument value

        std::vector<Token> expression(vec.begin() + 3, vec.end()); // thats the part after the assign
        std::string result = Evaluator::evaluate(expression, env);
        envMilf -> variables[vec[1].value] = Token {Evaluator::getTypeOfVariable(result), result};


        envMilf -> variables[vec[1].value] = Token {Evaluator::getTypeOfVariable(this->funDeclarationExpression.at(i+1)), arguments.at(2*i/3)}; // (var a, var b) (1,2)
        


    }
    
    //evaluate the rest
    i++; //pass the LSBRACE

    std::vector<Token> aux;

    while(this->funDeclarationExpression[i].name.compare(NEWLINE) != 0 && this->funDeclarationExpression[i].name.compare(RSBRACE) != 0){

        aux.insert(aux.end(),this->funDeclarationExpression[i]);
        i = i + 1;

        if(this->funDeclarationExpression[i].name.compare(RETURN)){
            std::string result = Evaluator::evaluate(aux,envMilf);
            return result;
        }
    }
    */
    return "!";
}