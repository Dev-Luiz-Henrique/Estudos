// Crie um programa de cadastro de funcionarios, que cadastre nome e salario de um funcionario

#include <stdio.h>
#include <string.h>

typedef struct {
   char  nome[31];
   float salario;
} Func;

int main() {
   FILE *s;
   Func f;
   
   if( (s=fopen("func.dat","wb"))==NULL ) 
        printf("O arquivo nao pode ser criado\n");
   else {
      	printf("Digite ponto para finalizar o cadastramento:\n");
    	do{
    	   	printf("\nNome: ");
    	   	gets(f.nome);
    	   	
    	   	// Verifica se o valor digitado foi um ponto
    	   	if(strcmp(f.nome,".") != 0 ) {
           	    printf("Salario: ");
    		    scanf("%f",&f.salario);
    		    getchar(); // Limpa o buffer
    		    fwrite(&f,sizeof(Func),1,s); // Grava os dados no arquivo de saida
           	}
           	
       	} while (strcmp(f.nome,".") != 0);
       	
       	fclose(s);
    }
    return 0;
}

