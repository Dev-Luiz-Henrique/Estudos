/*
    Leia 100 valores inteiros. Apresente entao o maior valor lido e a posicao dentre os 100 valores lidos.

    Entrada
        O arquivo de entrada contem 100 numeros inteiros, positivos e distintos.

    Saida
        Apresente o maior valor lido e a posicao de entrada, conforme exemplo abaixo.
*/

#include <stdio.h>

int main() {
    int n, maior = 0, pos;
    for(int i = 1; i <= 100; i++){
        scanf("%d", &n);
        if(n > maior){
            maior = n;
            pos = i;
        }
    }

    printf("%d\n%d\n", maior, pos);
    return 0;
}
