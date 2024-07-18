/*
    A corrida de lesmas e um esporte que cresceu muito nos ultimos anos, fazendo com que varias pessoas 
        dediquem suas vidas tentando capturar lesmas velozes, e treina-las para faturar milhoes em corridas pelo mundo. 
    Porem a tarefa de capturar lesmas velozes nao e uma tarefa muito facil, pois praticamente todas as lesmas 
        sao muito lentas. Cada lesma e classificada em um nivel dependendo de sua velocidade:

        Nivel 1: Se a velocidade e menor que 10 cm/h. 
        Nivel 2: Se a velocidade e maior ou igual a 10 cm/h e menor que 20 cm/h. 
        Nivel 3: Se a velocidade e maior ou igual a 20 cm/h.

    Sua tarefa e identificar qual nivel de velocidade da lesma mais veloz de um grupo de lesmas.

    Entrada 
        A entrada consiste de multiplos casos de teste, e cada um consiste em duas linhas: 
        A primeira linha contem um inteiro L (1 <= L <= 500) representando o numero de lesmas do grupo, 
        e a segunda linha contem L inteiros Vi (1 <= Vi <= 50) representando as velocidades de cada lesma do grupo.
        A entrada termina com o fim do arquivo (EOF).

    Saida 
        Para cada caso de teste, imprima uma unica linha indicando o nivel de velocidade da lesma mais veloz do grupo.
*/

#include <stdio.h>

int main() {
    int l, v, max, i;

    while (scanf("%d", &l) != EOF) {
        max = 0;
        for (i = 0; i < l; i++) {
            scanf("%d", &v);

            if (v > max)
                max = v;
        }

        if (max < 10)
            printf("1\n");
        else if (max < 20)
            printf("2\n");
        else
            printf("3\n");
    }
    return 0;
}
