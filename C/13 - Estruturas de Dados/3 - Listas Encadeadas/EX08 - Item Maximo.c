// Crie a funcao maximo(L), que devolve o maior item da lista L (se L estiver vazia, erro fatal)

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int maximo(Lista L) {
    if(!L) abort();
    int max = L->item;
    while(L) {
        if(L->item > max) max = L->item;
        L = L->prox;
    }
    return max;
}

int main(){
    Lista L = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(L);
    printf("Maximo: %d\n", maximo(L));
    return 0;
}