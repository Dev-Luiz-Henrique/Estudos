/* Crie a funcao prefixa(e), que devolve a forma prefixa da expressao aritmetica completamente parentesiada e. 
    O programa deve fazer as operações de adição, subtração, multiplicação, divisão e fatorial.
    Em seguida, faca um programa para testar a funcao.

    Dicas:
        Percorra a expressao infixa da direita para a esquerda.
        Use strlen() para determinar o tamanho da expressao infixa.
        Use _strrev() para inverter uma cadeia de caracteres.
        Expressoes:
            infixa: ((2*3)+(8/4))
            prefixa: + * 2 3 / 8 4

    Crie a funcao valpre(e), que devolve o valor da expressao aritmetica prefixa e. 
    Em seguida, faca um programa para testar a funcao.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int fat(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

char *prefixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = strlen(e) - 1; i >= 0; i--) {
        if (isdigit(e[i])) s[j++] = e[i];
        else if (strchr("!+*-/", e[i])) empilha(e[i], P);
        else if (e[i] == '(') s[j++] = desempilha(P);
    }
    s[j] = '\0';
    destroip(&P);
    return _strrev(s);
}

int valpre(char *e){
    Pilha P = pilha(256);

    for(int i = strlen(e) - 1; i >= 0; i--){
        if(isdigit(e[i])) empilha(e[i] - '0', P);
        else if(e[i] == '!') empilha(fat(desempilha(P)), P);
        else{
            int x = desempilha(P);
            int y = desempilha(P);
            switch(e[i]){
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
            }
        }
    }
    int r = desempilha(P);
    destroip(&P);
    return r;
}

int main(void) {
    char e[513];
    printf("Infixa? ");
    gets(e);

    char *p = prefixa(e);
    printf("Prefixa: %s\n", p);
    printf("Valor: %d\n", valpre(p));
    return 0;
}