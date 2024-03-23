// Crie uma funcao que retorne se um numero eh primo

#include <stdio.h>

// Funcao que verifica se um numero eh primo
int eh_primo(int num) {
    if(num <= 1) return 0; // Se for menor que 1 nao eh primo
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return 0;  // Se tiver um divisor, nao eh primo
    return 1;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if(eh_primo(num))
        printf("%d eh primo.", num);
    else
        printf("%d nao eh primo.", num);
    return 0;
}
