/* Com base nos algoritmos criados, crie um programa para ler uma expressao booleana completamente parentesiada 
    e exibir sua forma posfixa correspondente, bem como seu valor numerico.

    Considere que as expressoes sao compostas por:
        Operandos: letras maiusculas F e V, com valores numericos 0 e 1, respectivamente.
        Operadores: ! (nao), & (e) e | (ou), da maior para a menor prioridade.
        Delimitadores: parenteses de abertura e fechamento.

    Por exemplo, para a expressao booleana infixa parentesiada "((!F)|(F&V))", o programa
      deve apresentar como saida a forma posfixa "F!FV&|" e o valor numerico 1
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o) {
    switch( o ) {
        case '(': return 0;
        case '|': return 1;
        case '&': return 2;
        case '!': return 3;
    }
    return -1; // operador invalido!
}

char *posfixa(char *exp){
    static char s[256];
    Pilha P = pilha(256);
    int i, j = 0;

    for(i = 0; exp[i]; i++){

        if(exp[i] == '(') empilha(exp[i], P);
        else if( strchr("VF",  exp[i]) ) s[j++] = exp[i];
        else if( strchr("!&|", exp[i]) ) {
            
            while(!vaziap(P) && prio(topo(P)) >= prio(exp[i]))
                s[j++] = desempilha(P);
            empilha(exp[i], P);
        }
        else if(exp[i] == ')') {
            while(topo(P) != '('){
                s[j++] = desempilha(P);
            }
            desempilha(P);
        }
    }

    while(!vaziap(P))
        s[j++] = desempilha(P);
    s[j] = '\0';

    destroip(&P);
    return s;
}

int valor(char *pos){
    Pilha P = pilha(256);
    for(int i = 0; pos[i]; i++){
        if(strchr("VF", pos[i])) empilha(pos[i] == 'V' ? 1 : 0, P);
        else if(strchr("!", pos[i])){
            int a = desempilha(P);
            empilha(a ? 0 : 1, P);
        }
        else if(strchr("&|", pos[i])){
            int b = desempilha(P);
            int a = desempilha(P);
            empilha(pos[i] == '|' ? (a || b) : (a && b), P);
        }
    }
    int r = desempilha(P);
    destroip(&P);
    return r;
}

int main(void) {
    char e[513];
    printf("Infixa Booleana Parentesiada? ");
    gets(e);

    char *p = posfixa(e);
    printf("Posfixa: %s\n", p);
    printf("Valor: %d\n", valor(p));
    return 0;
}