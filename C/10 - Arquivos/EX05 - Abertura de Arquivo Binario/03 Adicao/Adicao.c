// Crie um programa que adicione dados em um arquivo binario

#include <stdio.h>

int main() {
    FILE *file;
    char data[] = "- 19 anos";

    file = fopen("CAD.dat", "ab"); // Abre o arquivo em modo de adicao de dados em binario
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    fwrite(&data, sizeof(data), 1, file); // Adiciona os dados no arquivo binario
    /* fwrite (param1, param2, param3, param4);
    
		param1: Ponteiro que aponta para a localizacao da memoria do dado a ser gravado.
		param2: Numero inteiro que indica o tamanho do tipo de dado a ser gravado. Geralmente, utilizamos o operador sizeof() que retorna o tamanho do registro. 
		param3: Quantidade de itens a serem gravados.
		param4: Ponteiro para a estrutura FILE do arquivo onde queremos gravar.
	*/

    fclose(file);

    return 0;
}


