#ifndef IF
#define IF
#include "ast.h"
#include "Token.h"
#include "lexer.h"
#include "parser.h"
#include "environment.h"
#include <vector>

class IfExpression 
{
 private:



 public:
    static void evaluateIfExpression(std::vector<Token> a, Environment env);

};

#endif