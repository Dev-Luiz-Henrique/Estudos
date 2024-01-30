/*  
	Codifique um programa que manipule dados de cadastro de funcionarios, 
	apresentando um menu com as opcoes de gravar (op.1), listar (op.2), consultar (op. 3) ou sair (op. 4).

	Gravar: deve solicitar os dados e gravar apenas 1 funcionario ao final do arquivo e voltar ao menu principal.
	Listar: deve exibir todos os funcionarios.
	Consultar: deve solicitar o nome do funcionario e fazer uma varredura no arquivo, encontrando e imprimindo os dados do funcionario.
	Sair: deve encerrar o programa.
	
	Obs: apos qualquer operacao o programa deve reapresentar as opcoes na tela, ate que o usuario deseje sair.
	Dica: usar a funcao strupr() para comparar as strings em letras maiusculas, evitando diferencas da forma digitada pra forma gravada no arquivo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Funcao para converter string para letras maiusculas
void stringMaiuscula(char *str) {
	int i;
    for(i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}

// Estrutura para armazenar os dados de um funcionario
typedef struct {
   char nome[31];
   float salario;
} Func;

// Prototipos das funcoes
int menu(void);
int gravar(char[]);
int listar(char[]);
int consultar(char[]);

// Programa principal
int main(){

	int opcao;
	char nomeArq[] = "funcionarios.dat";

	do{
		opcao = menu();
		system("cls"); // Limpa a tela
		
		switch (opcao)
		{
			case 1:
				printf("1- Gravar\n\n");
				if(gravar(nomeArq) == 1) return 1; // Se ocorrer algum erro na gravacao, retorna 1 e encerra o programa
				break;
			
			case 2:
				printf("2- Listar\n\n");
				if(listar(nomeArq) == 1) return 1; // Se ocorrer algum erro na listagem, retorna 1 e encerra o programa
				break;

			case 3:
				printf("3- Consultar\n\n");
				if(consultar(nomeArq) == 1) return 1; // Se ocorrer algum erro na consulta, retorna 1 e encerra o programa
				break;

			case 4:
				printf("Saindo do programa...\n"); return 0;

			default:
				printf("Opcao invalida. Tente novamente.\n");
		}

		printf("\n\n");
	} while (opcao != 4);

	return 0;
}

// Funcao para exibir o menu e ler a opcao selecionada pelo usuario
int menu(){
	int opcao;
	printf("=====================\n");
	printf("\tMenu\n");
	printf("1- Gravar\n");
	printf("2- Listar\n");
	printf("3- Consultar\n");
	printf("4- Sair\n");
	printf("\nSelecione uma opcao: ");
	scanf("%d", &opcao);
	getchar();
	printf("\n=====================\n\n");
	return opcao;
}

// Funcao para gravar os dados de um funcionario no arquivo
int gravar(char nomeArq[]){

	FILE *arq;
	Func f;

	if((arq=fopen(nomeArq,"ab"))==NULL) {// Abertura do arquivo em modo de adicao binaria
		printf("Ocorreu um erro durante a abertura do arquivo\n");
		return 1;
	}

	printf("Nome: ");
	gets(f.nome);
				
	printf("\nSalario: ");
	scanf("%f",&f.salario);
	getchar(); // Limpa o buffer
	fwrite(&f,sizeof(Func),1,arq); // Grava os dados no arquivo de saida
	
	fclose(arq);
	printf("\nDados gravados com sucesso\n");
	return 0;
}

// Funcao para listar os funcionarios do arquivo de entrada
int listar(char nomeArq[]){

	FILE *arq;
	Func f;
	int fim;
   
   	if((arq=fopen(nomeArq,"rb"))==NULL){
		printf("Ocorreu um erro durante a abertura do arquivo\n");
		return 1;
   	}
   		
   	printf("Nome\t\tSalario\n");
    printf("====\t\t=======\n");
    	
    do{     
		fread(&f, sizeof(Func), 1, arq); // Le os dados do arquivo
        fim = feof(arq); // Verifca o final do arquivo
        if (!fim)
            printf("%s\t%7.2f\n", f.nome, f.salario); // Exibe os dados
    } while (!fim);
       	
    fclose(arq);
	printf("\n\nTodos funcionarios listados\n");
	return 0;
}

// Funcao para consultar os funcionarios do arquivo de entrada pelo nome do funcionario
int consultar(char nomeArq[]){

	FILE *arq;
	Func funcBusca, f;
	int fim;

	if((arq=fopen(nomeArq,"rb"))==NULL){
		printf("Ocorreu um erro durante a abertura do arquivo\n");
		return 1;
	}

	printf("Digite o nome do funcionario que deseja buscar: ");
	gets(funcBusca.nome);
	stringMaiuscula(funcBusca.nome);

	do{     
		fread(&f, sizeof(Func), 1, arq); // Le os dados do arquivo
        fim = feof(arq); // Verifca o final do arquivo

		stringMaiuscula(f.nome); // Converte a string para letras maiusculas

        if (strcmp(funcBusca.nome, f.nome) == 0){
			printf("Nome\t\tSalario\n");
    		printf("====\t\t=======\n");
			printf("%s\t%7.2f\n", f.nome, f.salario); // Exibe os dados
			fclose(arq);
			return 0; // Encerra o programa se o funcionario for encontrado
		}
    } while (!fim);

	fclose(arq);
	printf("\nNao foi possivel achar o funcionario %s\n", f.nome);
	return 0;
}
