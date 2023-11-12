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
#include "../Header/environment.h"


void evaluateIf(std::vector<Token> a, Environment env){

    std::vector<Token> ar;

    int i = 2;

    while (a[i].name.compare(RPAREN) != 0){

        ar.insert(ar.end(),a[i]);
        i = i + 1;
    }

    NodeAST* n = ast::makeTree(ar);

    if (Parser::evaluateTree(n).compare(TRUE)){

        i = i + 2;

        while(a[i].name.compare(RSBRACE) != 0){
            if(a[i-1].name.compare(LSBRACE) == 0 || a[i-1].name.compare(NEWLINE) == 0){

                std::vector<Token> aux;

                while(a[i].name.compare(NEWLINE) != 0){

                    i = i + 1;
                    aux.insert(aux.end(),a[i]);
                
                }

                NodeAST* nodo = ast::makeTree(aux);
                Parser::evaluateTree(nodo);
            }
            
        }

    }
    
}