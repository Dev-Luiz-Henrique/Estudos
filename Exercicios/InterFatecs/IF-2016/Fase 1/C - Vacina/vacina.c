#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 16 // 15 + \0

int main(){
    char X[MAX_SIZE]; // Chikungunya
    char D[MAX_SIZE]; // Dengue
    char Z[MAX_SIZE]; // Zica
    int T; // Tamanho da subsequencia
    int count = 0; // Quantidade de repeticoes nas 3

    // Entradas com SCANF pois nao tem espacos " "
    scanf("%s", X);
    scanf("%s", D);
    scanf("%s", Z);
    scanf("%d", &T);
    int lenX = strlen(X), lenD = strlen(D), lenZ = strlen(Z); // Tamanho das strings

    int i, j, k;
    for(i = 0; i <= lenX - T; i++){ // Percorre a subsequencia ate o tamanho da string - tamanho da subsequencia (T)
        for(j = i;  j <= lenD - T; j++){ // Comeca a string no index i ate o seu tamnho - tamanho da subsequencia (T)

            // Se os T digitos atuais forem iguais
            if(strncmp(X+i, D+j, T) == 0){
                for(k = i; k <= lenZ - T; k++){ // Repete o que foi feito acima
                    
                    if(strncmp(X+i, Z+k, T) == 0)
                        count++; // Adiciona 1 na quantidade de repeticoes nas 3
                }
            }
        }
    } 
    printf("%d\n", count);
    return 0;
}
