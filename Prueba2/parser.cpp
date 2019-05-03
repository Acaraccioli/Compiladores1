#include "parser.h"
#include "error.h"

void Parser::parse() {
    currToken=lexer.getNextToken();
    input();
}

void Parser::input(){
    stmt_list();
    opt_eol();
}

void Parser::stmt_list(){
    stmt();
    stmt_list_prime();
}
void Parser::opt_eol(){
    if(currToken==Token::Eol)
    {
        currToken=lexer.getNextToken();
    }

}

void Parser::stmt(){
    if(currToken==Token::Ident)
    {
        currToken=lexer.getNextToken();
        if(currToken==Token::OpAssign)
        {
        currToken=lexer.getNextToken();
        expr();
        }
    }
    else if(currToken==Token::KwPrint)
    {
        currToken=lexer.getNextToken();
        expr();
    }
}

void Parser::stmt_list_prime(){
    if(currToken==Token::Eol)
    {
        currToken=lexer.getNextToken();
        stmt_list();
    }
}

void Parser::expr(){
    term();
    expr_prime();

}

void Parser::expr_prime(){

       if(currToken==Token::OpAdd)
    {
        currToken=lexer.getNextToken();
        expr_prime();
    }
    else if(currToken==Token::OpSub)
    {
        currToken=lexer.getNextToken();
        expr_prime();
    }
}

void Parser::term(){
    factor();
    term_prime();
}

void Parser::term_prime(){
   if(currToken==Token::OpMul)
    {
        currToken=lexer.getNextToken();
        factor();
        term_prime();
    }
    else if(currToken==Token::OpDiv)
    {
        currToken=lexer.getNextToken();
        factor();
        term_prime();
    }

}

void Parser::factor(){

    if(currToken==Token::OpenPar)
    {
        currToken=lexer.getNextToken();
        expr();
        if(currToken==Token::ClosePar);
        currToken=lexer.getNextToken();
    }
    else if(currToken==Token::Ident)
    {
        currToken=lexer.getNextToken();
       
    }
    else if(currToken==Token::Number)
    {
        currToken=lexer.getNextToken();
       
    }
    else if(currToken==Token::ClosePar)
    {
                currToken=lexer.getNextToken();

    }
    else if(currToken==Token::Eof)
    {
        currToken=lexer.getNextToken();
       
    }
    else
    {
        cout<<"error"<<endl;
    }
    
}