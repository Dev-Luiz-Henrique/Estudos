// Crie a funcao recursiva pal(s,p,u), que informa se a string s, cujo primeiro caractere esta na
// posicao p e cujo ultimo caractere está na posicao u, eh palíndroma (ignorando brancos)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pal(char *s, int p, int u){

    if(p >= u) return 1;
    if(s[p] == ' ') return pal(s, p+1, u); 
    if(s[u] == ' ') return pal(s, p, u-1); 
    if(tolower(s[p]) != tolower(s[u])) return 0;
    return pal(s, p+1, u-1);
}

int main(){
    char s[100];                                     
    printf("Digite a string: ");
    gets(s);
    printf("A string eh palindorma? %s", pal(s, 0, strlen(s)-1) ? "SIM" : "NAO");
    return 0;
}
