// Crie a funcao recursiva par(n), que determina se o natural n eh par, usando apenas subtracao

#include <stdio.h>

int par(int n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    return par(n-2);
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("O numero eh par? %s\n", par(n) ? "SIM" : "NAO");
    return 0;
}
