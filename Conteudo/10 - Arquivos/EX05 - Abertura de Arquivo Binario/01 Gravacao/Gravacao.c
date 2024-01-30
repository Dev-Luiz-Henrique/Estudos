// Crie um programa que grave dados em um arquivo binario

#include <stdio.h>

int main() {
    FILE *arq;
    char dados[] = "Luiz Henrique de Santana";

    arq = fopen("CAD.dat", "wb"); // Abertura de arquivo em modo de gravacao binaria
    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    fwrite(&dados, sizeof(dados), 1, arq); // Grava os dados no arquivo
    /* fwrite (param1, param2, param3, param4);
    
		param1: Ponteiro que aponta para a localizacao da memoria do dado a ser gravado.
		param2: Numero inteiro que indica o tamanho do tipo de dado a ser gravado. Geralmente, utilizamos o operador sizeof() que retorna o tamanho do registro. 
		param3: Quantidade de itens a serem gravados.
		param4: Ponteiro para a estrutura FILE do arquivo onde queremos gravar.
	*/


    fclose(arq);

    return 0;
}

