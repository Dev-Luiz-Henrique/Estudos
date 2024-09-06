// Crie a funcao recursiva destroiA(&A), que destroi uma arvore binaria A

#include <stdio.h>
#include "arv.h"

void destroiA(Arv *A){
    if(!*A) return;
    destroiA(&(*A)->esq);
    destroiA(&(*A)->dir);
    free(*A);
    *A = NULL;
}

int main(void) {
    Arv A = balanceada(9);
    exibe(A, 0);
    destroiA(&A);
    return 0;
}