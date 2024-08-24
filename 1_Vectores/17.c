#include <stdio.h>
int cargarpos(int [], int[], int, int );
void ingresar(int [], int);
int main(){
    int cant, vec[10] = {0}, vpos[10] = {0}, i, num;
    ingresar(vec, 10);  
    printf("\nBuscar:");
    scanf("%d", &num);
    cant = cargarpos(vec, vpos, num,10);
    printf("\n");
    for(i = 0; i< cant; i++){
        printf("%-2d ", vpos[i]);
    }
}
void ingresar(int vec[], int tam){
    int i;
    printf("\nIngrese 10 numeros:");
    for(i = 0; i < tam;i++){
        scanf("%d", &vec[i]);
    }
}
int cargarpos(int vec[], int pos[], int num, int tam){
    int i, j =0, cant;
    for(i = 0;  i<tam; i++){
        if(vec[i] == num){
            pos[j] = i;
            j++;
        }       
    }
    return j;
}