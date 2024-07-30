// Crie a funcao recursiva exiba_rd(L), que exibe a lista ordenada L em ordem direta, i.e.,
// mostrando os itens do primeiro ate o ultimo (um em cada linha)

// Crie a funcao recursiva exiba_ri(L), que exibe a lista ordenada L em ordem inversa, i.e.,
// mostrando os itens do ultimo ate o primeiro (um em cada linha)

#include <stdio.h>
#include "listaord.h"

void exiba_rd(Lista L){
    if(L != NULL){
    	printf("%d\n", L->item);
        exiba_rd(L->prox);
    }
}

void exiba_ri(Lista L){
    if(L != NULL){
        exiba_ri(L->prox);
    	printf("%d\n", L->item);
    }
}

int main(void) {
    Lista I = no(1, no(2, no(3, no(4, no(5, NULL))))); // Ordenada
    printf("Ordem direta:\n");
    exiba_rd(I);
    printf("\nOrdem inversa:\n");
    exiba_ri(I);
    return 0;
}
