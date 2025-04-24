// Crie a funcao iterativa ins_isr(x,&L), que insere o item x na lista ordenada L somente se
// ele ainda nao estiver nesta lista.

#include <stdio.h>
#include "listaord.h"

void ins_isr(Item x, Lista *L) {
    while( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    if( *L == NULL || (*L)->item != x ) 
		*L = no(x,*L);
}

int main(void) {
    Lista I = NULL;
    ins_isr(4,&I);
    ins_isr(1,&I);
    ins_isr(3,&I);
    ins_isr(5,&I);
    ins_isr(2,&I);
    ins_isr(4,&I);
    ins_isr(1,&I);
    ins_isr(3,&I);
    ins_isr(5,&I);
    ins_isr(2,&I);
    exibe(I);
    return 0;
}
