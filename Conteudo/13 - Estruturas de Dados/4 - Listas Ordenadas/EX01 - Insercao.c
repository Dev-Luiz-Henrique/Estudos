// Crie uma funcao de insercao em uma lista ordenada, alocando o item inserido na posicao correta

#include <stdio.h>
#include "listaord.h"

void ins(Item x, Lista *L) {
    while( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    *L = no(x,*L);
}

int main(void) {
    Lista I = NULL;
    ins(4,&I);
    ins(1,&I);
    ins(3,&I);
    ins(5,&I);
    ins(2,&I);
    exibe(I);
    return 0;
}
