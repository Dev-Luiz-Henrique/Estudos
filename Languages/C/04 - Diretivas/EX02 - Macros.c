// Defina as seguintes macros:
// soma(x, y); 
// max(x, y); 
// abs(n); 

#define soma(x, y) 	((x) + (y))
#define max(x, y) 	((x)>(y)? (x) : (y))
#define abs(n) 		((n)<0 ? -(n) : (n))

int main()
{
    int n1 = -7;
    int n2 =  8;
    printf("\n %d ", soma(2*3, 1 + 3));
    printf("\n %d ", abs(n1));
    printf("\n %d ", max(n1, n2));
    return 0;	
}

// Lembrar de usar esses parenteses para o programa nao interpretar errado