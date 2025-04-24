// Faca um programa usando o Laco do-while que inverta um numero

#include <stdio.h>

int main() {
    int num, inverso = 0, resto;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    // Estrutura de repeticao do-while
    do {
        resto = num % 10;
        inverso = inverso * 10 + resto;
        num /= 10;
    } while(num != 0);
    
    printf("Numero invertido: %d.", inverso);
    return 0;
}
