#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"
#include<algorithm>

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts()
{
	vector<CKart> vord;
	for(auto p:getPistas())
    {
	    for(auto c:p.getFrotaActual())
	        vord.push_back(c);
	}

	sort(vord.begin(), vord.end());

	return vord;
}

bool CKart::operator<(CKart &c)const {
    return this->numero<c.getNumero();
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)        //ha funcao que ja da os avariados
{
    int total = 0;
    for(auto p:getPistas())
    {
        for(auto c:p.getFrotaActual())
            if(c.getAvariado() && c.getCilindrada() == cilind)
                total++;
    }

    return total;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    int emProva = 0;

    for(auto p:frotaKartsPista){
        if(!p.getAvariado() && p.getCilindrada() == cilind){
            emProva++;
            kartsLinhaPartida.push(p);
        }
    }


    return emProva >= numeroKarts;
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    while(!kartsLinhaPartida.empty()){
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
    }

    return kartsEmProva.size();
}

