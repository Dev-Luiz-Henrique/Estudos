#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    int crumbs;
    int x, y;
    char directions[4];
} Friend; 

Friend Joao, Maria, Bruxa;
char forest[MAX][MAX];
char forestCopy[MAX][MAX];
int height, width;

void copyForest(void);
int searchCandies(Friend *f, int y, int x);

int main(){
    int n, i, j, rM, rB, rJ;
    scanf("%d",&n);
    
    // Inicializa as direcoes dos amigos
    strcpy(Bruxa.directions, "LONS"); // Bruxa: Leste, Oeste, Norte e Sul
    strcpy(Joao.directions,  "NLSO"); // Joao:  Norte, Leste, Sul e Oeste
    strcpy(Maria.directions, "SNOL"); // Maria: Sul, Norte, Oeste e Leste

    while(n > 0){
        scanf("%d %d", &height, &width);

        for(i = 0; i < height; i++){
            for(j = 0; j < width; j++){
                scanf(" %c", &forest[i][j]);

                // Econtra a posicao dos amigos e o numero de migalhas que cada um tem
                switch(forest[i][j]){
                    case 'B': Bruxa.x = j;  Bruxa.y = i; Bruxa.crumbs = 0; break;
                    case 'M': Maria.x = j;  Maria.y = i; Maria.crumbs = 0; break;
                    case 'J': Joao.x  = j;  Joao.y  = i; Joao.crumbs  = 0; break;
                } // Numero de migalhas 1, pois o lugar atual eh contabilizado
            }   
        }
        
        // Testando apenas os amigos
        copyForest();
        rM = searchCandies(&Maria, Maria.y, Maria.x);
        copyForest();
        rJ = searchCandies(&Joao, Joao.y, Joao.x);
        copyForest();
        rB = searchCandies(&Bruxa, Bruxa.y, Bruxa.x);

        // Verificando o vencedor
        if(!rM && !rJ && !rB) printf("ninguem\n");
        else if(rB && (!rM || Bruxa.crumbs < Maria.crumbs) && (!rJ || Bruxa.crumbs < Joao.crumbs)) 
            printf("bruxa %d\n", Bruxa.crumbs); 
        else if(rM && (!rB || Maria.crumbs < Bruxa.crumbs) && (!rJ || Maria.crumbs < Joao.crumbs))
            printf("maria %d\n", Maria.crumbs);
        else if(rJ && (!rB || Joao.crumbs < Bruxa.crumbs) && (!rM || Joao.crumbs < Maria.crumbs))
            printf("joao %d\n", Joao.crumbs);
        else printf("empate\n");
        n--;
    }
}

// Funcao que preenche uma copia da matriz
void copyForest(){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++)
            forestCopy[i][j] = forest[i][j];
    }
};

// Funcao que procura o doce na matriz
int searchCandies(Friend *f, int y, int x){

    // Verifique se a posicao atual eh valida e livre
    if( x < 0 || x >= width || y < 0 || y >= height || forestCopy[y][x] == '#' || forestCopy[y][x] == 'X')
        return 0;

    forestCopy[y][x] = 'X'; // Marca a posicao atual como visitada
    f->crumbs++; // Aumenta o numero de migalhas

    if(forest[y][x] == 'D') return 1; // Se o doce foi encontrado
        
    int i;
    for(i = 0; i < 4; i++){
        int dy = y, dx = x;

        // Altera a posicao atual conforme a ordem de direcao do amigo
        switch (f->directions[i]){
            case 'N': dy--; break;
            case 'S': dy++; break;
            case 'L': dx++; break;
            case 'O': dx--; break;
        }

        // Se o doce for encontrado
        if(searchCandies(f, dy, dx)) return 1;
    }
    return 0;
};