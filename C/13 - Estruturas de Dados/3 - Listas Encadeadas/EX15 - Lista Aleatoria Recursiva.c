// Crie a funcao recursiva rnd(n,m), que devolve uma lista com n itens aleatorios em [0, m-1]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

Lista rnd(int n, int m){
    if(n == 0) return NULL;
    return no(rand() % m, rnd(n-1, m));
}

int main(){
    int tam, intervalo;
    srand(time(NULL));

    printf("Digite a quantidade de itens da lista: ");
    scanf("%d", &tam);
    printf("Digite o intervalo n dos valores (0 ate n-1):  ");
    scanf("%d", &intervalo);

    Lista I = rnd(tam, intervalo);
    exibe(I);
    return 0;
}
