// Crie uma funcao que some os digitos de um numero n

#include <stdio.h>

// Funcao que soma os digitos de um numero
int soma_digitos(int num) {
    int soma = 0;
    while(num != 0) {
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
	printf("Soma dos digitos de %d = %d", num, soma_digitos(num));
    return 0;
}
