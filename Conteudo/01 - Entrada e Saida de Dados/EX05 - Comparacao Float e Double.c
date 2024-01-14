// Crie um programa que exiba um valor de um float e um double
// Analise a diferenca de precisao decimal

#include<stdio.h>
#include<stdlib.h>

int main() {
  float F;
  double D;
  
  printf("Digite um valor para float: ");
  scanf("%f", &F);  
  printf("Digite um valor para double: ");
  scanf("%lf", &D);  

  printf("\n  float F  = %.18f\n", F);
  printf("  double D = %.18f\n", D);
  
  printf("\n\nFim do Programa\n");
  return 0;
}
