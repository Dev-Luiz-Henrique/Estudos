// Crie uma funcao de filtro que receba um mapeamento m e uma string s. 
// A funcao deve retornar um novo mapeamento contendo apenas os elementos do mapeamento original que contenham no seu campo valor.

#include <stdio.h>
#include <string.h>
#include "map.h"

// strstr(A, B) verifica se a string B esta contida na string A

Map filtrarm(Map M, char* s) {
    Map N = NULL;
    while(M){
        if(strstr(M->valor, s) != NULL) insm(M->chave, M->valor, &N);
        M = M->prox;
    }
    return N;
}

int main() {
    Map I = NULL;
    insm(82, "Lucas Silva", &I);  
    insm(12, "Alexandre Santos", &I);
    insm(42, "Sophia Almeida", &I);
    insm(52, "Matheus Santos", &I);
    insm(22, "Lucas Rodrigues", &I);
    insm(62, "Larissa Costa", &I);
    insm(72, "Lucas Ferreira", &I);
    insm(35, "Gabriel Oliveira", &I);
    insm(92, "Rafael Santos", &I);
    insm(17, "Carolina Souza", &I);
    exibem(I);

    printf("Exibir todos 'Lucas': "); 
    exibem(filtrarm(I, "Lucas"));
    printf("\n");

    printf("Exibir todos 'Santos': "); 
    exibem(filtrarm(I, "Santos"));
    return 0;
}