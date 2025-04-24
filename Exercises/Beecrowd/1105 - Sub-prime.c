/*
    A mais recente crise economica foi em parte causada pela forma como os bancos faziam emprestimos para pessoas 
        que nao tinham capacidade de honra-los e revendiam tais emprestimos para outros bancos (debentures). 
    Obviamente, quando as pessoas pararam de pagar os emprestimos, o sistema inteiro entrou em colapso.

    A crise foi tao profunda que acabou atingindo paises do mundo inteiro, inclusive a Nlogonia, onde o 
        honrado primeiro ministro Man Dashuva ordenou que o presidente do Banco Central procurasse uma solucao para o problema. 
    Esse, por sua vez, teve uma ideia brilhante: 
        se cada banco fosse capaz de liquidar seus emprestimos somente com suas reservas monetarias, 
        todos os bancos sobreviveriam e a crise seria evitada. 

    Entretanto, com o elevado numero de debentures e bancos envolvidos, essa tarefa e extremamente complicada, 
        e portanto ele pediu a sua ajuda para escrever um programa que, dados os bancos e as debentures emitidas, 
        determine se e possivel que todos os bancos paguem suas dividas, utilizando suas reservas monetarias e seus creditos.

    Entrada 
        A entrada contem varios casos de teste. A primeira linha de um caso de teste contem dois inteiros B e N, indicando 
            respectivamente o numero de bancos (1 <= B <= 20) e o numero de debentures emitidas pelos bancos (1 <= N <= 20). 
        Os bancos sao identificados por inteiros entre 1 e B. 
        
        A segunda linha contem B inteiros Ri separados por espacos, indicando as reservas monetarias de cada um dos 
            B bancos (0 <= Ri <= 10^4, para 1 <= i <= B). 
        
        As N linhas seguintes contem cada uma tres inteiros separados por espacos: um inteiro D, indicando o 
            banco devedor (1 <= D <= B), um inteiro C, indicando o banco credor (1 <= C <= B e D <=� C), 
            e um inteiro V, indicando o valor da debenture (1 <= V <= 10^4).

        O final da entrada e indicado por uma linha que contem apenas dois zeros, separados por um espaco em branco.

    Saida 
        Para caso de teste, seu programa deve imprimir uma unica linha, contendo um unico caractere: 'S', 
            se for possivel liquidar todos as debentures sem intervencao do Banco Central da Nlogonia, e 'N', 
            se algum banco precisar de emprestimos do governo para liquidar suas debentures.
*/

#include <stdio.h>
#define lmtBancos 21

int main(){
    int bancos, debentures;
    int *reservas = malloc(sizeof(int) * lmtBancos);
    int devedor, credor, valor;
    int sucesso; // Booleano

    while(1){
        scanf("%d %d", &bancos, &debentures);
        if(bancos == 0 && debentures == 0) break;
        
        for(int i = 1; i <= bancos; i++)
            scanf("%d", &reservas[i]);
    
        for(int i = 0; i < debentures; i++){
            scanf("%d %d %d", &devedor, &credor, &valor);
            reservas[devedor] -= valor;
            reservas[credor] += valor;
        }

        sucesso = 1;
        for(int i = 1; i <= bancos; i++){
            if(reservas[i] < 0){
                sucesso = 0;
                break;
            }
        }

        if(sucesso) printf("S\n");
        else printf("N\n");
    }
    free(reservas);
    return 0;
}
