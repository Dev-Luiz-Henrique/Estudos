// Crie a funcao recursiva osc(L), que verifica se L eh uma lista ordenada de forma simplesmente
// crescente (i.e., cada item eh menor ou igual ao item seguinte na lista)

// Crie a funcao recursiva oec(L), que verifica se L eh uma lista ordenada de forma estritamente
// crescente (i.e., cada item eh menor que item seguinte na lista)

#include <stdio.h>
#include "listaord.h"

int osc(Lista L){
    // Vazia = Ordenada
    if(!L || L->prox == NULL) return 1; 
    if(L->item > L->prox->item) return 0;
    return osc(L->prox);
}

int oec(Lista L){
    // Vazia = Ordenada
    if(!L || L->prox == NULL) return 1; 
    if(L->item >= L->prox->item) return 0;
    return oec(L->prox);
}

int main(void) {
    Lista M = no(1, no(2, no(3, no(4, no(4, no(4, no(5, NULL))))))); // Ordenada simplesmente crescente
    Lista N = no(1, no(2, no(3, no(4, no(5, no(6, no(7, NULL))))))); // Ordenada estritamente crescente

    exibe(M); 
    printf("Ordenada simplesmente crescente? %d\n", osc(M));
    exibe(N);
    printf("Ordenada simplesmente crescente? %d\n", osc(N));

    printf("\n\n");

    exibe(M); 
    printf("Ordenada estritamente crescente? %d\n", oec(M));
    exibe(N);
    printf("Ordenada estritamente crescente? %d\n", oec(N));
    return 0;
}