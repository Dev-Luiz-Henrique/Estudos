/*
    Todos devem conhecer o jogo Zerinho ou Um (em algumas regioes tambem conhecido como Dois ou Um), 
        utilizado para determinar um ganhador entre tres ou mais jogadores. 

    Para quem nao conhece, o jogo funciona da seguinte maneira. Cada jogador escolhe um valor entre zero ou um; 
        a um comando (geralmente um dos competidores anuncia em voz alta “Zerinho ou… Um!”), 
        todos os participantes mostram o valor escolhido, utilizando uma das maos: 
            se o valor escolhido foi um, o competidor mostra o dedo indicador estendido; se o valor escolhido foi zero, 
            mostra a mao com todos os dedos fechados. 
    
    O ganhador e aquele que tiver escolhido um valor diferente de todos os outros; 
        se nao ha um jogador com valor diferente de todos os outros (por exemplo todos os jogadores escolhem zero, 
        ou um grupo de jogadores escolhe zero e outro grupo escolhe um), nao ha ganhador. 

    Alice, Beto e Clara sao grandes amigos e jogam Zerinho a toda hora: para determinar quem vai comprar 
        a pipoca durante a sessao de cinema, quem vai entrar na piscina primeiro, etc. 
    Jogam tanto que resolveram fazer um plugin no Facebook para jogar Zerinho. Como nao sabem programar, 
        dividiram as tarefas entre amigos que sabem, inclusive voce. Dados os tres valores escolhidos 
        por Alice, Beto e Clara, cada valor zero ou um, escreva um programa que determina se ha um ganhador, 
        e nesse caso determina quem e o ganhador.

    Entrada 
        A entrada e composta por varios casos de teste. 
        Cada caso de teste consiste de uma unica linha, que contem tres inteiros A, B e C (A,B,C so podem ser 0 ou 1), 
            indicando respectivamente os valores escolhidos por Alice, Beto e Clara. O final da entrada e 
            determinado por EOF (End of File).

    Saida 
        Para cada caso de teste, seu programa deve produzir uma unica linha, contendo um unico caractere. 
        Se o vencedor e Alice o caractere deve ser 'A', se o vencedor e Beto o caractere deve ser 'B', 
            se o vencedor e Clara o caractere deve ser 'C' e se nao ha vencedor o caractere deve ser '*' (asterisco).
*/

#include <stdio.h>

int main(){
    int a, b, c;
    
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        if(a + b + c == 1){
            if(a == 1)  
                printf("A\n");
            if(b == 1)  
                printf("B\n");
            if(c == 1)  
                printf("C\n");
        }
        else if(a + b + c == 2){
            if(a == 0)  
                printf("A\n");
            if(b == 0)  
                printf("B\n");
            if(c == 0)  
                printf("C\n");
        }
        else           
            printf("*\n");
    }
    return 0;
}
