/*
    Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos numeros impares entre eles.

    Entrada
        O arquivo de entrada contem dois valores inteiros.

    Saida
        O programa deve imprimir um valor inteiro. 
        Este valor e a soma dos valores impares que estao entre os valores fornecidos na entrada que devera caber em um inteiro.
*/

#include <stdio.h>

int main() {
    int x, y, i, soma = 0;
    scanf("%d %d", &x, &y);

    for(i = y + 1; i < x; i++){
        if(i % 2 != 0)
            soma += i;
    }

    printf("%d\n", soma);
    return 0;
}
