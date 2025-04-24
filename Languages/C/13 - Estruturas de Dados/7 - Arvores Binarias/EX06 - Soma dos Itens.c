// Crie a funcao recursiva soma(A), que devolve a soma de todos os itens armazenados na arvore binaria A. 
// Em seguida, faca um programa para testar o funcionamento da funcao.

#include <stdio.h>
#include <time.h>
#include "arv.h"

int soma(Arv A){
    if(!A) return 0;
    return A->item + soma(A->esq) + soma(A->dir);
}

int main(void) {
    srand(time(NULL));
    Arv A = balanceada(9);
    exibe(A, 0);
    printf("\nA soma de todos os itens eh %d \n", soma(A));
    return 0;
}