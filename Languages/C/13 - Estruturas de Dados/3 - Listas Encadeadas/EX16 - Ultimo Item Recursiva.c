// Crie a funcao recursiva last(L), que devolve o ultimo item da lista L

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int last(Lista L){
    if(!L) abort();
    if(L->prox == NULL) return L->item;
    return last(L->prox);
}

int main(void){
    Lista K = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(K);
    printf("Ultimo item da lista: %d", last(K));
    return 0;
}