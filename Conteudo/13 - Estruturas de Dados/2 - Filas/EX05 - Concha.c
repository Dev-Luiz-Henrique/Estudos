/* Uma cadeia c composta apenas por letras A e B e uma concha se cada letra em c pode ser conectada a exatamente 
   uma unica outra letra igual a ela em c, por meio de um arco, de modo que nenhum arco intercepte outro arco. 
   Com base nesta definicao: 
    	Crie a funcao concha(c), que recebe uma cadeia c e devolve 1 se c for uma concha (caso contrario, devolve 0). 
    	Crie a funcao filtra(F), que recebe uma fila F contendo cadeias compostas apenas por letras A e B e exibe 
        	apenas aquelas cadeias em F que sao conchas, bem como o total de cadeias em F que sao conchas. */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

int concha(char *c){ // Verifica se uma cadeia c eh concha
    Pilha P = pilha(256);
    for(int i = 0; c[i]; i++){
        if(vaziap(P)) empilha(c[i],P);
        else if(c[i] == topo(P)) desempilha(P);
        else empilha(c[i], P);
    }

    int r = vaziap(P);
    destroip(&P);
    return r;
}

void filtra(Fila F) { // Exibe apenas as cadeias em F que sao conchas 
    int total = 0;
    while(!vaziaf(F)){
        char *c = desenfileira(F);
        if(concha(c)) printf("%do: %s\n", ++total, c);
    }
} 

int main(void) { 
    Fila F = fila(20); 
    enfileira("AAAAAAAABAAABA",F); 
    enfileira("BBBBBBBBBBBBBB",F); 
    enfileira("ABBABBABBABB",F); 
    enfileira("AAABAAABBABAAA",F); 
    enfileira("ABAABAAAAAAAAA",F); 
    enfileira("AABAAAAAABAAAA",F); 
    enfileira("AAAABB",F); 
    enfileira("AABBBBAABAAB",F); 
    enfileira("ABAAAAAAAAAB",F); 
    enfileira("ABABBBABAB",F); 
    enfileira("BBBBBBBBBBBBBB",F); 
    enfileira("AABAABAAAA",F);
    enfileira("AABAAABBBBBABB",F); 
    enfileira("BBBAAAAABA",F); 
    enfileira("BBBBBBBBBBBBBB",F); 
    enfileira("AAAAAAAAAAAABB",F); 
    enfileira("BAAAAABAAAAAAA",F); 
    enfileira("BBBBABBBBBBA",F); 
    enfileira("BBABABAAAAAABB",F); 
    enfileira("ABAABAABAB",F); 
    filtra(F); // deve exibir 12 conchas 
    destroif(&F); 
    return 0; 
}

