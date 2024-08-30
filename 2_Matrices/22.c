#include <stdio.h>
void sumfilas(int [][4], int []);
void sumcolumnas(int [][4], int []);
void cargamatrix(int [][4]);

int main(){
    int matrix[5][4] = {0}, vSumCol[4] = {0}, vSumFil[5] = {0};
    cargamatrix(matrix);
    sumfilas(matrix, vSumFil);
    sumcolumnas(matrix, vSumCol);
    printf("\nMatriz\n\n");
    int i, j;
    for(i = 0; i < 5; i++){
        printf("\n");
        for(j = 0; j < 4; j++){
            printf("%-6d ", matrix[i][j]);
        }
    }
    printf("\nSuma Filas\n");
    for(i = 0; i < 5; i++){
        printf("%-6d ", vSumFil[i]);
    }
    printf("\nSuma columnas\n");
    for(i = 0; i < 4; i++){
        printf("%-6d ", vSumCol[i]);
    }

}
void cargamatrix(int matrix[][4]){
    int i, j;
    for(i = 0; i < 5; i++){
        printf("\nFila %d: ", i+1);
        for(j = 0; j < 4; j++){
            scanf("%i", &matrix[i][j]);
        }
    }
}
void sumfilas(int matrix[][4], int vec[]){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            vec[i] += matrix[i][j];
        }
    }
}
void  sumcolumnas(int matrix[][4], int vec[]){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0;j < 5; j++){
            vec[i] += matrix[j][i];
        }
    }
}