#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cost;
    int votes;
} Improvement;

// Funcao que compara os votos de duas melhorias, retorna o valor negativo se o voto de a for menor que o de b, 
// positivo se a for maior e zero se forem iguais
int compareVotes(const void *a, const void *b) {
    const Improvement *imp1 = (const Improvement *)a;
    const Improvement *imp2 = (const Improvement *)b;
    return imp2->votes - imp1->votes;
}

int main(){

    int n, totalMoney, numberImp, votesAnswered, i;
    Improvement *improvements = NULL;
    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &totalMoney, &numberImp); // Recebe o valor total de dinheiro e o numero de melhorias
        improvements = (Improvement *)malloc(numberImp * sizeof(Improvement)); // Aloca a memoria para o vetor de melhoria
        votesAnswered = 0; // Inicializa o numero de votos respondidos como zero

        // Para cada melhoria recebida, recebe o valor e os votos
        for(i = 0; i < numberImp; i++)
            scanf("%d %d", &improvements[i].cost, &improvements[i].votes);

        // Ordena o vetor de melhoria por ordem decrescente dos votos
        qsort(improvements, numberImp, sizeof(Improvement), compareVotes);

        for(i = 0; i < numberImp; i++){
            // Se o dinheiro atual for maior que o custo da melhoria, reduz o custo da melhoria do dinheiro atual e
            // adiciona o numero de votos da melhoria ao numero de votos respondidos
            if(totalMoney >= improvements[i].cost){
                totalMoney -= improvements[i].cost;
                votesAnswered += improvements[i].votes;
            }
        }

        if(votesAnswered == 0) printf("NO FUNDS\n");
        else                   printf("%d %d\n", votesAnswered, totalMoney);
        free(improvements);
    }
}