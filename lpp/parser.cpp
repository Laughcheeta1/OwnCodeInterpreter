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
    if (node == NULL)
        return ILLEGAL;

    else if (node->getValue().name.compare(INTEGER) == 0 || node->getValue().name.compare(DECIMAL)== 0
    || node->getValue().name.compare(TRUE)== 0 || node->getValue().name.compare(FALSE)==0 || node -> getValue().name.compare(WORD) == 0){
        return node->getValue().value;
    }

    std:: string left = evaluateTree(node->getLeftChild());
    std:: string right = evaluateTree(node->getRightChild());


    if ((left.compare(TRUE) == 0 || left.compare(FALSE)==0) && 
    (right.compare(TRUE)== 0 || right.compare(FALSE)==0)){

        if (node->getValue().value.compare("=") == 0){
            if (left.compare(right)==0){
            return TRUE;
            } else {
            return FALSE;
            }
        } else {
            return ILLEGAL;
        }
    } else if((!(left.compare(TRUE) == 0) || !(left.compare(FALSE)==0)) && 
    (right.compare(TRUE)== 0 || right.compare(FALSE)==0)) {
        return ILLEGAL;
    } else if ((left.compare(TRUE) == 0 || left.compare(FALSE)==0) && 
    (!(right.compare(TRUE)== 0) || !(right.compare(FALSE)==0))){
        return ILLEGAL;
    } if((left.compare(WORD) != 0 && right.compare(WORD) == 0)||
        (left.compare(WORD) == 0 && right.compare(WORD) != 0)) {
        return ILLEGAL;
    } else if(left.compare(WORD) == 0 && right.compare(WORD) == 0){
        std:: string c = left.append(right);
        return c;
    }  
    else {

        double a = stod(left);
        double b = stod(right);
        
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
                    return TRUE;
                }
                return FALSE;
        }
        else if (node->getValue().value.compare(">") == 0){
                if (a > b){
                    return TRUE;
                }
                return FALSE;
        }
        else if (node->getValue().value.compare("=") == 0){
                if (a == b){
                    return TRUE;
                }
                return FALSE;
        }
        else if (node->getValue().value.compare("<=") == 0){
                if (a <= b){
                    return TRUE;
                }
                return FALSE;
        }
        else if (node->getValue().value.compare(">=") == 0){
                if (a >= b){
                    return TRUE;
                }
                return FALSE;

        } else {
            return ILLEGAL;
        }

    }
    
    if (left.compare(ILLEGAL)== 0 || right.compare(ILLEGAL)==0){
        return ILLEGAL;
    }
    
   
    
}