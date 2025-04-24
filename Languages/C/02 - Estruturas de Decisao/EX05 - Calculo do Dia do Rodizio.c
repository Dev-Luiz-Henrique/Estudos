// Dado o ultimo digito da placa de um carro, informe o dia do seu rodizio. 
// Sugestao: utilize switch/ case.

#include <stdio.h>

int main() {
   int placa; // Declaracao de variavel
   
   // Entrada de dados (Final da placa)
   printf("\n Digito final da placa do veiculo: ");
   scanf("%d", &placa);
   
   // Estrutura de decisao com Switch Case da placa
   // Lembrando que o "break" impede que ele siga continue realizando os casos abaixo
   switch (placa) {
      case 1: // Segue para o 2
      case 2: printf("\n segunda-feira"); break;
      
      case 3: // Segue para o 4
      case 4: printf("\n terca-feira"); break;
      
      case 5: // Segue para o 6
      case 6: printf("\n quarta-feira"); break;
      
      case 7: // Segue para o 8
      case 8: printf("\n quinta-feira"); break;
      
      case 9: // Segue para o 0
      case 0: printf("\n sexta-feira"); break;
      
      default: printf("\n Digito inválido"); break;
   }
   return 0;
}



