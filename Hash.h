#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<vector>
#include"Primo.h"
#include"Lista.h"
#include"VetorBL.h"
template<class T>
class HashLista
{
    public:
    int tam;
    Lista<T> *vetor;
    HashLista(int t)
    {
        tam = primoMaisPerto(t);
        vetor = new Lista<T> [tam];

    }
    HashLista()
    {

    }

    void insere(int chave, T data)
    {
        int av;
        av = avaliacao(chave);
        this->vetor[av].InsereLista(chave,data);

    }

    int avaliacao(int chave)
    {
        return chave % tam;
    }

    void mostra()
    {
        for(int i=0;i<tam;i++){
            No<T>* aux= vetor[i].L;
            while(aux!=NULL){
                std::cout<<aux->chave<<" -> ";
                aux = aux->Lig;
            }
            std::cout<<"NULL"<<std::endl;

        }
    }
    bool pesquisa(int chave){
        return vetor[avaliacao(chave)].pesquisa(chave);
    }


};

template<class T>
class HashAberto
{
public:

    int tam;
    Nod<T> *vetor=NULL;
    HashAberto(int t)
    {
        tam = primoMaisPerto(2*t);
        vetor = new  Nod<T> [tam];
        zera();
    }

    HashAberto()
    {

    }

    void zera()
    {
        for(int i=0; i<tam; i++)
            this->vetor[i] = Nod<T>();

    }

    bool pesquisa(int chave)
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


    void insere(int chave, T data)
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

    int avaliacao(int chave)
    {
        return chave % tam;
    }

    void mostra(){
        for(int i=0;i<tam;i++)
        std::cout<<std::endl<<vetor[i].chave;
    }
};





#endif // HASH_H_INCLUDED
