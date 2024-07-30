// Crie a funcao iterativa rem_todo(x,&L), que remove toda ocorrencia do item x na lista ordenada L
// Em seguida crie uma funcao recursiva que faca a mesma coisa

#include <stdio.h>
#include "listaord.h"

void rem_todo(Item x, Lista *L) {
    while( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    if( *L == NULL || (*L)->item > x ) return;
    
    while( (*L)->item == x){
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

void rem_todo_rec(Item x, Lista *L){
    if( *L == NULL || (*L)->item > x ) return;
    rem_todo_rec(x, &(*L)->prox);
    if( (*L)->item == x ) free(*L);
}

int main(void) {
    Lista I = no(1, no(2, no(3, no(4, no(4, no(4, no(5, NULL))))))); // Ordenada
    exibe(I);
    rem_todo(4, &I);
    exibe(I);

    Lista J = no(1, no(2, no(3, no(4, no(4, no(4, no(5, NULL))))))); // Ordenada
    exibe(J);
    rem_todo_rec(4, &J);
    exibe(J);
    return 0;
}
