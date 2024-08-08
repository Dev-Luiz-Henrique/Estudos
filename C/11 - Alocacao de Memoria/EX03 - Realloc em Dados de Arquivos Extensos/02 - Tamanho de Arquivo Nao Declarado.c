// Crie um programa que carregue um Vetor Dinamico Amplo a partir da leitura de um arquivo em disco sem tamanho declarado

#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *ArqEnt; // Variavel que armazena o arquivo de entrada
	int Tam;
	double *Valores; // Vetor dinâmico amplo
	double aux;
	char tecla;
	int i;
	  
	ArqEnt = fopen("Arq-Ent-02.txt", "r"); // Abertura do arquivo em modo de leitura
	Tam = 0;
	Valores = NULL;
	
	// Enquanto a leitura for diferente de fim de arquivo, continue lendo
	while ( fscanf(ArqEnt, "%lf\n", &aux) != EOF ) { 
		Tam++;
	    Valores = (double *)realloc(Valores, sizeof(double) * Tam);  // Realoca a memoria do vetor          
	    Valores[Tam-1] = aux;
	
	    // Exibe os valores do vetor a cada volta
		for(i = 0; i < Tam; i++)
	    	printf(" %.2lf", Valores[i]);
	    scanf("%c", &tecla); // Deixa o programa esperando o usuario apertar qualquer tecla
	}
	fclose(ArqEnt);
	
	printf("\nElementos do vetor\n");
	for(i = 0; i < Tam; i++)
	    printf("  elemento %2d = %8.3lf\n", i, Valores[i]);
	
	free(Valores); // Libera a memoria
	printf("\n\nFim do Programa\n");
	return 0;
}
