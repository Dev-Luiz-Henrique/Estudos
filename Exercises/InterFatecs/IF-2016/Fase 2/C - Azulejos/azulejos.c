#include <stdio.h>

int matrix[9][9]; // Matriz 9x9
int verify[10] = {0};

void clearVerify();
int checkHorizontal();
int checkVertical();
int checkSectors();

int main(){

    int num, count = 1, i, j;
    scanf("%d", &num); // Quantidade de matrizes

    while (count <= num){

        // Alimentar a matriz 9x9
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++)
                scanf("%d", &matrix[i][j]);
        }

        printf("Parede %d\n", count);
        count++;

        if(checkHorizontal() == 0){
            printf("NAO\n");
            continue;
        }
        if(checkVertical() == 0){
            printf("NAO\n");
            continue;
        }
        if(checkSectors() == 0){
            printf("NAO\n");
            continue;
        }
        printf("SIM\n");
    }
    return 0;
}

// Funcao para limpar o vetor de verificacao
void clearVerify(){
    int i;
    for(i = 0; i < 10; i++)
        verify[i] = 0;
}

// Funcao que verifica se ha mais de um azulejo igual na HORIZONTAL
int checkHorizontal(){
    int i, j, possible = 0;

    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            verify[matrix[i][j]]++;
            
            if (verify[matrix[i][j]] > 1){
                return 0; // Retorna imediatamente se um azulejo duplicado for encontrado
            }
        }
        clearVerify();
    }
    return 1;
}

// Funcao que verifica se ha mais de um azulejo igual na VERTICAL
int checkVertical(){
    int i, j, possible = 0;
    
    for (j = 0; j < 9; j++){
        for (i = 0; i < 9; i++){
            verify[matrix[i][j]]++;

            if (verify[matrix[i][j]] > 1) 
                return 0; // Retorna imediatamente se um azulejo duplicado for encontrado
        }
        clearVerify();
    }
    return 1;
}

// Verificar se ha mais de um azulejo igual em QUADRANTES 3x3
int checkSectors(){
    int i, j, k, possible = 0;

    for (i = 0; i < 9; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                verify[matrix[j + 3 * (i / 3)][k + 3 * (i % 3)]]++;

                if (verify[matrix[i * 3 + j][k * 3 + k]] > 1)
                    return 0;
            }
        }
        clearVerify();
    }
    return 1;
}