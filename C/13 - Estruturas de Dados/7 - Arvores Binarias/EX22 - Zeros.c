// Crie a funcao zeros(A), que conta e retorna a quantidade de zeros de uma arvore binaria A

#include <stdio.h>
#include "arv.h"

int zeros(Arv A){
    // !A nao funciona pois 0 e NULL retornam FALSE
    if(A == NULL) return 0;   
    return (0 == A->item) + zeros(A->esq) + zeros(A->dir);
}

int main(void) {
    Arv A = arv(arv(arv(NULL,0,NULL),2,arv(NULL,4,NULL)),0,arv(arv(arv(NULL,8,NULL),0,arv(NULL,9,NULL)),1,arv(NULL,0,NULL)));
    exibe(A, 0);
    printf("\nEssa arvores possui %d zeros", zeros(A));
    return 0;
}