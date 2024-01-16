// Defina e teste as seguintes macros:
// eh_minuscula(c): substitui a macro por 1 se c for minuscula, ou por 0, caso contrario
// eh_maiuscula(c): substitui a macro por 1 se c for maiuscula, ou por 0, caso contrario
// minuscula(c): substitui o caractere c por seu correspondente minusculo
// maiuscula(c): substitui o caractere c por seu correspondente maiusculo

#include <stdio.h>

#define eh_maiuscula(c) ((c)>= 'A' && (c) <= 'Z' ? 1 : 0)
#define eh_minuscula(c) ((c)>= 'a' && (c) <= 'z' ? 1 : 0)
#define maiuscula(c) (eh_minuscula(c) ? ((c) + ('A' - 'a')) : (c))
#define minuscula(c) (eh_maiuscula(c) ? ((c) - ('A' - 'a')) : (c))

int main( ){
	char c;
	printf("\nDigite um caracter: ");
	scanf("%c", &c);
    printf("\nConverte para maiuscula: %c", maiuscula(c));
    printf("\nConverte para minuscula: %c", minuscula(c));
	return 0;
}

