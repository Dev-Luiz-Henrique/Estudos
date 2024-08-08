// O quadrado de um numero natural n eh dado pela soma dos n primeiros numeros impares consecutivos. 
// Por exemplo, 1^2=1, 2^2=1+3, 3^2=1+3+5, 4^2=1+3+5+7, etc. 
// Faca um progrma que dado um numero n, calcule seu quadrado usando a soma de impares ao inves de produto. 

#include <stdio.h>

int main() {
    int n, i, quad = 0, impar = 1;

    printf("Digite um numero: ");
    scanf("%d", &n);

	// Estrutura de repeticao
    for(i = 0; i < n; i++) {
        quad += impar;
        impar += 2;
    }

    printf("Quadrado do numero: %d", quad);
    return 0;
}

