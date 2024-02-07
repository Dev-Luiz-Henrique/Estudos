/*Og e um homem das cavernas com varios filhos e filhas, e ele quer contar todos eles. Og conta seus filhos com sua mao esquerda e suas filhas com sua mao direita.

Entretanto, Og nao e inteligente, e nao sabe somar os dois numeros. Assim, ele pediu para voce escrever um programa que realize a soma.

Entrada 
A entrada contem varios casos de teste. Cada caso de teste consiste em uma linha contendo dois inteiros L e R, separados por um espaco, 
indicando o numero de filhos e de filhas, respectivamente (1 <= L, R <= 5).

O fim do arquivo de entrada e indicado por L = R = 0.

Saida 
Para cada caso de teste, imprima uma linha contendo um inteiro indicando quantos filhos e filhas Og tem ao todo.*/

#include <stdio.h>

int main(){

    int L, R, soma;

    while(1){
        scanf("%d %d", &L, &R);
        if(L == R && L == 0) break;

        soma = L + R;
        printf("%d\n", soma);
    }

    return 0;
}
