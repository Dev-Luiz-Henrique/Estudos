// Escreva um programa que preencha um vetor de 10 livros solicitando a entrada de dados ao  usuario. 
// Defina um tipo de estrutura rotulada para armazenar o titulo, autor, editora e ano de publicacao de um livro.
// Em seguida imprima os valores armazenados.

#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[30];
    char autor[50];
    char editora[150];
    int anoPublicacao;
} LIVRO;

int main() {
    // Vetor do tipo Livros
    LIVRO livros[10];

	// Insercao dos dados
    for(int i = 0; i < 10 ; i++)
    {
    	printf("Insira os dados do livro %d:\n", i+1);
    	
        printf("Insira o titulo: ");
        gets(livros[i].titulo);

        printf("Insira o autor: ");
        gets(livros[i].autor);

        printf("Insira a editora: ");
        gets(livros[i].editora);

        printf("Insira o ano de publicacao: ");
        scanf("%d", &livros[i].anoPublicacao);
        getchar();  // Adicionado para consumir o caractere de nova linha
        
        printf("\n\n");
    }

	// Exibicao dos dados inseridos
    printf("Os livros inseridos sao: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("Exibindo o livro %d:\n", i+1);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Editora: %s\n", livros[i].editora);
        printf("Ano Publicao: %d\n", livros[i].anoPublicacao);
        printf("-------------------------------\n\n");
    }
    return 0;
}
