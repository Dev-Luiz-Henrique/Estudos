// Implemente a funcao furafila(x, F), inserindo um item x na primeira posicao da fila F (desrespeitando o conceito de FIFO).

#include <stdio.h>
#include "fila.h"
#define MAX 10

void furafila(Itemf x, Fila F){
    Fila I = fila(MAX);
    while( !vaziaf(F) )
        enfileira(desenfileira(F), I);

    enfileira(x, F);
    while( !vaziaf(I) )
        enfileira(desenfileira(I), F);
}

int main(void) {
    Fila F = fila(MAX);
    for(int i = 0; i<=4; i++)
        enfileira('A' + i, F);

    furafila('X', F);    
    furafila('Y', F);    
    furafila('Z', F);    
    while( !vaziaf(F) )
        printf("%c\n", desenfileira(F));

    destroif(&F); 
    return 0;
}