// Esse programa simula o compartilhamento de uma CPU entre varios processos. Qual a saida?

#include <stdio.h>
#include "fila.h"
#define TIMESLICE 3 // tempo maximo de uso ininterrupto de CPU

int main(void) {
    Fila F = fila(5);
    enfileira(17,F); // 1o processo requer 7s para concluir sua execucao
    enfileira(25,F);
    enfileira(39,F); 
    enfileira(46,F);
    while( !vaziaf(F) ) {
        int x = desenfileira(F);
        int p = x/10;
        int t = x%10;
        if( t>3 ) enfileira(p*10 + (t-TIMESLICE), F); 
        else printf("Processo %d concluido\n",p);
    }
    destroif(&F);
    return 0;
}

/*
R: Saida: 
    Processo 2 concluido
    Processo 4 concluido
    Processo 1 concluido
    Processo 3 concluido

    Cada processo tem um tempo de execucao especifico e eh executado em intervalos de tempo 
    de no maximo 3 unidades (TIMESLICE). A cada volta eh retirada 3 unidades de tempo ate que
    cada processo seja concluido.
*/