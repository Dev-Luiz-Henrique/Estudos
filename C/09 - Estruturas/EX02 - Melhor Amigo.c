// Defina a estrutura PESSOA com: Nome, Telefone e Data de nascimento
// Antes, nao esqueça de definir a estrutura DATA.

// Implemente um programa que solicite os dados do seu melhor amigo;
// Armazene numa variável do tipo PESSOA. 
// Em seguida imprima os dados desta variável na tela.

#include <stdio.h>
#include <string.h>

// Estrutura Data
typedef struct {
	int dia;
	int mes;
	int ano;
} DATA;

// Estrutura Pessoa
typedef struct {
	char nome[100];
	char tell[21];
	DATA dtNasc;
} PESSOA;

int main(){
	// Declarar variavel do tipo pessoa
	PESSOA amigo;
	
	// Alimentando os dados da variavel amigo
	printf("Digite o nome do seu melhor amigo: ");
	gets(amigo.nome);
	
	printf("Digite o telefone do seu melhor amigo: ");
	gets(amigo.tell);
	
	printf("Digite a data de nascimento do seu melhor amigo:\n");
	printf("Dia: ");
	scanf("%d", &amigo.dtNasc.dia);
	printf("Mes: ");
	scanf("%d", &amigo.dtNasc.mes);
	printf("Ano: ");
	scanf("%d", &amigo.dtNasc.ano);
	
	// Saida de dados do melhor amigo
	printf("--------------------------------");
	printf("\nDados do Melhor Amigo:");
	printf("\nNome: %s", amigo.nome);
	printf("\nTelefone: %s", amigo.tell);
	printf("\nData de Nascimento: %02d/%02d/%04d", amigo.dtNasc.dia, amigo.dtNasc.mes, amigo.dtNasc.ano);
	
	return 0;
}




