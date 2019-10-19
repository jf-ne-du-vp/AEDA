#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;



ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }

bool comp(const InfoCartao &info1, const InfoCartao &info2 ) { return (info1.nome < info2.nome); }


int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    InfoCartao info;
    info.nome = nome;
    return sequentialSearch(clientes, info);
}


int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    int pos = posicaoCliente(nome);

    if(pos == -1)
        throw ClienteNaoExistente(nome);

    return clientes[pos].frequencia;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;  //why do i have to initialize with 0?
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
    clientes[pos].frequencia++;
	vagas--;

	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}


void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    insertionSort(clientes);
}


// a implementar
void ParqueEstacionamento::ordenaClientesPorNome()
{
    sort(clientes.begin(), clientes.end(), comp);
}


// a implementar
vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    ordenaClientesPorFrequencia();
    vector<string> nomes;

    for(size_t i = 0; i < numClientes; i++)
        if(clientes[i].frequencia >= n1 && clientes[i].frequencia <= n2)
            nomes.push_back(clientes[i].nome);

    return nomes;
}


// a implementar
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    for(auto cliente : pe.clientes)
        os << "Nome: " << cliente.nome << " Esta presente: " << cliente.presente << " Numero de utilizacoes: " << cliente.frequencia << endl;
        //presente aparece como 0 ou 1, perguntar como mudar isso

    return os;
}


InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    InfoCartao info;
    if(p > (clientes.size() - 1))
        throw PosicaoNaoExistente(p);

    info = clientes[p];

    return info;
}

bool InfoCartao::operator==(const InfoCartao & info) const {
    return (this->nome == info.nome);
}

bool InfoCartao::operator<(const InfoCartao &info) const {          //needs to work for both name and frequency
    if(this->frequencia > info.frequencia)
        return true;
    else if(this->frequencia < info.frequencia)
        return false;
    else if(this->frequencia == info.frequencia)
    {
        return (this->nome < info.nome);
    }

    return false;
}



ClienteNaoExistente::ClienteNaoExistente(const string &nome) {
    this->nome = nome;
}

string ClienteNaoExistente::getNome() const {
    return this->nome;
}

PosicaoNaoExistente::PosicaoNaoExistente(const int &pos) {
    this->pos = pos;
}

int PosicaoNaoExistente::getValor() const{
    return this->pos;           //ask if i dont or why i have to use this->
}