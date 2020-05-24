#ifndef VETORBL_H_INCLUDED
#define VETORBL_H_INCLUDED

template <class T>
class Nod
{
public:
    T data;
    int chave;

    Nod();

    Nod(T value, int key);

    ~Nod();

    void operator= (const Nod<T> &other);

    bool operator< (T &other);
};

template<class T>
class VetorBL{
public:
    int tam, ult;
    Nod<T> *vetor;

    VetorBL(int t);
    VetorBL();

    bool insere(int chave, T data);

    bool insere(Nod<T> no);

    bool pesquisa(int key);

    Nod<T> operator [](int i);

};


#endif // VETORBL_H_INCLUDED
