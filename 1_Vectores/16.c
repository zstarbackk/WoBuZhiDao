#include <stdio.h>
void ordenar(int [], int[], int[], int);
int main(){
    int i, v[10] = {1,4,7,8,9,10,15,26,99,104}, vec[3];
    int vectorF[13] = {0};
    printf("\nIngrese 3 numeros...");
    scanf("%d%d%d", &vec[0], &vec[1], &vec[2]);
    printf("\n\n");
    for(i = 0; i< 10; i++){
        printf("%-4i ", v[i]);
    }
    printf("\n\n");
    ordenar(v, vec,vectorF, 10);
    for(i = 0; i< 13; i++){
        printf("%-4d ", vectorF[i]);
    }
}
void ordenar(int v[10], int new[3], int vectorF[13], int tam){
    int i = 0, j = 0, k = 0;
    while(k<13){
        if(i < 3 && new[i] < v[j]){
            vectorF[k] = new[i];
            i++;
        }
        else{
            if(j < 10){
                vectorF[k] = v[j];
                j++;
            }
        }
        k++;
    }
}