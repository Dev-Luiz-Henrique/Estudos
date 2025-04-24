// Criar um programa que calcule a serie de Fibonacci ate um numero n
// Dica: Utilize o laco for

#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, proximoTermo;

    printf("Digite o numero de termos: ");
    scanf("%d", &n);

    printf("Serie de Fibonacci: ");
	// Estrutura de repitacao
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
    }
    return 0;
}
