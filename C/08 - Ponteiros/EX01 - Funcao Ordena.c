// Escreva uma funcao ordena (a, b) que receba dois inteiros a e b e 
// devolva o menor deles em a e o maior em b.

#include <stdio.h>

// Funcao de ordenacao
void ordena(int *a, int *b){
    int c = *a;      // Acessa o valor apontado por 'a' e atribui a 'c'
    if (*a > *b) {   // Se o valor apontado por 'a' for maior que o valor apontado por 'b'
        *a = *b;     // Acessa o valor apontado por 'b' e atribui ao valor apontado por 'a'
        *b = c;      // Atribui 'c' ao valor apontado por 'b'
    }
}


int main() {
    int a, b;
    
    // Entrada de dados
    printf("Digite o valor de A e o valor de B: ");
    scanf("%d%d", &a, &b);
    
    ordena(&a, &b); // Chamada da funcao enviado o endereco das variaveis
    printf("Odenando:\na = %d\nb = %d\n", a, b); // Exibicao dos dados
    // Notar que as variaveis nativas foram alteradas
    return 0;
}
