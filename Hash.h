#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<vector>
#include"Primo.h"
#include"Lista.h"
#include"VetorBL.h"
template<class U>
class HashLista
{
    public:
    int tam;
    Lista<U> *vetor;
    HashLista(int t);
    HashLista();

    void insere(int chave, U data);

    int avaliacao(int chave);

    void mostra();
    bool pesquisa(int chave);


};

template<class A>
class HashAberto
{
public:

    int tam;
    Nod<A> *vetor=NULL;
    HashAberto(int t);

    HashAberto();

    void zera();

    bool pesquisa(int chave);

    void insere(int chave, A data);

    int avaliacao(int chave);

    void mostra();
};





#endif // HASH_H_INCLUDED
