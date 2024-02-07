// Crie um programa que carregue dois Vetores Dinamicos Amplos 
// a partir da leitura de um arquivo em disco sem tamanho declarado

#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *ArqEnt;
	int Tam;
	int *Qtde;
	double *PcUnit;
	int i, a;
	double r, SomaTotal;
	  
	// Carga dos dados
	ArqEnt = fopen("Arq-Ent", "r");
	Tam = 0;
	Qtde = NULL;
	PcUnit = NULL;
	while ( fscanf(ArqEnt, "%d;%lf\n", &a, &r) != EOF ) { 
		Tam++;
	    Qtde = (int *)realloc(Qtde, sizeof(int) * Tam);                    
	    PcUnit = (double *)realloc(PcUnit, sizeof(double) * Tam);                    
	    Qtde[Tam-1] = a;
	    PcUnit[Tam-1] = r;
	}
	fclose(ArqEnt);
	
	// Exibicao dos dados
	printf("Elementos lidos do arquivo e apuracao de resultados\n");
	for(i = 0; i < Tam; i++) {
	    printf("  qtde x pcUnit: %4d x %8.2lf -> total = %9.2lf\n", Qtde[i], PcUnit[i], Qtde[i] * PcUnit[i]);
	    SomaTotal = SomaTotal + Qtde[i] * PcUnit[i];
	}
	printf("Total de Vendas =                           %9.2lf", SomaTotal);
	  
	free(Qtde); // Libera a memoria
	free(PcUnit); // Libera a memoria
	printf("\n\nFim do Programa\n");
	return 0;
}
