// Escreva uma fucao recursiva que calcule a somatoria de n termos, sendo n um numero natural (n >=0)
// A funcao somatoria(n) eh definida da seguinte maneira:
/* somatoria(n) = { 0                      se n = 0
                    n + ... + 3 + 2 + 1    se n > 0
   }
*/

#include <stdio.h>

// Funcao recursiva somatoria(n)
int somatoria(int n){
	
	if(n == 0) return n;
	return n + somatoria(n-1);
}

int main() {
    int n;
    printf("Digite um numero natural (n >= 0): ");
    scanf("%d", &n);

    // Imprime a somatoria de n termos usando a funcao recursiva somatoria(n)
    printf("A somatoria de %d termos eh: %d\n", n, somatoria(n));
    return 0;
}
