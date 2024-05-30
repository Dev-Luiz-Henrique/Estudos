// Crie a funcao de busca(x, F) em que o usuario insere um valor x e o programa retorna a posicao desse elemento na fila F.

#include <stdio.h>
#include "fila.h"
#define MAX 26

int busca(Itemf item, Fila F){
    int i = 0, pos = -1, x;
    Fila I = fila(MAX);

    while( !vaziaf(F) ){
        x = desenfileira(F);
        enfileira(x, I);
        if( x == item ) pos = i;
        i++;
    }

    while( !vaziaf(I) )
        enfileira(desenfileira(I), F);
    return pos;
}

int main(void) {
    Fila F = fila(MAX);
    for(int i = 0; i < MAX; i++)
        enfileira('A' + i, F);
 
    printf("Posicao do elemento 'A': %d\n", busca('A', F));
    printf("Posicao do elemento 'B': %d\n", busca('B', F));
    printf("Posicao do elemento 'Z': %d\n", busca('Z', F));
    printf("Fila: ");
    while( !vaziaf(F) )
        printf("%c ", desenfileira(F));

    destroif(&F); 
    return 0;
}