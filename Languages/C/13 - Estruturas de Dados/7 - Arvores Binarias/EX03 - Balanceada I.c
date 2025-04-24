/*
    Uma arvore binaria esta balanceada se, para cada no, a diferenca entre o numero de descendentes
    a esquerda e o numero de descendentes a direita e no maximo 1. 
    
    Crie a funcao balanceada(n), que devolve uma arvore balanceada com n itens aleatorios.
*/

#include <stdio.h>
#include <time.h>
#include "arv.h"

Arv balanceadaA(int n){
    if( n == 0 ) return NULL;
    return arv(balanceadaA((n-1)/2), rand() % 100, balanceadaA(n/2));
}

int main(void) {
    srand(time(NULL));
    exibe(balanceadaA(9),0);
    return 0;
}

