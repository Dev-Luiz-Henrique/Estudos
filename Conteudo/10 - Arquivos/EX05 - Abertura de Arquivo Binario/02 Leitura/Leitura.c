// Crie um programa que leia dados de um arquivo binario

#include <stdio.h>

int main() {
    FILE *arq;
    char dados[100];

    arq = fopen("CAD.dat", "rb"); // Abre o arquivo em modo de leitura binaria
    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    fread(&dados, sizeof(dados), 1, arq); // Le os dados do arquivo
    /* fread (param1, param2, param3, param4);

		param1: Ponteiro para a localizacao da memoria onde serao armazenados os dados lidos do arquivo. 
		param2: Numero inteiro que indica o tamanho do tipo de dado a ser lido.
		param3: Quantidade de itens a serem lidos, a cada chamada.
		param4: Ponteiro para a estrutura FILE do arquivo a ser lido.
	*/

    
    printf("Dados lidos: %s\n", dados);

    fclose(arq);

    return 0;
}
