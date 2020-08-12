#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<vector>
#include"Lista.h"


/** \brief converte uma string em um inteiro
 *
 * \param string a ser convertido
 * \return soma dos valores de cada char da string
 *
 */
int string_to_int(std::string a)
{
    int soma=0, i=0;
    char aux = a[i];
    while(aux!='\n')
    {
        soma+=(int)aux;
        i++;
        aux =a[i];
    }
    return soma;

}


/** \brief HashLista<Chave,Valor> é uma implementação em Classe da estrutura de dados Hash.
 *  O tipo de dados do parâmetro template Chave está restrito aos tipos int e string.
 *  Já o tipo de dados do parâmetro template Valor é genérico.
 */
template<class T, class U>
class HashLista
{
    public:
    int tam;
    Lista<T, U> *vetor;
    HashLista(int t);

    HashLista();

    std::pair<bool, U> insere(T chave, U data);

    int avaliacao(std::string chave);
    int avaliacao(int chave);

    void mostra();
    bool retira(T chave);
    U* pesquisa(T chave);

};


/** \brief aloca a tabela de hash
 *
 * \param tamanho da tabela de hash
 *
 */
template<class T, class U>
HashLista<T, U>::HashLista(int t)
{
    tam=t;
    vetor = new Lista<T, U> [t];

}


/** \brief construtor vazio da HashList
 *
 */
template<class T, class U>
HashLista<T, U>::HashLista()
{

}


/** \brief insere um elemento e uma chave no hash
 *
 * \param Chave - permitido apenas string ou int
 * \param Data - qualquer tipo de objeto
 * \return pair(bool, data) - verdadeiro ou falso dependendo de se foi inserido no hash ou não, assim como o objeto que foi pedido a ser inserido
 *
 */
template<class T, class U>
std::pair<bool, U> HashLista<T, U>::insere(T chave, U data)
{
    int av;
    av = avaliacao(chave);
    return this->vetor[av].InsereLista(chave,data);


}


/** \brief caso a chave seja string, converte para inteiro e encontra a posição da chave no hash
 *
 * \param Chave - permitido apenas string
 * \return inteiro correspondente á posição no hash
 *
 */
template<class T, class U>
int HashLista<T, U>::avaliacao(std::string chave)
{
    int op;
    op = string_to_int(chave);
    int x =op % tam;
    return x;
}


/** \brief caso a chave seja int, encontra a posição da chave no hash
 *
 * \param Chave - permitido apenas int
 * \return inteiro correspondente á posição no hash
 *
 */
template<class T, class U>
int HashLista<T, U>::avaliacao(int chave)
{
    return chave % tam;
}


/** \brief imprime a tabela hash
 *
 */
template<class T, class U>
void HashLista<T, U>::mostra()
{
    for(int i=0; i<tam; i++)
    {
        No<T, U>* aux= vetor[i].L;
        while(aux!=NULL)
        {
            std::cout<<aux->chave<<" -> ";
            aux = aux->Lig;
        }
        std::cout<<"NULL"<<std::endl;

    }
}


/** \brief pesquisa uma chave na tabela hash
 *
 * \param Chave - chave do elemento a ser encontrado (permitido apenas string ou int)
 * \return endereço do valor
 *
 */
template<class T, class U>
U* HashLista<T, U>::pesquisa(T chave)
{
    return vetor[avaliacao(chave)].pesquisa(chave);
}


/** \brief Retira um elemento da hash
 *
 * \param Chave - chave do elemento a ser retirado (permitido apenas string ou int)
 * \return bool - verdadeiro ou falso, dependendo de se o elemento foi retirado ou não
 *
 */
template<class T, class U>
bool HashLista<T, U>::retira(T chave)
{

    int a = avaliacao(chave);
    return this->vetor[a].RetiraLista(chave);

}

#endif // HASH_H_INCLUDED
