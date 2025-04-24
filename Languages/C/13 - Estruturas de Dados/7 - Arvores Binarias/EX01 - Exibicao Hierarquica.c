// Crie um programa que exibe uma arvore binaria hierarquicamente

#include <stdio.h>
#include "arv.h"

void exibeA(Arv A, int n) {
    if( A==NULL ) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n", 3*n, "", A->item);
    exibe(A->esq, n+1);
}

int main(void) {
    Arv I = arv(arv(NULL,2,NULL),1,arv(NULL,3,arv(NULL,4,NULL)));
    exibeA(I,0);
    return 0;
}