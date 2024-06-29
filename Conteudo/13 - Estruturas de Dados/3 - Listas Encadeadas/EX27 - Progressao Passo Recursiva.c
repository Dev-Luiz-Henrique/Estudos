// Crie a funcao recursiva progressao_passo(p,u,k), que constroi e devolve uma lista com uma sequencia 
// progressiva de itens, iniciando em p e aumentando ate no maximo u, de k em k

#include <stdio.h>
#include "lista.h"

Lista progressao_passo(int p, int u, int k){
    if((u-p)*k < 0) return NULL;
    return no(p, progressao_passo(p+k, u, k));
}

int main(){
    int inicio, fim, passo;
    printf("Digite o inicio da progressao: ");
    scanf("%d", &inicio);
    printf("Digite o fim da progressao: ");
    scanf("%d", &fim);
    printf("Digite o passo da progressao: ");
    scanf("%d", &passo);

    Lista I = progressao_passo(inicio, fim, passo);
    printf("Lista de %d ate %d, com passo %d:\n", inicio, fim, passo);
    exibe(I);
    return 0;
}
