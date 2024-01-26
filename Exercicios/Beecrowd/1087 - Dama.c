/*O jogo de xadrez possui varias pecas com movimentos curiosos: uma delas e a dama, que pode se mover qualquer quantidade de casas na mesma linha, 
na mesma coluna, ou em uma das duas diagonais, conforme exemplifica a figura abaixo:

O grande mestre de xadrez Kary Gasparov inventou um novo tipo de problema de xadrez: 
dada a posicao de uma dama em um tabuleiro de xadrez vazio (ou seja, um tabuleiro 8x8, com 64 casas), 
de quantos movimentos, no minimo, ela precisa para chegar em outra casa do tabuleiro?

Kary achou a solucao para alguns desses problemas, mas teve dificuldade com outros, 
e por isso pediu que voce escrevesse um programa que resolve esse tipo de problema.

Entrada 
A entrada contem varios casos de teste. A primeira e unica linha de cada caso de teste contem quatro inteiros X1, Y1, X2 e Y2 (1 <= X1, Y1, X2, Y2 <= 8). 
A dama comeca na casa de coordenadas (X1, Y1), e a casa de destino e a casa de coordenadas(X2, Y2). 
No tabuleiro, as colunas sao numeradas da esquerda para a direita de 1 a 8 e as linhas de cima para baixo tambem de 1 a 8. 
As coordenadas de uma casa na linha X e coluna Y sao (X, Y).

O final da entrada e indicado por uma linha contendo quatro zeros.

Saida 
Para cada caso de teste da entrada seu programa deve imprimir uma unica linha na saida, contendo um numero inteiro, 
indicando o menor numero de movimentos necessarios para a dama chegar em sua casa de destino.*/

#include <stdio.h>

int main() {
    int x1, x2, y1, y2;

    while(1) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;

        if(x1 == x2 && y1 == y2)
            printf("0\n");

        else if(x1 == x2 || y1 == y2 || x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2)
            printf("1\n");

        else 
            printf("2\n");
    }
    return 0;
}
