// Dados os coeficientes (a diferente de 0, b e c) de uma equação do segundo grau, 
// calcule e informe suas raizes reais, usando a formula de Baskara

#include <stdio.h>
#include <math.h>
int main() {
	// Declaracao de variaveis
	int a, b, c;
   	float delta, x1, x2;
   	
   	// Entrada de dados (a, b, c)
    printf("Digite a, b, c: ");
    scanf(" %d %d %d", &a, &b, &c);
    
    // Verifica se o valor de a eh 0
    if (a==0)
		printf("O valor de a deve ser diferente de zero!");
	
	else {
		delta = pow(b,2) - 4* a * c; // Calculo do delta
		
		// Verifica se delta eh menor que 0
		if (delta < 0)
			printf("\nNao existem raizes reais.");
			
		else {        
			// Calculo formula de raizes
			x1 = (-b + sqrt(delta))/ (2*a);
			x2 = (-b - sqrt(delta))/ (2*a);
			printf("\nX1: %f e X2: %f", x1, x2); // Exibe o resultado
		}
	} 
	return 0;
}

