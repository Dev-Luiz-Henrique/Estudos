// Dado o seguinte programa, codifique as rotinas
//   obtem() -> obtem as temperaturas de cada dia da semana
//   media() -> calcula a media da temperatura da semana
//   conta() -> quantos dias estao acima da media

// #include <stdio.h>
// #define max 7
// int main() {
//       float temp[max], m;
//       obtem(temp, max);
//       m = media(temp, max);
//       printf("Estatistica: %d", conta(temp, max, m) );
//       return 0;
// }

#include <stdio.h>
#define max 7

// Funcao obtem() -> obtem as temperaturas de cada dia da semana
void obtem(float temp[], int tamanho){

    printf("Digite as temperaturas de segunda a domingo:\n");

    // Socilita as temperaturas e armazena no vetor
    for (int i = 0; i < tamanho; i++){
        printf("\nDigite a temperatura do dia %d: ", i + 1);
        scanf("%f", &temp[i]);
    }
}

// Funcao media() -> calcula a media da temperatura da semana
float media(float temp[], int limite){

    int contador = 0;
    float soma = 0;

    // Soma as temperaturas e divide pelo numero de dias da semana
    while (contador < limite){
        soma += temp[contador];
        contador++;
    }
    return soma / contador;
}

// Funcao conta() -> conta quantos dias estao acima da media
int conta(float temp[], int limite, float media){

    int ctAcimaMedia = 0;
    for (int i = 0; i < limite; i++){
        if (temp[i] > media)
            ctAcimaMedia++;
    }
    return ctAcimaMedia;
}

int main(){
    float temp[max], m;

    // Chama as funcoes e armazena o resultado em variaveis
    obtem(temp, max);
    m = media(temp, max);
    printf("Estatistica: %d", conta(temp, max, m));
    return 0;
}
