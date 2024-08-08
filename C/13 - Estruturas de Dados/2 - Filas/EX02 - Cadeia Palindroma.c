// Crie um programa usando fila e pilha para verificar se uma cadeia eh palindroma

#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
    char s[256];
    Fila F = fila(256);
    Pilha P = pilha(256);
    printf("\nFrase? ");
    gets(s);

    // Enfileira e empilha apenas letras
    for(int i=0; s[i]; i++)
        if( isalpha(s[i]) ) {
            char maiuscula = toupper(s[i]);
            enfileira(maiuscula, F); 
            empilha(maiuscula, P); 
        }
    // Desinfileira e desempilha enquanto os itens retirados forem iguais
    while( !vaziaf(F) && desenfileira(F)==desempilha(P) ); 
    
    if( vaziaf(F) ) puts("A frase e palindroma");
    else puts("A frase nao e palindroma");
    destroif(&F);
    destroip(&P);
    return 0;
}
