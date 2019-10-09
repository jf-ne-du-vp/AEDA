#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

/*
 * Classe Zoo
 */

int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1) {
    animais.push_back(a1);
}

bool Zoo::animalJovem(string nomeA) const{
    size_t numAZoo = animais.size();

    for(size_t i = 0; i<numAZoo; i++){   //could have created an iterator, as it was done at the previous exercices TP2
        if(animais[i]->getNome() == nomeA && animais[i]->eJovem() == true) {return true;}
    }

    return false;
}

string Zoo::getInformacao() const {
    string info;

    /*vector<Animal *>::const_iterator it=animais.begin();                  not working, soo i used a for loop
    while(it != animais.end()){
        info += (*it)->getInformacao();
        info += "\n";
    }*/

    for(size_t i = 0; i < animais.size(); i++){
        info += animais[i]->getInformacao();
    }


    return info;
}

void Zoo::alocaVeterinarios(istream &isV){
    //isV.open ("vets.txt"); don´t have to do this because it is already opened when if it is declared, before it is passed to alocaVeterinarios
    string vetNome, cod;  //there needs to be a cleaner solution then to use a variable garbage
    long vetCod;

    while(!isV.eof()){

        getline(isV, vetNome);
        //getline(isV, vetCod);    this is wrong because it can not assign a string to a long, it doesn´t do the type change
        getline(isV, cod);

        vetCod = stol(cod, nullptr,10);

        Veterinario *vete = new Veterinario(vetNome, vetCod);       //don´t forget in this case i have to create with the word new, because it is in the cicle
        veterinarios.push_back(vete);
    }

    int j = 0;

    for(int i = 0; i < animais.size(); i++){
        animais[i]->setVet(veterinarios.at(j));
        j++;
        if(j%numVeterinarios() == 0)
            j = 0;
    }
}

bool Zoo::removeVeterinario(string nomeV) {
    for(unsigned i = 0; i < veterinarios.size(); i++) {
        if(veterinarios[i]->getNome() == nomeV){
            for(unsigned j = 0; j < animais.size(); j++) {
                if (animais[i]->getVet() == veterinarios[i])
                    animais[i]->setVet(veterinarios[i+1]);
            }
            veterinarios.erase(veterinarios.begin()+i);
            return true;
        }
    }
    return false;
}

bool Zoo::operator < (Zoo& zoo2) const{
    int zoo1Age = 0, zoo2Age = 0;

    for(auto animal:animais){
        zoo1Age += animal->getIdade();
    }

    for(auto animal:zoo2.animais){
        zoo2Age += animal->getIdade();
    }

    return zoo1Age < zoo2Age;
}


