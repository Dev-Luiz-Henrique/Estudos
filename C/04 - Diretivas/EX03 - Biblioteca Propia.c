// Crie um programa quem utilize um biblioteca criada ("macros.h")
// Lembre-se que o padrao eh utilizar " " para colocar a biblioteca propria

#include <stdio.h>
#include "macros.h"

int main(){
    int n1 = -7;
    int n2 =  8;
    printf("\n %d ", soma(2*3, 1 + 3));
    printf("\n %d ", abs(n1));
    printf("\n %d ", max(n1, n2));
    return 0;
}

