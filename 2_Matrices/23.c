#include <stdio.h>
#include <stdlib.h>
void randomload(int [][8]);
int showmatrixmax(int [][8]);

int main(){
    int matrix [5][8],max, i ,j, counter = 0;
    srand(time(NULL));
    randomload(matrix);
    max = showmatrixmax(matrix);
    printf("\n\n\n%-6s %-6s", "FILA", "COLUMN");
    for(i = 0; i < 5; i++){
        for(j = 1; j < 8; j++){
            if(matrix[i][j] == max){
                counter++;
                printf("\n%-6d %-6d", i, j);
            }
        }
    }
    printf("\nSe repite %i veces....", counter);
}
void randomload(int matrix[][8]){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 8; j++){
            matrix[i][j] = rand()%100;
        }
    }
}
int showmatrixmax(int matrix[][8]){
    int i, j, max;
    max = matrix[0][0];
    for(i = 0; i < 5; i++){
        printf("\n");
        for(j = 0; j < 8; j++){
            printf("%-6d ", matrix[i][j]);
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    return max;
}