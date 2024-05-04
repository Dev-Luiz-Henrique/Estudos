// Usando a funcao soma_digitos(), criada em um exercicio anterior, crie a funcao recursiva super_digito(n), que 
// devolve o super digito de um nimero natural n, computado como exemplificado a seguir: 
// super_digito(9875) = super_digito(29) = super_digito(11) = super_digito(2) = 2.

//  int soma_digitos(int n){
//       if(n == 0) return 0;
//        return (n % 10) + soma_digitos(n / 10);
//  } 

#include <stdio.h>

int soma_digitos(int n){
    if(n == 0) return 0;
    return (n % 10) + soma_digitos(n / 10);
}

int super_digito(int n){
    if(n < 10) return n;
    return super_digito(soma_digitos(n));
}

int main(){
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    printf("O super digito de %d eh %d\n", n, super_digito(n));
    return 0;
}
