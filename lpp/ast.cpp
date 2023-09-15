#include "../Header/Token.h"
#include "../Header/ast.h"

using namespace std;

// NodeAST class
    NodeAST::NodeAST(NodeAST* par, NodeAST* lc, NodeAST* rc, Token val)
    {
        parent = par;
        leftChild = lc;
        rightChild = rc;
        value = val;
    }

    void NodeAST::setParent(NodeAST* p)
    {
        parent = p;
    }
    void NodeAST::setLeftChild(NodeAST* lc)
    {
        leftChild = lc;
    }
    void NodeAST::setRightChild(NodeAST* rc)
    {
        rightChild = rc;
    }
    void NodeAST::setValue(Token val)
    {
        value = val;
    }
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
    int ast::getPriority(string token)
    {
        if (!token.compare("=") || !token.compare("<=") || !token.compare(">=") || !token.compare("<")
            || !token.compare(">"))
            return 0;

        else if (!token.compare("+") || !token.compare("-"))
            return 1;

        else if (!token.compare("*") || !token.compare("/"))
            return 2;

        // TODO Finish the implementation of the raiz and log operand, for now, leave it there
        else if (!token.compare("^") || !token.compare("raiz") || !token.compare("log")) 
            return 3;

        else // Must be a number, and numbers have the higher priority
            return 4;
    }

    NodeAST* ast::getRoot(NodeAST* node)
    {
        while (node -> getParent() != NULL)
            node = node -> getParent();

        return node;
    }

    NodeAST* ast::placeOperand(NodeAST* upper, Token token)
    {
        /* When two characters have the same priority, evaluate from left to right, in case of the tree, have the right one (last to enter)
        on top */
        if (upper == NULL)
            return NULL;

        if (getPriority(token.value) > getPriority(upper -> getValue().value)) // Compare for more priority (stop climbing the tree)
        {
            NodeAST* result = new NodeAST(upper, upper -> getRightChild(), NULL, token);
            upper -> getRightChild() -> setParent(result);
            upper -> setRightChild(result);
            return result;
        }

        NodeAST* result = placeOperand(upper -> getParent(), token);
        if (result == NULL)
        {
            result = new NodeAST(NULL, upper, NULL, token);
            upper -> setParent(result);
        }

        return result;
    }

    /* Starting index and ending index are intended for parenthesis, so we can deal with them*/
    NodeAST* ast::makeTree(vector<Token> tokens, int currentIndex, int endingIndex)
    {
        /* Remember that to free the memory from creating a class with "new", you use "delete *name of the pointer*"
        For more info check "https://stackoverflow.com/questions/4061514/c-object-created-with-new-destroyed-with-free-how-bad-is-this" */
        
        NodeAST* currentNode; 
        NodeAST* lastNode = NULL;

        while (currentIndex <= endingIndex)
        {            
            if (tokens[currentIndex].name.compare("NUMBER") == 0) // if is a number
            {
                currentNode = new NodeAST(lastNode, NULL, NULL, tokens[currentIndex]);
                if (lastNode != NULL)
                    lastNode -> setRightChild(currentNode);
            } 
            // TODO add when it is a parenthesis
            else // If not a number, must be an Operand
            {
                currentNode = placeOperand(lastNode, tokens[currentIndex]);
            }

            lastNode = currentNode;
            currentIndex++;
        }

        return getRoot(currentNode);
    }