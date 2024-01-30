// Crie um programa que leia um arquivo, linha a linha, e exiba o conteudo no tela

#include <stdio.h>

int main() {
   FILE *ptrArq;
   char linha[100];    
   char c;
   
   // Tenta abrir o arquivo
   if((ptrArq=fopen("Teste.txt","r"))==NULL) 
      printf("Arquivo nao pode ser aberto\n");
   else {

   		// Le ate 99 caracteres e armazena-os na string linha - \0 no final, totalizando 100
   		// Ela para de ler se encontra um caractere de nova linha (\n) ou fim de arquivo.
       	while(fgets(linha, 100, ptrArq) != NULL) 
          	printf("%s", linha); // Exibe a linha na tela

       	fclose(ptrArq);
   }
   return 0;
} 
