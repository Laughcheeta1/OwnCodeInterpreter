#include "../Header/Token.h"
#include "../Header/ast.h"

using namespace std;

    // Constructor
    NodeAST::NodeAST() {  }

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