#include "caixa.h"
#include <sstream>
#include <queue>


Objeto::Objeto(unsigned idObj, unsigned pesoObj): id(idObj), peso(pesoObj)
{}

unsigned Objeto::getID() const {
	return id;
}

unsigned Objeto::getPeso() const {
	return peso;
}

Caixa::Caixa(unsigned cap): id(ultimoId++), capacidade(cap), cargaLivre(cap)
{}

unsigned Caixa::getID() const {
	return id;
}

unsigned Caixa::getCargaLivre() const {
	return cargaLivre;
}

void Caixa::addObjeto(Objeto& obj) {
	cargaLivre -= obj.getPeso();
	objetos.push(obj);
}

void Caixa::resetID(){
	ultimoId = 1;
}

unsigned Caixa::getSize() const {
	return objetos.size();
}


ostream& operator<<(ostream& os, Objeto obj) {
	os << "O" << obj.id << ": " << obj.peso;
	return os;
}

unsigned Caixa::ultimoId = 1;

bool Objeto::operator<(const Objeto& o1) const {
	return this->getPeso() < o1.getPeso();
}


bool Caixa::operator<(const Caixa& c1) const {
	return this->cargaLivre > c1.cargaLivre;
}


string Caixa::imprimeConteudo() const {
        if(!this->objetos.empty()){
            stringstream conteudo;
            conteudo << "C" << this->id << "[ ";
            STACK_OBJS aux;
            aux = objetos;
            while(!aux.empty()){
                conteudo << aux.top() << " ";
                aux.pop();
            }
            conteudo << "]";
            return conteudo.str();
        }

	return "Caixa "+to_string(this->id)+ " vazia!\n";
}



