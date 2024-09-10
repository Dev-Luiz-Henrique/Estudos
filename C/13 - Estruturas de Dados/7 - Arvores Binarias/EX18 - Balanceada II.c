/* 
   Crie a funcao recursiva balanceadaII(v,p,u), que devolve uma arvore binaria balanceada com os itens do vetor v, 
    cujo primeiro item esta na posicao p e cujo ultimo item esta na posicao u

   Por exemplo, supondo que v = {19,27,36,42,55,60,73,85}, a execucao da chamada balanceadaII(v,0,7),0) deve produzir: 

                85 
            73 
        60 
            55 
    42 
            36 
        27 
            19
*/

#include <stdio.h>
#include "arv.h"

Arv balanceadaII(Item v[], int p, int u){
    if( p > u ) return NULL;
    return arv(balanceadaII(v, p, ((p+u)/2)-1), v[(p+u)/2], balanceadaII(v, ((p+u)/2)+1, u)); 
}

int main(void) {
    int p = 0, u = 7;
    int v[] = { 19, 27, 36, 42, 55, 60, 73, 85};
    exibe(balanceadaII(v, p, u), 0);
    return 0;
}