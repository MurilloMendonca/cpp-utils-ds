#include<queue>
#include<tgmath.h>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
namespace murillo{
template <typename U>
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
    bool operator< (Node &other);
    bool operator!= (Node &other);
};

template <typename U>
Node<U>::Node()
{
    left = right = parent = NULL;
};

template <typename U>
Node<U>::Node(U value, int key)
{
    data = value;
    chave = key;
};

template <class U>
Node<U>::~Node()
{

};

template <class U>
void Node<U>::operator= (const Node<U> &other)
{
    chave = other.chave;
};

template <typename T>
bool Node<T>::operator< (T &other)
{
    return (data < other);
};

template <typename T>
bool Node<T>::operator< (Node<T> &other)
{
    return (chave < other.chave);
};
template <typename T>
bool Node<T>::operator!= (Node<T> &other)
{
    return (chave != other.chave);
};

template <typename T>
class Tree
{
public:
    Tree();
    ~Tree();
    void insert(int key, T value);
    void insert(int key);
    void substitui(int key, Node<T> novo);
    void dsw();
    int numeroDeNos();
    void percorreIterativo();
    void percorrePos();
    void buscaBinaria();
    void percursoEmLargura();
    int altura();
    void mostra (int n=0);
    Node<T>* search(int key);
    bool pesquisa(int key);
    int nivel(int key);
    bool remove(int key);
    virtual bool operator< (Tree<T> &other);
    void operator= (Tree<T> &other);
    bool operator== (Tree<T> &other);
    Node<T>*& first();

protected:
    Node<T> *root;
    void m_dsw(Node<T>* raiz);
    void m_buscaBinaria(Node<T>* raiz);
    void balancear (std::vector<T > &tree1, int primeiro, int ultimo);
    void emOrdemVetor(Node<T>* raiz, std::vector <T> &vetor);
    void m_mostra_iter(Node<T>*inicio);
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
    int m_nivel(Node<T> *node, int key, int& nivel);
    void m_substitui(Node<T>*& root, int key, Node<T> novo);
    bool compara(Node<T>* node, Node<T>* value);
    void m_percorrePos(Node<T>* root);
};

template <typename T>
Tree<T>::Tree()
{
    root = NULL;
};

template <typename T>
void Tree<T>::percorreIterativo(){
    this->m_mostra_iter(this->root);
}
template <typename T>
Tree<T>::~Tree()
{
    m_destroy(root);
};

template <typename T>
void Tree<T>::insert(int key){
    T aux;
    this->insert(key, aux);
}

template<typename T>
int Tree<T>::nivel(int key){
    int nivel=0;
    return m_nivel(root, key, nivel);
}
template <typename T>
void Tree<T>::insert(int key, T value)
{
    m_insert(root,NULL,value, key);
};

template <typename T>
void Tree<T>::dsw()
{
    m_dsw(this->root);
}

template <typename T>
void Tree<T>::substitui(int key, Node<T> novo){
    m_substitui(root, key, novo);
}

template <typename T>
int Tree<T>::numeroDeNos()
{
    return getNumNodes(this->root);
}

template <typename T>
void Tree<T>::buscaBinaria()
{
    m_buscaBinaria(this->root);
}

template <typename T>
void Tree<T>::percorrePos(){
    m_percorrePos(root);
}

template <typename T>
void Tree<T>::percursoEmLargura()
{
    m_percursoEmLargura(this->root);

};

template <typename T>
int Tree<T>::altura()
{
    return m_altura(root) + 1;
};

template <typename T>
void Tree<T>::mostra ( int n)
{
    m_mostra(root, n);
};

template <typename T>
Node<T>* Tree<T>::search(int key)
{
    return m_search(root,key);
};

template <typename T>
bool Tree<T>::pesquisa(int key)
{
    return m_pesquisa(root,key);
};

template <typename T>
bool Tree<T>::remove(int key)
{
    return m_remove(root,key);
};

template <typename T>
bool Tree<T>::operator< (Tree<T> &other)
{
    return (root->data < other.first()->data);
};

template <typename T>
void Tree<T>::operator= (Tree<T> &other)
{
    m_equal(root,other.first());
};

template <typename T>
bool Tree<T>::operator== (Tree<T> &other)
{
    Node<T>* aux;
    std::vector<Node<T>> arvore1;
    std::vector<Node<T>> arvore2;
    std::stack<Node<T>*> pilha;
    if(root != NULL)
    {
        pilha.push(root);

        while(!pilha.empty())
        {
          aux = pilha.top();
         pilha.pop();
          arvore1.push_back(*aux);
          if(aux->right) pilha.push(aux->right);
          if(aux->left) pilha.push(aux->left);
        }
    }
    if(other.first() != NULL)
    {
        pilha.push(other.first());

        while(!pilha.empty())
        {
          aux = pilha.top();
         pilha.pop();
          arvore2.push_back(*aux);
          if(aux->right) pilha.push(aux->right);
          if(aux->left) pilha.push(aux->left);
        }
    }
    std::sort(arvore1.begin(), arvore1.end());
    std::sort(arvore2.begin(), arvore2.end());
    for(int i=0;i<arvore1.size();i++)
    {
        if(arvore1.at(i) != arvore2.at(i))
            return false;
    }
    return true;

};

