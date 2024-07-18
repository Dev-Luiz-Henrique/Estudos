/*
    Leia quatro numeros (N1, N2, N3, N4), cada um deles com uma casa decimal, correspondente as quatro notas de um aluno.
    Calcule a media com pesos 2, 3, 4 e 1, respectivamente, para cada uma destas notas e mostre esta 
        media acompanhada pela mensagem "Media: ".
        
        Se esta media for maior ou igual a 7.0, imprima a mensagem "Aluno aprovado.".
        Se a media calculada for inferior a 5.0, imprima a mensagem "Aluno reprovado.".
        Se a media calculada for um valor entre 5.0 e 6.9, inclusive estas, o programa deve imprimir a mensagem "Aluno em exame.".

    No caso do aluno estar em exame, leia um valor correspondente a nota do exame obtida pelo aluno.
        Imprima entao a mensagem "Nota do exame: " acompanhada pela nota digitada.

    Recalcule a media (some a pontuacao do exame com a media anteriormente calculada e divida por 2).
        e imprima a mensagem "Aluno aprovado." (caso a media final seja 5.0 ou mais ) 
        ou "Aluno reprovado.", (caso a media tenha ficado 4.9 ou menos).

    Para estes dois casos (aprovado ou reprovado apos ter pego exame) apresente na ultima linha uma mensagem "Media final: " 
        seguido da media final para esse aluno.
*/

#include <stdio.h>

int main(){
    double n1, n2, n3, n4, media;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    scanf("%lf", &n4);

    media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4 * 1)) / 10;
    printf("Media: %.1lf\n", media);

    if (media >= 7.0)
        printf("Aluno aprovado.\n");

    else{
        if (media >= 5.0 && media < 7.0){
            printf("Aluno em exame.\n");

            double notaExame;
            scanf("%lf", &notaExame);
            printf("Nota do exame: %.1lf\n", notaExame);
            media = (media + notaExame) / 2;

            if (media >= 5.0)
                printf("Aluno aprovado.\n");
            else
                printf("Aluno reprovado.\n");

            printf("Media final: %.1lf\n", media);
        }
        else
            printf("Aluno reprovado.\n");
    }
    return 0;
}