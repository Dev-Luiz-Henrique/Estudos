#include <stdio.h>

// Funcao para calcular o Maximo Divisor Comum (MDC) usando o algoritmo de Euclides
int mdc(int a, int b){
    return b == 0 ? a : mdc(b, a % b);
}

// Funcao para calcular o Minimo Multiplo Comum (MMC) usando a formula a*b = mmc(a,b) * mdc(a,b)
int mmc(int a, int b){
    return a * b / mdc(a, b);
}

int main(){
    unsigned long long int trackSize;
    int competitors, i, r;

    // Loop para ler multiplos casos de teste ate o fim do arquivo (EOF)
    while(scanf("%llu %d", &trackSize, &competitors) != EOF){
        
        // Array para armazenar o tamanho do salto de cada competidor
        int jumpSize[competitors];
        for(i = 0; i < competitors; i++)
            scanf("%d", &jumpSize[i]);
        
        // Inicializa o resultado com o tamanho do salto do primeiro competidor
        r = jumpSize[0];

        // Calcula o MMC dos tamanhos de salto de todos os competidores
        for(i = 1; i < competitors; i++)
            r = mmc(r, jumpSize[i]);

        // Calcula a quantidade de blocos especiais, que sao os multiplos do MMC dos tamanhos de salto
        unsigned long long int specialBlocks = trackSize / r;

        // Imprime a quantidade de blocos especiais
        printf("%llu\n", specialBlocks);
    }

    return 0;
}
