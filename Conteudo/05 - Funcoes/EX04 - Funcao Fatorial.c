// Codifique a funcao fat(n), que devolve o fatorial de um inteiro n. Lembrando que:
//	n! = n * (n-1) * (n-2) * ... * 2 * 1
//	0! = 1 (por definicao)
//	
//	recebe parametro: n
//	tipo devolvido: inteiro

#include <stdio.h>

// Funcao que calcula o fatorial de um inteiro n
int fat(int n){
	int i, f = 1;
	for(i = n; i>0; i--)
    	f = f*i;
	return f;
}

int main(){
	int n;
	printf("Digite n:");
	scanf("%d", &n);

	// Imprime o fatorial de n
	printf("\nFatorial de %d: %d", n, fat(n));
	return 0;
}