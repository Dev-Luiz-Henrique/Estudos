// Crie uma funcao iterativa e recursiva que remove um item do mapa

#include <stdio.h>
#include "map.h"

// Funcao de remocao iterativa
void remm(Chave c, Map *M) {
    while( *M && c > (*M)->chave ) 
        M = &(*M)->prox;
    if( *M == NULL || c != (*M)->chave ) return;
    Map n = *M;
    *M = n->prox;
    free(n);
}

// Funcao de remocao recursiva
void remmr(Chave c, Map *M) {  
    if(!*M || c < (*M)->chave) return;
    if(c == (*M)->chave) {
        Map n = *M;
        *M = n->prox;
        free(n);   
    } 
    else remmr(c, &(*M)->prox);
}

int main() {
    Map I = NULL;
    insm(36,"Leo",&I); insm(15,"Ivo",&I); 
    insm(42,"Eva",&I); insm(29,"Ana",&I);
    exibem(I); remm(15, &I); 
    exibem(I);
    printf("\n\n");

    Map K = NULL;
    insm(36,"Leo",&K); insm(15,"Ivo",&K); insm(78,"Jao",&K); 
    insm(42,"Eva",&K); insm(29,"Ana",&K);
    exibem(K); remmr(15, &K);
    exibem(K); remmr(29, &K);
    exibem(K);
    return 0;
}
