// Crie a funcao intervalo(p,u), que cria e devolve uma lista contendo inteiros consecutivos de p ate u (para p <= u).
// Por exemplo, a chamada intervalo(-2,3) deve devolver a lista [-2,-1,0,1,2,3]. 
// Se p > u, a funcao deve devolver uma lista vazia.

#include <stdio.h>
#include "lista.h"

Lista intervalo(int p, int u) {
    Lista L = NULL;
    while(u >= p) {
    	L = no(u, L);
    	u--;
	}
    return L;
}

int main() {
    Lista I = intervalo(-2, 3);
    exibe(I);
    return 0;
}
