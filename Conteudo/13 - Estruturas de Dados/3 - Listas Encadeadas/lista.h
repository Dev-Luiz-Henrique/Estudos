// lista.h - implementacao de pilha lista encadeada

#include <stdlib.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
   Lista n = malloc(sizeof(struct no));
   n->item = x;
   n->prox = p;
   return n;
}

// As funcoes abaixo foram desenvolvidas nos exercicios e acrescentadas aqui para uso futuro
#include <stdio.h>
#include <time.h>

// EX01
void exibe(Lista L){
    printf("[");
    while(L != NULL){
        printf("%d", L->item);
        if(L->prox != NULL) printf(", ");
        L = L->prox;
    }
    printf("]\n");
}

//EX04
Lista aleatoria(int n, int m){
    Lista L = NULL;
    while( n > 0 ) {
        L = no(rand() % m, L);
        n--;
    }
    return L;
}