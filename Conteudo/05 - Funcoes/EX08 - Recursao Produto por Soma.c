// Codifique uma Funcao Recursiva que calcule o produto de dois naturais usando soma.

#include <stdio.h>

// Funcao recursiva que calcula o produto de dois naturais usando soma
unsigned int produto(unsigned int n1, unsigned int n2){

	if(n2 == 0) return 0;
	return n1 + produto(n1, n2-1);
}   // 2 x 2 = 2 + (2 x 1) = 2 + [2 + (2 x 0)] = 4

int main(){
    unsigned int a, b, c;
    printf("Digite a e b: ");
    scanf ("%u %u", &a, &b);

    // Calcula e exibe o produto de dois numeros
	c = produto(a, b);
    printf("%u X %u = %u", a, b, c);
	return 0;
}

