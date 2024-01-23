// Escreva um programa que leia uma cadeia de caracteres e imprima a mesma de tras pra frente. 
// Sugestao: Utilize a funcao strlen() para saber o tamanho da frase.

#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];

	// Entrada de dados
    printf("Digite uma frase: ");
    gets(frase); // Captura a string

    printf("Frase Inversa:\n");
    int i;
    // Laco que se inicia com tamanho da string -1 (Remover o espaco que aperece) e 
	// percorre enquanto i for maior ou igual a 0, subtraindo 1 a cada volta
    for (i = strlen(frase) - 1; i >= 0; i--) {
        printf("%c", frase[i]);
    }
    return 0;
}
