#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H
#include <sstream>
#include "lexer.h"
using namespace std;

class Parser {
public:
    Parser(Lexer&lex,std::ostringstream &stream):lexer(lex){}

	void parse();

    void input();
    void opt_eol();
    void stmt_list();
    void stmt_list_prime();
    void stmt();
    void expr();
    void expr_prime();
    void term_prime();
    void term();
    void factor();



private:
    Lexer &lexer;
    Token currToken;
    template<typename T>
    bool tokenIs(T tk) {
        return (currToken == tk);
    }

    template<typename T, typename... TArgs>
    bool tokenIs(T firstTk, TArgs... moreTk) {
        return (currToken == firstTk) || tokenIs(moreTk...);
    }
};

#endif
