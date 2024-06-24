// Crie a funcao recursiva clone(L), que devolve uma copia da lista L

#include <stdio.h>
#include "lista.h"

Lista clone(Lista L){
    if(!L) return NULL;
    return no(L->item, clone(L->prox));
}

int main(void){
    Lista K = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    printf("Lista original: "); exibe(K);
    printf("Lista clonada:  "); exibe(clone(K));
    return 0;
}