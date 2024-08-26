// Crie uma funcao que destroi um dicionario

#include <stdio.h>
#include "dic.h"

void destroidic(Dic *d) {
    for(int i=0; i < (*d)->tam; i++)
        destroim(&(*d)->vet[i]);
    free(*d);
    *d = NULL;
}

int main(){
    Dic D = dic(3);
    insd(11, "Ana", D); insd(22, "Bob", D); insd(33, "Eva", D);
    insd(44, "Dan", D); insd(55, "Ivy", D); insd(66, "Leo", D);
    insd(77, "Max", D); insd(88, "Nia", D); insd(99, "Oli", D);
    exibed(D);
    destroidic(&D);
    exibed(D);
    return 0;
}