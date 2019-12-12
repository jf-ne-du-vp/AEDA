#include "maquinaEmpacotar.h"
#include <sstream>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {

    for(auto it = objs.begin(); it != objs.end(); it++){
        if(it->getPeso() <= capacidadeCaixas){
            objetos.push(*it);
            it = objs.erase(it);            //lembrar que erase retorna o iterador na posicao a frente do que foi eliminado
            it--;
        }
    }

	return objetos.size();
}


Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	Caixa cx;
	vector<Caixa> auxiliar;

	while(!caixas.empty()){
	    if(caixas.top().getCargaLivre() >= obj.getPeso()){
	        cx = caixas.top();
	        caixas.pop();
	        break;
	    }
	    else{
	        auxiliar.push_back(caixas.top());
	        caixas.pop();
	    }
	}

	for(const auto & i : auxiliar){
	    caixas.push(i);
	}

	return cx;
}


unsigned MaquinaEmpacotar::empacotaObjetos() {

    while(!objetos.empty()){
        Objeto ob = objetos.top();
        Caixa cx = procuraCaixa(ob);
        cx.addObjeto(ob);
        caixas.push(cx);
        objetos.pop();
    }

	return caixas.size();
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
    if(objetos.empty())
	return "Nao ha objetos!\n";

    string objectos;
    priority_queue<Objeto> aux;     //uso ja uma priority_queue em vez de vetor, assim e so igualar
    aux = objetos;

    while(!aux.empty()){
        objectos= objectos + "O" + to_string(aux.top().getID()) +": " + to_string(aux.top().getPeso()) + "\n";          //operador << ja esta definido, podia ter usado stringstrem
        aux.pop();
    }


    return objectos;
}


Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
    if(caixas.empty())  throw MaquinaSemCaixas();

    Caixa cx;
    HEAP_CAIXAS aux;
    aux = caixas;

    while(!aux.empty()){
        if(cx.getSize() < aux.top().getSize()){
            cx = aux.top();
        }
        aux.pop();
    }
	return cx;
}



