// Faca um programa que verifique se um numero eh primo
// Sugestao: usar um laco for com break

#include <stdio.h>

int main() {
    int num, i;
    int eh_primo = 1; // Assume o numero como primo inicialmente

    printf("Digite um numero: ");
    scanf("%d", &num);

	// Estrutura de repeticao
    for(i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            eh_primo = 0; // Se numero divisivel por i, entao nao e primo
            break; // Sai do loop assim que encontra um divisor
        }
    }

    if(eh_primo && num > 1) 
        printf("%d eh um numero primo\n", num);
    else 
        printf("%d nao eh um numero primo\n", num);

    return 0;
}

