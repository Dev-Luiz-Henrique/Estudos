// Crie uma funcao recursiva para informar o item maximo de um vetor de inteiros v[n]

#include <stdio.h>

/*int maximo(int v[], int n, int max) {
    if(n == 1) return max;
    if(v[n-1] > v[n-2]) max = v[n-1];
    return maximo(v, n-1, max);
}*/

int maximo(int v[], int n) {
    if (n == 1) return v[0];
    int max = maximo(v, n-1);
    return (v[n-1] > max) ? v[n-1] : max;
}

int main() {
    int v[10];
    printf("Digite 10 numeros: ");
    for(int i = 0; i < 10; i++) scanf("%d", &v[i]);
    printf("O maior numero eh: %d\n", maximo(v, 10));
    return 0;
}
