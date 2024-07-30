// Crie uma funcao que remove um item x de uma lista L

#include <stdio.h>
#include "listaord.h"

void rem(Item x, Lista *L) {
    while( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    if( *L == NULL || (*L)->item > x ) return;
    Lista n = *L;
    *L = n->prox;
    free(n);
}

int main(void) {
    Lista I = no(1, no(2, no(3, no(4, no(5, NULL))))); // Ordenada
    exibe(I);
    rem(3, &I);
    exibe(I);
    return 0;
}
