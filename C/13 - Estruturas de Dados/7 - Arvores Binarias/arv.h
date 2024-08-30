// arv.h - implementacao de arvores binarias

#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct arv {
    struct arv *esq;
    Item item;
    struct arv *dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
} 

// As funcoes abaixo foram desenvolvidas nos exercicios e acrescentadas aqui para uso futuro

#include <time.h>

void exibe(Arv A,int n) {
    if( A==NULL ) return;
    exibe(A->dir,n+1);
    printf("%*s%d\n",3*n,"",A->item);
    exibe(A->esq,n+1);
}

Arv completa(int h) {
    if( h==0 ) return NULL;
    return arv(completa(h-1), rand()%100, completa(h-1));
}

Arv balanceada(int n){
    if( n == 0 ) return NULL;
    return arv(balanceada((n-1)/2), rand() % 100, balanceada(n/2));
}