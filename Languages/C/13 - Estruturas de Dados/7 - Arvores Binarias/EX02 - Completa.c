// Crie uma funcao que cria uma arvore binaria completa

// Uma arvore binaria completa e uma estrutura de dados especial onde todos os niveis da arvore, exceto possivelmente 
// o ultimo, estao completamente preenchidos, e todos os nos no ultimo nivel estao o mais a esquerda possivel

#include <stdio.h>
#include <time.h>
#include "arv.h"

Arv completaA(int h) {
    if( h==0 ) return NULL;
    return arv(completaA(h-1), rand() % 100, completaA(h-1));
}

int main(void) {
    srand(time(NULL));
    Arv A = completaA(3);
    exibe(A, 0);
    return 0; 
}

