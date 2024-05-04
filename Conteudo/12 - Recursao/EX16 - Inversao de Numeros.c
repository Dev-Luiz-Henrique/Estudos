// Codifique uma Funcao Recursiva que recebe um natural n e
// imprime seus digitos invertidos (da direita para a esquerda).

#include <stdio.h>

// Funcao recursiva que imprime os digitos de n ao contrario
void inverte(unsigned n){
	if (n<10)	
		printf("%u", n);
	else {
		printf("%u", n%10);
		inverte(n/10);
	}
}

int main(){
    unsigned int n;
    printf("Digite n: ");
    scanf ("%u", &n);

	// Imprime o valor de n ao contrario
    printf("O valor de %u ao contrario eh ", n);
    inverte(n);
	return 0;
}
