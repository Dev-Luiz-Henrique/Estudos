// Crie a funcao recursiva hanoi(n,origem,auxiliar,destino), que resolve o problema das Torres de Hanoi, 
// movendo n discos da torre origem, para a torre destino, usando a torre auxiliar. 

// Depois Crie uma funcao recursiva para determinar o numero minimo de movimentos necessarios para resolver 
// o problema das Torres de Hanoi com n>0 discos

#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino) {
    if (n == 1)
        printf("Mova o disco 1 da torre %c para a torre %c\n", origem, destino);
    else {
        hanoi(n-1, origem, destino, auxiliar);
        printf("Mova o disco %d da torre %c para a torre %c\n", n, origem, destino);
        hanoi(n-1, auxiliar, origem, destino);
    }
}

int hanoi_moves(int n) {
    if (n == 1) return 1;
    return 2 * hanoi_moves(n-1) + 1;
}

int main() {
    int n;
    printf("Digite o numero de discos: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("O numero de movimentos para resolver o problema eh %d\n", hanoi_moves(n));
    return 0;
}






































