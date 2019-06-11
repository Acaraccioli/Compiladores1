
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <bits/unique_ptr.h>
//using iostream;
//#define ADD(x, y) (std::make_unique<AddExpr>((x), (y)))
class ExprUPtr {
    public:
        ExprUPtr(str::unique_ptr){}
        virtual int eval() = 0;
};

class NumExpr : public ExprUPtr {
public:
    NumExpr(int val): value(val){}
    std::string toString(){
        return std::to_string(value);
    };
    int eval(){return value;};
    int value;
};

class IdExpr : public ExprUPtr { 
    public:
        IdExpr(ExprUPtr * Expression1, ExprUPtr * Expression2) : Expression1(std::move(Expression1)), Expression2(std::move(Expression2)){}
        ExprUPtr * Expression1, * Expression2;
        std::string toString(){};
        int eval(){};
};


class IdExpr : public ExprUPtr {
public:
    IdExpr(std::string name) : name(name){}
    std::string name;
    std::string toString(){
        return name;
    };
    int eval(){};
};








