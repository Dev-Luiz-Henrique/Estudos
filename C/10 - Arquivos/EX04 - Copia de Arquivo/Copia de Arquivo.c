// Escreva um programa que faça a copia do conteudo de um arquivo para outro
// Solicite ao usuario o nome do arquivo origem e do arquivo destino

#include <stdio.h>

int main() {
    FILE *arqOrigem, *arqDestino;
    char nomeArqOrigem[100], nomeArqDestino[100];
    char ch;

    // Solicita ao usuario o nome do arquivo de origem
    printf("Digite o nome do arquivo de origem: ");
    gets(nomeArqOrigem);

    // Solicita ao usuario o nome do arquivo de destino
    printf("Digite o nome do arquivo de destino: ");
    gets(nomeArqDestino);

    // Abre o arquivo de origem
    arqOrigem = fopen(nomeArqOrigem, "r");
    if (arqOrigem == NULL) {
        printf("Nao foi possivel abrir o arquivo de origem!\n");
        return 1;
    }

    // Abre o arquivo de destino
    arqDestino = fopen(nomeArqDestino, "w");
    if (arqDestino == NULL) {
        printf("Nao foi possivel abrir o arquivo de destino!\n");
        fclose(arqOrigem);
        return 1;
    }

    // Copia o conteudo do arquivo de origem para o arquivo de destino
    while ((ch = fgetc(arqOrigem)) != EOF)
        fputc(ch, arqDestino);

    printf("Arquivo copiado com sucesso.\n");

    // Fecha os arquivos
    fclose(arqOrigem);
    fclose(arqDestino);

    return 0;
}

