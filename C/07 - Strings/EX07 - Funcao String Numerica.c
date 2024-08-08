// Crie uma funcao que retorne 1 caso a string s seja formada somente por caracteres numericos, ou 0, caso contrario

#include <stdio.h>
#include <string.h>

// Funcao que verifica se a string eh numerica
int isNumStr(char *s) {
	
    while (*s) {
    	
        if (*s < '0' || *s > '9')
            return 0;
        s++;
    }
    return 1;
}

int main( ){
    char s[100];           
	
	// Entrada de dados
    printf("\nDigite uma string qualquer: ");
    gets(s);    
    
    // Verificacao e exibicao
    if (isNumStr(s) == 1)
       printf("\nString numerica.");
    else
       printf("\nString nao numerica.");
       
	return 0;
}

