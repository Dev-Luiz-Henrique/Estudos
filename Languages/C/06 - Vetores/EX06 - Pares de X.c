// Dado um vetor de inteiros e um numero x, escreva uma funcao que imprima todos os pares de elementos no vetor que somam x. 
// Se nao houver nenhum par que satisfaca essa condicao, a funcao deve imprimir uma mensagem indicando isso.

#include <stdio.h>

// Funcao que imprime todos os pares de elementos no vetor que somam x.
void encontrarPares(int v[], int n, int x) {
    
    int exisePar = 0, i, j;
    // Imprime todos os pares de elementos no vetor que somam x.
    for(i = 0; i < n; i++){
    	for(j = i+1; j < n; j++){
    		
    		if(v[i] + v[j] == x) {
    			printf("(%d, %d) eh par de x\n", v[i], v[j]);
    			exisePar = 1;
			}
		}
	}
	
    // Verifica se nao houve nenhum par de x.
	if(exisePar == 0) printf("Esse vetor nao possui par de x");
}

int main() {
    int vetor1[] = {1, 5, 7, -1, 5};
    int x = 6;
    int n = sizeof(vetor1)/sizeof(vetor1[0]); // Descobre o tamanho do vetor
    encontrarPares(vetor1, n, x);

	printf("\n-----------------------\n\n");

    int vetor2[] = {2, 3, 4, -2, 6, 8, 10, 0};
    x = 8;
    n = sizeof(vetor2)/sizeof(vetor2[0]); // Descobre o tamanho do vetor
    encontrarPares(vetor2, n, x);
    return 0;
}
