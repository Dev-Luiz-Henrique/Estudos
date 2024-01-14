// Dado um numero real n, imprimir seu valor absoluto (modulo) 
// usando operador condicional ternario.


#include <stdio.h>

int main () {
	float n, abs; // Declaracao de variaveis
	
	// Entrada de dados (Numero)
    printf("\nDigite n: ");
    scanf("%f", &n);
    
    // Estrutura de decisao ternaria
    abs = n>0 ? n : -n;   // condicao ? verdadeiro : falso
    
    // Exibicao do modulo do numero
    printf("\nValor absoluto de %f ‚ %f", n, abs);
    return 0;
}

