// O quadrado de um natural n eh a soma dos n primeiros impares, i.e., n^2 = 1 + 3 + 5 + ... + (2n-1).
// Crie a funcao recursiva q(n), que devolve o quadrado de n, como base nesta informacao

#include <stdio.h>

int q(int n){

    if(n == 0) return 0;
    return q(n-1) + (2*n - 1);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("O quadrado de %d eh %d.\n", n, q(n));
    return 0;
}