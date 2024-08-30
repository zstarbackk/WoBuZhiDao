#include <stdio.h>
void cargar(int [15][10]);
void mostrar(int [15][10]);
void sumpasajes(int [15][10], int []);
int validar(int, int, int);
int main(){
    int matrix[15][10] = {0},i, max, Ventas[15] = {0};
    cargar(matrix);
    mostrar(matrix);
    sumpasajes(matrix, Ventas);
    max = Ventas[0];
    for(i = 1; i < 15; i++){
        if(Ventas[i] > max){
            max = Ventas[i];
        }
    }
    printf("\n\n");
    printf("\n%-6s:", "AGENCIA");
    for(i = 0; i < 15; i++){
        if(Ventas[i] == max){
            printf("\n%-6d ", i+1);
        }
    }
}
void cargar(int matrix[][10]){
    int i, agencia, tour, pasaje;
    printf("\nIngrese codigo de agencia: ");
    agencia = validar(1, 15, -1);
    while(agencia != -1){
        printf("\nIngrese codigo de tour: ");
        tour = validar(1, 10, 2);
        printf("\n Ingrese cantidad de pasajes: ");
        pasaje = validar(0, 20, 1);
        matrix[agencia-1][tour -1] =pasaje;
        printf("\n\nIngrese codigo de agencia:  ");
        agencia = validar(1, 15, -1);
    }
}
void mostrar(int matrix[][10]){
    int i, j;
    for(i = 0; i < 15; i++){
        printf("\nAgencia %-2d:   ", i+1);
        for(j = 0; j < 10; j++){
            printf("%-2d ", matrix[i][j]);
        }
    }
}
void sumpasajes(int matrix[][10], int sum[]){
    int i, j;
    for(i = 0; i < 15; i++){
        for(j = 0; j < 10; j++){
            sum[i] += matrix[i][j];
        }
    }
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%d", &aux);
        if((aux < min || aux > max) && aux != ex){
            printf("\nIngrese dato valido:");
        }
    }while((aux < min || aux > max) && aux != ex);
    return aux;
}
