/* Crie a funcao maior(P), que recebe como entrada uma pilha P e devolve como saida o maior item existente em P. 
Apos a execucao da funcao, a pilha P deve estar da mesma forma que ela estava antes de a funcao ser executada. 
Dica: use a macro max() */

#include <stdio.h>
#include "pilha.h"

int maior(Pilha P){
    Pilha Q = pilha(100);

    // Inicializa o maior item como o primeiro item da pilha P
    int x, maior = desempilha(P);
    empilha(maior, Q);

    // Desempilha todos os itens de P para Q, encontrando o maior item
    while(!vaziap(P)){
        x = desempilha(P);
        if(x > maior)
            maior = x;
        empilha(x, Q);
    }

    // Empilha todos os itens de volta para P, mantendo a ordem original
    while(!vaziap(Q)){
        x = desempilha(Q);
        empilha(x, P);
    }

    destroip(&Q);
    return maior;
}

int main(){
    int n, i;

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &n);
    Pilha P = pilha(n);

    for(i = 1; i <= n; i++){
        int x;
        printf("Digite o item %d: ", i);
        scanf("%d", &x);
        empilha(x, P);
    }

    printf("\n\nO maior numero da pilha eh: %d", maior(P));
    printf("\nPilha: ");
    while(!vaziap(P))
        printf("%d ", desempilha(P));
    
    return 0;
}
