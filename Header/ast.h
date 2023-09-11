#ifndef AST_H
#define AST_H
#include "Token.h"

class NodeAST
{
    private:
        NodeAST* parent;
        NodeAST* leftChild;
        NodeAST* rightChild;
        Token value;

    public:

}
#endif