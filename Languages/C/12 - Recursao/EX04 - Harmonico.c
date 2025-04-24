// Crie a funcao recursiva h(n), que calcula a soma dos n >= 1
// primeiros termos da serie harmonica (1 + 1/2 + 1/3 + ... + 1/n).
#include <stdio.h>

float h(int n) {
    if( n==1 ) return 1;
    return h(n-1) + 1.0/n;
}

int main(void) {
    int n;
    printf("Num? ");
    scanf("%d",&n);
    printf("Harmonica = %.2f\n",h(n));
    return 0;
}
