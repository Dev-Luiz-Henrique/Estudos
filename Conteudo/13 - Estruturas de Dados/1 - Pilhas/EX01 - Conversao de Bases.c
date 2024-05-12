/* Usando uma pilha, crie um programa que le um numero inteiro positivo n (em base 10) e uma base b entre 2 e 36 e, em seguida, exibe o numero n na base b. Use as letras de A a Z para representar numeros em bases entre 11 e 36. */

#include <stdio.h>
#include "pilha.h"

int main(){
    
    int n, b;
    char conv[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Array de conversao

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    printf("Digite uma base entre 2 e 36: ");
    scanf("%d", &b);

    Pilha p = pilha(100);
    do{
       empilha(n % b, p); // Empilha o resto da divisao do numero pela base, que eh o numero na base b
       n = n / b; // Atualiza n com a divisao do numero pela base

    } while(n > 0);

    // Imprime o numero na base b, de acordo com o array de conversao
    while(!vaziap(p))
        printf("%c", conv[desempilha(p)]);
    
    destroip(&p);
    return 0;
}
