#include <stdio.h>
void multiplicar(int [][3], int);
void mostrar(int [][3]);
int main(){
    int matrix[3][3] = {0}, i, j, k;
    for(i = 0; i<3; i++){
        printf("\nFila %i;  ", i+1);
        for(j = 0; j<3; j++){
            scanf("%i", &matrix[i][j]);
        }
    }
    printf("\n\nIngresar escalar para muliplicar>>>>  ");
    scanf("%i", &k);
    multiplicar(matrix, k);
    mostrar(matrix);
}
void mostrar(int matrix[][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        printf("\n");
        for(j = 0; j < 3; j++){
            printf("%-6d ", matrix[i][j]);
        }
    }
}
void multiplicar(int matrix[][3], int k){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            matrix[i][j] *= k;
    }
}