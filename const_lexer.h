
#ifndef EXPR_LEXER_h
#define EXPR_LEXER_h
#include <iostream>
#include <fstream>
#include "fa/lexer.h"

class ConstLexer
{
private:
    std::string text;
    std::istream &in;
public:
    ConstLexer(std::istringstream &in): in(in){}
    Token getNextToken();
    std::string getText(){return text;}
    static const char* toString(Token tk);
    int getNextChar()
    {
        return in.get();
    }
   

   
};



#endif