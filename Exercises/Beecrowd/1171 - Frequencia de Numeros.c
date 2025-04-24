/*
    Neste problema sua tarefa sera ler varios numeros e em seguida dizer quantas vezes cada numero aparece 
        na entrada de dados, ou seja, deve-se escrever cada um dos valores distintos que aparecem na entrada 
        por ordem crescente de valor.

    Entrada 
        A entrada contem apenas 1 caso de teste. A primeira linha de entrada contem um unico inteiro N, 
            que indica a quantidade de valores que serao lidos para X (1 <= X <= 2000) logo em seguida. 
        Com certeza cada numero nao aparecera mais do que 20 vezes na entrada de dados.

    Saida 
        Imprima a saida de acordo com o exemplo fornecido abaixo, indicando quantas vezes cada um deles aparece 
            na entrada por ordem crescente de valor.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, x;
    int contagem[2001] = {0}; 
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        contagem[x]++;
    }

    for (i = 1; i <= 2000; i++) {
        if (contagem[i] > 0)
            printf("%d aparece %d vez(es)\n", i, contagem[i]);
    }
    return 0;
}
