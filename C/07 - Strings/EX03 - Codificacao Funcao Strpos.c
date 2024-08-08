// Codifique a funcao strpos(s, c) que devolve a posicao da primeira ocorrencia do caracter c na string s; 
// ou -1, caso c nao exista em s.

#include <stdio.h>
#include <string.h>

// Funcao strpos
int strpos(char s[], char c) {
    
    int i;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == c) 
            return i;
    }
    return -1;
}

int main( ){
    char s[100];     
	char c;        
	int i;
	
    printf("Digite uma frase: ");
    gets(s); // Captura a string
    
    printf("\nQual caracter deseja procurar? ");
    c = getchar(); // Captura o caractere
    
    i = strpos(s, c); // Chama a funcao strpos
    
    if (i != -1)
       printf("\nCaracter na posicao %d.", i+1);
    else
       printf("\nCaracter nao encontrado.");
	return 0;
}

