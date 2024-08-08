// Crie um programa em C que use uma union para armazenar e exibir diferentes tipos de dados
// Obs: uma union em C so pode armazenar um tipo de dado de cada vez, logo o valor da union sera o do ultimo membro armazenado

#include <stdio.h>
#include <string.h>

// Definindo a union
union Data {
   int i;
   float f;
   char str[20];
};

int main() {
   union Data data;

   // Armazenando um inteiro
   data.i = 10;
   printf("data.i: %d\n", data.i);

   // Armazenando um float
   data.f = 220.5;
   printf("data.f: %.2f\n", data.f);

   // Armazenando uma string
   strcpy(data.str, "C Programming");
   printf("data.str: %s\n", data.str);

   // Uma union pode ser usada para economizar memoria ao lidar com diferentes tipos de dados que nao precisam ser usados ao mesmo tempo,
   // sobreescrevendo e utilizando o ultimo membro armazenado apenas, logo o int desaparece quando float eh chamado no codigo.
   return 0;
}

