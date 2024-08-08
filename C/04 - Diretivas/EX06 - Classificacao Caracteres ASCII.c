// Crie um programa usando DIRETIVAS que:

// Le caracteres do teclado enquanto nao se digitar ESC(ASCII 27). Para cada caracter lido, classifica-lo como:
// - Caracter de controle: 0 a 31 e 127
// - Caracter alfabético maiúsculo: 65 a 90
// - Caracter alfabético minúsculo:97 a 122
// - Caracter numérico: 48 a 57
// - Caracter de pontuação: imprimivel, não alfabético e não numérico.
// Obs.: Caracter imprimivel: 32 a 126. Caracter alfabetico: maiusculos + minusculos

#include <stdio.h>
#include <conio.h>

#define controle(c) 	((c)>=0 && (c)<=31 || (c)==127)
#define maiusculo(c) 	((c)>=65 && (c)<=90)
#define minusculo(c) 	((c)>=97 && (c)<=122)
#define numerico(c) 	((c)>=48 && (c)<=57)
#define letra(c) 		(maiusculo(c) || minusculo(c))
#define imprimivel(c) 	((c)>=32 && (c)<=126)
#define pontuacao(c) 	(imprimivel(c) && !letra(c) && !numerico(c))

int main(){

	int ch;
	printf("Digite um caracter: ");
	ch = getch();
	
	while(ch != 27) {
		if(controle(ch))
			printf("\nCaracter de controle");
		else if(maiusculo(ch))
			printf("\nCaracter alfabetico maiusculo");
		else if(minusculo(ch))
			printf("\nCaracter alfabetico minusculo");
		else if(numerico(ch))
			printf("\nCaracter numerico");
		else if(pontuacao(ch))
			printf("\nCaracter de pontuacao");

		printf("\n\nDigite um character: ");	
		ch = getch();
	}
	return 0;
}
