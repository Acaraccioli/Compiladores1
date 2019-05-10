#include <iostream>
#include <algorithm>
#include "LL1.h"

LL1::LL1(Grammar &gr,
         const StringToStringSetMap& _firsts,
         const StringToStringSetMap& _follows): gr(gr)
{
    for (const auto& f : _firsts) {
        std::string nt_name = f.first;
        const StringSet& sset = f.second;
        GSymbolPtrSet symb_set;

        std::transform(sset.begin(), sset.end(), std::inserter(symb_set, symb_set.end()),
                        [&gr](const std::string& s) { return gr.getSymbol(s); });

        firsts[nt_name] = std::move(symb_set);
    }

    for (const auto& f : _follows) {
        std::string nt_name = f.first;
        const StringSet& sset = f.second;
        GSymbolPtrSet symb_set;

        std::transform(sset.begin(), sset.end(), std::inserter(symb_set, symb_set.end()),
                        [&gr](const std::string& s) { return gr.getSymbol(s); });

        follows[nt_name] = std::move(symb_set);
    }
}

GSymbolPtrSet LL1::getFirsts(const GSymbolPtrVector& symbv) {
     GSymbolPtr temp= symbv.back();
     //char & paraimprimir= temp->toString();
     //printf(temp->toString());
     printf("hola");
     GSymbolPtrSet *temps;
     if(temp->isTerminal()){
        for(int i=0;i<symbv.size();i++)
        {
            //temps.include(getFirsts(temp));

        }
     return *temps;
     }
     else
     {
         getFirsts(temp);
         
     }
     
     //if(temp==(GSymbol::epsilon))
     //cout<<temp->toString<<endl;



}

void LL1::computeTable()
{
    GSymbolPtrVector prueba;
    //getFirsts(prueba);
}

