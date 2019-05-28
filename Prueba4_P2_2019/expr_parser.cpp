#include <vector>
#include "expr_parser.h"

struct Rule {
    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

Rule rule0{Symbol::SPrime, {Symbol::S}};
Rule rule1{Symbol::S, {Symbol::OpenBrace, Symbol::L, Symbol::CloseBrace}};
Rule rule2{Symbol::L, {Symbol::L, Symbol::Comma, Symbol::Id}};
Rule rule3{Symbol::L, {Symbol::Id}};
Rule none;

enum ActionType { Accept, Shift, Reduce, Empty };
struct Action {
    Action(): 
        type(ActionType::Empty),
        state(-1),
        rule(none) {}

    Action(ActionType type):
        type(type),
        state(-1),
        rule(none) {}
    
    Action(unsigned state):
        type(ActionType::Shift),
        state(state),
        rule(none) {}
    
    Action(Rule& rule):
        type(ActionType::Reduce),
        state(-1),
        rule(rule) {}

    ActionType type;
    int state;
    Rule& rule;
};

Action empty;
Action s1(1);
Action s3(3);
Action s5(5);
Action s6(6);
Action s7(7);
Action r0(rule0); // Reduce rule 0: S' -> S
Action r1(rule1); // Reduce rule 1: S -> { L }
Action r2(rule2); // Reduce rule 2: L -> L , id
Action r3(rule3); // Reduce rule 3: L -> id
Action accept(ActionType::Accept);

/* { } , Id $ */
std::vector<std::vector<Action>> lr0_action = {
    {s1, empty, empty, empty,r0},/* State 0 */
    {empty, empty,empty, s3, r1},/* State 1 */
    {empty,empty,empty,empty, empty},/* State 2 */
    {r2,r2,r2,r2,r2},/* State 3 */
    {empty,r1,s5, empty, empty},/* State 4 */
    {empty, empty, empty, s7, empty},/* State 5 */
    {r1,r1, r1, r1, r1},/* State 6 */
    {r0, r0, r0, r0, accept}/* State 7 */
};

/* SPrime S L */
std::vector<std::vector<int>> lr0_goto = {
    {1,0,0,0,2},/* State 0 */ 
    {3,0,0,0,4},/* State 1 */ 
    {0,0,0,0,0},/* State 2 */ 
    {1,0,0,0,0},/* State 3 */ 
    {4,5,6,0,0},/* State 4 */ 
    {7,0,0,0,0},/* State 5 */ 
    {4,0,0,0,0},/* State 6 */ 
    {0,0,0,0,0}/* State 7 */ 
};

int Parser::parse(int count[4]) {
    currToken =lexer.getNextToken();
    lr0_goto[0];
    goto1();
    return 0;
}

void Parser::goto1()
{
    if(currToken==Symbol::OpenBrace)
    lr0_goto[1];
    else if(currToken==Symbol::S)
    lr0_goto[2];
}

void Parser::goto2()
{
    r0; //Reduce de S
}
void Parser::goto3()
{
    if(currToken==Symbol::Id)
    lr0_goto[3];
    else if (currToken==Symbol::L)
    lr0_goto[4];
}
