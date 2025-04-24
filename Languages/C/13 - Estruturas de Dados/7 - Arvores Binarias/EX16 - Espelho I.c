// Crie a funcao recursiva espelho(A), que devolve uma copia espelhada da arvore binaria A

#include <stdio.h>
#include "arv.h"

Arv espelho(Arv A){
    if(!A) return NULL;
    return arv(espelho(A->dir), A->item, espelho(A->esq));  // Inverte direita e esquerda
}

int main(void) {
    Arv A = balanceada(9);
    Arv B = espelho(A);
    printf("Arvore A: \n"); exibe(A, 0);
    printf("\n------------------------------\n");
    printf("Arvore B: \n"); exibe(B, 0);
    return 0;
}