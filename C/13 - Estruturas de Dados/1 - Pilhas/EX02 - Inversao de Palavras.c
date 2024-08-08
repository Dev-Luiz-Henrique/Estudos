/* Usando pilha, crie a funcao inverte(s), que inverte a ordem dos caracteres na cadeia s dada como entrada. */

#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define MAX 256

void inverte(char* s){
    int i;
    Pilha p = pilha(MAX);

    // Empilha a string s na pilha p.
    for(i = 0; s[i]; i++)
        empilha(s[i],p);

    // Desempilha a pilha p na string s (Agora invertida)
    i = 0;
    while(!vaziap(p)){
        s[i] = desempilha(p);
        i++;
    }

    destroip(&p);
}

int main(){
    char s[MAX];
    printf("Digite uma string: ");
    gets(s);
    inverte(s);
    puts(s);
    return 0;
}

// Nao precisa acrescentar o '\0', visto que a string invertida possui exatamente o mesmo tamanho 
// e o '\0' ja foi acrescentado automaticamente na funcao gets()