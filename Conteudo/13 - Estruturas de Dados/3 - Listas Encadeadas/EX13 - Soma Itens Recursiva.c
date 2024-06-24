// Crie a funcao recursiva sum(L), que devolve a soma dos itens da lista L

#include <stdio.h>
#include "lista.h"

int sum(Lista L){
    if(!L) return 0;
    return L->item + sum(L->prox);
}

int main(void){
    Lista I = no(1, no(2, no(3, no(4, no(5, no(6, no(7, NULL)))))));
    exibe(I);
    printf("Soma dos valores da lista: %d", sum(I));
    return 0;
}