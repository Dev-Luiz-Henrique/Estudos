// Crie uma funcao que verifica se um item existe em um dicionario

#include <stdio.h>
#include "dic.h"

int pertdic(Chave c, Valor v, Dic D) {
   return pertm(c, v, D->vet[hash(c,D->tam)]);
}

int main(){
    Dic D = dic(3);
    char w[30];
    insd(11, "Ana", D); insd(22, "Bob", D); insd(33, "Eva", D);
    insd(44, "Dan", D); insd(55, "Ivy", D); insd(66, "Leo", D);
    insd(77, "Max", D); insd(88, "Nia", D); insd(99, "Oli", D);
    exibed(D);

    if(pertdic(22, w, D)) printf("\n\nExiste: %s\n", w);
    else printf("\n\nNao Existe\n");


    return 0;
}