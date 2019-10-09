
#include "animal.h"
#include <sstream>
using namespace std;

/*
 * Classe Animal
 */

Animal::Animal(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
    if(maisJovem > idade)
        maisJovem = idade;
}

int Animal::maisJovem = 99999;

string Animal::getNome() const {
	return nome;
}

void Animal::setVet(Veterinario *vet) {
    this->vet = vet;
}

Veterinario *Animal::getVet() const {
    return vet;
}

Cao::Cao(string nome, int idade, string raca) : Animal(nome, idade){
    this->raca = raca;
}

Voador::Voador(int vmax, int amax) {
    velocidade_max = vmax;
    altura_max = amax;
}

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome, idade), Voador(vmax, amax){
}

int Animal::getMaisJovem() const {
    return maisJovem;
}

bool Cao::eJovem() const {
    return idade < 5;
}

bool Morcego::eJovem() const {
    return idade < 4;

}

int Animal::getIdade() const {
    return idade;
}

string Animal::getInformacao() const {
    /*string info;
    info += getNome();
    info += ", ";
    info += to_string(getIdade());
    if(!((*vet).getNome()).empty()) {
        info += ", ";
        info += (*vet).getNome();
        info += ", ";
        info += to_string((*vet).getCodOrdem());
    }
    info += vet->getInformacao();*/


    return nome + ", " + to_string(idade) + (*vet).getInformacao();
    //return info;
}

string Cao::getRaca() const {
    return raca;
}

string Cao::getInformacao() const {
    string info;
    info += Animal::getInformacao();
    info += ", ";
    info += getRaca();

    return info;
}

int Voador::getAlturaMax() const {
    return altura_max;
}

int Voador::getVMax() const {
    return velocidade_max;
}

string Voador::getInformacao() const {
    string info;
    info += to_string(getVMax());
    info += ", ";
    info += to_string(getAlturaMax());

    return info;
}

string Morcego::getInformacao() const{
    string info;
    info += Animal::getInformacao();
    info += ", ";
    info += Voador::getInformacao();

    return info;
}




