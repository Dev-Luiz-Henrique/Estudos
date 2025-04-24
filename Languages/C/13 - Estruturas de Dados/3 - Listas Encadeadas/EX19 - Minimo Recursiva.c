// Crie a funcao recursiva minimum(L), que devolve o menor item da lista L

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int minimum(Lista L){
    if(!L) return 0;
    return min(L->item, minimum(L->prox)); 
}

int main(){
    Lista I = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(I);
    printf("O menor valor da lista eh: %d\n", minimum(I));
    return 0;
}