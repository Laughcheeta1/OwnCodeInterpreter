#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include <string.h>
#include "../Header/ifExpression.h"
#include "../Header/Token.h"
#include "../Header/lexer.h"
#include "../Header/ast.h"
#include "../Header/parser.h"
#include "../Header/environment.h"
#include "../Header/evaluator.h"


void IfExpression::evaluateIfExpression(std::vector<Token> a, Environment* env){

    std::vector<Token> ar;

    int i = 2;

    while (a[i].name.compare(RPAREN) != 0){

        ar.insert(ar.end(),a[i]);
        i = i + 1;
    }

    std::string result = Evaluator::evaluate(ar, env);

    if (result.compare(TRUE) == 0){

        i = i + 2;

        while(i < (int)a.size() && a[i].name.compare(RSBRACE) != 0){
            if (a[i].name.compare(NEWLINE) == 0 && a[i-1].name.compare(LSBRACE) == 0){
                i = i + 1;
            }
            if (a[i].name.compare(IFEXPRESSION) == 0){
                std::vector<Token> vectorIf;
                while(a[i].name.compare(RSBRACE)!=0){
                    vectorIf.insert(vectorIf.end(),a[i]);
                    i = i+1;
                }
                
                vectorIf.insert(vectorIf.end(),a[i]);
                IfExpression::evaluateIfExpression(vectorIf,env);

                i ++;
            } else if(a[i-1].name.compare(LSBRACE) == 0 || a[i-1].name.compare(NEWLINE) == 0 ){

                std::vector<Token> aux;

                while(a[i].name.compare(NEWLINE) != 0 && a[i].name.compare(RSBRACE) != 0){

                    aux.insert(aux.end(),a[i]);
                    i = i + 1;         
                }

                result = Evaluator::evaluate(aux,env);
                std::cout << "Result inside If: " << result << std::endl;
                i++;
            } else if (a[i].name.compare(NEWLINE)==0 && a[i-1].name.compare(RSBRACE)==0) {

                i = i+1;

                std::vector<Token> aux;

                while(a[i].name.compare(NEWLINE) != 0 && a[i].name.compare(RSBRACE) != 0){

                    aux.insert(aux.end(),a[i]);
                    i = i + 1;         
                }

                if (aux.size() != 0)
                {
                    std::string result = Evaluator::evaluate(aux,env);
                    std::cout << "Result inside If: " << result << std::endl;
                }
            }
            
        }

    }
    
}