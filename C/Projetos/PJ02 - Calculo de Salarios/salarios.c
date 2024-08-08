#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double salBruto;
  double aliqINSS;
  double valINSS;
  double baseIR;
  double aliqIR;
  double valIR;
  double salLiquido;
} Dados;

double calcAliqINSS (double salBruto){

    if (salBruto <= 1751.81)
        return 0.08;
    else if (salBruto <= 2919.72)
        return 0.09;
    else if (salBruto <= 5839.45)
        return 0.11;
    else
        return 0;
}

double calcAliqIR (double baseIR){

    if (baseIR <= 1903.98)
        return 0 ;
    else if (baseIR <= 2826.65)
        return 0.075;
    else if (baseIR <= 3751.05)
        return 0.15;
    else if (baseIR <= 4664.68)
        return 0.225;
    else if (baseIR > 4664.68)
        return 0.275;
}

double calcValIR (double baseIR, double aliqIR) {

    // valIR = (salBruto - valINSS) * aliqIR - deducaoIR 
    // baseIR = salBruto - valINSS

    if (baseIR <= 1903.98)
        return baseIR * aliqIR - 0;
    else if (baseIR <= 2826.65)
        return baseIR * aliqIR - 142.80;
    else if (baseIR <= 3751.05)
        return baseIR * aliqIR - 354.80;
    else if (baseIR <= 4664.68)
        return baseIR * aliqIR - 636.13;
    else
        return baseIR * aliqIR - 869.36;
}

void bubbleSort(Dados *V, int tam) {
    int trocou = 1, i;
	Dados aux;

    while (trocou == 1) {
        trocou = 0;
        for (i = 0; i < tam-1; i++) {
            if (V[i].salBruto > V[i+1].salBruto) {
                aux = V[i+1];
                V[i+1] = V[i];
                V[i] = aux;
                trocou = 1;
            }
        }
    }
}

int main () {

    // Exibicao do grupo
    printf("\t\tCalculo de Salarios\n");
    printf("Luiz Henrique de Santana  - RA: 0000000000000\n");
    printf("Nicole Carvalho Fukushima - RA: 0000000000000\n");
    printf("---------------------------------------------\n\n\n");

    // Declaracao de variaveis
    int tam = 0, i = 0;
    FILE *arqEnt;
    FILE *arqSai;
    double salEnt;
    Dados *d;

    // Leitura dos dados do arquivo
    arqEnt = fopen ("salario.txt", "r");
    while (fscanf(arqEnt, "%lf\n", &salEnt) != EOF) {
        
        // Alocacao dinamica de memoria
        tam++;
        d = (Dados *)realloc(d, sizeof(Dados) * tam);

        // Armazenamento dos dados no vetor
        d[i].salBruto = salEnt;
        d[i].aliqINSS = calcAliqINSS(salEnt);
        d[i].valINSS = d[i].aliqINSS > 0 ? d[i].salBruto * d[i].aliqINSS : 642.34; // Se aliqINSS < 0, atribui o valor de 642.34
        d[i].baseIR = d[i].salBruto - d[i].valINSS;
        d[i].aliqIR = calcAliqIR(d[i].baseIR);
        d[i].valIR = calcValIR(d[i].baseIR, d[i].aliqIR);
        d[i].salLiquido = d[i].salBruto - d[i].valINSS - d[i].valIR;
        i++;
    }
    fclose(arqEnt);

    bubbleSort(d, tam);

    // Gravacao dos dados
    arqSai = fopen("calculos.txt", "w");
    fprintf(arqSai, "   Bruto     AliqINSS    Val.INSS    Base I.R.   AliqIR     Val.IR      Liquido\n");
    for(i = 0; i < tam; i++){
        fprintf(arqSai, "%9.2lf       %4.1lf     %8.2lf    %8.2lf     %5.2lf   %8.2lf    %9.2lf\n", d[i].salBruto, d[i].aliqINSS * 100, d[i].valINSS, d[i].baseIR, d[i].aliqIR * 100, d[i].valIR, d[i].salLiquido);
    }
    fclose(arqSai);  

    free(d);
    return 0;
}
