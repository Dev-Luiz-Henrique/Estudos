/* Usando pilha, crie uma funcao para verificar se uma expressao composta apenas por chaves,
colchetes e parenteses, representada por uma cadeia de caracteres, esta ou nao balanceada. Por exemplo, 
as expressoes "[{()()}{}]" e "{[([{}])]}" estao balanceadas, mas as expressoes "{[(}])" e "{[)()(]}" nao estao. */

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int bal(char *exp){
    Pilha P = pilha(256);
    int i;

    for(i = 0; exp[i]; i++){
        // Empilha o fechamento respectivo caso ache uma abertura
        switch (exp[i]){
            case '(': empilha(')', P); break;
            case '[': empilha(']', P); break;
            case '{': empilha('}', P); break;
            // Se nao for uma abertura, verifica se o fechamento eh o correto
            default: 
                if(vaziap(P) || exp[i] != desempilha(P)) { // Tira o fechamento da pilha e compara com a entrada
                    destroip(&P);
                    return 0;
                }
        }
    }
    int n = vaziap(P); // Se a pilha estiver vazia, significa que a expressao esta balanceada, caso contrario, nao esta.
    destroip(&P);
    return n;
}

int main(){
    char exp[256];
    printf("Digite uma expressao: ");
    gets(exp);
    printf("Balanceavel: %s", bal(exp) == 0 ? "Nao" : "Sim");
    return 0;
}