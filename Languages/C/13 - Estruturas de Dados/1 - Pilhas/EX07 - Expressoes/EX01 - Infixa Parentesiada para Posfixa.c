/* Crie um Algoritmo de conversao que converta uma expressao infixa parentesiada em posfixa, do seguinte modo:
    
    Inicie com uma pilha P e uma expressao posfixa s vazias.
    Para cada elemento da expressao infixa, da esquerda para a direita, faca:
        Se for um parentese de abertura, descarte-o.
        Se for um operando, anexe-o a expressao posfixa s.
        Se for um operador, insira-o na pilha P.
        Se for um parentese de fechamento, remova um item de P e anexe-o a s.
    No final, devolva s como resultado
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++)
        if( isdigit(e[i]) ) s[j++] = e[i];
        else if( strchr("+*-/",e[i]) ) empilha(e[i], P);
        else if( e[i]==')' ) s[j++] = desempilha(P);
    s[j] = '\0';
    destroip(&P);
    return s;
}

int main(void) {
    char e[513];
    printf("Infixa Parentesiada? ");
    gets(e);
    printf("Posfixa: %s\n", posfixa(e));
    return 0;
}
