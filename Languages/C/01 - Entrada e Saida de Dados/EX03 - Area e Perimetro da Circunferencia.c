// Escreva um programa em C que leia o raio de uma circunferencia, 
// calcule sua área e perímetro e imprima na tela.

// Defina uma constante PI = 3,1415

#include <stdio.h>
#include <math.h>  // Biblioteca para calculos matematicos
#define PI 3.1415  // Declaracao de constante

int main() {
    float raio, area, perimetro; // Declaracao de variaveis
    
    // Entrada de dados (raio)
    printf ("\nDigite o raio: ");
    scanf ("%f", &raio);
    
    // Calculo do perimetro e da area
    perimetro = 2 * PI * raio;
    area = PI * pow (raio,2);
    printf ("Area: %.2f e perimetro: %.2f\n", area, perimetro); // Exibicao do resultado
    system("pause");
    return 0;
}


