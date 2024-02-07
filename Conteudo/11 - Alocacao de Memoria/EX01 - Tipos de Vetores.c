// Faca um programa que exiba os tipos de Vetores em C
// Alimente os vetores com valores aleatorios

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int i;
  int N; // Usado como tamanho para o vetor dinamico restrito
  int Q; // Usado como tamanho para o vetor dinamico amplo
  
  int Ve[10];  // Vetor estatico - tamanho fixo
/*int Vdr[N];  // Vetor dinamico restrito - tamanho e variavel com limitacoes - 
                  esse vetor precisa ser declarado APOS a leitura de N e nao aqui, por isso esta linha esta comentada*/
  int *Vda;    // Vetor dinamico amplo - tamanho e variável e o limite e a memória do computador

  // Usar a semente com o horario do computador, para que os valores nao se repitam toda vez que rodar o codigo
  srand(time(NULL)); // Pode receber qualque valor numerico como semente, entretant pode haver repeticoes
   
  //
  // Carga de dados no vetor Ve  
  //
  for(i = 0; i < 10; i++)
    Ve[i] = rand() % 1000;
    
  printf("Exibicao do vetor estatico\n");
  for(i = 0; i < 10; i++)
    printf("  elemento %d = %d\n", i, Ve[i]);
  
  //
  // Carga de dados no vetor Vdr
  //
  printf("\n\nDigite N: ");
  scanf("%d", &N);
  int Vdr[N];  // Vetor dinamico restrito - tamanho variavel com limitacoes - criado no Stack (pilha do programa - que tem tamanho limitado)
  for(i = 0; i < N; i++)
    Vdr[i] = rand() % 1000; 

  printf("Exibicao do vetor dinamico restrito\n");
  for(i = 0; i < N; i++)
    printf("  elemento %d = %d\n", i, Vdr[i]);

  //
  // Carga de dados no vetor Vda
  //
  printf("\n\nDigite Q: ");
  scanf("%d", &Q);
  // malloc = memory allocation
  Vda = (int *)malloc(sizeof(int) * Q);  // Sizeof retorna o tamanho em bytes do tipo da variavel, 4 bytes no caso
  for(i = 0; i < Q; i++)
    Vda[i] = rand() % 1000; 

  printf("Exibicao do vetor dinamico amplo\n");
  for(i = 0; i < Q; i++)
    printf("  elemento %d = %d\n", i, Vda[i]);
    
  free(Vda); // lIBERA A MEMORIA ALOCADA
  // NAO ESQUECER, pode travar o computador (Leak error)
  
  printf("\n\nFim do Programa\n");
  return 0;
}
