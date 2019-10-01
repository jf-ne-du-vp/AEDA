#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : numMaximoClientes(nMaxCli) , lotacao(lot)
{
    /*
    lotacao = lot;                          not permitted because they are const
    numMaximoClientes = numMaximoClientes;
     */
    vagas = lot;
    clientes.clear();  //to be sure that clients vector is initialized with 0 clients
}

unsigned int ParqueEstacionamento::getNumLugares() const
{
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
    return numMaximoClientes;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome)
{
    if(clientes.size() < numMaximoClientes && posicaoCliente(nome) == -1 ) {
        InfoCartao novoCliente;
        novoCliente.nome = nome;
        novoCliente.presente = false;

        clientes.push_back(novoCliente);

        return true;
    }
    return false;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    //int posClient = -1; not necessary to create variable,  if return i or -1
    size_t sizeVecClient = clientes.size();

    for (size_t i = 0; i < sizeVecClient; i++)
    {
        if (nome == clientes[i].nome)
            return i;
    }

    return -1;
}

bool ParqueEstacionamento::entrar(const string &nome) {

    if(vagas == 0 || posicaoCliente(nome) == -1 || clientes[posicaoCliente(nome)].presente == true ) {
        //clientes[posicaoCliente(nome)].presente = true;
        return false;
    }
    clientes[posicaoCliente(nome)].presente = true;
    vagas--;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
    if(clientes[posicaoCliente(nome)].presente == false && posicaoCliente(nome) !=-1)
    {
        clientes.erase(clientes.begin() + posicaoCliente(nome));
        return true;
    }

    return false;
}

bool ParqueEstacionamento::sair(const string & nome)
{
    if(clientes[posicaoCliente(nome)].presente == true && posicaoCliente(nome) != -1) {
        clientes[posicaoCliente(nome)].presente = false;
        vagas++;
        return true;
    }

    return false;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
    return lotacao - vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{
    return clientes.size();
}




