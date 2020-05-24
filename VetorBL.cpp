#include"VetorBL.h"
template<class T>
Nod<T>::Nod()
{
    chave = -1;
};

template<class T>
Nod<T>::Nod(T value, int key)
{
    data = value;
    chave = key;
};

template<class T>
Nod<T>::~Nod()
{
};

template<class T>
void Nod<T>::operator= (const Nod<T> &other)
{
    chave = other.chave;
};

template<class T>
bool Nod<T>::operator< (T &other)
{
    return (data < other);
};

template<class T>
VetorBL<T>::VetorBL(int t)
{
    tam = t;
    ult = 0;
    vetor = new Nod<T>[tam];
}

template<class T>
VetorBL<T>::VetorBL()
{

}

template<class T>
bool VetorBL<T>::insere(int chave, T data)
{
    if (ult<tam)
    {
        vetor[ult] = Nod<T> (data, chave);
        ult++;
        return true;
    }
    return false;

}

template<class T>
bool VetorBL<T>::insere(Nod<T> no)
{
    if (ult<tam)
    {
        vetor[ult] = no;
        ult++;
        return true;
    }
    return false;
}

template<class T>
bool VetorBL<T>::pesquisa(int key)
{
    for(int i=0; i<ult; i++)
    {
        if(key == vetor[i].chave)
        {
            return true;
        }
    }
    return false;
}

template<class T>
Nod<T> VetorBL<T>::operator [](int i)
{
    return (i<ult)?vetor[i]:Nod<T>();
};
