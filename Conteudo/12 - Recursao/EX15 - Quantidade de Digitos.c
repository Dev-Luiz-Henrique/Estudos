// Crie a funcao recursiva qd(n), que devolve a quantidade de digitos binarios para representar o natural n. 
// Por exemplo, a chamada qd(13) deve devolver 4 (pois 13 em binario é 1101).

#include <stdio.h>

int qd(int n) {

    if (n == 0 || n == 1) return 1;
    return 1 + qd(n / 2);
}

int main() {
    int n;
    printf("Digite um numero natural: ");
    scanf("%d", &n);
    printf("A quantidade de digitos binarios para representar %d eh: %d\n", n, qd(n));
    return 0;
}