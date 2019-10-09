
#ifndef SRC_VETERINARIO_H_
#define SRC_VETERINARIO_H_

#include <string>
using namespace std;

class Veterinario {
	string nome;
	long codOrdem;
public:
	Veterinario(string nome, long cod);
	string getNome() const;
	long getCodOrdem() const;
	string getInformacao() const;
};


#endif /* SRC_VETERINARIO_H_ */
