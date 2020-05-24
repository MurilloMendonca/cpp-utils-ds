#include "Lista.h"

template<class T>
Lista<T>::Lista()
{
    L=NULL;
}
template<class T>
void Lista<T>::InsereLista (int chave, T Novo)
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
template<class T>
void Lista<T>::ImprimeLista ()
{
    No<T>* Ant = NULL;
    No<T>* Aux = L;
    std::cout << "L -> ";
    while ((Aux != NULL))
    {
        Ant = Aux;
        Aux = Aux->Lig;
        std::cout << Ant->chave<<" -> ";
    }
    if (Aux == NULL)
        std::cout << "NULL" << std::endl;
}
template<class T>
bool Lista<T>::pesquisa(int chave)
{
    No<T>* Ant = NULL;
    No<T>* Aux = L;
    while((Aux != NULL))  //ENCONTRA POSIÇÃO
    {
        if (Aux->chave == chave) return true;
        Ant = Aux;
        Aux = Aux->Lig;
    }
    return false;
}
