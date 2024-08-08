// Usando o tipo Fila, crie a funcao uniao(F1, F2) que acrescenta a Fila F2 no final da Fila F1, retornando a fila unida
// Use a biblioteca completa fila.h, como se estivesse criando uma funcao nativa dela
// Dica: Use F->max para saber o tamanho maximo da fila

#include <stdio.h>
#include "fila.h"

Fila uniao(Fila F1, Fila F2){
    Fila I = fila(F1->max + F2->max);
    while( !vaziaf(F1) )
        enfileira(desenfileira(F1), I);

    while( !vaziaf(F2) )
        enfileira(desenfileira(F2), I);
    return I;
}

int main(){
    Fila A = fila(5);
    Fila B = fila(5);
    for(int i = 0; i < 5; i++)
        enfileira('A' + i, A);
    for(int i = 5; i < 10; i++)
        enfileira('A' + i, B);

    Fila C = uniao(A, B);         
    printf("\nFila Unida: ");
    while( !vaziaf(C) )
        printf("%c ", desenfileira(C));

    destroif(&A);
    destroif(&B);
    destroif(&C);
    return 0;
}