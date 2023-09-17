#include "../Header/Token.h"
#include "../Header/ast.h"
#include "../Header/parser.h"
#include "../Header/lexer.h"

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
        if (!token.compare("EQUAL") || !token.compare("LESSER EQUAL") || !token.compare("GREATER EQUAL") || !token.compare("LESS THAN")
            || !token.compare("GREATER THAN"))
            return 0;

        else if (!token.compare("PLUS") || !token.compare("MINUS"))
            return 1;

        else if (!token.compare("MULTIPLICATION") || !token.compare("DIVISION"))
            return 2;

        // TODO Finish the implementation of the raiz and log operand, for now, leave it there
        else if (!token.compare("POWER") || !token.compare("ROOT") || !token.compare("LOG") || !token.compare("LN")) 
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

        if (getPriority(token.name) > getPriority(upper -> getValue().name)) // Compare for more priority (stop climbing the tree)
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
    NodeAST* ast::makeTree(vector<Token> tokens)
    {
        return makeTree(tokens, 0, tokens.size() - 1);
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
            // TODO: finish when it is a parenthesis
            if (tokens[currentIndex].name.compare("LPAREN") == 0)
            {
                int sIndex = currentIndex + 1;
                while (tokens[currentIndex].name.compare("RPAREN")) // Find the index of the closing parenthesis
                    currentIndex++;
                
                NodeAST* n = makeTree(tokens, currentIndex + 1, currentIndex - 1); // Get the tree inside the parenthesis
                if (n == NULL) // Check for validity of the tree
                    return NULL;

                Parser p; // Variable we are using to evaluate
                Lexer l;
                std::string result = p.evaluateTree(n); // Get the result inside of parenthesis
                std::string typeOfValue = l.getTypeOfValue(result);

                if (!typeOfValue.compare("ILLEGAL")) // If result is valid
                    return NULL;

                Token t = Token {typeOfValue, result};

                currentNode = new NodeAST(lastNode, NULL, NULL, t); // Make the token for the tree
                if (lastNode != NULL)
                    lastNode -> setRightChild(currentNode);

            }
            else if (tokens[currentIndex].name.compare("NUMBER") == 0) // if is a number
            {
                currentNode = new NodeAST(lastNode, NULL, NULL, tokens[currentIndex]);
                if (lastNode != NULL)
                    lastNode -> setRightChild(currentNode);
            } 
            else // If not a number, must be an Operand
            {
                currentNode = placeOperand(lastNode, tokens[currentIndex]);
            }

            lastNode = currentNode;
            currentIndex++;
        }

        return getRoot(currentNode);
    }

    // Frees up the tree in a inorder manner
    void ast::freeTree(NodeAST* currentNode)
    {
        if (currentNode -> getLeftChild() != NULL)
            freeTree(currentNode -> getLeftChild());
        if (currentNode -> getRightChild() != NULL)
            freeTree(currentNode -> getRightChild());
        
        delete currentNode;
    }