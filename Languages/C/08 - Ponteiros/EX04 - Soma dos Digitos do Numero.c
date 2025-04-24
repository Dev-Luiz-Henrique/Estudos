// Codifique um programa que use ponteiros para calcular a soma dos digitos de um numero

#include <stdio.h>

void somaDigitos(int n, int* soma) {
    *soma = 0; // Acessa o valor apontado por 'soma' e atribui 0
    while(n != 0) { // Enquanto n for diferente de 0
        *soma += n % 10; // Acessa o valor apontado por 'soma' e adiciona o último dígito de n
        n /= 10; // Remove o último dígito de n
    }
}


int main() {
    int numero = 12345;
    int soma;
    
    somaDigitos(numero, &soma); // Chamada da funcao enviado o endereco das variaveis
    printf("A soma dos digitos de %d eh: %d\n", numero, soma);
    return 0;
}

