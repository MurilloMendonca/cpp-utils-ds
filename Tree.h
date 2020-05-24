#ifndef TREE_CLASS
#define TREE_CLASS
#include<queue>
#include<tgmath.h>
#include <vector>
#include <stdio.h>
#include<iostream>

template <class U>
class Node
{
public:
    U data;
    Node *left, *right, *parent;
    int chave;

    Node();

    Node(U value, int key);

    ~Node();

    void operator= (const Node<U> &other);

    bool operator< (U &other);
};


template <class T>
class Tree
{
public:
    Tree();

    ~Tree();

    Node<T> *root;

    void insert(int key, T value);

    void dsw();
    int numeroDeNos();

    void buscaBinaria();

    void percursoEmLargura();

    int altura();

    void mostra ( int n);

    Node<T>* search(int key);

    bool pesquisa(int key, int &comp);

    bool pesquisa(int key);

    bool remove(int key);

    virtual bool operator< (Tree<T> &other);

    void operator= (Tree<T> &other);

    Node<T>*& first();

protected:

    void m_dsw(Node<T>* raiz);

    void m_buscaBinaria(Node<T>* raiz);

    void balancear ( std::vector<T > &tree1, int primeiro, int ultimo);

    void emOrdemVetor(Node<T>* raiz, std::vector <T> &vetor);


    void espinha(Node<T> ** tree);


    void rotDir(Node<T> **rootPtr);
    void montaDSW(Node<T> *rightVine);

    void compress(Node<T> **rootPtr, int times);
    void rotEsq(Node<T> **rootPtr);

    void _compress(Node<T> **rootPtr, int times);
    int getNumNodes(Node<T> *vine);

    void m_percursoEmLargura(Node<T>* inicio);

    void m_mostra ( Node<T>* a, int n);

    int m_altura(Node<T> *inicio);
    void m_equal(Node<T>* node, Node<T>* value);

    void m_destroy(Node<T>* value);
    void m_insert(Node<T> *&node, Node<T> *parent, T value, int key);
    void m_insert(Node<T> *&node, Node<T> *parent, Tree<T> &tree);

    Node<T>* m_search(Node<T> *node, int key);

    bool m_pesquisa(Node<T> *node, int key);

    bool m_remove(Node<T> *node, int key);
};



#endif //TREE_CLASS
