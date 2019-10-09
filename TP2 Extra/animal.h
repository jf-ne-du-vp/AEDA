
#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;


class Animal {
protected:
	string nome;
	int idade;
	Veterinario *vet;
	static int maisJovem;
public:
	Animal(string nome, int idade);
	virtual ~Animal(){};
	string getNome() const;
	int getMaisJovem() const;
	int getIdade() const;
	virtual string getInformacao() const;
	virtual bool eJovem() const = 0;
	Veterinario* getVet() const;
	void setVet(Veterinario *vet);
};



class Cao: public Animal {
	string raca;
public:
	Cao(string nome, int idade, string raca);
	bool eJovem() const;
	string getRaca() const;
	string getInformacao() const;
};


class Voador {
	int velocidade_max;
	int altura_max;
public:
	Voador(int vmax, int amax);
    virtual ~Voador(){};
    int getVMax() const;
    int getAlturaMax() const;
    virtual string getInformacao() const;
};


class Morcego: public Animal, public Voador {
public:
	Morcego(string nome, int idade, int vmax, int amax);
	bool eJovem() const;
	string getInformacao() const;
};


#endif /* SRC_ANIMAL_H_ */
