// Crie a funcao nested(A) que exibe uma arvore binaria A em notacao aninhada
// Por exemplo, se A = arv(NULL, 1, arv(arv(NULL, 3, NULL), 2, NULL)), o programa deve exibir:
// (()1((()3())2()))

#include <stdio.h>
#include "arv.h"

void nested(Arv A) {
    printf("(");
    if(A){
        nested(A->esq);
        printf("%d", A->item);
        nested(A->dir);
    }
    printf(")");
}

int main(void) {
    Arv A = arv(NULL, 1, arv(arv(NULL, 3, NULL), 2, NULL));
    nested(A);
    printf("\n\n");

    Arv I = arv(arv(NULL,2,NULL),1,arv(NULL,3,arv(NULL,4,NULL)));
    nested(I);
    printf("\n");
    return 0;
}