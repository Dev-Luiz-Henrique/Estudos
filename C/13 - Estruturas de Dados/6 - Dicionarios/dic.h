// dic.h - implementacao de dicionarios

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int hash(int c, int m) {
    return (c % m);
}

typedef struct dic {
    int tam;
    Map *vet;
} *Dic;

Dic dic(int m) {
    Dic d = malloc(sizeof(struct dic));
    d->tam = m;
    d->vet = malloc(m*sizeof(Map));
    for(int i=0; i<m; i++) d->vet[i] = NULL;
    return d;
}

// As funcoes abaixo foram desenvolvidas nos exercicios e acrescentadas aqui para uso futuro

// Funcao para inserir um elemento no dicionario
void insd(Chave c, Valor v, Dic d) {
    insm(c, v, &d->vet[hash(c,d->tam)]);
}

// Funcao para exibir o dicionario
void exibed(Dic d) {
    for(int i=0; i<d->tam; i++) {
        printf("%d: ", i);
        exibem(d->vet[i]); // Funcao que exibe um mapa
    }
}

// Funcao para remover um elemento do dicionario
void remd(Chave c, Dic d) {
    remm(c, &d->vet[hash(c,d->tam)]);
}

// Funcao para verificar se um elemento pertence ao dicionario
int pertd(Chave c, Valor v, Dic d) {
    return pertm(c, v, d->vet[hash(c,d->tam)]);
}

// Funcao para destruir o dicionario
void destroid(Dic *d) {
    for(int i=0; i<(*d)->tam; i++)
        destroim(&(*d)->vet[i]); // Funcao que destrui um mapa
    free(*d);
    *d = NULL;
}