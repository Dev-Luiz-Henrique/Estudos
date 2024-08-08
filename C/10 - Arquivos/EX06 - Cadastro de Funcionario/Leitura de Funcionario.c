// Crie um programa que leia os funcionarios cadastrados, com nome e salario de cada um

#include <stdio.h>
typedef struct {
   char nome[31];
   float salario;
} Func;

int main() {
	
   FILE *e;
   Func f;
   int fim;
   
   if( (e=fopen("func.dat","rb"))==NULL )
   		printf("O arquivo nao pode ser aberto\n");
   else {		
   		printf("Nome\tSalario\n");
    	printf("====\t=======\n");
    	
     	do{     
		 	fread(&f, sizeof(Func), 1, e); // Le os dados do arquivo
          	fim = feof(e); // Verifca o final do arquivo
          	if (!fim)
             	printf("%s\t%7.2f\n", f.nome, f.salario); // Exibe os dados
       	} while (!fim);
       	
       	fclose(e);
     }
	return 0;
}

