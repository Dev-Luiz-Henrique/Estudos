/*
    Uma arvore binaria aleatoria e uma arvore binaria qualquer. 
    
    Crie a funcao aleatoria(n), que devolve uma arvore binaria aleatoria, com n itens aleatorios.
*/

#include <stdio.h>
#include <time.h>
#include "arv.h"

Arv aleatoria(int n) {
    if (n <= 0) return NULL;
    int m = rand() % n;
    return arv(aleatoria(m), rand() % 100, aleatoria(n - 1 - m));
}

int main(){
    srand(time(NULL));
    exibe(aleatoria(10),0);
    return 0;
}