// Implemente um codigo que crie uma agenda com 5 pessoas e seus dados usando estruturas

#include <stdio.h>

// Estrutura DATA
typedef struct {
	   int dia;
	   int mes;
	   int ano;
}DATA;

// Estrutura PESSOA
typedef struct {
	char nome[31];
	char fone[21];
	DATA nasc;
}PESSOA;

int main() {
	// Vetor agenda do tipo PESSOA com dados
	PESSOA agenda[5] = {
		{ "Itivaldo Buzo" , "99850-9973", {27,  7, 1970} },
		{ "Roberto Soares", "99266-0876", {15, 11, 1971} },
		{ "Marcia Ueji", "99576-8292", { 9,  5, 1966} },
		{ "Silvio Lago", "99851-7715", { 18, 3, 1968} },
		{ "Mie Kobayashi", "99834-0192", { 4, 12, 1973} } };
	int i;
	
	// Exibicao dos Dados
	for (i = 0;i < 5; i++) {
	  printf("\nNome: %s", agenda[i].nome);
	  printf("\nFone: %s", agenda[i].fone);
	  printf("\nData de nascimento: %d/%d/%d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
	}
	return 0;
}


