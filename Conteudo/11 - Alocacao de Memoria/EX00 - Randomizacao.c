// Faca um programa em C que utilize a geracao de numeros randomicos
// Exemplifique o uso da funcao srand()

/* 
   Em suma, a funcao srand define a semente de geracao dos numeros "aleatorios",
   porem, se for um numero fixo, sempre ira gerar os mesmos numeros "aleatorios".
   Para contornar isso, deve-se usar o horario atual do computador como semente
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa o gerador de numeros aleatorios com um valor qualquer
    srand(1);
    
    printf("Gerando 5 numeros aleatorios entre 0 e 99 com srand fixo:\n");
    for(int i = 0; i < 5; i++) {
        // Gera um numero aleatorio entre 0 e 99
        int num = rand() % 100;
        printf("%d\n", num);
    }

    // Inicializa o gerador de numeros aleatorios usando time(0)
    srand(time(0));
    
    printf("\nGerando 5 numeros aleatorios entre 0 e 99 com srand variavel:\n");
    for(int i = 0; i < 5; i++) {
        // Gera um numero aleatorio entre 0 e 99
        int num = rand() % 100;
        printf("%d\n", num);
    }

    return 0;
}

