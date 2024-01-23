// Responda as questoes basicas sobre ponteiros:
/* 

1- Quais das seguintes instrucoes sao corretas para declarar um ponteiro? 
a) int _ptr x; 
b) int *ptr; 
c) *int ptr; 
d) *x;

R: b

----------------------------------------------------------------------------------------
2- Na expressao float *pont; o que eh do tipo float? 
a) a variavel pont. 
b) o endereco de pont. 
c) a variavel apontada por pont. 
d) nenhuma das anteriores.

R: c

----------------------------------------------------------------------------------------
3- Assumindo que o endereco de num foi atribuído a um ponteiro pnum, quais das seguintes 
expressoes sao verdadeiras? 
a) num == &pnum 
b) num == *pnum 
c) pnum == *num 
d) pnum == &num

R: b e d

----------------------------------------------------------------------------------------
4- Qual a instrucao deve ser adicionada ao programa seguinte para que ele trabalhe 
corretamente? 
main ( ) { 
	int j, *pj; 
	*pj = 3; 
}

R: 	
main ( ) { 
	int j, *pj = &j; 
	*pj = 3; 
}

----------------------------------------------------------------------------------------

5- Assumindo que o endereco da variavel x foi atribuido a um ponteiro px, escreva uma 
expressao que nao usa x e divida x por 5.
R: *px = *px / 5;

----------------------------------------------------------------------------------------
6- Qual o valor das seguintes expressoes: 
	int i = 3, j = 5; 
	int *p = &i, *q = &j; 

a) p == &i 
b) *p - *q 
c) **&p

R:
a) True
b) -2
c) 3, visto que um * referencia o valor do endereco do p (&) e o outro * referencia o 
valor do endereco armazenado em p (i)

*/
