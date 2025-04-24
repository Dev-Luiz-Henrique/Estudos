// Crie a funcao recursiva quoc(m,n), que devolve o quociente da divisao inteira do numero natural m pelo numero natural n !=0, 
// usando apenas soma e subtracao.

#include <stdio.h>

int quoc(int m, int n){
    if(m < n) return 0;
    return 1 + quoc(m - n, n);
}

int main() {
    int m, n;
    printf("Digite o dividendo: ");
    scanf("%d", &m);
    printf("Digite o divisor: ");
    scanf("%d", &n);

    printf("O quociente da divisao de %d por %d eh: %d\n", m, n, quoc(m, n));
    return 0;
}
