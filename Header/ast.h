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
        // Constructor, getters and setters
        explicit NodeAST(NodeAST* par, NodeAST* lc, NodeAST* rc, Token val);
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
        static int getPriority(std::string token); // Returns the priority of the expression in the following range [0, 4]
        static NodeAST* placeOperand(NodeAST* previous, Token token); // Places the operand in the place it should
                                                                // be, with the sons it should have.
        static float evaluateRoot(std::string expresion); // TODO make this function
        static float evaluateLog(std::string expresion); // TODO make this function
        static NodeAST* getRoot(NodeAST* node); // Returns the head of the tree you created
        static NodeAST* makeTree(std::vector<Token> tokens, int currentIndex, int endingIndex); // Returns a pointer to the head node of the tree
        static int getClosingParenIndex(std::vector<Token> tokens, int startingIndex, int maxIndex);
    
    public:
        static NodeAST* makeTree(std::vector<Token> tokens); // Returns a pointer to the head node of the tree
        static void freeTree(NodeAST* currentNode); // Given the head node of the tree, frees all the memory
            // I'm declaring a class by the keyword "new"

};
#endif