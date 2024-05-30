// Dada uma fila de inteiros, escreva um programa que exclua todos os numeros negativos 
// sem alterar a posicao dos outros elementos da fila

#include <stdio.h>
#include "fila.h"
#define MAX 10

void exibe(Fila F){
    Fila I = fila(MAX);
    Itemf x;
    printf("Fila: ");
    while( !vaziaf(F) ){
        x = desenfileira(F);
        printf("%d ", x);
        enfileira(x, I);
    }
    while( !vaziaf(I) ) enfileira(desenfileira(I), F);
    printf("\n");
}

void positivos(Fila F){
    Fila I = fila(MAX);
    Itemf x;
    while( !vaziaf(F) ){
        x = desenfileira(F);
        if(x >= 0) enfileira(x, I);
    }
    while( !vaziaf(I) ) enfileira(desenfileira(I), F);
}

int main(void) {
    Fila F = fila(MAX);
    for(int i = 0; i < MAX; i++)
        enfileira((rand() % 200) - 99, F);

    exibe(F);
    positivos(F);
    exibe(F);
    destroif(&F); 
    return 0;
}
