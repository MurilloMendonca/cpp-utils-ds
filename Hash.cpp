#include "Hash.h"
template<class T>
HashLista<T>::HashLista(int t)
{
    tam = primoMaisPerto(t);
    vetor = new Lista<T> [tam];

}
template<class T>
HashLista<T>::HashLista()
{

}
template<class T>
void HashLista<T>::insere(int chave, T data)
{
    int av;
    av = avaliacao(chave);
    this->vetor[av].InsereLista(chave,data);

}
template<class T>
int HashLista<T>::avaliacao(int chave)
{
    return chave % tam;
}
template<class T>
void HashLista<T>::mostra()
{
    for(int i=0; i<tam; i++)
    {
        No<T>* aux= vetor[i].L;
        while(aux!=NULL)
        {
            std::cout<<aux->chave<<" -> ";
            aux = aux->Lig;
        }
        std::cout<<"NULL"<<std::endl;

    }
}
template<class T>
bool HashLista<T>::pesquisa(int chave)
{
    return vetor[avaliacao(chave)].pesquisa(chave);
}


template<class T>
HashAberto<T>::HashAberto(int t)
{
    tam = primoMaisPerto(2*t);
    vetor = new  Nod<T> [tam];
    zera();
}
template<class T>
HashAberto<T>::HashAberto()
{

}
template<class T>
void HashAberto<T>::zera()
{
    for(int i=0; i<tam; i++)
        this->vetor[i] = Nod<T>();

}
template<class T>
bool HashAberto<T>::pesquisa(int chave)
{
    int av =avaliacao(chave);
    while(true)
    {
        if(this->vetor[av].chave==chave)
        {
            return true;
        }
        else if(this->vetor[av].chave==-1)
        {
            return false;
        }
        av = (av+1)%tam;
    }
}

template<class T>
void HashAberto<T>::insere(int chave, T data)
{
    int av =avaliacao(chave);
    Nod<T> stand(data, -1);
    while(true)
    {
        if(this->vetor[av].chave==stand.chave)
        {
            this->vetor[av] = Nod<T>(data, chave);
            return;
        }
        av = (av+1)%tam;
    }
}
template<class T>
int HashAberto<T>::avaliacao(int chave)
{
    return chave % tam;
}
template<class A>
void HashAberto<A>::mostra()
{
    for(int i=0; i<tam; i++)
        std::cout<<std::endl<<vetor[i].chave;
}
