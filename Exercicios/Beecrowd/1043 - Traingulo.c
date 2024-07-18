/*
    Leia 3 valores reais (A, B e C) e verifique se eles formam ou nao um triangulo.
    Em caso positivo, calcule o perimetro do triangulo e apresente a mensagem:
        Perimetro = XX.X

    Em caso negativo, calcule a area do trapezio que tem A e B como base e C como altura, mostrando a mensagem
        Area = XX.X

    Entrada
        A entrada contem tres valores reais.

    Saida
        O resultado deve ser apresentado com uma casa decimal.
*/

#include <stdio.h>

int main(){
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    if (a < b + c && b < a + c && c < a + b){
        float perimetro = a + b + c;
        printf("Perimetro = %.1f\n", perimetro);
    }
    else{
        float area = ((a + b) * c) / 2;
        printf("Area = %.1f\n", area);
    }
    return 0;
}