template <typename T>
Node<T>*& Tree<T>::first()
{
    return root;
};

template <typename T>
void Tree<T>::m_dsw(Node<T>* raiz)
{
    raiz = root;
    espinha(&root);
    raiz = root;
    montaDSW(raiz);
}

template <typename T>
void Tree<T>::m_buscaBinaria(Node<T>* raiz)
{
    std::vector<T> vetor;
    emOrdemVetor(raiz, vetor);
    int ultimo = vetor.size();
    root = NULL;
    balancear(vetor, 0, ultimo-1);
}

template <typename T>
void Tree<T>::balancear ( std::vector<T > &tree1, int primeiro, int ultimo)
{
    if(primeiro <= ultimo)
    {
        int meio = (primeiro + ultimo)/2;
        insert(tree1[meio].chave, tree1[meio]);
        balancear(tree1, primeiro, meio-1);
        balancear(tree1, meio+1, ultimo);
    }
}

template <typename T>
void Tree<T>::emOrdemVetor(Node<T>* raiz, std::vector <T> &vetor)
{
    if(raiz != NULL)
    {
        emOrdemVetor(raiz->left, vetor);
        vetor.push_back(raiz->data);
        emOrdemVetor(raiz->right, vetor);
    }
}

template <typename T>
void Tree<T>::espinha(Node<T> ** tree)
{

    Node<T> *r = *tree;

    if(r == NULL)
        return;

    while(r->left !=NULL)
    {
        rotDir(&r);
    }

    if(r->right != NULL)
    {
        espinha(&(r->right));
    }

    *tree = r;
}

template <typename T>
void Tree<T>::rotDir(Node<T> **rootPtr)
{
    Node<T> *node1, *node2, *childNode;

    childNode = *rootPtr;
    node1 = childNode->left;
    node2 = childNode->left->right;
    node1->right = childNode;
    node1->right->left = node2;
    *rootPtr = node1;
}

template <typename T>
void Tree<T>::montaDSW(Node<T> *rightVine)
{
    Node<T> *raiz = rightVine;
    int n = getNumNodes(raiz);
    int m = (pow(2, floor(log2(n+1)))- 1) ;

    compress( &raiz, n-m );

    while( m>1 )
    {
        m = floor( m/2 );
        compress( &raiz, m );
    }

    root = raiz;

}

template <typename T>
void Tree<T>::compress(Node<T> **rootPtr, int times)
{
    int i;
    for(i=0; i<times; i++)
        _compress( &(*rootPtr), i );
}

template <typename T>
void Tree<T>::rotEsq(Node<T> **rootPtr)
{
    Node<T> *node1, *node2, *childNode;

    childNode = *rootPtr;
    node1 = childNode->right;
    node2 = childNode->right->left;
    node1->left = childNode;
    node1->left->right = node2;
    *rootPtr = node1;
}

template <typename T>
void Tree<T>::_compress(Node<T> **rootPtr, int times)
{

    if(times ==0)
        rotEsq(&(*rootPtr));
    else
        _compress( &((*rootPtr)->right), times-1);
}

template <typename T>
int Tree<T>::getNumNodes(Node<T> *vine)
{
    int count =0;

    while( vine != NULL)
    {
        count ++;
        vine = vine->right;
    }

    return count;
}

template <typename T>
void Tree<T>::m_percursoEmLargura(Node<T>* inicio)
{
    Node<T> *temp = NULL;
    std::queue < Node<T>* > auxFila;
    if(inicio != NULL)
    {
        auxFila.push(inicio);
        while(!auxFila.empty())
        {
            temp = auxFila.front();
            auxFila.pop();
            if(temp->left ) auxFila.push(temp->left);
            if(temp->right) auxFila.push(temp->right);
            std::cout << temp->chave<< std::endl;
        }
    }
};

template <typename T>
void Tree<T>::m_mostra ( Node<T>* a, int n)
{
    if (a)
    {
        int i;
        m_mostra (a->right, n+1);
        for (i = 0; i < n; i++)
            std::cout << "    ";
        std::cout << a->chave << std::endl;
        m_mostra (a->left, n+1);
    }
};

template <typename T>
void Tree<T>::m_mostra_iter ( Node<T>* inicio)
{
    Node<T>* aux;
    std::stack<Node<T>*> pilha;
    if(inicio != NULL)
    {
        pilha.push(inicio);

        while(!pilha.empty())
        {
          aux = pilha.top();
         pilha.pop();
          std::cout<<aux->chave;
          if(aux->right) pilha.push(aux->right);
          if(aux->left) pilha.push(aux->left);
        }
    }
};

