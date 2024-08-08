// Crie a funcao recursiva progressao(p,u), que constroi e devolve uma lista com uma sequencia progressiva
// de itens, iniciando em p e aumentando ate u

#include <stdio.h>
#include "lista.h"

Lista progressao(int p, int u){
    if(p > u) return NULL;
    return no(p, progressao(p+1, u));
}

int main(){
    int inicio, fim;
    printf("Digite o inicio da progressao: ");
    scanf("%d", &inicio);
    printf("Digite o fim da progressao: ");
    scanf("%d", &fim);

    Lista I = progressao(inicio, fim);
    printf("Lista de %d ate %d:\n", inicio, fim);
    exibe(I);
    return 0;
}
