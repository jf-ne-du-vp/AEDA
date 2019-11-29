#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;


bool Aposta::contem(unsigned num) const
{
    auto it = numeros.find(num);

    return !(it == numeros.end());

}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    unsigned a = 0;
    while(getNumeros().size() != n){
        numeros.insert(valores[a]);
        a++;
    }
}


unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    unsigned numCertos = 0;

    auto itSorteio = sorteio.begin();

    while(itSorteio != sorteio.end()){
        auto it = numeros.find(*itSorteio);
        if(!(it == numeros.end()))
            numCertos++;
        itSorteio++;
    }

    return numCertos;
}