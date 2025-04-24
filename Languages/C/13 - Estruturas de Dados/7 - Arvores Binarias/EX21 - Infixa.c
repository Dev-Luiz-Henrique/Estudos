// Crie a funcao infixa(A), que imprime a forma infixa parentesiada da expressao aritmetica representada pela Arvore Binaria A
/* 
    Seja A a seguinte arvore: 
            3
        -
            5
    *
            2
        +
            1
    O programa deve imprimir: ((1+2)*(5-3))
*/

#include <stdio.h>
#include "arv.h"

void exibeC(Arv A, int n); // Prototipo de funcao

void infixa(Arv A) {
    if(!A) return;
    if(!A->esq && !A->dir)
        printf("%c", A->item);
    else{
        printf("(");
        infixa(A->esq);
        printf(" %c ", A->item); // Espaco ajustado por legibilidade
        infixa(A->dir);
        printf(")");
    }
}

int main(void) {
    Arv A = arv(arv(arv(NULL, '1', NULL), '+', arv(NULL, '2', NULL)), '*', arv(arv(NULL, '5', NULL), '-', arv(NULL, '3', NULL)));
    exibeC(A, 0);
    printf("\n\n");

    printf("Infixa Parentesiada: ");
    infixa(A);
    printf("\n");
    return 0;
}

// Exibe a arvore usando char inves de int
void exibeC(Arv A,int n) {
    if( A==NULL ) return;
    exibeC(A->dir, n+1);
    printf("%*s%c\n", 3*n, "", A->item);
    exibeC(A->esq, n+1);
}