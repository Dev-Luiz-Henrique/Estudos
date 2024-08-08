// Crie uma estrutura chamada DATA com os campos dia, mes e ano
// Crie 3 chamadas dessa mesma estrutura

#include <stdio.h>

// Definida a estrutura data
typedef struct {
	int dia;
	int mes;
	int ano;
} DATA;

int main(){
	// Declarando as variaveis do tipo DATA
	DATA hoje, ontem, amanha;
	
	// Atribuindo dados as variaveis
	hoje.dia = 30;
	hoje.mes = 11;
	hoje.ano = 2023;
	printf ("Hoje: %02d/%02d/%04d", hoje.dia, hoje.mes, hoje.ano);
	
	ontem.dia = 29;
	ontem.mes = 11;
	ontem.ano = 2023;
	printf ("\nOntem: %02d/%02d/%04d", ontem.dia, ontem.mes, ontem.ano);
	
	amanha.dia = 31;
	amanha.mes = 11;
	amanha.ano = 2023;
	printf ("\nAmanha: %02d/%02d/%04d", amanha.dia, amanha.mes, amanha.ano);
	return 0; 
}

