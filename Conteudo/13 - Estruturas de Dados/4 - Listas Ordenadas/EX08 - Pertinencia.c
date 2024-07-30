// Crie uma funcao que verifica a pertinencia de um item em uma lista ordenada

#include <stdio.h>
#include "listaord.h"

int pert(Item x, Lista L) {
    while( L != NULL && L->item < x )
        L = L->prox;
    return (L != NULL && L->item == x);
}

int main(void) {
    Lista I = no(1, no(2, no(3, no(4, no(4, no(4, no(5, NULL))))))); // Ordenada
    exibe(I);
    printf("%d\n", pert(2,I));
    return 0;
}