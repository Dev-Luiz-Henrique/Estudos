/* Qual sera a saida, se o usuario digite as cadeias "um", "dois" e "tres"? Por que?

#include <stdio.h>
#include "pilha.h" // pilha de char *
int main(void) {
    Pilha P = pilha(5);
    char s[11];
    for(int i=1; i<=3; i++) {
        printf("? ");
        gets(s);
        empilha(s,P);
    }
    while( !vaziap(P) ) 
        puts(desempilha(P));
    return 0;
}

R: Saida: tres
          tres
          tres

Porque o programa nao copia a string s, mas apenas o endereco dessa string.
Para copiar a string s, usar a funcao strdup(s), declarada em string.h.
Essa funcao duplica a cadeia s num area de memoria, alocada pela funcao malloc(), e devolve. */
  
///////////////////////////////////////////////////////////////////////////////////////////////

/* Use _strdup(s), declarada em string.h, para corrigir o programa do exercicio anterior.
Essa funcao duplica a cadeia s num area de memoria, alocada pela funcao malloc(), e devolve
o endereco dessa area. Depois de usada, essa copia pode ser destruida com a funcao  */

#include <stdio.h>
#include <string.h>
#include "pilha.h" // pilha de char *

int main(void){
    Pilha P = pilha(5);
    char s[11];

    for (int i = 1; i <= 3; i++){
        printf("? ");
        gets(s);
        empilha(_strdup(s), P);
    }

    while (!vaziap(P)){
        char *s = desempilha(P);
        puts(s);
        free(s);
    }
        
    destroip(&P);
    return 0;
}