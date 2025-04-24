// Crie a funcao recursiva palavras(c), que determina quantas palavras existem na cadeia de caracteres c (considere 
// que c contem apenas letras e espacos; que entre duas palavras consecutivas na cadeia c existe pelo menos um 
// espaco; e que pode haver um ou mais espacos tanto no comeco quanto no final da cadeia c). 
// Por exemplo, a chamada palavras(" Quantas palavras existem nesta cadeia ") deve devolver a resposta 5.

#include <stdio.h>

/*int palavras(char *c){
    if(c[0] == '\0') return 0;
    if(c[0] != ' ' && c[-1] == ' ') return 1 + palavras(c + 1);
    return palavras(c + 1);
}*/

int palavras(char *c){
    // A variavel static eh inicializada apenas uma vez e nao eh reinicializada a cada chamada da funcao
    static char ant = ' '; 

    if(c[0] == '\0') return 0;
    if(c[0] != ' ' && ant == ' ') {
        ant = c[0];
        return 1 + palavras(c + 1);
    }
    ant = c[0];
    return palavras(c + 1);
}

int main(){
    char c[] = " Quantas palavras existem nesta cadeia ";
    printf("%d", palavras(c));
    return 0;
}