// Codifique a funcao recursiva fat(n) que calcula o fatorial de n
//	n! = n * (n-1) * (n-2) * ... * 2 * 1
//	0! = 1 (por definicao)
//	
//	recebe parametro: n
//	tipo devolvido: inteiro

#include <stdio.h>

// Funcao recursiva que calcula o fatorial de n
int fat(int n){
	if (n==0) return 1;		
	return n * fat(n-1); 
}

int main(){
	int n;
	printf("Digite n:");
	scanf("%d", &n);

	// Calcula o fatorial de n
	printf("\nFatorial de %d: %d", n, fat(n));
	return 0;
}

/* SIMULACAO:
fat(5)
= 5*fat(4)
= 5*4*fat(3)
= 5*4*3*fat(2)
= 5*4*3*2*fat(1)
= 5*4*3*2*1*fat(0)
= 5*4*3*2*1*1 = 120
*/