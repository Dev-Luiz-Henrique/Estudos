// Qual a saida exibida pelo programa a seguir? 

#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila F = fila(5);
    for(int i=0; i<=3; i++)
        enfileira('A'+i,F);
    while( !vaziaf(F) )
        printf("%c\n",desenfileira(F));
    destroif(&F); 
    return 0;
}

/*
R: O programa imprime:
    A
    B
    C
    D

    O progrma cria um fila de tamanho 5, em seguida enfileira os caracteres 'A' + i,
      sendo que i eh um index numerico, logo o caracter sera alterado segundo a tabela ASCII.
    Apos isso, o programa imprime os caracteres enfileirados e destroi a fila.
*/
