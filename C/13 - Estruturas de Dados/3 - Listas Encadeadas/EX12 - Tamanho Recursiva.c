// Crie a funcao recursiva len(L), que devolve o tamanho da lista L

#include <stdio.h>
#include "lista.h"

int len(Lista L){
    if(!L) return 0;
    return 1 + len(L->prox);
}

int main(void){
    Lista L = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(L);
    printf("Tamanho da lista: %d", len(L));
    return 0;
}