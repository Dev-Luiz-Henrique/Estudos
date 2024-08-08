// Dado um numero real n, imprimir seu valor absoluto (modulo).

#include <stdio.h>
int main() {
	float n; // Declaracao de variavel
   	
   	// Entrada de dados (Numero)
   	printf ("Digite um numero: ");
    scanf ("%f", &n);   
    
    // Estrutura de decisao (Se valor eh negativo)
	if (n < 0)
		n = -n; // Conversao de valor negativo para positvo
		
	// Saida de dados
	printf ("\nO módulo de n eh: %f", n);
 	system("pause");
    return 0;
}
