// Crie a funcao recursiva osc(L), que verifica se L eh uma lista ordenada de forma simplesmente
// decrescente (i.e., cada item eh maior ou igual ao item seguinte na lista)

// Crie a funcao recursiva oec(L), que verifica se L eh uma lista ordenada de forma estritamente
// decrescente (i.e., cada item eh maior que item seguinte na lista)

#include <stdio.h>
#include "listaord.h"

int osd(Lista L){
    // Vazia = Ordenada
    if(!L || L->prox == NULL) return 1; 
    if(L->item < L->prox->item) return 0;
    return osd(L->prox);
}

int oed(Lista L){
    // Vazia = Ordenada
    if(!L || L->prox == NULL) return 1; 
    if(L->item <= L->prox->item) return 0;
    return oed(L->prox);
}

int main(void) {
    Lista M = no(5, no(4, no(4, no(4, no(3, no(2, no(1, NULL))))))); // Ordenada simplesmente decrescente
    Lista N = no(7, no(6, no(5, no(4, no(3, no(2, no(1, NULL))))))); // Ordenada estritamente decrescente

    exibe(M); 
    printf("Ordenada simplesmente decrescente? %d\n", osd(M));
    exibe(N);
    printf("Ordenada simplesmente decrescente? %d\n", osd(N));

    printf("\n\n");

    exibe(M); 
    printf("Ordenada estritamente decrescente? %d\n", oed(M));
    exibe(N);
    printf("Ordenada estritamente decrescente? %d\n", oed(N));
    return 0;
}
