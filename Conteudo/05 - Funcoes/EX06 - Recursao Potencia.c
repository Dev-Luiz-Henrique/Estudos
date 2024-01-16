// Crie uma Funcao Recursiva que calcule potencia de a elevado a b usando multiplicacao, 
// sendo a um double e b um inteiro maior ou igual a zero (unsigned).

#include <stdio.h>

// Funcao recursiva que calcula potencia de a elevado a b usando multiplicacao
double pot(double a, unsigned int b) {

	if (b == 0) return 1;
	return a * pot(a, b - 1); // a = 2, b = 3, 2 * pot(2, 2) = 2 * 2 * pot(2, 1) = 2 * 2 * 1 = 8
}

int main() {
	double a;
	unsigned int b;

	printf("\nDigite a e b: ");
	scanf("%lf %u", &a, &b);

	// Imprime resultado da potencia de a elevado a b usando multiplicacao
	printf("\n%.2lf elevado a %u: %.2lf", a, b, pot(a, b));

	return 0;
}
