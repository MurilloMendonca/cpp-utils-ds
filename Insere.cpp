#include "Insere.h"
void insere(int v[], int tam)
{
    int key, j;  
    for (int i = 1; i < tam; i++) 
    {  
        key = v[i];  
        j = i - 1;  
        while (j >= 0 && v[j] > key) 
        {  
            v[j + 1] = v[j];  
            j = j - 1;  
        }  
        v[j + 1] = key;  
    }  
}