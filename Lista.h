#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include<iostream>
#include"Pessoa.h"

using namespace std;

template<class T>
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

    Lista()
    {
        L=NULL;
    }

    void InsereLista (int chave, T Novo)
    {
        if (L == NULL)    // INSERÇÃO DO PRIMEIRO NÓ
        {
            L = new No<T>;
            L->Info = Novo;
            L->Lig = NULL;
            L->chave = chave;
        }
        else                    // AJUSTA PONTEIROS ANT E AUX
        {
            No<T>* Ant = NULL;
            No<T>* Aux = L;
            while((Aux != NULL))  //ENCONTRA POSIÇÃO
            {
                Ant = Aux;
                Aux = Aux->Lig;
            }
            Aux = new No<T>;
            Aux->Info = Novo;
            Aux->chave = chave;
            if (Ant == NULL)
            {
                Aux->Lig = L;
                L = Aux;
            }
            else
            {
                Aux->Lig = Ant->Lig;
                Ant->Lig = Aux;
            }
        }
    }




    /*bool RetiraLista ( Pessoa Novo)
    {
        No* Ant = NULL;
        No* Aux = L;
        while ((Aux != NULL) && (Aux->Info != Novo))
        {
            Ant = Aux;
            Aux = Aux->Lig;
        }
        if (Aux == NULL)
            return false;
        if (Aux == L)
            L = L->Lig;
        else
            Ant->Lig = Aux->Lig;
        delete Aux;
        return true;
    }*/

    void ImprimeLista ()
    {
        No<T>* Ant = NULL;
        No<T>* Aux = L;
        cout << "L -> ";
        while ((Aux != NULL))
        {
            Ant = Aux;
            Aux = Aux->Lig;
            cout << Ant->chave<<" -> ";
        }
        if (Aux == NULL)
            cout << "NULL" << endl;
    }

    bool pesquisa(int chave, int &comp)
    {
        No<T>* Ant = NULL;
        No<T>* Aux = L;
        while((Aux != NULL))  //ENCONTRA POSIÇÃO
            {
                comp++;
                if (Aux->chave == chave) return true;
                Ant = Aux;
                Aux = Aux->Lig;
            }
        return false;
    }

};


#endif // LISTA_H_INCLUDED
