// Usando aritmetica de ponteiros, codifique a funcao carrega(v,n), que preenche um vetor v com n valores lidos do teclado.
// Ex: scanf("%d", (v+i)); ou scanf("%d", *(v+i));  ???
// Ou scanf("%d", &(v+i)); ou scanf("%d", &*(v+i)); ???

// Resposta: scanf("%d", (v+i));


#include <stdio.h>

// Funcao que carrega o vetor
void carrega(int v[], int n){
	int i;
	for(i = 0; i < n; i++) {
        printf("Digite o valor para o index %d: ", i);
        scanf("%d", (v + i)); // Uso da resposta correta
    }
}

int main() {
    int n;
    
    // Entrada de dados
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];
    carrega(v, n); // Carregamento manual do vetor
    
    // Exibicao dos dados
    printf("\n\nVetor formado: \n");
    int i;
    for(i = 0; i < n; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }
    return 0;
}
