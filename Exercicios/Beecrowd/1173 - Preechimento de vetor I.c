/*
    Leia um valor e faca um programa que coloque o valor lido na primeira posicao de um vetor N[10].
    Em cada posicao subsequente, coloque o dobro do valor da posicao anterior.

    Por exemplo, se o valor lido for 1, os valores do vetor devem ser 1,2,4,8 e assim sucessivamente.
    Mostre o vetor em seguida.

    Entrada
        A entrada contem um valor inteiro (V<=50).

    Saida
        Para cada posicao do vetor, escreva "N[i] = X", onde i e a posicao do vetor e X e o valor armazenado na posicao i.
        O primeiro numero do vetor N (N[0]) ira receber o valor de V.
*/

#include <stdio.h>
#define max 10

int main(){
    int *n = malloc(sizeof(int) * max);
    int v;
    scanf("%d", &v);
    n[0] = v;

    for (int i = 1; i < max; i++)
        n[i] = n[i - 1] * 2;

    for (int i = 0; i < max; i++)
        printf("N[%d] = %d\n", i, n[i]);
    free(n);
    return 0;
}
