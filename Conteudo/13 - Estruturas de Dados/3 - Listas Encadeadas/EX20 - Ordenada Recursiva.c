// Crie a funcao recursiva sorted(L), que verifica se a lista L esta ordenada

#include <stdio.h>
#include "lista.h"

int sorted(Lista L){
    if(!L || L->prox == NULL) return 1;
    if(L->item > L->prox->item) return 0;
    return sorted(L->prox);
}

int main(){
    Lista I = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(I);
    if(sorted(I)) printf("A lista esta ordenada!\n");
    else          printf("A lista nao esta ordenada!\n");
    
    Lista J = no(1, no(2, no(3, no(4, no(5, no(6, no(7, NULL)))))));
    exibe(J);
    if(sorted(J)) printf("A lista esta ordenada!\n");
    else          printf("A lista nao esta ordenada!\n");
    return 0;
}
