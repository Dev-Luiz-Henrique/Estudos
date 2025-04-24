// Faca um programa que use o Laco while para calcular o fatorial de um numero

#include <stdio.h>

int main() {
    int num, i = 1;
    unsigned long long int fatorial = 1; // Variavel positiva inteira muito grande
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    // Estrutura de repeticao
    while(i <= num) {
        fatorial *= i;
        i++;
    }
    
    printf("O fatorial de %d eh %llu", num, fatorial);
    return 0;
}
