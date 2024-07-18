/*
    Neste problema voce devera ler 15 valores coloca-los em 2 vetores conforme estes valores forem pares ou impares. 
    
    So que o tamanho de cada um dos dois vetores e de 5 posicoes. Entao, cada vez que um dos dois vetores encher, 
        voce devera imprimir todo o vetor e utiliza-lo novamente para os proximos numeros que forem lidos. 
    
    Terminada a leitura, deve-se imprimir o conteudo que restou em cada um dos dois vetores, imprimindo primeiro os 
        valores do vetor impar. 
    Cada vetor pode ser preenchido tantas vezes quantas for necessario.

    Entrada 
        A entrada contem 15 numeros inteiros.

    Saida 
        Imprima a saida conforme o exemplo abaixo.
*/

#include <stdio.h>
#define maxVet 5
#define numEnt 15

void exibeVetor(int *v){
    if(v[0] % 2 == 0){
        for(int i=0; i < maxVet; i++){
        	if(v[i] == 0) break;
        	
            printf("par[%d] = %d\n", i, v[i]);
            v[i] = 0;
        }
    }
    else {
        for(int i=0; i < maxVet; i++){
        	if(v[i] == 0) break;
        	
            printf("impar[%d] = %d\n", i, v[i]);
            v[i] = 0;
        }
    }
}

int main(){
    int *vPar, *vImpar;
    int iPar = 0, iImpar = 0;
    int n;

    vPar = malloc(sizeof(int) * maxVet);
    vImpar = malloc(sizeof(int) * maxVet);

    for(int i=0; i < numEnt; i++){
        scanf("%d", &n);

        if (n%2 == 0){
            vPar[iPar] = n;
            iPar++;
            if (iPar == maxVet){
                exibeVetor(vPar);
                iPar = 0;
            }
        }
        else{
            vImpar[iImpar] = n;
            iImpar++;
            if (iImpar == maxVet){
                exibeVetor(vImpar);
                iImpar = 0;
            }
        }
    }
    if (iImpar > 0)
        exibeVetor(vImpar);
    if (iPar > 0)
        exibeVetor(vPar);

    free(vPar);
    free(vImpar);
    return 0;
}
