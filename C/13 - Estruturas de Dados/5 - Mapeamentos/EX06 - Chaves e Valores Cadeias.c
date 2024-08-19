/* Altere a implementacao de mapeamentos para criar mapeamentos em que tanto as chaves
quanto seus valores associados sao numeros cadeias de caracteres.

typedef char Chave[22];
typedef char Valor[22]; */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Chave[22];
typedef char Valor[22];
typedef struct map {
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
    Map n = malloc(sizeof(struct map));
    strcpy(n->chave,c);
    strcpy(n->valor,v);
    n->prox = p;
    return n;
}