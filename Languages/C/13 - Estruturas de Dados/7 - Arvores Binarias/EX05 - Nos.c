// Crie a funcao recursiva nos(A), que devolve a quantidade de nos existentes na arvore binaria A. 
// Em seguida, faca um programa para testar o funcionamento da funcao.

#include <stdio.h>
#include <time.h>
#include "arv.h"

int nos(Arv A){
    if(!A) return 0;
    return 1 + nos(A->esq) + nos(A->dir);
}

int main(void) {
    Arv A = balanceada(9);
    exibe(A, 0);
    printf("\nA arvore possui %d nos", nos(A));
    return 0;
}