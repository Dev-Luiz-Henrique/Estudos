// Crie a funcao exibeL(), de modo que os itens da lista sejam exibidos entre colchetes e separados por virgulas. 
// A lista vazia deve ser exibida como []
// Por exemplo: exibe([3,1,5]) deve exibir [3,1,5] 

#include <stdio.h>
#include "lista.h"

void exibeL(Lista L){
    printf("[");
    while(L != NULL){
        printf("%d", L->item);
        if(L->prox != NULL) printf(", ");
        L = L->prox;
    }
    printf("]\n");
}

int main(void) {
    Lista I = no(3,no(1,no(5,NULL)));
    exibeL(I);
    return 0;
}