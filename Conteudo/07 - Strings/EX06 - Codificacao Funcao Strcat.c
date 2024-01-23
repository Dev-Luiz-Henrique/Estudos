// Codifique a funcao strcat(s,t), que concatena a string t ao final da string s. 
// Por exemplo, se x armazena "facil" e y armazena "idade", apos a chamada strcat(x,y), x estara armazenando "facilidade".

#include <stdio.h>
#include <string.h>

void strcat(char *s, char *t) {
    
    while(*s != '\0') {
        s++;
    }

    while(*t != '\0') {
        *s = *t;
        s++;
        t++;
    }
    
    *s = '\0';
}

int main() {
	
	char str1[256];
    char str2[256];

	// Entrada de dados
    printf("Digite a primeira string: ");
    gets(str1);

    printf("Digite a segunda string: ");
    gets(str2);

    strcat(str1, str2); // Chama a funcao que concatena as strings
    printf("%s\n", str1);
    return 0;
}
