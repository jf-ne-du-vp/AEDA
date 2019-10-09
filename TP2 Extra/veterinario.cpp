
#include "veterinario.h"
#include <sstream>
using namespace std;

Veterinario::Veterinario(string nome, long cod) {
    this->nome = nome;
    codOrdem = cod;
}


string Veterinario::getNome() const {
	return nome;
}

long Veterinario::getCodOrdem() const {
    return codOrdem;
}

string Veterinario::getInformacao() const {
    string info = "";

    if (!getNome().empty()){
        info += ", ";
        info += getNome();
        info += ", ";
        info += to_string(getCodOrdem());
    }

    return info;
}





