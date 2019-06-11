#include "expr_ast.h"

std::string AddExpr::toString(){
	return "("+Expression1->toString()+")"+"+"+"("+Expression2->toString()+")";
}

std::string SubExpr::toString(){
	return "("+Expression1->toString()+")"+"-"+"("+Expression2->toString()+")";
}

std::string MulExpr::toString(){
	return "("+Expression1->toString()+")"+"*"+"("+Expression2->toString()+")";
}

std::string DivExpr::toString(){
	return "("+Expression1->toString()+")"+"/"+"("+Expression2->toString()+")";
}

std::string ModExpr::toString(){
	return "("+Expression1->toString()+")"+"%"+"("+Expression2->toString()+")";
}

int AddExpr::eval(){
	int x = Expression1->eval();
	int y = Expression2->eval();
	int res = x + y;
	return res;
}

int SubExpr::eval(){
	int x = Expression1->eval();
	int y = Expression2->eval();
	int res = x - y;
	return res;
}

int DivExpr::eval(){
    int x=Expression1->eval();
    int y=Expression2->eval();
    int res= x/y;
    return res;
}

int ModExpr::eval(){
    int x=Expression1->eval();
    int y=Expression2->eval();
    int res= x%y;
    return res;
}