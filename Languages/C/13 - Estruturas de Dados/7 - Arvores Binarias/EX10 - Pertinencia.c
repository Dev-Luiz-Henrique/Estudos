// Crie a funcao recursiva pertence(x,A), que determina se o item x pertence a arvore binaria A. 
// Em seguida, faca um programa para testar o funcionamento da funcao.

#include <stdio.h>
#include <time.h>
#include "arv.h"

int pertence(int x, Arv A){
    if(!A) return 0;
    if(A->item == x) return 1;
    return pertence(x, A->esq) || pertence(x, A->dir);
}

int main(void) {
    srand(time(NULL));
    Arv A = balanceada(9);
    exibe(A, 0);

    int n;
    printf("\nDigite um valor: ");
    scanf("%d", &n);
    printf("O valor %d pertence a arvore? %s", n, pertence(n, A) ? "Sim" : "Nao");
    return 0;
}