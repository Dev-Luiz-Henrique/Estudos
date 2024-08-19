// Usando mapeamentos, crie uma funcao recursiva para inserir um elemento no mapa

#include <stdio.h>
#include <string.h>
#include "map.h"

void insereRec(Chave c, Valor v, Map *M) {
    if(!*M || c < (*M)->chave)
        *M = no_map(c, v, *M);
    else if(c == (*M)->chave)
        strcpy((*M)->valor, v);
    else insereRec(c, v, &(*M)->prox);
}

int main(void) {
    Map I = NULL;
    insereRec(36,"Leo",&I);
    insereRec(15,"Ivo",&I);
    insereRec(42,"Eva",&I);
    insereRec(29,"Ana",&I);
    exibem(I);
    insereRec(72,"Ruy",&I);
    exibem(I);
    insereRec(29,"Bia",&I);
    exibem(I);   
    return 0;
}