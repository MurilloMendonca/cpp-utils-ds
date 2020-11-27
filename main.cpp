#include <iostream>
#include "Tree.hpp"


using namespace std;
int main()
{
    murillo::Tree<int> arvore;
    murillo::Tree<int> arvore2;
    //vector<int> valores  {3,5,7,1,8,2,4,6};
    vector<int> valores  {3,5,7,8,6,4,1,2};
 
    for(int x: valores)
        arvore.insert(x);
    valores.pop_back();
    for(int x: valores)
        arvore2.insert(x);

    arvore.mostra();
    arvore2.mostra();
    int aux =1;
    if(murillo::subarvore(arvore.first(),arvore2.first(), aux)) printf("Deu certo");
    else printf("Deu errado");

    




    return 0;
}
