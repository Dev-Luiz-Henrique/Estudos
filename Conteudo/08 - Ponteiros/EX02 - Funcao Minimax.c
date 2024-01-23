// Escreva a funcao minimax (v, n, a, b), que recebe um vetor v, com n valores reais e 
// devolvem em a e b os valores minimo e maximo entre aqueles armazenados em v. 

// Observacao: Parametros do tipo vetor sempre sao passados por referencia e nao por valor.

#include <stdio.h>

// Funcao que retorna o valor min e max de um vetor
void minimax(float v[], int n, float *a, float *b) {
    int i;
    *a = v[0]; // Acessa o valor apontado por 'a' e atribui o primeiro elemento do vetor
    *b = v[0]; // Acessa o valor apontado por 'b' e atribui o primeiro elemento do vetor
    
    for(i = 0; i < n; i++){
        if (v[i] < *a) // Se o elemento atual for menor que o valor apontado por 'a'
            *a = v[i]; // Acessa o valor apontado por 'a' e atualiza o valor minimo
            
        if (v[i] > *b) // Se o elemento atual for maior que o valor apontado por 'b'
            *b = v[i]; // Acessa o valor apontado por 'b' e atualiza o valor maximo
    }
}


int main(){
	float n1, n2;
	int tamanho;
	
	// Obtem o tamanho do vetor
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanho);
	
	// Alimenta o vetor
	float v[tamanho];
	int i;
	for(i = 0; i < tamanho; i++){
		printf("Digite o valor do index %d do vetor: ", i);
		scanf("%f", &v[i]);
	}
	
	// Exibe o vetor formado
	printf("\n\nVetor formado:\n");
	for(i = 0; i < tamanho; i++){
		printf("Vetor[%d] = %.2f\n", i, v[i]);
	}
	
	minimax(v, tamanho, &n1, &n2); // Chama a funcao, note que envia o endereco de n1 e n2 para alterar as variavies nativas
	printf("\n\nValor minimo obtido: %.2f", n1);
	printf("\nValor maximo obtido: %.2f", n2);
	return 0;
}

// Teste pronto
/*int main(){	
	float v[] = {0, -3, -10.5, 15.5, 20, 37};
	float x, y;
	int tam = 6;
	minimax (v, tam, &x, &y);
	printf("%f %f", x, y);
	system("pause");
	return 0;
}*/
