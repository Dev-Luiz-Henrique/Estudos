#include <stdio.h>

int main(){
    int n, i;

    // "Mi-nha-mae-man-dou-eu-es-co-lher-es-te-da-qui-mas-co-mo-sou-de-so-be-di-en-te-vou-es-co-lher-es-te-da-qui" 
    // Corresponde a 31

    // Loop infinito
    while(1){
        scanf("%d", &n);
        if(n == -1) break; // Ler as entradas ate que seja digitado '-1'

        if(n > 31) 
            printf("31\n");
        else 
            printf("%d\n", 31 % n != 0 ? 31 % n : 31); // Se o resto da divisao for diferente de 0, imprime o resto, senao imprime 31.
    }
    return 0;
}