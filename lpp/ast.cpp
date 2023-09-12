#include "../Header/Token.h"
#include "../Header/ast.h"

using namespace std;

// NodeAST class
    NodeAST* NodeAST::getParent()
    {
        return parent;
    }
    NodeAST* NodeAST::getLeftChild()
    {
        return leftChild;
    }
    NodeAST* NodeAST::getRightChild()
    {
        return rightChild;
    }
    Token NodeAST::getValue()
    {
        return value;
    }


// ast class
    int getPriority(string token)
    {
        if (!token.compare("=") || !token.compare("<=") || !token.compare(">=") || !token.compare("<")
            || !token.compare(">"))
            return 0;

        else if (!token.compare("+") || !token.compare("-"))
            return 1;

        else if (!token.compare("*") || !token.compare("/"))
            return 2;
        
        else if (!token.compare("^") || !token.compare("raiz") || !token.compare("log")) // Finish the implementation of the raiz and log operand, for now, leave it there
            return 3;
    }