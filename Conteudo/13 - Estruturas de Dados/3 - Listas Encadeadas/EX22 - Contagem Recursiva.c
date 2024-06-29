// Crie a funcao recursiva count(x,L), que informa quantas vezes o item x ocorre na lista L

#include <stdio.h>
#include "lista.h"

int count(int x, Lista L){
    if(!L) return 0;
    return (L->item == x) + count(x, L->prox);
}

int main(){
    Lista I = no(5, no(5, no(10, no(15, no(15, no(15, no(20, NULL)))))));
    int x;
    exibe(I);
    printf("Digite um valor da lista: ");
    scanf("%d", &x);
    printf("O valor digitado aparece %d vezes\n", count(x, I));
    return 0;
}