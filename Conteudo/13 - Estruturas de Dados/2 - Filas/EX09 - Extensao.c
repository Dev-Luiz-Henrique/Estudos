// Usando o tipo Fila, crie a funcao estende(F) que aumenta o tamanho da Fila F em 2 vezes
// Use a biblioteca completa fila.h, como se estivesse criando uma funcao nativa dela

#include <stdio.h>
#include "fila.h"

void estende(Fila *F){
    Fila I = fila((*F)->max * 2);
    while( !vaziaf(*F) )
        enfileira(desenfileira(*F), I);
    *F = I;
}

int main(void) {
    Fila F = fila(10);
    for(int i = 0; i < 10; i++)
        enfileira('A' + i, F);
 
    estende(&F);
    for(int i = 10; i < 20; i++)
        enfileira('A' + i, F);

    while( !vaziaf(F) )
        printf("%c ", desenfileira(F));

    destroif(&F); 
    return 0;
}