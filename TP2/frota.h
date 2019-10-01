#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include "veiculo.h"
using namespace std;

class Frota {
	vector<Veiculo *> veiculos;
public:
    void adicionaVeiculo(Veiculo* v1);
    int numVeiculos() const;
    int menorAno() const;
    friend ostream & operator<<(ostream & o, const Frota & f);  //this is declared as friend to have access to private members of classes
    vector<Veiculo *> operator () (int anoM) const;
    float totalImposto() const;
};

#endif /*FROTA_H_*/
