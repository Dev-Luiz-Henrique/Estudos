// Crie uma funcao que ira inserir um item em um dicionario e, em seguida, uma funcao que ira exibir um dicionario

#include <stdio.h>
#include "dic.h"

void insdic(Chave c, Valor v, Dic d) {
    insm(c, v, &d->vet[hash(c,d->tam)]);
}

void exibedic(Dic d) {
    for(int i=0; i<d->tam; i++) {
        printf("%d: ", i);
        exibem(d->vet[i]); // Funcao que exibe um mapa
    }
}

int main(){
    Dic D = dic(3);
    insdic(11, "Ana", D); insdic(22, "Bob", D); insdic(33, "Eva", D);
    insdic(44, "Dan", D); insdic(55, "Ivy", D); insdic(66, "Leo", D);
    insdic(77, "Max", D); insdic(88, "Nia", D); insdic(99, "Oli", D);
    exibedic(D);
    return 0;
}