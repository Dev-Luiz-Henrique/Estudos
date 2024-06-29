// Crie a funcao recursiva inversa(L,I) que, dada lista L e uma lista I (inicialmente vazia), 
// constroi e devolve a lista inversa de L

// Observacao: Note que a funcao deve usar recursao de cauda, acumulando os nos criados no parametro I

#include <stdio.h>
#include "lista.h"

Lista inversa(Lista L, Lista I){
    if(!L) return I;
    return inversa(L->prox, no(L->item, I));
}

int main(){
    Lista M = no(1, no(2, no(3, no(4, no(5, no(6, no(7, NULL)))))));
    Lista N = NULL;
    exibe(M);
    exibe(inversa(M, N));
    return 0;
}