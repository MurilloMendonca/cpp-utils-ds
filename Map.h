#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <string>
#include <utility>
#include <typeinfo>
#include <vector>
#include<algorithm> //sort
#include"Hash.h"


/**
 *  INVALID_KEY é uma constante que armazena a mensagem de erro que será printada
 *  caso o usuário tente declarar um objeto Map com a chave de um tipo de dados
 *  inválido.
 */
const std::string CHAVE_INVALIDA = "\n!!A chave deve ser do tipo int ou string!!\n";

/** \brief Map<Chave,Valor> é uma implementação em Classe da estrutura de dados Mapa.
 *  O tipo de dados do parâmetro template Chave está restrito aos tipos int e string.
 *  Já o tipo de dados do parâmetro template Valor é genérico.
 */
template<class T, class U>
class Mapa
{

private:
    bool ATIVO=true; /**Atributo booleano destinado ao controle dos métodos. Tem seu valor mudado de true para false caso o tipo da chave seja incorreto  */

public:
    Mapa();
    std::pair<bool, U> inserir(T chave, U valor);
    HashLista<T, U>*lista;
    bool remove(T chave);
    U* busca(T chave);
    void mostra();
    U operator [](T i);

    /** \brief Classe interna de Iterador para o Map
     *
     */
    class Iterador
    {
    private:
        unsigned int cont;/** Variável inteira positiva para o controle de quantos "passos para frente" o iterador já deu. */
    public:
        U* inicio;/**Ponteiro para o endereço do primeiro valor da listaIterador*/
        U* atual;/**Ponteiro para o endereço de memória do valor atual do Iterador  */
        Lista<T,U*> listaIterador;/**Lista contendo todas as chaves inseridas no mapa e o endereço dos seus valores */
        /** \brief Construtor da classe Iterador.
        *   Durante sua construção todos as chaves contidas no mapa são transferidas para o atributo listaIterador
        * \param Map<T,U> mapa O mapa com o qual esta instância da Classe Iterador se relacionará.
        */
        Iterador(Mapa<T,U> n)
        {
            cont = 0;
            HashLista<T,U> m=*(n.lista);
            for(int i=0; i<m.tam; i++)
            {
                No<T, U>* Ant = NULL;
                No<T, U>* Aux = m.vetor[i].L;
                while ((Aux != NULL))
                {
                    Ant = Aux;
                    Aux = Aux->Lig;
                    listaIterador.InsereLista(Ant->chave, &(Ant->Info));
                }
            }
            atualizaIterador();
        }


        /** \brief Sobrecarga do operador ++(pela esquerda).
         *  Faz com que a instância de Iterador passe a retornar no seu atributo atual
         * o endereço do próximo Valor em ordem crescente de Chave.
         * \return Retorna o atributo atual atualizado
         */
         U* operator++(){
            cont++;
            atualizaIterador();
            return this->atual;
        }

        /** \brief Sobrecarga do operador ++(pela direita).
         *  Faz com que a instância de Iterador passe a retornar no seu atributo atual
         * o endereço do próximo Valor em ordem crescente de Chave.
         * \return Retorna o atributo atual atualizado
         */
        U* operator++(int){
            cont++;
            atualizaIterador();
            return this->atual;
        }

        /** \brief Atualiza o valor do atributo atual.
         *  Atualiza o valor do atributo atual para refletir corretamente numa listaIterador
         */
         void atualizaIterador(){
            inicio = (listaIterador.L->Info);
            No<T,U*>* aux = listaIterador.L;
            for(int i=0;i<cont;i++)
            {
                aux = aux->Lig;
            }
            atual = aux->Info;
        }
    };

    std::pair<bool, U> inserir(T chave, U valor, Iterador* it);
    bool remove(T chave, Iterador* it);
};

/** \brief Construtor da Classe Map.
 *  Durante o construtor é verificado se a Chave passada para o template
 *  apresenta um tipo válido para se iniciar o atributo lista, mudando
 *  o estado do atributo ENABLE e apresentando uma mensagem de erro caso contrário.
 */
template<class T, class U>
Mapa<T,U>::Mapa()
{
    if(typeid(T)==typeid(int)||typeid(T)==typeid(std::string))
    {
        lista = new HashLista<T,U>(107);
    }
    else
    {
        std::cout<<CHAVE_INVALIDA;
        ATIVO = false;
    }
}


