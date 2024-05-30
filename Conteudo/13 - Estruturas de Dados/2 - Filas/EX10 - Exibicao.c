// Usando o tipo Fila, crie a funcao exibe(F) que exibe a Fila F

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

void exibe(Fila F){
    Fila I = fila(tamanho(F));
    Itemf x;
    printf("Fila: ");
    while( !vaziaf(F) ){
        x = desenfileira(F);
        printf("%c ", x);
        enfileira(x, I);
    }
    while( !vaziaf(I) ) enfileira(desenfileira(I), F);
    printf("\n");
}

int main(void) {
    Fila F = fila(10);
    for(int i = 0; i < 10; i++)
        enfileira('A' + i, F);
 
    exibe(F);
    destroif(&F); 
    return 0;
}