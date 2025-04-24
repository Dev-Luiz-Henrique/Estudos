/*
    Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duracao do jogo.
    Obs: O jogo tem duracaoo minima de um (1) minuto e duracao maxima de 24 horas.

    Entrada
        Quatro numeros inteiros representando a hora de inicio e fim do jogo.

    Saida
        Mostre a seguinte mensagem: "O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)".
*/

#include <stdio.h>

int main() {
    int hInicio, hFim, mInicio, mFim;
    int totMinInicio, totMinFim;
    int tempoH, tempoM;
    scanf("%d %d %d %d", &hInicio, &mInicio, &hFim, &mFim);

    if(hInicio == hFim && mInicio == mFim) {
        tempoH = 24;
        tempoM = 0; // O jogo durou 24 horas e 0 minutos.
    }
    else{
        totMinInicio = hInicio * 60 + mInicio;
        totMinFim = hFim * 60 + mFim;

        if(totMinInicio > totMinFim) totMinFim += 24 * 60; // Virou o dia

        tempoH = (totMinFim - totMinInicio) / 60;
        tempoM = (totMinFim - totMinInicio) % 60; // O resto da divisão eh o minuto.
    }
   
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", tempoH, tempoM);
    return 0;
}
