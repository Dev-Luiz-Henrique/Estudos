// Crie a funcao recursiva substitui(int x, int y, Arv A), que substitui toda ocorrencia do item x pelo item y na arvore binaria A

#include <stdio.h>
#include "arv.h"

void substitui(int x, int y, Arv A){
    if(!A) return;
    if(A->item == x) A->item = y;
    substitui(x, y, A->esq);
    substitui(x, y, A->dir);
}

int main(void) {
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,4,NULL)),1,arv(arv(arv(NULL,8,NULL),1,arv(NULL,9,NULL)),1,arv(NULL,7,NULL)));
    int x, y;
    printf("Arvore A: \n"); exibe(A, 0);
    printf("\n------------------------------\n");

    printf("Digite o valor que deseja substituir: ");
    scanf("%d", &x);
    printf("Digite o valor que substituira %d: ", x);
    scanf("%d", &y);

    substitui(x, y, A);
    printf("Arvore A: \n"); 
    exibe(A, 0);
    return 0;
}