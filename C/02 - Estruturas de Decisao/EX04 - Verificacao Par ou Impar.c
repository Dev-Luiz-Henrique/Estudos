// Dado um inteiro n, informe se n eh par ou impar 
// usando o operador condicional ternario

#include <stdio.h>

int main() {
    int n; // Declaracao de variavel
    
    // Entrada de dados (Numero)
	printf ("Digite um numero: ");
   	scanf ("%d", &n);
   	
   	// Exibicao de dados com operador ternario
   	printf ("%s", (n%2)==0 ? "par": "impar");
   	return 0;
}

