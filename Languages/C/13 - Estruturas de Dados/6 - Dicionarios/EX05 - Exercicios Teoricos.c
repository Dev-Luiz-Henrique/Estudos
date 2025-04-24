/*

1. Qual a vantagem de se usar um dicionario (ou tabela de hashing), que e um vetor de mapeamentos, em vez de um 
mapeamento simples?
R: A vantagem de usar um dicionario e a velocidade de acesso aos elementos, que e muito mais rapida.

2. Qual o papel da funcao de espalhamento (ou funcao de hashing)?
R: Essa funcao tem o papel de converter uma chave em um indice em um vetor, permitindo que os valores sejam distribuidos 
   de maneira eficiente no vetor, facilitando o acesso rapido aos dados.

3. O que eh uma colisao de chaves? Como elas sao resolvidas na implementacao de dicionario? 
R: Uma colisao de chaves ocorre quando duas chaves diferentes produzem o mesmo indice após passarem pela funcao de hashing. 

4. Desenhe o dicionario que e construido quando o conjunto de chaves C = {1,6,89,43,0,14,27,3,90,77} e espalhado 
pela funcao de hashing h(c) = (c % 5).
R:  
    0: { 0, 90}
    1: { 1,  6}
    2: {27, 77}
    3: { 3, 43}
    4: {14, 89}

5. Quantas colisoes ocorrem durante o espalhamento realizado no Exercicio 4? 
R: Ocorreram 5 colisoes

6. Desenhe o dicionario que e construido quando o conjunto de chaves C = {1,3,5,7,9,11,13,15,17,19,21,23} e espalhado 
pela funcao de hashing h(c) = (c%2).
R: 
    0: { 1,  3,  5,  7,  9, 11, 13, 15, 17, 19, 21, 23}
    1: {  }

7. Quantas colisoes ocorrem durante o espalhamento realizado no Exercicio 6?
R: Ocorreram 11 colisoes

*/