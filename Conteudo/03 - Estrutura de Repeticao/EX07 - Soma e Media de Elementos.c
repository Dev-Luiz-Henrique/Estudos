// Faca um programa que solicite um valor N e, em seguida, solicite N elementos
// Some todos elementos e exiba o total e sua media

#include<stdio.h>
#include<stdlib.h>

int main() {
  int N, i;
  double X, Total, Media;
  
  do {
    printf("Digite um inteiro: ");
    scanf("%d", &N);
  } while (N <= 1);
  
  Total = 0;
  for (i = 0; i < N; i++) {
    printf("Digite o elemento %d: ", i);
    scanf("%lf", &X);
    Total = Total + X; 
  }
  printf("\n\nTotal = %.3lf", Total);
  Media = Total / N;
  printf("\nMedia = %.3lf", Media);

  printf("\n\nFim do Programa\n");
  return 0;
}






