// Com base na tabela abaixo, escreva um programa que leia o codigo de um item e a quantidade deste item. 
// A seguir, calcule e mostre o valor da conta a pagar.

// CODIGO | ESPECIFICACAO   | PRECO
// 1      | Cachorro Quente | R$ 4.00
// 2      | X-Salada        | R$ 4.50
// 3      | X-Bacon         | R$ 5.00
// 4      | Torrada simples | R$ 2.00
// 5      | Refrigerante    | R$ 1.50


// Entrada
// O arquivo de entrada contem dois valores inteiros correspondentes ao codigo e a quantidade de um item conforme tabela acima.

// Saida
// O arquivo de saida deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas apos o ponto decimal.


#include <stdio.h>

int main(){
	int cod, qntd;
	double tot;
	
	scanf("%d", &cod);
	scanf("%d", &qntd);
	
	switch(cod){
	    case 1: tot = qntd * 4.00; break;
	    case 2: tot = qntd * 4.50; break;
	    case 3: tot = qntd * 5.00; break;
	    case 4: tot = qntd * 2.00; break;
	    case 5: tot = qntd * 1.50;
	}
	
	printf("Total: R$ %.2lf\n", tot);
	return 0;
}
