// Crie a funcao recursiva replace(x,y,L), que substitui ocorrencias de x por y na lista L

#include <stdio.h>
#include "lista.h"

void replace(int x, int y, Lista *L){
    if(!(*L)) return;
    if((*L)->item == x) (*L)->item = y;
    return replace(x, y, &((*L)->prox));
}

int main(){
    Lista I = no(10, no(20, no(30, no(10, no(10, no(20, no(30, NULL)))))));
    int x, y;
    exibe(I);
    printf("Digite o valor que sera substituido: ");
    scanf("%d", &x);
    printf("Digite o valor que ira substituir: ");
    scanf("%d", &y);
    replace(x, y, &I);
    exibe(I);
    return 0;
}
