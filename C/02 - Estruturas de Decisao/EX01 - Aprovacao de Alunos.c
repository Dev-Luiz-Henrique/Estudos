// Crie um programa que leia 2 notas, calculo a media e 
// exiba se foi aprovado (MEDIA >= 6) ou reprovado

#include <stdio.h>

int main( ) {
   float a, b, m; // Declaracao de variaveis
   
   // Entrada de dados (Notas)
   printf ("\nInforme as duas notas obtidas: ");
   scanf ("%f %f", &a, &b);
   
   // Calculo da media
   m = (a+b)/2;
   
   // Estrutura de decisao (Aprovado ou Reprovado)
   if ( m >= 6.0 ) 
		printf ("\n Aprovado\n");
   else 	
		printf ("\n Reprovado\n");
   
   system("pause");
   return 0;
}

