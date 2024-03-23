// Crie uma funcao que retorne se um numero eh um palindromo
// Ex: 12321 eh um palindromo, pois quando lido ao contrario permanece igual, assim como 123321

#include <stdio.h>

int eh_palindromo(int num) {
    int reverso = 0, x = num;
    while(x != 0) {
        reverso = reverso * 10 + x % 10;
        x /= 10;
    }
    return num == reverso;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if(eh_palindromo(num))
        printf("%d eh um palindromo.", num);
    else
        printf("%d nao eh um palindromo.", num);
    return 0;
}

