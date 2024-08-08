// Faca um programa que solicite um numero e exiba o correspondente ASCII do mesmo

#include<stdio.h>
#include<stdlib.h>

int main() {
  int x;
  
  printf("Digite x: ");
  scanf("%d", &x);
  
  // Estrutura de repeticao
  while (x != 0) {  
    printf("O numero %d corresponde ao caractere %c\n", x, char(x));

    printf("Digite x: ");
    scanf("%d", &x);
  }

  printf("\n\nFim do Programa\n");
  return 0;
}
