/* Considere n processos a serem executados (numerados de 1 a n), uma fila F contendo a ordem de chamada dos 
processos (i.e., o processo no inicio da fila foi o primeiro chamado e aquele no final foi o ultimo) e uma pilha P
contendo a ordem de execucao ideal dos processos (i.e., se um processo i esta sobre outro processo j em P, entao 
i deve ser executado antes de j). Supondo que cada mudanca de ordem dos processos na fila, bem como a 
execucao de um processo, consome 1 segundo, crie a funcao ttm(F,P), que recebe a fila F e a pilha P e devolve o 
tempo total minimo necessario para executar todos os processos na ordem ideal. Por exemplo, se a fila F contem os 
processos 2, 3 e 1 (sendo 2 o processo no inicio de F e 1 aquele no final de F) e a ordem de execucao ideal em P e 
1, 3 e 2 (sendo 1 o processo no topo de P e 2 aquele na base de P), entao o tempo total minimo necessario para 
executar todos os processos na ordem ideal e 6 segundos. Note que a funcao ttm() deve funcionar para qualquer 
quantidade de processos e, no final da execucao da funcao, F e P devem estar vazias. */

#include <stdio.h> 
#include "pilha.h" 
#include "fila.h" 

int ttm(Fila F, Pilha P) { // tempo total mínimo 
    int t = 0;
    while(!vaziaf(F) && !vaziap(P)) {
        int x = desempilha(P);
        int y = desenfileira(F);

        while(x != y) {
            t++;
            enfileira(y, F);
            y = desenfileira(F);
        }
        t++;
    }
    return t;
} 

int main(void) { 
    Fila F = fila(3); 
    enfileira(2,F); 
    enfileira(3,F); 
    enfileira(1,F); 

    Pilha P = pilha(3); 
    empilha(2,P); 
    empilha(3,P); 
    empilha(1,P);

    printf("\nTempo total minimo: %d\n\n", ttm(F,P)); 
    destroif(&F); 
    destroip(&P); 
    return 0; 
}
