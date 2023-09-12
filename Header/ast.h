#ifndef AST_H
#define AST_H
#include "Token.h"
#include <vector>

class NodeAST
{
    private:
        NodeAST* parent;
        NodeAST* leftChild;
        NodeAST* rightChild;
        Token value;

    public:
        NodeAST* getParent();
        NodeAST* getLeftChild();
        NodeAST* getRightChild();
        Token getValue();

};

class ast
{
    private:
        int getPriority(std::string token); // Returns the priority of the expression in the following range [0, 3]
    
    public:
        NodeAST* makeTree(std::vector<Token> tokens); // Returns a pointer to the head node of the tree

};
#endif