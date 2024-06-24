// Crie a funcao recursiva nth(n,L), que devolve o enesimo (n>=1) item da lista L

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int nth(int n, Lista L){
    if(n < 1 || L == NULL) abort();
    if(n == 1) return L->item;
    return nth(n-1, L->prox);
}

int main(){
    Lista I = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    int x;
    printf("Digite uma posicao: ");
    scanf("%d", &x);
    printf("O item da posicao %d eh: %d\n", x, nth(x,I));
    exibe(I);
    return 0;
}