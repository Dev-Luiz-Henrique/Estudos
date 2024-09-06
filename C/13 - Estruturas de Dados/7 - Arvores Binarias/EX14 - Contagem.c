// Crie a funcao recursiva conta(x,A), que informa quantas vezes o item x ocorre na arvore A

#include <stdio.h>
#include "arv.h"

int conta(Item x, Arv A){
    if(!A) return 0;
    return (x == A->item) + conta(x, A->esq) + conta(x, A->dir);
}

int main(void) {
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,4,NULL)),1,arv(arv(arv(NULL,8,NULL),1,arv(NULL,9,NULL)),1,arv(NULL,7,NULL)));
    Item x;
    exibe(A, 0);
    printf("Digite o item que deseja contar: ");
    scanf("%d", &x);
    printf("\nO item %d aparece %d vezes", x, conta(x, A));
    return 0;
}