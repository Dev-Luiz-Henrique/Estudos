/*Escreva um programa para ler as coordenadas (X,Y) de uma quantidade indeterminada de pontos no sistema cartesiano. 
Para cada ponto escrever o quadrante a que ele pertence. 
O algoritmo sera encerrado quando pelo menos uma de duas coordenadas for NULA (nesta situacao sem escrever mensagem alguma).

Entrada
A entrada contem varios casos de teste. Cada caso de teste contem 2 valores inteiros.

Saida
Para cada caso de teste mostre em qual quadrante do sistema cartesiano se encontra a coordenada lida, conforme o exemplo.*/

#include <stdio.h>

int main(){
    int x, y;

    do {
        scanf("%d%d", &x, &y);

        if (x > 0 && y > 0)
            printf ("primeiro\n");

        else if (x < 0 && y > 0)
            printf ("segundo\n");

        else if (x < 0 && y < 0)
            printf ("terceiro\n");
        
        else if (x > 0 && y < 0)
            printf ("quarto\n");
    } while (x != 0 && y != 0);

    return 0;
}
