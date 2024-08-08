// Crie a funcao de tamanho(F) que devolva o tamanho da fila F

#include <stdio.h>
#include "fila.h"

int tamanho(Fila F){
    Fila I = fila(100);
    int i = 0;
    while( !vaziaf(F) ){
        enfileira(desenfileira(F), I);
        i++;
    }

    while( !vaziaf(I) )
        enfileira(desenfileira(I), F);
    return i;
}

int main(void) {
    Fila F = fila(100);
    for(int i = 0; i < 100; i++)
        enfileira(i, F);
 
    printf("Tamanho da fila: %d\n", tamanho(F));
    printf("Fila: ");
    while( !vaziaf(F) )
        printf("%d ", desenfileira(F));

    destroif(&F); 
    return 0;
}