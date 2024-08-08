// Crie um programa que alimente um arquivo de saida com um vetor dinamico amplo
// Lembre-se que esse tipo de vetor tem como limite a memoria do compuador, logo permite muitos dados

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	
	int n;
	int i;
	int *Vda;  // Vetor dinâmico amplo - tamanho variavel e limite = memoria do computador
	FILE *Arq;
	
	srand(time(NULL)); // Semente de numeros aleatorios
   
	// Carga de dados no vetor Vda
	printf("Digite N: ");
	scanf("%d", &n);
	Vda = (int *)malloc(sizeof(int) * n);  // Alocacao de memoria
	for(i = 0; i < n; i++)
		Vda[i] = rand() % 1000;
	
	Arq = fopen("Arq-Saida.txt", "w");
	for(i = 0; i < n; i++)
		fprintf(Arq, "%d\n", Vda[i]);
	fclose(Arq);
	
	printf("Dados gravados no arquivo de saida");
	free(Vda); // Libera a memoria
	  
	printf("\n\nFim do Programa\n");
	return 0;
}
