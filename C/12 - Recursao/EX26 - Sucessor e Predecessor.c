/*Considere as funcoes a seguir: 
    int suc(int n) { return n+1; } 
    int pred(int n) { return n-1; } 

Usando essas funcoes (e nenhum operador aritmetico), crie funcoes recursivas para determinar: 
(a) A soma de dois numeros naturais. 
(b) A subtracao de dois numeros naturais (o resultado pode ser negativo). 
(c) O dobro de um numero natural. 
(d) A metade inteira de um numero natural. 
(e) O minimo entre dois numeros naturais. 
(f) O máximo entre dois numeros naturais. 
(g) Se um numero natural e par. 
(h) Se um numero natural e impar. 

Usando as funcoes do exercicio anterior (e nenhum operador aritmetico), crie funcoes recursivas para calcular: 
(a) O produto de dois numeros naturais. 
(b) O quociente da divisao inteira de dois numeros naturais. 
(c) O resto da divisao inteira de dois numeros naturais. 
(d) A potência de um numero natural elevado a outro numero natural. 
(e) O quadrado de um numero natural n, considerando que n^2 = 1 + 3 + 5 + ...+ (2n-1). */

#include <stdio.h>

int suc(int n) { return n+1; } 
int pred(int n) { return n-1; }

// a) A soma de dois numeros naturais
int soma(int a, int b) { 
    if(b == 0) return a;
    return soma(suc(a), pred(b));
}

// b) A subtracao de dois numeros naturais (resultado pode ser negativo)
int subtracao(int a, int b){
    if(b == 0) return a;
    return subtracao(pred(a), pred(b));
}

// c) O dobro de um numero natural
int dobro(int n){
    if(n == 0) return n;
    return suc(suc(dobro(pred(n))));
}

// d) A metade inteira de um numero natural
int metade(int n){
    if(n == 0) return n;
    return suc(metade(pred(pred(n))));
}

// e) O minimo entre dois numeros naturais
int minimo(int a, int b){
    if(a == 0) return a;
    if(b == 0) return b;
    return suc(minimo(pred(a), pred(b)));
}

// (f) O maximo entre dois numeros naturais
int maximo(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return suc(maximo(pred(a), pred(b)));
}

// (g) Se um numero natural eh par
int par(int n){
    if(n < 0)  return 0;
    if(n == 0) return 1;
    return par(pred(pred(n)));
}

// (h) Se um numero natural eh impar
int impar(int n){
    if(n < 0)  return 1;
    if(n == 0) return 0;
    return impar(pred(pred(n)));
}

// A partir deste ponto, as funcoes feitas podem ser usadas

// (i) O produto de dois numeros naturais
int produto(int a, int b){
    if(b == 0) return 0;
    return soma(a, produto(a, pred(b)));
}

// (j) O quociente da divisao inteira de dois numeros naturais
int quociente(int a, int b){
    if(a < b) return 0;
    return suc(quociente(subtracao(a,b), b));
}

// (k) O resto da divisao inteira de dois numeros naturais
int resto(int a, int b){
    if(a < b) return a;
    return resto(subtracao(a,b), b);
}

// (l) A potencia de um numero natural elevado a outro numero natural
int potencia(int a, int b){
    if(b == 0) return 1;
    return produto(potencia(a, pred(b)), a);
}

// (m) O quadrado de um numero natural n, considerando que n^2 = 1 + 3 + 5 + ... + (2n-1)
int quadrado(int n){
    if(n == 0) return 0;
    return soma(quadrado(pred(n)), pred(soma(n, n)));
}

char menu(void);
void opcoes(char escolha);

int main(){
    char escolha = menu();
    opcoes(escolha);
    return 0;
}

char menu(){
    char c;
    printf("Escolha uma das opcoes abaixo:\n");
    printf("a) A soma de dois numeros naturais\n");
    printf("b) A subtracao de dois numeros naturais\n");
    printf("c) O dobro de um numero natural\n");
    printf("d) A metade inteira de um numero natural\n");
    printf("e) O minimo entre dois numeros naturais\n");
    printf("f) O maximo entre dois numeros naturais\n");
    printf("g) Se um numero natural eh par\n");
    printf("h) Se um numero natural eh impar\n");
    printf("i) O produto de dois numeros naturais\n");
    printf("j) O quociente da divisao inteira de dois numeros naturais\n");
    printf("k) O resto da divisao inteira de dois numeros naturais\n");
    printf("l) A potencia de um numero natural elevado a outro numero natural\n");
    printf("m) O quadrado de um numero natural n\n");
    printf("Opcao: ");
    scanf("%c", &c);
    printf("\n----------------------------------\n");
    return c;
}

void opcoes(char escolha){
    int n1, n2;
    switch(escolha){
        case 'a':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", soma(n1, n2));
            break;
        case 'b':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", subtracao(n1, n2));
            break;
        case 'c':
            printf("Digite um numero natural:\n");
            scanf("%d", &n1);
            printf("%d\n", dobro(n1));
            break;
        case 'd':
            printf("Digite um numero natural:\n");
            scanf("%d", &n1);
            printf("%d\n", metade(n1));
            break;
        case 'e':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", minimo(n1, n2));
        case 'f':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", maximo(n1, n2));
            break;
        case 'g':
            printf("Digite um numero natural:\n");
            scanf("%d", &n1);
            printf("%s\n", par(n1) ? "SIM" : "NAO");
            break;
        case 'h':
            printf("Digite um numero natural:\n");
            scanf("%d", &n1);
            printf("%s\n", impar(n1) ? "SIM" : "NAO");
            break;
        case 'i':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", produto(n1, n2));
            break;
        case 'j':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", quociente(n1, n2));
            break;
        case 'k':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", resto(n1, n2));
            break;
        case 'l':
            printf("Digite dois numeros naturais:\n");
            scanf("%d %d", &n1, &n2);
            printf("%d\n", potencia(n1, n2));
            break;
        case 'm':
            printf("Digite um numero natural:\n");
            scanf("%d", &n1);
            printf("%d\n", quadrado(n1));
            break;
        default:
            printf("Opcao invalida\n");
    }
}
