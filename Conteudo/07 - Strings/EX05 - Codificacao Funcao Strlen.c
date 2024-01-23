// Codifique a funcao strlen(s), que devolve o numero de caracteres armazenados na string s. 
// Lembre-se de que o terminador '\0' nao faz parte da string e, portanto, nao deve ser contado.

#include <stdio.h>
#include <string.h>

// Funcao strlen
int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char s[100];

	// Entrada de dados
    printf("Digite uma string: ");
    gets(s); // le a string do usuario

	// Calculo e exibicao do tamanho
    int tamanho = strlen(s);
    printf("Numero de caracteres na string '%s': %d\n", s, tamanho);
    return 0;
}
