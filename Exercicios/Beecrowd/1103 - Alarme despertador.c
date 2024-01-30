/*Daniela e enfermeira em um grande hospital, e tem os horarios de trabalho muito variaveis. Para piorar, ela tem sono pesado, 
e uma grande dificuldade para acordar com relogios despertadores.

Recentemente ela ganhou de presente um relogio digital, com alarme com varios tons, e tem esperanca que isso resolva o seu problema. 
No entanto, ela anda muito cansada e quer aproveitar cada momento de descanso. Por isso, carrega seu relogio digital despertador para todos os lugares, 
e sempre que tem um tempo de descanso procura dormir, programando o alarme despertador para a hora em que tem que acordar. 
No entanto, com tanta ansiedade para dormir, acaba tendo dificuldades para adormecer e aproveitar o descanso.

Um problema que a tem atormentado na hora de dormir e saber quantos minutos ela teria de sono se adormecesse imediatamente 
e acordasse somente quando o despertador tocasse. Mas ela realmente nao e muito boa com numeros, e pediu sua ajuda para escrever um programa que, 
dada a hora corrente e a hora do alarme, determine o numero de minutos que ela poderia dormir.

Entrada 
A entrada contem varios casos de teste. Cada caso de teste e descrito em uma linha, contendo quatro numeros inteiros H 1 , M 1 , H2 e M 2, 
com H1:M1 representando a hora e minuto atuais, e H2:M2 representando a hora e minuto para os quais o alarme despertador foi programado 
(0<=H1<=23, 0<=M1<=59, 0<=H2<=23, 0<=M2<=59).

O final da entrada e indicado por uma linha que contem apenas quatro zeros, separados por espacos em branco.

Saida 
Para cada caso de teste da entrada seu programa deve imprimir uma linha, cada uma contendo um numero inteiro, 
indicando o numero de minutos que Daniela tem para dormir.*/

#include <stdio.h>

int main(){
	int h1, m1, h2, m2;
    int totMin1, totMin2;
	
    while(1){
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        totMin1 = h1 * 60 + m1;
        totMin2 = h2 * 60 + m2;

        if(totMin2 < totMin1) totMin2 += 24 * 60;
        
        printf("%d\n", totMin2 - totMin1);
    }
	return 0;
}
