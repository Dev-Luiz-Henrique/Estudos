// Altere o PROGRAMA abaixo para que alem de:
// Ler as 2 notas dos 10 alunos de uma turma
// Calcular e armazenar a media de cada aluno;
//
// Calcule tambem a media da turma;
// Ao final, imprima:
// A media de cada aluno;
// Se o aluno esta na media, acima ou abaixo

/* PROGRAMA
int main(){
    float A[10][3]; 
    int i, j;

    for (i=0; i<10; i++){     // Percorre linhas para digitação de notas
		for (j=0; j<2; j++){  // Percorre colunas 0 e 1 para ler notas

            printf ("Aluno %d - Nota %d", i+1 , j+1);          
            scanf ("%f", &A[i][j]);	       
        }     
        A[i][2] = (A[i][0] + A[i][1])/2; // Media da linha i
    }
    for (i=0; i<10; i++){ 	//Percorre linhas para impressão       
        printf("\n");       
        for(j=0; j<3; j++)  // Percorre colunas para cada linha i              
            printf("%.2f", A[i][j] "\t"); // Imprime as notas   
    }
	return 0;
}
*/

#include <stdio.h>

int main(){
    float A[10][3];
    int i, j;
    float mediaTurma = 0;

    for (i=0; i<10; i++){     // Percorre linhas para digitacao de notas
		for (j=0; j<2; j++){  // Percorre colunas 0 e 1 para ler notas

            printf ("Aluno %d - Nota %d: ", i+1 , j+1);          
            scanf ("%f", &A[i][j]);	       
        }     
        A[i][2] = (A[i][0] + A[i][1])/2; // Media da linha i
        mediaTurma += A[i][2];           // Adiciona a media da linha i na variavel
    }
    
    mediaTurma = mediaTurma / 10; // Divide a soma das medias pela quantia de alunos
	printf("\nMedia da Turma: %.2f\n", mediaTurma);
	printf("Aluno N:\tNota1\tNota2\tMedia\n");
	
    for (i=0; i<10; i++){ 	//Percorre linhas para impressao       
        printf("\nAluno %d:\t", i+1);       
        for(j=0; j<3; j++){  // Percorre colunas para cada linha i              
            printf("%.2f\t", A[i][j]); // Imprime as notas   
        }
        
        // Verifica se o aluno esta abaixo, acima ou na media
        if (A[i][2] == mediaTurma )
            printf("Aluno na media");
        else {
        	if (A[i][2] > mediaTurma)
                printf("Aluno acima da media");
            else
                printf("Aluno abaixo da media");
        }
    }
	return 0;
}
