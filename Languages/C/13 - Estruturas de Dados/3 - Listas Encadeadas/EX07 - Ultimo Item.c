// Crie a funcao ultimo(L), que devolve o ultimo item da lista L (se L estiver vazia, erro fatal)

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int ultimo(Lista L){
    if(!L) abort();
    while (L->prox) L = L->prox;
    return L->item;
}

int main(void) {
    Lista I = no(3,no(1,no(5,NULL)));
    exibe(I);
    printf("Ultimo item: %d\n", ultimo(I));
    return 0;
}
