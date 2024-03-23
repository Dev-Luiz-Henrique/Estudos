// Crie um programa que teste todos os tipos de funcoes

#include <stdio.h>

// Funcao sem retorno e sem argumentos
void funcao1() {
    printf("Esta eh uma funcao sem retorno e sem argumentos.\n");
}

// Funcao com argumentos mas sem retorno
void funcao2(int a, int b) {
    printf("Esta eh uma funcao com argumentos mas sem retorno. A soma de %d e %d eh %d.\n", a, b, a+b);
}

// Funcao sem argumentos mas com retorno
int funcao3() {
    printf("Esta eh uma funcao sem argumentos mas com retorno.\n");
    return 5;
}

// Funcao com argumentos e retorno
int funcao4(int a, int b) {
    printf("Esta eh uma funcao com argumentos e retorno. O produto de %d e %d eh %d.\n", a, b, a*b);
    return a*b;
}

int main() {
    int a = 3, b = 4;
    
    // Chamando as funcoes
    funcao1();
    funcao2(a, b);
    printf("O retorno da funcao 3 eh %d.\n", funcao3());
    printf("O retorno da funcao 4 eh %d.\n", funcao4(a, b));
    
    return 0;
}