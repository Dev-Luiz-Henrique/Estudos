// Crie um programa que carregue um Vetor Dinamico Amplo a partir da leitura de um arquivo em disco

#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *ArqEnt; // Variavel que armazena o arquivo de entrada
	int Tam;
	double *Valores; // Vetor dinâmico amplo
	double aux;
	int i = 0;
	  
	ArqEnt = fopen("Arq-Ent-01.txt", "r"); // Abertura do arquivo em modo de leitura
	fscanf(ArqEnt, "%d\n", &Tam);  // primeira linha do arquivo contem um inteiro
	  
	Valores = (double *)malloc(sizeof(double) * Tam);                    
	while ( fscanf(ArqEnt, "%lf\n", &aux) != EOF ) { // enquanto a leitura for diferente de fim de arquivo, continue lendo
		Valores[i] = aux;
	    i++;
	}
	fclose(ArqEnt);
	
	printf("Elementos do vetor\n");
	for(i = 0; i < Tam; i++)
	    printf("  elemento %2d = %8.3lf\n", i, Valores[i]);
	
	free(Valores); // Libera a memoria
	printf("\n\nFim do Programa\n");
	return 0;
}
