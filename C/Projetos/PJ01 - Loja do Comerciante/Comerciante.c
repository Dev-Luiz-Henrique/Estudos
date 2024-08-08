#include <stdio.h>

float entradaDados(){
    float item, total = 0;
    system("cls");
    printf("Digite o valor das mercadorias (zero para sair): ");
    do{
        scanf("%f",&item);
        if (item<0)
            printf("Valor invalido");
        else
            total += item;
    } while (item != 0);
    return total;
}

float desconto(float vlr){
    if (vlr<50)
        return 0.95*vlr;
    else if (vlr<=100)
        return 0.9*vlr;
    else if (vlr<=200)
        return 0.85*vlr;
    else 
		return 0.8*vlr;
}

int main() {
    float vlrTotal, vlrCompra;
    vlrTotal = entradaDados();
    vlrCompra = desconto(vlrTotal);
    printf("Valor final da compra: R$ %.2f", vlrCompra);
    return 0;
}

