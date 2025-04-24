// Crie a funcao recursiva inv(s,p,u), que inverte a string s, cujo primeiro caractere esta na
// posicao p e cujo ultimo caractere está na posicao u. A funcao deve devolver s como resposta

#include <stdio.h>
#include <string.h>

char *inv(char s[], int p, int u){
	
    if(p >= u) return s;

    char aux = s[p];
    s[p] = s[u];
    s[u] = aux;
    return inv(s, p+1, u-1);
}

int main(){
    char s[100];                                     
    printf("Digite a string: ");
    gets(s);
    printf("String invertida: %s", inv(s, 0, strlen(s)-1));
    return 0;
}
