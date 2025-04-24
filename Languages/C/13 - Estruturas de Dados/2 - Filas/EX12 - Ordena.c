// Crie a funcao ordena(F) que ordena os elementos da Fila F em ordem crescente
// Dica: Use uma Pilha auxiliar para armazenar os elementos da Fila

#include <stdio.h>
#include "pilha.h"
#include "fila.h"
#define MAX 10

void ordena(Fila F) {
   Pilha P = pilha(MAX);
   Itemf x;
   while (!vaziaf(F)) {
        x = desenfileira(F);
        while (!vaziap(P) && topo(P) < x)
            enfileira(desempilha(P), F);
        empilha(x, P);
   }
   while (!vaziap(P))
        enfileira(desempilha(P), F);
   destroip(&P);
}

int main(void) {
    Fila F = fila(MAX);
    enfileira(1, F);
    enfileira(12, F);
    enfileira(12, F);
    enfileira(14, F);
    enfileira(22, F);
    enfileira(3, F);
    enfileira(-45, F);
    enfileira(12, F);
    enfileira(8, F);
    enfileira(9, F);

    ordena(F);
    while( !vaziaf(F) )
        printf("%d ", desenfileira(F));
    destroif(&F); 
    return 0;
}