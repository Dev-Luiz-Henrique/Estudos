#include <stdio.h>
#include <math.h>

int main(){

    int lines, columns, dataSize, i, j, k, count = 1;
    double pixels, sum;
    char direction;
    
    while(scanf("%d %d", &lines, &columns) != EOF){
        pixels = 0;

        // Cria e alimenta a matriz com os dados
        char matrix[lines][columns]; 
        for(i = 0; i < lines; i++){ 
            for(j = 0; j < columns; j++){ 
                scanf(" %c", &matrix[i][j]);

                if(matrix[i][j] == '1')
                    pixels++; // Soma de todos os pixels nao transparentes do grafico (0 e 1)
            }
        }

        // Pega a direcao e o tamanho do setor do grafico
        scanf(" %c", &direction);
        getchar();
        scanf("%d", &dataSize);

        // Pega os dados do setor e cria o vetor de dados de cada setor do grafico
        int sectorData[dataSize];
        sum = 0;
        for(i = 0; i < dataSize; i++){
            scanf("%d", &sectorData[i]);

            sum+=sectorData[i]; // Soma de todos os dados do setor
        }

        // Tamanho de cada setor do grafico
        int sectorSize[dataSize];
        for(i = 0; i < dataSize; i++)
            sectorSize[i] = (int)floor((sectorData[i] / sum) * pixels); // Tamanho de cada setor do grafico 
        
        // Cria a matriz do grafico
        if(direction == 'H') // Grafico Horizontal
        {   
            k = 1;
            for (i = 0; i < lines; i++){
                for (j = 0; j < columns; j++){
                    if(matrix[i][j] == '1'){
                        
                        if(dataSize-1 != k-1){
                            if(sectorSize[k-1] == 0)
                                k++;
                    
                            sectorSize[k-1]--;
                        }
                        matrix[i][j] = '0' + k;
                    }
                }
            }
        }

        else // Grafico Vertical
        {
            k = 1;
            for (j = 0; j < columns; j++){
                for(i = 0; i < lines; i++){
                    if(matrix[i][j] == '1'){
                        
                        if(dataSize-1 != k-1){
                            if(sectorSize[k-1] == 0)
                                k++;
                    
                            sectorSize[k-1]--;
                        }
                        matrix[i][j] = '0' + k;
                    }
                }
            }
        }

        // Exibicao da matriz
        printf("Caso %d:\n", count);
        for (i = 0; i < lines; i++){
            for(j = 0; j < columns; j++)
                printf("%c", matrix[i][j]);
            printf("\n");
        }
        count++;
    }
    return 0;
}
