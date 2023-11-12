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
    ast::ast(vector<Token> tok)
    {
        tokens = tok;
        size = tok.size();
        currentIndex = 0;
    }

    int ast::getPriority(string token)
    {
        if (!token.compare(EQUAL) || !token.compare(LESSEREQUAL) || !token.compare(GREATEREQUAL) || !token.compare(LESSTHAN)
            || !token.compare(GREATERTHAN))
            return 0;

        else if (!token.compare(PLUS) || !token.compare(MINUS))
            return 1;

        else if (!token.compare(MULTIPLICATION) || !token.compare(DIVISION))
            return 2;

        // TODO Finish the implementation of the raiz and log operand, for now, leave it there
        else if (!token.compare(POWER) || !token.compare(ROOT) || !token.compare(LOG) || !token.compare(LN)) 
            return 3;

        else // Must be a number, and numbers have the higher priority
            return 4;
    }

    NodeAST* ast::getRoot(NodeAST* node)
    {
        if (node == NULL)
            return NULL;
            
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

    /* Starting index and ending index are intended for parenthesis, so we can deal with them*/
    NodeAST* ast::makeTree()
    {
        /* Remember that to free the memory from creating a class with "new", you use "delete *name of the pointer*"
        For more info check "https://stackoverflow.com/questions/4061514/c-object-created-with-new-destroyed-with-free-how-bad-is-this" */
        
        NodeAST* currentNode = NULL; 
        NodeAST* lastNode = NULL;

        while (currentIndex < size && tokens[currentIndex].name.compare(RPAREN))
        {   
            if (tokens[currentIndex].name.compare(NEGATION) == 0)
            {   
                int numberOfNegation = 0;
                while (currentIndex < size && tokens[currentIndex].name.compare(NEGATION) == 0)
                {
                    currentIndex++;
                    numberOfNegation++;
                }

                if (currentIndex == size) // If there isn't something behind the negation
                {
                    freeTree(getRoot(lastNode));
                    return NULL;
                }

                std::string result;
                if (tokens[currentIndex].name.compare(LPAREN) == 0) // is is an expresion in parenthesis
                {
                    currentIndex += 2; // By adding two, instead of one, we avoid making an extra recursion unnesesarily 
                        // (because when finding a LPAREN it )
                    NodeAST* n = makeTree(); // Get the tree inside the parenthesis
                    if (n == NULL) // Check for validity of the tree
                    {
                        freeTree(getRoot(lastNode));
                        return NULL;
                    }

                    result = Parser::evaluateTree(n);
                    freeTree(n); // Free the tree after being evaluated
                    result = Lexer::getTypeOfValue(result);
                }
                else
                {
                    result = tokens[currentIndex].name;
                }
                
                if (result.compare(TRUE) == 0)
                {
                    if (numberOfNegation % 2 == 1)
                        result = FALSE;
                }
                else if (result.compare(FALSE) == 0)
                {
                    if (numberOfNegation % 2 == 1)
                        result = TRUE;
                }
                else // Theres an invalid thing behind the negation
                {
                    freeTree(getRoot(lastNode));
                    return NULL;
                }

                Token t = Token {result, result}; // Make the base node
                currentNode = new NodeAST(lastNode, NULL, NULL, t);
            }
            else if (tokens[currentIndex].name.compare(LPAREN) == 0)
            {
                currentIndex++; // Advance the index when entering the 
                NodeAST* n = makeTree(); 
                    // Get the tree inside the parenthesis
                if (n == NULL) // Check for validity of the tree
                {
                    freeTree(getRoot(lastNode));
                    return NULL;
                }

                std::string result = Parser::evaluateTree(n); // Get the result inside of parenthesis
                freeTree(n); // Free the tree after being evaluated
                std::string typeOfValue = Lexer::getTypeOfValue(result);

                if (!typeOfValue.compare(ILLEGAL)) // If result is valid
                {
                    freeTree(getRoot(lastNode));
                    return NULL;
                }

                Token t = Token {typeOfValue, result};

                currentNode = new NodeAST(lastNode, NULL, NULL, t); // Make the token for the tree
                if (lastNode != NULL)
                    lastNode -> setRightChild(currentNode);

            }
            else if (tokens[currentIndex].name.compare(INTEGER) == 0 || tokens[currentIndex].name.compare(DECIMAL) == 0
                || tokens[currentIndex].name.compare(TRUE) == 0 || tokens[currentIndex].name.compare(FALSE) == 0) 
                // if is a number or boolean
            {
                currentNode = new NodeAST(lastNode, NULL, NULL, tokens[currentIndex]);
                if (lastNode != NULL)
                    lastNode -> setRightChild(currentNode);
            } 
            else // If not a number or boolean, must be an Operand
            {
                currentNode = placeOperand(lastNode, tokens[currentIndex]);
            }

            lastNode = currentNode;
            currentIndex++;
        }

        return getRoot(currentNode);
    }

    NodeAST* ast::makeTree(std::vector<Token> tok) // This is intended to initialize the recursive function
        // this is so the other classes does not need to deal with setting the currentIndex to 0 again when calling the function.
    {
        ast a(tok);
        return a.makeTree();
    }

    // Frees up the tree in a inorder manner
    void ast::freeTree(NodeAST* currentNode)
    {
        if (currentNode == NULL)
            return;

        freeTree(currentNode -> getLeftChild());
        freeTree(currentNode -> getRightChild());
        
        delete currentNode;
    }