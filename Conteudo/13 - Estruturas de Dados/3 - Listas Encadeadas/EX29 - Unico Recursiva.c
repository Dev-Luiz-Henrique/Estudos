// Crie a funcao recursiva unico(L), que constroi e devolve uma lista contendo todos os itens de L, sem repeticao

#include <stdio.h>
#include "lista.h"

int in(int x, Lista L){
    if(!L) return 0;
    if(L->item == x) return 1;
    return in(x, L->prox);
}

Lista unico(Lista L){
    if(!L) return NULL;
    Lista resto = unico(L->prox);
    return in(L->item, resto) ? resto : no(L->item, resto);
}

int main(){
    Lista I = no(1, no(3, no(1, no(2, no(3, no(2, (3, no(1, NULL))))))));
    exibe(I);
    printf("Lista sem repeticoes:\n");
    exibe(unico(I));
    return 0;
}
