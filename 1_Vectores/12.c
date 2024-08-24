#include <stdio.h>
int validar(int, int, int);
void ingresarCodigo(int [], int);
int buscarPos(int [], int, int);
void mostrarlista(int [], int [], int);
void mayormenorU(int [], int [], int);
int main(){
    int vecCod[10], pos, vecCant[10] = {0}, codigo, cant;
    ingresarCodigo(vecCod, 10);
    do{
    printf("\nIngrese codigo:   ");
    scanf("%i", &codigo);
    pos = buscarPos(vecCod, codigo, 10);
    if(pos==-1 )
        printf("\nIngrese dato valido:    ");
    }while(pos == -1 && codigo != 0);

    while(codigo != 0){
        printf("\nIngrese cantidad solicitada:  ");
        cant = validar(0, 100000, 2);
        vecCant[pos] += cant;
        do{
        printf("\nIngrese codigo:   ");
        codigo = validar(999, 10000, 0);
        pos = buscarPos(vecCod, codigo, 10);
        if(pos==-1)
            printf("\nIngrese dato valido:    ");
        }while(pos == -1 && codigo != 0);
    }
    mostrarLista(vecCod, vecCant, 10);
    mayormenorU(vecCod, vecCant, 10);
}
void ingresarCodigo(int vec[], int tam){
    int i, cod, pos;
    printf("#############################\n",
        "###########INGRESO###########\n \
        #############################\n");
    for(i = 0; i < tam; i++){
        printf("\nIngreso Codigo %i: ", i+1);
        cod = validar(999, 10000, 1000);
        pos = buscarPos(vec, cod, tam);
        while(pos !=-1){
            printf("\nDato reptido");
            cod = validar(999, 10000, 1000);
            pos = buscarPos(vec, cod, tam);
        }
        vec[i] = cod;
    }
}
int validar(int min, int max, int ex){
    int valor;
    do{
        scanf("%i", &valor);
        if((valor<min || valor > max) && valor != ex)
            printf("\nIngrese dato valido:");
    }while((valor<min || valor > max )&& valor!= ex);
    return valor;
}
int buscarPos(int vec[], int cod, int tam){
    int i = 0, pos = -1;
    while(i< tam && pos== -1){
        if(vec[i] == cod)
            pos = i;
        i++;
    }
    return pos;
}
void mostrarLista(int vecCod[], int vecCant[], int tam){
    int i;
    printf("\nLista de productos vendidos:");
    printf("\n%-8s %-8s\n", "CODIGO", "CANTIDAD");
    for(i =0; i < tam; i++){
        printf("\n%-8d %-8d\n", vecCod[i], vecCant[i]);
    }    
}
void mayormenorU(int vecCod[], int vecCant[], int tam){
    int i = 1, contmax = 0, contmin = 0;
    int max = vecCant[0];
    int min = vecCant[0];
    for(i = 1; i<tam; i++){
        if(vecCant[i] > max)
            max = vecCant[i];
        if(vecCant[i]<min)
            min = vecCant[i];
    }
    printf("\n%-7s %-7s\n", "MAXIMO", "MINIMO");
    for(i = 0; i <tam; i++){
        if(vecCant[i] == max)
            printf("%i\n", vecCod[i]);
            contmax++;
        if(vecCant[i] == min)
            printf("%-7s %-7d\n", " ", vecCod[i]);
            contmin++;
    }
}