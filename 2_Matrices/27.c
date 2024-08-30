/*2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 
productos a lo lardo del año. Los productos están identificados por códigos
numéricos de 3 cifras. Como primera información se ingresa el precio unitario
de cada uno de los productos y su código. Luego por cada venta se ingresa:
    • Código de producto
    • Día de venta
    • Mes de venta
    • Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
    a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
    b. El producto con el cual se obtuvo la mayor recaudación.
    c. El trimestre de menor recaudación del año.*/
#include <stdio.h>
int posSearch(int [], int, int);
int validar(int, int, int);
void ingresoinicial(int [], float[]);
void ingresoventas(int[][12], int[], float [][12], float[]);
void mostrar(int [][12], int[]);
void buscarmaxrecaudacion(float[][12], int[]);
void lessearning(float [][12]);
int main(){
    int codigo[20], cant[20][12] = {0}; 
    float precio[20], recaudacion[20][12] ={0};
    ingresoinicial(codigo, precio);
    ingresoventas(cant, codigo, recaudacion, precio);
    /*a.Mostrar unidades de ventas por producto en cada mes*/
    mostrar(cant, codigo);
    /*b.Mostrar el producto con la mayor recaudacion*/
    buscarmaxrecaudacion(recaudacion, codigo);
    /*c.Trimestre con menor recaudacion*/
    lessearning(recaudacion);
}
void lessearning(float Mrecaudacion[][12]){
    int i, j, trimestre,  minTrimestre, start =0;
    float min, suma;
    for(trimestre = 0; trimestre < 4; trimestre++){
        suma = 0;
        for(i = 0; i < 20; i++){
            for(j = start; j < start +3; j++){
                suma += Mrecaudacion[i][j];
            }
        }
        if(suma < min || trimestre == 0){
            min = suma;
            minTrimestre = trimestre;
        }
        start += 3;
    }
    printf("\nTrimestre con menor recaudacion:  %d", minTrimestre+1);
    printf("\nRecaudacion: %.2f", min);

}
void  buscarmaxrecaudacion(float Mrecaudacion[][12], int Vcodigo[]){
    float max = -1, suma;
    int posfila, i, j;
    for(i = 0; i < 20; i++){
        suma = 0;
        for(j = 0; j< 12; j++){
            suma += Mrecaudacion[i][j];
        }
        if(suma > max){
            posfila = i;
            max = suma;
        }
    }
    printf("\n\nEl producto con mayor recaudaciones el de codigo: %i", Vcodigo[posfila]);
    printf("\nRecaudacion:  %2.f", max);
}

void mostrar(int Mcant[][12], int Vcodigo[]){
    int i, j;
    printf("\nMES ");
    for(i = 0; i < 12; i++){
        printf("%-4i ", i+1);
    }
    for(i = 0; i < 20; i++){
        printf("\n%i ", Vcodigo[i]);
        for(j = 0; j < 12; j++){
            printf("%-4i ", Mcant[i][j]);
        }
    }
}
void ingresoventas(int cant[][12], int codigo[], float recaudacion[][12],float precio[]){
    int code, dia, mes, cantidad, pos;
    printf("\nINGRESO VENTAS\n");
    do{
        code = validar(100, 999, 0);
        pos = posSearch(codigo, code, 20);
        if(pos == -1 && code != 0){
            printf("\nCodigo invalido");
        }
    }while(pos == -1 && code != 0);
    while(code != 0){
        printf("\nDia:  ");
        dia =validar(1, 30, 20);
        printf("\nMes:  ");
        mes = validar(1, 12, 2);
        printf("\nCantidad:  ");
        cantidad = validar(1, 3000, 200);
        cant[pos][mes-1] += cantidad;
        recaudacion[pos][mes-1] += precio[pos] * (float)cantidad;
        printf("\nIngrese codigo:  ");
        do{
            code = validar(100, 999, 0);
            pos = posSearch(codigo, code, 20);
            if(pos == -1 && code != 0){
                printf("\nCodigo invalido");
            }
        }while(pos == -1 && code != 0);
    }while(pos == -1 && code != 0);
}
void ingresoinicial(int code[], float price[]){
    int i, pos = -1;
    printf("\nIngrese codigo:  ");
    code[0] = validar(100, 999, 0);
    printf("\nIngrese precio:  ");
    scanf("%f", &price[0]);
    for(i = 1; i < 20; i++){
        printf("\nIngrese codigo:  ");
        do{
            code[i] = validar(100, 999, 102);
            pos = posSearch(code, code[i], i);
            if(pos != -1){
                printf("\nCodigo repetido: ");
            }
        }while(pos!= -1);
        printf("\nIngrese precio:  ");
        scanf("%f",&price[i]);
    }
}
int posSearch(int vec[], int cod, int tam){
    int i = 0, pos =-1;
    while(i <  tam && pos == -1){
        if(vec[i] == cod){
            pos = i;
        }
        i++;
    }
    return pos;
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%i", &aux);
        if((aux<min && aux>max)&& aux != ex){
            printf("\nIngrese dato valido:  ");
        }
    }while((aux < min || aux >max) && aux != ex);
    return aux;
}