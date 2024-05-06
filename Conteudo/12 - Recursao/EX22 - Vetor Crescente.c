// Crie uma funcao recursiva para verificar se um vetor de inteiros v[n] esta em ordem crescente

#include <stdio.h>

int crescente(int v[], int n) { // Tamanho n porem o vetor comeca em 0

    if(n == 1) return 1;
    if(v[n-1] > v[n-2]) return crescente(v, n-1); 
    return 0;
}

int main(){
    int v[10]; // Para n = 10
    printf("Digite 10 numeros inteiros: ");
    for(int i = 0; i < 10; i++) scanf("%d", &v[i]);
    if(crescente(v, 10)) printf("O vetor esta em ordem crescente\n");
    else printf("O vetor nao esta em ordem crescente\n");
    return 0;
}