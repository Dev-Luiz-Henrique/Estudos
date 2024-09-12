#include <stdio.h>

// Estrutura para armazenar as posicoes necessarias
typedef struct {
    int floor;
    int x;
    int y;
} Posicao;

// Array com os movimentos possiveis de x e y
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Prototipo da funcao dfs
int dfs(Posicao *inicio, Posicao destino, int A, int L, char grid[A][L]);

int main() {

    int numFloors, floorAntenna, A, L, i, j, k;

    while(scanf("%d %d", &numFloors, &floorAntenna) && numFloors) {
        scanf("%d %d", &A, &L);

        // Posicoes necessarias para o tom, antena e as escadas de subida
        Posicao tom, antenna, upperStairs[numFloors-1];

        // Matriz com os valores das posicoes   
        char grid[numFloors][A][L]; //Andar, Coluna, Linha
        for(i = 0; i < numFloors; i++) {
            for(j = 0; j < A; j++) {
                for(k = 0; k < L; k++){
                    scanf(" %c", &grid[i][j][k]); // Alimenta a matriz

                    // Verifica se a posicao e um tom, antena, escada de subida ou parede
                    switch (grid[i][j][k]){
                        case 'T': tom.floor = i; tom.x = j; tom.y = k; 
                            break;

                        case 'A': antenna.floor = i; antenna.x = j; antenna.y = k;
                            break;
                        
                        case 'S': upperStairs[i].floor = i; upperStairs[i].x = j; upperStairs[i].y = k;
                            break;

                        default: break;
                    }
                }
            }
        }

        i = 0;
        // Enquanto o andar do tom for diferente do andar da antena, o tom anda para a escada de subida correspondente.
        while(tom.floor != antenna.floor) {

            if(dfs(&tom, upperStairs[i], A, L, grid[i]))
                tom.floor++;
            i++;
        }

        // Verifica se o tom e capaz de chegar a antena. Se sim, imprime "viavel". Caso contrario, imprime "inviavel".
        if(dfs(&tom, antenna, A, L, grid[i]))
            printf("viavel\n");
        else
            printf("inviavel\n");
    }   
}

// Funcao que implementa o algoritmo de busca em profundidade
int dfs(Posicao *inicio, Posicao destino, int A, int L, char grid[A][L]) {

    int visitado[A][L], i;
    visitado[inicio->x][inicio->y] = 1; // Posicao inicial marcada como visitada

    if(inicio->x == destino.x && inicio->y == destino.y) return 1; // Chegou no destino

    // Percorre as posicoes adjacentes do inicio, verificando se e valida, nao e visitada e nao e parede.
    for(i = 0; i < 4; i++) {
        Posicao next;
        next.x = inicio->x + dx[i];
        next.y = inicio->y + dy[i];

        // Verifica se a proxima posicao e valida, nao e visitada e nao e parede.
        if(next.x >= 0 && next.y >= 0 && next.x < A && next.y < L && !visitado[next.x][next.y] && grid[next.x][next.y] != '#') 
        {
            if(dfs(&next, destino, A, L, grid)) return 1; // Recursao - Chegou no destino
        }
    }
    return 0;
}