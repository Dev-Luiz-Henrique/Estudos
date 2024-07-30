// Crie a funcao recursiva ins_rec(x,&L), que insere o item x na lista ordenada L

#include <stdio.h>
#include "listaord.h"

void ins_isr(Item x, Lista *L) {
    if(*L == NULL || (*L)->item >= x) 
		*L = no(x,*L);
    else ins_isr(x, &(*L)->prox);
}

int main(void) {
    Lista I = NULL;
    ins_isr(4,&I);
    ins_isr(1,&I);
    ins_isr(3,&I);
    ins_isr(5,&I);
    ins_isr(2,&I);
    ins_isr(4,&I);
    ins_isr(2,&I);
    exibe(I);
    return 0;
}
