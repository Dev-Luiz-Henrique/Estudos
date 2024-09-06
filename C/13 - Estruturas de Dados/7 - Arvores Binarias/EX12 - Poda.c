// Crie a funcao recursiva poda(&A), que remove todas, e so, as folhas de uma arvore binaria A

#include <stdio.h>
#include "arv.h"

void poda(Arv *A){
    if(!*A) return;
    if(!(*A)->esq && !(*A)->dir) {
        free(*A);
        *A = NULL;
    }
    else {
        poda(&(*A)->esq);
        poda(&(*A)->dir);
    }
}

int main(void) {
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),1,arv(arv(arv(NULL,8,NULL),6,arv(NULL,9,NULL)),3,arv(NULL,7,NULL)));
    exibe(A, 0);

    printf("\n-------------------------\nPrimeira poda:\n");
    poda(&A);          
    exibe(A, 0);

    printf("\n-------------------------\nSegunda poda:\n");
    poda(&A);         
    exibe(A, 0);

    printf("\n-------------------------\nTerceira poda:\n");
    poda(&A);         
    exibe(A, 0);

    printf("\n-------------------------\nQuarta poda:\n");
    poda(&A);         
    exibe(A, 0);
    return 0;
}