// Escreva um progrma que calcule o IMC

# include <stdio.h>

int main (){
    float peso, altura, imc; // Declaracao de variaveis
    
    system ("cls"); // Limpa a tela
    
    // Solicita a altura e o peso
    printf ("\nDigite peso e altura:");
    scanf ("%f %f", &peso, &altura);
    
    // Cacula e exibe o IMC
    imc = peso / (altura * altura);
    printf ("\nIMC: %.2f", imc);
    return 0;	
}

