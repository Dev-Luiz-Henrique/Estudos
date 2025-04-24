#include <stdio.h>
#include <string.h>

#define MAX 305

// Funcao que move o texto
void shift(char *str, int len) {
    char temp = str[0];
    for(int i = 0; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = temp;
}

int main() {
    int M, T, E;
    char text[MAX];

    while(scanf("%d %d", &M, &T) != EOF) {
        getchar(); // Consome o \n
        fgets(text, MAX, stdin);
        text[strcspn(text, "\n")] = 0; // Remove o \n
        scanf("%d", &E);

        // Move o texto para frente
        for(int i = 0; i < E % T; i++) // E % T para retirar as voltas completas
            shift(text, T);

        text[M] = '\0';
        printf("%s\n", text);
    }

    return 0;
}


