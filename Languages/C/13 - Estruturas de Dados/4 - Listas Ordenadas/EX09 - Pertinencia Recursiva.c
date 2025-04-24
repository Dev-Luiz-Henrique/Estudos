// Crie a funcao recursiva pert_rec(x,L), que verifica se o item x esta na lista ordenada L

#include <stdio.h>
#include "listaord.h"

int pert_rec(Item x, Lista L) {
    if(!L || L->item > x) return 0;
    if(L->item == x) return 1;
    return pert_rec(x, L->prox);
}

int main(void) {
    Lista I = no(1, no(2, no(3, no(4, no(4, no(4, no(5, NULL))))))); // Ordenada
    exibe(I);
    printf("%d\n", pert_rec(2,I));
    printf("%d\n", pert_rec(7,I));
    return 0;
}