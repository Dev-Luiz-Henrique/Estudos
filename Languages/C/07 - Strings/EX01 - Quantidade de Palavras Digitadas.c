// Escreva um programa que leia uma frase, conte e exiba a quantidade de palavras digitadas.

#include <stdio.h>
#include <string.h>

int main() {
    char frase[500];
    int contagem = 0;

	// Solicita a entrada de uma string
    printf("Digite uma frase: ");
    gets(frase); // Captura a string

	// Realiza a contagem 
    int i;
    for (i = 0; frase[i] != '\0'; i++) {    // O final da String sempre eh \0
        if (frase[i] == ' ' && frase[i+1] != ' ')
            contagem++;
    }

    printf("Quantidade de palavras digitadas: %d\n", contagem + 1); 
    // Adiciona 1 pois o programa conta espacos em branco, nao as palavras em si
    return 0;
}
