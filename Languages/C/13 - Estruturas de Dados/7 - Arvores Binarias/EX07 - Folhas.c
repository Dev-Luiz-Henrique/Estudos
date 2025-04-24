// Crie a funcao recursiva folhas(A), que devolve a quantidade de folhas existentes na arvore binaria A. 
// Depois, faca um programa para testar o funcionamento da funcao.

#include <stdio.h>
#include <time.h>
#include "arv.h"

int folhas(Arv A){
    if(!A) return 0;
    if(!A->esq && !A->dir) return 1;    // ou if(A->esq == A->dir) return 1;
    return folhas(A->esq) + folhas(A->dir);
}

int main(void) {
    Arv A = balanceada(9);
    exibe(A, 0);
    printf("\nA arvore possui %d folhas \n", folhas(A));
    return 0;
}