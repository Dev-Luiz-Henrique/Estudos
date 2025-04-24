// Crie uma funcao que coloque todos elementos do mapa M em caixa alta
// Crie uma funcao que coloque todos elementos do mapa M em caixa baixa
// Nao use nenhuma funcao pronta da linguagem

#include <stdio.h>
#include "map.h"

void toUpper(Map M) {
    while(M){
        for(int i = 0; M->valor[i]; i++) {
            if(M->valor[i] >= 'a' && M->valor[i] <= 'z')  
                M->valor[i] -= 32;
        }
        M = M->prox;
    }
}

void toLower(Map M) {
    while(M){
        for(int i = 0; M->valor[i]; i++) {
            if(M->valor[i] >= 'A' && M->valor[i] <= 'Z')
                M->valor[i] += 32;
        }
        M = M->prox;
    }
}

int main() {
    Map I = NULL;
    insm(82, "Lucas Silva", &I);  
    insm(12, "Alexandre Santos", &I);
    insm(42, "Sophia Almeida", &I);
    insm(52, "Matheus Santos", &I);
    exibem(I);

    toUpper(I);
    exibem(I);

    toLower(I);
    exibem(I);
    return 0;
}