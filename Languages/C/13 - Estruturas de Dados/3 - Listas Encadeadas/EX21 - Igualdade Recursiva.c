// Crie a funcao recursiva equal(A,B), que verifica se as listas A e B sao iguais

#include <stdio.h>
#include "lista.h"

int equal(Lista A, Lista B){
    if(!A && !B) return 1;
    if(!A || !B) return 0;
    if(A->item != B->item) return 0;
    return equal(A->prox, B->prox);
}

int main(){
    Lista I = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    Lista J = no(1, no(2, no(3, no(4, no(5, no(6, no(7, NULL)))))));
    exibe(I); exibe(J);
    if(equal(I, J)) printf("As listas sao iguais!\n");
    else            printf("As listas nao sao iguais!\n");
    printf("\n");
    Lista M = no(11, no(22, no(33, no(44, no(55, no(66, no(77, NULL)))))));
    Lista N = no(11, no(22, no(33, no(44, no(55, no(66, no(77, NULL)))))));
    exibe(M); exibe(N);
    if(equal(M, N)) printf("As listas sao iguais!\n");
    else            printf("As listas nao sao iguais!\n");
    return 0;
}
