// Crie uma funcao que mostre a sequencia de finonacci ate um determinado limite l

#include <stdio.h>

void fibonacci(int limite) {
    int a = 0, b = 1;
    while(a <= limite) {
        printf("%d ", a);
        int c = a;
        a = b;
        b = c + b;
    }
}

int main() {
    int limite;
    printf("Digite o limite: ");
    scanf("%d", &limite);
    printf("Sequência de Fibonacci ate %d:\n", limite);
    fibonacci(limite);
    return 0;
}

