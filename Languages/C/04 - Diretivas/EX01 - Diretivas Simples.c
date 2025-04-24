// Crie um progrma simples usando as diretivas para substituir o printf e exibir uma frase

# include <stdio.h>
# define diga printf
# define oi "\nOla, tudo bem?"
# define devolve return

int main(){	
	diga (oi);
	devolve 0;
}

