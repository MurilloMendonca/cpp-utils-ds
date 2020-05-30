#include"buscabin.h"
template<class T>
int buscabinite(T* a, T elem ,int inicio, int fim){
    int m;
    while(true){
        m = (inicio+fim)/2;
        if(inicio==fim && a[m]!=elem)
            return -1;
        if(elem>a[m])
            inicio=m+1;
        else if(elem<a[m])
            fim = m;
        else
            return m;
    }
}
