// Crie uma funcao iterativa e uma funcao recursiva, que verifique se uma chave pertence a um mapa, 
// retornando 0 ou 1 e o valor da chave caso exista

#include <stdio.h>
#include <string.h>
#include "map.h"

int pertm(Chave c, Valor v, Map M) {
    while( M && c > M->chave ) 
        M = M->prox;
    if( M && c == M->chave ) 
        strcpy(v, M->valor);
    return (M && c == M->chave);
}

int pertmr(Chave c, Valor v, Map I) {
    if(!I || c < I->chave) return 0;
    if(c == I->chave) {
        strcpy(v, I->valor);
        return 1; 
    }
    return pertmr(c, v, I->prox);
}

int main(void) {
    Valor w;
    Map I = NULL;
    insm(36,"Leo",&I); insm(15,"Ivo",&I); insm(42,"Eva",&I);    
    exibem(I);

    printf("Iterativa:\n");
    if( pertm(42,w,I) ) printf("Valor da chave 29: %s\n",w);
    else puts("Chave 29 inexistente!");
    if( pertm(10,w,I) ) printf("Valor: %s\n",w);
    else puts("Chave 10 inexistente!");

    printf("\n\nRecursiva:\n");
    if(pertmr(42, w, I)) printf("Valor da chave 29: %s\n", w);
    else puts("Chave 29 inexistente!");
    if(pertmr(10, w, I)) printf("Valor: %s\n", w);
    else puts("Chave 10 inexistente!");
    return 0;
}