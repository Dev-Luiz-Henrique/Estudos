// Crie uma funcao que remove um item de um dicionario

#include <stdio.h>
#include "dic.h"

void remdic(int c, Dic D){
    remm(c, &D->vet[hash(c, D->tam)]);
}

int main(){
    int item;
    Dic D = dic(3);
    insd(11, "Ana", D); insd(22, "Bob", D); insd(33, "Eva", D);
    insd(44, "Dan", D); insd(55, "Ivy", D); insd(66, "Leo", D);
    insd(77, "Max", D); insd(88, "Nia", D); insd(99, "Oli", D);
    exibed(D);

    printf("\n\nDigite o valor que quer remover: ");
    scanf("%d", &item);
    remdic(item, D);
    exibed(D);
    return 0;
}