template <typename T>
int Tree<T>::m_altura(Node<T> *inicio)
{
    if (!inicio)
        return -1;
    else
    {
        int alturaesquerda, alturadireita;
        alturaesquerda = m_altura (inicio->left);
        alturadireita  = m_altura (inicio->right);

        if (alturaesquerda < alturadireita)
            return alturadireita + 1;
        else
            return alturaesquerda + 1;
    }
};

template <typename T>
void Tree<T>::m_equal(Node<T>* node, Node<T>* value)
{
    if(value != NULL)
    {
        node = new Node<T>();
        *node = *value;
        if(value->left != NULL)
            m_equal(node->left, value->left);
        if(value->right != NULL)
            m_equal(node->right, value->right);
    }
}

template <typename T>
void Tree<T>::m_destroy(Node<T>* value)
{
    if(value != NULL)
    {
        m_destroy(value->left);
        m_destroy(value->right);
        delete value;
    }
};

template <typename T>
void Tree<T>::m_insert(Node<T> *&node, Node<T> *parent, T value, int key)
{
    if(node == NULL)
    {
        node = new Node<T>();
        node->data= value;
        node->chave = key;
        node->parent = parent;
    }
    else if(key < node->chave)
    {
        m_insert(node->left,node,value, key);
    }
    else
        m_insert(node->right,node,value, key);
};

template <typename T>
void Tree<T>::m_insert(Node<T> *&node, Node<T> *parent, Tree<T> &tree)
{
    Node<T> *value = tree.first();
    if(node == NULL)
    {
        node = new Node<T>();
        *node = *value;
        node->parent = parent;
    }
    else if(value->chave < node->chave)
    {
        m_insert(node->left,tree);
    }
    else
        m_insert(node->right,tree);
};

template <typename T>
Node<T>* Tree<T>::m_search(Node<T> *node, int key)
{
    if(node == NULL)
        return NULL;
    else if(key == node->chave)
        return node;
    else if(key < node->chave)
        return m_search(node->left,key);
    else
        return m_search(node->right,key);
};

template <typename T>
bool Tree<T>::m_pesquisa(Node<T> *node, int key)
{
    if(node == NULL)
        return false;
    else if(key == node->chave)
        return true;
    else if(key < node->chave)
        return m_pesquisa(node->left,key);
    else
        return m_pesquisa(node->right,key);
};

template <typename T>
bool Tree<T>::m_remove(Node<T> *node, int key)
{

    Node<T> *tmp = m_search(root,key);
    if(tmp == NULL)
        return false;
    Node<T> *parent = tmp->parent;
    bool iamleft = false;
    if(parent->left == tmp)
        iamleft = true;
    if(tmp->left != NULL && tmp->right != NULL)
    {
        if(parent->left == NULL || parent->right == NULL)
        {
            parent->left = tmp->left;
            parent->right = tmp->right;
        }
        else
        {
            if(iamleft)
                parent->left = tmp->left;
            else
                parent->right = tmp->left;
            key = tmp->right->chave;
            T data = tmp->right->data;
            delete tmp;
            m_insert(root,NULL,data,key);
        }
    }
    else if(tmp->left != NULL)
    {
        if(iamleft)
            parent->left = tmp->left;
        else
            parent->right = tmp->left;
    }
    else if(tmp->right != NULL )
    {
        if(iamleft)
            parent->left = tmp->right;
        else
            parent->right = tmp->right;
    }
    else
    {
        if(iamleft)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    return true;
};

template <typename T>
int Tree<T>::m_nivel(Node<T> *node, int key, int& nivel)
{
    if(node == NULL)
        return -1;
    else if(key == node->chave)
        return nivel;
    nivel++;
    if(key < node->chave)
        return m_nivel(node->left,key, nivel);
    else
        return m_nivel(node->right,key, nivel);
};

template <typename T>
void Tree<T>::m_substitui(Node<T>*& root, int key, Node<T> novo)
{
    if(root == NULL)
        return;

    if(key == root->chave)
    {
        root->chave = novo.chave;
        root->data = novo.data;
    }
        
    m_substitui(root->left,key, novo);
    m_substitui(root->right,key, novo);
}

template <typename T>
void Tree<T>::m_percorrePos(Node<T>* root){
    if(root==NULL)
        return;
    m_percorrePos(root->left);
    m_percorrePos(root->right);
    std::cout<<root->chave;
}

template <typename T>
bool subarvore(Node<T>* A,Node<T>* B, int& flag){
    if(A==NULL || B==NULL) return false;
    if(flag==0)
    {
        if(A->chave==B->chave)
        {
            subarvore(A->left, B->left, flag);
            subarvore(A->right, B->right, flag);
        }
    }
    else{
        if(A->chave==B->chave)
        {
            flag =0;
            subarvore(A, B, flag);
        }
        else{
            flag =1;
            subarvore(A->left, B->left, flag);
            subarvore(A->right, B->right, flag);
        }
    }
    if(flag==0) return true;
    else return false;

}


}

