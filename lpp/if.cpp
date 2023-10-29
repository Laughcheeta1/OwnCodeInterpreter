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

void evaluateIf(std::vector<Token> a){

    std::vector<Token> ar;

    int i = 2;

    while (a[i].value.compare(")") != 0){

        i = i + 1;

        ar.insert(ar.end(),a[i]);
    }

    NodeAST* n = ast::makeTree(ar);

    if (Parser::evaluateTree(n).compare(TRUE)){

        i = i + 2;

        while(a[i].value.compare("]") != 0){
            if(a[i-1].value.compare("[") == 0 || a[i-1].value.compare("\n") == 0){

                std::vector<Token> aux;

                while(a[i].value.compare("\n") != 0){
                    i = i + 1;

                    aux.insert(aux.end(),a[i]);
                
                }

                NodeAST* nodo = ast::makeTree(aux);

                Parser::evaluateTree(nodo);
 
            }
            
        }

    }
    
}