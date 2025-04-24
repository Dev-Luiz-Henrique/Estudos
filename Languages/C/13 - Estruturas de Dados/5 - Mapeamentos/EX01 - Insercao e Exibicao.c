// Usando mapeamentos, crie uma funcao para inserir um elemento no mapa e uma para exibir o mapa

#include <stdio.h>
#include <string.h>
#include "map.h"

void insere(Chave c, Valor v, Map *M) {
    while( *M && c>(*M)->chave ) 
        M = &(*M)->prox;

    if( *M && c==(*M)->chave )
        strcpy((*M)->valor,v);
    else
        *M = no_map(c,v,*M);
}

void exibe(Map M) {
    printf("[");
    while(M) {
        printf("(%d,%s)",M->chave,M->valor);
        if( M->prox ) printf(",");
        M = M->prox;
    }
    printf("]\n");
}

int main(void) {
    Map I = NULL;
    insere(36,"Leo",&I);
    insere(15,"Ivo",&I);
    insere(42,"Eva",&I);
    insere(29,"Ana",&I);
    exibe(I);
    insere(72,"Ruy",&I);
    exibe(I);
    insere(29,"Bia",&I);
    exibe(I);   
    return 0;
}