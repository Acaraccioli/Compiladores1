#ifndef __LEXER_H__
#define __LEXER_H__

enum class StateId {
    Start_q0,
    Start_q1,
    Numbers_q0,
    Numbers_q1,
    Numbers_q2,
};

enum class Token {
    Binary,
    Decimal,
    Eof,
    Hex,
    Octal,
};
#endif