/** \brief Insere um elemento com Chave e Valor no Mapa.
 *  Insere um elemento com Chave e Valor no Mapa caso já não
 *  exista essa chave no mapa.
 * \param   chave - Chave do elemento a ser inserido no Mapa.
 * \param   valor - Valor do elemento a ser inserido no Mapa.
 * \return  Um pair<bool, U> contendo true caso a inserção tenha ocorrido e false caso contrário,
 * e o valor relacionado a inserção.
 *
 */
template<class T, class U>
std::pair<bool, U>  Mapa<T,U>::inserir(T chave, U valor)
{
    if(ATIVO)
        return (this->busca(chave) == NULL)?this->lista->insere(chave, valor):(std::pair<bool,U>(false, valor));
}

/** \brief Remove um elemento pela Chave do Mapa.
 *  Remove um elemento com Chave=key do Mapa caso
 *  exista essa chave no mapa.
 * \param   chave - Chave do elemento a ser removido do Mapa.
 * \return  Um valor booleano contendo true caso a remoção tenha ocorrido e false caso contrário.
 *
 */
template<class T, class U>
bool Mapa<T,U>::remove(T chave)
{
    if(ATIVO)
      return  this->lista->retira(chave);
}

/** \brief Procura um elemento pela Chave do Mapa.
 *  Procura um elemento com Chave=chave do Mapa caso
 *  exista essa chave no mapa.
 * \param   chave - Chave do elemento a ser procurado do Mapa.
 * \return  Um ponteiro para o valor do elemento da Chave procurada.
 *
 */
template<class T, class U>
U* Mapa<T,U>::busca(T chave)
{
    if(ATIVO)
        return this->lista->pesquisa(chave);

}

/** \brief Mostra a tabela de hash deste mapa.
 */
template<class T, class U>
void Mapa<T,U>::mostra()
{
    if(ATIVO)
        this->lista->mostra();
}

/** \brief Sobrecarga do operador [].
 *  Pesquisa um elemento com chave igual ao valor passado entre [],
 *  caso não exista essa chave no mapa, cria com valor padrão.
 * \param   chave - Chave do elemento a ser pesquisado do Mapa.
 * \return  O valor do elemento da Chave procurada.
 *
 */
template<class T, class U>
U Mapa<T,U>::operator [](T chave)
{
    if(ATIVO)
    {
        U* b = this->busca(chave);
        if(b==NULL)
        {
            std::pair<bool, U> a = this->inserir(chave, U());
            return a.second;
        }
        return *b;
    }
};

/** \brief Sobrecarga da operação de inserção.
 *  Insere um elemento com Chave e Valor no Mapa caso já não
 *  exista essa chave no mapa e atualiza este valor também no Iterador it.
 * \param   chave - Chave do elemento a ser inserido no Mapa.
 * \param   valor - Valor do elemento a ser inserido no Mapa.
 * \param   it - Iterador de mapa para ser operado simultâneamente ao mapa.
 * \return  Um pair<bool, U> contendo true caso a inserção tenha ocorrido e false caso contrário,
 * e o valor relacionado a inserção.
 *
 */
template<class T, class U>
std::pair<bool, U> Mapa<T,U>::inserir(T chave, U valor, Iterador* it)
{
    std::pair<bool, U> a = this->inserir(chave, valor);
    it->listaIterador.InsereLista(chave, &a.second);
    it->atualizaIterador();
    return a;
}

/** \brief Sobrecarga da operação de remoção.
 *  Remove um elemento com Chave=key do Mapa caso
 *  exista essa chave no mapa e atualiza este valor também no Iterador it..
 * \param   chave - Chave do elemento a ser removido do Mapa.
 * \param   it - Iterador de mapa para ser operado simultâneamente ao mapa.
 * \return  Um valor booleano contendo true caso a remoção tenha ocorrido e false caso contrário.
 *
 */
template<class T, class U>
bool Mapa<T,U>::remove(T chave, Iterador* it){
    it->listaIterador.RetiraLista(chave);
    it->atualizaIterador();
    return this->remove(chave);
}

#endif // MAP_H_INCLUDED
