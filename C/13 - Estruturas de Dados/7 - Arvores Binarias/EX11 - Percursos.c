/*                  Arvore Binaria

                    1
            2                       3
        4       5           6               7
                        8       9

Para cada tipo de percurso, informe em que ordem os itens da arvore a seguir sao processados.

Legenda:
    Raiz = R, Esquerda = E, Direita = D

Pre-ordem (R-E-D): 1 2 4 5 3 6 8 9 7
Em-ordem  (E-R-D): 4 2 5 1 8 6 9 3 7
Pos-ordem (E-D-R): 4 5 2 8 9 6 7 3 1

Inversa - Pre-ordem (D-E-R): 7 9 8 6 3 5 4 2 1
Inversa - Em-ordem  (D-R-E): 7 3 9 6 8 1 5 2 4
Inversa - Pos-ordem (R-D-E): 1 3 7 6 9 8 2 5 4

Crie a funcao recursiva preordem(A), que exibe a sequencia pre-ordem da arvore binaria A
Crie a funcao recursiva emordem(A),  que exibe a sequencia em-ordem  da arvore binaria A
Crie a funcao recursiva posordem(A), que exibe a sequencia pos-ordem da arvore binaria A
Crie a funcao recursiva invpreordem(A), que exibe a sequencia inversa da pre-ordem da arvore binaria A
Crie a funcao recursiva invemordem(A),  que exibe a sequencia inversa da em-ordem  da arvore binaria A
Crie a funcao recursiva invposordem(A), que exibe a sequencia inversa da pos-ordem da arvore binaria A
*/

#include <stdio.h>
#include "arv.h"

void preordem(Arv A){
    if(!A) return;
    printf("%d ", A->item); preordem(A->esq); preordem(A->dir); // R-E-D
}

void emordem(Arv A){
    if(!A) return;
    emordem(A->esq); printf("%d ", A->item); emordem(A->dir); // E-R-D
}

void posordem(Arv A){
    if(!A) return;
    posordem(A->esq); posordem(A->dir); printf("%d ", A->item); // E-D-R
}

void invpreordem(Arv A){
    if(!A) return;
    invpreordem(A->dir); invpreordem(A->esq); printf("%d ", A->item); // D-E-R
}

void invemordem(Arv A){
    if(!A) return;
    invemordem(A->dir); printf("%d ", A->item); invemordem(A->esq); // D-R-E
}

void invposordem(Arv A){
    if(!A) return;
    printf("%d ", A->item); invposordem(A->dir); invposordem(A->esq); // R-D-E
}

int main(void) {
    Arv A = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),1,arv(arv(arv(NULL,8,NULL),6,arv(NULL,9,NULL)),3,arv(NULL,7,NULL)));
    /*exibe(A, 0);

    printf("\nPre-ordem: "); preordem(A);
    printf("\nEm-ordem:  ");  emordem(A);
    printf("\nPos-ordem: "); posordem(A);
    printf("\n");
    printf("\nInverso - Pre-ordem: "); invpreordem(A);
    printf("\nInverso - Em-ordem:  ");  invemordem(A);
    printf("\nInverso - Pos-ordem: "); invposordem(A);*/


    /*Arv B = arv(arv(arv(NULL, 4, arv(NULL, 8, NULL)),2,arv(NULL, 5, NULL)),1,arv(arv(arv(NULL, 9, NULL), 6, NULL), 3, arv(NULL, 7, NULL)));
    exibe(B, 0);*/

    Arv C = arv(arv(arv(NULL, 1, NULL), 2, arv(arv(NULL, 3, NULL), 4, NULL)), 5, arv(arv(NULL, 6, arv(NULL, 7, NULL)), 8, arv(NULL, 9, NULL)));
    exibe(C, 0);

    //printf("\nPos-ordem: "); posordem(B);
    return 0;
}