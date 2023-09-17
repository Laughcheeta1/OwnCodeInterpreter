#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// Numerical:
    const std::string INTEGER = "INTEGER";
    const std::string DECIMAL = "FLOATNUMBER";
    const std::string PLUS = "PLUS"; // +
    const std::string MINUS = "MINUS"; // -
    const std::string MULTIPLICATION = "MULTIPLICATION"; // *
    const std::string DIVISION = "DIVISION"; // /
    const std::string POWER = "POWER"; // ^
    const std::string ROOT = "ROOT"; // root
    const std::string LOG = "LOG"; // log
    const std::string LN = "LN"; // ln

// Logical
    const std::string TRUE = "TRUE"; // true
    const std::string FALSE = "FALSE"; // false
    const std::string NEGATION = "NEGATION"; // ! // TODO: implement the negation
    const std::string EQUAL = "EQUAL"; // =
    const std::string LESSTHAN = "LESSTHAN"; // <
    const std::string GREATERTHAN = "GREATERTHAN"; // >
    const std::string LESSEREQUAL = "LESSEREQUAL"; // <=
    const std::string GREATEREQUAL = "GREATEREQUAL"; // >=

// Programming Wise
    const std::string ASSIGN = "ASSIGN"; // :

// Text
    const std::string WORD = "WORD";
    const std::string LPAREN = "LPAREN"; // (
    const std::string RPAREN = "RPAREN"; // )
    const std::string COMMA = "COMMA"; // ,
    const std::string LSBRACE = "LSBRACE";
    const std::string RSBRACE = "RSBRACE";

// Other
    const std::string ILLEGAL = "ILLEGAL";

struct Token {
    std::string name;
    std::string value;
};

#endif // TOKEN_H
