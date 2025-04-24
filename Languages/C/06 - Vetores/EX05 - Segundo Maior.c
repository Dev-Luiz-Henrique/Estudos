// Dado um vetor de inteiros, escreva uma funcao que retorne o segundo maior numero no vetor. 
// Se o vetor tiver menos de dois elementos, a funcao deve retornar -1.

#include <stdio.h>

// Retorna o segundo maior numero no vetor
int segundoMaior(int v[], int n) {
    
    // Verifica se o vetor tem menos de dois elementos ou dois elementos iguais
    if (n < 2)  return -1;
    if (n == 2) return v[0] > v[1] ? v[0] : v[1];
    
    // Encontra o maior numero
    int n1_Maior = v[0], n2_Maior = v[0], i;
    for(i = 0; i < n; i++){
    	if (v[i] > n1_Maior)
			n1_Maior = v[i];
	}

	// Encontra o segundo maior numero
	for(i = 0; i < n; i++){
    	if (v[i] > n2_Maior && v[i] < n1_Maior) 
			n2_Maior = v[i];
	}
	return n2_Maior;
}

int main() {
    int vetor[] = {10, 20, 4, 45, 6, 89, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]); // Descobre o tamanho do vetor
    printf("O segundo maior numero eh %d\n", segundoMaior(vetor, n)); //  45
    return 0;
}

