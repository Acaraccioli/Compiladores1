Token ExprLexer::getNextToken() {
    StateId state = StateId::Start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // Start
            case StateId::Start_q0:
                state = StateId::Start_q1;
                text="";
                break;
            case StateId::Start_q1:
                if (ch == '\n') {
                    state = StateId::Start_q1;
                    ch = getNextChar();
                } else if (ch == ' ') {
                    state = StateId::Start_q1;
                    ch = getNextChar();
                } else if (ch == '\t') {
                    state = StateId::Start_q1;
                    ch = getNextChar();
                } else if (ch == EOF) {
                    return Token::Eof;
                } else {
                    // Trying next automaton 'Numbers'
                    state = StateId::Numbers_q0;
                }
                break;
            // Numbers
            case StateId::Numbers_q0:
                if ((ch >= 'a') && (ch <= 'f')) {
                    text += ch;
                    state = StateId::Numbers_q1;
                    ch = getNextChar();
                } else if ((ch >= 'A') && (ch <= 'F')) {
                    text += ch;
                    state = StateId::Numbers_q1;
                    ch = getNextChar();
                } else if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = StateId::Numbers_q2;
                    ch = getNextChar();
                } else {
                    reportError(ch);
                    ch = getNextChar();
                    state = StateId::Start_q0;
                }
                break;
            case StateId::Numbers_q1:
                if (ch == 'h') {
                    text += ch;
                    return Token::Hex;
                } else if ((ch >= 'a') && (ch <= 'f')) {
                    text += ch;
                    state = StateId::Numbers_q1;
                    ch = getNextChar();
                } else if ((ch >= 'A') && (ch <= 'F')) {
                    text += ch;
                    state = StateId::Numbers_q1;
                    ch = getNextChar();
                } else {
                    state = StateId::Start_q0;
                    ch = getNextChar();
                }
                break;
            case StateId::Numbers_q2:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = StateId::Numbers_q2;
                    ch = getNextChar();
                } else if (ch == 'o') {
                    text += ch;
                    return Token::Octal;
                } else if (ch == 'O') {
                    text += ch;
                    return Token::Octal;
                } else if (ch == 'b') {
                    text += ch;
                    return Token::Binary;
                } else if (ch == 'B') {
                    text += ch;
                    return Token::Binary;
                } else {
                    ungetChar(ch);
                    return Token::Decimal;
                }
                break;
        }
    }
}
