// Codifique a funcao rodizio(placa), que recebe o numero da placa de um veiculo e exibe o dia em ele esta no rodizio.

#include <stdio.h>

// Funcao que recebe o ultimo numero da placa e exibe o dia em que o veiculo esta no rodizio
void rodizio(int placa) {
    switch(placa) {
        case 1:
        case 2: printf("O veiculo esta no rodizio na segunda-feira.\n"); break;
        case 3:
        case 4: printf("O veiculo esta no rodizio na terca-feira.\n"); break;
        case 5:
        case 6: printf("O veiculo esta no rodizio na quarta-feira.\n"); break;
        case 7:
        case 8: printf("O veiculo esta no rodizio na quinta-feira.\n"); break;
        case 9:
        case 0: printf("O veiculo esta no rodizio na sexta-feira.\n"); break;
        default: printf("Numero de placa invalido.\n");
    }
}

int main() {
    int placa;
    printf("Digite o ultimo numero da placa: ");
    scanf("%d", &placa);
    
    // Chama a funcao rodizio passando o ultimo numero da placa como parametro.
    rodizio(placa);
    return 0;
}