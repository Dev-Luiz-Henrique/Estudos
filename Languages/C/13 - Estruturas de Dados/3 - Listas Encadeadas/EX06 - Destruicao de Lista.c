// Crie a funcao que ira destruir uma Lista L

#include <stdio.h>
#include "lista.h"

void destroiL(Lista *L) {
    while( *L ) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

int main(void) {
    Lista I = no(3,no(1,no(5,NULL)));
    destroi(&I);
    return 0;
}