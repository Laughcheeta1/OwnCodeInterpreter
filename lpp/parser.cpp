#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include <string.h>
#include "../Header/Token.h"
#include "../Header/lexer.h"
#include "../Header/ast.h"
#include "../Header/parser.h"


std::string Parser::evaluateTree(NodeAST* node){
    if((node->getLeftChild()->getValue().name.compare("INTEGER")==0 || node->getLeftChild()->getValue().name.compare("FLOATNUMBER")==0) 
    && (node->getRightChild()->getValue().name.compare("INTEGER")== 0 || node->getRightChild()->getValue().name.compare("FLOATNUMBER")== 0))
    {
        double a = stod(node->getLeftChild()->getValue().value);
        double b = stod(node->getRightChild()->getValue().value);

        if (node->getValue().value.compare("+") == 0){
            std:: string c = std::to_string(a+b);
            return c;
        }
        else if (node->getValue().value.compare("-") == 0){
            std:: string c = std::to_string(a-b);
            return c;
        }
        else if (node->getValue().value.compare("/") == 0){
            std:: string c = std::to_string(a/b);
            return c;
        }
        else if (node->getValue().value.compare("*") == 0){
            std:: string c = std::to_string(a*b);
            return c;
        }
        else if (node->getValue().value.compare("<") == 0){
            if (a < b){
                return "TRUE";
            }
            return "FALSE";
        }
        else if (node->getValue().value.compare(">") == 0){
            if (a > b){
                return "TRUE";
            }
            return "FALSE";
        }
        else if (node->getValue().value.compare("=") == 0){
            if (a == b){
                return "TRUE";
            }
            return "FALSE";
        }
        else if (node->getValue().value.compare("<=") == 0){
            if (a <= b){
                return "TRUE";
            }
            return "FALSE";
        }
        else if (node->getValue().value.compare(">=") == 0){
            if (a >= b){
                return "TRUE";
            }
            return "FALSE";
        }
    }
    else if((node->getLeftChild()->getValue().name.compare("INTEGER")==0 || node->getLeftChild()->getValue().name.compare("FLOATNUMBER")==0) 
    && (!(node->getRightChild()->getValue().name.compare("INTEGER")== 0) || !(node->getRightChild()->getValue().name.compare("FLOATNUMBER")== 0)))
    {
       return evaluateTree(node->getRightChild());
    }
    else if((!(node->getLeftChild()->getValue().name.compare("INTEGER")==0) || !(node->getLeftChild()->getValue().name.compare("FLOATNUMBER")==0)) 
    && (node->getRightChild()->getValue().name.compare("INTEGER")== 0 || node->getRightChild()->getValue().name.compare("FLOATNUMBER")== 0))
    {
       return evaluateTree(node->getLeftChild());
    }
}