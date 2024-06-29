// Crie a funcao recursiva regressao(p,u), que constroi e devolve uma lista com uma sequencia regressiva de itens, 
// iniciando em p e diminuindo ate u

#include <stdio.h>
#include "lista.h"

Lista regressao(int p, int u){
    if(p < u) return NULL;
    return no(p, regressao(p-1, u));
}

int main(){
    int inicio, fim;
    printf("Digite o inicio da regressao: ");
    scanf("%d", &inicio);
    printf("Digite o fim da regressao: ");
    scanf("%d", &fim);

    Lista I = regressao(inicio, fim);
    printf("Lista de %d ate %d:\n", inicio, fim);
    exibe(I);
    return 0;
}
