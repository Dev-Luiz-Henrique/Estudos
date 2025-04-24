// Crie uma funcao para calcular a soma dos itens da lista
// Por exemplo, considerando que I aponta a lista de inteiros [3,1,5], a chamada soma(I) deve devolver a resposta 9

#include <stdio.h>
#include "lista.h"

int somaItensL(Lista L){
    int s = 0;
    while(L != NULL){
        s += L->item;
        L = L->prox;
    }
    return s;
}

int main(void) {
    Lista I = no(3,no(1,no(5,NULL)));
    exibe(I);
    printf("Soma dos elementos da lista: %d", somaItensL(I));
    return 0;
}
