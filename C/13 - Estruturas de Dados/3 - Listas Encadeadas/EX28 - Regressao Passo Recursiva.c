// Crie a funcao recursiva regressao_passo(p,u,k), que constroi e devolve uma lista com uma sequencia 
// regressiva de itens, iniciando em p e diminuindo ate no minimo u, de k em k. 

#include <stdio.h>
#include "lista.h"

Lista regressao_passo(int p, int u, int k){
    if((u+p)*k > 0) return NULL;
    return no(p, regressao_passo(p+k, u, k));
}

int main(){
    int inicio, fim, passo;
    printf("Digite o inicio da regressao: ");
    scanf("%d", &inicio);
    printf("Digite o fim da regressao: ");
    scanf("%d", &fim);
    printf("Digite o passo da regressao: ");
    scanf("%d", &passo); // Deve ser negativo

    Lista I = regressao_passo(inicio, fim, passo);
    printf("Lista de %d ate %d, com passo %d:\n", inicio, fim, passo);
    exibe(I);
    return 0;
}