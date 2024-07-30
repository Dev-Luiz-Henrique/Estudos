// Crie a funcao recursiva ins_rec(x,&L), que insere o item x na lista ordenada L somente
// se ele ainda nao estiver nesta lista.

#include <stdio.h>
#include "listaord.h"

void ins_isr(Item x, Lista *L) {
    if(*L == NULL || (*L)->item > x) 
		*L = no(x,*L);
    else if((*L)->item < x)
        ins_isr(x, &(*L)->prox);
    // Se forem iguais nao faz nada
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
