// Codifique a funcao strdel(s, p) que remove o caracter na posicao p da string s. Dica: usar funcao strcpy().

#include <stdio.h>
#include <string.h>

// Funcao que deleta o caractere da posicao p
void strdel(char s[], int p) {

    if(p >= 0 && p < strlen(s)) {
        strcpy(&s[p], &s[p + 1]);
    }
}

// Teste pronto
int main() {
    char frase[150];
    int posicao;
    
    // Entrada de dados
    printf("Digite uma frase: ");
    gets(frase); // Le a string do usuario

    printf("\nDigite a posicao do caractere a ser deletado: ");
    scanf("%d", &posicao);

	printf("\n\n----------------------------------\n");
    printf("String Orginal:  %s\n", frase);
    strdel(frase, posicao);
    printf("String Alterada: %s\n", frase);
    return 0;
}
