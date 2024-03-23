// Crie uma funcao para calcular o mdc e o mmc de dois numeros

#include <stdio.h>

int mdc(int a, int b) {
    while(b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int main() {
    int a = 15, b = 20;
    printf("MDC de %d e %d = %d\n", a, b, mdc(a, b));
    printf("MMC de %d e %d = %d\n", a, b, mmc(a, b));
    return 0;
}

