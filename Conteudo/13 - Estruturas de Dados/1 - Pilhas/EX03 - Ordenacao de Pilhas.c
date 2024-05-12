/* Crie um programa que le uma sequencia de n numeros inteiros digitados pelo usuario e, usando duas pilhas A e B,
ordena essa sequencia de forma decrescente e sem repeticao. */

#include <stdio.h>
#include "pilha.h"

int main(){
	int num, tam, i;
	
	printf("Digite o tamanho da sequencia: "); 
	scanf("%d", &tam);

	Pilha A = pilha(tam);
    Pilha B = pilha(tam);

	printf("Digite a sequencia de numeros:\n");
	for(i=1; i <= tam; i++){
		printf("%do. num? ", i);
		scanf("%d", &num);

        // Enquanto a pilha A nao estiver vazia e o numero digitado for menor que o topo da pilha A, 
        // empilha (transfere) o topo da pilha A na pilha B. 
        while(!vaziap(A) && num < topo(A))
            empilha(desempilha(A), B);

		// Depois, empilha o numero digitado na pilha A se num nao for um numero repetido
        if(vaziap(A) ||  num != topo(A))
            empilha(num, A); 
            
        // Retorna tudo que estava na pilha B de volta para pilha A
		while(!vaziap(B))
            empilha(desempilha(B), A);
	}

    printf("Sequencia decrescente: ");
    while(!vaziap(A))
        printf("%d ", desempilha(A));
    
    destroip(&A);
    destroip(&B);
	
    return 0;
}

// Caso queira em odem crescente basta alterar o sinal de
// while(!vaziap(A) && num < topo(A)) para '>'
// Caso possa ter repeticao basta tirar o if
