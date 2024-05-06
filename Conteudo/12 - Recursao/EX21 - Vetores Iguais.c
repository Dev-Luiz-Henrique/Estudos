// Crie uma funcao recursiva para verificar se dois vetores de inteiros v[n] e w[n] sao iguais, para n>0.

#include <stdio.h>

int iguais(int v[], int w[], int n){
    if(n == 0) return 1;
    if(v[n-1] == w[n-1]) return iguais(v, w, n-1);
    return 0;
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    printf("%d\n", iguais(a, b, 5));
    return 0;   
}