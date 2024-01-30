// Crie um programa que grave dados digitados pelo usuario em um arquivo, linha a linha, ate que seja digitado FIM

#include <stdio.h>

int main() {
   FILE *ptrArq;
   char linha[100];    
   char c;
   
   // Tenta abrir o arquivo
   if((ptrArq=fopen("Teste.txt","w"))==NULL) 
      printf("Arquivo nao pode ser aberto\n");
   else {
   	
   		// Solicita a entrada de dados ate que seja digitado FIM
		while(1) {
			gets(linha);
          	if (strcmp(linha,"FIM") == 0)
             	break;
             	
            // Escreve no arquivo o conteudo recebido
          	fputs(linha, ptrArq);	 
          	fputs("\n", ptrArq);
      	} 
       	fclose(ptrArq);
   }
   return 0;
}
