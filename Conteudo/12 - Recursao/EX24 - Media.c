// Crie uma funcao recursiva para calcular a media de um vetor de reais v[n].

#include <stdio.h>

float media(float v[], int n) {
    if (n == 0) return 0;
    return (v[n-1] + (n-1) * media(v, n-1)) / n;
}

int main(){
    float v[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = sizeof(v) / sizeof(v[0]);
    printf("%f", media(v, n));
}
