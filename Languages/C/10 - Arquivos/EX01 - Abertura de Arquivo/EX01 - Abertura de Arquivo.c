// Crie um programa que abra um arquivo, verifique se foi possivel abri-lo e, em seguida, feche-o

#include <stdio.h>

int main(){
	// Declaracao da variavel que ira armazenar o arquivo
	FILE *arqENT;
	
	arqENT = fopen("teste.txt", "r"); // Abertura e armazenamento do arquivo em modo leitura
	
	// Verifica se o arquivo foi aberto com suceso
	if (arqENT == NULL ) 
 		printf("Nao foi possivel abrir o arquivo!");
 	else
 		printf("Arquivo aberto com sucesso!");
 		
 	fclose(arqENT); // Fecha o arquivo
	return 0;
}
