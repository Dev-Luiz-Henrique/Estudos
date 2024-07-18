/*Leia a hora inicial e a hora final de um jogo. A seguir calcule a duracao do jogo, sabendo que o mesmo pode comecar em um dia e terminar em outro, tendo uma duração minima de 1 hora e maxima de 24 horas.

Entrada
A entrada contem dois valores inteiros representando a hora de inicio e a hora de fim do jogo.*/

#include <stdio.h>

int main(){
    int inicio, fim, tempo;
    scanf("%d %d", &inicio, &fim);

    if (inicio < fim)
        tempo = fim - inicio;
    else if (inicio > fim)
        tempo = 24 - inicio + fim;
    else
        tempo = 24;

    printf("O JOGO DUROU %d HORA(S)\n", tempo);
    return 0;
}