// Crie um programa que abra um arquivo em modo de leitura (r) e leia e exiba seu nome
// Lembre-se de fechar o arquivo

#include <stdio.h>

int main(){
	FILE *arqENT; // Declaracao da variavel que ira armazenar o arquivo
	char c;

	arqENT = fopen("Nome.txt", "r"); // Abertura e armazenamento do arquivo em modo leitura
	
	// Verifica se o arquivo foi aberto com sucesso
	if (arqENT == NULL)
		printf("Nao foi possivel abrir o arquivo!");
	else {
		printf("Arquivo aberto com sucesso!\n");
		
		// Leitura e exibicao do arquivo 
		do{
	      	c = fgetc(arqENT);  // le caracter do arquivo 
	      	if(!feof(arqENT))   // final de arquivo? 
				putchar(c);	    // exibe caracter na tela
	
	   	} while(!feof(arqENT)); // Enquanto o final do arquivo nao foi alcancado
	   	// Outra opcao:
	   	// while(c != EOF) *End Of File

   		fclose(arqENT); // Fecha o arquivo
	}

	return 0;
}

