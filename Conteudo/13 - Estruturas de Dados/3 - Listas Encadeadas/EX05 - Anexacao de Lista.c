// Crie uma funcao que anexe uma Lista B em uma Lista A

#include <stdio.h>
#include "lista.h"

void anexaL(Lista *A, Lista B){
    if(!B) return;
    while(*A) // != NULL
        A = &(*A)->prox;
    *A = B;
}

int main(void) {
    Lista H = no(4,no(2,NULL));
    Lista I = no(3,no(1,no(5,NULL)));
    printf("H = "); exibe(H);
    printf("I = "); exibe(I);
    printf("Pressione enter");
    getchar();
    anexaL(&H,I);
    printf("H = "); exibe(H);
    printf("I = "); exibe(I);
    return 0;
}
