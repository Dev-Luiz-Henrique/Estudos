// Crie a funcao recursiva clone(A), que devolve um clone (copia) da arvore binaria A. 
// Em seguida, faca um programa para testar o funcionamento da funcao.

#include <stdio.h>
#include "arv.h"

Arv clone(Arv A){
    if(A == NULL) return NULL;
    return arv(clone(A->esq), A->item, clone(A->dir));
}

int main(void) {
    Arv A = balanceada(9);
    exibe(A, 0);
    printf("\n-------------------------\n");
    exibe(clone(A), 0);
    return 0;
}