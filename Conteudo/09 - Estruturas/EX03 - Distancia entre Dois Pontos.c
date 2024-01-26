// Distancia entre dois pontos 

// Defina um tipo de estrutura nomeada para representar pontos no plano atraves de suas coordenadas cartesianas (x, y). 
// Em seguida, crie uma funcao para calcular a distancia entre dois pontos e codifique um programa para testar seu funcionamento. 

#include <stdio.h>
#include <math.h>

// Estrutura PONTO
typedef struct {
    float x;
    float y;
} PONTO;

// Funcao para calcular a distancia entre dois pontos
float distancia(PONTO p1, PONTO p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    // Declaracao de variaveis do tipo PONTO
    PONTO p1;
    PONTO p2;
    
    // Alimentando as variaveis do tipo PONTO
    printf("Digite o valor de X e Y do ponto 1: ");
    scanf("%f%f", &p1.x, &p1.y);
	printf("Digite o valor de X e Y do ponto 2: ");
    scanf("%f%f", &p2.x, &p2.y);
    
    // Exibir a distancia entre os pontos
    printf("Distancia entre os dois pontos: %.2f\n", distancia(p1, p2)); // Chamar a funcao distancia
    return 0;
}

