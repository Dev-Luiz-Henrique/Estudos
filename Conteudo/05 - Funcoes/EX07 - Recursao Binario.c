// Codifique uma Funcao Recursiva que recebe um natural n e imprime seu respectivo binario.
// Ex.: Binario de 13 = 1101 

#include <stdio.h>

// Funcao recursiva que imprime o binario de um numero natural n
void bin(unsigned n) {
	if (n < 2) printf("%u", n);
	else {
		bin(n/2);
		printf("%u", n%2);
	}
}

int main() {
	unsigned n;
	printf("Digite n: ");
	scanf("%u", &n);

	// Exibe o binario corresponde do numero digitado
	printf("\n%u em binario: ", n);
	bin(n);
	return 0;
}
