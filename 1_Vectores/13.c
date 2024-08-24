#include <stdio.h>
#include <time.h>
void desordenar(int [], int);
void bubblesort(int [], int [], int);

int main(){
    int i, vecG[5] = {1, 2, 3, 4,5}, vecCod[5];
    srand(time(NULL));
    desordenar(vecCod, 5);
    for(i = 0; i< 5; i++){
        printf("%-4i ", vecCod[i]);
    }
    printf("\n");
    for(i = 0; i<5; i++){
        printf("%-4i ", vecG[i]);
    }
    printf("\n");
    bubblesort(vecG, vecCod, 5);
    printf("\nOrden de grupos: %i, %i, %i, %i, %i ",vecG[0],vecG[1], vecG[2], vecG[3], vecG[4]);
    printf("\n\n");
    for(i = 0; i< 5; i++){
        printf("%-4i ", vecCod[i]);
    }
    printf("\n");
    for(i = 0; i<5; i++){
        printf("%-4i ", vecG[i]);
    }
}
int buscar(int vec[], int obj, int tam){
    int i = 0, pos = -1;
    while(i < tam && pos != -1){
        if(vec[i] == obj)
            pos == i;
        i++;
    }
}
void desordenar(int vec[], int tam){
    int i, aux, pos;
    vec[0] = rand()% 100;
    for(i = 1; i< tam; i++){
        aux = rand()%100;
        while(pos == -1){
            aux = rand()%100;
            pos = buscar(vec, aux, 5);
        }
        vec[i] = aux;
    }
}
void bubblesort(int vecG[], int vecC[], int tam){
    int i, desordenado, aux1,  limite = tam -1;
    do
    {
        desordenado = 0;
        for(i = 0; i < limite; i++){
            if(vecC[i] > vecC[i+1]){
                aux1 = vecC[i];
                vecC[i] = vecC[i+1];
                vecC[i+1] = aux1;
                aux1 = vecG[i];
                vecG[i] = vecG[i+1];
                vecG[i+1] = aux1;
                desordenado = i;
            }
        }
        limite = desordenado;
    } while (desordenado);
}