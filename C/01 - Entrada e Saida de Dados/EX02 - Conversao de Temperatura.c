// Codifique um programa que leia uma temperatura em fahrenheit e 
// informe seu valor correspondente em Celsius.

// Lembrando da fórmula de conversão: 
//	C = (F-32) * 5/9 


#include <stdio.h>

int main () {
    float tc, tf; // Declaracao de variaveis
	
	// Entrada de dados (Temperatura em Fahrenheit)
	printf ("\nDigite a temperatura em Fahrenheit:");
    scanf ("%f", &tf);
    
    // Conversao para graus celsius
    tc = (tf-32) * 5/9;
    printf ("Em Celsius: %.2f\n", tc); // Exibindo o  resultado
    system("pause"); // Pausa a tela
    return 0;
}

