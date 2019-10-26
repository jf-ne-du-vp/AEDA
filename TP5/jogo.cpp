/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

Jogo::Jogo() = default;

Jogo::Jogo(list<Crianca>& lc2)
{
    criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
    criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res;

    /*for(auto crianca:criancas)            not necessary because there is operator =
        res.push_back(crianca);*/
    res = criancas;

    return res;
}

string Jogo::escreve() const
{
    string res;

    for(auto crianca:criancas) {
        res += crianca.escreve();
        res += "\n";
    }

    return res;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)      //whene need to stay with one child!!
{
    //Crianca *c1 = new Crianca();          //dont need this
    unsigned int num_pal = numPalavras(frase);
    unsigned int saved;



    while(criancas.size() >1 ){
        list<Crianca>::iterator it=criancas.begin();
        saved = (num_pal -1)%criancas.size();       //index of child to be erased from list
        advance(it,saved);                      //returns iterator to position to be erased
        criancas.erase(it);                         //erase child pointed by the iterator
    }

    //return *c1;
    return *criancas.begin();
}


list<Crianca>& Jogo::inverte()          //there is the function reverse, but lets try to do it, criancas.reverse();
{
    list<Crianca> inverted;

    list<Crianca>::iterator it = criancas.end();

    while(it != criancas.begin()){
        it--;       //need to put because end it is not the index of last list element
        inverted.push_back(*it);
    }

    criancas = inverted;

    return criancas;
}


list<Crianca> Jogo::divide(unsigned id)         //when we use erase it is returned an iterator to the next position, so we need to reduce it by one position
{
    list<Crianca> res;

    for(auto c:criancas){
        if(c.getIdade() > id) {
            res.push_back(c);
            criancas.remove(c);             //with remove we dont have the iterator problem
        }
    }
    return res;
}


void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    list<Crianca>::const_iterator it = l1.begin();          //it is const because i am not changing the content of l1.
    while(it!= l1.end()){
        criancas.push_back(*it);
        it++;           //never forget to increment the iterator!!!!!!!!
    }

    //criancas = l1;
}

bool Jogo::operator==(Jogo& j2)
{
    if(criancas.size() != j2.criancas.size())
        return false;

    size_t tam = j2.criancas.size();
    auto it1 = criancas.begin();
    auto it2 = j2.criancas.begin();

    while(tam > 0){
        if(!(*it1 == *it2))
            return false;
        tam--;
        it1++;          //almost forgot to increment iterators
        it2++;
    }

	return true;
}

list<Crianca> Jogo::baralha() const         //dont forget to use advance
{
    list<Crianca> res, intermedia = criancas;
    int rand_index;

    while(intermedia.size() > 0){
        //srand(time(nullptr));
        rand_index = rand() % intermedia.size(); //(-1)  dont need to do this because of operator %
        auto it = intermedia.begin();
        advance(it,rand_index);
        res.push_back(*it);
        intermedia.erase(it);       //can use erase and not worry
    }

    return res;
}
