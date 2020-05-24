#include "Primo.h"
bool isPrimo(int n)
{
    for(int i=2; i<n; i++)
        if(n%i==0)
            return false;
    return true;
}

int casoMaior(int n)
{
    if (isPrimo(n))
        return n;
    return casoMaior(n+1);
}
int casoMenor(int n)
{
    if (isPrimo(n))
        return n;
    return casoMenor(n-1);
}


int primoMaisPerto(int n)
{

    int maior = casoMaior(n);
    int menor = casoMenor(n);
    if((maior-n)<(n-menor))
        return maior;
    return menor;
}
