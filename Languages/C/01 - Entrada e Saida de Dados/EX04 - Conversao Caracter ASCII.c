// Dado um caracter, informe seu código ASCII em octal, decimal e hexadecimal.

#include <stdio.h>

int main() {
    char c; // Declaracao de variavel
    
    // Entrada de dados (Caracter)
    printf ("\nDigite um caracter: ");
    scanf ("%c", &c);
    
    // Saida de dados
    printf ("\nDecimal: %d", c);      // Valor em decimal - %d eh um numero inteiro (Base 10)
    printf ("\nOctal: %o", c);        // Valor em octal - %o eh um numero em base 8
    printf ("\nHexadecimal: %x\n", c);  // Valor em hexadecimal - %x eh um numero em base 16
    system("pause");
    return 0;
}

