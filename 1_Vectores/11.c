#include <stdio.h>
#include <time.h>
void generar(int [], int);
void menorymayor(int [], int);
void buscarposmax(int[], int, int);
void mostrarv(int[], int);
int main(){
    int vec[20];
    srand(time(NULL));
    generar(vec, 20);
    mostrarv(vec, 20);
    menorymayor(vec, 20);
}
void generar(int vec[], int tam){
    int i;
    for(i = 0; i< tam; i++){
        vec[i] = rand()%100;
    }
}
void menorymayor(int vec[], int tam){
    int contmin = 1, i;
    int max = vec[0];
    int min = vec[0];
    for(i = 1; i < tam; i++){
        if(vec[i] > max)
            max = vec[i];
        if(vec[i] < min)
            min = vec[i];
            contmin = 1;
        if(vec[i] == min)
            contmin++;
    }
    buscarposmax(vec, max, tam);
    printf("\nEl menor valor es %i y se repite %i veces...\n", min, contmin);
}
void buscarposmax(int vec[],int max, int tam){
    int i, cont;
    printf("\nPosiciones donde se encuentra el maximo:");
    for(i = 0; i < tam; i++){
        if(vec[i] == max){
            printf("   %i", i);
        }
    }
}
void mostrarv(int vec[], int tam){
    int i;
    printf("\n\n");
    for(i = 0; i < tam; i++){
        printf("   %i", vec[i]);
    }
}