#include <iostream>

#include "Map.h"

using namespace std;
class Carro{
    public:
    int numero_serie;
    string modelo;
    void mostraCarro(){
            cout<<"\nNumero de Serie: "<<this->numero_serie<<"\nModelo: "<<this->modelo;
    }
    Carro(int a, string b){
        this->numero_serie=a;
        this->modelo=b;
    }
    Carro(){
    };
};

void testes(){

    //Objetos Carro's
    Carro carro1(1234, "ferrari");
    Carro carro2(4321, "ford ka");
    Carro carro3(7896, "mustang");

    //Objeto Mapa com chave int
    Mapa<int,Carro> map;    //instanciando

    map.inserir(1, carro1); //inserção
    map.inserir(3, carro3);
    map.inserir(2, carro2);

    //map.mostra();           //Vai mostrar a tabela hash, vai ficar bem grande

    map[3].mostraCarro();   //Sobrecarga do operador []

    cout<<"\nEndereco do elemento 3: "<<map.busca(3); //Metodo busca

    map.remove(1);          //remoção

    //map.mostra();           //mostrar que apagou

    Mapa<int, Carro>::Iterador it(map);    //instanciando e construindo Iterador

    cout<<"\nIterador.inicio: ";
    (*it.inicio).mostraCarro();    //Inicio do iterador

    it++;//ou ++it                   //Sobrecarga do operador ++

    cout<<"\nIterador.atual: ";
    (*it.atual).mostraCarro();  //Atual após um ++

    map.inserir(1, carro1, &it);            //Inserção atualizando o iterador

    cout<<"\nIterador.atual: ";
    (*it.atual).mostraCarro();  //Atual após uma inserção
}
int main()
{
    testes();


    return 0;
}
