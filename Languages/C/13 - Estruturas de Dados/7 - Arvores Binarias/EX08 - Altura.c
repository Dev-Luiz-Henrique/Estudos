// Crie a funcao recursiva altura(A), que devolve a altura de uma arvore binaria A, supondo
// que arvore vazia tem altura 0. Depois, faca um programa para testar o funcionamento da funcao.

#include <time.h>
#include "arv.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Arv A){
    if(!A) return 0;
    return 1 + max(altura(A->esq), altura(A->dir));
}

int main(void) {
    srand(time(NULL));
    // Arv A = balanceada(9);
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),1,arv(arv(arv(NULL,8,NULL),6,arv(NULL,9,NULL)),3,arv(NULL,7,NULL)));
    exibe(A, 0);
    printf("\nA altura da arvore eh %d\n", altura(A));
    return 0;
}