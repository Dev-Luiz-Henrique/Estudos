// Codifique a funcao recursiva fat_rec(n) que calcula o fatorial de n
//	n! = n * (n-1) * (n-2) * ... * 2 * 1
//	0! = 1 (por definicao)
//	
//	recebe parametro: n
//	tipo devolvido: inteiro

/*int fat(int n){
	int i, f = 1;
	for(i = n; i>0; i--)
    	f = f*i;
	return f;
}*/

#include <stdio.h>

// Funcao recursiva que calcula o fatorial de n
int fat_rec(int n)
{
	if (n==0) return 1;		
	return (n * fat_rec(n-1) ); 
}

int main(){
	int n;
	printf("Digite n:");
	scanf("%d", &n);

	// Calcula o fatorial de n
	printf("\nFatorial de %d: %d", n, fat_rec(n));
	return 0;
}