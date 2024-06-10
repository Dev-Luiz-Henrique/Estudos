// Crie uma funcao que devolva o tamanho de uma lista qualquer

#include <stdio.h>
#include "lista.h"

int tamanhoL(Lista L){
    int t = 0;
    while(L != NULL){
        t++;
        L = L->prox;
    }
    return t;
}

int main(void) {
    Lista I = no(9,no(3,no(1,no(5,NULL))));
    printf("O tamanho da lista eh: %d", tamanhoL(I));
    return 0;
}
