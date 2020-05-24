#ifndef VETORBL_H_INCLUDED
#define VETORBL_H_INCLUDED
#include <windows.h>
#include "Tree.h"




template <class T>
class Nod
{
public:
    T data;
    int chave;

    Nod()
    {
        chave = -1;
    };

    Nod(T value, int key)
    {
        data = value;
        chave = key;
    };

    ~Nod()
    {
    };

    void operator= (const Nod<T> &other)
    {
        chave = other.chave;
    };

    bool operator< (T &other)
    {
        return (data < other);
    };
};

template<class T>
class VetorBL{
public:
    int tam, ult;
    Nod<T> *vetor;

    VetorBL(int t){
        tam = t;
        ult = 0;
        vetor = new Nod<T>[tam];
    }
    VetorBL(){

    }

    bool insere(int chave, T data)
    {
        if (ult<tam){
            vetor[ult] = Nod<T> (data, chave);
            ult++;
            return true;
        }
        return false;

    }

    bool insere(Nod<T> no){
        if (ult<tam){
            vetor[ult] = no;
            ult++;
            return true;
        }
        return false;
    }

    bool pesquisa(int key, double &tempo, int &comp)
    {
        comp=0;
        StartCounter();
        tempo = GetCounter();
        for(int i=0;i<ult;i++){
            comp++;
            if(key == vetor[i].chave) {
                tempo = GetCounter() - tempo;
                return true;
            }
        }
        tempo = GetCounter() - tempo;
        return false;
    }

    Nod<T> operator [](int i){
        return (i<ult)?vetor[i]:Nod<T>();
    }


};


#endif // VETORBL_H_INCLUDED
