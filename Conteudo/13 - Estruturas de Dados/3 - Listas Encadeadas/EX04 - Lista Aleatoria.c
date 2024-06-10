// Codifique uma funcao que crie uma Lista de tamanho n, composta por n itens aleatorios no intervalo [0, m-1] 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

Lista lista_aleatoria(int n, int m){
    Lista L = NULL;
    while( n > 0 ) {
        L = no(rand() % m, L);
        n--;
    }
    return L;
}

int main(){
    int tam, intervalo;
    srand(time(NULL));

    printf("Digite a quantidade de itens da lista: ");
    scanf("%d", &tam);
    printf("Digite o intervalo n dos valores (0 ate n-1):  ");
    scanf("%d", &intervalo);

    Lista I = lista_aleatoria(tam, intervalo);
    exibe(I);
    return 0;
}
