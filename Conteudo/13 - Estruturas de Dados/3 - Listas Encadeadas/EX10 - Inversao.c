// Crie a funcao inversa(L), que cria e devolve uma copia invertida da lista L. 
// Por exemplo, se L for a lista [1,2,3], a chamada inversa(L) deve devolver a lista [3,2,1]

#include <stdio.h>
#include "lista.h"

Lista inversa(Lista L) {
    Lista R = NULL;
    while(L) {
        R = no(L->item, R);
        L = L->prox;
    }
    return R;
}

int main() {
    Lista L = no(12, no(22, no(99, no(21, no(87, no(65, no(43, NULL)))))));
    exibe(L);
    exibe(inversa(L));
    return 0;
}
