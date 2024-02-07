/*Paula simplesmente adora matematica. Seu maior passatempo e ficar inventando jogos ou atividades que a envolvam para brincar com seus amiguinhos. 
Obviamente, nem todos eles nao sao tao apaixonados assim por matematica e tem muita dificuldade para resolver as brincadeiras propostas por ela. 
Agora Paula inventou um pequeno passatempo que envolve 3 caracteres: um digito numerico, uma letra e outro digito numerico.

Se a letra for maiuscula, deve-se subtrair o primeiro digito do segundo. 
Se a letra for minuscula, deve-se somar ambos os digitos e se os DIGITOS forem iguais, deve-se desconsiderar a letra e mostrar o produto entre os dois digitos. 
Ela pediu para seu amigo Marcelo, que e bom em programacao, para criar um programa para que encontre a solucao para cada uma das sequencias que Paula lhe apresentar.

Entrada
A entrada contem varios casos de teste. A primeira linha da entrada contem um inteiro N, indicando o numero de casos de teste que virao a seguir. 
Cada caso de teste e uma sequencia de tres caracteres criada por Paula. Esta sequencia contem na primeira posicao um caractere de '0' a '9', 
na segunda posicao uma letra maiuscula ou minuscula do alfabeto e na terceira posicao outro caractere de '0' a '9'.

Saida
Para cada caso de teste, deve ser impressa uma linha com um valor inteiro que representa a solucao da sequencia proposta por Paula.*/

#include <stdio.h>

int main(){
	int *dados;
    int n, d1, d2;
    char c;
    
	scanf("%d", &n);
    dados = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i ++){
        scanf("%d%c%d", &d1, &c, &d2);

        if (d1 == d2)
            dados[i] = d1 * d2;
        else
        {
            if (c >= 'A' && c <= 'Z')
                dados[i] = d2 - d1;
            else if (c >= 'a' && c <= 'z')
                dados[i] = d1 + d2;
        }
    }
    
    for(int i = 0; i < n; i ++)
        printf("%d\n", dados[i]);
        
	free(dados);
	return 0;
}
