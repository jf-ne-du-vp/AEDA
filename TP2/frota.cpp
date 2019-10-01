#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return veiculos.size();
}

int Frota::menorAno() const {
    int ano_menor;

    if(numVeiculos() == 0)
        return 0;
    ano_menor = veiculos[0]->getAno();  //or (*veiculos[0]).getAno()

    for(size_t i = 1 ; i < numVeiculos(); i++)
    {
        if(ano_menor > veiculos[i]->getAno())
            ano_menor = veiculos[i]->getAno();
    }

    return ano_menor;
}

vector<Veiculo *> Frota::operator()(int anoM) const {
    vector<Veiculo *> veiculos_anoM;

    if(numVeiculos() == 0)
        return veiculos_anoM;

    vector<Veiculo *>::const_iterator it=veiculos.begin();
    while(it!= veiculos.end()){
        if((*it)->getAno() == anoM){
            veiculos_anoM.push_back(*it);
        }
        it++;
    }

    return veiculos_anoM;
}

float Frota::totalImposto() const{
    float impostoTotal = 0.0;

    if(numVeiculos() == 0)
        return impostoTotal;

    vector<Veiculo *>::const_iterator it=veiculos.begin();
    while(it!= veiculos.end()){
        impostoTotal = (*it)->calcImposto() + impostoTotal;
        it++;
    }

    return impostoTotal;
}

/*ostream & operator<< (ostream & o, const Frota & f){              //why is this declared in tests?
    vector<Veiculo *>::const_iterator it=f.veiculos.begin();
    while(it!= f.veiculos.end()){
        (*it)->info();
        it++;
    }

    return o;
}*/
