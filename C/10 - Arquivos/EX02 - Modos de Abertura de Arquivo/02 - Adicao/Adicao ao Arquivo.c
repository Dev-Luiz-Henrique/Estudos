// Crie um programa que abra um arquivo em modo de adicao (a) com seu nome e adicione sua idade nele
// Lembre-se de fechar o arquivo

#include <stdio.h>

int main(){
	FILE *arqADD; // Declaracao da variavel que ira armazenar o arquivo

	arqADD = fopen("Nome.txt", "a"); // Abertura e armazenamento do arquivo em modo adicao
	
	// Verifica se o arquivo foi aberto com sucesso
	if (arqADD == NULL)
		printf("Nao foi possivel abrir o arquivo!");
	else {
		printf("Arquivo aberto com sucesso!\n");
		
		// Adicao de conteudo ao arquivo
		fprintf(arqADD, "\n19");
		
		fclose(arqADD); // Fecha o arquivo
	}
	return 0;
}

