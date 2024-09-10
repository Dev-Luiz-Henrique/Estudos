// Crie a funcao recursiva espelho(A,B), que informa se a arvore A e espelho da arvore B

#include <stdio.h>
#include "arv.h"

Arv cria_espelho(Arv A){
    if(!A) return NULL;
    return arv(cria_espelho(A->dir), A->item, cria_espelho(A->esq));  // Inverte direita e esquerda
}

int espelho(Arv A, Arv B){
    if(!A && !B) return 1;
    if((A->item != B->item) || !A || !B) return 0;
    return espelho(A->esq, B->dir) && espelho(A->dir, B->esq);
}

int main(void) {
    Arv A = balanceada(9);
    Arv B = cria_espelho(A);
    printf("Arvore A: \n"); exibe(A, 0);
    printf("\n------------------------------\n");
    printf("Arvore B: \n\n"); exibe(B, 0);

    printf("A e espelho de A? %s\n", espelho(A, A) ? "Sim" : "Nao");
    printf("A e espelho de B? %s\n", espelho(A, B) ? "Sim" : "Nao");
    return 0;
}