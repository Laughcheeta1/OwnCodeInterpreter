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
        void setParent(NodeAST* p);
        void setLeftChild(NodeAST* lc);
        void setRightChild(NodeAST* rc);
        void setValue(Token val);
        NodeAST* getParent();
        NodeAST* getLeftChild();
        NodeAST* getRightChild();
        Token getValue();

};

class ast
{
    private:
        int getPriority(std::string token); // Returns the priority of the expression in the following range [0, 3]
        float evaluateRoot(std::string expresion); // TODO make this function
        float evaluateLog(std::string expresion); // TODO make this function
    
    public:
        NodeAST* makeTree(std::vector<Token> tokens, int currentIndex, int endingIndex); // Returns a pointer to the head node of the tree

};
#endif