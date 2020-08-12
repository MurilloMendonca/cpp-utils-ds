#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include<iostream>
#include <unordered_map>

template<class T, class U>
class No
{
public:
    T chave;
    U Info;
    No * Lig;
};

/** \brief Lista<Chave,Valor> é uma implementação em Classe da estrutura de dados Lista.
 *  O tipo de dados do parâmetro template Chave está restrito aos tipos int e string.
 *  Já o tipo de dados do parâmetro template Valor é genérico.
 */
template<class T, class U>
class Lista
{
public:
    No<T, U>* L;/**< Raiz da lista */
    Lista();
    std::pair<bool, U> InsereLista (T chave, U valor);
    bool RetiraLista (T chave);
    void ImprimeLista ();
    U* pesquisa(T chave);
};


template<class T, class U>
Lista<T, U>::Lista()
{
    L=NULL;
}


/** \brief Insere um elemento na Lista
 *
 * \param Chave - permitido apenas string ou int
 * \param Valor - elemento a ser inserido na lista
 * \return pair(bool, valor) - verdadeiro ou falso dependendo de se foi inserido na lista ou não, assim como o elemento que foi pedido a ser inserido
 *
 */
template<class T, class U>
std::pair<bool, U> Lista<T, U>::InsereLista (T chave, U valor)
{
    if (L == NULL)    // INSERÇÃO DO PRIMEIRO NÓ
    {
        L = new No<T, U>;
        L->Info = valor;
        L->Lig = NULL;
        L->chave = chave;
    }
    else                    // AJUSTA PONTEIROS ANT E AUX
    {
        No<T, U>* Ant = NULL;
        No<T, U>* Aux = L;
        while((Aux != NULL)&&(Aux->chave<chave))  //ENCONTRA POSIÇÃO
        {
            Ant = Aux;
            Aux = Aux->Lig;
        }
        Aux = new No<T, U>;
        Aux->Info = valor;
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
    return std::pair<bool, U>(true, valor);
}


/** \brief Retira um elemento da lista
 *
 * \param Chave - chave do elemento a ser retirado (permitido apenas string ou int)
 * \return bool - verdadeiro ou falso, dependendo de se o elemento foi retirado ou não
 *
 */
template<class T, class U>
bool Lista<T, U>::RetiraLista (T chave)
{
    if (L == NULL)
        return false;

    else
    {
        No<T, U>* Ant = NULL;
        No<T, U>* Aux = L;

        while((Aux != NULL) && (Aux->chave != chave))
        {
            Ant = Aux;
            Aux = Aux->Lig;
        }
        if(Aux == NULL)
            return false;

        if(Aux->chave == chave)
        {
            if(Ant == NULL)
            {
                L = Aux->Lig;
                delete Aux;
                return true;
            }
            Ant->Lig = Aux->Lig;
            delete Aux;
            return true;
        }

        else
            return false;
    }
}


/** \brief Imprime elementos da lista
 *
 */
template<class T, class U>
void Lista<T, U>::ImprimeLista ()
{
    No<T, U>* Ant = NULL;
    No<T, U>* Aux = L;
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


/** \brief pesquisa uma chave na lista
 *
 * \param Chave - chave do elemento a ser encontrado (permitido apenas string ou int)
 * \return endereço do valor
 *
 */
template<class T, class U>
U* Lista<T, U>::pesquisa(T chave)
{
    No<T,U>* Ant = NULL;
    No<T, U>* Aux = L;
    while((Aux != NULL)&&(Aux->chave<=chave))  //ENCONTRA POSIÇÃO
    {
        if (Aux->chave == chave) return &(Aux->Info);
        Ant = Aux;
        Aux = Aux->Lig;
    }
    return NULL;
}


#endif // LISTA_H_INCLUDED
