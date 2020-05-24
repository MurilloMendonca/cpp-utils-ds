#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include<iostream>

template<typename T>
class No
{
public:
    int chave;
    T Info;
    No * Lig;
};


template<class T>
class Lista
{
public:
    No<T>* L;

    Lista();

    void InsereLista (int chave, T Novo);

    /*bool RetiraLista ( Pessoa Novo);*/

    void ImprimeLista ();

    bool pesquisa(int chave);

};


#endif // LISTA_H_INCLUDED
