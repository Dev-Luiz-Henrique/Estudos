// Crie uma funcao iterativa e uma funcao recursiva que destrua um mapa

#include <stdio.h>
#include "map.h"

void destroim(Map *M){
    while(*M){
        Map x = *M;
        *M = x->prox;
        free(x);
    } 
}

void destroimr(Map *M){
    if( !*M ) return;
    Map x = *M;
    *M = x->prox;
    destroimr(M);
    free(x);
}

int main(){
    Map I = NULL;
    insm(36,"Leo",&I); insm(15,"Ivo",&I); 
    insm(42,"Eva",&I); insm(29,"Ana",&I);
    exibem(I); 
    destroim(&I);
    exibem(I); 

    printf("\n\n");

    Map J = NULL;
    insm(36,"Leo",&J); insm(15,"Ivo",&J); 
    insm(42,"Eva",&J); insm(29,"Ana",&J);
    exibem(J); 
    destroimr(&J);
    exibem(J);
    return 0;
}