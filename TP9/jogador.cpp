#include "jogador.h"


void Jogador::adicionaAposta(const Aposta & ap)
{
    apostas.insert(ap);
}


unsigned Jogador::apostasNoNumero(unsigned num) const
{
	unsigned contem = 0;

	for(auto a : apostas){
	    if(a.contem(num))
	        contem++;
	}

	return contem;
}


tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;

	for(auto a : apostas){
	    if(a.calculaCertos(sorteio) > 3){
	        money.insert(a);
	    }
	}

	return money;
}
