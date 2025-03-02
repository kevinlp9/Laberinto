#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 7 
void mostrarlab(int lab[N][N]) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            printf(" %d ", lab[i][j]); 
        } 
        printf("\n"); 
    } 
} 
int salida(int lab[N][N], int x, int y) { 
    if (x == N-1 && y == N-1) { 
        lab[x][y] = 2; 
        return 1; 
    } 
    if (lab[x][y] != 1) { 
        return 0; 
    } 
    lab[x][y] = 3; 
 
 
    if (y < N-1 && salida(lab, x, y+1)) { 
        lab[x][y] = 2; 
        return 1; 
    } 
    if (x < N-1 && salida(lab, x+1, y)) { 
        lab[x][y] = 2; 
        return 1; 
    } 
    lab[x][y] = 0; 
    return 0; 
} 
int main() { 
    int lab[N][N]; 
    srand(time(NULL)); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            if (rand() % 3 == 0) { 
                lab[i][j] = 0; 
            } else { 
                lab[i][j] = 1; 
            } 
        } 
    } 
 
 
    lab[0][0] = 1; 
    lab[N-1][N-1] = 1; 
    printf(" LABERINTO :\n"); 
    mostrarlab(lab); 
    if (salida(lab, 0, 0)) { 
        printf("\n SOLUCION:\n"); 
        mostrarlab(lab); 
    } else { 
        printf("\nNo tiene solucion.\n"); 
    } 
 
    return 0; 
}