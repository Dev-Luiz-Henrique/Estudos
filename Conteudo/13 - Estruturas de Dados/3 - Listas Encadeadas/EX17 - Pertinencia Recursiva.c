// Crie a funcao recursiva in(x,L), que verifica se o item x esta na lista L

#include <stdio.h>
#include "lista.h"

int in(int x, Lista L){
    if(!L) return 0;
    if(L->item == x) return 1;
    return in(x, L->prox);
}

int main(){
    Lista I = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    int x;
    printf("Digite um valor: ");
    scanf("%d", &x);
    printf("O numero digitado %sesta na lista\n", in(x, I) ? "" : "nao ");
    exibe(I);
    return 0;
}