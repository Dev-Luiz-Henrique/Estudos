// Crie a funcao recursiva sd(n), que devolve a soma dos digitos do numero natural n. 
// Por exemplo, a chamada sd(7859) deve devolver 29 (pois 7+8+5+9 = 29).

#include <stdio.h>

int sd(int n){

    if(n == 0) return 0;
    return (n % 10) + sd(n / 10);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("A soma dos digitos de %d eh %d.\n", n, sd(n));
    return 0;
}