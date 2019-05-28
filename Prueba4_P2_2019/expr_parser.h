#ifndef _PARSER_H
#define _PARSER_H

#include <iosfwd>
#include "expr_lexer.h"

class Parser {
public:
    Parser(Lexer& lexer): lexer(lexer) {}
    int parse(int count[4]);
    void goto1();
    void goto2();
    void goto3();


private:
    Lexer& lexer;
    Symbol currToken;
};

#endif
