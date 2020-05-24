#ifndef TREE_CLASS
#define TREE_CLASS
#include <queue>
#include<tgmath.h>
#include<vector>
#include <stdio.h>
#include <time.h>
#include <windows.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
template <class T>
class Node
{
public:
    T data;
    Node *left, *right, *parent;
    int chave;

    Node()
    {
        left = right = parent = NULL;
    };

    Node(T value, int key)
    {
        data = value;
        chave = key;
    };

    ~Node()
    {
    };

    void operator= (const Node<T> &other)
    {
        chave = other.chave;
    };

    bool operator< (T &other)
    {
        return (data < other);
    };
};


template <class T>
class Tree
{
public:
    Tree()
    {
        root = NULL;
    };

    ~Tree()
    {
        m_destroy(root);
    };


    void insert(int key, T value)
    {
        m_insert(root,NULL,value, key);
    };

    void dsw()
    {
        m_dsw(this->root);
    }
    int numeroDeNos(){
        return getNumNodes(this->root);
    }

    void buscaBinaria()
    {
        m_buscaBinaria(this->root);
    }

    void percursoEmLargura()
    {
        m_percursoEmLargura(this->root);

    };

    int altura()
    {
        return m_altura(root) + 1;
    };

    void mostra ( int n)
    {
        m_mostra(root, n);
    };


    Node<T>* search(int key)
    {

        return m_search(root,key);
    };

    bool pesquisa(int key, double &tempo, int &comp)
    {
        comp =0;
        StartCounter();
        tempo = GetCounter();
        bool a= m_pesquisa(root,key,comp);
        tempo = GetCounter() - tempo;

        return a;
    };

    bool pesquisa(int key)
    {

        return m_pesquisa(root,key);


    };

    bool remove(int key)
    {
        return m_remove(root,key);
    };

    virtual bool operator< (Tree<T> &other)
    {
        return (root->data < other.first()->data);
    };

    void operator= (Tree<T> &other)
    {
        m_equal(root,other.first());
    };

    Node<T>*& first()
    {
        return root;
    };

    Node<T> *root;
protected:
    //this will be our root node and private functions

    void m_dsw(Node<T>* raiz)
    {
        raiz = root;
        espinha(&root);
        raiz = root;
        montaDSW(raiz);
    }

    void m_buscaBinaria(Node<T>* raiz)
    {
        std::vector<T> vetor;
        emOrdemVetor(raiz, vetor);
        int ultimo = vetor.size();


        root = NULL;
        balancear(vetor, 0, ultimo-1);


    }

    void balancear ( std::vector<T > &tree1, int primeiro, int ultimo)
    {
        if(primeiro <= ultimo)
        {
            int meio = (primeiro + ultimo)/2;
            insert(tree1[meio].chave, tree1[meio]);
            balancear(tree1, primeiro, meio-1);
            balancear(tree1, meio+1, ultimo);
        }
    }

    void emOrdemVetor(Node<T>* raiz, std::vector <T> &vetor)
    {
        if(raiz != NULL)
        {
            emOrdemVetor(raiz->left, vetor);
            vetor.push_back(raiz->data);
            emOrdemVetor(raiz->right, vetor);
        }
    }


    void espinha(Node<T> ** tree)
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


    void rotDir(Node<T> **rootPtr)
    {
        Node<T> *node1, *node2, *childNode;

        childNode = *rootPtr;
        node1 = childNode->left;
        node2 = childNode->left->right;
        node1->right = childNode;
        node1->right->left = node2;
        *rootPtr = node1;
    }
    void montaDSW(Node<T> *rightVine)
    {
        Node<T> *raiz = rightVine;
        int n = getNumNodes(raiz), m = pow(2, floor(log2(n+1)))- 1 ;

        compress( &raiz, n-m );

        while( m>1 )
        {
            m = floor( m/2 );
            compress( &raiz, m );
        }

        root = raiz;

    }

    void compress(Node<T> **rootPtr, int times)
    {
        int i;

        for(i=0; i<times; i++)
            _compress( &(*rootPtr), i );
    }
    void rotEsq(Node<T> **rootPtr)
    {
        Node<T> *node1, *node2, *childNode;

        childNode = *rootPtr;
        node1 = childNode->right;
        node2 = childNode->right->left;
        node1->left = childNode;
        node1->left->right = node2;
        *rootPtr = node1;
    }

    void _compress(Node<T> **rootPtr, int times)
    {

        if(times ==0)
            rotEsq(&(*rootPtr));
        else
            _compress( &((*rootPtr)->right), times-1);
    }
    int getNumNodes(Node<T> *vine)
    {
        int count =0;

        while( vine != NULL)
        {
            count ++;
            vine = vine->right;
        }

        return count;
    }

    void m_percursoEmLargura(Node<T>* inicio)
    {
        Node<T> *temp = NULL;
        std::queue < Node<T>* > auxFila;
        if(inicio != NULL)
        {
            auxFila.push(inicio);
            while(auxFila.empty() != true)
            {
                temp = auxFila.front();
                auxFila.pop();
                if(temp->left != NULL)
                    auxFila.push(temp->left);
                if(temp->right != NULL)
                    auxFila.push(temp->right);
                std::cout << temp->data<< std::endl;
            }
        }
    };

    void m_mostra ( Node<T>* a, int n)
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

    int m_altura(Node<T> *inicio)
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
    void m_equal(Node<T>* node, Node<T>* value)
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

    void m_destroy(Node<T>* value)
    {
        if(value != NULL)
        {
            m_destroy(value->left);
            m_destroy(value->right);
            delete value;
        }
    };
    void m_insert(Node<T> *&node, Node<T> *parent, T value, int key)
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
    void m_insert(Node<T> *&node, Node<T> *parent, Tree<T> &tree)
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

    Node<T>* m_search(Node<T> *node, int key)
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

    bool m_pesquisa(Node<T> *node, int key, int &comp)
    {
        comp++;
        if(node == NULL)
            return false;
        else if(key == node->chave)
            return true;
        else if(key < node->chave)
            return m_pesquisa(node->left,key, comp);
        else
            return m_pesquisa(node->right,key, comp);
    };

    bool m_remove(Node<T> *node, int key)
    {

        Node<T> *tmp = m_search(root,key);
        if(tmp == NULL)
            return false;
        Node<T> *parent = tmp->parent;
        //am i the left or right of the parent?
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
};


#endif //TREE_CLASS
