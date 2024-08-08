// Crie um programa que represente uma leitura de temperatura que pode ser expressa em graus Celsius ou Fahrenheit. 
// Dica: usar uma union dentro de uma struct.

#include <stdio.h>

// Definindo a union
union Temperatura {
   float celsius;
   float fahrenheit;
};

// Definindo a struct
struct Leitura {
    union Temperatura temperatura;
    char escala;
};

int main() {
   struct Leitura leitura;

   // Armazenando uma temperatura em Celsius
   leitura.temperatura.celsius = 25.0;
   leitura.escala = 'C';
   if (leitura.escala == 'C')
       printf("Temperatura: %.2f graus Celsius\n", leitura.temperatura.celsius);

   // Armazenando uma temperatura em Fahrenheit
   leitura.temperatura.fahrenheit = 77.0;
   leitura.escala = 'F';
   if (leitura.escala == 'F')
       printf("Temperatura: %.2f graus Fahrenheit\n", leitura.temperatura.fahrenheit);

   return 0;
}

