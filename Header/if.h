#ifndef IF
#define IF
#include "ast.h"
#include "Token.h"
#include "lexer.h"
#include "parser.h"
#include "environment.h"
#include <vector>

class If 
{
 private:



 public:
    static void evaluateIf(std::vector<Token> a, Environment env);

};

#endif