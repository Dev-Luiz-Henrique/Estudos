// Crie um programa que use um prototipo de funcao (Declarada apos o main)

#include <stdio.h>

// Prototipo da funcao
void funcao();

int main() {
    // Chamando a funcao
    funcao();
    
    return 0;
}

// Definicao da funcao
void funcao() {
    printf("Esta eh uma funcao declarada abaixo da funcao main.\n");
}
