// Crie um programa que abra um arquivo em modo de gravacao (w) e escreva seu nome nele
// Lembre-se de fechar o arquivo

#include <stdio.h>

int main(){
	// Declaracao da variavel que ira armazenar o arquivo
	FILE *arqSAI;
	
	arqSAI = fopen("Nome.txt", "w"); // Abertura e armazenamento do arquivo em modo gravacao
	
	// Verifica se o arquivo foi aberto com sucesso
	if (arqSAI == NULL) 
 		printf("Nao foi possivel abrir o arquivo!");
 	else {
 		printf("Arquivo aberto com sucesso!");
 		
 		// Gravacao de dados no arquivo
 		fprintf(arqSAI, "Luiz Henrique de Santana\n");
 		
 		fclose(arqSAI); // Fecha o arquivo
 	}
	return 0;
}

