// Codifique uma Funcao Recursiva que calcule o resto da divisao inteira usando apenas operacoes basicas como a subtracao.

#include <stdio.h>

// Funcao recursiva que calcula o resto da divisao inteira usando subtracao.
int restoDivisao(int n, int d){
	
	if (n < d) return n;
	return restoDivisao(n - d, d);
}

int main(){
    int num, div;
    printf("Digite um numero: ");
    scanf ("%d", &num);
    printf("\nDigite um divisor: ");
    scanf ("%d", &div);
    
    // Chamada da funcao recursiva
    printf("\nO resto da divisao eh: %d", restoDivisao(num, div));
	return 0;
}
