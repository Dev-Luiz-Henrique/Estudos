// Crie a funcao pertence(x,L), que verifica se o item x pertence a lista L

#include <stdio.h>
#include "lista.h"

int pertence(int x, Lista L) {
    if(L == NULL) return 0;
    while (L) {
        if (L->item == x) return 1;
        L = L->prox;
    }
    return 0;
}

int main() {
    Lista K = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    int x;
    printf("Digite um valor: ");
    scanf("%d", &x);
    if (pertence(x, K)) printf("O valor pertence a lista\n");
    else printf("O valor nao pertence a lista\n");
    exibe(K);
    return 0;
}