/* Crie um Algoritmo de conversao que converta uma expressao infixa em posfixa, por ordem de prioridade, do seguinte modo:
    
    Inicie com uma pilha P e uma expressao posfixa s vazias.

    Para cada elemento da expressao infixa, da esquerda para a direita, faca:
        Se for um parentese de abertura, empilhe-o em P.
        Se for um operando, anexe-o a expressao posfixa s.
        Se for um operador, enquanto o operador no topo tiver maior ou igual prioridade,
            desempilhe-o e anexe-o a s; depois, empilhe o operador encontrado na expressao.
        Se for um parentese de fechamento, enquanto o item no topo nao for parentese de
            abertura, desempilhe-o e anexe-o s; depois, desempilhe e descarte o parentese.

    Enquanto a pilha P nao estiver vazia, desempilhe um operador e anexe-o a s.
    Devolva s como resultado.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o) {
    switch( o ) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1; // operador invalido!
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++){
        
        if( e[i]=='(' ) empilha('(',P);
        else if( isdigit(e[i]) ) s[j++] = e[i];
        else if( strchr("+-/*",e[i]) ) {
            while( !vaziap(P) && prio(topo(P))>=prio(e[i]) )
                s[j++] = desempilha(P);
            empilha(e[i],P);
        }
        else if( e[i] == ')' ) {
            while( topo(P)!='(' )
            s[j++] = desempilha(P);
            desempilha(P);
        }
    }

    while( !vaziap(P) )
        s[j++] = desempilha(P);
    s[j] = '\0';

    destroip(&P);
    return s;
}

int main(void) {
    char e[513];
    printf("Infixa? ");
    gets(e);
    printf("Posfixa: %s\n", posfixa(e));
    return 0;
}

