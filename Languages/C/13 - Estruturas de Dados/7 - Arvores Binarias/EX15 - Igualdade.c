// Crie a funcao recursiva iguais(A,B), que informa se as arvores binarias A e B sao iguais.

#include <stdio.h>
#include <time.h>
#include "arv.h"

int iguais(Arv A, Arv B){
    if(!A && !B) return 1;
    if((A->item != B->item) || !A || !B) return 0;
    return iguais(A->esq, B->esq) && iguais(A->dir, B->dir);
}

int main(void) {
    srand(time(NULL));
    Arv A = balanceada(9);
    Arv B = balanceada(9);
    printf("Arvore A: \n"); exibe(A, 0);
    printf("\n------------------------------\n");
    printf("Arvore B: \n"); exibe(B, 0);

    printf("As arvores A e A sao iguais? %s", iguais(A, A) ? "Sim" : "Nao");
    printf("\nAs arvores A e B sao iguais? %s", iguais(A, B) ? "Sim" : "Nao");
    return 0;
}